// sketch to test interface with the Sharp 2Y0A21 F 27 infrared sensor

#include <DistanceGP2Y0A21YK.h>
#include <RunningMedian.h>

const int SENSOR = A0;

RunningMedian samples = RunningMedian(30);
DistanceGP2Y0A21YK Dist;
/* int distance; */
long count = 0;

void setup() {
  Serial.begin(9600);
  Dist.begin(SENSOR);
}

void loop() {
  /* distance = Dist.getDistanceCentimeter(); */
  samples.add(Dist.getDistanceCentimeter());
  count++;
  if (count % 10 == 0)
    /* Serial.println(microsecondsToInches(samples.getMedian())); */
    Serial.println(samples.getMedian());  
  delay(10);
}
