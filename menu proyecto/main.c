#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "funciones.h"
#include <time.h>
#include <math.h>
#include <windows.h>

int main()
{ char c[3][3];
       int a;
       char x[80];
    printf("Bienvenido a mi compilatorio de juegos\neliga su juego\n1.buscaminas\n2.tres en raya\n3.ver historial\n");
    scanf("%d",&a);
    if (a==1){   char vectormina[8][8],nivel, vectormuerte[8][8], fin, condicion;
        int clicki=0, clickj=0, posicion=0, acum = 0;
        int i=0,j=0;
        int s=0, m=0, h=0; //contadores para el cronometro
        system("color f");
        //LLAMADO DE LAS FUNCIONES DECLARADAS
        Bienvenida();
        Eleccion(&nivel);
        Inicializar(vectormina, vectormuerte);
        Random(vectormuerte, &nivel, i, j);
        Mostrar(vectormina);
        do
        {
            Pregunta(&condicion);
            if (condicion=='b'|| condicion=='B')
            {Bandera( vectormuerte, vectormina, &clicki, &clickj, &acum);}
            else if( condicion=='c' || condicion== 'C')
            {
                Coordenada(vectormina, vectormuerte, &clicki, &clickj, posicion, &acum);
            }
            Mostrar(vectormina);
            if (vectormuerte[clicki-1][clickj-1] == 'X' && condicion=='c' || vectormuerte[clicki-1][clickj-1] == 'X' && condicion=='C')
            {//LA PARTIDA HABRA TERMINADO
                fin = 'X';
                for (int i=0; i<8; i++)
                {for(int j=0; j<8; j++)
                    {if (vectormuerte[i][j]=='X')
                        {vectormina[i][j]=0;
                        vectormina[i][j]= vectormuerte[i][j];
                        }
                    }
                }
                system("cls");

                Mostrar(vectormina);


                printf("\n\nLA PARTIDA HA FINALIZADO:::::::::\n");
                system("pause");
                system("cls");
                printf("\n El puntaje obtenido en la partida es %i\n", acum);
                printf("\n El tiempo jugado fue:\n");
                printf("%i %i %i",h,m,s);
                printf("\n\n       ");
                system("pause");
            }
}while (fin != 'X');

}else if(a==2){
   int i,j;
    i=0;
    intro_primera(c);

    do
    {
        system("cls");
        tablero(c);
        if(i%2==0)
        {
            intro_yo(c);
        }
        else
        {
            intro_tu(c);
        }
        j=ganador(c);
        i++;
    }
    while(i<9 && j==2);
    system("cls");
    tablero(c);
    if (j==0)
    {
        printf ("\nganas jugador uno");
        puntos2();
    }
    else if (j==1)
    {
        printf("\ngana jugador dos ");
        puntos3();

    }else {printf("\n empate intentelo de nuevo\n");
    return 0;}


}else if (a==3){
    FILE *archivo1;
    int letra1, contador1= 0;
    archivo1= fopen("ganadas_x.txt","r");
    while(letra1!=EOF)
    {
        letra1= getc(archivo1);
        if(letra1==99)
            contador1++;};

    fclose(archivo1);
    printf("\nvictorias de X\n");
    printf("%d",contador1);







  FILE *archivo2;
    int letra2, contador2= 0;
    archivo2= fopen("ganadas_O.txt","r");
    while(letra2!=EOF)
    {
        letra2= getc(archivo2);
        if(letra2==99)
            contador2++;}

    fclose(archivo2);
    printf("\nvictorias de O\n");
    printf("%d",contador2);


  FILE*archivo3;
    int letra3, contador3= 0;
    archivo3=fopen("ganadas.txt","r");
    while(letra3!=EOF)
    {
        letra3= getc(archivo3);
        if(letra3==99)
            contador3++;};

    fclose(archivo3);
    printf("\nvictorias de minas\n");
    printf("%d",contador3);
}
    return 0;
}
