/*
 * A project to introduce the IOT to highschool students in collaboration with
 * makerspace - Faculty of Computer Science at the Free University of
 * Bozen-Bolzano.
 * 
 *                                                                         
 *    m  a  k  e  r  s  p  a  c  e  .  i  n  f  .  u  n  i  b  z  .  i  t  
 *                                                                         
 *   8888888888888888888888888888888888888888888888888888888888888888888888
 *                                                                         
 *                  8                                                      
 *                  8                                                      
 *   YoYoYo. .oPYo. 8  .o  .oPYo. YoYo. .oPYo. 8oPYo. .oPYo. .oPYo. .oPYo. 
 *   8' 8' 8 .oooo8 8oP'   8oooo8 8  `  Yb..`  8    8 .oooo8 8   `  8oooo8 
 *   8  8  8 8    8 8 `b.  8.  .  8      .'Yb. 8    8 8    8 8   .  8.  .  
 *   8  8  8 `YooP8 8  `o. `Yooo' 8     `YooP' 8YooP' `YooP8 `YooP' `Yooo' 
 *                                             8                           
 *                                             8                           
 *                                                                         
 *   8888888888888888888888888888888888888888888888888888888888888888888888
 *                                                                         
 *    c  o  m  p  u  t  e  r    s  c  i  e  n  c  e    f  a  c  u  l  t  y 
 *                                                                         
 *                                                                         
 * The MIT License (MIT)
 *
 * Copyright (c) 2016 Julian Sanin
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

/************************** Configuration ***********************************/

// edit the config.h tab and enter your Adafruit IO credentials
// and any additional configuration needed for WiFi, cellular,
// or ethernet clients.
#include "config.h"

/************************ Example Starts Here *******************************/

// set up the 'graph' feeds they must be created on io.adafruit.com
AdafruitIO_Feed * graphHIFeed = io.feed("graphHI");
AdafruitIO_Feed * graphKIFeed = io.feed("graphKI");

void setup() {
	// use serial port for printing messages
	Serial.begin(115200);
	while (!Serial);

  Serial.println();
  if(INTERNET_HW){
    Serial.println("Connecting to Adafruit IO");
	  connectIO();
  }else{
    Serial.println("No internet connection");
  }

	// initialize DHT sensor
	dht.begin();
}

void loop() {
	// io.run(); is required for all sketches.
	// it should always be present at the top of your loop
	// function. it keeps the client connected to
	// io.adafruit.com, and processes any incoming data.
	if(INTERNET_HW) io.run();

	// wait a few seconds between DHT sensor measurements
	delay(2000);

	// sensor readings are up to 2 seconds 'old' (its a very slow sensor)
	double RH = dht.readHumidity(); // from 20% to 90%
	double T = dht.readTemperature();; // from 0°C to 50°C
  double V = 0.5; // wind speed m/sec
	// print sensor values
	Serial.print(RH, 0);
	Serial.print("% ");
	Serial.print(T, 0);
	Serial.print("°"); // degree symbol
	Serial.print("C\t");
  Serial.print(V);
  Serial.print("m/s\t");
     double HI = 0;
     double KI = 0;
  if(T>20){
	// calculate heat index 
      HI = heatIndex(T, RH);
      Serial.print("HI = ");
      Serial.println(HI);
      if(INTERNET_HW) graphHIFeed->save(HI);
  }else{
      KI = windChill(T,V);
      Serial.print("KI = ");
      Serial.println(KI);
      if(INTERNET_HW) graphKIFeed->save(KI);
  }
}

double heatIndex(double T, double RH) {
  return 
    C1 + C2 * T + C3 * RH + C4 * T * RH +
    C5 * pow(T, 2) + C6 * pow(RH, 2) +
    C7 * pow(T, 2) * RH + C8 * T * pow(RH, 2) +
    C9 * pow(T, 2) * pow(RH, 2);
}

double windChill(double T, double V) {
  return D1 + D2 * T + D3 * pow(V,0.16) + D4 * T * pow(V,0.16);
}

void connectIO() {
    // connect to io.adafruit.com
    io.connect();
    // wait for a connection
    while (io.status() < AIO_CONNECTED) {
      Serial.print(".");
      delay(500);
    }
    Serial.println("done: ");
    Serial.println(io.statusText());
}

