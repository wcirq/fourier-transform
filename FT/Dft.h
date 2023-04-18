#pragma once
#include <windows.h>
#include "ComplexNumber.h"

#define      MAX_VECTOR_SIZE          2048                       // ԭʼ�ź����������
#define      PI                                           3.141592653         // Բ���ʦеĽ���ֵ

class CDft
{
public:
	CDft(void);
	~CDft(void);

public:
	bool dft(double IN const vec[], int IN const len);                // һά��ɢ����Ҷ�任
	bool idft(LPVOID OUT* pVec, int OUT* ilen);                    // һά��ɢ����Ҷ��任

	bool has_dft_vector();                                                         // �Ƿ��Ѵ��б任���

	void clear_dft_vector();                                                       // ������еı任���
	void print();                                                                           // ��ӡ�任���

public:
	CComplexNumber* m_dft_vector;                                     // ����任���������

private:
	bool      m_has_dft_vector;
	int         m_dft_vector_size;                                                 // �任����ĳ���
};