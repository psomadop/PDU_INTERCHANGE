FLATBUFFERS_INCLUDE=flatbuffers/include/flatbuffers
TRANSCODER_LOC=pdu_transcoder
SCHEMA_SRC_OUT=pdu_transcoder
SCHEMA_DEF=pdu_spec/pdu.fbs

# Take all C and C++ source files for protobuf transcoder
TRANSCODER_SOURCES:=$(wildcard $(TRANSCODER_LOC)/*.cpp)

CPP=c++ -std=c++11 -c
CC=gcc -c
LD=gcc
BLD=gcc -g
FLATC=flatbuffers/flatc

schema_src: $(SCHEMA_DEF)
	$(FLATC) -c -o $(SCHEMA_SRC_OUT)/ $(SCHEMA_DEF)
	
cpp_objs: $(TRANSCODER_SOURCES)
	$(CPP) -I. -Iflatbuffers/include $(TRANSCODER_SOURCES)

all: schema_src cpp_objs
	$(BLD) -I. -Ipdu_transcoder demo.c pdu_transcoder.o
