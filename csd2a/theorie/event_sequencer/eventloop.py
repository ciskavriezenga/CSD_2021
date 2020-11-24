#
# Example of an event-based sequencer
#
# There is no 'end of sequence', which results in an odd timing at the end
#  of each loop
#
# The loop runs in its own thread and user input is processed in the main
# thread, so the speed can be changed while the loop is playing.
# Implementation is quick-and-dirty.
#
# Marc Groenewegen HKU 2020
#

import sys
import threading
import time
import simpleaudio as sa

#
# Load sound samples
#
hihat = sa.WaveObject.from_wave_file("kit/hihat.wav")
snare = sa.WaveObject.from_wave_file("kit/snare.wav")
kick = sa.WaveObject.from_wave_file("kit/kick.wav")


bpm=120
quarterNoteDuration = 60000.0/bpm
eighthNoteDuration = quarterNoteDuration/2

continueFlag=True # continue looping as long as this is true


#
# Sequencer thread
#
class sequencer(threading.Thread):
  # constructor calls threading init
  def __init__(self,sequence):
    threading.Thread.__init__(self)
    self.sequence = sequence
  def run(self):
    # make a copy of the sequence so we can pop elements from it
    tmpsequence=list(self.sequence)

    while continueFlag:
      event=tmpsequence.pop(0)

      timeZero=time.time()*1000; # reset start-of-loop time

      # Loop over the entire sequence once
      while True:
        now=time.time()*1000
        if now-timeZero >= event['timestamp']*eighthNoteDuration:
          play_obj = event['instrument'].play() # replace by an event handler
          if tmpsequence: # if events left in list
            event=tmpsequence.pop(0) # take & use event from head of the list
          else:
            break # if no events left, break from the loop
        else:
          time.sleep(0.01) # if time for event hasn't come, wait
        
      tmpsequence=list(self.sequence) # copy for the next loop


#
# Function to create new events
#
def create_event(timestamp,instrument,instrumentname):
  event = {
    'timestamp': timestamp,
    'instrument': instrument,
    'instrumentname': instrumentname,
    'note': "NA",
    'percussive': True,
    'duration': 500,
    'velocity': 30,
  }
  return event

#
# Create a rhythm sequence in a hard-coded way.
# This should eventually be done by a composition algorithm
#
def create_sequence():
  rhythm=[]

  # non-mutable!
  rhythm.append(create_event(0,kick,"Kick"))
  rhythm.append(create_event(2,snare,"Snare"))
  rhythm.append(create_event(4,kick,"Kick"))
  rhythm.append(create_event(6,snare,"Snare"))
  rhythm.append(create_event(8,kick,"Kick"))
  rhythm.append(create_event(9,kick,"Kick"))
  rhythm.append(create_event(10,snare,"Snare"))
  rhythm.append(create_event(11,kick,"Kick"))
  rhythm.append(create_event(12,kick,"Kick"))
  rhythm.append(create_event(14,snare,"Snare"))

  # hihat on every tick
  for i in range(16):
    rhythm.append(create_event(i,hihat,"Hi-hat"))

  # sort sequence according to given sort key
  rhythm.sort(key = lambda x: x['timestamp'])

  return rhythm



sequence = create_sequence()
print(sequence)
sequencerThread = sequencer(sequence)
sequencerThread.start()


#
# Main thread
#
while True:
  bpmline=input("BPM " + str(bpm) + " --> ")
  if bpmline == "quit" or bpmline == "exit":
    continueFlag=False
    sequencerThread.join() # wait for thread to finish
    sys.exit()

  if bpmline.isnumeric():
    bpm=float(bpmline)
  else:
    continue # ask again for BPM input

  quarterNoteDuration = 60000.0/bpm
  eighthNoteDuration = quarterNoteDuration/2


