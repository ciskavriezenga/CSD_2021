<H1>Session 4</H1>

<H2>Content</H2>

* Sine wave generation
  * Sine function
  * Sine function in audio context
  * Sine in code example - plotting the resulting text output

* Installing jack - sounding simple sine example

* Optional topics:
  * recap pointersw
  * Oscillator inheritance with Sine class
  * How to generate other waveforms?



\
<H3>Plotting</H3> Multiple options exist to plot data.
\
The R language, or R-Studio:
https://www.datacamp.com/community/tutorials/installing-R-windows-mac-ubuntu
\
Or e.g. mathplotlib.
The directory 01_sine contains a python script that uses this library to plot the data.

```
pip3 install mathplotlib
cd 01_sine
python3 plot.py
```

\
<H3>Jackaudio</H3>

https://jackaudio.org/downloads/

https://github.com/jackaudio/jackaudio.github.com/wiki/jackd(1)

Here it is reccomended to download JACK2. 
32-bit Jack will be installed under: C:/Program\ Files\ \(x86\)/JACK2/
64-bit Jack will be installed under: C:/Program\ Files/JACK2/
In these tutorials we are using 32-bit JACK2

<H3>Windows edits in files<H3>
-> When importing math.h we should use: <math.h>
-> When importing math.h we should first define the strongtypes: #define _USE_MATH_DEFINES
-> In case you need to import Jack in your code use the following CFLAGS and LDFLAGS 
  (The parts of the path before JACK2 can differ depending on your installation location):
  ```CFLAGS := -Ic:/Program\ Files\ \(x86\)/JACK2/include -std=c++1z```
  32-bit:
  ```LDFLAGS= -Lc:/Program\ Files/JACK2/lib32 -llibjack```
  64-bit:
  ```LDFLAGS= -Lc:/Program\ Files/JACK2/lib -llibjack64```
-> In the main.cpp when initializing jack please give the .exe file name as an argument instead of argv[0]