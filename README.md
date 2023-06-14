# PAA5100JE/PMW3901 Arduino Python Reader
 Access and read distance data from PAA5100JE and PMW3901 for Arduino in Python.

## Setup
This code is built on [Bitcraze's Arduino driver](https://github.com/bitcraze/Bitcraze_PMW3901), which is necessary for this project.

### Arduino Setup
1. Download the [Bitcraze's Arduino driver](https://github.com/bitcraze/Bitcraze_PMW3901)
2. Open the Arduino IDE.
3. ```Sketch > Include Library > Add .ZIP Library...``` and select your downloaded folder to install the driver as a library.
4. Run ```sketch.ino``` under the ```Arduino Code``` folder or paste the code into a new sketch.

### Python Setup
5. Install __PySerial__ into your Python envornment using ```pip install pyserial```
6. Open the code under the ```Python Code``` folder.
7. Find which port your Arduino is under by running ```python -m serial.tools.list_ports``` or checking the select board dropdown on the Arduino IDE.
8. Replace your port number on line 5 in ```example.py```
9. Run the introductory code in ```example.py```



