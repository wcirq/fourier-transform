#include "ComplexNumber.h"

CComplexNumber::CComplexNumber(void)
{
	m_rl = 0;
	m_im = 0;
}

CComplexNumber::CComplexNumber(double rl, double im)
{
	m_rl = rl;
	m_im = im;
}

CComplexNumber::~CComplexNumber(void)
{
}

void CComplexNumber::SetValue(double rl, double im) {
	m_rl = rl;
	m_im = im;
}