#include "pdu_transcoder.h"
#include "pdu.pb.h"

/**
 * This is the mediator between demo app <-> protobuf.
 */

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
    printf ("ENCODING");
    int i;
    PDU p_pdu;

    for (i = 0; i < tx_pdu->num_cells; i++)
    {
    }

    return 1;
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
    printf("DECODING");
    return 1;
}
