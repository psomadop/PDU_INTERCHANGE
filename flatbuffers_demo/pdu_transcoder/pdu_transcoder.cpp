#include "pdu_transcoder.h"
#include "pdu_generated.h"
#include "pdu_types.h"

using namespace GTP;

/**
 * ASN.1 Encode tx_pdu, to the supplied buffer of specified length.
 *
 * @param   tx_pdu          TX_PDU structure to encode to ASN.1 binary format.
 * @param   buffer          Byte buffer where encoded TX_PDU will be stored.
 * @param   buffer_size     Size of supplied buffer.
 * @param   enc_len         Will contain the number of encoded bytes, on success.
 *
 * @return  encoded bytes   On success, the number of encoded bytes is returned.
 *          -1              On failure.
 */
int pdu_encode(TX_PDU* tx_pdu, char* buffer, int buffer_size, int *enc_len)
{
    int                             i, status;
    flatbuffers::FlatBufferBuilder  builder(1024);

    /**
     *  Not a C++ expert, but this will assign the right type at compile-time.
     *  I'll reassign later.
     */
    auto fcell = CreateCell(builder);

    /**
     * I need a vector to store flatbuffer Cells.
     * These will be converted to a flatbuffers vector.
     */
    std::vector<flatbuffers::Offset<Cell>> fcells;  // Collection of encoded PDU Cells.

    for (i = 0; i < tx_pdu->num_cells; i++)
    {
        CELL *cur = &tx_pdu->cells[i];
        
        switch (cur->type)
        {
            case CELL_TYPE_INT:
                fcell = CreateCell(builder, CellType_INT, cur->u.int_val);
                break;

            case CELL_TYPE_BOOL:
                fcell = CreateCell(builder, CellType_BOOL, 0, cur->u.bool_val);
                break;

            case CELL_TYPE_NAME:
                fcell = CreateCell(builder, CellType_NAME, 0, false,
                                   builder.CreateString(std::string(cur->u.name_val)));
                break;

            case CELL_TYPE_MESSAGE:
                auto fmessage =  CreateComplexType(builder,
                                     cur->u.message.clock_ticks,
                                     builder.CreateVector(cur->u.message.integers,
                                                          sizeof(cur->u.message.integers)));

                fcell = CreateCell(builder, CellType_MESSAGE, 0, false, 0, fmessage);
                break;
        }

        fcells.push_back(fcell);
    }

    *enc_len = 0;
    auto all_fcells = builder.CreateVector(fcells);
    auto fpdu = CreatePDU(builder, all_fcells);
    builder.Finish(fpdu);

    uint8_t *buf = builder.GetBufferPointer();
    *enc_len = builder.GetSize();

    if (*enc_len == 0)
        return -1;

    return *enc_len;
}


/**
 * Decode ASN.1 encoded buffer to supplied TX_PDU structure;
 *
 * @param   tx_pdu          TX_PDU structure with decoded data.
 * @param   buffer          Byte buffer where encoded TX_PDU is be stored.
 * @param   buffer_size     Size of supplied buffer.
 *
 * @return  Consumed bytes  On success, the number of bytes consumed from buffer is returned.
 *          -1              On failure.
 */
int pdu_decode(TX_PDU* tx_pdu, char* buffer, int buffer_size)
{
    return 1;
}
