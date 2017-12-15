"""key.go - mixnet user key
Copyright (C) 2017  Yawning Angel.
Copyright (C) 2017  Ruben Pollan.

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU Affero General Public License as
published by the Free Software Foundation, either version 3 of the
License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU Affero General Public License for more details.

You should have received a copy of the GNU Affero General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.

Package minclient provides a mixnet minimal client library

session.go - mixnet session client
Copyright (C) 2017  Yawning Angel.
Copyright (C) 2017  Ruben Pollan.

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU Affero General Public License as
published by the Free Software Foundation, either version 3 of the
License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU Affero General Public License for more details.

You should have received a copy of the GNU Affero General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
"""
import collections
import os
import sys
import cffi as _cffi_backend

_PY3 = sys.version_info[0] == 3

ffi = _cffi_backend.FFI()
ffi.cdef("""
typedef signed char GoInt8;
typedef unsigned char GoUint8;
typedef short GoInt16;
typedef unsigned short GoUint16;
typedef int GoInt32;
typedef unsigned int GoUint32;
typedef long long GoInt64;
typedef size_t GoUintptr;
typedef unsigned long long GoUint64;
typedef GoInt64 GoInt;
typedef GoUint64 GoUint;
typedef float GoFloat32;
typedef double GoFloat64;
typedef struct { const char *p; GoInt n; } GoString;
typedef void *GoMap;
typedef void *GoChan;
typedef struct { void *t; void *v; } GoInterface;
typedef struct { void *data; GoInt len; GoInt cap; } GoSlice;
typedef struct { GoFloat32 real; GoFloat32 imag; } GoComplex64;
typedef struct { GoFloat64 real; GoFloat64 imag; } GoComplex128;

extern GoComplex64 _cgopy_GoComplex64(GoFloat32 p0, GoFloat32 p1);
extern GoComplex128 _cgopy_GoComplex128(GoFloat64 p0, GoFloat64 p1);
extern GoString _cgopy_GoString(char* p0);
extern char* _cgopy_CString(GoString p0);
extern void _cgopy_FreeCString(char* p0);
extern GoUint8 _cgopy_ErrorIsNil(GoInterface p0);
extern char* _cgopy_ErrorString(GoInterface p0);
extern void cgopy_incref(void* p0);
extern void cgopy_decref(void* p0);

extern void cgo_pkg_minclient_init();

// C definitions for Go type minclient.minclient_Client.
// C definitions for Go type minclient.minclient_Key.
// C definitions for Go type minclient.minclient_LogConfig.
// C definitions for Go type minclient.minclient_Session.
// C definitions for Go type minclient.minclient_Client.
// C definitions for Go type minclient.minclient_Key.
// C definitions for Go type minclient.minclient_LogConfig.
// C definitions for Go type minclient.minclient_Session.
// A type definition of the minclient.cgo_type_minclient_Client for wrapping.
typedef void* cgo_type_minclient_Client;
extern void* cgo_func_minclient_Client_new();
// A type definition of the minclient.cgo_type_minclient_Key for wrapping.
typedef void* cgo_type_minclient_Key;
extern void* cgo_func_minclient_Key_new();
// A type definition of the minclient.cgo_type_minclient_LogConfig for wrapping.
typedef void* cgo_type_minclient_LogConfig;
extern void* cgo_func_minclient_LogConfig_new();
// A type definition of the minclient.cgo_type_minclient_Session for wrapping.
typedef void* cgo_type_minclient_Session;
extern void* cgo_func_minclient_Session_new();
typedef struct { cgo_type_minclient_Client r0; GoInterface r1; } cgo_func_minclient_NewClient_return;
extern cgo_func_minclient_NewClient_return cgo_func_minclient_NewClient(GoString p0, GoString p1, cgo_type_minclient_LogConfig p2);
typedef struct { cgo_type_minclient_Key r0; GoInterface r1; } cgo_func_minclient_StringToKey_return;
extern cgo_func_minclient_StringToKey_return cgo_func_minclient_StringToKey(GoString p0);
typedef struct { cgo_type_minclient_Key r0; GoInterface r1; } cgo_func_minclient_GenKey_return;
extern cgo_func_minclient_GenKey_return cgo_func_minclient_GenKey();
typedef struct { cgo_type_minclient_Session r0; GoInterface r1; } cgo_func_minclient_Client_NewSession_return;
extern cgo_func_minclient_Client_NewSession_return cgo_func_minclient_Client_NewSession(void* p0, GoString p1, GoString p2, cgo_type_minclient_Key p3);
extern GoString cgo_func_minclient_Client_str(void* p0);
extern GoString cgo_func_minclient_Key_getter_1(void* p0);
extern void cgo_func_minclient_Key_setter_1(void* p0, GoString p1);
extern GoString cgo_func_minclient_Key_getter_2(void* p0);
extern void cgo_func_minclient_Key_setter_2(void* p0, GoString p1);
extern GoString cgo_func_minclient_Key_str(void* p0);
extern GoString cgo_func_minclient_LogConfig_getter_1(void* p0);
extern void cgo_func_minclient_LogConfig_setter_1(void* p0, GoString p1);
extern GoString cgo_func_minclient_LogConfig_getter_2(void* p0);
extern void cgo_func_minclient_LogConfig_setter_2(void* p0, GoString p1);
extern GoUint8 cgo_func_minclient_LogConfig_getter_3(void* p0);
extern void cgo_func_minclient_LogConfig_setter_3(void* p0, GoUint8 p1);
extern GoString cgo_func_minclient_LogConfig_str(void* p0);
extern GoString cgo_func_minclient_Session_GetMessage(void* p0);
extern GoInterface cgo_func_minclient_Session_SendMessage(void* p0, GoString p1, GoString p2, GoString p3);
extern void cgo_func_minclient_Session_Shutdown(void* p0);
extern GoString cgo_func_minclient_Session_str(void* p0);
""")

