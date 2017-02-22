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
void setup() {
  Serial.begin(9600); // puerto serie activado
  // declaracion pines botones y finales de carrera-----------------------------------
  pinMode(BOTON, INPUT_PULLUP);
  pinMode(FINAL_FIN, INPUT_PULLUP);
  pinMode(FINAL_INICIO, INPUT_PULLUP);
  // declaracion de pines easy driver ----------------------------------------------------------
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
  // prueba rele - se activiara cada rele durante un segundo --------------------------
  // rele 1
  digitalWrite ( RELE1, ACTIVO_RELE);
  Serial.println(" rele1 activo");
  delay (1000);
  digitalWrite (RELE1, PARO_RELE);
  Serial.println(" rele1 apagado");
  delay (1000);
  //rele 2
  digitalWrite ( RELE2, ACTIVO_RELE);
  Serial.println(" rele2 activo");
  delay (1000);
  digitalWrite (RELE2, PARO_RELE);
  Serial.println(" rele2 apagado");
  delay (1000);
  //rele 3
  digitalWrite ( RELE3, ACTIVO_RELE);
  Serial.println(" rele3 activo");
  delay (1000);
  digitalWrite (RELE3, PARO_RELE);
  Serial.println(" rele3 apagado");
  delay (1000);
  //rele4
  digitalWrite ( RELE4, ACTIVO_RELE);
  Serial.println(" rele4 activo");
  delay (1000);
  digitalWrite (RELE4, PARO_RELE);
  Serial.println(" rele4 apagado");
  delay (1000);
  Serial.println ("fIN PRUEBA RELES");
  delay(1000);
  // prueba motor --------------------------------------------------------------------------------------------
  int pasos = 1000; // cantidad de pasos
  int TIEMPO = 600; // 600 ms
  Serial.println(" Prueba avanzado motor");
  digitalWrite (PIN_DIR, DIR_AVANZA);
  for (int i = 0; i <= pasos; i++)
  {
    digitalWrite (PIN_STEP, HIGH);
    delay( TIEMPO);
    digitalWrite (PIN_STEP, LOW);
    delay( TIEMPO);
  }
  Serial.println ("pruieba retroceso motor");
  digitalWrite (PIN_DIR, DIR_RETROCESO);
  for (int i = 0; i <= pasos; i++)
  {
    digitalWrite (PIN_STEP, HIGH);
    delay( TIEMPO);
    digitalWrite (PIN_STEP, LOW);
    delay( TIEMPO);
  }
  Serial.println ("FIN PRUEBA MOTOR");
  delay(1000);

  
  // PRUEBA BOTONES y FINALES DE CARRERA -------------------------------------------------------
  byte boton1 = 0;
  byte final1 = 0;
  byte final2 = 0;
  do {
    boton1 = digitalRead (BOTON);
    final1 = digitalRead (FINAL_FIN);
    final2 = digitalRead (FINAL_INICIO);
    if ( boton1 == ACTIVO_BOTON)
      Serial.print ( "BOTON: ON \t");
    else
      Serial.print ( "BOTON: OFF \t");
    if (final1 == ACTIVO_F_F)
      Serial.print ( "FINAL FIN: ON \t");
    else
      Serial.print ( "FINAL FIN: OFF \t");
    if ( final1 == ACTIVO_F_F)
      Serial.println ( "FINAL INCIO: ON \t");
    else
      Serial.println ( "FINAL INICIO: OFF \t");
    delay (1000);
  } while (1);
}

