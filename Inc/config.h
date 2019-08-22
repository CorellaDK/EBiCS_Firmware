//place all your personal configurations here and keep this file when updating!
#ifndef CONFIG_H
#define CONFIG_H
#include "stdint.h"

#define DISPLAY_TYPE_KINGMETER_618U (1<<4)                  // King-Meter 618U protocol (KM5s, EBS-LCD2, J-LCD, SW-LCD)
#define DISPLAY_TYPE_KINGMETER_901U (1<<8)                  // King-Meter 901U protocol (KM5s)
#define DISPLAY_TYPE_KINGMETER      (DISPLAY_TYPE_KINGMETER_618U|DISPLAY_TYPE_KINGMETER_901U)
#define DISPLAY_TYPE DISPLAY_TYPE_KINGMETER_901U

#define wheel_circumference 2.202 	//wheel circumference in m
#define THROTTLE_OFFSET 690//1210 			//ADC-value at closed throttle 670 for throttle, 1255 for TS
#define THROTTLE_MAX 3015
#define TS_COEF 2000				//coefficient for torque-sensor-mode
//#define TS_MODE						//Torquesensor-Mode
#define PAS_TIMEOUT 12000			//time tics @ 16kHz untils motor stops
#define RAMP_END 4000					//time tics @ 16kHz where motor reaches full level power
#define PH_CURRENT_MAX 380			//iq value (phase current in rotating frame), not calibrated yet

#define P_FACTOR_I_Q 1L				//proportional factor for PI control of iq
#define I_FACTOR_I_Q 0.1F			//integral factor for PI control of iq
#define P_FACTOR_I_D 1L				//proportional factor for PI control of id
#define I_FACTOR_I_D 1L				//integral factor for PI control of id


#define DELTA_TETA_MAX 120000000L
#define DELTA_TETA_MIN 2000000L

#define SPEC_ANGLE  -715827882L		//motor specific angle, refer to chapter 8.3.3 of UM1052.shengyi:-715827882L, 715827882 536870912 357913941L; //357913941 298261617 119304647L // 30� BionX IGH3 motor specific angle, refer to chapter 8.8.3 of UM1052 180� maped to 2^31

#define OFFSET_A 1980 //1025 				//Offset of current sensing phase A
#define OFFSET_B 1932 //1022				//Offset of current sensing phase B
#define OFFSET_C 1925 //1042				//Offset of current sensing phase C

//LeftShift um bei R*L in vern�nftigen Ganzzahlbereich zu kommen
#define CAL_V 15LL<<8			  		// ADC*25,6 mV/Digit*1/SQRT(3)=15,  bei �bergabe an Observerfunktion >>11 um Dutycycle reinzurechnen.  Im Oberserver kommt Spannung in mV *2^-8 an.
#define CAL_I 38LL<<8					// ADC * 37,5 mA/Digit. Strom kommt in mA *2^-8 im Observer an. Siehe Post Nr. 99 im Thread (f�r 12 FET)

//Constants for Motor model of observer
#define INDUCTANCE	6LL		//war nach Messung 13 (mit einfachem LCR-Tester)		//H = V*s/A Induktivit�t in �H/100 Shengyi hat 200�Henry Induktivit�t 2^16*0,0002 -->>>16 in Observer um auf Henry zukommen
#define RESISTANCE 40LL		//war nach Messung 60	//Ohm = V/A Widerstand in Shengi ist 117mOhm -->2^9*0,117 >>9 in Observer um auf Ohm zu kommen.
#define FLUX_LINKAGE 1200LL			//V*s/rad von Hand angepasst
#define GAMMA 9LL					//per trial and error


#define _T 2048						//Periode des Timers1 zur Einstellung der PWM Frequenz 2048 ergibt 16kHz

#endif
