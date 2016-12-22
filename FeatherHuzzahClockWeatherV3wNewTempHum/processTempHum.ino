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
 // TFTInsideHumTempPrint2();
  Serial.println("In the Main Loop");
  Serial.print(" prevHum:"); Serial.print(prevHum); Serial.print("Hum:"); Serial.print(humidity); Serial.print(" HumChange "); Serial.println(humChange);
  Serial.print(" prevTemp:"); Serial.print(prevTemp); Serial.print("Temp:"); Serial.print(temp); Serial.print("tempChange "); Serial.println(tempChange);

  //processINTempHUM();
  processINTempHUM2();
}

/*
void processINTempHUM()
{
  inTemp = dht.readTemperature(true);
  Serial.print(F("In Temperature = ")); Serial.println(inTemp, DEC);


  inHum = dht.readHumidity();
  Serial.print(F("In Humidity = ")); Serial.println(inHum, DEC);
 
}
*/
void TFTInsideHumTempPrint2()
{
  
}
void processINTempHUM2()
{
    inTemp = (int)(1.8*(sensor.readTemperature())+32.0);
  
  inHum = sensor.readHumidity();
 
 
  
}
