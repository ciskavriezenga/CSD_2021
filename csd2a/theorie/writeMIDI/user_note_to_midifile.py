#
# Demo program for asking user for some note(s), then write them to
#  a MIDI file using midiutil
#   https://pypi.org/project/MIDIUtil
#

from midiutil import MIDIFile

note=int(input("Enter a note: "))
velocity=int(input("Velocity: "))

mf = MIDIFile(1) 
track = 0

time = 0
mf.addTrackName(track, time, "Beat Sample Track")
mf.addTempo(track, time, 120)

#
# Format:
# mf.addNote(track, channel, pitch, time, duration, velocity)
#

mf.addNote(0, 0, note, 2, 1, velocity)

with open("symphony.midi",'wb') as outf:
    mf.writeFile(outf)


