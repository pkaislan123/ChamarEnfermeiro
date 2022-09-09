

String nome_quartos[14];
int quartos[14];

String nome_leitos[28];
int leitos[28];

void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);

  //Quartos
  int porta = 2;
  int num_quarto_person = 51;
  int num_quarto_person2 = 1;

  for (int i = 0; i <= 13; i++) {
    if (porta == 2) {
      nome_quartos[i] = "Quarto 2";
    } else if (porta == 3) {
      nome_quartos[i] = "Quarto 3";
    } else if (porta >= 4 && porta <= 11) {
      String num_quarto = String(num_quarto_person);
      nome_quartos[i] = "Quarto " +  num_quarto;
      num_quarto_person++;

      if (num_quarto_person == 55) {
        num_quarto_person = 58;
      }

    } else if (porta >= 22 && porta <= 24) {
      String num_quarto = String(num_quarto_person2);
      String nome_quarto = "Quarto PO";
      nome_quarto.concat(num_quarto);
      nome_quartos[i] =  nome_quarto;
      num_quarto_person2++;
    } else if (porta == 25) {
      nome_quartos[i] = "Quarto 38";
    }



    quartos[i] = porta;
    pinMode(quartos[i], INPUT);
    porta++;

    if (porta == 12) {
      porta = 22;
    }

  }

  for (int i = 0; i <= 13; i++) {
    Serial.print(nome_quartos[i]);
    Serial.print(" listado na porta ");
    Serial.print(quartos[i]);
    Serial.println();
    delay(20);
  }


  //Leitos

  porta = 26;
  int num_leito_person = 1;

  for (int i = 0; i <= 27; i++) {

    if (porta >= 26 && porta <= 27) {
      String num_leito = String(num_leito_person);
      String nome_leito = "Leito 2_";
      nome_leito.concat(num_leito);
      nome_leitos[i] =  nome_leito;
      num_leito_person++;

      if (num_leito_person == 3)
        num_leito_person = 1;

    } else if (porta >= 28 && porta <= 29) {
      String num_leito = String(num_leito_person);
      String nome_leito = "Leito 3_";
      nome_leito.concat(num_leito);
      nome_leitos[i] =  nome_leito;
      num_leito_person++;

      if (num_leito_person == 3)
        num_leito_person = 1;

    } else if (porta >= 30 && porta <= 32) {
      String num_leito = String(num_leito_person);
      String nome_leito = "Leito 5";
      nome_leito.concat(num_leito);
      nome_leitos[i] =  nome_leito;

      

      num_leito_person++;

      if (num_leito_person == 5)
        num_leito_person = 1;

      if (num_leito_person == 3)
        num_leito_person = 4;

    } else if (porta >= 33 && porta <= 34) {
      String num_leito = String(num_leito_person);
      String nome_leito = "Leito 55_";
      nome_leito.concat(num_leito);
      nome_leitos[i] =  nome_leito;
      num_leito_person++;

      if (num_leito_person == 3)
        num_leito_person = 1;
    } else if (porta == 35) {
      nome_leitos[i] =  "Leitor 58";
    } else if (porta >= 36 && porta <= 40) {
      String num_leito = String(num_leito_person);
      String nome_leito = "Leito 59_";
      nome_leito.concat(num_leito);
      nome_leitos[i] =  nome_leito;
      num_leito_person++;

      if (num_leito_person == 6)
        num_leito_person = 1;
    } else if (porta >= 41 && porta <= 44) {
      String num_leito = String(num_leito_person);
      String nome_leito = "Leito 60_";
      nome_leito.concat(num_leito);
      nome_leitos[i] =  nome_leito;
      num_leito_person++;

      if (num_leito_person == 5)
        num_leito_person = 1;
    } else if (porta >= 45) {
      String num_leito = String(num_leito_person);
      String nome_leito = "Leito 61_";
      nome_leito.concat(num_leito);
      nome_leitos[i] =  nome_leito;
      num_leito_person++;
    }


    leitos[i] = porta;
    pinMode(leitos[i], INPUT);
    porta++;


  }

  Serial.println();
  Serial.println();
  Serial.println();

  for (int i = 0; i <= 27; i++) {
    Serial.print(nome_leitos[i]);
    Serial.print(" listado na porta ");
    Serial.print(leitos[i]);
    Serial.println();
    delay(20);
  }


}

void loop() {
  
    for (int i = 0; i <= 13; i++) {

      int estado = digitalRead(quartos[i]);
      if (estado == 1) {

        Serial.print(nome_quartos[i]);
        Serial.print(" listado na porta ");
        Serial.print(quartos[i]);
        Serial.println(" está chamando");
        Serial.println();
        delay(100);
      }
    }

    for (int i = 0; i <= 27; i++) {

      int estado = digitalRead(leitos[i]);
      if (estado == 1) {

        Serial.print(nome_leitos[i]);
        Serial.print(" listado na porta ");
        Serial.print(leitos[i]);
        Serial.println(" está chamando");
        Serial.println();
        delay(100);
      }
    }


  


}
