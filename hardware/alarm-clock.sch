EESchema Schematic File Version 2
LIBS:power
LIBS:device
LIBS:transistors
LIBS:conn
LIBS:linear
LIBS:regul
LIBS:74xx
LIBS:cmos4000
LIBS:adc-dac
LIBS:memory
LIBS:xilinx
LIBS:microcontrollers
LIBS:dsp
LIBS:microchip
LIBS:analog_switches
LIBS:motorola
LIBS:texas
LIBS:intel
LIBS:audio
LIBS:interface
LIBS:digital-audio
LIBS:philips
LIBS:display
LIBS:cypress
LIBS:siliconi
LIBS:opto
LIBS:atmel
LIBS:contrib
LIBS:valves
LIBS:parts
LIBS:Common Part Library
LIBS:alarm-clock-cache
EELAYER 25 0
EELAYER END
$Descr USLetter 11000 8500
encoding utf-8
Sheet 1 1
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L SW_PUSH SW2
U 1 1 580C2F63
P 4050 4350
F 0 "SW2" H 4200 4460 50  0000 C CNN
F 1 "SW_PUSH" H 4050 4270 50  0000 C CNN
F 2 "Buttons_Switches_ThroughHole:SW_PUSH-12mm" H 4050 4350 50  0001 C CNN
F 3 "" H 4050 4350 50  0000 C CNN
	1    4050 4350
	1    0    0    -1  
$EndComp
$Comp
L R R7
U 1 1 580C2FBA
P 5750 3850
F 0 "R7" V 5830 3850 50  0000 C CNN
F 1 "2.2k" V 5750 3850 50  0000 C CNN
F 2 "Resistors_ThroughHole:Resistor_Horizontal_RM7mm" V 5680 3850 50  0001 C CNN
F 3 "" H 5750 3850 50  0000 C CNN
	1    5750 3850
	1    0    0    -1  
$EndComp
$Comp
L R R11
U 1 1 580C3149
P 6050 3600
F 0 "R11" V 6130 3600 50  0000 C CNN
F 1 "2.2k" V 6050 3600 50  0000 C CNN
F 2 "Resistors_ThroughHole:Resistor_Horizontal_RM7mm" V 5980 3600 50  0001 C CNN
F 3 "" H 6050 3600 50  0000 C CNN
	1    6050 3600
	1    0    0    -1  
$EndComp
$Comp
L R R8
U 1 1 580C3190
P 5850 1800
F 0 "R8" V 5930 1800 50  0000 C CNN
F 1 "2.2k" V 5850 1800 50  0000 C CNN
F 2 "Resistors_ThroughHole:Resistor_Horizontal_RM7mm" V 5780 1800 50  0001 C CNN
F 3 "" H 5850 1800 50  0000 C CNN
	1    5850 1800
	1    0    0    -1  
$EndComp
$Comp
L R R6
U 1 1 580C3257
P 5750 2050
F 0 "R6" V 5830 2050 50  0000 C CNN
F 1 "2.2k" V 5750 2050 50  0000 C CNN
F 2 "Resistors_ThroughHole:Resistor_Horizontal_RM7mm" V 5680 2050 50  0001 C CNN
F 3 "" H 5750 2050 50  0000 C CNN
	1    5750 2050
	1    0    0    -1  
$EndComp
$Comp
L R R12
U 1 1 580C328F
P 6150 2050
F 0 "R12" V 6230 2050 50  0000 C CNN
F 1 "2.2k" V 6150 2050 50  0000 C CNN
F 2 "Resistors_ThroughHole:Resistor_Horizontal_RM7mm" V 6080 2050 50  0001 C CNN
F 3 "" H 6150 2050 50  0000 C CNN
	1    6150 2050
	1    0    0    -1  
$EndComp
$Comp
L R R10
U 1 1 580C30EC
P 5950 3850
F 0 "R10" V 6030 3850 50  0000 C CNN
F 1 "2.2k" V 5950 3850 50  0000 C CNN
F 2 "Resistors_ThroughHole:Resistor_Horizontal_RM7mm" V 5880 3850 50  0001 C CNN
F 3 "" H 5950 3850 50  0000 C CNN
	1    5950 3850
	1    0    0    -1  
