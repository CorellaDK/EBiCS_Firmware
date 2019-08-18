//place all your personal configurations here and keep this file when updating!
#ifndef CONFIG_H
#define CONFIG_H
#include "stdint.h"

#define DISPLAY_TYPE_KINGMETER_618U (1<<4)                  // King-Meter 618U protocol (KM5s, EBS-LCD2, J-LCD, SW-LCD)
#define DISPLAY_TYPE_KINGMETER_901U (1<<8)                  // King-Meter 901U protocol (KM5s)
#define DISPLAY_TYPE_KINGMETER      (DISPLAY_TYPE_KINGMETER_618U|DISPLAY_TYPE_KINGMETER_901U)
#define DISPLAY_TYPE DISPLAY_TYPE_KINGMETER_901U

#define wheel_circumference 2.202 	//wheel circumference in m
#define THROTTE_OFFSET 670//1210 			//ADC-value at closed throttle 670 for throttle, 1255 for TS
#define TS_COEF 2000				//coefficient for torque-sensor-mode
//#define TS_MODE						//Torquesensor-Mode
#define PAS_TIMEOUT 12000			//time tics @ 16kHz untils motor stops
#define RAMP_END 4000					//time tics @ 16kHz where motor reaches full level power
#define PH_CURRENT_MAX 500			//iq value (phase current in rotating frame), not calibrated yet

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

#define CAL_V 144LL			// 1V / 40 digits ADC, *1/Sqrt(3)*10000, geteilt durch 2048 max DutyCycle als >>2^11 bei �bergabe an Observerfunktion. >>1 zus�tzlich um Aufl�sung von CAS-V zu verbessern, im Oberserver kommt Spannung in mV an.
#define CAL_I 50LL					// 1A / 20 digits ADC Strom kommt in mA im Observer an.

//Constants for Motor model of observer an speed PLL
#define INDUCTANCE	2LL				//H = V*s/A Induktivit�t in �H/100 Shengyi hat 200�Henry Induktivit�t -->>>5 Observer um auf Henry zukommen
#define RESISTANCE 117LL			//Ohm = V/A Widerstand in Shengi ist 117mOhm --> >>3 in Observer um auf Ohm zu kommen.
#define FLUX_LINKAGE 300LL			//V*s/rad von Hand angepasst mit Ziel err schwingt um Null
#define GAMMA 24LL					//per trial and error


#define _T 2048						//Periode des Timers1 zur Einstellung der PWM Frequenz 2048 ergibt 16kHz

#endif
