# PAA5100JE/PMW3901 Arduino Python Reader
Access and read distance data from PAA5100JE and PMW3901 for Arduino in Python.


<details>
  <summary><h1>Setup</h1></summary>
  

This code is built on [Bitcraze's Arduino driver](https://github.com/bitcraze/Bitcraze_PMW3901), which is necessary for this project.

### Arduino Setup
1. Download the [Bitcraze's Arduino driver](https://github.com/bitcraze/Bitcraze_PMW3901)
2. Open the Arduino IDE.
3. ```Sketch > Include Library > Add .ZIP Library...``` and select your downloaded folder to install the driver as a library.
4. Open ```sketch.ino``` under the ```Arduino Code``` folder or paste the code into a new sketch.
5. Make sure to upload the code to the Arduino, wait for it to complete, then terminate it (I close out the IDE to be sure).

### Python Setup
5. Install __PySerial__ into your Python envornment using ```pip install pyserial```
6. Open the code under the ```Python Code``` folder.
7. Find which port your Arduino is under by running ```python -m serial.tools.list_ports``` or checking the select board dropdown on the Arduino IDE.
8. Replace your port number on line 5 in ```example.py```
9. Run the introductory code in ```example.py```

## Common Errors
**Could not open port 'COM_': PermissionError(13, 'Access is denied.', None, 5)**<br>
This is because you have a process already running at that port, whether it's the uploaded code on Arduino, or another instance of a Python environment. Close out the Arduino IDE and delete the Python terminal and rerun
</details>



# PAA5100JE/PMW3901 with PySerial

This repository contains Python and Arduino code for interfacing with a PMW3901 optical flow sensor on an Arduino board. The Python code reads the accumulated X and Y movement counts since initialization or the last reset and the Arduino code calculates these counts.

## Contents

This repository consists of two main parts:

1. Arduino code (`Arduino_PMW3901.ino`): This code runs on the Arduino and reads the data from the PMW3901 sensor. It accumulates the X and Y movement counts and sends these counts to the serial port.

2. Python code (`ArduinoReader.py`, `main.py`): This code runs on your computer and reads the accumulated X and Y movement counts from the Arduino over the serial port.

## Python Code

The Python code includes a class called `ArduinoReader` that handles communication with the Arduino over the serial port.

Here is a brief summary of the functions provided by the `ArduinoReader` class:

- `__init__(self, port, baud_rate)`: This is the constructor for the `ArduinoReader` class. You need to specify the port and baud rate when creating an instance of the class.

- `distanceSinceInit(self)`: This function returns the accumulated X and Y movement counts since initialization or the last reset. It returns two values: `total_X` and `total_Y`.

- `reset(self)`: This function resets the accumulated X and Y movement counts to zero.

- `stop(self)`: This function stops the reading from the serial port. This function should be called when you're done using an instance of the `ArduinoReader` class.

### Example Usage

Here is an example of how to use the `ArduinoReader` class in your Python code:

```python
from ArduinoReader import ArduinoReader
import time

arduino = ArduinoReader('COM3', 9600)  # Replace 'COM3' with your Arduino's port

try:
    while True:
        time.sleep(1)
        total_X, total_Y = arduino.distanceSinceInit()
        print("Total X: ", total_X, "Total Y: ", total_Y)
except KeyboardInterrupt:
    arduino.stop()
```

This code creates an instance of the `ArduinoReader` class, then enters a loop where it prints the accumulated X and Y movement counts every second. The loop continues until you stop the program with a keyboard interrupt (usually Ctrl+C), at which point the `stop` function is called to close the serial connection.

You can reset the accumulated movement counts by calling the `reset` function like this:

```python
arduino.reset()
```

After calling the `reset` function, the `distanceSinceInit` function will start returning the movement counts since the reset.

## Arduino Code

The Arduino code (`Arduino_PMW3901.ino`) is straightforward. It initializes the PMW3901 sensor and enters a loop where it reads the X and Y movement counts, accumulates them, and sends them over the serial port. The Arduino code also listens for a reset command from the Python code and resets the accumulated movement counts when it receives this command.

## Conclusion

This repository provides a simple way to read data from a PMW3901 sensor on an Arduino from a Python program on your computer. It provides functions for getting the accumulated movement counts and resetting them. The Arduino and Python code are designed to work together, with the Arduino handling the sensor reading and the Python code providing a user-friendly API for getting the data.
