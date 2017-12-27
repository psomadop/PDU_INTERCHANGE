#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include "pdu_types.h"
#include "pdu_transcoder.h"

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
    memset(encoded, 0, encoded_len);

    /* Just populate my data types to encode. */
    cell_a.type = CELL_TYPE_INT;
    cell_a.u.int_val = 2;

    cell_b.type = CELL_TYPE_BOOL;
    cell_b.u.bool_val = TRUE;

    cell_c.type = CELL_TYPE_MESSAGE;
    cell_c.u.message.clock_ticks = 34332;
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
    printf ("flatbuffers encoder returned: %d. Bytes encoded:%d\n", (int)success, bytes_encoded);
    for (int i = 0; i < bytes_encoded && success; i++)
    {
        printf("0x%2x,", (unsigned char)encoded[i]);
    }
    printf("\n");

    /* Decode and see what we get back. */
    success = pdu_decode(&decoded, encoded, encoded_len);
    printf ("flatbuffers decoder returned: %d\n", (int)success);

    printf("num cells decoded %d\n", decoded.num_cells);

    if (memcmp(&tx_pdu, &decoded, sizeof(TX_PDU)) == 0)
    {
        printf (" It all worked marvelously. Before and after TX_PDUs are the same.\n");
    }
    else
    {
        printf ("!! Before and after TX_PDUs are not the same !!\n");
    }

    exit(0);
}
