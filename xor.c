#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h> //per rand e srand

char plain[128], chiave[128], out[128];
time_t t; //inizializzo seme con tempo attuale
char scelta;
int caso1();
int caso2();
int a;


int main ()
{


  printf("Inserire una stringa di massimo 128 caratteri. ATTENZIONE: stringhe superiori a 128 caratteri saranno troncate alla lunghezza massima di 128:\n");
  fgets (plain, 128, stdin); //input sicuro a 128 caratteri
  /*char c;
  while((c = getchar()) != '\n' && c != '\0');*/


  //fflush(stdin); pulisco lo standard input per evitare buffer di input incasinati in futuro

  a = strlen (plain) - 1;
  printf("\nLa lunghezza del valore inserito corrisponde a: %d\n", a);

  //provare fgets

  //uso do... while (!check); cioè se si è triggerato il check
  int check = 0;

  do {
    printf("\nScegliere come procedere:\n1) per inserire una chiave personale\n2) per generarla randomicamente\n");
    scanf("%c", &scelta);
    char c;
    while((c = getchar()) != '\n' && c != EOF);


    printf("scelta effettuata: %c\n", scelta);

    //printf ("DEBUG sono nel do\n");

    switch (scelta){
      case '1':
      //printf("DEBUG sono nel caso 1 nello switch\n");
      check = 1;
      caso1();
          break;



      case '2':
      //printf("DEBUG sono nel caso 2 nello switch\n");
      check = 1;
      caso2();

          break;

      default:
        printf("\nLa scelta deve essere 1 0 2\n");

        }

  } while (!check);

}

int caso1(){
  char reverse[128];

  printf("\nInserire manualmente chiave di cifratura di lunghezza minima %d e massima 128\n", a);

  do {

    fgets (chiave, 128, stdin);
    if(strlen(chiave) <  strlen (plain)) {
      printf ("\nInserire un input tra %d e 128 caratteri:\n", a);

    }
  } while (strlen (chiave) < strlen (plain));
  //stampo chiave (debug)
  printf("\nChiave personale inserita: %s\n", chiave);
  for (int i = 0; i < strlen(plain); i++) {

    out[i] = plain[i] ^ chiave [i];

  }
  for (int i = 0; i < a; i++){
    printf("Valore %d cifrato: %X\n", i + 1 , out[i]);
  }
  printf("\nStringa cifrata: ");
  for(int i = 0; i < a; i++){

    printf("%X", out[i]);
  }

  printf("\n\n");

  //formula inversa per stringa originale

  for (int i = 0; i < a; i++) {

    reverse[i] = out[i] ^ chiave[i];
    printf("Valore %d stringa originale (ottenuta con formula inversa): %c\n", i + 1, reverse[i]);

  }


return 0;


}

int caso2() {
  printf("\n");
  char reverse[128];

  srand((unsigned)time(&t));
  for(int i = 0; i < strlen(plain); i++) {

    chiave[i] = rand()%128;

  }
  //cifratura (xor)
  for(int i = 0; i < a; i++){
    out[i] = plain[i] ^ chiave [i];

  }
  //stampo chiave di sicurezza
  for(int i = 0; i < a; i++){
    printf("Carattere %d chiave di sicurezza: %c\n", i + 1, chiave[i]);
  }
  printf("\nStringa cifrata: ");

  //stampo chiave di sicurezza
  for(int i = 0; i < a; i++){
    printf("%c", chiave[i]);
  }
  printf("\n\n");

  printf("\n");
  for(int i = 0; i < a; i++){

    printf("Valore %d cifrato: %c\n", i + 1 , out[i]);
  }
  printf("\n");


  //uso formula inversa per calcolo del plain
  printf("\n");


  for (int i = 0; i < a; i++) {

    reverse[i] = out[i] ^ chiave[i];
    printf("Valore %d stringa originale (ottenuto con formula inversa): %c\n", i + 1, reverse[i]);

  }
  //printf("Chiave di cifratura: %s\n", chiave);



return 0;
}
