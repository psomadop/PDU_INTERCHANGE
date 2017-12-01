CC=gcc
INCLUDE=asn_enc_dec
ASN_SRC=asn_enc_dec
OUT=demo
ASN1_ROOT_PDU=PDU


all:
	$(CC) -std=c99 -DPDU=$(ASN1_ROOT_PDU) -o$(OUT) -I$(INCLUDE) demo.c $(ASN_SRC)/*.c

