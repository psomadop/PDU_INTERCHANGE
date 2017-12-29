Go to flatbuffers_demo, do a "make all" and let the demo run. 
It will 
(1) Encode PDU from pdu_types.h, in C, to a buffer and will write the buffer to enc_pdu.bin
(2) Decode from a binary buffer to a PDU, and print the decoded PDU properties.
(3) Decode enc_pdu.bin from a Python program and print the decoded PDU properties.
