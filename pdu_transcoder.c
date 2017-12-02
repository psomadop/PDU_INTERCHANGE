//
// Created by Tasos Psomadopoulos on 02/12/2017.
//

#include "pdu_transcoder.h"
#include "PDU.h"
#include <stdlib.h>
#include <string.h>

int pdu_encode(TX_PDU* tx_pdu, char* buffer, int buffer_size)
{
    int i;

    Cell_t  *asn_cells = malloc(tx_pdu->num_cells * sizeof(Cell_t));
    for (i = 0; i < tx_pdu->num_cells; i++)
    {
        CELL *cur = &tx_pdu->cells[i];
        Cell_t asn_cur;

        switch (cur->type)
        {
            case CELL_TYPE_INT:
                asn_cur.present = Cell_PR_intVal;
                asn_cur.choice.intVal = cur->u.int_val;
                break;
            case CELL_TYPE_BOOL:
                asn_cur.present = Cell_PR_boolVal;
                asn_cur.choice.boolVal = cur->u.bool_val;
                break;
            case CELL_TYPE_NAME:
                asn_cur.present = Cell_PR_name;
                asn_cur.choice.name.buf = (unsigned char*) cur->u.name_val;
                asn_cur.choice.name.size = strlen(cur->u.name_val);
                break;
            case CELL_TYPE_MESSAGE:
                asn_cur.present = Cell_PR_message;
                asn_cur.choice.message.clockTicks = cur->u.message.clock_ticks;
                //for (int i = 0; i < sizeof(cur->u.message.integers); i++)
                //{
                    asn_sequence_add(
                            (void*)&asn_cur.choice.message.intSequence,
                            &cur->u.message.integers[i]);
                //}
                break;
        }
    }

    return 1;
}
