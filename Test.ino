// ARDUINO REACTION TIMER
// include the library code:


// declare button pin
const int button = 2;
const int button2 = 3;

// declare varible
double reaction = 0;
double reaction2 = 0;
unsigned long time = 0;

// declare output LED's
const int stage = 5;
const int amber1 = 6;
const int amber2 = 7;
const int amber3 = 8;
const int green = 9;
const int red = 10;
const int stage2 = 4;
const int green2 = 11;
const int red2 = 12;

// declare fuctions
void Start();



void setup()
{  
  // set up the lcd's number of columns and rows: 
  Serial.begin(9600);
  // Print a message to the lcd.
  Serial.println("Drag Racing Tree!"); 
  // button pin
  pinMode(button, INPUT);
  pinMode(button2, INPUT);
  // light pins
  pinMode(stage, OUTPUT);
  pinMode(amber1, OUTPUT);
  pinMode(amber2, OUTPUT);
  pinMode(amber3, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(red, OUTPUT);
  pinMode(stage2, OUTPUT);
  pinMode(green2, OUTPUT);
  pinMode(red2, OUTPUT);
}

void loop() 
{

  if(digitalRead(button2)==HIGH)
  {
    Serial.println("Burn Out");
    digitalWrite(stage2, LOW);
    digitalWrite(amber1, HIGH);
    digitalWrite(amber2, HIGH);
    digitalWrite(amber3, HIGH);
    digitalWrite(green2, HIGH);
    digitalWrite(red2, HIGH);
  }
  

  
  if(digitalRead(button2)== HIGH)
    {
      delay(random(500,2000));
      Serial.println("               ");
      Start();
    }
}

void Start()
{              
  digitalWrite(stage2, HIGH);
  digitalWrite(amber1, LOW);
  digitalWrite(amber2, HIGH);
  digitalWrite(amber3, HIGH);
  digitalWrite(green2, HIGH);
  digitalWrite(red2, HIGH);
  delay(500);
  digitalWrite(stage2, HIGH);
  digitalWrite(amber1, HIGH);
  digitalWrite(amber2, LOW);
  digitalWrite(amber3, HIGH);
  digitalWrite(green2, HIGH);
  digitalWrite(red2, HIGH);
  delay(500);
  digitalWrite(stage2, HIGH);
  digitalWrite(amber1, HIGH);
  digitalWrite(amber2, HIGH);
  digitalWrite(amber3, LOW); time = millis(); // start timing on the third amber
  digitalWrite(green2, HIGH);
  digitalWrite(red2, HIGH);
  
  // with while loop for the delay
  while( ((millis() - time)<499.9)&&(digitalRead(button2) == HIGH))
  {// purposly left blank // used for an active delay
  }
  if(digitalRead(button2) == LOW )
  {
    digitalWrite(stage2, HIGH);
    digitalWrite(amber1, HIGH);
    digitalWrite(amber2, HIGH);
    digitalWrite(amber3, HIGH);
    digitalWrite(green2, HIGH);
    digitalWrite(red2, LOW);
    reaction = ((millis() - time));
    reaction = reaction * .001;
    Serial.println(reaction,4);
    Serial.println(" sec. FAIL");
    delay(2000);
  }
  
  if(digitalRead(button2) == HIGH )
  {
    digitalWrite(stage2, HIGH);
    digitalWrite(amber1, HIGH);
    digitalWrite(amber2, HIGH);
    digitalWrite(amber3, HIGH);
    digitalWrite(green2, LOW);
    digitalWrite(red2, HIGH);
    while(digitalRead(button2) == HIGH )
    {
      if(digitalRead(button2) == LOW )
      {
      reaction = ((millis() - time));
      reaction = reaction * .001;
      Serial.println(reaction,3);
      Serial.println(" sec.");
      }
     }
    delay(5000);
   
  }
}
