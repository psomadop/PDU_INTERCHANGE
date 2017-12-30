This little demo application demonstrates how to use flatbuffers for C (flatcc), in order to define over-the-air exchangeable messages.

pdu_spec contains the flatbuffers PDU specification.
pdu_types.h is the structures that we wish to transmit over the air, and we want them encoded.
pdu_transcoder is the module which encodes/decodes the structures to flatbuffer messages. It encapsulates all codec functionality.
See docs_from_Tasos folder for design notes and instructions to build flatcc for your platform.

Feel free to build flatbuffers and flatcc for your platform, but the makefile can do it for you. In general, you'll be on the safe side if you "make all", because it will attempt to build flatcc, flatbuffers and everything else on your platform. 

You will need Python 2.7, CMake, make (or mingw32-make) and GCC (or mingw32-gcc).
