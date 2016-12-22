
void serialPrintTime()
{
  Serial.print(now16.year(), DEC);
  Serial.print('/');
  Serial.print(now16.month(), DEC);
  Serial.print('/');
  Serial.print(now16.day(), DEC);
  Serial.print(" (");
  Serial.print(daysOfTheWeek[now.dayOfTheWeek()]);
  Serial.print(") ");
  Serial.print(now16.hour(), DEC);
  Serial.print(':');
  Serial.print(now16.minute(), DEC);
  Serial.print(':');
  Serial.print(now16.second(), DEC);

  Serial.println();
}