$EndComp
$Comp
L R R9
U 1 1 580C3214
P 5850 3600
F 0 "R9" V 5930 3600 50  0000 C CNN
F 1 "2.2k" V 5850 3600 50  0000 C CNN
F 2 "Resistors_ThroughHole:Resistor_Horizontal_RM7mm" V 5780 3600 50  0001 C CNN
F 3 "" H 5850 3600 50  0000 C CNN
	1    5850 3600
	1    0    0    -1  
$EndComp
$Comp
L R R5
U 1 1 580C31DA
P 5650 3600
F 0 "R5" V 5730 3600 50  0000 C CNN
F 1 "2.2k" V 5650 3600 50  0000 C CNN
F 2 "Resistors_ThroughHole:Resistor_Horizontal_RM7mm" V 5580 3600 50  0001 C CNN
F 3 "" H 5650 3600 50  0000 C CNN
	1    5650 3600
	1    0    0    -1  
$EndComp
$Comp
L R R13
U 1 1 580D1B6C
P 6250 1800
F 0 "R13" V 6330 1800 50  0000 C CNN
F 1 "2.2k" V 6250 1800 50  0000 C CNN
F 2 "Resistors_ThroughHole:Resistor_Horizontal_RM7mm" V 6180 1800 50  0001 C CNN
F 3 "" H 6250 1800 50  0000 C CNN
	1    6250 1800
	1    0    0    -1  
$EndComp
Text GLabel 4000 1050 2    60   Input ~ 0
PB0
Text GLabel 6050 4000 3    60   Input ~ 0
PD4
Text GLabel 4000 1150 2    60   Input ~ 0
PB1
Text GLabel 4000 1250 2    60   Input ~ 0
PB2
Text GLabel 4000 1350 2    60   Input ~ 0
PB3
Text GLabel 4000 1450 2    60   Input ~ 0
PB4
Text GLabel 4000 2100 2    60   Input ~ 0
PC2
Text GLabel 4000 2200 2    60   Input ~ 0
PC3
Text GLabel 4000 2300 2    60   Input ~ 0
PC4
Text GLabel 4000 2400 2    60   Input ~ 0
PC5
Text GLabel 4000 2650 2    60   Input ~ 0
PD0
Text GLabel 4000 2750 2    60   Input ~ 0
PD1
Text GLabel 4000 2850 2    60   Input ~ 0
PD2
Text GLabel 4000 2950 2    60   Input ~ 0
PD3
Text GLabel 4000 3150 2    60   Input ~ 0
PD5
Text GLabel 4000 3250 2    60   Input ~ 0
PD6
Text GLabel 4000 3350 2    60   Input ~ 0
PD7
$Comp
L Crystal_Small Y2
U 1 1 580D3237
P 4450 1700
F 0 "Y2" H 4450 1800 50  0000 C CNN
F 1 "16MHz" H 4450 1600 50  0000 C CNN
F 2 "Crystals:Crystal_HC50-U_Vertical" H 4450 1700 50  0001 C CNN
F 3 "" H 4450 1700 50  0000 C CNN
	1    4450 1700
	0    -1   -1   0   
$EndComp
$Comp
L CP1_Small C1
U 1 1 580D3F40
P 1200 3150
F 0 "C1" H 1210 3220 50  0000 L CNN
F 1 "10µF" H 1210 3070 50  0000 L CNN
F 2 "Capacitors_ThroughHole:C_Radial_D5_L11_P2" H 1200 3150 50  0001 C CNN
F 3 "" H 1200 3150 50  0000 C CNN
	1    1200 3150
	0    -1   -1   0   
$EndComp
$Comp
L CP1_Small C3
U 1 1 580D3FDC
P 1600 3150
F 0 "C3" H 1610 3220 50  0000 L CNN
F 1 "1µF" H 1610 3070 50  0000 L CNN
F 2 "Capacitors_ThroughHole:C_Radial_D6.3_L11.2_P2.5" H 1600 3150 50  0001 C CNN
F 3 "" H 1600 3150 50  0000 C CNN
	1    1600 3150
	0    1    1    0   
$EndComp
$Comp
L D D1
U 1 1 580D432E
P 1400 2350
F 0 "D1" H 1400 2450 50  0000 C CNN
F 1 "D" H 1400 2250 50  0000 C CNN
F 2 "Diodes_THT:Diode_DO-41_SOD81_Horizontal_RM10" H 1400 2350 50  0001 C CNN
F 3 "" H 1400 2350 50  0000 C CNN
	1    1400 2350
	1    0    0    -1  
