#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "funciones.h"
#include <time.h>
#include <math.h>
#include <windows.h>
void Bienvenida()
{
    char rsp;
    printf("\n Bienvenidos al buscaMinas \n");


    printf("\n Sabe usted como jugar BuscaMinas ? Si(Presione cualquier tecla), No(n)\n");
    scanf(" %c", &rsp);

    if (rsp == 'n'|| rsp == 'N')
    {
        system("cls");
        printf("\n Buscaminas es un juego basado en un tablero, en este caso de 8 filas\n");
        printf("\n y 8 columnas. El juego, dependiendo del nivel que usted seleccione, \n");
        printf("\n arrojara un numero de minas al tablero. Jugada tras jugada, debera \n");
        printf("\n ingresar una coordenada con dos posibilidades: abrir la casilla escogida\n");
        printf("\n o colocar una bandera 'B', indicando que cree que ahi se encuentra una mina.\n");
        printf("\n Al seleccionar una casilla si se encuentra una mina aparecera una 'X', de\n");
        printf("\n de lo contrario aparecera un numero, que indicara el numero de minas que\n");
        printf("\n se encuentran en el perimetro; asi: si aparece el numero 1, significa que\n");
        printf("\n hay una mina en el perimetro de esa casilla.\n");
        printf("\n El objetivo del buscaminas es lograr descubrir las casillas minadas, \n");
        printf("\n pero sin activarlas, es decir, localizarlas por descarte, prestando \n");
        printf("\n atencion a los cuadros numericos que ayudan a revelar la ubicacion de las \n");
        printf("\n minas\n");
        printf("\n \n");
        printf("\n EL jugador podra marcar las minas para bloquearlas y acumular puntos\n");
        printf("\n Si el jugador marca una casilla sin minas, entonces se le sumara un punto\n");
        printf("\n La partida habra terminado cuando el jugador active una mina\n");
        printf("\n Gana el jugador que obtenga mas puntos siempre y cuando el puntaje sea positivo\n");
        system("pause");
    }
    else if  (rsp == 'S'|| rsp == 's')
    {
        printf("\n Listo para jugar, solo \n");
        system("pause");
    }
}void Eleccion(char *nivel)
{


    system("cls");
    printf("\n Ingrese el nivel de dificultad en el cual desea jugar:\n");
    printf("\n Facil<1>, Intermedio <2>, Dificil <3>\n");
    printf("\n Facil:      para jugar con 3 minas en tablero.\n");
    printf("\n Intermedio: para jugar con 6 minas en tablero.\n");
    printf("\n Dificil:    para jugar con 10 minas en tablero.\n");

    do
    {
        scanf(" %c", &*nivel);
        system("cls");
        if(*nivel!='1' && *nivel!='2' && *nivel!='3')
        {

            printf("\n El nivel ingresado es incorrecto por favor ingrese un dato valido\n\n");
        }
    }
    while( *nivel!='1' && *nivel!='2' && *nivel!='3' );
}
void Inicializar(char vectormina[][8], char vectormuerte[][8])
{
    for(int i=0; i<8; i++)
    {
        for(int j=0; j<8; j++)
        {
            vectormina[i][j]='$';
            vectormuerte[i][j]=0;
        }
    }
}
void Random(char vectormuerte[][8], char *nivel, int i, int j)
{

    //CONDICIONES PARA LA VARIABLE NIVEL
    if (*nivel == '1')
    {
        printf("\n Ha seleccionado el Nivel Facil\n");
        system("pause");


        srand(time(NULL));//semilla random

        for(int k =1; k <=3; k++)
        {

            if(vectormuerte[i][j] != 'X')
            {

                i = (rand() % 8);

                j = (rand() % 8);
            }

            else if(vectormuerte[i][j] == 'X')
            {


                i = (rand() % 7)+1;

                j = (rand() % 7)+1;

            }

            vectormuerte[i][j] = 'X';




        }
    }

    else if (*nivel == '2')
    {
        printf("\n Ha seleccionado el nivel Intermedio\n");
        system("pause");

        srand(time(NULL)); //SEMILLA DEL RANDOM 2

        for(int k =1; k <=6; k++)
        {
            if(vectormuerte[i][j] != 'X')
            {

                i = (rand() % 8);

                j = (rand() % 8);
            }

            else if(vectormuerte[i][j] == 'X')
            {


                i = (rand() % 7)+1;

                j = (rand() % 7)+1;

            }

            vectormuerte[i][j] = 'X';



        }
    }

    else if (*nivel == '3')
    {
        printf("\n Ha seleccionado el nivel Dificil\n");
        system("pause");



        srand(time(NULL)); //SEMILLA DEL RANDOM 3

        for(int k =1; k <=10; k++)
        {
            if(vectormuerte[i][j] != 'X')
            {

                i = (rand() % 8);

                j = (rand() % 8);
            }

            else if(vectormuerte[i][j] == 'X')
            {


                i = (rand() % 7)+1;

                j = (rand() % 7)+1;

            }




            vectormuerte[i][j] = 'X';






        }

    }
}   // FIN DEL VOID RANDOM
void Mostrar(char vectormina[][8])
{

    printf("\n\n");
    printf("                   ");
    for(int i = 1; i <= 8; i++)
    {

        printf("( %i )", i);
    }
    printf("\n");

    for(int i = 1; i <= 8; i++)
    {
        printf("\n              ( %i )", i);
        for(int j = 1; j <= 8; j++)
        {

            printf("[ %c ]", vectormina[i-1][j-1]);
        }
        printf("\n");
    }
}
void Pregunta(char *condicion)
{
    printf("\n Si desea desbloquear una casilla marque la letra 'c'\n");
    printf("\n Si desea marcar una casilla marque la letra 'b'\n");

    do
    {

        scanf(" %c", &*condicion);

        if( *condicion!='c' && *condicion!='C' && *condicion!='b' && *condicion!='B')
        {
            printf("\n    Opcion equivocada, seleccione una opcion valida ('c') o ('b')\n ");
        }

    }
    while( *condicion!='c' && *condicion!='C' && *condicion!='b' && *condicion!='B');

}
void Bandera(char vectormuerte[][8], char vectormina[][8], int *clicki, int *clickj,  int *acum)

