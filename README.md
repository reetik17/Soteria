# Soteria

More than 65 million people are suffering from epilepsy, a disease which bars to either use public transport or drive their own vehicle to travel. Our product enables them to drive their vehicle safely anywhere by alerting them of the upcoming seizure if any.

Features of our project are:
1. Continuous monitoring of heartbeat and detection of an upcoming seizure.
2. Alert the user by an LED indication before a seizure, hence preventing any fatal accident.
3. Notify the user's family member and the hospital for immediate attention.

A heartbeat monitoring sensor, connected to a 32-bit microcontroller(NodeMCU ESP8266) will be placed on the steering wheel. Our program will detect a seizure, before it comes, using the data collected by the sensor. The NodeMCU will be connected to a cloud-based IoT service, IFTTT, through the internet. Whenever there will be a seizure, the NodeMCU will send data to IFTTT and an LED will blink to alert the driver. IFTTT will generate an SMS, containing the GPS location of the user to the registered numbers immediately after receiving the data.
