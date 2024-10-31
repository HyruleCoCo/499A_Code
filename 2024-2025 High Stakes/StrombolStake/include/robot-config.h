using namespace vex;

extern brain Brain;

//To set up a motor called LeftFront here, you'd use
//extern motor LeftFront;
extern motor TL;
extern motor BL;
extern motor ML;
extern motor TR;
extern motor BR;
extern motor MR;
extern motor armMotorA;
extern motor armMotorB;
extern motor_group arm;
extern motor towerConvey;
extern motor frontConvey;
extern motor_group convey;
//Add your devices below, and don't forget to do the same in robot-config.cpp:
extern controller Controller1;
extern inertial imu;
//extern rotation hori;//horizontal tracker
//extern rotation vert;//vertical tracker
extern digital_out msClamp;
/*
extern motor_group enter;
extern digital_out lpusher;
*/
void  vexcodeInit( void );