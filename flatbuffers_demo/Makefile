FLATBUFFERS_INCLUDE=flatcc/include
FLATBUFFERS_RUNTIME=flatcc/lib/libflatccrt.a
TRANSCODER_LOC=pdu_transcoder
SCHEMA_DEF=pdu_spec/pdu.fbs

# Take all C and C++ source files for protobuf transcoder
TRANSCODER_SOURCES:=$(wildcard $(TRANSCODER_LOC)/*.*)

CPP=c++ -std=c++11 -c
CC=gcc -c
LD=gcc
BLD=gcc -g
FLATC=flatcc/bin/flatcc

schema_src: $(SCHEMA_DEF)
	$(FLATC) -a -o $(TRANSCODER_LOC)/ $(SCHEMA_DEF)

all: schema_src $(TRANSCODER_SOURCES) $(FLATBUFFERS_RUNTIME)
	$(BLD) -std=c11 -oflatbuffers_demo -I. -I$(FLATBUFFERS_INCLUDE) -I$(TRANSCODER_LOC) demo.c $(TRANSCODER_LOC)/pdu_transcoder.c $(FLATBUFFERS_RUNTIME)
