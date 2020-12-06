curve(expr=sin, from=0, to=2*pi, xname = "t")
abline(h = 0, lty = 1, col = "gray")

samplerate = 44100
sinewave <- function(t) sin(t * 2*pi / samplerate)
curve(sinewave, 0, samplerate, xname = "x")
abline(h = 0, lty = 1, col = "gray")


frequency <- 2
curve(sin(2 * pi * frequency * x / samplerate), add = TRUE, col = "violet")
frequency <- 10
curve(sin(2 * pi * frequency * x / samplerate), add = TRUE, col = "green")





# Let t indicate the index of a sample,
# then the equation is as follow.
# sample =  sin((t * 2 * pi) / samplerate)
#
# and:
# phase = t / samplerate
# within the interval [0, 1]
#
# Rewriting the equation.
# sample = sin(2 * pi * phase)
#
# It is therefore sufficient to keep track of the phase
# and to increase this at each sample step.
# phase += 1 / samplerate
#
# To also take the frequency into account,
# we can simply add it as follow.
# phase += frequency / samplerate
