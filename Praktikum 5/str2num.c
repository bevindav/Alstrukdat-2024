#include <stdio.h>
#include <string.h>
#include "mesinkata.h"

boolean bandingkanKata(Word kata, char teks[]) {
    if (kata.Length != strlen(teks)) {
        return false;
    }
    for (int indeks = 0; indeks < kata.Length; indeks++) {
        if (kata.TabWord[indeks] != teks[indeks]) {
            return false;
        }
    }
    return true;
}

boolean cekAkhirPoin(Word kata) {
    return (kata.TabWord[kata.Length - 1] == '.');
}

int main(void) {
    STARTWORD();

    int valueAngkanya = 0;
    boolean counting = false;
    Word kataNow;

    while (!EndWord) {
        strcpy(kataNow.TabWord, currentWord.TabWord);
        kataNow.Length = currentWord.Length;
        if (cekAkhirPoin(kataNow)) {
            kataNow.Length--;
        }
        if (bandingkanKata(kataNow, "nol")) {
            counting = true;
        } else if (bandingkanKata(kataNow, "satu")) {
            counting = true;
            valueAngkanya += 1;
        } else if (bandingkanKata(kataNow, "dua")) {
            counting = true;
            valueAngkanya += 2;
        } else if (bandingkanKata(kataNow, "tiga")) {
            counting = true;
            valueAngkanya += 3;
        } else if (bandingkanKata(kataNow, "empat")) {
            counting = true;
            valueAngkanya += 4;
        } else if (bandingkanKata(kataNow, "lima")) {
            counting = true;
            valueAngkanya += 5;
        } else if (bandingkanKata(kataNow, "enam")) {
            counting = true;
            valueAngkanya += 6;
        } else if (bandingkanKata(kataNow, "tujuh")) {
            counting = true;
            valueAngkanya += 7;
        } else if (bandingkanKata(kataNow, "delapan")) {
            counting = true;
            valueAngkanya += 8;
        } else if (bandingkanKata(kataNow, "sembilan")) {
            counting = true;
            valueAngkanya += 9;
        } else if (bandingkanKata(kataNow, "sepuluh") || bandingkanKata(kataNow, "belas")) {
            counting = true;
            valueAngkanya += 10;
        } else if (bandingkanKata(kataNow, "sebelas")) {
            counting = true;
            valueAngkanya += 11;
        } else if (bandingkanKata(kataNow, "puluh")) {
            counting = true;
            valueAngkanya += 10 * (valueAngkanya % 10) - (valueAngkanya % 10);
        } else if (bandingkanKata(kataNow, "seratus")) {
            counting = true;
            valueAngkanya += 100;
        } else if (bandingkanKata(kataNow, "ratus")) {
            counting = true;
            valueAngkanya += 100 * (valueAngkanya % 100) - (valueAngkanya % 100);
        } else {
            if (counting) {
                printf("%d ", valueAngkanya);
                valueAngkanya = 0;
                counting = false;
            }
        }

        ADVWORD();
        if (!counting) {
            int panjangKata = kataNow.Length;
            for (int i = 0; i < panjangKata; i++) {
                printf("%c", kataNow.TabWord[i]);
            }
            if (!EndWord) {
                printf(" ");
            }
        }
    }
    if (counting) {
        printf("%d", valueAngkanya);
    }
    
    printf("\n");
    return 0;
}

//strequal
// // Prints word from Mesin Kata
// int printWord(Word word) {

//    int i;

//    for (i = 0; i < word.Length; i++) {

//       printf("%c", word.TabWord[i]);

//    }

// }

// int main(){
//     Word w1,w2;
//     int i;
//     STARTWORD();
//     w1 = currentWord;
//     ADVWORD();
//     w2 = currentWord;
//     printf("Moving "); 
//     printWord(w1);
//     if (w2.TabWord[4] == 'U'){
//         printf(" square upwards\n");
//     } else if (w2.TabWord[4] == 'D'){
//         printf(" square downwards\n");
        
//     } else if (w2.TabWord[4] == 'L'){
//         printf(" square leftwards\n");
    
//     } else if (w2.TabWord[4] == 'R'){
//         printf(" square rightwards\n");

//     }
    
    
    

//     return 0;
// }
//anagram
// boolean cekAnagram(Word w1, Word w2){
//     int i,j;
//     boolean isAnagram = false, tempword;
//     for (i = 0; i<w1.Length; i++){
//         tempword = false;
//         for (j=0; j<w2.Length; j++){
//             if (w1.TabWord[i] == w2.TabWord[j]){
//                 tempword = true;
//                 w2.TabWord[j] = MARK;
//             }
//         }
//         if (!tempword) return false;
//     }
//     return true;
// }

