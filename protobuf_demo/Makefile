PROTOC=protobuf-3.5.0/src/protoc
PROTOC_INPUT_PATH=pdu_spec
PROTOC_OUTPUT_PATH=pdu_transcoder

transcoder_src: $(PROTOC_INPUT_PATH)/pdu.proto
	$(PROTOC) -I=$(PROTOC_INPUT_PATH) --cpp_out=$(PROTOC_OUTPUT_PATH) pdu.proto
