#ifdef FUNCIONES_H
void cronometro(int s, int m, int h);
void Coordenada(char vectormina[][8], char vectormuerte[][8], int *clicki, int *clickj, int posicion, int *acum);
void Bandera(char vectormuerte[][8], char vectormina[][8], int *clicki, int *clickj,  int *acum);
void Pregunta(char *condicion);
void Mostrar(char vectormina[][8]);
void Random(char vectormuerte[][8], char *nivel, int i, int j);
void Inicializar(char vectormina[][8], char vectormuerte[][8]);
void Eleccion(char *nivel);
void Bienvenida();
void loop(char c[3][3]);
void intro_primera(char c[3][3]);
void tablero(char c[3][3]);
void intro_yo(char c[3][3]);
void intro_tu(char c[3][3]);
int ganador(char c[3][3]);
#endif // FUNCIONES_H
