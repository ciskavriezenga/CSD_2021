#
# Example of the use of a Python dictionary to represent events
#
# An event in the context of a sample sequencer contains a time stamp and
# payload in the form of e.g. the sound sample, volume/velocity, duration,
#  a symbolic name etc.
#
# Marc Groenewegen HKU 2020
#

snare_event = {
'timestamp': 10200, # msec w.r.t start of program
'instrument': "snare", # name of instrument in text
'velocity': 82, # numeric MIDI-based, 0-127
'duration': 500 # msec
}


kick_event = {
'timestamp': 10000, # msec w.r.t start of program
'instrument': "kick", # name of instrument in text
'velocity': 71, # numeric MIDI-based, 0-127
'duration': 100 # msec
}


#
# Event handler
#
def handle_note_event(event):
  print("Note event handler")
  print(event['instrument'],"to be played at",event['timestamp'])



handle_note_event(snare_event)

#
# Build a small sequence of events
#

sequence=[]
sequence.append(snare_event)
sequence.append(kick_event)


print("Raw sequence: ",sequence)


# sort using a sort key provided by lambda function
sequence.sort(key = lambda x: x['timestamp'])

print("Sorted sequence: ",sequence)


# function to be used as sort key
def get_timestamp(event):
  return event['timestamp']


# sort using a sort key
sequence.sort(key = get_timestamp,reverse=True)
print("Reverse sorted sequence: ",sequence)