$EndComp
Text GLabel 3250 6000 2    60   Input ~ 0
PC5
Text GLabel 3000 6100 2    60   Input ~ 0
PC4
$Comp
L Battery BT1
U 1 1 580D4C5B
P 1250 6150
F 0 "BT1" H 1350 6200 50  0000 L CNN
F 1 "3V" H 1350 6100 50  0000 L CNN
F 2 "custom:CR2032" V 1250 6190 50  0001 C CNN
F 3 "" V 1250 6190 50  0000 C CNN
	1    1250 6150
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR01
U 1 1 580D4D32
P 1250 6300
F 0 "#PWR01" H 1250 6050 50  0001 C CNN
F 1 "GND" H 1250 6150 50  0000 C CNN
F 2 "" H 1250 6300 50  0000 C CNN
F 3 "" H 1250 6300 50  0000 C CNN
	1    1250 6300
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR02
U 1 1 580D4F57
P 1750 6100
F 0 "#PWR02" H 1750 5850 50  0001 C CNN
F 1 "GND" H 1750 5950 50  0000 C CNN
F 2 "" H 1750 6100 50  0000 C CNN
F 3 "" H 1750 6100 50  0000 C CNN
	1    1750 6100
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR03
U 1 1 580D5051
P 2100 3350
F 0 "#PWR03" H 2100 3100 50  0001 C CNN
F 1 "GND" H 2100 3200 50  0000 C CNN
F 2 "" H 2100 3350 50  0000 C CNN
F 3 "" H 2100 3350 50  0000 C CNN
	1    2100 3350
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR04
U 1 1 580D5134
P 1400 3250
F 0 "#PWR04" H 1400 3000 50  0001 C CNN
F 1 "GND" H 1400 3100 50  0000 C CNN
F 2 "" H 1400 3250 50  0000 C CNN
F 3 "" H 1400 3250 50  0000 C CNN
	1    1400 3250
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR05
U 1 1 580D51A4
P 5000 1700
F 0 "#PWR05" H 5000 1450 50  0001 C CNN
F 1 "GND" H 5000 1550 50  0000 C CNN
F 2 "" H 5000 1700 50  0000 C CNN
F 3 "" H 5000 1700 50  0000 C CNN
	1    5000 1700
	1    0    0    -1  
$EndComp
$Comp
L Crystal_Small Y1
U 1 1 580D5384
P 1550 5800
F 0 "Y1" H 1550 5900 50  0000 C CNN
F 1 "38.7kHz" H 1550 5700 50  0000 C CNN
F 2 "Crystals:Crystal_Round_Vertical_2mm" H 1550 5800 50  0001 C CNN
F 3 "" H 1550 5800 50  0000 C CNN
	1    1550 5800
	1    0    0    -1  
$EndComp
$Comp
L SW_PUSH SW3
U 1 1 580D5596
P 4050 4700
F 0 "SW3" H 4200 4810 50  0000 C CNN
F 1 "SW_PUSH" H 4050 4620 50  0000 C CNN
F 2 "Buttons_Switches_ThroughHole:SW_PUSH-12mm" H 4050 4700 50  0001 C CNN
F 3 "" H 4050 4700 50  0000 C CNN
	1    4050 4700
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR06
U 1 1 580D567E
P 4350 4700
F 0 "#PWR06" H 4350 4450 50  0001 C CNN
F 1 "GND" H 4350 4550 50  0000 C CNN
F 2 "" H 4350 4700 50  0000 C CNN
F 3 "" H 4350 4700 50  0000 C CNN
	1    4350 4700
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR07
U 1 1 580D56DD
P 4350 4350
F 0 "#PWR07" H 4350 4100 50  0001 C CNN
F 1 "GND" H 4350 4200 50  0000 C CNN
F 2 "" H 4350 4350 50  0000 C CNN
F 3 "" H 4350 4350 50  0000 C CNN
	1    4350 4350
	1    0    0    -1  
