using namespace vex;

extern brain Brain;

// VEXcode devices
extern controller Controller1;
extern motor TL;
extern motor BL;
extern motor TR;
extern motor BR;
extern inertial Inertial2;
extern motor cata1;
extern motor cata2;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );