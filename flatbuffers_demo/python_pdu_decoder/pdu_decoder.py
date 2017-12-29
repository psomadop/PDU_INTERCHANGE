import sys
import os.path
sys.path.append(os.path.join('..', 'flatbuffers', 'python'))
import flatbuffers
import GTP.Cell
import GTP.CellType
import GTP.ComplexType
import GTP.PDU

def decode_pdu_from_file(filename):
    cell_type = [ "CELL_TYPE_INT",
                  "CELL_TYPE_BOOL",
                  "CELL_TYPE_NAME",
                  "CELL_TYPE_MESSAGE" ]

    encFile = open(filename, 'rb')
    encoded = bytearray(encFile.read())

    pdu = GTP.PDU.PDU.GetRootAsPDU(encoded, 0)

    # DONE. Now let's print it!
    for i in range(0, pdu.CellsLength()):
        print ('=== Cell %s ===' % i)
        cell = pdu.Cells(i)
        print cell_type[ cell.Type() ]
        if cell.Type() == 0:
            print cell.IntVal()
        elif cell.Type() == 1:
            print cell.BoolVal()
        elif cell.Type() == 2:
            print cell.Name()
        elif cell.Type() == 3:
            print cell.Msg().ClockTicks()
            for k in range(0, cell.Msg().IntSequenceLength()):
                print cell.Msg().IntSequence(k)

print ("\n-> Python demo. Decoding enc_pdu.bin")
decode_pdu_from_file(os.path.join('..', 'enc_pdu.bin'))