$EndComp
Text GLabel 3750 4350 0    60   Input ~ 0
PD0
Text GLabel 3750 4700 0    60   Input ~ 0
PD1
$Comp
L Q_NPN_BCE Q1
U 1 1 580D59B6
P 1700 4400
F 0 "Q1" H 2000 4450 50  0000 R CNN
F 1 "Q_NPN_BCE" H 2300 4350 50  0000 R CNN
F 2 "TO_SOT_Packages_THT:TO-92_Inline_Narrow_Oval" H 1900 4500 50  0001 C CNN
F 3 "" H 1700 4400 50  0000 C CNN
	1    1700 4400
	0    1    1    0   
$EndComp
$Comp
L GND #PWR08
U 1 1 580D5E88
P 2000 4500
F 0 "#PWR08" H 2000 4250 50  0001 C CNN
F 1 "GND" H 2000 4350 50  0000 C CNN
F 2 "" H 2000 4500 50  0000 C CNN
F 3 "" H 2000 4500 50  0000 C CNN
	1    2000 4500
	1    0    0    -1  
$EndComp
$Comp
L R R1
U 1 1 580D5FB2
P 1700 4050
F 0 "R1" V 1780 4050 50  0000 C CNN
F 1 "3.3k" V 1700 4050 50  0000 C CNN
F 2 "Resistors_ThroughHole:Resistor_Horizontal_RM7mm" V 1630 4050 50  0001 C CNN
F 3 "" H 1700 4050 50  0000 C CNN
	1    1700 4050
	1    0    0    -1  
$EndComp
Text GLabel 1700 3850 1    60   Input ~ 0
PC3
Text GLabel 5950 4000 3    60   Input ~ 0
PD5
Text GLabel 5850 4000 3    60   Input ~ 0
PD6
Text GLabel 6150 1650 1    60   Input ~ 0
PC0
Text GLabel 5850 1650 1    60   Input ~ 0
PB3
Text GLabel 5750 1650 1    60   Input ~ 0
PB2
Text GLabel 5650 4000 3    60   Input ~ 0
PB0
Text GLabel 5750 4000 3    60   Input ~ 0
PD7
Text GLabel 4000 1900 2    60   Input ~ 0
PC0
Text GLabel 4000 2000 2    60   Input ~ 0
PC1
Text GLabel 6250 1650 1    60   Input ~ 0
PC1
$Comp
L GND #PWR09
U 1 1 580DA773
P 3500 5550
F 0 "#PWR09" H 3500 5300 50  0001 C CNN
F 1 "GND" H 3500 5400 50  0000 C CNN
F 2 "" H 3500 5550 50  0000 C CNN
F 3 "" H 3500 5550 50  0000 C CNN
	1    3500 5550
	1    0    0    -1  
$EndComp
Text GLabel 4500 5450 2    60   Input ~ 0
PD2
$Comp
L SPEAKER SP1
U 1 1 580DAB0A
P 2900 4550
F 0 "SP1" H 2800 4800 50  0000 C CNN
F 1 "BUZZER" H 2800 4300 50  0000 C CNN
F 2 "Buzzers_Beepers:Buzzer_12x9.5RM7.6" H 2900 4550 50  0001 C CNN
F 3 "" H 2900 4550 50  0000 C CNN
	1    2900 4550
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR010
U 1 1 580DAD7E
P 2450 4650
F 0 "#PWR010" H 2450 4400 50  0001 C CNN
F 1 "GND" H 2450 4500 50  0000 C CNN
F 2 "" H 2450 4650 50  0000 C CNN
F 3 "" H 2450 4650 50  0000 C CNN
	1    2450 4650
	1    0    0    -1  
$EndComp
Text GLabel 2600 4450 0    60   Input ~ 0
PC2
$Comp
L C_Small C5
U 1 1 580DB46E
P 4700 1500
F 0 "C5" H 4710 1570 50  0000 L CNN
F 1 "20pF" H 4710 1420 50  0000 L CNN
F 2 "Capacitors_ThroughHole:C_Disc_D3_P2.5" H 4700 1500 50  0001 C CNN
F 3 "" H 4700 1500 50  0000 C CNN
	1    4700 1500
	0    1    1    0   
$EndComp
$Comp
L C_Small C6
U 1 1 580DB5B3
P 4700 1900
F 0 "C6" H 4710 1970 50  0000 L CNN
F 1 "20pF" H 4710 1820 50  0000 L CNN
F 2 "Capacitors_ThroughHole:C_Disc_D3_P2.5" H 4700 1900 50  0001 C CNN
F 3 "" H 4700 1900 50  0000 C CNN
	1    4700 1900
	0    1    1    0   
