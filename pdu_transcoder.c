//
// Created by Tasos Psomadopoulos on 02/12/2017.
//

#include "pdu_transcoder.h"
#include "PDU.h"
#include "errno.h"
#include <stdlib.h>
#include <string.h>

int pdu_encode(TX_PDU* tx_pdu, char* buffer, int buffer_size, int *enc_len)
{
    int         i;
    Cell_t      *asn_cells;
    struct PDU  asn_pdu;

    asn_codec_ctx_t  context;
    asn_enc_rval_t   asn_result;

    asn_cells = malloc(tx_pdu->num_cells * sizeof(Cell_t));

    if (asn_cells == NULL)
    {
        return 0;
    }

    memset(&asn_pdu, 0, sizeof(struct PDU));

    for (i = 0; i < tx_pdu->num_cells; i++)
    {
        CELL *cur = &tx_pdu->cells[i];
        Cell_t *asn_cur = &asn_cells[i];
        memset(asn_cur, 0, sizeof(Cell_t));

        switch (cur->type)
        {
            case CELL_TYPE_INT:
                asn_cur->present = Cell_PR_intVal;
                asn_cur->choice.intVal = cur->u.int_val;
                break;

            case CELL_TYPE_BOOL:
                asn_cur->present = Cell_PR_boolVal;
                asn_cur->choice.boolVal = cur->u.bool_val;
                break;

            case CELL_TYPE_NAME:
                asn_cur->present = Cell_PR_name;
                asn_cur->choice.name.buf = (unsigned char*) cur->u.name_val;
                asn_cur->choice.name.size = strlen(cur->u.name_val);
                break;

            case CELL_TYPE_MESSAGE:
                asn_cur->present = Cell_PR_message;
                asn_cur->choice.message.clockTicks = cur->u.message.clock_ticks;
                for (int i = 0; i < sizeof(cur->u.message.integers); i++)
                {
                    if (0 != ASN_SEQUENCE_ADD( &asn_cur->choice.message.intSequence,
                                                 &cur->u.message.integers[i]))
                    {
                        return 0;
                    }
                }
                break;

            default:
                asn_cur->present = Cell_PR_NOTHING;
                break;
        }

        if (0 != ASN_SEQUENCE_ADD( &asn_pdu.cells, cur ))
        {
            return 0;
        }
    }
    
    //xer_fprint(stdout, &asn_DEF_PDU, &asn_pdu);
    asn_enc_rval_t er;  /* Encoder return value */
    er.encoded = -1; 

    er = der_encode_to_buffer( &asn_DEF_PDU, 
                               &asn_pdu, buffer, buffer_size );

    printf ("ASN encode errno: %d\n", errno);
    
    *enc_len = 0;
    if(er.encoded == -1) 
    {
        return -1;
    } 
    else 
    {
        if (enc_len)
        {
            *enc_len = (int)asn_result.encoded;
        }

        return er.encoded;
    }

    return 0;
}