# python <--> cffi helper.
class _cffi_helper(object):

    here = os.path.dirname(os.path.abspath(__file__))
    lib = ffi.dlopen(os.path.join(here, "_minclient.so"))

    @staticmethod
    def cffi_cgopy_cnv_py2c_bool(o):
        return ffi.cast('_Bool', o)

    @staticmethod
    def cffi_cgopy_cnv_py2c_complex64(o):
        real = o.real
        imag = o.imag
        complex64 = _cffi_helper.lib._cgopy_GoComplex64(real, imag)
        return complex64

    @staticmethod
    def cffi_cgopy_cnv_py2c_complex128(o):
        real = o.real
        imag = o.imag
        complex128 = _cffi_helper.lib._cgopy_GoComplex128(real, imag)
        return complex128

    @staticmethod
    def cffi_cgopy_cnv_py2c_string(o):
        if _PY3:
            o = o.encode('ascii')
        s = ffi.new("char[]", o)
        return _cffi_helper.lib._cgopy_GoString(s)

    @staticmethod
    def cffi_cgopy_cnv_py2c_int(o):
        return ffi.cast('int', o)

    @staticmethod
    def cffi_cgopy_cnv_py2c_float32(o):
        return ffi.cast('float', o)

    @staticmethod
    def cffi_cgopy_cnv_py2c_float64(o):
        return ffi.cast('double', o)

    @staticmethod
    def cffi_cgopy_cnv_py2c_uint(o):
        return ffi.cast('uint', o)

    @staticmethod
    def cffi_cgopy_cnv_c2py_bool(c):
        return bool(c)

    @staticmethod
    def cffi_cgopy_cnv_c2py_complex64(c):
         return complex(c.real, c.imag)

    @staticmethod
    def cffi_cgopy_cnv_c2py_complex128(c):
         return complex(c.real, c.imag)

    @staticmethod
    def cffi_cgopy_cnv_c2py_string(c):
        s = _cffi_helper.lib._cgopy_CString(c)
        pystr = ffi.string(s)
        _cffi_helper.lib._cgopy_FreeCString(s)
        if _PY3:
            pystr = pystr.decode('utf8')
        return pystr

    @staticmethod
    def cffi_cgopy_cnv_c2py_errstring(c):
        s = _cffi_helper.lib._cgopy_ErrorString(c)
        pystr = ffi.string(s)
        _cffi_helper.lib._cgopy_FreeCString(s)
        if _PY3:
            pystr = pystr.decode('utf8')
        return pystr

    @staticmethod
    def cffi_cgopy_cnv_c2py_int(c):
        return int(c)

    @staticmethod
    def cffi_cgopy_cnv_c2py_float32(c):
        return float(c)

    @staticmethod
    def cffi_cgopy_cnv_c2py_float64(c):
        return float(c)

    @staticmethod
    def cffi_cgopy_cnv_c2py_uint(c):
        return int(c)

    # converters for minclient_Client - Client
    @staticmethod
    def cffi_cgopy_cnv_py2c_minclient_Client(o):
        if type(o) is Client:
            return o.cgopy
    
    @staticmethod
    def cffi_cgopy_cnv_c2py_minclient_Client(c):
        o = Client()
        o.cgopy = c
        return o
    
    # converters for minclient_Key - Key
    @staticmethod
    def cffi_cgopy_cnv_py2c_minclient_Key(o):
        if type(o) is Key:
            return o.cgopy
    
    @staticmethod
    def cffi_cgopy_cnv_c2py_minclient_Key(c):
        o = Key()
        o.cgopy = c
        return o
    
    # converters for minclient_LogConfig - LogConfig
    @staticmethod
    def cffi_cgopy_cnv_py2c_minclient_LogConfig(o):
        if type(o) is LogConfig:
            return o.cgopy
    
    @staticmethod
    def cffi_cgopy_cnv_c2py_minclient_LogConfig(c):
        o = LogConfig()
        o.cgopy = c
        return o
    
    # converters for minclient_Session - Session
    @staticmethod
    def cffi_cgopy_cnv_py2c_minclient_Session(o):
        if type(o) is Session:
            return o.cgopy
    
    @staticmethod
    def cffi_cgopy_cnv_c2py_minclient_Session(c):
        o = Session()
        o.cgopy = c
        return o
    
    # converters for minclient_Client - Client
    @staticmethod
    def cffi_cgopy_cnv_py2c_minclient_Client(o):
        if type(o) is Client:
            return o.cgopy
    
    @staticmethod
    def cffi_cgopy_cnv_c2py_minclient_Client(c):
        o = Client()
        o.cgopy = c
        return o
    
    # converters for minclient_Key - Key
    @staticmethod
    def cffi_cgopy_cnv_py2c_minclient_Key(o):
        if type(o) is Key:
            return o.cgopy
    
    @staticmethod
    def cffi_cgopy_cnv_c2py_minclient_Key(c):
        o = Key()
        o.cgopy = c
        return o
    
    # converters for minclient_LogConfig - LogConfig
    @staticmethod
    def cffi_cgopy_cnv_py2c_minclient_LogConfig(o):
        if type(o) is LogConfig:
            return o.cgopy
    
    @staticmethod
    def cffi_cgopy_cnv_c2py_minclient_LogConfig(c):
        o = LogConfig()
        o.cgopy = c
        return o
    
    # converters for minclient_Session - Session
    @staticmethod
    def cffi_cgopy_cnv_py2c_minclient_Session(o):
        if type(o) is Session:
            return o.cgopy
    
    @staticmethod
    def cffi_cgopy_cnv_c2py_minclient_Session(c):
        o = Session()
        o.cgopy = c
        return o
    
    @staticmethod
    def cffi_cgopy_cnv_py2c_minclient_Client(o):
        return o.cgopy
        
    @staticmethod
    def cffi_cgopy_cnv_c2py_minclient_Client(c):
        o = Client()
        o.cgopy = ffi.gc(c, _cffi_helper.lib.cgopy_decref)
        return o
        
    @staticmethod
    def cffi_cgopy_cnv_py2c_minclient_Key(o):
        return o.cgopy
        
    @staticmethod
    def cffi_cgopy_cnv_c2py_minclient_Key(c):
        o = Key()
        o.cgopy = ffi.gc(c, _cffi_helper.lib.cgopy_decref)
        return o
        
    @staticmethod
    def cffi_cgopy_cnv_py2c_minclient_LogConfig(o):
        return o.cgopy
        
    @staticmethod
    def cffi_cgopy_cnv_c2py_minclient_LogConfig(c):
        o = LogConfig()
        o.cgopy = ffi.gc(c, _cffi_helper.lib.cgopy_decref)
        return o
        
    @staticmethod
    def cffi_cgopy_cnv_py2c_minclient_Session(o):
        return o.cgopy
        
    @staticmethod
    def cffi_cgopy_cnv_c2py_minclient_Session(c):
        o = Session()
        o.cgopy = ffi.gc(c, _cffi_helper.lib.cgopy_decref)
        return o
        