$EndComp
$Comp
L +5V #PWR011
U 1 1 580DD982
P 2650 5800
F 0 "#PWR011" H 2650 5650 50  0001 C CNN
F 1 "+5V" H 2650 5940 50  0000 C CNN
F 2 "" H 2650 5800 50  0000 C CNN
F 3 "" H 2650 5800 50  0000 C CNN
	1    2650 5800
	1    0    0    -1  
$EndComp
$Comp
L +5V #PWR012
U 1 1 580DDA0B
P 2800 5550
F 0 "#PWR012" H 2800 5400 50  0001 C CNN
F 1 "+5V" H 2800 5690 50  0000 C CNN
F 2 "" H 2800 5550 50  0000 C CNN
F 3 "" H 2800 5550 50  0000 C CNN
	1    2800 5550
	1    0    0    -1  
$EndComp
$Comp
L +5V #PWR013
U 1 1 580DDA94
P 3000 5550
F 0 "#PWR013" H 3000 5400 50  0001 C CNN
F 1 "+5V" H 3000 5690 50  0000 C CNN
F 2 "" H 3000 5550 50  0000 C CNN
F 3 "" H 3000 5550 50  0000 C CNN
	1    3000 5550
	1    0    0    -1  
$EndComp
$Comp
L R R2
U 1 1 580DDBE0
P 2800 5700
F 0 "R2" V 2880 5700 50  0000 C CNN
F 1 "2.2k" V 2800 5700 50  0000 C CNN
F 2 "Resistors_ThroughHole:Resistor_Horizontal_RM7mm" V 2730 5700 50  0001 C CNN
F 3 "" H 2800 5700 50  0000 C CNN
	1    2800 5700
	1    0    0    -1  
$EndComp
$Comp
L R R3
U 1 1 580DDCFE
P 3000 5700
F 0 "R3" V 3080 5700 50  0000 C CNN
F 1 "2.2k" V 3000 5700 50  0000 C CNN
F 2 "Resistors_ThroughHole:Resistor_Horizontal_RM7mm" V 2930 5700 50  0001 C CNN
F 3 "" H 3000 5700 50  0000 C CNN
	1    3000 5700
	1    0    0    -1  
$EndComp
$Comp
L +5V #PWR014
U 1 1 580DF563
P 1950 2700
F 0 "#PWR014" H 1950 2550 50  0001 C CNN
F 1 "+5V" H 1950 2840 50  0000 C CNN
F 2 "" H 1950 2700 50  0000 C CNN
F 3 "" H 1950 2700 50  0000 C CNN
	1    1950 2700
	1    0    0    -1  
$EndComp
$Comp
L +5V #PWR015
U 1 1 580DF644
P 2100 1050
F 0 "#PWR015" H 2100 900 50  0001 C CNN
F 1 "+5V" H 2100 1190 50  0000 C CNN
F 2 "" H 2100 1050 50  0000 C CNN
F 3 "" H 2100 1050 50  0000 C CNN
	1    2100 1050
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR016
U 1 1 580DF8BC
P 2100 3250
F 0 "#PWR016" H 2100 3000 50  0001 C CNN
F 1 "GND" H 2100 3100 50  0000 C CNN
F 2 "" H 2100 3250 50  0000 C CNN
F 3 "" H 2100 3250 50  0000 C CNN
	1    2100 3250
	1    0    0    -1  
$EndComp
$Comp
L VPP #PWR017
U 1 1 580E043A
P 850 2700
F 0 "#PWR017" H 850 2550 50  0001 C CNN
F 1 "VPP" H 850 2850 50  0000 C CNN
F 2 "" H 850 2700 50  0000 C CNN
F 3 "" H 850 2700 50  0000 C CNN
	1    850  2700
	1    0    0    -1  
$EndComp
$Comp
L PWR_FLAG #FLG018
U 1 1 581E8BD4
P 950 700
F 0 "#FLG018" H 950 795 50  0001 C CNN
F 1 "PWR_FLAG" H 950 880 50  0000 C CNN
F 2 "" H 950 700 50  0000 C CNN
F 3 "" H 950 700 50  0000 C CNN
	1    950  700 
	1    0    0    -1  
