using namespace vex;

extern brain Brain;

//To set up a motor called LeftFront here, you'd use
//extern motor LeftFront;
extern motor TL;
extern motor BL;
extern motor TBL;
extern motor TR;
extern motor BR;
extern motor TBR;
extern motor arm;
extern motor FI;
extern motor convey;
//Add your devices below, and don't forget to do the same in robot-config.cpp:
extern controller Controller1;
extern inertial imu;
extern rotation hori;//horizontal tracker
extern rotation vert;//vertical tracker
extern rotation armTrack;
extern rotation armTrack2;
extern digital_out msClamp;
/*
extern motor_group enter;
extern digital_out lpusher;
*/
void  vexcodeInit( void );