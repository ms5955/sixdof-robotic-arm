#include <Servo.h>
const byte N=6, pins[N]={2,3,4,5,6,7};
const int lo[N]={0,20,10,0,0,20}, hi[N]={180,160,170,180,180,85};
const int home[N]={90,90,90,90,90,55};
Servo s[N]; String line;
void setJoint(byte i,int a){if(i>=N)return;a=constrain(a,lo[i],hi[i]);s[i].write(a);}
void homeAll(){for(byte i=0;i<N;i++)setJoint(i,home[i]);}
void command(String c){c.trim();c.toUpperCase();if(c=="HOME"){homeAll();Serial.println("OK HOME");return;}if(c.length()>=4&&c[0]=='A'){int p=c.indexOf(':');if(p>1){int j=c.substring(1,p).toInt(),a=c.substring(p+1).toInt();if(j>=1&&j<=N){setJoint(j-1,a);Serial.println("OK");return;}}}Serial.println("ERR: use A1:90 ... A6:55 or HOME");}
void setup(){Serial.begin(115200);line.reserve(32);for(byte i=0;i<N;i++)s[i].attach(pins[i]);delay(300);homeAll();Serial.println("6DOF ARM READY");}
void loop(){while(Serial.available()){char c=Serial.read();if(c=='\n'||c=='\r'){if(line.length()){command(line);line="";}}else if(line.length()<31)line+=c;}}
