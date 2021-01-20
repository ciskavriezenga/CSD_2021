<h1>Create a (Stereo)Delay</h1>
Use this small delay application that uses a circular buffer and extend it with:

1. A Delay class that is the owner of the circular buffer and contains a process method. This process method expects:
  - a pointer to an input buffer
  - a pointer to an output buffer
  - number of frames

2. Add functionality to the Delay class to change the delay time. Be aware: this will result in ticks.

3. Think of and implement a solution to prevent ticks when changing the delay time.

4. Alter the jack_module.cpp file in such way that the Jack onProcess function retrieves two output buffers. Apply two delay objects, one to each output buffer.

5. Create a StereoDelay class. You can consider interleaved channels.
