#SimpleBMP180 library

This is bare bone BMP085/BMP180 Library

##Dependency

This library uses the Wire library.

##Usage

* begin()

 Check the device and retrieves the calibration data.  Returns false if the operation fails.

* getPressure(mode)

 Initiate a temperature and pressure reading and returns the pressure in Pascal.
 
* getLastTemperature()

 Retrieves the sensor temperature in deci Celsius as measured during the pressure reading.

See the example how to use this library.

 