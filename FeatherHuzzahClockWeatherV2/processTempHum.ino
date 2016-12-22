void processTempHum()
{
  prevHum = humidity; prevTemp = temp;
  getANDprocessFeeds();
  humChange = (!(prevHum == humidity));
  tempChange = (!(prevTemp == temp));
  if (tempChange||humChange)
  {
    TFTHumTempClear();
  }
  
  TFTHumTempPrint();
  TFTInsideHumTempPrint();
  Serial.println("In the Main Loop");
  Serial.print(" prevHum:"); Serial.print(prevHum); Serial.print("Hum:"); Serial.print(humidity); Serial.print(" HumChange "); Serial.println(humChange);
  Serial.print(" prevTemp:"); Serial.print(prevTemp); Serial.print("Temp:"); Serial.print(temp); Serial.print("tempChange "); Serial.println(tempChange);

  processINTempHUM();
}

void processINTempHUM()
{
  inTemp = dht.readTemperature(true);
  Serial.print(F("In Temperature = ")); Serial.println(inTemp, DEC);


  inHum = dht.readHumidity();
  Serial.print(F("In Humidity = ")); Serial.println(inHum, DEC);
 
}

