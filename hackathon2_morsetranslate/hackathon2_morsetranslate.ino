#include <string.h>

//Serial Input Variables
const byte numChars = 32;
char receivedChars[numChars];
boolean newData = false;
int inputsize = 0;

//Buzzer Control Variables
const int buzzer = 2;

//LED Control
const int LED = 5;
const int finish = 7;

void setup() {
   Serial.begin(9600);
   Serial.println("Hello! Welcome to the Morse Translator! Enter words in the form of <input>");
   Serial.println("Your input words will be translate to Morse Code via a blinking LED and a buzzer");
   pinMode(buzzer, OUTPUT);
   pinMode(LED, OUTPUT);
   pinMode(finish,OUTPUT);
}

void loop() {
    recvWithStartEndMarkers();
    showNewData();
    delay(100);
    inputsize = sizeof(receivedChars); 
    
    digitalWrite(buzzer,LOW);
    digitalWrite(LED,LOW);
    digitalWrite(finish,LOW);
    
    for (int i=0;i<inputsize;i++)
    {
      switch (toLowerCase(receivedChars[i]))
      {
        case 'a':
        morseshort();
        delay(200);
        morselong();
        delay(600);
        break;

        case 'b':
        morselong();
        delay(200);
        morseshort();
        delay(200);
        morseshort();
        delay(200);
        morseshort();
        delay(600);
        break;

        case 'c':
        morselong();
        delay(200);
        morseshort();
        delay(200);
        morselong();
        delay(200);
        morseshort();
        delay(600);
        break;

        case 'd':
        morselong();
        delay(200);
        morseshort();
        delay(200);
        morseshort();
        delay(600);
        break;

        case 'e':
        morseshort();
        delay(600);
        break;

        case 'f':
        morseshort();
        delay(200);
        morseshort();
        delay(200);
        morselong();
        delay(200);
        morseshort();
        delay(600);
        break;

        case 'g':
        morselong();
        delay(200);
        morselong();
        delay(200);
        morseshort();
        delay(600);
        break;

        case 'h':
        morseshort();
        delay(200);
        morseshort();
        delay(200);
        morseshort();
        delay(200);
        morseshort();
        delay(600);
        break;

        case 'i':
        morseshort();
        delay(200);
        morseshort();
        delay(600);
        break;

        case 'j':
        morseshort();
        delay(200);
        morselong();
        delay(200);
        morselong();
        delay(200);
        morselong();
        delay(600);
        break;

        case 'k':
        morselong();
        delay(200);
        morseshort();
        delay(200);
        morselong();
        delay(600);
        break;

        case 'l':
        morseshort();
        delay(200);
        morselong();
        delay(200);
        morseshort();
        delay(200);
        morseshort();
        delay(600);
        break;

        case 'm':
        morselong();
        delay(200);
        morselong();
        delay(600);
        break;

        case 'n':
        morselong();
        delay(200);
        morseshort();
        delay(600);
        break;

        case 'o':
        morselong();
        delay(200);
        morselong();
        delay(200);
        morselong();
        delay(600);
        break;

        case 'p':
        morseshort();
        delay(200);
        morselong();
        delay(200);
        morselong();
        delay(200);
        morseshort();
        delay(600);
        break;

        case 'q':
        morselong();
        delay(200);
        morselong();
        delay(200);
        morseshort();
        delay(200);
        morselong();
        delay(600);
        break;


        case 'r':
        morseshort();
        delay(200);
        morselong();
        delay(200);
        morseshort();
        delay(600);
        break;

        case 's':
        morseshort();
        delay(200);
        morseshort();
        delay(200);
        morseshort();
        delay(600);
        break;

        case 't':
        morselong();
        delay(600);
        break;

        case 'u':
        morseshort();
        delay(200);
        morseshort();
        delay(200);
        morselong();
        delay(600);
        break;

        case 'v':
        morseshort();
        delay(200);
        morseshort();
        delay(200);
        morseshort();
        delay(200);
        morselong();
        delay(600);
        break;

        case 'w':
        morseshort();
        delay(200);
        morselong();
        delay(200);
        morselong();
        delay(600);
        break;

        case 'x':
        morselong();
        delay(200);
        morseshort();
        delay(200);
        morseshort();
        delay(200);
        morselong();
        delay(600);
        break;

        case 'y':
        morselong();
        delay(200);
        morseshort();
        delay(200);
        morselong();
        delay(200);
        morselong();
        delay(600);
        break;

        case 'z':
        morselong();
        delay(200);
        morselong();
        delay(200);
        morseshort();
        delay(200);
        morseshort();
        delay(600);
        break;
        
        default: 
        break;
      } 
    }

    if (newData==false)
    {
      digitalWrite(finish,HIGH);
    }
    memset(receivedChars, 0, sizeof receivedChars);
    
    
}

void recvWithStartEndMarkers() {
    static boolean recvInProgress = false;
    static byte ndx = 0;
    char startMarker = '<';
    char endMarker = '>';
    char rc;
    
    while (Serial.available() > 0 && newData == false) {
        rc = Serial.read();

        if (recvInProgress == true) {
            if (rc != endMarker) {
                receivedChars[ndx] = rc;
                ndx++;
                if (ndx >= numChars) {
                    ndx = numChars - 1;
                }
            }
            else {
                receivedChars[ndx] = '\0'; // terminate the string
                recvInProgress = false;
                ndx = 0;
                newData = true;
            }
        }

        else if (rc == startMarker) {
            recvInProgress = true;
        }
    }
}

void showNewData() {
    if (newData == true) {
        Serial.print("This just in ... ");
        Serial.println(receivedChars);
        newData = false;
    }
}

void morselong(){
  digitalWrite(buzzer,HIGH);
  digitalWrite(LED,HIGH);
  delay(600);
  digitalWrite(buzzer,LOW);
  digitalWrite(LED,LOW);
  //Serial.println("long");
}

void morseshort(){
  digitalWrite(buzzer,HIGH);
  digitalWrite(LED,HIGH);
  delay(200);
  digitalWrite(buzzer,LOW);
  digitalWrite(LED,LOW);
  //Serial.println("short");
}
