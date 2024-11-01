#include <stdio.h>
#include "point.h"
#include <math.h>

/*Membentuk Point*/
void CreatePoint (POINT * P, float X, float Y){
    Absis(*P) = X;
    Ordinat(*P) = Y;
}


/*Membaca nilai absis dan ordinat*/
void BacaPOINT (POINT * P){
    float X, Y;
    scanf("%f %f", &X, &Y);
    CreatePoint(P, X, Y);
}

/*Mencetak point*/
void TulisPOINT (POINT P){
    printf("(%.2f,%.2f)", Absis(P), Ordinat(P));
}

/*Mengembalikan nilai true jika absis dan ordinatnya sama*/
boolean EQ (POINT P1, POINT P2){
        return (Absis(P1)==Absis(P2)) && (Ordinat(P1)==Ordinat(P2));
}

/*Mengembalikan nilai true jika antara point 1 dan point 2 tidak sama*/
boolean NEQ (POINT P1, POINT P2){
    return !EQ(P1,P2);
}

/*Mengembalikan nilai true jika P titik origin*/
boolean IsOrigin (POINT P){
    return (Absis(P) == (float)0) && (Ordinat(P) == (float)0);
}

/*Mengembalikan nilai true jika P terletak pada sumbu X*/
boolean IsOnSbX (POINT P){
    return (Ordinat(P) == (float)0);
}

/*Mengembalikan nilai true jika P terletak pada sumbu Y*/
boolean IsOnSbY (POINT P){
    return (Absis (P) == 0);
}
/*Menentukan kuadran dari point*/
int Kuadran (POINT P){
    if (Absis(P) > 0 && Ordinat(P) > 0) {
        return 1;
    } else if (Absis(P) < 0 && Ordinat(P) > 0) {
        return 2;
    } else if (Absis(P) < 0 && Ordinat(P) < 0) {
        return 3;
    } else {
        return 4;
    }
}

/* *** KELOMPOK OPERASI LAIN TERHADAP TYPE *** */                           
POINT NextX (POINT P){
    Absis(P) = Absis(P) + 1;
    return P;
}
POINT NextY (POINT P){
    Ordinat(P) = Ordinat(P) + 1;
    return P;
}
POINT PlusDelta (POINT P, float deltaX, float deltaY){
    Absis(P) = Absis(P) + deltaX;
    Ordinat(P) = Ordinat(P) + deltaY;
    return P;
}
POINT MirrorOf (POINT P, boolean SbX){
    if (SbX) {
        Ordinat(P) = (-1) * Ordinat(P);
    } else {
        Absis(P) = (-1) * Absis(P);
    }
    return P;
}
float Jarak0 (POINT P){
    return sqrt(Absis(P) * Absis(P) + Ordinat(P) * Ordinat(P));
}


float Panjang (POINT P1, POINT P2){
    return sqrt((Absis(P1) - Absis(P2)) * (Absis(P1) - Absis(P2)) + (Ordinat(P1) - Ordinat(P2)) * (Ordinat(P1) - Ordinat(P2)));
}

void Geser (POINT *P, float deltaX, float deltaY){
    Absis(*P) = Absis(*P) + deltaX;
    Ordinat(*P) = Ordinat(*P) + deltaY;
}
void GeserKeSbX (POINT *P){
    Ordinat(*P) = 0;
}
void GeserKeSbY (POINT *P){
    Absis(*P) = 0;
}
void Mirror (POINT *P, boolean SbX){
    if (SbX) {
        Ordinat(*P) = (-1) * Ordinat(*P);
    } else {
        Absis(*P) = (-1) * Absis(*P);
    }
}
void Putar (POINT *P, float Sudut){
    float X, Y;
    X = Absis(*P);
    Y = Ordinat(*P);
    Sudut = Sudut * 3.141592 / 180;
    Absis(*P) = X * cos(Sudut) + Y * sin(Sudut);
    Ordinat(*P) = -1 * X * sin(Sudut) + Y * cos(Sudut);
}

void PersamaanLinearDuaVariabel (POINT P1, POINT P2){
    int a, b;
    if(Absis(P1) == Absis(P2)){
        a = 0;
    }
    else {
        a = Ordinat(P2) - Ordinat (P1) / (Absis(P2) - Absis(P1));
    }
    b = Ordinat(P1) - a*Absis(P1); 
    printf ("%d %d", a, b);
}
