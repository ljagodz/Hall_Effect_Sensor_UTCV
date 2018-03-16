
 int refsig = 600; // Be aware that this refsig value is entirely dependent on the particular Hall Effect sensor you are using
 int val;
 int prev_val = 0;
 float t, cur_t = 0; 
 void setup()
 {
   Serial.begin(115200);
   pinMode(A0, INPUT);
 }
 void loop()//Measure RPM
 {
   int sig = analogRead(A0); 
   if (sig > refsig) val = HIGH; 
   else val = LOW;
   if (prev_val == 0 && val == 1) { 
     cur_t = micros();
     Serial.print(1000000 * 60 / (cur_t - t)); //print the rpm 1000000 * 60
     //Serial.print("cur_t:");
     //Serial.print(cur_t);
     Serial.print('\n');
     delay(100);
     t = micros();
   }
   prev_val = val;
 }
