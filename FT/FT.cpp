#include <iostream>
#include "Dft.h"


double* generateSignal(int* fres, int fresNum, int &len)
{
    int total_time = 1;  // 秒
    int sr = 100;  // 采样率
    int amp = 10; // 振幅
    int phase = 0; // 相位
    double stop = total_time * 2 * PI; 
    int size = total_time * sr;
    double *ys = new double[size];
    for (size_t i = 0; i < size; i++)
    {
        ys[i] = 0;
        double x = stop * i / size;
        for (size_t j = 0; j < fresNum; j++)
        {
            double temp = amp * sin(fres[j] * x + phase);
            ys[i] += temp;
        }
    }
    len = size;
    return ys;
}


int main()
{
    double signal[] = { 15, 32, 9, 222, 18, 151, 5, 7, 56, 233, 56, 121, 235, 89, 98, 111 };
    int len = sizeof(signal) / sizeof(double);

    /*int len = -1;
    int fres[] = {2, 8};
    int fresNum = sizeof(fres) / sizeof(int);
    double* signal = generateSignal(fres, fresNum, len);*/

    /*double* signal = new double[100];
    for (size_t i = 0; i < 100; i++)
    {
        signal[i] = 0;
    }
    signal[2] = -5;
    signal[8] = -5;
    signal[92] = 5;
    signal[98] = 5;
    int len = 100;*/
    
    //print 原始信号
    printf("原始信号: \n");
    for (int i = 0; i < len; i++)
    {
        printf("\t%d: %f\n", i, signal[i]);
    }
    
    // 对一维信号进行傅里叶变换，并打印变换结果
    CDft dft;
    dft.dft(signal, len);

    printf("傅里叶变换的结果为：\n");
    dft.print();

    // 进行傅里叶逆变换
    LPVOID pVec = NULL;
    int ilen = 0;
    dft.idft(&pVec, &ilen);

    // 打印逆变换的结果，以便和原始信号作对比
    printf("\n");
    char msg[256] = "      ";
    CComplexNumber* vec = (CComplexNumber*)pVec;
    if ((ilen > 0) && (NULL != vec)) {
        printf("傅里叶逆变换的结果为：\n");
        for (int x = 0; x < ilen; x++) {
            sprintf(msg + 6, "idft %d: %lf + %1fi\n", x + 1, vec[x].m_rl, vec[x].m_im);
            printf(msg);
        }
        delete[] vec;
    }

    return 0;
}