{
    do
    {
        printf("\n Ingrese la coordenana que desea marcar (en forma de fila y columna)\n");

        scanf("%i", &*clicki);
        scanf("%i", &*clickj);

        if(vectormina[*clicki-1][*clickj-1]!='$')
        {

            system("cls");

            printf("\n                La coordenada seleccionada ya fue utilizada\n");

            Mostrar(vectormina);
        }

    }
    while (vectormina[*clicki-1][*clickj-1]!='$');

    vectormina[*clicki-1][*clickj-1] = 0;
    vectormina[*clicki-1][*clickj-1] = 'B';

    //CONDICION PARA SUMAR O RESTAR PUNTOS
    if (vectormuerte[*clicki-1][*clickj-1] == 'X')
    {
        *acum = *acum + 5;
    }
    else if (vectormuerte[*clicki-1][*clickj-1] != 'X')
    {
        *acum = *acum -2;
    }

}
void Coordenada(char vectormina[][8], char vectormuerte[][8], int *clicki, int *clickj, int posicion, int *acum)
{
    do
    {

        printf("\n Ingrese la coordenada que desea desbloquear (en forma de fila y columna)\n");

        scanf("%i", &*clicki);
        scanf("%i", &*clickj);

        if(vectormina[*clicki-1][*clickj-1]!='$' && vectormina[*clicki-1][*clickj-1]!='B')
        {

            system("cls");

            printf("\n                La coordenada seleccionada ya fue utilizada\n\n");

            Mostrar(vectormina);

        }

    }
    while (vectormina[*clicki-1][*clickj-1]!='$' && vectormina[*clicki-1][*clickj-1]!='B');


    if (vectormina[*clicki-1][*clickj-1]!='$')
    {
        acum++;

    }


    if (vectormuerte[*clicki-1][*clickj-1] != 'X')
    {
        acum++;

        if ((*clicki-1)!=0 && (*clicki-1)!=7 && (*clickj-1)!=0 && (*clickj-1)!=7) //Calculo Matriz central
        {

            for (int i=0; i<3; i++)
            {
                for (int j=0; j<3; j++)
                {

                    if (vectormuerte[*clicki-2+i][*clickj-2+j]=='X')
                    {
                        posicion++;

                    }
                }
            }

        }

        else if( (*clicki-1)==0 && (*clickj-1)!=0 && (*clickj-1)!=7) //Validacion Fila 0
        {
            for (int i=0; i<3; i++)
            {
                for (int j=0; j<3; j++)
                {
                    do
                    {

                        if (vectormuerte[*clicki-2+i][*clickj-2+j]=='X')
                        {
                            posicion++;

                        }
                    }
                    while( (*clicki-1>0) );
                }
            }
        }



        else if( (*clicki-1)==7 && (*clickj-1)!=0 && (*clickj-1)!=7) //Validacion Fila 7
        {
            for (int i=0; i<3; i++)
            {
                for (int j=0; j<3; j++)
                {
                    do
                    {

                        if (vectormuerte[*clicki-2+i][*clickj-2+j]=='X')
                        {
                            posicion++;

                        }
                    }
                    while( (*clicki-1<8) );
                }
            }
        }

        else if( (*clickj-1)==0 && (*clicki-1)!=0 && (*clicki-1)!=7) //Validacion columna 0
        {
            for (int i=0; i<3; i++)
            {
                for (int j=0; j<3; j++)
                {
                    do
                    {

                        if (vectormuerte[*clicki-2+i][*clickj-2+j]=='X')
                        {
                            posicion++;

                        }
                    }
                    while( (*clickj-1<0) );
                }
            }
        }

        else if( ( (*clickj-1)==7 && (*clicki-1)!=0 && (*clicki-1)!=7)) //Validacion columna 7
        {
            for (int i=0; i<3; i++)
            {
                for (int j=0; j<3; j++)
                {
                    do
                    {

                        if (vectormuerte[*clicki-2+i][*clickj-2+j]=='X')
                        {
                            posicion++;

                        }
                    }
                    while( (*clickj-1<8) );
                }
            }
        }

        else if( ( (*clickj-1)==0 && (*clicki-1)==0) ) //Validacion Esquina 1
        {
            for (int i=0; i<3; i++)
            {
                for (int j=0; j<3; j++)
                {
                    do
                    {

                        if (vectormuerte[*clicki-2+i][*clickj-2+j]=='X')
                        {
                            posicion++;

                        }
                    }
                    while( (*clickj-1<0) && (*clicki-1<0) );
                }
            }
        }

        else if( ( (*clickj-1)==0 && (*clicki-1)==7) ) //Validacion Esquina 2
        {
            for (int i=0; i<3; i++)
            {
                for (int j=0; j<3; j++)
                {
                    do
                    {

                        if (vectormuerte[*clicki-2+i][*clickj-2+j]=='X')
                        {
                            posicion++;

                        }
                    }
                    while( (*clicki-1<0) && (*clickj-1<8) );
                }
            }
        }

        else if( ( (*clickj-1)==7 && (*clicki-1)==0) ) //Validacion Esquina 3
        {
            for (int i=0; i<3; i++)
            {
                for (int j=0; j<3; j++)
                {
                    do
                    {

                        if (vectormuerte[*clicki-2+i][*clickj-2+j]=='X')
                        {
                            posicion++;

                        }
                    }
                    while( (*clicki-1<8) && (*clickj-1<0) );
                }
            }
        }

        else if( ( (*clickj-1)==7 && (*clicki-1)==7) ) //Validacion Esquina 4
        {
            for (int i=0; i<3; i++)
            {
                for (int j=0; j<3; j++)
                {
                    do
                    {

                        if (vectormuerte[*clicki-2+i][*clickj-2+j]=='X')
                        {
                            posicion++;

                        }
                    }
                    while( (*clicki-1<7) && (*clickj-1<7) );
                }
            }
        }



        switch(posicion)
        {
        case 1:
            vectormuerte[*clicki-1][*clickj-1] = '1';
            break;

        case 2:
            vectormuerte[*clicki-1][*clickj-1] = '2';
            break;

        case 3:
            vectormuerte[*clicki-1][*clickj-1] = '3';
            break;

        case 4:
            vectormuerte[*clicki-1][*clickj-1] = '4';
            break;

        case 5:
            vectormuerte[*clicki-1][*clickj-1] = '5';
            break;

        case 6:
            vectormuerte[*clicki-1][*clickj-1] = '6';
            break;

        case 7:
            vectormuerte[*clicki-1][*clickj-1] = '7';
            break;

        case 8:
            vectormuerte[*clicki-1][*clickj-1] = '8';
            break;
        }




    }
    vectormina[*clicki-1][*clickj-1] = 0;
    vectormina[*clicki-1][*clickj-1] = vectormuerte[*clicki-1][*clickj-1];
}
void cronometro(int s, int m, int h)
{
    while(1)
    {
        if (s >=60)
        {
            s = 0;
            m++;
            if (m >= 60)
            {
                m = 0;
                h++;
            }
        }

        Sleep(1000);
        s++;


    }
    getch();
}

