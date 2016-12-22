void processFeedData(FeedData feed,int i)
{
   switch (i) {
      case 0:
        Serial.println("Temp Feed:");
        feed.intValue(&temp);
      Serial.print(F("     temp= ")); Serial.println(temp, DEC);
        break;
      case 1:
      Serial.println("Humidity Feed:");
      feed.intValue(&humidity);
      Serial.print(F("     Humidity= ")); Serial.println(humidity, DEC);
   }
  

}



void getANDprocessFeeds()
{  FeedData templatest = tempFeed.receive();
  FeedData humiditylatest = humidityFeed.receive();

  processFeedData(templatest,0);
  processFeedData(humiditylatest,1);

  
  // Now wait 30 MSmore seconds and repeat.
  Serial.println(F("Waiting 3 seconds and then receiving a new feed value."));
  delay(30 );
}
