# C3PO

 I wanted to get away from having to connect up C3PO to my computer to run bottango and instead have him running freestanding. Using Jesse M's animatronic build I've added in a couple of extra parts. Instead of having a trigger wired up i thought I'd leverage the ESPNow protocol to send a single message from the hand controller simultaneously to the 4 esp32's in the  body and the 1 in the base at the same time

The Base
 600mm x 18mm round pine x2
 40mm x 18mm x 1.2m
In the base is a 12v step down to 7v for the servos and a 12v to 5v for the esp32 and dfplayer. The amp is powered directly from the 12v input/

Hand Control
 refer included part list

Export to code from Bottango. Set to not play on start and not loop.
For each driver copy the following two files from your exported code into the base folder for each of the drivers:
GeneratedCommandStreams.cpp
GeneratedCommandStreams.h

