void pruebasIniciales() {


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
  int TIEMPO = 1; // 600 ms
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
