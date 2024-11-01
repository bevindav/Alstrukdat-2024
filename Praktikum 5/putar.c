#include <stdio.h>
#include <string.h>
#include "mesinkarakter.h"
#include "mesinkata.h"
// #include "mesinkata.c"
// #include "mesinkarakter.c"

void diputar(){
    int count;
    for(count = currentWord.Length-1; count >= 0; count--){
        printf("%c", currentWord.TabWord[count]);
    }
}

void biasa(){
    int count;
    for(count = 0; count < currentWord.Length; count++){
        printf("%c", currentWord.TabWord[count]);
    }
}

char word[100];
int i;
void newWord(int i){
    int count;
    for(count = 0; count<currentWord.Length; count++){
        word[i] =currentWord.TabWord[count];
        i++;
    }

}

// int main(void) {
//     STARTWORD();
//     Word w1;

//     while (!EndWord) {
//         strcpy(w1.TabWord, currentWord.TabWord);
//         w1.Length = currentWord.Length;
//         if (cekAkhirPoin(w1)) {
//             w1.Length--;
//         }
//         int panjangKata = w1.Length;
//         for (int i = 0; i < panjangKata; i++) {
//             printf("%c", w1.TabWord[i]);
//         }
//         if (!EndWord) {
//             printf(" ");
//         }
//         ADVWORD();
//     }
//     printf("\n");
//     return 0;
// }

int main(){
    STARTWORD();
    //kasus huruf pertama harus diatasi karna ganjil, tapi jika tidak diatasi tidak bisa dibalik
    int kasus_huruf_pertama = 1; 
    while(!EndWord){
        if (kasus_huruf_pertama)
            kasus_huruf_pertama = 0;
        else
            printf(" ");
            i++;
        newWord(i);
        if(i%2 == 1){
            diputar();
        }else{
            biasa();
        }
        ADVWORD();
    }
    printf("\n");
}