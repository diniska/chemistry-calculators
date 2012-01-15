#!/usr/bin/env python
# -*- coding: utf-8 -*-
#
#		Sortase Reaction Calculator
#       Copyright 2012 Aaron Decker <d00ble.ard@gmail.com>
#       
#       This program is free software; you can redistribute it and/or modify
#       it under the terms of the GNU General Public License as published by
#       the Free Software Foundation; either version 2 of the License, or
#       (at your option) any later version.
#       
#       This program is distributed in the hope that it will be useful,
#       but WITHOUT ANY WARRANTY; without even the implied warranty of
#       MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#       GNU General Public License for more details.
#       
#       You should have received a copy of the GNU General Public License
#       along with this program; if not, write to the Free Software
#       Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
#       MA 02110-1301, USA.

def write_file_newvar(n_volume, n_stock, ratio, acb_volume, acb_stock, sortase_stock, sortase_final, sort_volume, total_volume, n_conc_final, acb_conc_final):
    print """
    \t* If you want to write a file type a name and hit enter, 
    \t* If not, 
    \t* Just hit CTRL-C (^C)....
    \t* Also... if you are going to, end it in .txt obviously!
    """
    reactiondata = raw_input("???$>>")
    towrite = open(reactiondata, 'w')
    line1 = "Total volume in uL of the reaction", total_volume, "uL"
    line2 = "Concentration in uL of the sortase stock you are using", sortase_stock, "uM"
    line3 = "Final concentration in uL of sortase", sortase_final, "uM"
    line4 = "Original concentration of nucleophile, rrACB", acb_stock, "uM"
    line5 = "Original concentration of lxptg substrate, r-mod-n", n_stock, "uM"
    line6 = "The ratio of the two", ratio
    line7 = "The amount of sortase to use is:", sort_volume, "in uL"
    line8 = "The amount of nucleophile (acb) to use is", acb_volume, "uL"
    line9 = "The concentration of nucleophile (acb) will be", acb_conc_final, "uM"
    line10 = "The amount of substrate (nterm) to use is", n_volume, "uL"
    line11 = "The concentration of substrate (nterm) will be", n_conc_final, "uM"
    print ""
    print "The file will now be written/ over-written"
    print ""
    # quick note here: write will only write a string, so make your variable is a string with str() first.
    towrite.write(str(line1))
    towrite.write("\n")
    towrite.write(str(line2))
    towrite.write("\n")
    towrite.write(str(line3))
    towrite.write("\n")
    towrite.write(str(line4))
    towrite.write("\n")
    towrite.write(str(line5))
    towrite.write("\n")
    towrite.write(str(line6))
    towrite.write("\n")
    towrite.write(str(line7))
    towrite.write("\n")
    towrite.write(str(line8))
    towrite.write("\n")
    towrite.write(str(line9))
    towrite.write("\n")
    towrite.write(str(line10))
    towrite.write("\n")
    towrite.write(str(line11))
    towrite.write("\n")

def total_volume_calc():
    print "First enter the total volume in uL of the reaction"
    total_volume = float(raw_input("<0>"))
    print "Second, enter the concentration of the sortase you sample you are using"
    sortase_stock = float(raw_input("<0>"))
    print "Also enter the final concentration in microliters you want sortase to be. Usually we use 5 or 10"
    sortase_final = float(raw_input("<0>"))
    print "Third, enter the concentration of nucleophile, rrACB"
    acb_stock = float(raw_input("<0>"))
    print "Fourth, enter the concentration of lxptg substrate, r-mod-n"
    n_stock = float(raw_input("<0>"))
    print "Finally enter the ratio of the nucleophile to substrate, usally 5:1 (just enter 5 for this, 10 for 10:1)"
    ratio = float(raw_input("<0>"))
    print "Working.............................................."
    
    sort_volume = (total_volume * sortase_final) / sortase_stock
    volleft = (total_volume) - (sort_volume)
    n_conc_final = (volleft / total_volume) / ((ratio / acb_stock) + (1 / n_stock))
    acb_conc_final = (n_conc_final * ratio)
    acb_volume = (acb_conc_final * total_volume ) / (acb_stock)
    n_volume = (n_conc_final * total_volume) / (n_stock)

    print "The amount of sortase to use is:", sort_volume, "in uL"
    print "The amount of nucleophile (acb) to use is", acb_volume, "uL"
    print "The concentration of nucleophile (acb) will be", acb_conc_final,  "uM"
    print "The amount of substrate (nterm) to use is", n_volume, "uL"
    print "The concentration of substrate (nterm) will be", n_conc_final, "uM"
    return n_volume, n_stock, ratio, acb_volume, acb_stock, sortase_stock, sortase_final, sort_volume, total_volume, n_conc_final, acb_conc_final

    
