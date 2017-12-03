//
// Created by Tasos Psomadopoulos on 02/12/2017.
//

#ifndef ASN_PDU_TYPES_H
#define ASN_PDU_TYPES_H

#define TRUE    (1)
#define FALSE   (0)

/**
 * Cell data type definitions.
 */
typedef enum cell_type_t
{
    CELL_TYPE_INT,
    CELL_TYPE_BOOL,
    CELL_TYPE_NAME,
    CELL_TYPE_MESSAGE
} CELL_TYPE;

/**
 * Complex type definition.
 */
typedef struct message_t
{
    unsigned long int   clock_ticks;
    int                 integers[4];    // Say I have an array of 4 integers here.
} MESSAGE;

/**
 * Cell definition.
 */
typedef struct cell_t
{
    CELL_TYPE type;
    union
    {
        int             int_val  : 4;
        unsigned int    bool_val : 1;
        char            *name_val;
        MESSAGE         message;
    }u;
} CELL;

typedef struct tx_pdu_t
{
    CELL    *cells;
    int     num_cells;
} TX_PDU;
#endif //ASN_PDU_TYPES_H
