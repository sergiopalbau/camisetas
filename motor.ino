//=================================================================================================
void avanzaMotor () {

  int pasos = 300; // cantidad de pasos
  int TIEMPO = 1;
  digitalWrite (PIN_DIR, DIR_AVANZA);
  for (int i = 0; i <= pasos; i++)
  {
    digitalWrite (PIN_STEP, HIGH);
    delay( TIEMPO);
    digitalWrite (PIN_STEP, LOW);
    delay( TIEMPO);
  }

}
//=================================================================================================
void retrocesoMotor () {

  digitalWrite (PIN_DIR, DIR_RETROCESO);
  digitalWrite (PIN_STEP, HIGH);
  delay(1);
  digitalWrite (PIN_STEP, LOW);
  delay(1);
}
//=================================================================================================

void avanzaN (int p, int t)
{
  digitalWrite (PIN_DIR, DIR_AVANZA);
  digitalWrite (PIN_STEP, HIGH);
  delay(1);
  digitalWrite (PIN_STEP, LOW);
  delay(1);
}
//=================================================================================================
void retrocesoN (int p, int t) {

  int pasos = 300; // cantidad de pasos
  int TIEMPO = 1;

  digitalWrite (PIN_DIR, DIR_RETROCESO);
  for (int i = 0; i <= p; i++)
  {
    digitalWrite (PIN_STEP, HIGH);
    delay(t);
    digitalWrite (PIN_STEP, LOW);
    delay(t);
  }
}
