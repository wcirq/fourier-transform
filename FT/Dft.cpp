#include "Dft.h"


CDft::CDft(void)
{
    m_dft_vector = NULL;
    m_has_dft_vector = false;
    m_dft_vector_size = 0;
}

CDft::~CDft(void)
{
    if (m_has_dft_vector && (NULL != m_dft_vector) && (m_dft_vector_size > 0))
        delete[] m_dft_vector;
}


bool CDft::has_dft_vector()
{
    return m_has_dft_vector;
}


void CDft::clear_dft_vector()
{
    if (m_has_dft_vector && (NULL != m_dft_vector) && (m_dft_vector_size > 0)) {
        delete[] m_dft_vector;
        m_has_dft_vector = false;
        m_dft_vector_size = 0;
    }
}

void CDft::print()
{
    char msg[256] = "      ";

    if ((!m_has_dft_vector) || (NULL == m_dft_vector) || (m_dft_vector_size <= 0))
        return;

    for (int i = 0; i < m_dft_vector_size; i++) {
        sprintf(msg + 6, "%d: %lf + %lfi\n", i + 1, m_dft_vector[i].m_rl, m_dft_vector[i].m_im);
        printf(msg);
    }
}


bool CDft::dft(double IN const vec[], int IN const len)
{
    if ((len <= 0) || (NULL == vec))
        return false;

    clear_dft_vector();

    m_dft_vector = new CComplexNumber[len];
    for (int u = 0; u < len; u++) {
        m_dft_vector[u].SetValue(0, 0);
    }
    CComplexNumber   cplTemp(0, 0);
    double fixed_factor = (-2 * PI) / len;
    // 这是最关键的两个嵌套for循环，是离散傅里叶变换公式的代码实现，其中的运算操作和公式定义是完全一致的
    for (int u = 0; u < len; u++) {
        for (int x = 0; x < len; x++) {
            double power = u * x * fixed_factor;
            cplTemp.m_rl = vec[x] * cos(power);
            cplTemp.m_im = vec[x] * sin(power);
            m_dft_vector[u] = m_dft_vector[u] + cplTemp;
        }
    }

    m_has_dft_vector = true;
    m_dft_vector_size = len;
    return true;
}


bool CDft::idft(LPVOID OUT* pVec, int OUT* ilen)
{
    if ((!m_has_dft_vector) || (NULL == m_dft_vector) || (m_dft_vector_size <= 0))
        return false;

    if (*pVec)
        delete[] * pVec;
    *pVec = (LPVOID)new CComplexNumber[m_dft_vector_size];

    CComplexNumber   cplTemp(0, 0);
    CComplexNumber   cplResult(0, 0);
    double fixed_factor = (2 * PI) / m_dft_vector_size;
    // 这是最关键的两个嵌套for循环，是离散傅里叶逆变换公式的代码实现，其中的运算操作和公式定义是完全一致的
    for (int x = 0; x < m_dft_vector_size; x++) {
        for (int u = 0; u < m_dft_vector_size; u++) {
            double power = u * x * fixed_factor;
            cplTemp.SetValue(cos(power), sin(power));
            cplResult = cplResult + m_dft_vector[u] * cplTemp;
        }
        ((CComplexNumber*)*pVec)[x] = cplResult / m_dft_vector_size;
        cplResult.SetValue(0, 0);
    }

    *ilen = m_dft_vector_size;
    return true;
}
