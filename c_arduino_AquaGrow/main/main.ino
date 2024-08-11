// Цей файл
int sensorHumidity_pin = A0;
int sensorLight_pin = A1;
int watering_can_pin = 2;

int sensorLight_value = 0;
int sensorHumidity_value = 0;
int watering_can_value = 0;

unsigned int last_fix_time;
unsigned int next_check = 21600000;

void printSensorInfo(int value, float voltage, int percentages) {
  // Виведення значення на серійний монітор
  Serial.print("Analog value: ");
  Serial.print(value);
  Serial.print("\t Voltage: ");
  Serial.print(voltage);
  Serial.print("V\t Percentages: ");
  Serial.print(percentages);
  Serial.println("%");
}

void setup() {
  // pinMode(sensorLight_pin, INPUT);
  // pinMode(sensorHumidity_pin, INPUT);
  pinMode(watering_can_pin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  digitalWrite(watering_can_pin, HIGH);
  Serial.println("HIGH");
  delay(1000);
  digitalWrite(watering_can_pin, LOW);
  Serial.println("LOW");
  delay(5000);
  
  // if (millis() - last_fix_time > next_check) {
  //   last_fix_time = millis();
  
  //   Serial.println("-------------------------------------------------------");

  //   sensorLight_value = analogRead(sensorLight_pin);
  //   float sensorLight_vol = sensorLight_value * (5.0 / 1023.0);
  //   int sensorLight_percentages = map(sensorLight_value, 0, 1023, 100, 0);
  //   printSensorInfo(sensorLight_value, sensorLight_vol, sensorLight_percentages);

  //   sensorHumidity_value = analogRead(sensorHumidity_pin);
  //   float sensorHumidity_vol = sensorHumidity_value * (5.0 / 1023.0);
  //   int sensorHumidity_percentages = map(sensorHumidity_value, 0, 1023, 100, 0);
  //   printSensorInfo(sensorHumidity_value, sensorHumidity_vol, sensorHumidity_percentages);

  //   if (sensorLight_percentages != 75 && sensorHumidity_percentages != 60) {
  //     Serial.print("Water value: ");
  //     Serial.print("1");
  //     Serial.print("\t\t Voltage: ");
  //     Serial.print("5.00");
  //     Serial.print("V\t Percentages: ");
  //     Serial.print("100");
  //     Serial.println("%");
  //     digitalWrite(2, HIGH);
  //   }
  //   else {
  //     Serial.print("Water value: ");
  //     Serial.print("0");
  //     Serial.print("\t\t Voltage: ");
  //     Serial.print("5.00");
  //     Serial.print("V\t Percentages: ");
  //     Serial.print("0");
  //     Serial.println("%");
  //     digitalWrite(2, LOW);
  //   }
  // }
}

  

  // int humidity = map(sensorValue, 0, 1023, 0, 100); // Перетворення в відсотки
  // if (humidity > 100) {humidity = 100;}

  // if (humidity < 70){
  //   digitalWrite(7, HIGH);
  //   digitalWrite(8, LOW);  
  // }
  // else {
  //   digitalWrite(7, LOW);
  //   digitalWrite(8, HIGH);
  // }




  // // Затримка перед наступним зчитуванням
  // delay(1000);

