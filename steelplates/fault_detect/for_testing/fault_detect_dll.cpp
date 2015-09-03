#include "mwcomtypes.h"
#include "mclmcrrt.h"
#include "mclcom.h"
#include "mclxlmain.h"
#include "Class1_com.hpp"
#include "fault_detect_idl_i.c"
#include "mwcomutil_i.c"
#include "mwcomtypes_i.c"
#include <sys/stat.h>


#ifdef __cplusplus
extern "C" {
#endif


#ifdef __cplusplus
}
#endif


static bool _mcr_initialize_fcn(HMCRINSTANCE* inst,
                                const char* path_to_component,
                                mclCtfStream ctfStream)
{
    {
        if (ctfStream) {
            return mclInitializeComponentInstanceEmbedded(  inst,
                                                            NULL, 
                                                            NULL,
                                                            ctfStream);
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
    CClass1::GetClassObject, "Class1", "fault_detect.Class1", "fault_detect.Class1.1_0"
  },
  {
    NULL, NULL, NULL, NULL, "", "", ""
  }
};

static void build_mclmcrrt_name(const char* major_ver, const char* minor_ver, const char* update_ver, char* mclmcrrt_name)
{
    char strUUpdateOrEmpty[10];
    strUUpdateOrEmpty[0]='\0';
    if (strcmp(update_ver,"0")!=0) {
        strcat(strUUpdateOrEmpty,"_");
        strcat(strUUpdateOrEmpty,update_ver);
    }
    mclmcrrt_name[0]='\0';
    strcat(mclmcrrt_name,"mclmcrrt");
    strcat(mclmcrrt_name,major_ver);
    strcat(mclmcrrt_name,"_");
    strcat(mclmcrrt_name,minor_ver);
    strcat(mclmcrrt_name,strUUpdateOrEmpty);
    strcat(mclmcrrt_name,".dll");    
}

static bool file_exist( const char* file_name)
{
    struct stat buf;
    if ( stat(file_name,&buf) ==0 ) 
    {
        return true;
    }
    else
    {
        return false;
    }
}
static void initialize_path()
{
	char mclmcrrt_name[_MAX_PATH];
	char* pSysPath=NULL;
	char matlabroot[_MAX_PATH];
	memset(matlabroot,_MAX_PATH,0);
    build_mclmcrrt_name("8","3","0",mclmcrrt_name);
	if (pSysPath = getenv("PATH"))
	{
		char* newPath = (char *) malloc((strlen(pSysPath)+_MAX_PATH+1)*sizeof(char));
		char* pch =NULL;
		newPath[0]='\0';
		strcat(newPath,"PATH=");
		strcat(newPath,pSysPath);
		pch = strtok(pSysPath,";");
		while (pch != NULL) {
			char filepath[_MAX_PATH];
			strcpy(filepath,pch);
			strcat(filepath,"\\");
			strcat(filepath,mclmcrrt_name);
			if (file_exist(filepath)) {
				strcpy(matlabroot,pch);
				strcat(matlabroot,"\\..\\..");
				break;
			}
			pch = strtok(NULL,";");
		}
		if (strlen(matlabroot)!=0)
		{
			strcat(matlabroot,"\\bin\\");
			strcat(matlabroot,"win32");
			strcat(newPath,";");
			strcat(newPath,matlabroot);
			_putenv(newPath);
		}
        free(newPath);
	}
}

extern "C" { 

BOOL WINAPI DllMain( HINSTANCE hInstance, DWORD dwReason, void *pv )
{
  initialize_path();
  return g_pModule->InitMain(objectmap, &LIBID_fault_detect, 1, 0, hInstance, dwReason, 
                             pv);
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
