# PID-Controller
----
This is a project aiming at building a PID controller that can drive a simulated car through some track. The controller utilizes CTE returned
by the simulator to calculate the adjustment range of the steering wheel. The P, I and D parameters are tuned and the car is able to drive
smoothly around the track without crashing or going off road.

## Key Files 
### The simulator
The simulator can be found in the folder */PID/home/simulator*.

### Original readme
The original project readme file can be found in the folder */PID/home/CarND-PID-Control-Project*.

### Codes
The folder */PID/home/CarND-PID-Control-Project/src* contains the main codes of this project.

- main.cpp
Main program communicates with the Simulator, calls the controller function.

- PID.h and PID.cpp
Codes that define the controller function, which the main work of this project happened inside these files.
