#ifndef _Forecaster_Class1_com_HPP
#define _Forecaster_Class1_com_HPP 1

#include <windows.h>
#include "Forecaster_idl.h"
#include "mclmcrrt.h"
#include "mclcom.h"
#include "mclxlmain.h"
#include "mclcomclass.h"

class CClass1 : public CMCLClassImpl<IClass1, &IID_IClass1, CClass1, &CLSID_Class1>
{
public:
  CClass1();
  ~CClass1();

  HRESULT __stdcall loadForecast(/*[in]*/long nargout, /*[in,out]*/VARIANT* y, 
                                 /*[in]*/VARIANT date, /*[in]*/VARIANT hour, 
                                 /*[in]*/VARIANT temperature, /*[in]*/VARIANT 
                                 isWorkingDay, /*[in]*/VARIANT histDate, /*[in]*/VARIANT 
                                 histHour, /*[in]*/VARIANT histLoad); 

};
#endif
