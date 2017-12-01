CC=gcc
INCLUDE=asn_enc_dec
ASN_SRC=asn_enc_dec
OUT=demo
ASN1_ROOT_PDU=PDU

# I need to exclude converter-example.c, because it contains a stray main(),
# and BIT_STRING.C from the glob sources list. Also need to exclude BIT_STRING.c,
# I need to CPP-define ASN_DISABLE_OER_SUPPORT to build it, or it compiles 
# references to unresolved symbols.
# I have no words...
ASN_SRC_FILES = $(wildcard $(ASN_SRC)/*.c)
ASN_SOURCES := $(filter-out $(ASN_SRC)/BIT_STRING.c, $(ASN_SRC_FILES))
ASN_SOURCES := $(filter-out $(ASN_SRC)/converter-example.c, $(ASN_SOURCES))

bit_string.o:	$(ASN_SRC)/BIT_STRING.c
	$(CC) -c -std=c99 -DPDU=$(ASN1_ROOT_PDU) -DASN_DISABLE_OER_SUPPORT -oBIT_STRING.o -I$(INCLUDE) $(ASN_SRC)/BIT_STRING.c

all: bit_string.o
	$(CC) -std=c99 -DPDU=$(ASN1_ROOT_PDU) -o$(OUT) -I$(INCLUDE) demo.c BIT_STRING.o $(ASN_SOURCES)
	rm BIT_STRING.o

