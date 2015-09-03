#include "Class1_com.hpp"


CClass1::CClass1()
{
  g_pModule->InitializeComponentInstanceEx(&m_hinst);
}
CClass1::~CClass1()
{
  if (m_hinst)
    g_pModule->TerminateInstance(&m_hinst);
}

HRESULT __stdcall CClass1::loadForecast(/*[in]*/long nargout, /*[in,out]*/VARIANT* y, 
                                        /*[in]*/VARIANT date, /*[in]*/VARIANT hour, 
                                        /*[in]*/VARIANT temperature, /*[in]*/VARIANT 
                                        isWorkingDay, /*[in]*/VARIANT histDate, 
                                        /*[in]*/VARIANT histHour, /*[in]*/VARIANT 
                                        histLoad) {
  return( CallComFcn( "loadForecast", (int) nargout, 1, 7, y, &date, &hour, &temperature, 
                      &isWorkingDay, &histDate, &histHour, &histLoad ) );
}

