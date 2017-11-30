CC=gcc
INCLUDE=asn_enc_dec
ASN_SRC=asn_enc_dec
OUT=demo



all:
	$(CC) -std=c99 -DPDU=PDU -o$(OUT) -I$(INCLUDE) demo.c $(ASN_SRC)/*.c