def lxptg_sub_calc():
    print "Enter volume lxptg (rmn) you want to use"
    n_volume = float(raw_input("> "))
    print "Enter concentration lxptg (rmn) this is"
    n_stock = float(raw_input("> "))
    print "Enter the ratio to ACB"
    ratio = float(raw_input("> "))
    print "Enter the stock ACB concentration"
    acb_stock = float(raw_input("> "))
    print "Enter stock sortase concentration"
    sortase_stock = float(raw_input("> "))
    print "Enter final desired sortase concentration (usually 5 uM)"
    sortase_final = float(raw_input("> "))

    test_list = [n_volume, n_stock, ratio, acb_stock, sortase_stock, sortase_final]

    '''
    for item in test_list:
        if item >= 0.01:
            print "oops, you entered a string"
            lxptg_sub()
        elif item <= 20000:
            print "oops, you entered a string"
            lxptg_sub()
        else:
            print "okay...."
    '''


    #begin calculation
    acb_volume = ( n_stock * n_volume * ratio ) / acb_stock
    pre_volume = acb_volume + n_volume
    sort_volume = (pre_volume * sortase_final) / sortase_stock
    total_volume = pre_volume + sort_volume
    n_conc_final = n_stock * n_volume / total_volume
    acb_conc_final = acb_stock * acb_volume / total_volume
    #return entered and calculated variables
    return n_volume, n_stock, ratio, acb_volume, acb_stock, sortase_stock, sortase_final, sort_volume, total_volume, n_conc_final, acb_conc_final

def product_calc():
    """ none yet """
    
def total_volume():
    n_volume, n_stock, ratio, acb_volume, acb_stock, sortase_stock, sortase_final, sort_volume, total_volume, n_conc_final, acb_conc_final = total_volume_calc()
    write_file_newvar(n_volume, n_stock, ratio, acb_volume, acb_stock, sortase_stock, sortase_final, sort_volume, total_volume, n_conc_final, acb_conc_final)
    
def lxptg_sub():
    #calls function to calculate, assigns variables
    n_volume, n_stock, ratio, acb_volume, acb_stock, sortase_stock, sortase_final, sort_volume, total_volume, n_conc_final, acb_conc_final = lxptg_sub_calc()
    #calls write function with variables from above
    write_file_newvar(n_volume, n_stock, ratio, acb_volume, acb_stock, sortase_stock, sortase_final, sort_volume, total_volume, n_conc_final, acb_conc_final)

def product():
    n_volume, n_stock, ratio, acb_volume, acb_stock, sortase_stock, sortase_final, sort_volume, total_volume, n_conc_final, acb_conc_final = product_calc()
    write_file_newvar(n_volume, n_stock, ratio, acb_volume, acb_stock, sortase_stock, sortase_final, sort_volume, total_volume, n_conc_final, acb_conc_final)
    
def main():
    print "This calculator helps set up sortase reactions"
    print ""
    print """Chose:
    \t 1) To calculate based on total volume
    \t 2) To calculate based on limiting reagent (lxptg substate /rmn)
    \t 3) To calculate based on total moles of product desired
    """
    go = raw_input("> ")
    if go == "1":
        total_volume()
    elif go == "2":
        lxptg_sub()
    elif go == "3":
        product()
    else:
        print ""
        print "\t I didnt understand that, please enter A NUMBER 1-3!"
        print ""
        main()
        
	return 0
	
	
if __name__ == '__main__':
	main()







    

