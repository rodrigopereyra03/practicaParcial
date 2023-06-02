#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int elegirTamanio();
void cargarVectorAleatorio(int v[], int tam);
void mostrarVector(int v[], int tam);
int posMin(int v[], int tam);
int posMax(int v[], int tam);
int minVector(int v[], int tam);
int maxVector(int v[], int tam);
float promVector(int v[], int tam);
void sumaVectores(int v[], int w[], int resultado[], int tam);
void restaVectores(int v[], int w[], int resultado[], int tam);
int aleatorioEntre(int mini, int maxi);
void cargarVectorConAleatorios(int v[], int tam, int mini,int maxi);


int main(){

    srand(time(0));

    int tam = elegirTamanio();
    int v[tam];
    cargarVectorAleatorio(v,tam);

    mostrarVector(v, tam);

    posMin(v,tam);

    posMax(v,tam);

    minVector(v,tam);

    maxVector(v,tam);

    promVector(v,tam);

    int w[tam];
    int resultado[tam];
    sumaVectores(v,w,resultado,tam);
    mostrarVector(resultado,tam);

    restaVectores(v,w,resultado,tam);
    mostrarVector(resultado,tam);

    aleatorioEntre(10,99);

    cargarVectorConAleatorios(v,tam,10,99);
    mostrarVector(v,tam);


    return 0;
}

int elegirTamanio(){
    int tamanio;

    printf("ingrese el tamanio: ");
    scanf("%d", &tamanio);

    while (tamanio<0 || tamanio>170){
        printf("ingrese otro tamanio: \n");
        scanf("%d",&tamanio);
    }
    return tamanio;
};

void cargarVectorAleatorio(int v[], int tam){
    for (int i=0; i<tam; i++){
        v[i]= -70 + rand() %(101);
    }

};

void mostrarVector(int v[], int tam){
    for(int i=0; i<tam; i++){
        printf(" |%d| ", v[i]);
    }
};

int posMin(int v[], int tam){
    int posm=0;

    for(int i=0; i<tam; i++){
        if(v[i]<v[posm]){
        posm=i;
        }
    }
    printf("\n\n La posicion del menor es: %d \n",posm);
    return posm;
};

int posMax(int v[], int tam){
    int posM=0;

    for(int i=1; i<tam; i++){
        if(v[i]>v[posM]){
            posM=i;
        }
    }
    printf("\n La posicion del mayor es: %d \n", posM);
    return posM;
};

int minVector(int v[], int tam){
    int aux=v[0];

    for(int i=0; i<tam; i++){
        if(v[i]<aux){
            aux=v[i];
        }
    }

    printf("\n El valor minimo es: %d \n",aux);
    return aux;

};

int maxVector(int v[], int tam){
    int aux2=v[0];

    for(int j=0; j<tam; j++){
        if(v[j]>aux2){
            aux2=v[j];
        }
    }
    printf("\n El valor maximo es: %d \n",aux2);
    return aux2;

};

float promVector(int v[], int tam){
    float prom=0;

    for(int i=0; i<tam; i++){
        prom=prom+v[i];
    }

    prom=prom/tam;
    printf("\n El promedio del vector es: %.2f\n\n", prom);
    return prom;
};

void sumaVectores(int v[], int w[], int resultado[], int tam){
    ///cargar w
    for(int i=0; i<tam; i++){
        w[i]= -70+ rand()%(100);
    }
    ///mostrar w
    for(int i=0; i<tam; i++){
        printf(" |%d| ", w[i]);
    }

    /// sumar v y w
    printf("\n\n La suma es: ");
    for(int i=0; i<tam; i++){
        resultado[i]=0;
        for(int j=0; j<tam; j++){
        resultado[i]=v[i]+w[i];
        }
    }
};

void restaVectores(int v[], int w[], int resultado[], int tam){
    printf("\n\n La resta es: ");
    for(int i=0; i<tam; i++){
        resultado[i]=0;
        for(int j=0; j<tam; j++){
        resultado[i]=v[i]-w[i];
        }
    }
};

int aleatorioEntre(int mini, int maxi){
    int ale;

    ale= mini + rand() % (maxi);
    printf("\n\n El numero aleatorio entre min y max es: %d\n\n", ale);
    return ale;
};

void cargarVectorConAleatorios(int v[], int tam, int mini,int maxi){
        for(int i=0; i<tam; i++){
            v[i]= mini+ rand() %maxi;
        }

        for(int i=0; i<tam; i++){
            printf(" |%d| ", v[i]);
        }


};

int numeroExiste(int v[], int t, int numero) {
    for (int i = 0; i < t; i++) {
        if (v[i] == numero) {
            return 1;
        }
    }
    return 0;
}

void cargarVecorConAleSinRepetir(int v[], int t, int min, int max){

    printf("\n");
    for (int i = 0; i < t; i++) {
        int numero;
        do {
            numero = min + rand()%(max-min+1);
        } while (numeroExiste(v, i, numero));

        v[i] = numero;
    }


};
