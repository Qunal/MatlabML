

/* this ALWAYS GENERATED file contains the proxy stub code */


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

#if !defined(_M_IA64) && !defined(_M_AMD64)


#pragma warning( disable: 4049 )  /* more than 64k source lines */
#if _MSC_VER >= 1200
#pragma warning(push)
#endif
#pragma warning( disable: 4100 ) /* unreferenced arguments in x86 call */
#pragma warning( disable: 4211 )  /* redefine extent to static */
#pragma warning( disable: 4232 )  /* dllimport identity*/
#pragma optimize("", off ) 

#define USE_STUBLESS_PROXY


/* verify that the <rpcproxy.h> version is high enough to compile this file*/
#ifndef __REDQ_RPCPROXY_H_VERSION__
#define __REQUIRED_RPCPROXY_H_VERSION__ 475
#endif


#include "rpcproxy.h"
#ifndef __RPCPROXY_H_VERSION__
#error this stub requires an updated version of <rpcproxy.h>
#endif // __RPCPROXY_H_VERSION__


#include "Forecaster_idl.h"

#define TYPE_FORMAT_STRING_SIZE   1075                              
#define PROC_FORMAT_STRING_SIZE   157                               
#define TRANSMIT_AS_TABLE_SIZE    0            
#define WIRE_MARSHAL_TABLE_SIZE   1            

typedef struct _MIDL_TYPE_FORMAT_STRING
    {
    short          Pad;
    unsigned char  Format[ TYPE_FORMAT_STRING_SIZE ];
    } MIDL_TYPE_FORMAT_STRING;

typedef struct _MIDL_PROC_FORMAT_STRING
    {
    short          Pad;
    unsigned char  Format[ PROC_FORMAT_STRING_SIZE ];
    } MIDL_PROC_FORMAT_STRING;


static RPC_SYNTAX_IDENTIFIER  _RpcTransferSyntax = 
{{0x8A885D04,0x1CEB,0x11C9,{0x9F,0xE8,0x08,0x00,0x2B,0x10,0x48,0x60}},{2,0}};


extern const MIDL_TYPE_FORMAT_STRING __MIDL_TypeFormatString;
extern const MIDL_PROC_FORMAT_STRING __MIDL_ProcFormatString;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IClass1_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IClass1_ProxyInfo;


extern const USER_MARSHAL_ROUTINE_QUADRUPLE UserMarshalRoutines[ WIRE_MARSHAL_TABLE_SIZE ];

#if !defined(__RPC_WIN32__)
#error  Invalid build platform for this stub.
#endif

#if !(TARGET_IS_NT50_OR_LATER)
#error You need a Windows 2000 or later to run this stub because it uses these features:
#error   /robust command line switch.
#error However, your C/C++ compilation flags indicate you intend to run this app on earlier systems.
#error This app will die there with the RPC_X_WRONG_STUB_VERSION error.
#endif


