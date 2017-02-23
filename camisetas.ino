


//---------------------------------------------------------
//| d0| d1| d2| d3| d4| d5| d6| d7| d8| d9|d10|d11|d12|d13|
//---------------------------------------------------------
// | x| x | x | x | x | x | x | x | x | x | x |   |   |   | 
//---------------------------------------------------------


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
#define RELE1 10    // bomba1
#define RELE2 9     // bomba2
#define RELE3 8     // alimentacion easydriver
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
  
pruebasIniciales();

}//fin setup()


//=================================================================================================
void loop (){
  Serial.println ("pulse el boton para comenzar ...");
  boolean botonAZ = false;
  boolean salida = false;
  do
  {
    botonAZ =digitalRead (BOTON);
    if (botonAZ == ACTIVO_BOTON);
    {
      delay(40);
      botonAZ =digitalRead (BOTON);  
      if (botonAZ == ACTIVO_BOTON);
           salida = true;      
    }
  
  }while (!salida);

  
  
  digitalWrite ( RELE3, ACTIVO_RELE);      // alimentamos el rele del easy driver
  avanzaN (10,1);
  digitalWrite (RELE1, ACTIVO_RELE);    // BOMBA 1
  do
  {
    avanzaN (50,1);
    
  } while ( digitalRead (FINAL_FIN));
  digitalWrite (RELE1, PARO_RELE);    // BOMBA 1 parada

  do
  {
    retrocesoN (50,1);
    
  }while (digitalRead (FINAL_INICIO));
  digitalWrite(RELE3, PARO_RELE);
  Serial.println ("FIN DEL PROCESO 1");


  
}//fin loop()












