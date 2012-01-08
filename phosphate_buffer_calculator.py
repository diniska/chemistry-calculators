#!/usr/bin/env python

#This is a henderson hasselbach buffer calculator

#the main buffer I am using is phosphate:
#phosphoric acid: 98 g/mol pKa= 2.16
#monobasic dihydrate: 155.99 g/mol pKA= 6.86
#Bibasic anhydrous:  141.96 g/mol pKA= 12.32
#henderson hasselbach
# pH= pKa + log([base]/[acid])
# [base] = 1 - [Acid]
#example:
#   pka of my acid is 6.86, desired pH = 7.5 so first calc is 
#   7.5 - 6.86 = 0.64
#   0.64 = log(base/acid)
#   then cancel the base 10 log
#   10**.64= 4.365 = [Base]/[Acid]
#   then this our ratio, so for a 50mm buffer:
#   0.05 = [base] + [Acid]

def fullcalc(ph, pkaacid, concentration, mwacid, mwbase, volume):
    acon = (concentration / (10**(ph - pkaacid) + 1 ))
    bcon = concentration - acon
    massacid = acon * volume * mwacid
    massbase = bcon * volume * mwbase
    return acon, bcon, massacid, massbase

print "This script will calculate amount of buffer to add for phosphate buffers"
print ""
print "Choose between:"
print "1: Na-> Dibasic-anhydrate /// Monobasic-Dihydrate"
print "\t 141.96 g/mol  /// 155.99 g/mol !"
print ""
print "2: Na->Dibasic-heptahydrate /// Monobasic-Dihydrate"
print "\t  268.07 g/mol  /// 155.99 g/mol !"
print ""
print "3: K->Dibasic-anhydrate /// Monobasic-anhydrate"
print "\t  174.2 g/mol- pKa=12.4 /// 136 g/mol- pKa=7.2 !"
print ""
print "4: K->Dibasic-anhydrate /// Monobasic-anhydrate"
print "\t  174.2 g/mol- pKa=12.4 /// 136 g/mol- pKa=7.2 !"
print ""
print "9: none of these..... (custom values)"
print ""
choice = int(raw_input("Type the number you want > "))
print "Now choose final concentration"
concentration = float(raw_input("Concentration (Molar) > "))
print "Next I need the volume you want to make"
volume = float(raw_input("Volume (liters)?> "))
print "Finally choose final pH"
ph = float(raw_input("pH ? > "))

if choice == 1:
    print "You chose type 1"
    pkaacid = 6.86
    pkabase = 12.32
    mwacid = 155.99
    mwbase = 141.96
    acon, bcon, amass, bmass = fullcalc(ph, pkaacid, concentration, mwacid, mwbase, volume)
    print "Acid concentration to use is", acon
    print "Base concentration to use is", bcon
    print "Mass of acid to weigh (monobasic)", amass
    print "mass of base to weigh (dibasic)", bmass
elif choice == 2:
    print "You chose type 2"
    pkaacid = 7.2
    pkabase = 12.32
    mwacid = 136
    mwbase = 174.2
    acon, bcon, amass, bmass = fullcalc(ph, pkaacid, concentration, mwacid, mwbase, volume)
    print "Acid concentration to use is", acon
    print "Base concentration to use is", bcon
    print "Mass of acid to weigh (monobasic)", amass
    print "mass of base to weigh (dibasic)", bmass
elif choice == 3:
    print "You chose type 2"
    pkaacid = 6.86
    pkabase = 12.32
    mwacid = 155.99
    mwbase = 268.07
    acon, bcon, amass, bmass = fullcalc(ph, pkaacid, concentration, mwacid, mwbase, volume)
    print "Acid concentration to use is", acon
    print "Base concentration to use is", bcon
    print "Mass of acid to weigh (monobasic)", amass
    print "mass of base to weigh (dibasic)", bmass
elif choice == 9:
    print "You will need to enter your own Molecular weights and pKa's in this case"
    pkaacid = float(raw_input("enter pKa acid here > "))
    mwacid = float(raw_input("enter MW acid here > "))
    pkabase = float(raw_input("enter pKa base here > "))
    mwbase = float(raw_input("enter MW base here > "))
    acon, bcon, amass, bmass = fullcalc(ph, pkaacid, concentration, mwacid, mwbase, volume)
    print "Acid concentration to use is", acon
    print "Base concentration to use is", bcon
    print "Mass of acid to weigh (monobasic)", amass
    print "mass of base to weigh (dibasic)", bmass
else:
    "You did not choice a valid number, try again"
    choice = int(raw_input("Type the number you want > "))

    
if concentration > 0.400:
    print 3 * "WARNING SOLUBILITY MAY BE EXCEEDED \n"
if ph > 8.5:
    print 3 * "WARNING SAFE BUFFER RANGE MAY BE EXCEEDED \n"
if ph < 5.5:
    print 3 * "WARNING SAFE BUFFER RANGE MAY BE EXCEEDED \n"


