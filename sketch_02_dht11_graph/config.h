// Adafruit invests time and resources providing this open source code.
// Please support Adafruit and open source hardware by purchasing
// products from Adafruit!
//
// Written by Todd Treece for Adafruit Industries
// Copyright (c) 2016 Adafruit Industries
// Licensed under the MIT license.
//
// All text above must be included in any redistribution.

#ifndef CONFIG_H
#define CONFIG_H

/******************* DHT11 Humidity Sensor Config **************************/
#define DHT_PIN 5
// Uncomment whatever type you're using!
#define DHT_TYPE DHT11   // DHT 11
//#define DHT_TYPE DHT22   // DHT 22  (AM2302), AM2321
//#define DHT_TYPE DHT21   // DHT 21 (AM2301)

/************************ Adafruit IO Config *******************************/

// visit io.adafruit.com if you need to create an account,
// or if you need your Adafruit IO key.
#define IO_USERNAME    "your_username"
#define IO_KEY         "your_key"

/******************************* WIFI **************************************/

// the AdafruitIO_WiFi client will work with the following boards:
//   - HUZZAH ESP8266 Breakout -> https://www.adafruit.com/products/2471
//   - Feather HUZZAH ESP8266 -> https://www.adafruit.com/products/2821
//   - Feather M0 WiFi -> https://www.adafruit.com/products/3010
//   - Feather WICED -> https://www.adafruit.com/products/3056

#define WIFI_SSID       "your_ssid"
#define WIFI_PASS       "your_pass"

// comment out the following two lines if you are using fona or ethernet
// #include "AdafruitIO_WiFi.h"
// AdafruitIO_WiFi io(IO_USERNAME, IO_KEY, WIFI_SSID, WIFI_PASS);


/******************************* FONA **************************************/

// the AdafruitIO_FONA client will work with the following boards:
//   - Feather 32u4 FONA -> https://www.adafruit.com/product/3027

// uncomment the following two lines for 32u4 FONA,
// and comment out the AdafruitIO_WiFi client in the WIFI section
// #include "AdafruitIO_FONA.h"
// AdafruitIO_FONA io(IO_USERNAME, IO_KEY);

/**************************** ETHERNET ************************************/

// the AdafruitIO_Ethernet client will work with the following boards:
//   - Ethernet FeatherWing -> https://www.adafruit.com/products/3201
//#include "AdafruitIO_Ethernet.h"
//AdafruitIO_Ethernet io(IO_USERNAME, IO_KEY);

byte MAC[] = { 0x90, 0xa2, 0xda, 0x10, 0x21, 0xc7 };

#include "AdafruitIOHack.h"
AdafruitIOHack io(IO_USERNAME, IO_KEY, MAC);

/********************** DHT11 Humidity Sensor *****************************/
#include <DHT.h>
DHT dht(DHT_PIN, DHT_TYPE);

/*************************** Heat Index ***********************************/
#define C1 -8.784695
#define C2  1.61139411
#define C3  2.338549
#define C4 -0.14611605
#define C5 -1.2308094e-2
#define C6 -1.6424828e-2
#define C7  2.211732e-3
#define C8  7.2546e-4
#define C9 -3.582e-6
#define D1 13.12
#define D2 0.6215
#define D3 -11.37
#define D4 0.3965
#endif // CONFIG_H
