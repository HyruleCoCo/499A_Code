/*#include "vex.h"
#include "arm_pid.h"*/
//! arm pid
/*startsummary
insert summary of code here
endsummary*/
/*
int armPID(){  // to use in auton we need to set armDesiredValue to the degree we want it to
    while(enableArmPid){
        //position of the two arm sides
        int position = armTrack.position(degrees);
        int position2 = armTrack2.position(degrees);
        int averagePos = (position + position2)/2; // average posiion of the two arm sides
        // potential, kp
        armError = averagePos - armDesiredValue;
        //derrivative, kd
        armDerrivative = armError - armPrevError;
        //integral(ki)  velocity -> position -> ansement(position * time)
        armTotalError += armError;
        //multiples the error by the porportional value, adds derrivative value and integral value
        //divided by 12.0 for voltage control
        double armPower = (armError * armKP + armDerrivative * armKD * + armTotalError * armKI) / 12.0;

        arm.spin(fwd, armPower, volt); // provides power to the motor

        armPrevError = armError;
        if(armDesiredValue == armTotalError){// resets total error after it reaches the target to prevent windup
            armTotalError = 0;
        }
        wait(20, msec); 
    }   
    return 0;
}
//ENDVEXDOC
*/