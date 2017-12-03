PROTOC=protobuf-3.5.0/src/protoc
PROTOC_INPUT_PATH=pdu_spec
PROTOC_OUTPUT_PATH=pdu_transcoder
PROTOBUF_LIB=pdu_transcoder.a
PROTOBUF_SRC=protobuf-3.5.0/src
# Take all C and C++ source files for protobuf transcoder
TRANSCODER_SOURCES:=$(wildcard $(PROTOC_OUTPUT_PATH)/*.cc)
TRANSCODER_OBJECTS:=$(patsubst %.cc,%.o,$(TRANSCODER_SOURCES))
OUT_DIR=pdu_transcoder_lib
CPP=g++ -c -g
CC=gcc -c -g
LD=gcc

transcoder_src: $(PROTOC_INPUT_PATH)/pdu.proto
	$(PROTOC) -I=$(PROTOC_INPUT_PATH) --cpp_out=$(PROTOC_OUTPUT_PATH) pdu.proto

transcoder_objects:
	$(CPP) -I. -Ipdu_transcoder_lib -I$(PROTOC_OUTPUT_PATH) -I$(PROTOBUF_SRC) $(TRANSCODER_SOURCES)

demo_object:
	$(CC)  -I. -Ipdu_transcoder_lib demo.c

all: transcoder_src transcoder_objects demo_object
	./protobuf-3.5.0/libtool -o demo --mode=link gcc -O -odemo $(PROTOBUF_SRC)/libprotobuf.la demo.o *.o
