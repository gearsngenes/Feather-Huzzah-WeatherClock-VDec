void tftPrintDayMmDtYr()
{

  tft.print(daysOfTheWeek[now16.dayOfTheWeek()]);
  tft.print(" ");
  tft.print(monthsOfTheYear[now16.month() - 1]);
  tft.print(" ");
  tft.print (now16.day());
  tft.print("  ");
  tft.setTextColor(ILI9341_GREEN);
  //   tft.println();
  // tft.print("    ");
  tft.println(now16.year());

}

void printBlinkingAMPM()
{
 tft.setTextSize(3);
 if (now16.hour() < 12) {
    if (now16.second() % 2 == 0) {
      tft.setTextColor(ILI9341_BLACK);
      tft.println("AM");
    }
    else {
      tft.setTextColor(ILI9341_ORANGE);
      tft.println("AM");
    }

  }
  else  {
    if (now16.second() % 2 == 0) {
      tft.setTextColor(ILI9341_BLACK);
      tft.println("PM");
    }
    else {
      tft.setTextColor(ILI9341_MAGENTA);
      tft.println("PM");
    }

  }
}
void printMinute()
{
  if (now16.minute() > 9) {
    tft.print(":");
  } else {
    if ((now16.minute() == 9) && (now16.second() == 59))
    {
      tft.setTextColor(ILI9341_BLACK);
      tft.print(":0");
    }
    else
    {
      tft.print(":0");
    }
  }

  if (now16.second() == 59) {
    tft.setTextColor(ILI9341_BLACK);
    tft.print(now16.minute());
  }
  else {
    tft.print (now16.minute());
  }
}

void tftPrintIntraHourTime()
{
  tft.setCursor(10, 20);
  //    tft.println();
  tft.setTextColor(ILI9341_WHITE);  tft.setTextSize(3);

  tftPrintDayMmDtYr();

  tft.println();

  tft.setTextColor(ILI9341_YELLOW); tft.setTextSize(5);

  tft.setCursor(60, 60);

  int hr = now16.hour()%12;

  if (hr ==0) {tft.print(12);} else {tft.print(hr); }
  
  printMinute();

  tft.print(" ");

  printBlinkingAMPM();

  tft.println();

}

void TFTsetup() {

  //  delay(10);
  Serial.println("FeatherWing TFT Test!");

  tft.begin();
  tft.setRotation(1);
  tft.fillScreen(ILI9341_BLACK);

}

void TFTPrint() {
  boolean eohour = (now16.minute() == 59) && (now16.second() == 59);
tft.drawRect(0, 0, 320, 105, ILI9341_WHITE );
tft.drawRect(1, 1, 319, 104, ILI9341_WHITE );
tft.drawRect(2, 2, 317, 102, ILI9341_WHITE );

tft.drawRect(0,108, 320,40, ILI9341_GREEN );
tft.drawRect(0,109, 319,39, ILI9341_GREEN );

tft.drawRect(0,150, 320,40, ILI9341_BLUE );
tft.drawRect(0,149, 319,40, ILI9341_BLUE );

  if (eohour)  {
    tft.fillScreen(ILI9341_BLACK);
    yield();
  }

  else   {
    tftPrintIntraHourTime();
  }

  delay(10);
}

void TFTHumTempClear()
{
 tft.setCursor(0,130);
tft.fillRect(0,109, 316,40, ILI9341_BLACK );
/* tft.setTextColor(ILI9341_BLACK);  tft.setTextSize(3);
 tft.print(" Hum:");  tft.print (humidity, 0); tft.print ("%");
 tft.print(" Tmp:"); tft.print(temp,0); tft.print(" F "); 
 delay(50);
*/
}

void TFTHumTempPrint()
{
   tft.setCursor(0,120);
   tft.fillRect(2,110, 316,38, ILI9341_WHITE);
 tft.setTextColor(ILI9341_RED);  tft.setTextSize(3);
 tft.print(" OUT: ");  tft.print(temp); tft.setTextSize(1); tft.print('o');tft.setTextSize(3);tft.print("F  ");
 tft.print (humidity); tft.print ("%");
 //tft.print(" Tmp:"); ;  
}

void TFTInsideHumTempPrint()
{
   tft.setCursor(0,160);
   tft.fillRect(2,152, 316,38, ILI9341_YELLOW);
 tft.setTextColor(ILI9341_BLACK);  tft.setTextSize(3);
 tft.print(" IN:  ");  tft.print(inTemp); tft.setTextSize(1); tft.print('0');tft.setTextSize(3);tft.print("F  ");
 tft.print (inHum); tft.print ("%");
 //tft.print(" Tmp:"); ;  
}


