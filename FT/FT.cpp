#include <iostream>
#include "Dft.h"

int main()
{
    char msg[256] = "11111 ";
    double signal[] = { 15, 32, 9, 222, 18, 151, 5, 7, 56, 233, 56, 121, 235, 89, 98, 111 };
    int len = sizeof(signal) / sizeof(double);

    // 对一维信号进行傅里叶变换，并打印变换结果
    CDft dft;
    dft.dft(signal, len);

    printf("傅里叶变换的结果为：");
    dft.print();

    // 进行傅里叶逆变换
    LPVOID pVec = NULL;
    int ilen = 0;
    dft.idft(&pVec, &ilen);

    // 打印逆变换的结果，以便和原始信号作对比
    printf("\n");
    double* vec = (double*)pVec;
    if ((ilen > 0) && (NULL != vec)) {
        printf("傅里叶逆变换的结果为：");
        for (int x = 0; x < ilen; x++) {
            sprintf(msg + 6, "idft %d: %lf", x + 1, vec[x]);
            printf(msg);
        }
        delete[] vec;
    }

    return 0;
}