# make sure Cgo is loaded and initialized
_cffi_helper.lib.cgo_pkg_minclient_init()

# Python type for struct minclient.Client
class Client(object):
    """Client is katzenpost object\n"""
    def __init__(self, *args, **kwargs):
        cgopy = _cffi_helper.lib.cgo_func_minclient_Client_new()
        if cgopy == ffi.NULL:
            raise MemoryError('gopy: could not allocate Client.')
        self.cgopy = ffi.gc(cgopy, _cffi_helper.lib.cgopy_decref)
        
    
    
    #  pythonization of: minclient.NewSession
    def NewSession(self, user, provider, key):
        """NewSession(str user, str provider, object key) object, object\n\nNewSession stablishes a session with provider using key\n"""
        c_user = _cffi_helper.cffi_cgopy_cnv_py2c_string(user)
        c_provider = _cffi_helper.cffi_cgopy_cnv_py2c_string(provider)
        c_key = _cffi_helper.cffi_cgopy_cnv_py2c_minclient_Key(key)
        cret = _cffi_helper.lib.cgo_func_minclient_Client_NewSession(self.cgopy, c_user, c_provider, c_key)
        if not _cffi_helper.lib._cgopy_ErrorIsNil(cret.r1):
            py_err_str = _cffi_helper.cffi_cgopy_cnv_c2py_errstring(cret.r1)
            raise RuntimeError(py_err_str)
        r0 = _cffi_helper.cffi_cgopy_cnv_c2py_minclient_Session(cret.r0)
        return r0
    
    def __repr__(self):
        cret = _cffi_helper.lib.cgo_func_minclient_Client_str(self.cgopy)
        ret = _cffi_helper.cffi_cgopy_cnv_c2py_string(cret)
        return ret
        
    def __str__(self):
        cret = _cffi_helper.lib.cgo_func_minclient_Client_str(self.cgopy)
        ret = _cffi_helper.cffi_cgopy_cnv_c2py_string(cret)
        return ret
        

