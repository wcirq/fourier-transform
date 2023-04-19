#pragma once
#include <iostream>

class CComplexNumber
{
public:
    CComplexNumber(double rl, double im);
    CComplexNumber(void);
    ~CComplexNumber(void);

public:
    // 重载四则运算符号
    inline CComplexNumber operator +(const CComplexNumber& c) {
        return CComplexNumber(m_rl + c.m_rl, m_im + c.m_im);
    }
    inline CComplexNumber operator -(const CComplexNumber& c) {
        return CComplexNumber(m_rl - c.m_rl, m_im - c.m_im);
    }
    inline CComplexNumber operator *(const CComplexNumber& c) {
        return CComplexNumber(m_rl * c.m_rl - m_im * c.m_im, m_im * c.m_rl + m_rl * c.m_im);
    }

    inline CComplexNumber operator /(const CComplexNumber& c) {
        if ((0 == c.m_rl) && (0 == c.m_im)) {
            printf("11111 ComplexNumber    ERROR: divider is 0!");
            return CComplexNumber(m_rl, m_im);
        }
        return CComplexNumber((m_rl * c.m_rl + m_im * c.m_im) / (c.m_rl * c.m_rl + c.m_im * c.m_im),
            (m_im * c.m_rl - m_rl * c.m_im) / (c.m_rl * c.m_rl + c.m_im * c.m_im));
    }

    template<typename T>
    inline CComplexNumber operator *(const T& i) {
        return CComplexNumber(m_rl * i, m_im * i);
    }

    template<typename T>
    inline CComplexNumber operator /(const T& i) {
        return CComplexNumber(m_rl / i, m_im / i);
    }

    template<typename T>
    inline CComplexNumber& operator /=(const T& i) {
        m_rl /= i;
        m_im /= i;
        return *this;
    }

    template<typename T>
    inline T abs() {
        return sqrt(pow(m_rl, 2) + pow(m_im, 2));
    }

    void   SetValue(double rl, double im);

public:
    double     m_rl;    // 实部, real part
    double     m_im;    // 虚部, imagery part
};