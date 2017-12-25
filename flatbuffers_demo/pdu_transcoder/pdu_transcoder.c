#include "pdu_transcoder.h"
#include "pdu.pb.h"
#include "pb_encode.h"
#include "pb_decode.h"

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
    int 			i, status;
    PDU 			p_pdu;
    pb_ostream_t 	stream;

    stream = pb_ostream_from_buffer((pb_byte_t*)buffer, buffer_size);

    for (i = 0; i < tx_pdu->num_cells; i++)
    {
        CELL *cur = &tx_pdu->cells[i];
        Cell p_cell;
        
        switch (cur->type)
        {
            case CELL_TYPE_INT:
                p_cell.type = CellType_CELLTYPE_INT;
                p_cell.intVal = cur->u.int_val;
                break;

            case CELL_TYPE_BOOL:
                p_cell.type = CellType_CELLTYPE_BOOL;
                p_cell.boolVal = cur->u.bool_val;
                break;

            case CELL_TYPE_NAME:
                p_cell.type = CellType_CELLTYPE_NAME;
                p_cell.name.arg =
                p_cell.name.funcs.encode = &encode_name;
                break;

            case CELL_TYPE_MESSAGE:
                p_cell.type = CellType_CELLTYPE_MESSAGE;
                p_cell.msg.clockTicks = cur->u.message.clock_ticks;
                p_cell.msg.intSequence.funcs.encode = &encode_complex;
                break;
    }

    status = pb_encode(&stream, Cell_fields, &p_cell);
    if (enc_len)
    {
    	*enc_len = stream.bytes_written;
    }

    if (!status)
    {
    	return -1;
    }
    else
    {
    	return 1;
    }
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
