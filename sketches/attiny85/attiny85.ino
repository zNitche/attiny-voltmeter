const float VOLTAGE_REFERENCE = 1.1; // 1.1v reference, may slightly differ between units
const float VOLTAGE_DIVIDER_RATIO = 4.3; // 1v at ADC == 4.3v of Vs
const float ADC_CONVERSION_VALUE = (VOLTAGE_REFERENCE / 1023) * VOLTAGE_DIVIDER_RATIO;

const int READING_SAMPLES_COUNT = 10;

const int LED = 0;

void setup() {
  analogReference(INTERNAL);
  // Serial.begin(9600);

  pinMode(LED, OUTPUT);
}

float getVoltage() {
  float avg = 0;

  for (int i = 0; i < READING_SAMPLES_COUNT; i++) {
    int adcValue = analogRead(A2);
    avg += adcValue * ADC_CONVERSION_VALUE;

    delay(100);
  }

  return avg / READING_SAMPLES_COUNT;
}

void loop() {
  digitalWrite(LED, LOW);

  while (true) {
    float voltage = getVoltage();

    if (voltage >= 3.1) {
      digitalWrite(LED, HIGH);
    } else {
      digitalWrite(LED, LOW);
    }

    // Serial.println(voltage);

    delay(500);
  }
}
