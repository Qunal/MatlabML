#ifndef _fault_detect_Class1_com_HPP
#define _fault_detect_Class1_com_HPP 1

#include <windows.h>
#include "fault_detect_idl.h"
#include "mclmcrrt.h"
#include "mclcom.h"
#include "mclxlmain.h"
#include "mclcomclass.h"

class CClass1 : public CMCLClassImpl<IClass1, &IID_IClass1, CClass1, &CLSID_Class1>
{
public:
  CClass1();
  ~CClass1();
  HRESULT __stdcall get_help(/*[in]*/ BSTR funcname, /*[out, retval*/ BSTR* text);

  HRESULT __stdcall steelfault(/*[in]*/long nargout, /*[in,out]*/VARIANT* out, 
                               /*[in]*/VARIANT in); 
private:
  static std::map<std::string, const wchar_t*> help_map;
  static std::map<std::string, const wchar_t*> createHelpMap();
  static const wchar_t * steelfault_help;
};
#endif
