#include <stdio.h>
#include <math.h>
#include "matrix.h"
// #include "matrix.c"

int main(){
    int i, j, N, count = 0;
    Matrix m, temp;
    scanf("%d", &N);
    createMatrix(N, N, &temp);
    createMatrix(N, N, &m);
    readMatrix(&m, N, N);
    for(i=0; i<ROW_EFF(m); i++){
        for(j=0; j<COL_EFF(m); j++){
            if (ELMT(m,i,j) != 0){
                int i_temp, j_temp, count_temp=0;
                for(i_temp = 0; i_temp <ROW_EFF(temp); i_temp++){
                    if(i_temp==i){
                        continue;
                    }else{
                        count_temp = count_temp + ELMT(m, i_temp, j);
                        count_temp = count_temp%(1000000007);
                    }
                }
                for(j_temp = 0; j_temp <COL_EFF(temp); j_temp++){
                    if(j_temp==j){
                        continue;
                    }else{
                        count_temp = count_temp + ELMT(m, i, j_temp);
                        count_temp = count_temp%(1000000007);
                    }
                ELMT(temp, i, j) = count_temp%(1000000007);
                }
            }
        }
    }


    for(i=0; i<ROW_EFF(m); i++){
        for(j=0; j<COL_EFF(m); j++){
            count += ELMT(temp, i, j);
            count = count%(1000000007);
        }
    }
    printf("%d\n", count%(1000000007));
    return 0;
}

// baris sama
// kolom sama

// 0, 0
// 0, 1
// 1, 0


// 0,0
// 0,1 0,2 row eff = col eff = N yudhlah
// 1,0 2,0

// 0,2
// 0,1 0,2
// 1,2 2,2