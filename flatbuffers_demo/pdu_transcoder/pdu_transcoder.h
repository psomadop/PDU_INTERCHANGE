//
// Created by Tasos Psomadopoulos on 02/12/2017.
//

/**
 * App <-> pdu_transcoder mediator.
 */

#ifndef PDU_TRASNCODER_H
#define PDU_TRASNCODER_H

#include "pdu_types.h"

/**
 * Encode tx_pdu to flatbuffer, to the supplied buffer of specified length.
 *
 * @param   tx_pdu          TX_PDU structure to encode to binary format.
 * @param   buffer          Byte buffer where encoded TX_PDU will be stored.
 * @param   buffer_size     Size of supplied buffer.
 * @param   enc_len         Will contain the number of encoded bytes, on success.
 *
 * @return  encoded bytes   On success, the number of encoded bytes is returned.
 *          -1              On failure.
 */
int pdu_encode(TX_PDU* tx_pdu, char* buffer, int buffer_size, int *enc_len);

/**
 * Decode encoded flatbuffer to supplied TX_PDU structure;
 *
 * @param   tx_pdu          TX_PDU structure with decoded data.
 * @param   buffer          Byte buffer where encoded TX_PDU is be stored.
 * @param   buffer_size     Size of supplied buffer.
 *
 * @return  Consumed bytes  On success, the number of bytes consumed from buffer is returned.
 *          -1              On failure.
 */
int pdu_decode(TX_PDU* tx_pdu, char* buffer, int buffer_size);

#endif //PDU_TRASNCODER_H
