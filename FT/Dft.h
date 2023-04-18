#pragma once
#include <windows.h>
#include "ComplexNumber.h"

#define      MAX_VECTOR_SIZE          2048                       // 原始信号最大允许长度
#define      PI                                           3.141592653         // 圆周率π的近似值

class CDft
{
public:
	CDft(void);
	~CDft(void);

public:
	bool dft(double IN const vec[], int IN const len);                // 一维离散傅里叶变换
	bool idft(LPVOID OUT* pVec, int OUT* ilen);                    // 一维离散傅里叶逆变换

	bool has_dft_vector();                                                         // 是否已存有变换结果

	void clear_dft_vector();                                                       // 清除已有的变换结果
	void print();                                                                           // 打印变换结果

public:
	CComplexNumber* m_dft_vector;                                     // 保存变换结果的容器

private:
	bool      m_has_dft_vector;
	int         m_dft_vector_size;                                                 // 变换结果的长度
};