// int main(){
//     Word arrWord[100];
//     int countWord = 0, countAnagram = 0, i, j;
//     boolean isAnagram;
//     STARTWORD();
//     while (!EndWord) {
//         arrWord[countWord] = currentWord;
//         countWord++;
//         ADVWORD();
//     }
//     for (i = 0; i<countWord-1; i++){
//         for (j=i+1; j<countWord; j++){
//             isAnagram = false;
//             if (i != j){
//                 if (arrWord[i].Length == arrWord[j].Length){
//                     isAnagram = cekAnagram(arrWord[i], arrWord[j]);
//                 }
//             }
//             if (isAnagram) countAnagram++;
//         }
//     }
//     printf("%d\n", countAnagram);
//     return 0;
// }
//palindrome
// boolean cekPalindrome(Word w){
//     int i;
//     for (i = 0; i<w.Length/2; i++){
//         if (w.TabWord[i] != w.TabWord[w.Length-1-i]){
//             return false;
//         }
//     }
//     return true;
// }
// int main(){
//     Word arrWord[100];
//     int countWord = 0, countPalindrome = 0, i;
//     boolean isPalindrome;
//     STARTWORD();
//     while (!EndWord) {
//         arrWord[countWord] = currentWord;
//         countWord++;
//         ADVWORD();
//     }
//     for (i = 0; i<countWord; i++){
//         isPalindrome = cekPalindrome(arrWord[i]);
//         if (isPalindrome) countPalindrome++;
//     }
//     printf("%d\n", countPalindrome);
//     return 0;
// }
//vokal
// boolean cekVokal(char c){
//     return (c == 'a' || c == 'i' || c == 'u' || c == 'e' || c == 'o');
// }
// int main(){
//     Word w;
//     int countVokal = 0, i;
//     STARTWORD();
//     w = currentWord;
//     for (i = 0; i<w.Length; i++){
//         if (cekVokal(w.TabWord[i])){
//             countVokal++;
//         }
//     }
//     printf("%d\n", countVokal);
//     return 0;
// }
// int compareWord(Word word1, Word word2) {
//     int i = 0;
//     while (i < word1.Length && i < word2.Length) {
//         if (word1.TabWord[i] < word2.TabWord[i]) {
//             return -1;
//         } else if (word1.TabWord[i] > word2.TabWord[i]) {
//             return 1;
//         }
//         i++;
//     }

//     if (word1.Length < word2.Length) {
//         return -1;
//     } else if (word1.Length > word2.Length) {
//         return 1;
//     }

//     return 0;
// }

// void sortWords(char words[][NMax + 1], int n) {
//     int i, j;
//     char temp[NMax + 1];

//     for (i = 0; i < n - 1; i++) {
//         for (j = i + 1; j < n; j++) {
//             Word word1, word2;

//             int k = 0;
//             while (words[i][k] != '\0') {
//                 word1.TabWord[k] = words[i][k];
//                 k++;
//             }
//             word1.Length = k;

//             k = 0;
//             while (words[j][k] != '\0') {
//                 word2.TabWord[k] = words[j][k];
//                 k++;
//             }
//             word2.Length = k;

//             int compareResult = compareWord(word1, word2);

//             if (compareResult > 0) {
//                 int l = 0;
//                 while (words[i][l] != '\0') {
//                     temp[l] = words[i][l];
//                     l++;
//                 }
//                 temp[l] = '\0';

//                 l = 0;
//                 while (words[j][l] != '\0') {
//                     words[i][l] = words[j][l];
//                     l++;
//                 }
//                 words[i][l] = '\0';

//                 l = 0;
//                 while (temp[l] != '\0') {
//                     words[j][l] = temp[l];
//                     l++;
//                 }
//                 words[j][l] = '\0';
//             }
//         }
//     }
// }

// int main() {
//     STARTWORD();

//     char words[100][NMax + 1];

//     int n = 0;

//     while (!EndWord) {
//         int i = 0;
//         while (i < currentWord.Length) {
//             words[n][i] = currentWord.TabWord[i];
//             i++;
//         }
//         words[n][i] = '\0';
//         n++;

//         ADVWORD();
//     }

//     sortWords(words, n);

//     for (int i = 0; i < n; i++) {
//         printf("%s\n", words[i]);
//     }

//     return 0;
// }