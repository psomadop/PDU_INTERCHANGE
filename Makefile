CC=gcc
INCLUDE=asn
ASN_SRC=asn_enc_dec
OUT=demo

all:
	$(CC) -o$(OUT) -I$(INCLUDE) demo.c $(ASN_SRC)/*.c

