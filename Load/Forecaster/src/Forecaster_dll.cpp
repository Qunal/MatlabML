#include "mwcomtypes.h"
#include "mclmcrrt.h"
#include "mclcom.h"
#include "mclxlmain.h"
#include "Class1_com.hpp"
#include "Forecaster_idl_i.c"
#include "mwcomutil_i.c"
#include "mwcomtypes_i.c"



#ifdef __cplusplus
extern "C" {
#endif

extern mclComponentData __MCC_Forecaster_component_data;

#ifdef __cplusplus
}
#endif


static bool _mcr_initialize_fcn(HMCRINSTANCE* inst,
                                const char* path_to_component,
                                mclCtfStream ctfStream, int ctfStreamSize)
{
  __MCC_Forecaster_component_data.path_to_component = path_to_component;
    {
        if (ctfStream) {
            return mclInitializeComponentInstanceEmbedded(  inst,
                                                            
                                                  &__MCC_Forecaster_component_data,
                                                            true, 
                                                            COMObject, 
                                                            LibTarget,
                                                            NULL, 
                                                            NULL,
                                                            ctfStream, 
                                                            ctfStreamSize);
        } else {
            return false;
        }
    }      
  return false;

}
static bool _mcr_terminate_fcn(HMCRINSTANCE* inst)
{
  return mclTerminateInstance(inst);
}
static CMCLSingleModule g_Module(_mcr_initialize_fcn, _mcr_terminate_fcn, true);
CMCLModule* g_pModule = &g_Module;

static _MCLOBJECT_MAP_ENTRY objectmap[] = 
{
  {
      &CLSID_Class1, CClass1::RegisterClass, CClass1::UnregisterClass, 
    CClass1::GetClassObject, "Class1", "Forecaster.Class1", "Forecaster.Class1.1_0"
  },
  {
    NULL, NULL, NULL, NULL, "", "", ""
  }
};

extern "C" { 

BOOL WINAPI DllMain( HINSTANCE hInstance, DWORD dwReason, void *pv )
{
  return g_pModule->InitMain(objectmap, &LIBID_Forecaster, 1, 0, hInstance, dwReason, pv);
}

HRESULT __stdcall DllCanUnloadNow()
{
  return (g_pModule->GetLockCount()==0) ? S_OK : S_FALSE;
}

HRESULT __stdcall DllGetClassObject(REFCLSID clsid, REFIID iid, void **ppv )
{
  return g_pModule->GetClassObject( clsid, iid, ppv );
}

HRESULT __stdcall DllRegisterServer()
{
  return g_pModule->UpdateRegistry( TRUE );
}

HRESULT __stdcall DllUnregisterServer()
{
  return g_pModule->UpdateRegistry( FALSE );
}

}
