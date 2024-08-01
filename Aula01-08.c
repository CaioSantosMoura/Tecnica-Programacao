// 1) Quanto de memória a variável arquivo irá utilizar durante a execução do programa?
    // Variável arquivo: O consumo de memória depende do tipo de dado. Para um ponteiro FILE, geralmente ocupa 8 bytes em sistemas de 64 bits.

// 2) Um ponteiro FILE em linguagem C pode armazenar quantos bytes?
    // Ponteiro FILE: Em sistemas de 64 bits, ocupa 8 bytes. Em sistemas de 32 bits, ocupa 4 bytes.

// 3) Um ponteiro int pode armazenar quantos bytes?
    // Ponteiro int: Em sistemas de 64 bits, ocupa 8 bytes. Em sistemas de 32 bits, ocupa 4 bytes.

// 4) Analise os dois programas a seguir:
// Programa 1:
int main ()
{
   float matrx [50][50];
   int i,j;
   for (i=0;i<50;i++)
       for (j=0;j<50;j++)
           matrx[i][j]=0.0;
   return(0);
}


// Programa 2:
int main ()
{
   float matrx [50][50];
   float *p;
   int count;
   p=matrx[0];
   for (count=0;count<2500;count++) {
       *p=0.0;
       p++;
   }
   return(0);
}

// Quanta memória cada programa ocupa durante a sua execução?
    // Memória dos programas:
        //  Programa 1: Usa 50 × 50 × 4 bytes = 10.000 bytes (4 bytes por float).
        //  Programa 2: Usa a mesma quantidade, 50 × 50 × 4 bytes = 10.000 bytes.
