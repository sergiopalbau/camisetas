

// ENTRADAS DIGITALES Y FINAL DE CARRERA-----------
#define BOTON 4
#define ACTIVO_BOTON 0
#define FINAL_FIN 5
#define ACTIVO_F_F 0
#define FINAL_INICIO 6
#define ACTIVO_F_I 0
// EASY DRIVER ------------------------------------
#define PIN_STEP 3 // PULSOS DE AVANCE
#define PIN_DIR 2 // DIRECCION DEL MOTOR
#define DIR_AVANZA 1
#define DIR_RETROCESO 0
// RELES -----------------------------------------
#define RELE1 10
#define RELE2 9
#define RELE3 8
#define RELE4 7
#define ACTIVO_RELE 1
#define PARO_RELE 0

//=================================================================================================
void setup() {
  Serial.begin(9600); // puerto serie activado
  // declaracion pines botones y finales de carrera------------------------------------------------
  pinMode(BOTON, INPUT_PULLUP);
  pinMode(FINAL_FIN, INPUT_PULLUP);
  pinMode(FINAL_INICIO, INPUT_PULLUP);
  // declaracion de pines easy driver -------------------------------------------------------------
  pinMode(PIN_STEP, OUTPUT);
  pinMode(PIN_DIR, OUTPUT);
  // apagamos las salidas por seguridad
  digitalWrite (PIN_STEP, 0);
  digitalWrite (PIN_DIR, 0);
  // declaracion de pines reles ------------------------------------------------------------------
  pinMode(RELE1, OUTPUT);
  pinMode(RELE2, OUTPUT);
  pinMode(RELE3, OUTPUT);
  pinMode(RELE4, OUTPUT);

  digitalWrite (RELE1, PARO_RELE);
  digitalWrite (RELE2, PARO_RELE);
  digitalWrite (RELE3, PARO_RELE);
  digitalWrite (RELE4, PARO_RELE);
  pruebasiniciales();

}//fin setup()
//=================================================================================================
void loop (){
  delay(10);
}//fin loop()