# Python type for struct minclient.Key
class Key(object):
    """Key keeps the key public and private data\n"""
    def __init__(self, *args, **kwargs):
        nkwds = len(kwargs)
        nargs = len(args)
        if nkwds + nargs > 2:
            raise TypeError('Key.__init__ takes at most 2 argument(s)')
        cgopy = _cffi_helper.lib.cgo_func_minclient_Key_new()
        if cgopy == ffi.NULL:
            raise MemoryError('gopy: could not allocate Key.')
        self.cgopy = ffi.gc(cgopy, _cffi_helper.lib.cgopy_decref)
        
        py_kwd_001 = None
        if  0 < nargs:
            py_kwd_001 = args[0]
        if "Private" in kwargs:
            py_kwd_001 = kwargs["Private"]
        if py_kwd_001 != None:
            if not isinstance(py_kwd_001, str):
                raise TypeError("invalid type for 'Private' attribute")
            c_kwd_001 = _cffi_helper.cffi_cgopy_cnv_py2c_string(py_kwd_001)
            _cffi_helper.lib.cgo_func_minclient_Key_setter_1(self.cgopy, c_kwd_001)
        py_kwd_002 = None
        if  1 < nargs:
            py_kwd_002 = args[1]
        if "Public" in kwargs:
            py_kwd_002 = kwargs["Public"]
        if py_kwd_002 != None:
            if not isinstance(py_kwd_002, str):
                raise TypeError("invalid type for 'Public' attribute")
            c_kwd_002 = _cffi_helper.cffi_cgopy_cnv_py2c_string(py_kwd_002)
            _cffi_helper.lib.cgo_func_minclient_Key_setter_2(self.cgopy, c_kwd_002)
    
    @property
    def Private(self):
        cret =  _cffi_helper.lib.cgo_func_minclient_Key_getter_1(self.cgopy)
        ret = _cffi_helper.cffi_cgopy_cnv_c2py_string(cret)
        return ret
        
    @Private.setter
    def Private(self, value):
        c_value = _cffi_helper.cffi_cgopy_cnv_py2c_string(value)
        _cffi_helper.lib.cgo_func_minclient_Key_setter_1(self.cgopy, c_value)
        
    @property
    def Public(self):
        cret =  _cffi_helper.lib.cgo_func_minclient_Key_getter_2(self.cgopy)
        ret = _cffi_helper.cffi_cgopy_cnv_c2py_string(cret)
        return ret
        
    @Public.setter
    def Public(self, value):
        c_value = _cffi_helper.cffi_cgopy_cnv_py2c_string(value)
        _cffi_helper.lib.cgo_func_minclient_Key_setter_2(self.cgopy, c_value)
        
    def __repr__(self):
        cret = _cffi_helper.lib.cgo_func_minclient_Key_str(self.cgopy)
        ret = _cffi_helper.cffi_cgopy_cnv_c2py_string(cret)
        return ret
        
    def __str__(self):
        cret = _cffi_helper.lib.cgo_func_minclient_Key_str(self.cgopy)
        ret = _cffi_helper.cffi_cgopy_cnv_c2py_string(cret)
        return ret
        

