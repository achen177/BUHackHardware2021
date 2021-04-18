 //TONES
 
 #define  A  440.00
 #define  Ab 415.30
 #define  B  493.88
 #define  Bb 466.16
 #define  C  523.25
 #define  D  587.33
 #define  Cs 554.37
 #define  E  659.26
 #define  Eb 622.25
 #define  F  698.46
 #define  Fs 739.99   
 #define  G  783.99
 #define  R  0

const int buzzerPin=3;
const int pirPin=2;

const int pause=1000;
const int tempo = 140;
const int beats = 30;
const int duration = beats*tempo;

const int pirates[] = {D,D,D,E,F,F,
F,G,E,E,D,C,C,D,
A,C,D,D,D,E,F,F,
F,G,E,E,D,C,C,D,
A,C,D,D,D,E,G,G,A,Bb,Bb,A,G,A,D,
D,E,F,F,G,A,D,
D,F,E,E,D,C,C,D,
D,D,D,D,E,F,F,
F,G,E,E,D,C,C,D,A,C}; 

int currenttone = 0;
int val = 0;
bool motionstate = false;

//Functions

void setup() {
  // put your setup code here, to run once:
  pinMode(buzzerPin, OUTPUT);
  pinMode (pirPin, INPUT);
  //pinMode (5, OUTPUT);
  Serial.begin(9600);
}

void loop() {
   //put your main code here, to run repeatedly:
  val = digitalRead(pirPin);
  if (val == HIGH)
  {
    if (motionstate == false)
    {
      Serial.println("Customer here!");
      motionstate == true;
    }
    
    int count=sizeof(pirates);
    for (int i=0; i<count; i++)
    {
      currenttone=pirates[i];
      tone(buzzerPin, currenttone);
    }
  }
  else
  {
       Serial.println("Currently no customers!");
       motionstate = false;
       noTone(buzzerPin);
  }
}
