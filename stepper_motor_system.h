
#include <Stepper.h>

class StepperMotorSystem
{
public:
  StepperMotorSystem();

  void initialize(const int stepPin, const int dirPin);
  void terminate();

  void activate_motors();
  void deactivate_motors();

  void stepForward(const int stepCount);
  void stepBackward(const int stepCount);



private:
  int _stepPin, _dirPin;
  int _stepCount;

//  int _stepsPerRevolution, _motorSpeed;
};

StepperMotorSystem::StepperMotorSystem()
{
}

void StepperMotorSystem::initialize(const int stepPin, const int dirPin){
  
  _stepPin = stepPin;
  _dirPin = dirPin;
  
  pinMode(stepPin, OUTPUT);
  pinMode(dirPin, OUTPUT);
}

void StepperMotorSystem::terminate()
{
  deactivate_motors();
}

void StepperMotorSystem::stepForward(const int stepCount) {
  // stepCount = 200
  digitalWrite(stepPin, HIGH);
  for(int x = 0; x < stepCount; x++) {
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(500);
    digitalWrite(stepPin, LOW);
    delayMicroseconds(500);
  }
}

void StepperMotorSystem::stepBackward(const int stepCount) {
  digitalWrite(stepPin, LOW);
  for(int x = 0; x < stepCount; x++) {
    digitalWrite(_stepPin, HIGH);
    delayMicroseconds(500);
    digitalWrite(_stepPin, LOW);
    delayMicroseconds(500);
  }
}

void StepperMotorSystem::deactivate_motors()
{
  digitalWrite(_dirPin, LOW); // turns it OFF
}

void StepperMotorSystem::activate_motors()
{
  digitalWrite(_dirPin, HIGH); // turns it ON

}