# Python type for struct minclient.LogConfig
class LogConfig(object):
    """LogConfig keeps the configuration of the loger\n"""
    def __init__(self, *args, **kwargs):
        nkwds = len(kwargs)
        nargs = len(args)
        if nkwds + nargs > 3:
            raise TypeError('LogConfig.__init__ takes at most 3 argument(s)')
        cgopy = _cffi_helper.lib.cgo_func_minclient_LogConfig_new()
        if cgopy == ffi.NULL:
            raise MemoryError('gopy: could not allocate LogConfig.')
        self.cgopy = ffi.gc(cgopy, _cffi_helper.lib.cgopy_decref)
        
        py_kwd_001 = None
        if  0 < nargs:
            py_kwd_001 = args[0]
        if "File" in kwargs:
            py_kwd_001 = kwargs["File"]
        if py_kwd_001 != None:
            if not isinstance(py_kwd_001, str):
                raise TypeError("invalid type for 'File' attribute")
            c_kwd_001 = _cffi_helper.cffi_cgopy_cnv_py2c_string(py_kwd_001)
            _cffi_helper.lib.cgo_func_minclient_LogConfig_setter_1(self.cgopy, c_kwd_001)
        py_kwd_002 = None
        if  1 < nargs:
            py_kwd_002 = args[1]
        if "Level" in kwargs:
            py_kwd_002 = kwargs["Level"]
        if py_kwd_002 != None:
            if not isinstance(py_kwd_002, str):
                raise TypeError("invalid type for 'Level' attribute")
            c_kwd_002 = _cffi_helper.cffi_cgopy_cnv_py2c_string(py_kwd_002)
            _cffi_helper.lib.cgo_func_minclient_LogConfig_setter_2(self.cgopy, c_kwd_002)
        py_kwd_003 = None
        if  2 < nargs:
            py_kwd_003 = args[2]
        if "Enabled" in kwargs:
            py_kwd_003 = kwargs["Enabled"]
        if py_kwd_003 != None:
            if not isinstance(py_kwd_003, bool):
                raise TypeError("invalid type for 'Enabled' attribute")
            c_kwd_003 = _cffi_helper.cffi_cgopy_cnv_py2c_bool(py_kwd_003)
            _cffi_helper.lib.cgo_func_minclient_LogConfig_setter_3(self.cgopy, c_kwd_003)
    
    @property
    def File(self):
        cret =  _cffi_helper.lib.cgo_func_minclient_LogConfig_getter_1(self.cgopy)
        ret = _cffi_helper.cffi_cgopy_cnv_c2py_string(cret)
        return ret
        
    @File.setter
    def File(self, value):
        c_value = _cffi_helper.cffi_cgopy_cnv_py2c_string(value)
        _cffi_helper.lib.cgo_func_minclient_LogConfig_setter_1(self.cgopy, c_value)
        
    @property
    def Level(self):
        cret =  _cffi_helper.lib.cgo_func_minclient_LogConfig_getter_2(self.cgopy)
        ret = _cffi_helper.cffi_cgopy_cnv_c2py_string(cret)
        return ret
        
    @Level.setter
    def Level(self, value):
        c_value = _cffi_helper.cffi_cgopy_cnv_py2c_string(value)
        _cffi_helper.lib.cgo_func_minclient_LogConfig_setter_2(self.cgopy, c_value)
        
    @property
    def Enabled(self):
        cret =  _cffi_helper.lib.cgo_func_minclient_LogConfig_getter_3(self.cgopy)
        ret = _cffi_helper.cffi_cgopy_cnv_c2py_bool(cret)
        return ret
        
    @Enabled.setter
    def Enabled(self, value):
        c_value = _cffi_helper.cffi_cgopy_cnv_py2c_bool(value)
        _cffi_helper.lib.cgo_func_minclient_LogConfig_setter_3(self.cgopy, c_value)
        
    def __repr__(self):
        cret = _cffi_helper.lib.cgo_func_minclient_LogConfig_str(self.cgopy)
        ret = _cffi_helper.cffi_cgopy_cnv_c2py_string(cret)
        return ret
        
    def __str__(self):
        cret = _cffi_helper.lib.cgo_func_minclient_LogConfig_str(self.cgopy)
        ret = _cffi_helper.cffi_cgopy_cnv_c2py_string(cret)
        return ret
        

