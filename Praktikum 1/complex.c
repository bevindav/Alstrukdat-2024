#include <stdio.h>
#include "complex.h"

/* ***************************************************************** */
/* DEFINISI PRIMITIF                                                 */
/* ***************************************************************** */

/* KELOMPOK VALIDASI TERHADAP TYPE                                   */
/* ***************************************************************** */
boolean IsCOMPLEXValid(float Re, float Im) {
    /* Bilangan kompleks, seluruh bilangan real dan imajiner valid */
    return true;
}

/* *** Konstruktor: Membentuk sebuah COMPLEX dari komponen-komponennya *** */
void CreateComplex(COMPLEX *C, float Re, float Im) {
    Real(*C) = Re;
    Imag(*C) = Im;
}

/* ***************************************************************** */
/* KELOMPOK BACA/TULIS                                               */
/* ***************************************************************** */
/* Membaca Bilangan Kompleks (re dan im) dari Masukan User */
void BacaCOMPLEX(COMPLEX *C) {
    float Re, Im;
    scanf("%f %f", &Re, &Im);
    CreateComplex(C, Re, Im);
}

/* Menulis Bilangan Kompleks (re dan im) ke layar */
void TulisCOMPLEX(COMPLEX C) {
    if (Imag(C) >= 0) {
        printf("%.2f+%.2fi\n", Real(C), Imag(C));
    } else {
        printf("%.2f-%.2fi\n", Real(C), Imag(C)*(-1));
    }
}

/* ***************************************************************** */
/* KELOMPOK OPERASI ARITMATIKA TERHADAP TYPE                         */
/* ***************************************************************** */

/* Operasi untuk menghitung hasil penjumlahan C1 + C2 */
COMPLEX AddCOMPLEX(COMPLEX C1, COMPLEX C2) {
    COMPLEX jawaban;
    jawaban.Re = Real(C1) + Real(C2);
    jawaban.Im = Imag(C1) + Imag(C2);
    return jawaban;
}

/* Operasi untuk menghitung hasil pengurangan C1 - C2 */
COMPLEX SubtractCOMPLEX(COMPLEX C1, COMPLEX C2) {
    COMPLEX jawaban;
    jawaban.Re = Real(C1) - Real(C2);
    jawaban.Im = Imag(C1) - Imag(C2);
    return jawaban;
}

/* Operasi untuk menghitung hasil perkalian C1 * C2 */
COMPLEX MultiplyCOMPLEX(COMPLEX C1, COMPLEX C2) {
    COMPLEX jawaban;
    jawaban.Re = Real(C1) * Real(C2) - Imag(C1) * Imag(C2);
    jawaban.Im = Real(C1) * Imag(C2) + Imag(C1) * Real(C2);
    return jawaban;
}

/* Operasi untuk menghitung hasil pembagian C1 / C2 */
COMPLEX DivideCOMPLEX(COMPLEX C1, COMPLEX C2) {
    COMPLEX jawaban;
    float denominator = Real(C2) * Real(C2) + Imag(C2) * Imag(C2);
    if (denominator == 0) {
        jawaban.Re = 0;
        jawaban.Im = 0;
    } else {
        // Menggunakan rumus pembagian yang benar
        jawaban.Re = (Real(C1) * Real(C2) + Imag(C1) * Imag(C2)) / denominator;
        jawaban.Im = (Imag(C1) * Real(C2) - Real(C1) * Imag(C2)) / denominator; 
    }
    return jawaban;
}


/* ***************************************************************** */
/* KELOMPOK OPERASI LAIN TERHADAP TYPE                               */
/* ***************************************************************** */

/* Mengembalikan nilai absolut (modulus) dari C */
float AbsCOMPLEX(COMPLEX C) {
    return sqrt(Real(C) * Real(C) + Imag(C) * Imag(C));
}

/* Mengembalikan nilai konjugasi dari C */
COMPLEX ConjugateCOMPLEX(COMPLEX C) {
    COMPLEX jawaban;
    jawaban.Re = Real(C);
    jawaban.Im = -(Imag(C));
    return jawaban;
}

/* *** Kelompok Operator Relational *** */
boolean CEQ(COMPLEX C1, COMPLEX C2) {
    return (Real(C1) == Real(C2)) && (Imag(C1) == Imag(C2));
    /* Mengembalikan true jika C1 = C2 (Re dan Im sama) */
}

boolean CNEQ(COMPLEX C1, COMPLEX C2) {
    return !CEQ(C1, C2);
    /* Mengembalikan true jika C1 tidak sama dengan C2 */
}