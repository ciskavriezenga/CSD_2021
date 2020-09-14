import time
import simpleaudio as sa

# list with a rhythmic sequence in quarter notes
note_seq = [1.5, 1, 1, 0.5]
bpm = 120

# function to transform a rhythmic sequence into duration in time (sec.)
def to_time(src_seq, bpm):
    dst_seq = []
    dur_multiplyer = 60.0 / bpm

    # iterate through the source sequence, add duration values to destiation seq
    for note_dur in src_seq:
        dst_seq.append(note_dur * dur_multiplyer)

    return dst_seq

# call the to_time function and store the restulting sequence
time_seq = to_time(note_seq, bpm)

print("Sequence with quarter note values:", note_seq)
print("Sequence with duration values in seconds:", time_seq)