# Python type for struct minclient.Session
class Session(object):
    """Session holds the client session\n"""
    def __init__(self, *args, **kwargs):
        cgopy = _cffi_helper.lib.cgo_func_minclient_Session_new()
        if cgopy == ffi.NULL:
            raise MemoryError('gopy: could not allocate Session.')
        self.cgopy = ffi.gc(cgopy, _cffi_helper.lib.cgopy_decref)
        
    
    
    #  pythonization of: minclient.GetMessage
    def GetMessage(self):
        """GetMessage() str\n\nGetMessage blocks until there is a message in the inbox\n"""
        cret = _cffi_helper.lib.cgo_func_minclient_Session_GetMessage(self.cgopy)
        ret = _cffi_helper.cffi_cgopy_cnv_c2py_string(cret)
        return ret
    
    
    #  pythonization of: minclient.SendMessage
    def SendMessage(self, recipient, provider, msg):
        """SendMessage(str recipient, str provider, str msg) object\n\nSendMessage into the mix network\n"""
        c_recipient = _cffi_helper.cffi_cgopy_cnv_py2c_string(recipient)
        c_provider = _cffi_helper.cffi_cgopy_cnv_py2c_string(provider)
        c_msg = _cffi_helper.cffi_cgopy_cnv_py2c_string(msg)
        cret = _cffi_helper.lib.cgo_func_minclient_Session_SendMessage(self.cgopy, c_recipient, c_provider, c_msg)
        if not _cffi_helper.lib._cgopy_ErrorIsNil(cret):
            py_err_str = _cffi_helper.cffi_cgopy_cnv_c2py_errstring(cret)
            raise RuntimeError(py_err_str)
        return
    
    
    #  pythonization of: minclient.Shutdown
    def Shutdown(self):
        """Shutdown() \n\nShutdown the session\n"""
        _cffi_helper.lib.cgo_func_minclient_Session_Shutdown(self.cgopy)
    
    def __repr__(self):
        cret = _cffi_helper.lib.cgo_func_minclient_Session_str(self.cgopy)
        ret = _cffi_helper.cffi_cgopy_cnv_c2py_string(cret)
        return ret
        
    def __str__(self):
        cret = _cffi_helper.lib.cgo_func_minclient_Session_str(self.cgopy)
        ret = _cffi_helper.cffi_cgopy_cnv_c2py_string(cret)
        return ret
        

