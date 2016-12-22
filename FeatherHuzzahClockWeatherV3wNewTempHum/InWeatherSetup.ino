void DHT22Setup()
{
  dht.begin();

  Serial.println(F("Ready!"));
}

void Si7021Setup()
{
     sensor.begin();
}