static const MIDL_PROC_FORMAT_STRING __MIDL_ProcFormatString =
    {
        0,
        {

	/* Procedure get_MWFlags */

			0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/*  2 */	NdrFcLong( 0x0 ),	/* 0 */
/*  6 */	NdrFcShort( 0x7 ),	/* 7 */
/*  8 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 10 */	NdrFcShort( 0x0 ),	/* 0 */
/* 12 */	NdrFcShort( 0x8 ),	/* 8 */
/* 14 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 16 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 18 */	NdrFcShort( 0x0 ),	/* 0 */
/* 20 */	NdrFcShort( 0x0 ),	/* 0 */
/* 22 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ppvFlags */

/* 24 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 26 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 28 */	NdrFcShort( 0x2 ),	/* Type Offset=2 */

	/* Return value */

/* 30 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 32 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 34 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_MWFlags */

/* 36 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 38 */	NdrFcLong( 0x0 ),	/* 0 */
/* 42 */	NdrFcShort( 0x8 ),	/* 8 */
/* 44 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 46 */	NdrFcShort( 0x0 ),	/* 0 */
/* 48 */	NdrFcShort( 0x8 ),	/* 8 */
/* 50 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 52 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 54 */	NdrFcShort( 0x0 ),	/* 0 */
/* 56 */	NdrFcShort( 0x0 ),	/* 0 */
/* 58 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pvFlags */

/* 60 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 62 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 64 */	NdrFcShort( 0x6 ),	/* Type Offset=6 */

	/* Return value */

/* 66 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 68 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 70 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure loadForecast */

/* 72 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 74 */	NdrFcLong( 0x0 ),	/* 0 */
/* 78 */	NdrFcShort( 0x9 ),	/* 9 */
/* 80 */	NdrFcShort( 0x80 ),	/* x86 Stack size/offset = 128 */
/* 82 */	NdrFcShort( 0x8 ),	/* 8 */
/* 84 */	NdrFcShort( 0x8 ),	/* 8 */
/* 86 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0xa,		/* 10 */
/* 88 */	0x8,		/* 8 */
			0x7,		/* Ext Flags:  new corr desc, clt corr check, srv corr check, */
/* 90 */	NdrFcShort( 0x20 ),	/* 32 */
/* 92 */	NdrFcShort( 0x100 ),	/* 256 */
/* 94 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter nargout */

/* 96 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 98 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 100 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter y */

/* 102 */	NdrFcShort( 0x11b ),	/* Flags:  must size, must free, in, out, simple ref, */
/* 104 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 106 */	NdrFcShort( 0x41a ),	/* Type Offset=1050 */

	/* Parameter date */

/* 108 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 110 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 112 */	NdrFcShort( 0x428 ),	/* Type Offset=1064 */

	/* Parameter hour */

/* 114 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 116 */	NdrFcShort( 0x1c ),	/* x86 Stack size/offset = 28 */
/* 118 */	NdrFcShort( 0x428 ),	/* Type Offset=1064 */

	/* Parameter temperature */

/* 120 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 122 */	NdrFcShort( 0x2c ),	/* x86 Stack size/offset = 44 */
/* 124 */	NdrFcShort( 0x428 ),	/* Type Offset=1064 */

	/* Parameter isWorkingDay */

/* 126 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 128 */	NdrFcShort( 0x3c ),	/* x86 Stack size/offset = 60 */
/* 130 */	NdrFcShort( 0x428 ),	/* Type Offset=1064 */

	/* Parameter histDate */

/* 132 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 134 */	NdrFcShort( 0x4c ),	/* x86 Stack size/offset = 76 */
/* 136 */	NdrFcShort( 0x428 ),	/* Type Offset=1064 */

	/* Parameter histHour */

/* 138 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 140 */	NdrFcShort( 0x5c ),	/* x86 Stack size/offset = 92 */
/* 142 */	NdrFcShort( 0x428 ),	/* Type Offset=1064 */

	/* Parameter histLoad */

/* 144 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
/* 146 */	NdrFcShort( 0x6c ),	/* x86 Stack size/offset = 108 */
/* 148 */	NdrFcShort( 0x428 ),	/* Type Offset=1064 */

	/* Return value */

/* 150 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 152 */	NdrFcShort( 0x7c ),	/* x86 Stack size/offset = 124 */
/* 154 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

			0x0
        }
    };

static const MIDL_TYPE_FORMAT_STRING __MIDL_TypeFormatString =
    {
        0,
        {
			NdrFcShort( 0x0 ),	/* 0 */
/*  2 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/*  4 */	NdrFcShort( 0x2 ),	/* Offset= 2 (6) */
/*  6 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/*  8 */	NdrFcLong( 0xa295776 ),	/* 170481526 */
/* 12 */	NdrFcShort( 0x23a1 ),	/* 9121 */
/* 14 */	NdrFcShort( 0x410a ),	/* 16650 */
/* 16 */	0x94,		/* 148 */
			0xbd,		/* 189 */
/* 18 */	0xc,		/* 12 */
			0x6c,		/* 108 */
/* 20 */	0x61,		/* 97 */
			0xb8,		/* 184 */
/* 22 */	0x91,		/* 145 */
			0xb7,		/* 183 */
/* 24 */	
			0x11, 0x0,	/* FC_RP */
/* 26 */	NdrFcShort( 0x400 ),	/* Offset= 1024 (1050) */
/* 28 */	
			0x13, 0x0,	/* FC_OP */
/* 30 */	NdrFcShort( 0x3e8 ),	/* Offset= 1000 (1030) */
/* 32 */	
			0x2b,		/* FC_NON_ENCAPSULATED_UNION */
			0x9,		/* FC_ULONG */
/* 34 */	0x7,		/* Corr desc: FC_USHORT */
			0x0,		/*  */
/* 36 */	NdrFcShort( 0xfff8 ),	/* -8 */
/* 38 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 40 */	NdrFcShort( 0x2 ),	/* Offset= 2 (42) */
/* 42 */	NdrFcShort( 0x10 ),	/* 16 */
/* 44 */	NdrFcShort( 0x2f ),	/* 47 */
/* 46 */	NdrFcLong( 0x14 ),	/* 20 */
/* 50 */	NdrFcShort( 0x800b ),	/* Simple arm type: FC_HYPER */
/* 52 */	NdrFcLong( 0x3 ),	/* 3 */
/* 56 */	NdrFcShort( 0x8008 ),	/* Simple arm type: FC_LONG */
/* 58 */	NdrFcLong( 0x11 ),	/* 17 */
/* 62 */	NdrFcShort( 0x8001 ),	/* Simple arm type: FC_BYTE */
/* 64 */	NdrFcLong( 0x2 ),	/* 2 */
/* 68 */	NdrFcShort( 0x8006 ),	/* Simple arm type: FC_SHORT */
/* 70 */	NdrFcLong( 0x4 ),	/* 4 */
/* 74 */	NdrFcShort( 0x800a ),	/* Simple arm type: FC_FLOAT */
/* 76 */	NdrFcLong( 0x5 ),	/* 5 */
/* 80 */	NdrFcShort( 0x800c ),	/* Simple arm type: FC_DOUBLE */
/* 82 */	NdrFcLong( 0xb ),	/* 11 */
/* 86 */	NdrFcShort( 0x8006 ),	/* Simple arm type: FC_SHORT */
/* 88 */	NdrFcLong( 0xa ),	/* 10 */
/* 92 */	NdrFcShort( 0x8008 ),	/* Simple arm type: FC_LONG */
/* 94 */	NdrFcLong( 0x6 ),	/* 6 */
/* 98 */	NdrFcShort( 0xe8 ),	/* Offset= 232 (330) */
/* 100 */	NdrFcLong( 0x7 ),	/* 7 */
/* 104 */	NdrFcShort( 0x800c ),	/* Simple arm type: FC_DOUBLE */
/* 106 */	NdrFcLong( 0x8 ),	/* 8 */
/* 110 */	NdrFcShort( 0xe2 ),	/* Offset= 226 (336) */
/* 112 */	NdrFcLong( 0xd ),	/* 13 */
/* 116 */	NdrFcShort( 0xf6 ),	/* Offset= 246 (362) */
/* 118 */	NdrFcLong( 0x9 ),	/* 9 */
/* 122 */	NdrFcShort( 0x102 ),	/* Offset= 258 (380) */
/* 124 */	NdrFcLong( 0x2000 ),	/* 8192 */
/* 128 */	NdrFcShort( 0x10e ),	/* Offset= 270 (398) */
/* 130 */	NdrFcLong( 0x24 ),	/* 36 */
/* 134 */	NdrFcShort( 0x336 ),	/* Offset= 822 (956) */
/* 136 */	NdrFcLong( 0x4024 ),	/* 16420 */
/* 140 */	NdrFcShort( 0x330 ),	/* Offset= 816 (956) */
/* 142 */	NdrFcLong( 0x4011 ),	/* 16401 */
/* 146 */	NdrFcShort( 0x32e ),	/* Offset= 814 (960) */
/* 148 */	NdrFcLong( 0x4002 ),	/* 16386 */
/* 152 */	NdrFcShort( 0x32c ),	/* Offset= 812 (964) */
/* 154 */	NdrFcLong( 0x4003 ),	/* 16387 */
/* 158 */	NdrFcShort( 0x32a ),	/* Offset= 810 (968) */
/* 160 */	NdrFcLong( 0x4014 ),	/* 16404 */
/* 164 */	NdrFcShort( 0x328 ),	/* Offset= 808 (972) */
/* 166 */	NdrFcLong( 0x4004 ),	/* 16388 */
/* 170 */	NdrFcShort( 0x326 ),	/* Offset= 806 (976) */
/* 172 */	NdrFcLong( 0x4005 ),	/* 16389 */
/* 176 */	NdrFcShort( 0x324 ),	/* Offset= 804 (980) */
/* 178 */	NdrFcLong( 0x400b ),	/* 16395 */
/* 182 */	NdrFcShort( 0x30e ),	/* Offset= 782 (964) */
/* 184 */	NdrFcLong( 0x400a ),	/* 16394 */
/* 188 */	NdrFcShort( 0x30c ),	/* Offset= 780 (968) */
/* 190 */	NdrFcLong( 0x4006 ),	/* 16390 */
/* 194 */	NdrFcShort( 0x316 ),	/* Offset= 790 (984) */
/* 196 */	NdrFcLong( 0x4007 ),	/* 16391 */
/* 200 */	NdrFcShort( 0x30c ),	/* Offset= 780 (980) */
/* 202 */	NdrFcLong( 0x4008 ),	/* 16392 */
/* 206 */	NdrFcShort( 0x30e ),	/* Offset= 782 (988) */
/* 208 */	NdrFcLong( 0x400d ),	/* 16397 */
/* 212 */	NdrFcShort( 0x30c ),	/* Offset= 780 (992) */
/* 214 */	NdrFcLong( 0x4009 ),	/* 16393 */
/* 218 */	NdrFcShort( 0x30a ),	/* Offset= 778 (996) */
/* 220 */	NdrFcLong( 0x6000 ),	/* 24576 */
/* 224 */	NdrFcShort( 0x308 ),	/* Offset= 776 (1000) */
/* 226 */	NdrFcLong( 0x400c ),	/* 16396 */
/* 230 */	NdrFcShort( 0x306 ),	/* Offset= 774 (1004) */
/* 232 */	NdrFcLong( 0x10 ),	/* 16 */
/* 236 */	NdrFcShort( 0x8002 ),	/* Simple arm type: FC_CHAR */
/* 238 */	NdrFcLong( 0x12 ),	/* 18 */
/* 242 */	NdrFcShort( 0x8006 ),	/* Simple arm type: FC_SHORT */
/* 244 */	NdrFcLong( 0x13 ),	/* 19 */
/* 248 */	NdrFcShort( 0x8008 ),	/* Simple arm type: FC_LONG */
/* 250 */	NdrFcLong( 0x15 ),	/* 21 */
/* 254 */	NdrFcShort( 0x800b ),	/* Simple arm type: FC_HYPER */
/* 256 */	NdrFcLong( 0x16 ),	/* 22 */
/* 260 */	NdrFcShort( 0x8008 ),	/* Simple arm type: FC_LONG */
/* 262 */	NdrFcLong( 0x17 ),	/* 23 */
/* 266 */	NdrFcShort( 0x8008 ),	/* Simple arm type: FC_LONG */
/* 268 */	NdrFcLong( 0xe ),	/* 14 */
/* 272 */	NdrFcShort( 0x2e4 ),	/* Offset= 740 (1012) */
/* 274 */	NdrFcLong( 0x400e ),	/* 16398 */
/* 278 */	NdrFcShort( 0x2e8 ),	/* Offset= 744 (1022) */
/* 280 */	NdrFcLong( 0x4010 ),	/* 16400 */
/* 284 */	NdrFcShort( 0x2e6 ),	/* Offset= 742 (1026) */
/* 286 */	NdrFcLong( 0x4012 ),	/* 16402 */
/* 290 */	NdrFcShort( 0x2a2 ),	/* Offset= 674 (964) */
/* 292 */	NdrFcLong( 0x4013 ),	/* 16403 */
/* 296 */	NdrFcShort( 0x2a0 ),	/* Offset= 672 (968) */
/* 298 */	NdrFcLong( 0x4015 ),	/* 16405 */
/* 302 */	NdrFcShort( 0x29e ),	/* Offset= 670 (972) */
/* 304 */	NdrFcLong( 0x4016 ),	/* 16406 */
/* 308 */	NdrFcShort( 0x294 ),	/* Offset= 660 (968) */
/* 310 */	NdrFcLong( 0x4017 ),	/* 16407 */
/* 314 */	NdrFcShort( 0x28e ),	/* Offset= 654 (968) */
/* 316 */	NdrFcLong( 0x0 ),	/* 0 */
/* 320 */	NdrFcShort( 0x0 ),	/* Offset= 0 (320) */
/* 322 */	NdrFcLong( 0x1 ),	/* 1 */
/* 326 */	NdrFcShort( 0x0 ),	/* Offset= 0 (326) */
/* 328 */	NdrFcShort( 0xffff ),	/* Offset= -1 (327) */
/* 330 */	
			0x15,		/* FC_STRUCT */
			0x7,		/* 7 */
/* 332 */	NdrFcShort( 0x8 ),	/* 8 */
/* 334 */	0xb,		/* FC_HYPER */
			0x5b,		/* FC_END */
/* 336 */	
			0x13, 0x0,	/* FC_OP */
/* 338 */	NdrFcShort( 0xe ),	/* Offset= 14 (352) */
/* 340 */	
			0x1b,		/* FC_CARRAY */
			0x1,		/* 1 */
/* 342 */	NdrFcShort( 0x2 ),	/* 2 */
/* 344 */	0x9,		/* Corr desc: FC_ULONG */
			0x0,		/*  */
/* 346 */	NdrFcShort( 0xfffc ),	/* -4 */
/* 348 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 350 */	0x6,		/* FC_SHORT */
			0x5b,		/* FC_END */
/* 352 */	
			0x17,		/* FC_CSTRUCT */
			0x3,		/* 3 */
/* 354 */	NdrFcShort( 0x8 ),	/* 8 */
/* 356 */	NdrFcShort( 0xfff0 ),	/* Offset= -16 (340) */
/* 358 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 360 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 362 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 364 */	NdrFcLong( 0x0 ),	/* 0 */
/* 368 */	NdrFcShort( 0x0 ),	/* 0 */
/* 370 */	NdrFcShort( 0x0 ),	/* 0 */
/* 372 */	0xc0,		/* 192 */
			0x0,		/* 0 */
/* 374 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 376 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 378 */	0x0,		/* 0 */
			0x46,		/* 70 */
/* 380 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 382 */	NdrFcLong( 0x20400 ),	/* 132096 */
/* 386 */	NdrFcShort( 0x0 ),	/* 0 */
/* 388 */	NdrFcShort( 0x0 ),	/* 0 */
/* 390 */	0xc0,		/* 192 */
			0x0,		/* 0 */
/* 392 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 394 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 396 */	0x0,		/* 0 */
			0x46,		/* 70 */
/* 398 */	
			0x13, 0x10,	/* FC_OP [pointer_deref] */
/* 400 */	NdrFcShort( 0x2 ),	/* Offset= 2 (402) */
/* 402 */	
			0x13, 0x0,	/* FC_OP */
/* 404 */	NdrFcShort( 0x216 ),	/* Offset= 534 (938) */
/* 406 */	
			0x2a,		/* FC_ENCAPSULATED_UNION */
			0x49,		/* 73 */
/* 408 */	NdrFcShort( 0x18 ),	/* 24 */
/* 410 */	NdrFcShort( 0xa ),	/* 10 */
/* 412 */	NdrFcLong( 0x8 ),	/* 8 */
/* 416 */	NdrFcShort( 0x5a ),	/* Offset= 90 (506) */
/* 418 */	NdrFcLong( 0xd ),	/* 13 */
/* 422 */	NdrFcShort( 0x7e ),	/* Offset= 126 (548) */
/* 424 */	NdrFcLong( 0x9 ),	/* 9 */
/* 428 */	NdrFcShort( 0x9e ),	/* Offset= 158 (586) */
/* 430 */	NdrFcLong( 0xc ),	/* 12 */
/* 434 */	NdrFcShort( 0xc8 ),	/* Offset= 200 (634) */
/* 436 */	NdrFcLong( 0x24 ),	/* 36 */
/* 440 */	NdrFcShort( 0x124 ),	/* Offset= 292 (732) */
/* 442 */	NdrFcLong( 0x800d ),	/* 32781 */
/* 446 */	NdrFcShort( 0x140 ),	/* Offset= 320 (766) */
/* 448 */	NdrFcLong( 0x10 ),	/* 16 */
/* 452 */	NdrFcShort( 0x15a ),	/* Offset= 346 (798) */
/* 454 */	NdrFcLong( 0x2 ),	/* 2 */
/* 458 */	NdrFcShort( 0x174 ),	/* Offset= 372 (830) */
/* 460 */	NdrFcLong( 0x3 ),	/* 3 */
/* 464 */	NdrFcShort( 0x18e ),	/* Offset= 398 (862) */
/* 466 */	NdrFcLong( 0x14 ),	/* 20 */
/* 470 */	NdrFcShort( 0x1a8 ),	/* Offset= 424 (894) */
/* 472 */	NdrFcShort( 0xffff ),	/* Offset= -1 (471) */
/* 474 */	
			0x1b,		/* FC_CARRAY */
			0x3,		/* 3 */
/* 476 */	NdrFcShort( 0x4 ),	/* 4 */
/* 478 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 480 */	NdrFcShort( 0x0 ),	/* 0 */
/* 482 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 484 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 486 */	
			0x48,		/* FC_VARIABLE_REPEAT */
			0x49,		/* FC_FIXED_OFFSET */
/* 488 */	NdrFcShort( 0x4 ),	/* 4 */
/* 490 */	NdrFcShort( 0x0 ),	/* 0 */
/* 492 */	NdrFcShort( 0x1 ),	/* 1 */
/* 494 */	NdrFcShort( 0x0 ),	/* 0 */
/* 496 */	NdrFcShort( 0x0 ),	/* 0 */
/* 498 */	0x13, 0x0,	/* FC_OP */
/* 500 */	NdrFcShort( 0xff6c ),	/* Offset= -148 (352) */
/* 502 */	
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 504 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 506 */	
			0x16,		/* FC_PSTRUCT */
			0x3,		/* 3 */
/* 508 */	NdrFcShort( 0x8 ),	/* 8 */
/* 510 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 512 */	
			0x46,		/* FC_NO_REPEAT */
			0x5c,		/* FC_PAD */
/* 514 */	NdrFcShort( 0x4 ),	/* 4 */
/* 516 */	NdrFcShort( 0x4 ),	/* 4 */
/* 518 */	0x11, 0x0,	/* FC_RP */
/* 520 */	NdrFcShort( 0xffd2 ),	/* Offset= -46 (474) */
/* 522 */	
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 524 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 526 */	
			0x21,		/* FC_BOGUS_ARRAY */
			0x3,		/* 3 */
/* 528 */	NdrFcShort( 0x0 ),	/* 0 */
/* 530 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 532 */	NdrFcShort( 0x0 ),	/* 0 */
/* 534 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 536 */	NdrFcLong( 0xffffffff ),	/* -1 */
/* 540 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 542 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 544 */	NdrFcShort( 0xff4a ),	/* Offset= -182 (362) */
/* 546 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 548 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 550 */	NdrFcShort( 0x8 ),	/* 8 */
/* 552 */	NdrFcShort( 0x0 ),	/* 0 */
/* 554 */	NdrFcShort( 0x6 ),	/* Offset= 6 (560) */
/* 556 */	0x8,		/* FC_LONG */
			0x36,		/* FC_POINTER */
/* 558 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 560 */	
			0x11, 0x0,	/* FC_RP */
/* 562 */	NdrFcShort( 0xffdc ),	/* Offset= -36 (526) */
/* 564 */	
			0x21,		/* FC_BOGUS_ARRAY */
			0x3,		/* 3 */
/* 566 */	NdrFcShort( 0x0 ),	/* 0 */
/* 568 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 570 */	NdrFcShort( 0x0 ),	/* 0 */
/* 572 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 574 */	NdrFcLong( 0xffffffff ),	/* -1 */
/* 578 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 580 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 582 */	NdrFcShort( 0xff36 ),	/* Offset= -202 (380) */
/* 584 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 586 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 588 */	NdrFcShort( 0x8 ),	/* 8 */
/* 590 */	NdrFcShort( 0x0 ),	/* 0 */
/* 592 */	NdrFcShort( 0x6 ),	/* Offset= 6 (598) */
/* 594 */	0x8,		/* FC_LONG */
			0x36,		/* FC_POINTER */
/* 596 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 598 */	
			0x11, 0x0,	/* FC_RP */
/* 600 */	NdrFcShort( 0xffdc ),	/* Offset= -36 (564) */
/* 602 */	
			0x1b,		/* FC_CARRAY */
			0x3,		/* 3 */
/* 604 */	NdrFcShort( 0x4 ),	/* 4 */
/* 606 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 608 */	NdrFcShort( 0x0 ),	/* 0 */
/* 610 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 612 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 614 */	
			0x48,		/* FC_VARIABLE_REPEAT */
			0x49,		/* FC_FIXED_OFFSET */
/* 616 */	NdrFcShort( 0x4 ),	/* 4 */
/* 618 */	NdrFcShort( 0x0 ),	/* 0 */
/* 620 */	NdrFcShort( 0x1 ),	/* 1 */
/* 622 */	NdrFcShort( 0x0 ),	/* 0 */
/* 624 */	NdrFcShort( 0x0 ),	/* 0 */
/* 626 */	0x13, 0x0,	/* FC_OP */
/* 628 */	NdrFcShort( 0x192 ),	/* Offset= 402 (1030) */
/* 630 */	
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 632 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 634 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 636 */	NdrFcShort( 0x8 ),	/* 8 */
/* 638 */	NdrFcShort( 0x0 ),	/* 0 */
/* 640 */	NdrFcShort( 0x6 ),	/* Offset= 6 (646) */
/* 642 */	0x8,		/* FC_LONG */
			0x36,		/* FC_POINTER */
/* 644 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 646 */	
			0x11, 0x0,	/* FC_RP */
/* 648 */	NdrFcShort( 0xffd2 ),	/* Offset= -46 (602) */
/* 650 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 652 */	NdrFcLong( 0x2f ),	/* 47 */
/* 656 */	NdrFcShort( 0x0 ),	/* 0 */
/* 658 */	NdrFcShort( 0x0 ),	/* 0 */
/* 660 */	0xc0,		/* 192 */
			0x0,		/* 0 */
/* 662 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 664 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 666 */	0x0,		/* 0 */
			0x46,		/* 70 */
/* 668 */	
			0x1b,		/* FC_CARRAY */
			0x0,		/* 0 */
/* 670 */	NdrFcShort( 0x1 ),	/* 1 */
/* 672 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 674 */	NdrFcShort( 0x4 ),	/* 4 */
/* 676 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 678 */	0x1,		/* FC_BYTE */
			0x5b,		/* FC_END */
/* 680 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 682 */	NdrFcShort( 0x10 ),	/* 16 */
/* 684 */	NdrFcShort( 0x0 ),	/* 0 */
/* 686 */	NdrFcShort( 0xa ),	/* Offset= 10 (696) */
/* 688 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 690 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 692 */	NdrFcShort( 0xffd6 ),	/* Offset= -42 (650) */
/* 694 */	0x36,		/* FC_POINTER */
			0x5b,		/* FC_END */
/* 696 */	
			0x13, 0x0,	/* FC_OP */
/* 698 */	NdrFcShort( 0xffe2 ),	/* Offset= -30 (668) */
/* 700 */	
			0x1b,		/* FC_CARRAY */
			0x3,		/* 3 */
/* 702 */	NdrFcShort( 0x4 ),	/* 4 */
/* 704 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 706 */	NdrFcShort( 0x0 ),	/* 0 */
/* 708 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 710 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 712 */	
			0x48,		/* FC_VARIABLE_REPEAT */
			0x49,		/* FC_FIXED_OFFSET */
/* 714 */	NdrFcShort( 0x4 ),	/* 4 */
/* 716 */	NdrFcShort( 0x0 ),	/* 0 */
/* 718 */	NdrFcShort( 0x1 ),	/* 1 */
/* 720 */	NdrFcShort( 0x0 ),	/* 0 */
/* 722 */	NdrFcShort( 0x0 ),	/* 0 */
/* 724 */	0x13, 0x0,	/* FC_OP */
/* 726 */	NdrFcShort( 0xffd2 ),	/* Offset= -46 (680) */
/* 728 */	
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 730 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 732 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 734 */	NdrFcShort( 0x8 ),	/* 8 */
/* 736 */	NdrFcShort( 0x0 ),	/* 0 */
/* 738 */	NdrFcShort( 0x6 ),	/* Offset= 6 (744) */
/* 740 */	0x8,		/* FC_LONG */
			0x36,		/* FC_POINTER */
/* 742 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 744 */	
			0x11, 0x0,	/* FC_RP */
/* 746 */	NdrFcShort( 0xffd2 ),	/* Offset= -46 (700) */
/* 748 */	
			0x1d,		/* FC_SMFARRAY */
			0x0,		/* 0 */
/* 750 */	NdrFcShort( 0x8 ),	/* 8 */
/* 752 */	0x1,		/* FC_BYTE */
			0x5b,		/* FC_END */
/* 754 */	
			0x15,		/* FC_STRUCT */
			0x3,		/* 3 */
/* 756 */	NdrFcShort( 0x10 ),	/* 16 */
/* 758 */	0x8,		/* FC_LONG */
			0x6,		/* FC_SHORT */
/* 760 */	0x6,		/* FC_SHORT */
			0x4c,		/* FC_EMBEDDED_COMPLEX */
/* 762 */	0x0,		/* 0 */
			NdrFcShort( 0xfff1 ),	/* Offset= -15 (748) */
			0x5b,		/* FC_END */
/* 766 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 768 */	NdrFcShort( 0x18 ),	/* 24 */
/* 770 */	NdrFcShort( 0x0 ),	/* 0 */
/* 772 */	NdrFcShort( 0xa ),	/* Offset= 10 (782) */
/* 774 */	0x8,		/* FC_LONG */
			0x36,		/* FC_POINTER */
/* 776 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 778 */	NdrFcShort( 0xffe8 ),	/* Offset= -24 (754) */
/* 780 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 782 */	
			0x11, 0x0,	/* FC_RP */
/* 784 */	NdrFcShort( 0xfefe ),	/* Offset= -258 (526) */
/* 786 */	
			0x1b,		/* FC_CARRAY */
			0x0,		/* 0 */
/* 788 */	NdrFcShort( 0x1 ),	/* 1 */
/* 790 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 792 */	NdrFcShort( 0x0 ),	/* 0 */
/* 794 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 796 */	0x1,		/* FC_BYTE */
			0x5b,		/* FC_END */
/* 798 */	
			0x16,		/* FC_PSTRUCT */
			0x3,		/* 3 */
/* 800 */	NdrFcShort( 0x8 ),	/* 8 */
/* 802 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 804 */	
			0x46,		/* FC_NO_REPEAT */
			0x5c,		/* FC_PAD */
/* 806 */	NdrFcShort( 0x4 ),	/* 4 */
/* 808 */	NdrFcShort( 0x4 ),	/* 4 */
/* 810 */	0x13, 0x0,	/* FC_OP */
/* 812 */	NdrFcShort( 0xffe6 ),	/* Offset= -26 (786) */
/* 814 */	
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 816 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 818 */	
			0x1b,		/* FC_CARRAY */
			0x1,		/* 1 */
/* 820 */	NdrFcShort( 0x2 ),	/* 2 */
/* 822 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 824 */	NdrFcShort( 0x0 ),	/* 0 */
/* 826 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 828 */	0x6,		/* FC_SHORT */
			0x5b,		/* FC_END */
/* 830 */	
			0x16,		/* FC_PSTRUCT */
			0x3,		/* 3 */
/* 832 */	NdrFcShort( 0x8 ),	/* 8 */
/* 834 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 836 */	
			0x46,		/* FC_NO_REPEAT */
			0x5c,		/* FC_PAD */
/* 838 */	NdrFcShort( 0x4 ),	/* 4 */
/* 840 */	NdrFcShort( 0x4 ),	/* 4 */
/* 842 */	0x13, 0x0,	/* FC_OP */
/* 844 */	NdrFcShort( 0xffe6 ),	/* Offset= -26 (818) */
/* 846 */	
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 848 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 850 */	
			0x1b,		/* FC_CARRAY */
			0x3,		/* 3 */
/* 852 */	NdrFcShort( 0x4 ),	/* 4 */
/* 854 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 856 */	NdrFcShort( 0x0 ),	/* 0 */
/* 858 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 860 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 862 */	
			0x16,		/* FC_PSTRUCT */
			0x3,		/* 3 */
/* 864 */	NdrFcShort( 0x8 ),	/* 8 */
/* 866 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 868 */	
			0x46,		/* FC_NO_REPEAT */
			0x5c,		/* FC_PAD */
/* 870 */	NdrFcShort( 0x4 ),	/* 4 */
/* 872 */	NdrFcShort( 0x4 ),	/* 4 */
/* 874 */	0x13, 0x0,	/* FC_OP */
/* 876 */	NdrFcShort( 0xffe6 ),	/* Offset= -26 (850) */
/* 878 */	
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 880 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 882 */	
			0x1b,		/* FC_CARRAY */
			0x7,		/* 7 */
/* 884 */	NdrFcShort( 0x8 ),	/* 8 */
/* 886 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 888 */	NdrFcShort( 0x0 ),	/* 0 */
/* 890 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 892 */	0xb,		/* FC_HYPER */
			0x5b,		/* FC_END */
/* 894 */	
			0x16,		/* FC_PSTRUCT */
			0x3,		/* 3 */
/* 896 */	NdrFcShort( 0x8 ),	/* 8 */
/* 898 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 900 */	
			0x46,		/* FC_NO_REPEAT */
			0x5c,		/* FC_PAD */
/* 902 */	NdrFcShort( 0x4 ),	/* 4 */
/* 904 */	NdrFcShort( 0x4 ),	/* 4 */
/* 906 */	0x13, 0x0,	/* FC_OP */
/* 908 */	NdrFcShort( 0xffe6 ),	/* Offset= -26 (882) */
/* 910 */	
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 912 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 914 */	
			0x15,		/* FC_STRUCT */
			0x3,		/* 3 */
/* 916 */	NdrFcShort( 0x8 ),	/* 8 */
/* 918 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 920 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 922 */	
			0x1b,		/* FC_CARRAY */
			0x3,		/* 3 */
/* 924 */	NdrFcShort( 0x8 ),	/* 8 */
/* 926 */	0x7,		/* Corr desc: FC_USHORT */
			0x0,		/*  */
/* 928 */	NdrFcShort( 0xffd8 ),	/* -40 */
/* 930 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 932 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 934 */	NdrFcShort( 0xffec ),	/* Offset= -20 (914) */
/* 936 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 938 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 940 */	NdrFcShort( 0x28 ),	/* 40 */
/* 942 */	NdrFcShort( 0xffec ),	/* Offset= -20 (922) */
/* 944 */	NdrFcShort( 0x0 ),	/* Offset= 0 (944) */
/* 946 */	0x6,		/* FC_SHORT */
			0x6,		/* FC_SHORT */
/* 948 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 950 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 952 */	NdrFcShort( 0xfdde ),	/* Offset= -546 (406) */
/* 954 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 956 */	
			0x13, 0x0,	/* FC_OP */
/* 958 */	NdrFcShort( 0xfeea ),	/* Offset= -278 (680) */
/* 960 */	
			0x13, 0x8,	/* FC_OP [simple_pointer] */
/* 962 */	0x1,		/* FC_BYTE */
			0x5c,		/* FC_PAD */
/* 964 */	
			0x13, 0x8,	/* FC_OP [simple_pointer] */
/* 966 */	0x6,		/* FC_SHORT */
			0x5c,		/* FC_PAD */
/* 968 */	
			0x13, 0x8,	/* FC_OP [simple_pointer] */
/* 970 */	0x8,		/* FC_LONG */
			0x5c,		/* FC_PAD */
/* 972 */	
			0x13, 0x8,	/* FC_OP [simple_pointer] */
/* 974 */	0xb,		/* FC_HYPER */
			0x5c,		/* FC_PAD */
/* 976 */	
			0x13, 0x8,	/* FC_OP [simple_pointer] */
/* 978 */	0xa,		/* FC_FLOAT */
			0x5c,		/* FC_PAD */
/* 980 */	
			0x13, 0x8,	/* FC_OP [simple_pointer] */
/* 982 */	0xc,		/* FC_DOUBLE */
			0x5c,		/* FC_PAD */
/* 984 */	
			0x13, 0x0,	/* FC_OP */
/* 986 */	NdrFcShort( 0xfd70 ),	/* Offset= -656 (330) */
/* 988 */	
			0x13, 0x10,	/* FC_OP [pointer_deref] */
/* 990 */	NdrFcShort( 0xfd72 ),	/* Offset= -654 (336) */
/* 992 */	
			0x13, 0x10,	/* FC_OP [pointer_deref] */
/* 994 */	NdrFcShort( 0xfd88 ),	/* Offset= -632 (362) */
/* 996 */	
			0x13, 0x10,	/* FC_OP [pointer_deref] */
/* 998 */	NdrFcShort( 0xfd96 ),	/* Offset= -618 (380) */
/* 1000 */	
			0x13, 0x10,	/* FC_OP [pointer_deref] */
/* 1002 */	NdrFcShort( 0xfda4 ),	/* Offset= -604 (398) */
/* 1004 */	
			0x13, 0x10,	/* FC_OP [pointer_deref] */
/* 1006 */	NdrFcShort( 0x2 ),	/* Offset= 2 (1008) */
/* 1008 */	
			0x13, 0x0,	/* FC_OP */
/* 1010 */	NdrFcShort( 0x14 ),	/* Offset= 20 (1030) */
/* 1012 */	
			0x15,		/* FC_STRUCT */
			0x7,		/* 7 */
/* 1014 */	NdrFcShort( 0x10 ),	/* 16 */
/* 1016 */	0x6,		/* FC_SHORT */
			0x1,		/* FC_BYTE */
/* 1018 */	0x1,		/* FC_BYTE */
			0x8,		/* FC_LONG */
/* 1020 */	0xb,		/* FC_HYPER */
			0x5b,		/* FC_END */
/* 1022 */	
			0x13, 0x0,	/* FC_OP */
/* 1024 */	NdrFcShort( 0xfff4 ),	/* Offset= -12 (1012) */
/* 1026 */	
			0x13, 0x8,	/* FC_OP [simple_pointer] */
/* 1028 */	0x2,		/* FC_CHAR */
			0x5c,		/* FC_PAD */
/* 1030 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x7,		/* 7 */
/* 1032 */	NdrFcShort( 0x20 ),	/* 32 */
/* 1034 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1036 */	NdrFcShort( 0x0 ),	/* Offset= 0 (1036) */
/* 1038 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 1040 */	0x6,		/* FC_SHORT */
			0x6,		/* FC_SHORT */
/* 1042 */	0x6,		/* FC_SHORT */
			0x6,		/* FC_SHORT */
/* 1044 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 1046 */	NdrFcShort( 0xfc0a ),	/* Offset= -1014 (32) */
/* 1048 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 1050 */	0xb4,		/* FC_USER_MARSHAL */
			0x83,		/* 131 */
/* 1052 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1054 */	NdrFcShort( 0x10 ),	/* 16 */
/* 1056 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1058 */	NdrFcShort( 0xfbfa ),	/* Offset= -1030 (28) */
/* 1060 */	
			0x12, 0x0,	/* FC_UP */
/* 1062 */	NdrFcShort( 0xffe0 ),	/* Offset= -32 (1030) */
/* 1064 */	0xb4,		/* FC_USER_MARSHAL */
			0x83,		/* 131 */
/* 1066 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1068 */	NdrFcShort( 0x10 ),	/* 16 */
/* 1070 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1072 */	NdrFcShort( 0xfff4 ),	/* Offset= -12 (1060) */

			0x0
        }
    };

