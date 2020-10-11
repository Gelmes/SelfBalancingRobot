# SelfBalancingRobot

A self balancing robot using an [Arduino Nano](https://www.arduino.cc/en/pmwiki.php?n=Main/ArduinoBoardNano) and two [DRV8834 motor drivers](https://www.pololu.com/product/2134).

To reduce development time a sutomized version of the arduino [Tone](https://github.com/bhagman/Tone) library was used. This customized version keeps track of the frequency ticks in order to be able to calculate distance.