PROTOC=protobuf-3.5.0/src/protoc
PROTOC_INPUT_PATH=pdu_spec
PROTOC_OUTPUT_PATH=pdu_transcoder
PROTOBUF_LIB=protobuf-3.5.0/lib
PROTOBUF_SRC=protobuf-3.5.0/src
PROTOBUF_INCLUDE=protobuf-3.5.0/include
TRANSCODER_INCLUDE=pdu_transcoder

# Take all C and C++ source files for protobuf transcoder
TRANSCODER_SOURCES:=$(wildcard $(PROTOC_OUTPUT_PATH)/*.cc)

CPP=g++ -c -g
CC=gcc -c -g
LD=gcc

transcoder_src: $(PROTOC_INPUT_PATH)/pdu.proto
	$(PROTOC) -I=$(PROTOC_INPUT_PATH) --cpp_out=$(PROTOC_OUTPUT_PATH) pdu.proto

# C++ here, but with C linkage for the mediator.
transcoder_objects:
	$(CPP) -I. -I$(PROTOBUF_INCLUDE) -I$(TRANSCODER_INCLUDE) $(TRANSCODER_SOURCES)

# C here.
demo_object:
	$(CC)  -I. -I$(TRANSCODER_INCLUDE) demo.c

# Link them all, against protobuf library. Statically.
all: transcoder_src transcoder_objects demo_object
	$(LD) -odemo -L$(PROTOBUF_LIB) -lprotobuf -lstdc++ *.o