static const USER_MARSHAL_ROUTINE_QUADRUPLE UserMarshalRoutines[ WIRE_MARSHAL_TABLE_SIZE ] = 
        {
            
            {
            VARIANT_UserSize
            ,VARIANT_UserMarshal
            ,VARIANT_UserUnmarshal
            ,VARIANT_UserFree
            }

        };



/* Object interface: IUnknown, ver. 0.0,
   GUID={0x00000000,0x0000,0x0000,{0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}} */


/* Object interface: IDispatch, ver. 0.0,
   GUID={0x00020400,0x0000,0x0000,{0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}} */


/* Object interface: IClass1, ver. 0.0,
   GUID={0x1515271A,0x78BC,0x4A0C,{0xA9,0xFD,0x29,0xC1,0x49,0xF1,0x39,0x32}} */

#pragma code_seg(".orpc")
static const unsigned short IClass1_FormatStringOffsetTable[] =
    {
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    0,
    36,
    72
    };

static const MIDL_STUBLESS_PROXY_INFO IClass1_ProxyInfo =
    {
    &Object_StubDesc,
    __MIDL_ProcFormatString.Format,
    &IClass1_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IClass1_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    __MIDL_ProcFormatString.Format,
    &IClass1_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(10) _IClass1ProxyVtbl = 
{
    &IClass1_ProxyInfo,
    &IID_IClass1,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetTypeInfoCount */ ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetTypeInfo */ ,
    0 /* (void *) (INT_PTR) -1 /* IDispatch::GetIDsOfNames */ ,
    0 /* IDispatch_Invoke_Proxy */ ,
    (void *) (INT_PTR) -1 /* IClass1::get_MWFlags */ ,
    (void *) (INT_PTR) -1 /* IClass1::put_MWFlags */ ,
    (void *) (INT_PTR) -1 /* IClass1::loadForecast */
};


static const PRPC_STUB_FUNCTION IClass1_table[] =
{
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2
};

CInterfaceStubVtbl _IClass1StubVtbl =
{
    &IID_IClass1,
    &IClass1_ServerInfo,
    10,
    &IClass1_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};

static const MIDL_STUB_DESC Object_StubDesc = 
    {
    0,
    NdrOleAllocate,
    NdrOleFree,
    0,
    0,
    0,
    0,
    0,
    __MIDL_TypeFormatString.Format,
    1, /* -error bounds_check flag */
    0x50002, /* Ndr library version */
    0,
    0x600016e, /* MIDL Version 6.0.366 */
    0,
    UserMarshalRoutines,
    0,  /* notify & notify_flag routine table */
    0x1, /* MIDL flag */
    0, /* cs routines */
    0,   /* proxy/server info */
    0   /* Reserved5 */
    };

const CInterfaceProxyVtbl * _Forecaster_idl_ProxyVtblList[] = 
{
    ( CInterfaceProxyVtbl *) &_IClass1ProxyVtbl,
    0
};

const CInterfaceStubVtbl * _Forecaster_idl_StubVtblList[] = 
{
    ( CInterfaceStubVtbl *) &_IClass1StubVtbl,
    0
};

PCInterfaceName const _Forecaster_idl_InterfaceNamesList[] = 
{
    "IClass1",
    0
};

const IID *  _Forecaster_idl_BaseIIDList[] = 
{
    &IID_IDispatch,
    0
};


#define _Forecaster_idl_CHECK_IID(n)	IID_GENERIC_CHECK_IID( _Forecaster_idl, pIID, n)

int __stdcall _Forecaster_idl_IID_Lookup( const IID * pIID, int * pIndex )
{
    
    if(!_Forecaster_idl_CHECK_IID(0))
        {
        *pIndex = 0;
        return 1;
        }

    return 0;
}

const ExtendedProxyFileInfo Forecaster_idl_ProxyFileInfo = 
{
    (PCInterfaceProxyVtblList *) & _Forecaster_idl_ProxyVtblList,
    (PCInterfaceStubVtblList *) & _Forecaster_idl_StubVtblList,
    (const PCInterfaceName * ) & _Forecaster_idl_InterfaceNamesList,
    (const IID ** ) & _Forecaster_idl_BaseIIDList,
    & _Forecaster_idl_IID_Lookup, 
    1,
    2,
    0, /* table of [async_uuid] interfaces */
    0, /* Filler1 */
    0, /* Filler2 */
    0  /* Filler3 */
};
#pragma optimize("", on )
#if _MSC_VER >= 1200
#pragma warning(pop)
#endif


#endif /* !defined(_M_IA64) && !defined(_M_AMD64)*/