# pythonization of: minclient.NewClient 
def NewClient(pkiAddress, pkiKey, logConfig):
    """NewClient(str pkiAddress, str pkiKey, object logConfig) object, object\n\nNewClient configures the pki to be used\n"""
    c_pkiAddress = _cffi_helper.cffi_cgopy_cnv_py2c_string(pkiAddress)
    c_pkiKey = _cffi_helper.cffi_cgopy_cnv_py2c_string(pkiKey)
    c_logConfig = _cffi_helper.cffi_cgopy_cnv_py2c_minclient_LogConfig(logConfig)
    cret = _cffi_helper.lib.cgo_func_minclient_NewClient(c_pkiAddress, c_pkiKey, c_logConfig)
    if not _cffi_helper.lib._cgopy_ErrorIsNil(cret.r1):
        py_err_str = _cffi_helper.cffi_cgopy_cnv_c2py_errstring(cret.r1)
        raise RuntimeError(py_err_str)
    r0 = _cffi_helper.cffi_cgopy_cnv_c2py_minclient_Client(cret.r0)
    return r0


# pythonization of: minclient.StringToKey 
def StringToKey(keyStr):
    """StringToKey(str keyStr) object, object\n\nStringToKey builds a Key from a string\n"""
    c_keyStr = _cffi_helper.cffi_cgopy_cnv_py2c_string(keyStr)
    cret = _cffi_helper.lib.cgo_func_minclient_StringToKey(c_keyStr)
    if not _cffi_helper.lib._cgopy_ErrorIsNil(cret.r1):
        py_err_str = _cffi_helper.cffi_cgopy_cnv_c2py_errstring(cret.r1)
        raise RuntimeError(py_err_str)
    r0 = _cffi_helper.cffi_cgopy_cnv_c2py_minclient_Key(cret.r0)
    return r0


# pythonization of: minclient.GenKey 
def GenKey():
    """GenKey() object, object\n\nGenKey creates a new ecdh key\n"""
    cret = _cffi_helper.lib.cgo_func_minclient_GenKey()
    if not _cffi_helper.lib._cgopy_ErrorIsNil(cret.r1):
        py_err_str = _cffi_helper.cffi_cgopy_cnv_c2py_errstring(cret.r1)
        raise RuntimeError(py_err_str)
    r0 = _cffi_helper.cffi_cgopy_cnv_c2py_minclient_Key(cret.r0)
    return r0

