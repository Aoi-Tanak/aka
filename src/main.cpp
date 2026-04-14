#include <M5Unified.h>
#include "M5_Scales.h"

M5_Scales scales;

void setup() {
  auto cfg = M5.config();
  M5.begin(cfg);

  Serial.begin(9600);

  // I2C初期化
  Wire.begin();

  // センサ初期化
  if (!scales.begin(&Wire)) {
    Serial.println("Scale Unit not found!");
    while (1);
  }

  Serial.println("Scale ready");
  scales.setOffset(58000/2+6700/2+760/2+88/2+19/2);
}



void loop() {
  M5.update();
  

  // 重量取得（g）
  float weight = scales.getWeight();

  Serial.printf("Weight: %.2f g\n", weight);

  delay(500);
}