$EndComp
$Comp
L PWR_FLAG #FLG019
U 1 1 581E8CBA
P 950 950
F 0 "#FLG019" H 950 1045 50  0001 C CNN
F 1 "PWR_FLAG" H 950 1130 50  0000 C CNN
F 2 "" H 950 950 50  0000 C CNN
F 3 "" H 950 950 50  0000 C CNN
	1    950  950 
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR020
U 1 1 581E8FC3
P 650 950
F 0 "#PWR020" H 650 700 50  0001 C CNN
F 1 "GND" H 650 800 50  0000 C CNN
F 2 "" H 650 950 50  0000 C CNN
F 3 "" H 650 950 50  0000 C CNN
	1    650  950 
	1    0    0    -1  
$EndComp
$Comp
L VPP #PWR021
U 1 1 581E97E3
P 650 700
F 0 "#PWR021" H 650 550 50  0001 C CNN
F 1 "VPP" H 650 850 50  0000 C CNN
F 2 "" H 650 700 50  0000 C CNN
F 3 "" H 650 700 50  0000 C CNN
	1    650  700 
	1    0    0    -1  
$EndComp
NoConn ~ 2650 5900
NoConn ~ 4000 2500
NoConn ~ 2100 1650
NoConn ~ 2100 1350
$Comp
L 4Dig7Seg U3
U 1 1 581F8DB4
P 5950 2850
F 0 "U3" H 4950 3200 60  0000 C CNN
F 1 "4Dig7Seg" H 6800 3200 60  0000 C CNN
F 2 "custom:4Dig7Seg" H 6750 2500 60  0000 C CNN
F 3 "" H 6750 2500 60  0001 C CNN
	1    5950 2850
	1    0    0    -1  
$EndComp
Wire Wire Line
	4300 1650 4300 1600
Wire Wire Line
	4300 1600 4450 1600
Wire Wire Line
	4300 1750 4300 1800
Wire Wire Line
	4300 1800 4450 1800
Wire Wire Line
	4450 1800 4450 1900
Wire Wire Line
	4450 1900 4600 1900
Wire Wire Line
	4450 1600 4450 1500
Wire Wire Line
	4450 1500 4600 1500
Wire Wire Line
	4900 1900 4800 1900
Wire Wire Line
	4900 1500 4900 1900
Wire Wire Line
	4900 1500 4800 1500
Wire Wire Line
	4900 1700 5000 1700
Connection ~ 4900 1700
Wire Wire Line
	1300 3150 1500 3150
Wire Wire Line
	1400 3000 1400 3250
Connection ~ 1400 3150
Wire Wire Line
	1800 3150 1700 3150
Wire Wire Line
	1800 2350 1800 3150
Wire Wire Line
	1000 2350 1000 3150
Wire Wire Line
	1000 3150 1100 3150
Wire Wire Line
	1800 2350 1550 2350
Connection ~ 1800 2700
Wire Wire Line
	1250 2350 1000 2350
Connection ~ 1000 2700
Wire Wire Line
	1950 2700 1800 2700
Wire Wire Line
	850  2700 1000 2700
Wire Wire Line
	2650 6000 3250 6000
Wire Wire Line
	2650 6100 3000 6100
Wire Wire Line
	1250 6000 1750 6000
Wire Wire Line
	1650 5800 1750 5800
Wire Wire Line
	1350 5900 1750 5900
Wire Wire Line
	1350 5550 1350 5900
Wire Wire Line
	1350 5800 1450 5800
Wire Wire Line
	1250 4500 1500 4500
Wire Wire Line
	1900 4500 2000 4500
Wire Wire Line
	1700 3900 1700 3850
Wire Wire Line
	4000 1750 4300 1750
Wire Wire Line
	4000 1650 4300 1650
Wire Wire Line
	2450 4650 2600 4650
Wire Wire Line
	2800 5850 2800 6100
Connection ~ 2800 6100
Wire Wire Line
	3000 5850 3000 6000
Connection ~ 3000 6000
Wire Wire Line
	650  700  950  700 
Wire Wire Line
	650  950  950  950 
Wire Wire Line
	5850 1950 5850 2200
Wire Wire Line
	6250 2200 6250 1950
Wire Wire Line
	5950 3700 5950 3450
Wire Wire Line
	5750 3700 5750 3450
