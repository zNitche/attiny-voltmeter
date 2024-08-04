const float VOLTAGE_REFERENCE = 1.1; // 1.1v reference, may slightly differ between units
const float VOLTAGE_DIVIDER_RATIO = 4.3; // 1v at ADC == 4.3v of Vs

const float ADC_CONVERSION_VALUE = (VOLTAGE_REFERENCE / 1023) * VOLTAGE_DIVIDER_RATIO;

const int LED = 0;

void setup() {
  analogReference(INTERNAL);

  pinMode(LED, OUTPUT);
}

void loop() {
  digitalWrite(LED, LOW);

  while (true) {
    float voltage = analogRead(A2) * ADC_CONVERSION_VALUE;

    if (voltage >= 3.1) {
      digitalWrite(LED, HIGH);
    } else {
      digitalWrite(LED, LOW);
    }

    delay(500);
  }
}
