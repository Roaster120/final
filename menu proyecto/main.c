#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "funciones.h"
#include <time.h>
#include <math.h>
#include <windows.h>

int main()
{
    FILE*archivo=NULL;
    char*nombrearchivo="ganadas";
    archivo=fopen(nombrearchivo,"a");
    if (archivo==NULL){return -1;}
    int lectura;
    fscanf(archivo,"%d",&lectura);
    printf("lectura:%d",lectura);
    return 0;}//    int a;
//    printf("Bienvenido a mi compilatorio de juegos\neliga su juego\n1.buscaminas\n2.tres en raya\n");
//    scanf("%d",&a);
//    if (a==1){   char vectormina[8][8],nivel, vectormuerte[8][8], fin, condicion;
//        int clicki=0, clickj=0, posicion=0, acum = 0;
//        int i=0,j=0;
//        int s=0, m=0, h=0; //contadores para el cronometro
//        system("color f");
//        //LLAMADO DE LAS FUNCIONES DECLARADAS
//        Bienvenida();
//        Eleccion(&nivel);
//        Inicializar(vectormina, vectormuerte);
//        Random(vectormuerte, &nivel, i, j);
//        Mostrar(vectormina);
//        do
//        {
//            Pregunta(&condicion);
//            if (condicion=='b'|| condicion=='B')
//            {Bandera( vectormuerte, vectormina, &clicki, &clickj, &acum);}
//            else if( condicion=='c' || condicion== 'C')
//            {
//                Coordenada(vectormina, vectormuerte, &clicki, &clickj, posicion, &acum);
//            }
//            Mostrar(vectormina);
//            if (vectormuerte[clicki-1][clickj-1] == 'X' && condicion=='c' || vectormuerte[clicki-1][clickj-1] == 'X' && condicion=='C')
//            {//LA PARTIDA HABRA TERMINADO
//                fin = 'X';
//                for (int i=0; i<8; i++)
//                {for(int j=0; j<8; j++)
//                    {if (vectormuerte[i][j]=='X')
//                        {vectormina[i][j]=0;
//                        vectormina[i][j]= vectormuerte[i][j];
//                        }
//                    }
//                }
//                system("cls");
//
//                Mostrar(vectormina);
//
//
//                printf("\n\n     :::::::::Usted ha perdido !x_x!   LA PARTIDA HA FINALIZADO:::::::::\n");
//                system("pause");
//                system("cls");
//                printf("\n El puntaje obtenido en la partida es %i\n", acum);
//                printf("\n El tiempo jugado fue:\n");
//                printf("%i %i %i",h,m,s);
//                printf("\n\n       ");
//                system("pause");
//            }
//}while (fin != 'X');
//
//}else if(a==2){
//    char c[3] [3];
//    int i,j;
//    i=0;
//    intro_primera(c);
//
//    do
//    {
//        system("cls");
//        tablero(c);
//        if(i%2==0)
//        {
//            intro_yo(c);
//        }
//        else
//        {
//            intro_tu(c);
//        }
//        j=ganador(c);
//        i++;
//    }
//    while(i<=9 && j==2);
//    system("cls");
//    tablero(c);
//    if (j==0)
//    {
//        printf ("\ngana jugador uno");
//    }
//    else if (j==1)
//    {
//        printf("\ngana jugador dos ");
//    }
//
//}
//
//
//    return 0;
//}