$Comp
L GND #PWR022
U 1 1 581FB1F9
P 6250 3450
F 0 "#PWR022" H 6250 3200 50  0001 C CNN
F 1 "GND" H 6250 3300 50  0000 C CNN
F 2 "" H 6250 3450 50  0000 C CNN
F 3 "" H 6250 3450 50  0000 C CNN
	1    6250 3450
	1    0    0    -1  
$EndComp
Wire Wire Line
	5750 1650 5750 1900
Wire Wire Line
	6150 1650 6150 1900
Wire Wire Line
	5650 4000 5650 3750
Wire Wire Line
	5850 4000 5850 3750
Wire Wire Line
	6050 4000 6050 3750
Text GLabel 5650 1650 1    60   Input ~ 0
PB1
Text GLabel 5950 1650 1    60   Input ~ 0
PB4
Text GLabel 6050 1650 1    60   Input ~ 0
PB5
Text GLabel 6150 4000 3    60   Input ~ 0
PD3
Wire Wire Line
	5650 2200 5650 1650
Wire Wire Line
	5950 2200 5950 1650
Wire Wire Line
	6050 2200 6050 1650
Wire Wire Line
	6150 4000 6150 3450
$Comp
L DS1307 U2
U 1 1 58202732
P 2150 5900
F 0 "U2" H 2150 5900 50  0001 L CNN
F 1 "DS1307" H 2150 5900 50  0001 L CNN
F 2 "Housings_DIP:DIP-8_W7.62mm_LongPads" H 2150 5900 60  0001 C CNN
F 3 "Maxim Integrated" H 2150 5900 50  0001 L CNN
F 4 "Unavailable" H 2150 5900 50  0001 L CNN "Availability"
F 5 "1.32 USD" H 2150 5900 50  0001 L CNN "Price"
F 6 "DIP-8 Maxim Integrated" H 2150 5900 50  0001 L CNN "Package"
F 7 "DS1307" H 2150 5900 50  0001 L CNN "MP"
F 8 "Ic Rtc Clk/Calendar I2c 8-Dip" H 2150 5900 50  0001 L CNN "Description"
	1    2150 5900
	1    0    0    -1  
$EndComp
$Comp
L BARREL_JACK CON1
U 1 1 5820329B
P 950 3750
F 0 "CON1" H 950 4000 50  0000 C CNN
F 1 "BARREL_JACK" H 950 3550 50  0000 C CNN
F 2 "Connectors:BARREL_JACK" H 950 3750 50  0001 C CNN
F 3 "" H 950 3750 50  0000 C CNN
	1    950  3750
	1    0    0    -1  
$EndComp
$Comp
L BARREL_JACK CON2
U 1 1 5820332A
P 950 4500
F 0 "CON2" H 950 4750 50  0000 C CNN
F 1 "BARREL_JACK" H 950 4300 50  0000 C CNN
F 2 "Connectors:BARREL_JACK" H 950 4500 50  0001 C CNN
F 3 "" H 950 4500 50  0000 C CNN
	1    950  4500
	1    0    0    -1  
$EndComp
$Comp
L VPP #PWR023
U 1 1 58203612
P 1250 4400
F 0 "#PWR023" H 1250 4250 50  0001 C CNN
F 1 "VPP" H 1250 4550 50  0000 C CNN
F 2 "" H 1250 4400 50  0000 C CNN
F 3 "" H 1250 4400 50  0000 C CNN
	1    1250 4400
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR024
U 1 1 582036C2
P 1250 3850
F 0 "#PWR024" H 1250 3600 50  0001 C CNN
F 1 "GND" H 1250 3700 50  0000 C CNN
F 2 "" H 1250 3850 50  0000 C CNN
F 3 "" H 1250 3850 50  0000 C CNN
	1    1250 3850
	1    0    0    -1  
$EndComp
$Comp
L VPP #PWR025
U 1 1 58203748
P 1250 3650
F 0 "#PWR025" H 1250 3500 50  0001 C CNN
F 1 "VPP" H 1250 3800 50  0000 C CNN
F 2 "" H 1250 3650 50  0000 C CNN
F 3 "" H 1250 3650 50  0000 C CNN
	1    1250 3650
	1    0    0    -1  
$EndComp
Wire Wire Line
	1250 3750 1250 3850
Wire Wire Line
	1250 4500 1250 4600
