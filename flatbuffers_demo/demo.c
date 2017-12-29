#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include "pdu_types.h"
#include "pdu_transcoder.h"


void print_cell(CELL *c)
{
    switch (c->type)
    {
        case CELL_TYPE_INT:
            printf ("CELL_TYPE_INT\n");
            printf ("\t int_val:%d \n", c->u.int_val);
            break;
            
        case CELL_TYPE_BOOL:
            printf ("CELL_TYPE_BOOL\n");
            printf ("\t bool_val:%d\n", c->u.bool_val);
            break;
            
        case CELL_TYPE_NAME:
            printf ("CELL_TYPE_NAME\n");
            printf ("\t name_val:%s\n", c->u.name_val);
            break;
            
        case CELL_TYPE_MESSAGE:
            printf ("CELL_TYPE_MESSAGE\n");
            printf ("\t clock_ticks: %ld\n", c->u.message.clock_ticks);
            printf  ("\t integers: %d,%d,%d,%d\n",
                    c->u.message.integers[0],
                    c->u.message.integers[1],
                    c->u.message.integers[2],
                    c->u.message.integers[3]);
            break;
    }
}

int main(void)
{
    /* My data types. */
    CELL    cell_a, cell_b, cell_c, cell_d;
    CELL    cells[4];
    memset(cells, 0, sizeof(cells));
    
    /* Buffer for encoded data. */
    char    encoded[8192];
    int     encoded_len = 8192;
    int     bytes_encoded;    

    TX_PDU tx_pdu;      // I will encode this one.
    TX_PDU decoded;     // And I will decode it here.

    memset(&tx_pdu, 0, sizeof(TX_PDU));
    memset(&decoded, 0, sizeof(TX_PDU));
    memset(cells, 0, 4 * sizeof(CELL));
    memset(encoded, 0, encoded_len);

    /* Just populate my data types to encode. */
    cell_a.type = CELL_TYPE_INT;
    cell_a.u.int_val = 2;

    cell_b.type = CELL_TYPE_BOOL;
    cell_b.u.bool_val = TRUE;

    cell_c.type = CELL_TYPE_MESSAGE;
    cell_c.u.message.clock_ticks = 34431;
    cell_c.u.message.integers[0] = 1;
    cell_c.u.message.integers[1] = 2;
    cell_c.u.message.integers[2] = 3;
    cell_c.u.message.integers[3] = 4;

    cell_d.type = CELL_TYPE_NAME;
    cell_d.u.name_val = "Tasos Psomadopoulos";

    cells[0] = cell_a;
    cells[1] = cell_b;
    cells[2] = cell_c;
    cells[3] = cell_d;

    tx_pdu.cells = cells;
    tx_pdu.num_cells = 4;
    
    /* Encode here. */
    int success = pdu_encode(&tx_pdu, encoded, encoded_len, &bytes_encoded);
    printf ("== ENCODE ==\nflatbuffers encoder returned: %d. Bytes encoded:%d\n", (int)success, bytes_encoded);
    for (int i = 0; i < bytes_encoded && success; i++)
    {
        printf("0x%02x,", (unsigned char)encoded[i]);
    }
    printf("\n");

    /* Decode and see what we get back. */
    success = pdu_decode(&decoded, encoded, encoded_len);
    printf ("flatbuffers decoder returned: %d\n", (int)success);

    printf("\n== DECODE ==\nNum cells decoded %d\n", decoded.num_cells);
    for (int i = 0; i < decoded.num_cells; i++)
    {
        print_cell(&decoded.cells[i]);
    }
    
    exit(0);
}
