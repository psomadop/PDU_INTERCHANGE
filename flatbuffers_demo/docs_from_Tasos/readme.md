This little demo application demonstrates how to use flatbuffers for C (flatcc), in order to define over-the-air exchangeable messages.

* pdu_spec contains the flatbuffers PDU specification.
* pdu_types.h is the structures that we wish to transmit over the air, and we want them encoded.
* pdu_transcoder is the module which encodes/decodes the structures to flatbuffer messages. It encapsulates all codec functionality.

See docs_from_Tasos folder for design notes and instructions to build flatcc for your platform.

Make sure you build flatcc first, because the commited executables and libraries are build on MacOS.
