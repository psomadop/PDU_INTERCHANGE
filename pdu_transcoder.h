//
// Created by Tasos Psomadopoulos on 02/12/2017.
//

#ifndef ASN_ASN_TRASNCODER_C_H
#define ASN_ASN_TRASNCODER_C_H

#include "pdu_types.h"

int pdu_encode(TX_PDU* tx_pdu, char* buffer, int buffer_size, int *enc_len);
int pdu_decode(TX_PDU* tx_pdu, char* buffer, int buffer_size);


#endif //ASN_ASN_TRASNCODER_C_H
