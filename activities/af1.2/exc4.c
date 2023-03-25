#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void tryA(int ROW, int COL) {
    int data[ROW][COL];
    for (int i = 0; i < ROW; i++) {
        for (int j = i; j >= 0; j--) {
            data[j][i] = rand() % 100 + 1;
            printf("|%d|", data[j][i]);
        }
        printf("\n");
    }
}

void tryB(int ROW, int COL) {
    int data[ROW][COL];
    for (int i = 0; i <= ROW; i++) {
        for (int j = i; j <= COL; j++) {
            data[i][j] = rand() % 100 + 1;
            printf("|%d|", data[j][i]);
        }
        printf("\n");
    }
}

void tryC(int ROW, int COL) {
    int data[ROW][COL];
    for (int i = 0; i < ROW; i++) {
        for (int j = i; j < COL; j++) {
            data[i][j] = rand() % 100 + 1;
            printf("|%d|", data[j][i]);
        }
        printf("\n");
    }
}

void tryD(int ROW, int COL) {
    int data[ROW][COL];
    for (int i = 0; i < COL; i++) {
        for (int j = i; j < ROW; j++) {
            data[i][j] = rand() % 100 + 1;
            printf("|%d|", data[j][i]);
        }
        printf("\n");
    }
}

void tryE(int ROW, int COL) {
    int data[ROW][COL];
    for (int i = 0; i < ROW; i++) {
        for (int j = i; j >= 0; j--) {
            data[i][j] = rand() % 100 + 1;
            printf("|%d|", data[j][i]);
        }
    printf("\n");
    }
}

void tryF(int ROW, int COL) {
    int data[ROW][COL];
    for (int i = 0; i < ROW; i++) {
        for (int j = i; j < COL; j++) {
            data[j][i] = rand() % 100 + 1;
            printf("|%d|", data[j][i]);
        }
    printf("\n");
    }
}


int main(void) {
    int ROW = 5;
    int COL = 5;
    tryA(ROW, COL);
    printf("\n");
    tryB(ROW, COL);
    printf("\n");
    tryC(ROW, COL);
    printf("\n");
    tryD(ROW, COL);
    printf("\n");
    tryE(ROW, COL);
    printf("\n");
    tryF(ROW, COL);
    printf("\n");
    return 0;
}

