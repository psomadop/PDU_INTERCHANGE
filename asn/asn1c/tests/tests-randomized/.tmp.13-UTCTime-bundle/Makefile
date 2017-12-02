CFLAGS+= -DASN1_TEXT='UTCTime'
ASN_PROGRAM = random-test-driver
ASN_PROGRAM_SRCS = random-test-driver.c

include converter-example.mk

all-tests-succeeded: /Users/tasospsomadopoulos/Documents/asn1_sample/asn1c/asn1c/asn1c $(ASN_PROGRAM_SRCS) $(ASN_MODULE_SRCS) $(ASN_MODULE_HDRS)
	@rm -f $@
	@echo Previous try did not go correctly. To reproduce:
	@cat .test-reproduce
	@exit 1

fuzz: fuzz-der fuzz-oer fuzz-uper fuzz-xer
fuzz-%: random-data/% random-test-driver
	ASN1_DATA_DIR=$<  UBSAN_OPTIONS=print_stacktrace=1 ./random-test-driver -timeout=3 -max_total_time=10 -max_len=128 $<
