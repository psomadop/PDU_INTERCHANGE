# Change platform to windows or macosx as per your machine.
PLATFORM=macosx

PROTOC_NANO=nanopb-0.3.9-$(PLATFORM)-x86
PROTOC_NANO_GEN=$(PROTOC_NANO)/generator-bin/protoc
PROTOBUF_NANO_INCLUDE=$(PROTOC_NANO)

PROTOC_GEN=protobuf-3.5.0/src/protoc
PROTOC_INPUT_PATH=pdu_spec/
PROTOC_OUTPUT_PATH=pdu_transcoder
PROTOBUF_LIB=protobuf-3.5.0/lib
PROTOBUF_SRC=protobuf-3.5.0/src
PROTOBUF_INCLUDE=protobuf-3.5.0/include

TRANSCODER_INCLUDE=pdu_transcoder

# Take all C and C++ source files for protobuf transcoder
TRANSCODER_SOURCES:=$(wildcard $(PROTOC_OUTPUT_PATH)/*.cc)

CPP=g++ -c
CC=gcc -c
LD=gcc
BLD=gcc

transcoder_src: $(PROTOC_INPUT_PATH)/pdu.proto
	$(PROTOC_GEN) -I=$(PROTOC_INPUT_PATH) --cpp_out=$(PROTOC_OUTPUT_PATH) pdu.proto

# C++ here, but with C linkage for the mediator.
transcoder_objects:
	$(CPP) -I. -I$(PROTOBUF_INCLUDE) -I$(TRANSCODER_INCLUDE) $(TRANSCODER_SOURCES)

# C here.
demo_object:
	$(CC)  -I. -I$(TRANSCODER_INCLUDE) demo.c

# Link them all, against protobuf library. Statically.
all_protobuf: transcoder_src transcoder_objects demo_object
	$(LD) -odemo -L$(PROTOBUF_LIB) -lprotobuf -lstdc++ *.o

# This is to build the nanopb version, which is a lot simpler.
transcoder_src_nano: $(PROTOC_INPUT_PATH)/pdu.proto 
	./$(PROTOC_NANO_GEN) --nanopb_out=$(PROTOC_OUTPUT_PATH) $(PROTOC_INPUT_PATH)pdu.proto

all_nano: transcoder_src_nano
	$(BLD) -odemo -I$(PROTOBUF_NANO_INCLUDE) -I$(PROTOC_OUTPUT_PATH) -I$(PROTOC_OUTPUT_PATH)/pdu_spec -I. demo.c $(PROTOC_NANO)/*.c $(PROTOC_OUTPUT_PATH)/*.c