$Comp
L SWITCH_INV SW1
U 1 1 582208B3
P 4000 5550
F 0 "SW1" H 3800 5700 50  0000 C CNN
F 1 "SWITCH_INV" H 3850 5400 50  0000 C CNN
F 2 "Buttons_Switches_THT:SW_Micro_SPST" H 4000 5550 50  0001 C CNN
F 3 "" H 4000 5550 50  0000 C CNN
	1    4000 5550
	1    0    0    -1  
$EndComp
$Comp
L LED D2
U 1 1 58220B55
P 4700 5650
F 0 "D2" H 4700 5750 50  0000 C CNN
F 1 "LED" H 4700 5550 50  0000 C CNN
F 2 "LEDs:LED-5MM" H 4700 5650 50  0001 C CNN
F 3 "" H 4700 5650 50  0000 C CNN
	1    4700 5650
	1    0    0    -1  
$EndComp
$Comp
L R R4
U 1 1 58220BE8
P 5050 5650
F 0 "R4" V 5130 5650 50  0000 C CNN
F 1 "270" V 5050 5650 50  0000 C CNN
F 2 "Resistors_ThroughHole:Resistor_Horizontal_RM7mm" V 4980 5650 50  0001 C CNN
F 3 "" H 5050 5650 50  0000 C CNN
	1    5050 5650
	0    1    1    0   
$EndComp
$Comp
L LM7805CT U1
U 1 1 582252D4
P 1400 2750
F 0 "U1" H 1200 2950 50  0000 C CNN
F 1 "LM7805CT" H 1400 2950 50  0000 L CNN
F 2 "Power_Integrations:TO-220" H 1400 2850 50  0000 C CIN
F 3 "" H 1400 2750 50  0000 C CNN
	1    1400 2750
	1    0    0    -1  
$EndComp
Text GLabel 4000 1550 2    60   Input ~ 0
PB5
$Comp
L ATMEGA328-P IC1
U 1 1 581EA9E9
P 3000 2150
F 0 "IC1" H 2250 3400 50  0000 L BNN
F 1 "ATMEGA328-P" H 3400 750 50  0000 L BNN
F 2 "Housings_DIP:DIP-28_W7.62mm" H 3000 2150 50  0000 C CIN
F 3 "" H 3000 2150 50  0000 C CNN
	1    3000 2150
	1    0    0    -1  
$EndComp
$Comp
L +5V #PWR026
U 1 1 58227C48
P 5200 5650
F 0 "#PWR026" H 5200 5500 50  0001 C CNN
F 1 "+5V" H 5200 5790 50  0000 C CNN
F 2 "" H 5200 5650 50  0000 C CNN
F 3 "" H 5200 5650 50  0000 C CNN
	1    5200 5650
	1    0    0    -1  
$EndComp
Text GLabel 4000 3050 2    60   Input ~ 0
PD4
$Comp
L C_Small C?
U 1 1 5823D955
P 1350 5450
F 0 "C?" H 1360 5520 50  0000 L CNN
F 1 "C_Small" H 1360 5370 50  0000 L CNN
F 2 "" H 1350 5450 50  0000 C CNN
F 3 "" H 1350 5450 50  0000 C CNN
	1    1350 5450
	1    0    0    -1  
$EndComp
$Comp
L C_Small C4
U 1 1 5823D9D7
P 1700 5450
F 0 "C4" H 1710 5520 50  0000 L CNN
F 1 "12.5pF" H 1710 5370 50  0000 L CNN
F 2 "Capacitors_ThroughHole:C_Disc_D3_P2.5" H 1700 5450 50  0001 C CNN
F 3 "" H 1700 5450 50  0000 C CNN
	1    1700 5450
	1    0    0    -1  
$EndComp
Connection ~ 1350 5800
Wire Wire Line
	1700 5800 1700 5550
Connection ~ 1700 5800
Wire Wire Line
	1350 5350 1350 5250
Wire Wire Line
	950  5250 1700 5250
Wire Wire Line
	1700 5250 1700 5350
Wire Wire Line
	950  5250 950  5350
Connection ~ 1350 5250
$Comp
L GND #PWR027
U 1 1 5823DC58
P 950 5350
F 0 "#PWR027" H 950 5100 50  0001 C CNN
F 1 "GND" H 950 5200 50  0000 C CNN
F 2 "" H 950 5350 50  0000 C CNN
F 3 "" H 950 5350 50  0000 C CNN
	1    950  5350
	1    0    0    -1  
$EndComp
$EndSCHEMATC
