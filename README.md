## DHT11 Sensor Data Publisher to Adafruit IO

This Arduino project transmits temperature and humidity readings from a DHT11 sensor to Adafruit IO using WiFi and MQTT communication.

**Features:**

- Connects to a WiFi network.
- Reads temperature and humidity data from a DHT11 sensor.
- Publishes the sensor readings to designated feeds (`Temperature` and `Humidity`) on your Adafruit IO account.
- Provides feedback on connection status and data publishing success/failure via the serial monitor.

**Hardware Requirements:**

- Arduino Uno or compatible board
- DHT11 temperature and humidity sensor
- WiFi module (if not built-in)
- Breadboard and jumper wires

**Software Requirements:**

- Arduino IDE ([https://www.arduino.cc/](https://www.arduino.cc/))
- Adafruit_MQTT library ([https://www.arduino.cc/reference/en/libraries/adafruit-mqtt-library/](https://www.arduino.cc/reference/en/libraries/adafruit-mqtt-library/))
- SimpleDHT library ([https://github.com/adafruit/Adafruit_CircuitPython_ST7789/releases](https://github.com/adafruit/Adafruit_CircuitPython_ST7789/releases))

**Installation:**

1. Download and install the Arduino IDE.
2. Install the required libraries (`Adafruit_MQTT` and `SimpleDHT`) using the Library Manager in the Arduino IDE (Sketch -> Include Library -> Manage Libraries).
3. Replace the placeholder values in the code:
   - `SSID` and `PASS`: Your WiFi network name and password.
   - `USERNAME` and `KEY`: Your Adafruit IO username and AIO key (obtainable from your Adafruit IO account).
4. Connect your DHT11 sensor and other hardware components according to your specific circuit.
5. Upload the code to your Arduino board.

**Usage:**

1. Open the serial monitor in the Arduino IDE (Tools -> Serial Monitor) at 115200 baud.
2. You'll see messages indicating connection attempts and status.
3. Once connected, the program will display temperature (°C) and humidity (%) readings every 5 seconds (adjustable in the code).
4. If publishing is successful, "Sent!" messages will appear on the serial monitor.

**Additional Notes:**

- The code includes error handling for connection attempts. 
- Consider using `float` data types for temperature and humidity to store more precise values.
- Adjust the delay in the `loop` function based on your desired data update frequency.
- Explore the Adafruit IO dashboard to visualize the published sensor data.

This project provides a basic example of using an Arduino to collect sensor data and send it to the cloud using Adafruit IO. You can extend this project by adding features like:

- Logging data to an SD card.
- Sending push notifications based on sensor readings.
- Controlling external devices based on sensor data.
