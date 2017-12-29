FLATBUFFERS_INCLUDE=flatcc/include
FLATBUFFERS_RUNTIME=flatcc/lib/libflatccrt.a
TRANSCODER_LOC=pdu_transcoder
SCHEMA_DEF=pdu_spec/pdu.fbs
PYTHON_DECODER_LOC=python_pdu_decoder

# Take all C and C++ source files for protobuf transcoder
TRANSCODER_SOURCES:=$(wildcard $(TRANSCODER_LOC)/*.*)

CPP=c++ -std=c++11 -c
CC=gcc -c
LD=gcc
BLD=gcc -g
FLATC=flatcc/bin/flatcc
FLATBUFFERSC=flatbuffers/flatc

$(FLATC):
	cd flatcc && scripts/initbuild.sh make
	cd flatcc && scripts/build.sh

$(FLATBUFFERSC):
	cd flatbuffers && cmake -G "Unix Makefiles"
	cd flatbuffers && make

schema_src: $(SCHEMA_DEF)
	$(FLATC) -a -o $(TRANSCODER_LOC)/ $(SCHEMA_DEF)

python_decoder: $(SCHEMA_DEF) $(FLATBUFFERSC)
	$(FLATBUFFERSC) --python -o $(PYTHON_DECODER_LOC)  $(SCHEMA_DEF)

all: $(FLATC) $(FLATBUFFERSC) schema_src $(TRANSCODER_SOURCES) $(FLATBUFFERS_RUNTIME) python_decoder
	$(BLD) -std=c11 -oflatbuffers_demo -I. -I$(FLATBUFFERS_INCLUDE) -I$(TRANSCODER_LOC) demo.c $(TRANSCODER_LOC)/pdu_transcoder.c $(FLATBUFFERS_RUNTIME)
	./flatbuffers_demo
	cd python_pdu_decoder && python pdu_decoder.py
