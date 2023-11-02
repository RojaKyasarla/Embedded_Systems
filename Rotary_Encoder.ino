#define CLK 2
#define DT 3
#define SW 4
int counter = 0;
int currentState;
int initState;
unsigned long bebounceDelay = 0;
void setup()
{
  pinMode(CLK, INPUT);
  pinMode(DT, INPUT);
  Serial.begin(9600);
  // Read the initial state of CLK
  initState = digitalRead(CLK);
} 

void loop() 
{
  // Read the current state of CLK
  currentState = digitalRead(CLK);
  // If last and current state of CLK are different, then we can be sure that the pulse occurred
  if (currentState != initState  && currentState == 1) {
    // Encoder is rotating counterclockwise so we decrement the counter
    if (digitalRead(DT) != currentState) {
      counter ++;
    } else {
      // Encoder is rotating clockwise so we increment the counter
      counter --;
    }
    // print the value in the serial monitor window
    Serial.print("Counter: ");
    Serial.println(counter);
  }
   
  // Remember last CLK state for next cycle
  initState = currentState;
}
