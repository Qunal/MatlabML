

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 6.00.0366 */
/* at Mon Aug 09 11:38:15 2010
 */
/* Compiler settings for C:\Seminars\Load Forecasting\Load\Forecaster\src\Forecaster_idl.idl:
    Oicf, W1, Zp8, env=Win32 (32b run)
    protocol : dce , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
//@@MIDL_FILE_HEADING(  )

#pragma warning( disable: 4049 )  /* more than 64k source lines */


/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 475
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif // __RPCNDR_H_VERSION__

#ifndef COM_NO_WINDOWS_H
#include "windows.h"
#include "ole2.h"
#endif /*COM_NO_WINDOWS_H*/

#ifndef __Forecaster_idl_h__
#define __Forecaster_idl_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IClass1_FWD_DEFINED__
#define __IClass1_FWD_DEFINED__
typedef interface IClass1 IClass1;
#endif 	/* __IClass1_FWD_DEFINED__ */


#ifndef __Class1_FWD_DEFINED__
#define __Class1_FWD_DEFINED__

#ifdef __cplusplus
typedef class Class1 Class1;
#else
typedef struct Class1 Class1;
#endif /* __cplusplus */

#endif 	/* __Class1_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"
#include "mwcomtypes.h"

#ifdef __cplusplus
extern "C"{
#endif 

void * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free( void * ); 

#ifndef __IClass1_INTERFACE_DEFINED__
#define __IClass1_INTERFACE_DEFINED__

/* interface IClass1 */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IClass1;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("1515271A-78BC-4A0C-A9FD-29C149F13932")
    IClass1 : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_MWFlags( 
            /* [retval][out] */ IMWFlags **ppvFlags) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_MWFlags( 
            /* [in] */ IMWFlags *pvFlags) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE loadForecast( 
            /* [in] */ long nargout,
            /* [out][in] */ VARIANT *y,
            /* [in] */ VARIANT date,
            /* [in] */ VARIANT hour,
            /* [in] */ VARIANT temperature,
            /* [in] */ VARIANT isWorkingDay,
            /* [in] */ VARIANT histDate,
            /* [in] */ VARIANT histHour,
            /* [in] */ VARIANT histLoad) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IClass1Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IClass1 * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IClass1 * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IClass1 * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IClass1 * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IClass1 * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IClass1 * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IClass1 * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_MWFlags )( 
            IClass1 * This,
            /* [retval][out] */ IMWFlags **ppvFlags);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_MWFlags )( 
            IClass1 * This,
            /* [in] */ IMWFlags *pvFlags);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *loadForecast )( 
            IClass1 * This,
            /* [in] */ long nargout,
            /* [out][in] */ VARIANT *y,
            /* [in] */ VARIANT date,
            /* [in] */ VARIANT hour,
            /* [in] */ VARIANT temperature,
            /* [in] */ VARIANT isWorkingDay,
            /* [in] */ VARIANT histDate,
            /* [in] */ VARIANT histHour,
            /* [in] */ VARIANT histLoad);
        
        END_INTERFACE
    } IClass1Vtbl;

    interface IClass1
    {
        CONST_VTBL struct IClass1Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IClass1_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IClass1_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IClass1_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IClass1_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IClass1_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IClass1_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IClass1_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IClass1_get_MWFlags(This,ppvFlags)	\
    (This)->lpVtbl -> get_MWFlags(This,ppvFlags)

#define IClass1_put_MWFlags(This,pvFlags)	\
    (This)->lpVtbl -> put_MWFlags(This,pvFlags)

#define IClass1_loadForecast(This,nargout,y,date,hour,temperature,isWorkingDay,histDate,histHour,histLoad)	\
    (This)->lpVtbl -> loadForecast(This,nargout,y,date,hour,temperature,isWorkingDay,histDate,histHour,histLoad)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IClass1_get_MWFlags_Proxy( 
    IClass1 * This,
    /* [retval][out] */ IMWFlags **ppvFlags);


void __RPC_STUB IClass1_get_MWFlags_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IClass1_put_MWFlags_Proxy( 
    IClass1 * This,
    /* [in] */ IMWFlags *pvFlags);


void __RPC_STUB IClass1_put_MWFlags_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IClass1_loadForecast_Proxy( 
    IClass1 * This,
    /* [in] */ long nargout,
    /* [out][in] */ VARIANT *y,
    /* [in] */ VARIANT date,
    /* [in] */ VARIANT hour,
    /* [in] */ VARIANT temperature,
    /* [in] */ VARIANT isWorkingDay,
    /* [in] */ VARIANT histDate,
    /* [in] */ VARIANT histHour,
    /* [in] */ VARIANT histLoad);


void __RPC_STUB IClass1_loadForecast_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IClass1_INTERFACE_DEFINED__ */



#ifndef __Forecaster_LIBRARY_DEFINED__
#define __Forecaster_LIBRARY_DEFINED__

/* library Forecaster */
/* [helpstring][version][uuid] */ 


EXTERN_C const IID LIBID_Forecaster;

EXTERN_C const CLSID CLSID_Class1;

#ifdef __cplusplus

class DECLSPEC_UUID("1CAD517D-68AA-4328-848E-9492D75CCD40")
Class1;
#endif
#endif /* __Forecaster_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

unsigned long             __RPC_USER  VARIANT_UserSize(     unsigned long *, unsigned long            , VARIANT * ); 
unsigned char * __RPC_USER  VARIANT_UserMarshal(  unsigned long *, unsigned char *, VARIANT * ); 
unsigned char * __RPC_USER  VARIANT_UserUnmarshal(unsigned long *, unsigned char *, VARIANT * ); 
void                      __RPC_USER  VARIANT_UserFree(     unsigned long *, VARIANT * ); 

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


