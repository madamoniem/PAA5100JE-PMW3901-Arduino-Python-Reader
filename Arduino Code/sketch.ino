#include "Bitcraze_PMW3901.h"

// Using digital pin 10 for chip select
Bitcraze_PMW3901 flow(10);

// Variables for keeping track of total movement
long totalDeltaX = 0;
long totalDeltaY = 0;

void setup() {
  Serial.begin(9600);

  if (!flow.begin()) {
    Serial.println("Initialization of the flow sensor failed");
    while(1) { }
  }
  flow.setLed(true);
}

void loop() {
  int16_t deltaX, deltaY;
  
  // Get motion count since last call
  flow.readMotionCount(&deltaX, &deltaY);

  // Accumulate the total movement
  totalDeltaX += deltaX;
  totalDeltaY += deltaY;

  // Print the total movement since initialization
  Serial.print("Total X: ");
  Serial.print(totalDeltaX);
  Serial.print(", Total Y: ");
  Serial.println(totalDeltaY);

  // Check for reset command
  if (Serial.available()) {
    char cmd = Serial.read();
    if (cmd == 'R') {
      totalDeltaX = 0;
      totalDeltaY = 0;
    }
  }

  delay(100);
}