void intro_primera(char c[3][3])
{
    int i,j;
    char aux;
    aux='1';
    for (i=0; i<3; i++)
    {
        for(j=0; j<3; j++)
        {
            c[i][j]=aux++;
        }


    }
}
void tablero(char c[3][3])
{
    int i,j;
    for(i=0; i<3; i++)
    {


        for (j=0; j<3; j++)
        {

            if (j<2)
            {


                printf(" %c |",c[i][j]);
            }
            else
            {
                printf("%c",c[i][j]);
            }
        }
        if (i<2)
        {
            printf("\n-----------\n");
        }
    }
}
void intro_yo(char c[3][3])
{
    int i,j,k;
    char aux;
    do
    {
        do
        {
            printf("\n coloca una ficha:");
            fflush(stdin);
            scanf("%c",&aux);
        }
        while(aux<'1'||aux>'9');
        k=0;
        switch(aux)
        {
        case '1':
        {
            i=0;
            j=0;
            if(c[i][j]=='x'||c[i][j]=='O')
            {
                k=1;
                printf("la casilla esta ocupada! intenta otra!!\n\n");
            }
            break;
        }
        case '2':
        {
            i=0;
            j=1;
            if(c[i][j]=='x'||c[i][j]=='O')
            {
                k=1;
                printf("la casilla esta ocupada! intenta otra!!\n\n");
            }
            break;
        }
        case '3':
        {
            i=0;
            j=2;
            if(c[i][j]=='x'||c[i][j]=='O')
            {
                k=1;
                printf("la casilla esta ocupada! intenta otra!!\n\n");
            }
            break;
        }
        case '4':
        {
            i=1;
            j=0;
            if(c[i][j]=='x'||c[i][j]=='O')
            {
                k=1;
                printf("la casilla esta ocupada! intenta otra!!\n\n");
            }
            break;
        }
        case '5':
        {
            i=1;
            j=1;
            if(c[i][j]=='x'||c[i][j]=='O')
            {
                k=1;
                printf("la casilla esta ocupada! intenta otra!!\n\n");
            }
            break;
        }
        case '6':
        {
            i=1;
            j=2;
            if(c[i][j]=='x'||c[i][j]=='O')
            {
                k=1;
                printf("la casilla esta ocupada! intenta otra!!\n\n");
            }
            break;
        }
        case '7':
        {
            i=2;
            j=0;
            if(c[i][j]=='x'||c[i][j]=='O')
            {
                k=1;
                printf("la casilla esta ocupada! intenta otra!!\n\n");
            }
            break;
        }
        case '8':
        {
            i=2;
            j=1;
            if(c[i][j]=='x'||c[i][j]=='O')
            {
                k=1;
                printf("la casilla esta ocupada! intenta otra!!\n\n");
            }
            break;
        }
        case '9':
        {
            i=2;
            j=2;
            if(c[i][j]=='x'||c[i][j]=='O')
            {
                k=1;
                printf("la casilla esta ocupada! intenta otra!!\n\n");
            }
            break;
        }
        }
    }
    while(k==1);
    c[i][j]='x';
}
void intro_tu(char c[3][3])
{
    int i,j,k;
    char aux;
    do
    {
        do
        {
            printf("\n coloca una ficha:");
            fflush(stdin);
            scanf("%c",&aux);
        }
        while(aux<'1'||aux>'9');
        k=0;
        switch(aux)
        {
        case '1':
        {
            i=0;
            j=0;
            if(c[i][j]=='x'||c[i][j]=='O')
            {
                k=1;
                printf("la casilla esta ocupada! intenta otra!!\n\n");
            }
            break;
        }
        case '2':
        {
            i=0;
            j=1;
            if(c[i][j]=='x'||c[i][j]=='O')
            {
                k=1;
                printf("la casilla esta ocupada! intenta otra!!\n\n");
            }
            break;
        }
        case '3':
        {
            i=0;
            j=2;
            if(c[i][j]=='x'||c[i][j]=='O')
            {
                k=1;
                printf("la casilla esta ocupada! intenta otra!!\n\n");
            }
            break;
        }
        case '4':
        {
            i=1;
            j=0;
            if(c[i][j]=='x'||c[i][j]=='O')
            {
                k=1;
                printf("la casilla esta ocupada! intenta otra!!\n\n");
            }
            break;
        }
        case '5':
        {
            i=1;
            j=1;
            if(c[i][j]=='x'||c[i][j]=='O')
            {
                k=1;
                printf("la casilla esta ocupada! intenta otra!!\n\n");
            }
            break;
        }
        case '6':
        {
            i=1;
            j=2;
            if(c[i][j]=='x'||c[i][j]=='O')
            {
                k=1;
                printf("la casilla esta ocupada! intenta otra!!\n\n");
            }
            break;
        }
        case '7':
        {
            i=2;
            j=0;
            if(c[i][j]=='x'||c[i][j]=='O')
            {
                k=1;
                printf("la casilla esta ocupada! intenta otra!!\n\n");
            }
            break;
        }
        case '8':
        {
            i=2;
            j=1;
            if(c[i][j]=='x'||c[i][j]=='O')
            {
                k=1;
                printf("la casilla esta ocupada! intenta otra!!\n\n");
            }
            break;
        }
        case '9':
        {
            i=2;
            j=2;
            if(c[i][j]=='x'||c[i][j]=='O')
            {
                k=1;
                printf("la casilla esta ocupada! intenta otra!!\n\n");
            }
            break;
        }
        }
    }
    while(k==1);
    c[i][j]='O';
}
int ganador(char c[3][3])
{
    if(c[0][0]=='x'||c[0][0]=='O')
    {
        if(c[0][0]==c[0][1]==c[0][2])
        {
            if(c[0][0]=='x')
            {

                return 0;//gano yo
            }
            else
            {
                return 1;//ganaste tu}
            }
        }

        if(c[0][0]==c[1][0]&&c[0][0]==c[2][0])
        {
            if(c[0][0]=='x')
            {

                return 0;//gano yo
            }
            else
            {
                return 1;//ganaste tu
            }
        }
    }
    if(c[1][1]=='x'||c[1][1]=='O')
    {
        if(c[1][1]==c[0][0]&&c[1][1]==c[2][2])
        {
            if(c[1][1]=='x')
            {

                return 0;//gano yo
            }
            else
            {
                return 1;//ganaste tu
            }
        }
        if(c[1][1]==c[1][0]&&c[1][1]==c[1][2])
        {
            if(c[1][1]=='x')
            {

                return 0;//gano yo
            }
            else
            {
                return 1;//ganaste tu
            }
        }
        if(c[1][1]==c[2][0]&&c[1][1]==c[0][2])
        {
            if(c[1][1]=='x')
            {

                return 0;//gano yo
            }
            else
            {
                return 1;//ganaste tu
            }
        }
        if(c[1][1]==c[0][1]&&c[1][1]==c[2][1])
        {
            if(c[1][1]=='x')
            {

                return 0;//gano yo
            }
            else
            {
                return 1;//ganaste tu
            }
        }




    }
    if (c[2][2]=='x'||c[2][2]=='O')
    {
        if(c[2][2]==c[2][0]&&c[2][1]==c[2][1])
        {
            if(c[2][2]=='x')
            {

                return 0;//gano yo
            }
            else
            {
                return 1;//ganaste tu
            }
        }
        if(c[2][2]==c[0][2]&&c[2][2]==c[1][2])
        {
            if(c[2][2]=='x')
            {

                return (0);//gano yo
            }
            else
            {

                return (1);//ganaste tu
            }
        }
    }
    return (2);
}
void puntos(){
        FILE *archivo;
    int letra;
    archivo= fopen("ganadas.txt","a");
    fputc('c',archivo);
    fclose(archivo);
}
void puntos2(){
        FILE *archivo;
    int letra;
    archivo= fopen("ganadas_x.txt","a");
    fputc('c',archivo);
    fclose(archivo);
}
void puntos3(){
        FILE *archivo;
   int contador= 0;
    archivo= fopen("ganadas_O.txt","a");
    fputc('c',archivo);
    fclose(archivo);
}





