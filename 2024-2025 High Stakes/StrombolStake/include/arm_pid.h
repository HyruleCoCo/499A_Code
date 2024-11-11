bool enableArmPid = true;
int armPID(int armDesiredValue);
double armKP = 0.0;
double armKI = 0.0;
double armKD = 0.0;// error - preverror  calculates speed
int armError; // SensorValue - DesieredValue    Positional Value, DeltaX
int armPrevError; // Position 20 miliseconds(however long the wait period is) ago
int armDerrivative;// error - preverror  calculates speed
int armTotalError = 0; // totalError = totalError + error
//autonomous settings
int armDesiredValue = 0;