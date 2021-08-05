// https://www.pjrc.com/teensy/td_libs_AccelStepper.html
// Include the AccelStepper Library
#include <AccelStepper.h>


class STEPER_Motor
{
    int motorPins[4];
    int FULLSTEP;
    AccelStepper *stepper_num_x = NULL;


  public:
  // constracture
    STEPER_Motor(const int mot_Pins[4], int f_FULLSTEP)
    {
      motorPins[0] = mot_Pins[0];
      motorPins[1] = mot_Pins[2];
      motorPins[2] = mot_Pins[1];
      motorPins[3] = mot_Pins[3];
      FULLSTEP = f_FULLSTEP;
      stepper_num_x = new AccelStepper(FULLSTEP, motorPins[0], motorPins[1], motorPins[2], motorPins[3]);
    }
    
    
    // method
    void Run_with_accel(int max_speed, int accelrate, int initSpeed, int movingTo)
    {
      stepper_num_x->setMaxSpeed(max_speed);
      stepper_num_x->setAcceleration(accelrate);
      stepper_num_x->setSpeed(initSpeed);
      // stepper_num_x->moveTo(movingTo);
      // stepper_num_x->runToPosition(movingTo);
      stepper_num_x->run();
    }
    
    
    // method
    void RunToPosition_set(int max_speed, int accelrate, int Rot_num)
    {
      int movingTo = Rot_num * 4096;
      stepper_num_x->setMaxSpeed(max_speed);
      stepper_num_x->setAcceleration(accelrate);
      stepper_num_x->moveTo(movingTo);
      // stepper_num_x->runToPosition(); 
      // stepper_num_x->stop(); // Stop as fast as possible: sets new target
      // Serial.println("Steppr steps to go = \n");
      // Serial.println(stepper_num_x->distanceToGo());
    }
    
    //method
    void RunToPosition_No_ret()
    {
      stepper_num_x->runToPosition(); 
    }
    
    // method
    void Bounce_set(int max_speed, int accelrate, int initSpeed, int Rot_num)
    {
      int movingTo = Rot_num * 2048;
      stepper_num_x->setMaxSpeed(max_speed);
      stepper_num_x->setSpeed(initSpeed);
      stepper_num_x->setAcceleration(accelrate);
      stepper_num_x->moveTo(movingTo);
    }
    
    
    // method
    void Bounce()
    {
      if (stepper_num_x->distanceToGo() == 0)
      stepper_num_x->moveTo(-stepper_num_x->currentPosition());
      stepper_num_x->run();
    }
    
    // method
    void Run_Cons_Speed_to(int max_speed, int initSpeed, int movingTo)
    {
      stepper_num_x->setMaxSpeed(max_speed);
      stepper_num_x->setSpeed(initSpeed);
      stepper_num_x->moveTo(movingTo);
      stepper_num_x->runSpeed();
    }
    
    
    // method
    void QuikStop(int max_speed, int accelrate, int movingTo)
    {
      
      stepper_num_x->setMaxSpeed(max_speed);
      stepper_num_x->setAcceleration(accelrate);
      
      stepper_num_x->moveTo(movingTo);
      while (stepper_num_x->currentPosition() != movingTo) // Full speed up to 300
        stepper_num_x->run();
      stepper_num_x->stop(); // Stop as fast as possible: sets new target
      stepper_num_x->runToPosition(); 
      // Now stopped after quickstop
    
      // Now go backwards
      stepper_num_x->moveTo(-movingTo);
      while (stepper_num_x->currentPosition() != 0) // Full speed basck to 0
        stepper_num_x->run();
      stepper_num_x->stop(); // Stop as fast as possible: sets new target
      stepper_num_x->runToPosition(); 
      // Now stopped after quickstop

    }
    


};

const int pins1[] = {18, 19, 20, 21};
STEPER_Motor Steppr_1(pins1, 8);



const int pins2[] = {33, 32, 31, 30};
STEPER_Motor Steppr_2(pins2, 8);

const int pins3[] = {29, 28, 27, 26};
STEPER_Motor Steppr_3(pins3, 8);


const int pins4[] = {14, 15, 16, 17};
STEPER_Motor Steppr_4(pins4, 8);

const int pins5[] = {7, 6, 5, 4};
STEPER_Motor Steppr_5(pins5, 8);

void setup()
{
  
  
  // Steppr_5.RunToPosition_set(1000, 200, 12);
  
  
  // Bounce_set(int max_speed, int accelrate, int initSpeed, int Rot_num)
  Steppr_1.Bounce_set(1000, 100, 200, 1);
  Steppr_2.Bounce_set(1000, 100, 200, 1);
  Steppr_3.Bounce_set(1000, 100, 200, 1);
  Steppr_4.Bounce_set(1000, 100, 200, 1);
  Steppr_5.Bounce_set(1000, 100, 200, 1);

}
  
void loop()
{
  
  // Steppr_5.RunToPosition_No_ret();
  

  Steppr_1.Bounce();
  Steppr_2.Bounce();
  Steppr_3.Bounce();
  Steppr_4.Bounce();
  Steppr_5.Bounce();

}





void recycle()
{
  
  
  // Steppr_1.Bounce(1000, 1000, 1000, -5048);
  // Steppr_1.Bounce(1000, 1000, 1000, 5048);
  
  
  
  
  
  
  // Steppr_1.Run_Cons_Speed_to(1000, -50, 1);
  // Steppr_1.Run_Cons_Speed_to(1000, -500, 1);

  // Steppr_1.QuikStop(1000, 100, 2000);
  // Steppr_2.QuikStop(1000, 100, 2000);
  // Steppr_3.QuikStop(1000, 100, 2000);
  // Steppr_4.QuikStop(1000, 100, 2000);
  // Steppr_5.QuikStop(1000, 100, 2000);

  // Steppr_3.Run_it(1000, 1000, 1000, -2048);
  // Steppr_3.Run_it(1000, 1000, 1000, 2048);
  // Steppr_4.Run_it_2(1000, 1000, 1000, 2048);
  // Steppr_4.Run_it(1000, 1000, 1000, 4048);
  // Steppr_4.Run_it(1000, 1000, 1000, 2048);
  // Steppr_4.Run_it(250, 250, 250, -2048); 
  
  
  
  
}
