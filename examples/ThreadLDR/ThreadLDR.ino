#include <Lolin3.h>
#include <Threadable.h>
#include <LightDependentResistor.h>

class LDRThreadable : public LightDependentResistor, public Threadable{
  public:
    LDRThreadable(){
      Setup();
    }

    void Start() override {
      Threadable::Start();
      Serial.println("Iniciando LDR Threadable...");
    }

    void Tick() override {
      Read();
    }
};

LDRThreadable ldr;

void setup() {
  Serial.begin(9600);
  delay(500);
  Serial.println("..");
  pinMode(LED_BUILTIN, OUTPUT);

  ldr.Setup(D2, [](bool value){
    if(value){
      Serial.println("Turn ON");
    } else {
      Serial.println("Turn OFF");
    }
  });

  ldr.Start();
  Serial.println("Starting...");
}

void loop() {
  ldr.Loop();
}