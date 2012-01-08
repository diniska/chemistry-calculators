#!/usr/bin/python

#####################################################
#
# A very simple script that uses the integral of the sin function to estimate the are under a curve on a chromatogram. Basically should only be used when being really lazy. 
#
#####################################################

import math

print "Sinusoidal FPLC curve estimator."

print "First enter the width of the peak (the volume eluted in, in mL)"
volume = float(raw_input("> "))

print "Now, enter the concentration of the most concentrated fraction (in uM)"
height = float(raw_input("> "))
print "also,  "
mw = float(raw_input("Enter MW: "))

h = volume / 2
a = (-1 * height) / (h**2)

def quadint(derp):
    n = (a*(derp)**3)/3 + (height*(derp**2))/2
    return n

y = quadint(volume)
x = quadint(0)
quad_int_outcome = y - x

print "Here is the uM*mL for QUADRATIC() estimation: ", quad_int_outcome
# quad_int_outcome = uM * mL = moles*10^-6/L * 10^-3 L, so *10^-9=moles
moles = quad_int_outcome*(10**-9)
print "In moles this is: ", moles
mg = moles * mw * 1000
print "In mg this is: ", mg
um = quad_int_outcome / 0.5
print "In 0.5mL volume (for NMR), the concentration = ", um
print ""
print ""


def sineint(x):
    #n = math.sin( ((derp - (volume/4)) * 3.14159) / (volume / 2)) * (height / 2) + (height / 2)
    # above = function integrated from, below = integral from wolfram alpha
    n = (height / (4*3.14159) )*((2*3.14159*x) - volume * math.sin((2*3.14159*x)/volume))
    return n

sineint_outcome = sineint(volume) - sineint(0)
print "Here is the uM*mL for SINE() estimation: ", sineint_outcome
moles2 = sineint_outcome*(10**-9)
print "In moles this is: ", moles2
mg2 = moles2 * mw * 1000
print "In mg this is: ", mg2
um2 = sineint_outcome / 0.5
print "In 0.5mL volume (for NMR), the concentration = ", um2
print ""
print "average =", (um + um2)/2
print ""





