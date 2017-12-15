/*
  C stubs for package minclient.
  gopy gen -lang=python minclient

  File is generated by gopy gen. Do not edit.
*/

#ifdef _POSIX_C_SOURCE
#undef _POSIX_C_SOURCE
#endif

#include "Python.h"
#include "structmember.h"
#include "memoryobject.h"
#include "bufferobject.h"

// header exported from 'go tool cgo'
#include "minclient.h"

#if PY_VERSION_HEX > 0x03000000
#error "Python-3 is not yet supported by gopy"
#endif


// --- gopy object model ---

struct _gopy_object;

// empty interface converter
typedef GoInterface (*gopy_efacefunc)(struct _gopy_object *);


// proxy for all go values
struct _gopy_object {
	PyObject_HEAD
	void *go; /* handle to address of go value */
	gopy_efacefunc eface;
};

typedef struct _gopy_object gopy_object;

// --- gopy object model ---


// helpers for cgopy

#define def_cnv(name, c2py, py2c, gotype) \
	static int \
	cgopy_cnv_py2c_ ## name(PyObject *o, gotype *addr) { \
		*addr = py2c(o); \
		return 1;	\
	} \
	\
	static PyObject* \
	cgopy_cnv_c2py_ ## name(gotype *addr) { \
		return c2py(*addr); \
	} 

#if (GOINTBITS == 4)
	def_cnv( int,  PyLong_FromLong,         PyLong_AsLong,         GoInt)
	def_cnv(uint,  PyLong_FromUnsignedLong, PyLong_AsUnsignedLong, GoUint)
#else
	def_cnv( int,  PyInt_FromLong, PyInt_AsLong, GoInt)
	def_cnv(uint,  PyInt_FromLong, PyInt_AsLong, GoUint)
#endif

def_cnv(  int8, PyInt_FromLong, PyInt_AsLong, GoInt8)
def_cnv( int16, PyInt_FromLong, PyInt_AsLong, GoInt16)
def_cnv( int32, PyInt_FromLong, PyInt_AsLong, GoInt32)
def_cnv( int64, PyLong_FromLong, PyLong_AsLong, GoInt64)
def_cnv(uint8,  PyInt_FromLong, PyInt_AsLong, GoUint8)
def_cnv(uint16, PyInt_FromLong, PyInt_AsLong, GoUint16)
def_cnv(uint32, PyInt_FromLong, PyInt_AsLong, GoUint32)
def_cnv(uint64, PyLong_FromUnsignedLong, PyLong_AsUnsignedLong, GoUint64)

def_cnv(float64, PyFloat_FromDouble, PyFloat_AsDouble, GoFloat64)

#undef def_cnv

static int
cgopy_cnv_py2c_bool(PyObject *o, GoUint8 *addr) {
	*addr = (o == Py_True) ? 1 : 0;
	return 1;
}

static PyObject*
cgopy_cnv_c2py_bool(GoUint8 *addr) {
	long v = *addr;
	return PyBool_FromLong(v);
}

static int
cgopy_cnv_py2c_string(PyObject *o, GoString *addr) {
	const char *str = PyString_AsString(o);
	if (str == NULL) {
		return 0;
	}
	*addr = _cgopy_GoString((char*)str);
	return 1;
}

static PyObject*
cgopy_cnv_c2py_string(GoString *addr) {
	const char *str = _cgopy_CString(*addr);
	PyObject *pystr = PyString_FromString(str);
	free((void*)str);
	return pystr;
}

static int
cgopy_cnv_py2c_float32(PyObject *o, GoFloat32 *addr) {
	GoFloat32 v = PyFloat_AsDouble(o);
	*addr = v;
	return 1;
}

static PyObject*
cgopy_cnv_c2py_float32(GoFloat32 *addr) {
	GoFloat64 v = *addr;
	return PyFloat_FromDouble(v);
}

static int
cgopy_cnv_py2c_complex64(PyObject *o, GoComplex64 *addr) {
	Py_complex v = PyComplex_AsCComplex(o);
	*addr = v.real + v.imag * _Complex_I;
	return 1;
}

static PyObject*
cgopy_cnv_c2py_complex64(GoComplex64 *addr) {
	return PyComplex_FromDoubles(creal(*addr), cimag(*addr));
}

static int
cgopy_cnv_py2c_complex128(PyObject *o, GoComplex128 *addr) {
	Py_complex v = PyComplex_AsCComplex(o);
	*addr = v.real + v.imag * _Complex_I;
	return 1;
}

static PyObject*
cgopy_cnv_c2py_complex128(GoComplex128 *addr) {
	return PyComplex_FromDoubles(creal(*addr), cimag(*addr));
}

/* --- decls for struct minclient.Client --- */
typedef void* cgo_type_minclient_Client;

/* Python type for struct minclient.Client
 */
typedef struct {
	PyObject_HEAD
	cgo_type_minclient_Client cgopy; /* unsafe.Pointer to minclient_Client */
	gopy_efacefunc eface;
} cpy_type_minclient_Client;



/* tp_new for minclient.Client */
static PyObject*
cpy_func_minclient_Client_new(PyTypeObject *type, PyObject *args, PyObject *kwds);

/* tp_dealloc for minclient.Client */
static void
cpy_type_minclient_Client_dealloc(cpy_type_minclient_Client *self);

/* tp_init for minclient.Client */
static int
cpy_func_minclient_Client_init(cpy_type_minclient_Client *self, PyObject *args, PyObject *kwds);

/* tp_getset for minclient.Client */

/* methods for minclient.Client */

/* wrapping minclient.Client.NewSession */
static PyObject*
cpy_func_minclient_Client_NewSession(cpy_type_minclient_Client *self, PyObject *args, PyObject *kwds);

/* __str__ support for minclient.Client */
static PyObject*
cpy_func_minclient_Client_tp_str(PyObject *self);

/* converters for minclient_Client - Client */
static int
cgopy_cnv_py2c_minclient_Client(PyObject *o, cgo_type_minclient_Client *addr);
static PyObject*
cgopy_cnv_c2py_minclient_Client(cgo_type_minclient_Client *addr);


/* check-type function for minclient.Client */
static int
cpy_func_minclient_Client_check(PyObject *self);

/* --- decls for struct minclient.Key --- */
typedef void* cgo_type_minclient_Key;

/* Python type for struct minclient.Key
 */
typedef struct {
	PyObject_HEAD
	cgo_type_minclient_Key cgopy; /* unsafe.Pointer to minclient_Key */
	gopy_efacefunc eface;
} cpy_type_minclient_Key;



/* tp_new for minclient.Key */
static PyObject*
cpy_func_minclient_Key_new(PyTypeObject *type, PyObject *args, PyObject *kwds);

/* tp_dealloc for minclient.Key */
static void
cpy_type_minclient_Key_dealloc(cpy_type_minclient_Key *self);

/* tp_init for minclient.Key */
static int
cpy_func_minclient_Key_init(cpy_type_minclient_Key *self, PyObject *args, PyObject *kwds);

/* tp_getset for minclient.Key */

/* getter for minclient.Key.Private */
static PyObject*
cpy_func_minclient_Key_getter_1(cpy_type_minclient_Key *self, void *closure); /* Private */

/* setter for minclient.Key.Private */
static int
cpy_func_minclient_Key_setter_1(cpy_type_minclient_Key *self, PyObject *value, void *closure);

/* getter for minclient.Key.Public */
static PyObject*
cpy_func_minclient_Key_getter_2(cpy_type_minclient_Key *self, void *closure); /* Public */

/* setter for minclient.Key.Public */
static int
cpy_func_minclient_Key_setter_2(cpy_type_minclient_Key *self, PyObject *value, void *closure);

/* methods for minclient.Key */

/* __str__ support for minclient.Key */
static PyObject*
cpy_func_minclient_Key_tp_str(PyObject *self);

/* converters for minclient_Key - Key */
static int
cgopy_cnv_py2c_minclient_Key(PyObject *o, cgo_type_minclient_Key *addr);
static PyObject*
cgopy_cnv_c2py_minclient_Key(cgo_type_minclient_Key *addr);


/* check-type function for minclient.Key */
static int
cpy_func_minclient_Key_check(PyObject *self);

/* --- decls for struct minclient.LogConfig --- */
typedef void* cgo_type_minclient_LogConfig;

/* Python type for struct minclient.LogConfig
 */
typedef struct {
	PyObject_HEAD
	cgo_type_minclient_LogConfig cgopy; /* unsafe.Pointer to minclient_LogConfig */
	gopy_efacefunc eface;
} cpy_type_minclient_LogConfig;



/* tp_new for minclient.LogConfig */
static PyObject*
cpy_func_minclient_LogConfig_new(PyTypeObject *type, PyObject *args, PyObject *kwds);

/* tp_dealloc for minclient.LogConfig */
static void
cpy_type_minclient_LogConfig_dealloc(cpy_type_minclient_LogConfig *self);

/* tp_init for minclient.LogConfig */
static int
cpy_func_minclient_LogConfig_init(cpy_type_minclient_LogConfig *self, PyObject *args, PyObject *kwds);

/* tp_getset for minclient.LogConfig */

/* getter for minclient.LogConfig.File */
static PyObject*
cpy_func_minclient_LogConfig_getter_1(cpy_type_minclient_LogConfig *self, void *closure); /* File */

/* setter for minclient.LogConfig.File */
static int
cpy_func_minclient_LogConfig_setter_1(cpy_type_minclient_LogConfig *self, PyObject *value, void *closure);

/* getter for minclient.LogConfig.Level */
static PyObject*
cpy_func_minclient_LogConfig_getter_2(cpy_type_minclient_LogConfig *self, void *closure); /* Level */

/* setter for minclient.LogConfig.Level */
static int
cpy_func_minclient_LogConfig_setter_2(cpy_type_minclient_LogConfig *self, PyObject *value, void *closure);

/* getter for minclient.LogConfig.Enabled */
static PyObject*
cpy_func_minclient_LogConfig_getter_3(cpy_type_minclient_LogConfig *self, void *closure); /* Enabled */

/* setter for minclient.LogConfig.Enabled */
static int
cpy_func_minclient_LogConfig_setter_3(cpy_type_minclient_LogConfig *self, PyObject *value, void *closure);

/* methods for minclient.LogConfig */

/* __str__ support for minclient.LogConfig */
static PyObject*
cpy_func_minclient_LogConfig_tp_str(PyObject *self);

/* converters for minclient_LogConfig - LogConfig */
static int
cgopy_cnv_py2c_minclient_LogConfig(PyObject *o, cgo_type_minclient_LogConfig *addr);
static PyObject*
cgopy_cnv_c2py_minclient_LogConfig(cgo_type_minclient_LogConfig *addr);


/* check-type function for minclient.LogConfig */
static int
cpy_func_minclient_LogConfig_check(PyObject *self);

/* --- decls for struct minclient.Session --- */
typedef void* cgo_type_minclient_Session;

/* Python type for struct minclient.Session
 */
typedef struct {
	PyObject_HEAD
	cgo_type_minclient_Session cgopy; /* unsafe.Pointer to minclient_Session */
	gopy_efacefunc eface;
} cpy_type_minclient_Session;



/* tp_new for minclient.Session */
static PyObject*
cpy_func_minclient_Session_new(PyTypeObject *type, PyObject *args, PyObject *kwds);

/* tp_dealloc for minclient.Session */
static void
cpy_type_minclient_Session_dealloc(cpy_type_minclient_Session *self);

/* tp_init for minclient.Session */
static int
cpy_func_minclient_Session_init(cpy_type_minclient_Session *self, PyObject *args, PyObject *kwds);

/* tp_getset for minclient.Session */

/* methods for minclient.Session */

/* wrapping minclient.Session.GetMessage */
static PyObject*
cpy_func_minclient_Session_GetMessage(cpy_type_minclient_Session *self, PyObject *args, PyObject *kwds);

/* wrapping minclient.Session.SendMessage */
static PyObject*
cpy_func_minclient_Session_SendMessage(cpy_type_minclient_Session *self, PyObject *args, PyObject *kwds);

/* wrapping minclient.Session.Shutdown */
static PyObject*
cpy_func_minclient_Session_Shutdown(cpy_type_minclient_Session *self, PyObject *args, PyObject *kwds);

/* __str__ support for minclient.Session */
static PyObject*
cpy_func_minclient_Session_tp_str(PyObject *self);

/* converters for minclient_Session - Session */
static int
cgopy_cnv_py2c_minclient_Session(PyObject *o, cgo_type_minclient_Session *addr);
static PyObject*
cgopy_cnv_c2py_minclient_Session(cgo_type_minclient_Session *addr);


/* check-type function for minclient.Session */
static int
cpy_func_minclient_Session_check(PyObject *self);


/* --- impl for minclient.Client */


/* tp_new */
static PyObject*
cpy_func_minclient_Client_new(PyTypeObject *type, PyObject *args, PyObject *kwds) {
	cpy_type_minclient_Client *self;
	self = (cpy_type_minclient_Client *)type->tp_alloc(type, 0);
	self->cgopy = cgo_func_minclient_Client_new();
	self->eface = (gopy_efacefunc)cgo_func_minclient_Client_eface;
	return (PyObject*)self;
}


/* tp_dealloc for minclient.Client */
static void
cpy_type_minclient_Client_dealloc(cpy_type_minclient_Client *self) {
	cgopy_decref((cgo_type_minclient_Client)(self->cgopy));
	self->ob_type->tp_free((PyObject*)self);
}


/* tp_init */
static int
cpy_func_minclient_Client_init(cpy_type_minclient_Client *self, PyObject *args, PyObject *kwds) {
	return 0;

cpy_label_cpy_type_minclient_Client_init_fail:
	
	return -1;
}


/* tp_getset for minclient.Client */
static PyGetSetDef cpy_type_minclient_Client_getsets[] = {
	{NULL} /* Sentinel */
};


/* wrapping minclient.Client.NewSession */
static PyObject*
cpy_func_minclient_Client_NewSession(cpy_type_minclient_Client *self, PyObject *args, PyObject *kwds) {
	GoString arg000;
	GoString arg001;
	cgo_type_minclient_Key arg002;
	struct cgo_func_minclient_Client_NewSession_return ret;
	
	if (!PyArg_ParseTuple(args, "O&O&O&", cgopy_cnv_py2c_string, &arg000, cgopy_cnv_py2c_string, &arg001, cgopy_cnv_py2c_minclient_Key, &arg002)) {
		return NULL;
	}
	
	ret = cgo_func_minclient_Client_NewSession(self->cgopy, arg000, arg001, arg002);
	
	if (!_cgopy_ErrorIsNil(ret.r1)) {
		const char* c_err_str = _cgopy_ErrorString(ret.r1);
		PyErr_SetString(PyExc_RuntimeError, c_err_str);
		free((void*)c_err_str);
		return NULL;
	}
	
	return cgopy_cnv_c2py_minclient_Session(&ret.r0);
}


/* methods for minclient.Client */
static PyMethodDef cpy_type_minclient_Client_methods[] = {
	{"NewSession", (PyCFunction)cpy_func_minclient_Client_NewSession, METH_VARARGS, "NewSession(str user, str provider, object key) object, object\n\nNewSession stablishes a session with provider using key\n"},
	{NULL} /* sentinel */
};

static PyObject*
cpy_func_minclient_Client_tp_str(PyObject *self) {
	cgo_type_minclient_Client c_self = ((cpy_type_minclient_Client*)self)->cgopy;
	GoString str = cgo_func_minclient_Client_str(c_self);
	return cgopy_cnv_c2py_string(&str);
}

static PyTypeObject cpy_type_minclient_ClientType = {
	PyObject_HEAD_INIT(NULL)
	0,	/*ob_size*/
	"Client",	/*tp_name*/
	sizeof(cpy_type_minclient_Client),	/*tp_basicsize*/
	0,	/*tp_itemsize*/
	(destructor)cpy_type_minclient_Client_dealloc,	/*tp_dealloc*/
	0,	/*tp_print*/
	0,	/*tp_getattr*/
	0,	/*tp_setattr*/
	0,	/*tp_compare*/
	0,	/*tp_repr*/
	0,	/*tp_as_number*/
	0,	/*tp_as_sequence*/
	0,	/*tp_as_mapping*/
	0,	/*tp_hash */
	0,	/*tp_call*/
	cpy_func_minclient_Client_tp_str,	/*tp_str*/
	0,	/*tp_getattro*/
	0,	/*tp_setattro*/
	0,	/*tp_as_buffer*/
	Py_TPFLAGS_DEFAULT,	/*tp_flags*/
	"Client is katzenpost object\n",	/* tp_doc */
	0,	/* tp_traverse */
	0,	/* tp_clear */
	0,	/* tp_richcompare */
	0,	/* tp_weaklistoffset */
	0,	/* tp_iter */
	0,	/* tp_iternext */
	cpy_type_minclient_Client_methods,             /* tp_methods */
	0,	/* tp_members */
	cpy_type_minclient_Client_getsets,	/* tp_getset */
	0,	/* tp_base */
	0,	/* tp_dict */
	0,	/* tp_descr_get */
	0,	/* tp_descr_set */
	0,	/* tp_dictoffset */
	(initproc)cpy_func_minclient_Client_init,      /* tp_init */
	0,                         /* tp_alloc */
	cpy_func_minclient_Client_new,	/* tp_new */
};

static int
cgopy_cnv_py2c_minclient_Client(PyObject *o, cgo_type_minclient_Client *addr) {
	cpy_type_minclient_Client *self = NULL;
	self = (cpy_type_minclient_Client *)o;
	*addr = self->cgopy;
	return 1;
}

static PyObject*
cgopy_cnv_c2py_minclient_Client(cgo_type_minclient_Client *addr) {
	PyObject *o = cpy_func_minclient_Client_new(&cpy_type_minclient_ClientType, 0, 0);
	if (o == NULL) {
		return NULL;
	}
	((cpy_type_minclient_Client*)o)->cgopy = *addr;
	return o;
}


/* check-type function for minclient.Client */
static int
cpy_func_minclient_Client_check(PyObject *self) {
	return PyObject_TypeCheck(self, &cpy_type_minclient_ClientType);
}



/* --- impl for minclient.Key */


/* tp_new */
static PyObject*
cpy_func_minclient_Key_new(PyTypeObject *type, PyObject *args, PyObject *kwds) {
	cpy_type_minclient_Key *self;
	self = (cpy_type_minclient_Key *)type->tp_alloc(type, 0);
	self->cgopy = cgo_func_minclient_Key_new();
	self->eface = (gopy_efacefunc)cgo_func_minclient_Key_eface;
	return (PyObject*)self;
}


/* tp_dealloc for minclient.Key */
static void
cpy_type_minclient_Key_dealloc(cpy_type_minclient_Key *self) {
	cgopy_decref((cgo_type_minclient_Key)(self->cgopy));
	self->ob_type->tp_free((PyObject*)self);
}


/* tp_init */
static int
cpy_func_minclient_Key_init(cpy_type_minclient_Key *self, PyObject *args, PyObject *kwds) {
	static char *kwlist[] = {
		"Private", /* py_kwd_000 */
		"Public", /* py_kwd_001 */
		NULL
	};
	PyObject *py_kwd_000 = NULL;
	PyObject *py_kwd_001 = NULL;
	Py_ssize_t nkwds = (kwds != NULL) ? PyDict_Size(kwds) : 0;
	Py_ssize_t nargs = (args != NULL) ? PySequence_Size(args) : 0;
	if ((nkwds + nargs) > 2) {
		PyErr_SetString(PyExc_TypeError, "Key.__init__ takes at most 2 argument(s)");
		goto cpy_label_cpy_type_minclient_Key_init_fail;
	}
	
	if (!PyArg_ParseTupleAndKeywords(args, kwds, "|OO", kwlist, &py_kwd_000, &py_kwd_001)) {
		goto cpy_label_cpy_type_minclient_Key_init_fail;
	}
	
	if (py_kwd_000 != NULL) {
		if (cpy_func_minclient_Key_setter_1(self, py_kwd_000, NULL)) {
			goto cpy_label_cpy_type_minclient_Key_init_fail;
		}
		
	}
	
	if (py_kwd_001 != NULL) {
		if (cpy_func_minclient_Key_setter_2(self, py_kwd_001, NULL)) {
			goto cpy_label_cpy_type_minclient_Key_init_fail;
		}
		
	}
	
	return 0;

cpy_label_cpy_type_minclient_Key_init_fail:
	Py_XDECREF(py_kwd_000);
	Py_XDECREF(py_kwd_001);
	
	return -1;
}


/* getter for minclient.Key.Private */
static PyObject*
cpy_func_minclient_Key_getter_1(cpy_type_minclient_Key *self, void *closure) /* Private */ {
	PyObject *o = NULL;
	GoString c_ret = cgo_func_minclient_Key_getter_1(self->cgopy); /*wrap*/
	o = Py_BuildValue("O&", cgopy_cnv_c2py_string, &c_ret);
	return o;
}


/* setter for minclient.Key.Private */
static int
cpy_func_minclient_Key_setter_1(cpy_type_minclient_Key *self, PyObject *value, void *closure) {
	GoString c_ret;
	if (value == NULL) {
		PyErr_SetString(PyExc_TypeError, "cannot delete 'Private' attribute");
		return -1;
	}
	
	if (!PyString_Check(value)) {
		PyErr_SetString(PyExc_TypeError, "invalid type for 'Private' attribute");
		return -1;
	}
	
	if (!cgopy_cnv_py2c_string(value, &c_ret)) {
		return -1;
	}
	
	cgo_func_minclient_Key_setter_1((cgo_type_minclient_Key)(self->cgopy), c_ret);
	return 0;
}


/* getter for minclient.Key.Public */
static PyObject*
cpy_func_minclient_Key_getter_2(cpy_type_minclient_Key *self, void *closure) /* Public */ {
	PyObject *o = NULL;
	GoString c_ret = cgo_func_minclient_Key_getter_2(self->cgopy); /*wrap*/
	o = Py_BuildValue("O&", cgopy_cnv_c2py_string, &c_ret);
	return o;
}


/* setter for minclient.Key.Public */
static int
cpy_func_minclient_Key_setter_2(cpy_type_minclient_Key *self, PyObject *value, void *closure) {
	GoString c_ret;
	if (value == NULL) {
		PyErr_SetString(PyExc_TypeError, "cannot delete 'Public' attribute");
		return -1;
	}
	
	if (!PyString_Check(value)) {
		PyErr_SetString(PyExc_TypeError, "invalid type for 'Public' attribute");
		return -1;
	}
	
	if (!cgopy_cnv_py2c_string(value, &c_ret)) {
		return -1;
	}
	
	cgo_func_minclient_Key_setter_2((cgo_type_minclient_Key)(self->cgopy), c_ret);
	return 0;
}


/* tp_getset for minclient.Key */
static PyGetSetDef cpy_type_minclient_Key_getsets[] = {
	{"Private", (getter)cpy_func_minclient_Key_getter_1, (setter)cpy_func_minclient_Key_setter_1, "doc for Private", NULL},
	{"Public", (getter)cpy_func_minclient_Key_getter_2, (setter)cpy_func_minclient_Key_setter_2, "doc for Public", NULL},
	{NULL} /* Sentinel */
};


/* methods for minclient.Key */
static PyMethodDef cpy_type_minclient_Key_methods[] = {
	{NULL} /* sentinel */
};

static PyObject*
cpy_func_minclient_Key_tp_str(PyObject *self) {
	cgo_type_minclient_Key c_self = ((cpy_type_minclient_Key*)self)->cgopy;
	GoString str = cgo_func_minclient_Key_str(c_self);
	return cgopy_cnv_c2py_string(&str);
}

static PyTypeObject cpy_type_minclient_KeyType = {
	PyObject_HEAD_INIT(NULL)
	0,	/*ob_size*/
	"Key",	/*tp_name*/
	sizeof(cpy_type_minclient_Key),	/*tp_basicsize*/
	0,	/*tp_itemsize*/
	(destructor)cpy_type_minclient_Key_dealloc,	/*tp_dealloc*/
	0,	/*tp_print*/
	0,	/*tp_getattr*/
	0,	/*tp_setattr*/
	0,	/*tp_compare*/
	0,	/*tp_repr*/
	0,	/*tp_as_number*/
	0,	/*tp_as_sequence*/
	0,	/*tp_as_mapping*/
	0,	/*tp_hash */
	0,	/*tp_call*/
	cpy_func_minclient_Key_tp_str,	/*tp_str*/
	0,	/*tp_getattro*/
	0,	/*tp_setattro*/
	0,	/*tp_as_buffer*/
	Py_TPFLAGS_DEFAULT,	/*tp_flags*/
	"Key keeps the key public and private data\n",	/* tp_doc */
	0,	/* tp_traverse */
	0,	/* tp_clear */
	0,	/* tp_richcompare */
	0,	/* tp_weaklistoffset */
	0,	/* tp_iter */
	0,	/* tp_iternext */
	cpy_type_minclient_Key_methods,             /* tp_methods */
	0,	/* tp_members */
	cpy_type_minclient_Key_getsets,	/* tp_getset */
	0,	/* tp_base */
	0,	/* tp_dict */
	0,	/* tp_descr_get */
	0,	/* tp_descr_set */
	0,	/* tp_dictoffset */
	(initproc)cpy_func_minclient_Key_init,      /* tp_init */
	0,                         /* tp_alloc */
	cpy_func_minclient_Key_new,	/* tp_new */
};

static int
cgopy_cnv_py2c_minclient_Key(PyObject *o, cgo_type_minclient_Key *addr) {
	cpy_type_minclient_Key *self = NULL;
	self = (cpy_type_minclient_Key *)o;
	*addr = self->cgopy;
	return 1;
}

static PyObject*
cgopy_cnv_c2py_minclient_Key(cgo_type_minclient_Key *addr) {
	PyObject *o = cpy_func_minclient_Key_new(&cpy_type_minclient_KeyType, 0, 0);
	if (o == NULL) {
		return NULL;
	}
	((cpy_type_minclient_Key*)o)->cgopy = *addr;
	return o;
}


/* check-type function for minclient.Key */
static int
cpy_func_minclient_Key_check(PyObject *self) {
	return PyObject_TypeCheck(self, &cpy_type_minclient_KeyType);
}



/* --- impl for minclient.LogConfig */


/* tp_new */
static PyObject*
cpy_func_minclient_LogConfig_new(PyTypeObject *type, PyObject *args, PyObject *kwds) {
	cpy_type_minclient_LogConfig *self;
	self = (cpy_type_minclient_LogConfig *)type->tp_alloc(type, 0);
	self->cgopy = cgo_func_minclient_LogConfig_new();
	self->eface = (gopy_efacefunc)cgo_func_minclient_LogConfig_eface;
	return (PyObject*)self;
}


/* tp_dealloc for minclient.LogConfig */
static void
cpy_type_minclient_LogConfig_dealloc(cpy_type_minclient_LogConfig *self) {
	cgopy_decref((cgo_type_minclient_LogConfig)(self->cgopy));
	self->ob_type->tp_free((PyObject*)self);
}


/* tp_init */
static int
cpy_func_minclient_LogConfig_init(cpy_type_minclient_LogConfig *self, PyObject *args, PyObject *kwds) {
	static char *kwlist[] = {
		"File", /* py_kwd_000 */
		"Level", /* py_kwd_001 */
		"Enabled", /* py_kwd_002 */
		NULL
	};
	PyObject *py_kwd_000 = NULL;
	PyObject *py_kwd_001 = NULL;
	PyObject *py_kwd_002 = NULL;
	Py_ssize_t nkwds = (kwds != NULL) ? PyDict_Size(kwds) : 0;
	Py_ssize_t nargs = (args != NULL) ? PySequence_Size(args) : 0;
	if ((nkwds + nargs) > 3) {
		PyErr_SetString(PyExc_TypeError, "LogConfig.__init__ takes at most 3 argument(s)");
		goto cpy_label_cpy_type_minclient_LogConfig_init_fail;
	}
	
	if (!PyArg_ParseTupleAndKeywords(args, kwds, "|OOO", kwlist, &py_kwd_000, &py_kwd_001, &py_kwd_002)) {
		goto cpy_label_cpy_type_minclient_LogConfig_init_fail;
	}
	
	if (py_kwd_000 != NULL) {
		if (cpy_func_minclient_LogConfig_setter_1(self, py_kwd_000, NULL)) {
			goto cpy_label_cpy_type_minclient_LogConfig_init_fail;
		}
		
	}
	
	if (py_kwd_001 != NULL) {
		if (cpy_func_minclient_LogConfig_setter_2(self, py_kwd_001, NULL)) {
			goto cpy_label_cpy_type_minclient_LogConfig_init_fail;
		}
		
	}
	
	if (py_kwd_002 != NULL) {
		if (cpy_func_minclient_LogConfig_setter_3(self, py_kwd_002, NULL)) {
			goto cpy_label_cpy_type_minclient_LogConfig_init_fail;
		}
		
	}
	
	return 0;

cpy_label_cpy_type_minclient_LogConfig_init_fail:
	Py_XDECREF(py_kwd_000);
	Py_XDECREF(py_kwd_001);
	Py_XDECREF(py_kwd_002);
	
	return -1;
}


/* getter for minclient.LogConfig.File */
static PyObject*
cpy_func_minclient_LogConfig_getter_1(cpy_type_minclient_LogConfig *self, void *closure) /* File */ {
	PyObject *o = NULL;
	GoString c_ret = cgo_func_minclient_LogConfig_getter_1(self->cgopy); /*wrap*/
	o = Py_BuildValue("O&", cgopy_cnv_c2py_string, &c_ret);
	return o;
}


/* setter for minclient.LogConfig.File */
static int
cpy_func_minclient_LogConfig_setter_1(cpy_type_minclient_LogConfig *self, PyObject *value, void *closure) {
	GoString c_ret;
	if (value == NULL) {
		PyErr_SetString(PyExc_TypeError, "cannot delete 'File' attribute");
		return -1;
	}
	
	if (!PyString_Check(value)) {
		PyErr_SetString(PyExc_TypeError, "invalid type for 'File' attribute");
		return -1;
	}
	
	if (!cgopy_cnv_py2c_string(value, &c_ret)) {
		return -1;
	}
	
	cgo_func_minclient_LogConfig_setter_1((cgo_type_minclient_LogConfig)(self->cgopy), c_ret);
	return 0;
}


/* getter for minclient.LogConfig.Level */
static PyObject*
cpy_func_minclient_LogConfig_getter_2(cpy_type_minclient_LogConfig *self, void *closure) /* Level */ {
	PyObject *o = NULL;
	GoString c_ret = cgo_func_minclient_LogConfig_getter_2(self->cgopy); /*wrap*/
	o = Py_BuildValue("O&", cgopy_cnv_c2py_string, &c_ret);
	return o;
}


/* setter for minclient.LogConfig.Level */
static int
cpy_func_minclient_LogConfig_setter_2(cpy_type_minclient_LogConfig *self, PyObject *value, void *closure) {
	GoString c_ret;
	if (value == NULL) {
		PyErr_SetString(PyExc_TypeError, "cannot delete 'Level' attribute");
		return -1;
	}
	
	if (!PyString_Check(value)) {
		PyErr_SetString(PyExc_TypeError, "invalid type for 'Level' attribute");
		return -1;
	}
	
	if (!cgopy_cnv_py2c_string(value, &c_ret)) {
		return -1;
	}
	
	cgo_func_minclient_LogConfig_setter_2((cgo_type_minclient_LogConfig)(self->cgopy), c_ret);
	return 0;
}


/* getter for minclient.LogConfig.Enabled */
static PyObject*
cpy_func_minclient_LogConfig_getter_3(cpy_type_minclient_LogConfig *self, void *closure) /* Enabled */ {
	PyObject *o = NULL;
	GoUint8 c_ret = cgo_func_minclient_LogConfig_getter_3(self->cgopy); /*wrap*/
	o = Py_BuildValue("O&", cgopy_cnv_c2py_bool, &c_ret);
	return o;
}


/* setter for minclient.LogConfig.Enabled */
static int
cpy_func_minclient_LogConfig_setter_3(cpy_type_minclient_LogConfig *self, PyObject *value, void *closure) {
	GoUint8 c_ret;
	if (value == NULL) {
		PyErr_SetString(PyExc_TypeError, "cannot delete 'Enabled' attribute");
		return -1;
	}
	
	if (!PyBool_Check(value)) {
		PyErr_SetString(PyExc_TypeError, "invalid type for 'Enabled' attribute");
		return -1;
	}
	
	if (!cgopy_cnv_py2c_bool(value, &c_ret)) {
		return -1;
	}
	
	cgo_func_minclient_LogConfig_setter_3((cgo_type_minclient_LogConfig)(self->cgopy), c_ret);
	return 0;
}


/* tp_getset for minclient.LogConfig */
static PyGetSetDef cpy_type_minclient_LogConfig_getsets[] = {
	{"File", (getter)cpy_func_minclient_LogConfig_getter_1, (setter)cpy_func_minclient_LogConfig_setter_1, "doc for File", NULL},
	{"Level", (getter)cpy_func_minclient_LogConfig_getter_2, (setter)cpy_func_minclient_LogConfig_setter_2, "doc for Level", NULL},
	{"Enabled", (getter)cpy_func_minclient_LogConfig_getter_3, (setter)cpy_func_minclient_LogConfig_setter_3, "doc for Enabled", NULL},
	{NULL} /* Sentinel */
};


/* methods for minclient.LogConfig */
static PyMethodDef cpy_type_minclient_LogConfig_methods[] = {
	{NULL} /* sentinel */
};

static PyObject*
cpy_func_minclient_LogConfig_tp_str(PyObject *self) {
	cgo_type_minclient_LogConfig c_self = ((cpy_type_minclient_LogConfig*)self)->cgopy;
	GoString str = cgo_func_minclient_LogConfig_str(c_self);
	return cgopy_cnv_c2py_string(&str);
}

static PyTypeObject cpy_type_minclient_LogConfigType = {
	PyObject_HEAD_INIT(NULL)
	0,	/*ob_size*/
	"LogConfig",	/*tp_name*/
	sizeof(cpy_type_minclient_LogConfig),	/*tp_basicsize*/
	0,	/*tp_itemsize*/
	(destructor)cpy_type_minclient_LogConfig_dealloc,	/*tp_dealloc*/
	0,	/*tp_print*/
	0,	/*tp_getattr*/
	0,	/*tp_setattr*/
	0,	/*tp_compare*/
	0,	/*tp_repr*/
	0,	/*tp_as_number*/
	0,	/*tp_as_sequence*/
	0,	/*tp_as_mapping*/
	0,	/*tp_hash */
	0,	/*tp_call*/
	cpy_func_minclient_LogConfig_tp_str,	/*tp_str*/
	0,	/*tp_getattro*/
	0,	/*tp_setattro*/
	0,	/*tp_as_buffer*/
	Py_TPFLAGS_DEFAULT,	/*tp_flags*/
	"LogConfig keeps the configuration of the loger\n",	/* tp_doc */
	0,	/* tp_traverse */
	0,	/* tp_clear */
	0,	/* tp_richcompare */
	0,	/* tp_weaklistoffset */
	0,	/* tp_iter */
	0,	/* tp_iternext */
	cpy_type_minclient_LogConfig_methods,             /* tp_methods */
	0,	/* tp_members */
	cpy_type_minclient_LogConfig_getsets,	/* tp_getset */
	0,	/* tp_base */
	0,	/* tp_dict */
	0,	/* tp_descr_get */
	0,	/* tp_descr_set */
	0,	/* tp_dictoffset */
	(initproc)cpy_func_minclient_LogConfig_init,      /* tp_init */
	0,                         /* tp_alloc */
	cpy_func_minclient_LogConfig_new,	/* tp_new */
};

static int
cgopy_cnv_py2c_minclient_LogConfig(PyObject *o, cgo_type_minclient_LogConfig *addr) {
	cpy_type_minclient_LogConfig *self = NULL;
	self = (cpy_type_minclient_LogConfig *)o;
	*addr = self->cgopy;
	return 1;
}

static PyObject*
cgopy_cnv_c2py_minclient_LogConfig(cgo_type_minclient_LogConfig *addr) {
	PyObject *o = cpy_func_minclient_LogConfig_new(&cpy_type_minclient_LogConfigType, 0, 0);
	if (o == NULL) {
		return NULL;
	}
	((cpy_type_minclient_LogConfig*)o)->cgopy = *addr;
	return o;
}


/* check-type function for minclient.LogConfig */
static int
cpy_func_minclient_LogConfig_check(PyObject *self) {
	return PyObject_TypeCheck(self, &cpy_type_minclient_LogConfigType);
}



/* --- impl for minclient.Session */


/* tp_new */
static PyObject*
cpy_func_minclient_Session_new(PyTypeObject *type, PyObject *args, PyObject *kwds) {
	cpy_type_minclient_Session *self;
	self = (cpy_type_minclient_Session *)type->tp_alloc(type, 0);
	self->cgopy = cgo_func_minclient_Session_new();
	self->eface = (gopy_efacefunc)cgo_func_minclient_Session_eface;
	return (PyObject*)self;
}


/* tp_dealloc for minclient.Session */
static void
cpy_type_minclient_Session_dealloc(cpy_type_minclient_Session *self) {
	cgopy_decref((cgo_type_minclient_Session)(self->cgopy));
	self->ob_type->tp_free((PyObject*)self);
}


/* tp_init */
static int
cpy_func_minclient_Session_init(cpy_type_minclient_Session *self, PyObject *args, PyObject *kwds) {
	return 0;

cpy_label_cpy_type_minclient_Session_init_fail:
	
	return -1;
}


/* tp_getset for minclient.Session */
static PyGetSetDef cpy_type_minclient_Session_getsets[] = {
	{NULL} /* Sentinel */
};


/* wrapping minclient.Session.GetMessage */
static PyObject*
cpy_func_minclient_Session_GetMessage(cpy_type_minclient_Session *self, PyObject *args, PyObject *kwds) {
	GoString ret;
	
	ret = cgo_func_minclient_Session_GetMessage(self->cgopy);
	
	return cgopy_cnv_c2py_string(&ret);
}


/* wrapping minclient.Session.SendMessage */
static PyObject*
cpy_func_minclient_Session_SendMessage(cpy_type_minclient_Session *self, PyObject *args, PyObject *kwds) {
	GoString arg000;
	GoString arg001;
	GoString arg002;
	GoInterface ret;
	
	if (!PyArg_ParseTuple(args, "O&O&O&", cgopy_cnv_py2c_string, &arg000, cgopy_cnv_py2c_string, &arg001, cgopy_cnv_py2c_string, &arg002)) {
		return NULL;
	}
	
	ret = cgo_func_minclient_Session_SendMessage(self->cgopy, arg000, arg001, arg002);
	
	if (!_cgopy_ErrorIsNil(ret)) {
		const char* c_err_str = _cgopy_ErrorString(ret);
		PyErr_SetString(PyExc_RuntimeError, c_err_str);
		free((void*)c_err_str);
		return NULL;
	}
	
	Py_INCREF(Py_None);
	return Py_None;
}


/* wrapping minclient.Session.Shutdown */
static PyObject*
cpy_func_minclient_Session_Shutdown(cpy_type_minclient_Session *self, PyObject *args, PyObject *kwds) {
	
	cgo_func_minclient_Session_Shutdown(self->cgopy);
	
	Py_INCREF(Py_None);
	return Py_None;
}


/* methods for minclient.Session */
static PyMethodDef cpy_type_minclient_Session_methods[] = {
	{"GetMessage", (PyCFunction)cpy_func_minclient_Session_GetMessage, METH_NOARGS, "GetMessage() str\n\nGetMessage blocks until there is a message in the inbox\n"},
	{"SendMessage", (PyCFunction)cpy_func_minclient_Session_SendMessage, METH_VARARGS, "SendMessage(str recipient, str provider, str msg) object\n\nSendMessage into the mix network\n"},
	{"Shutdown", (PyCFunction)cpy_func_minclient_Session_Shutdown, METH_NOARGS, "Shutdown() \n\nShutdown the session\n"},
	{NULL} /* sentinel */
};

static PyObject*
cpy_func_minclient_Session_tp_str(PyObject *self) {
	cgo_type_minclient_Session c_self = ((cpy_type_minclient_Session*)self)->cgopy;
	GoString str = cgo_func_minclient_Session_str(c_self);
	return cgopy_cnv_c2py_string(&str);
}

static PyTypeObject cpy_type_minclient_SessionType = {
	PyObject_HEAD_INIT(NULL)
	0,	/*ob_size*/
	"Session",	/*tp_name*/
	sizeof(cpy_type_minclient_Session),	/*tp_basicsize*/
	0,	/*tp_itemsize*/
	(destructor)cpy_type_minclient_Session_dealloc,	/*tp_dealloc*/
	0,	/*tp_print*/
	0,	/*tp_getattr*/
	0,	/*tp_setattr*/
	0,	/*tp_compare*/
	0,	/*tp_repr*/
	0,	/*tp_as_number*/
	0,	/*tp_as_sequence*/
	0,	/*tp_as_mapping*/
	0,	/*tp_hash */
	0,	/*tp_call*/
	cpy_func_minclient_Session_tp_str,	/*tp_str*/
	0,	/*tp_getattro*/
	0,	/*tp_setattro*/
	0,	/*tp_as_buffer*/
	Py_TPFLAGS_DEFAULT,	/*tp_flags*/
	"Session holds the client session\n",	/* tp_doc */
	0,	/* tp_traverse */
	0,	/* tp_clear */
	0,	/* tp_richcompare */
	0,	/* tp_weaklistoffset */
	0,	/* tp_iter */
	0,	/* tp_iternext */
	cpy_type_minclient_Session_methods,             /* tp_methods */
	0,	/* tp_members */
	cpy_type_minclient_Session_getsets,	/* tp_getset */
	0,	/* tp_base */
	0,	/* tp_dict */
	0,	/* tp_descr_get */
	0,	/* tp_descr_set */
	0,	/* tp_dictoffset */
	(initproc)cpy_func_minclient_Session_init,      /* tp_init */
	0,                         /* tp_alloc */
	cpy_func_minclient_Session_new,	/* tp_new */
};

static int
cgopy_cnv_py2c_minclient_Session(PyObject *o, cgo_type_minclient_Session *addr) {
	cpy_type_minclient_Session *self = NULL;
	self = (cpy_type_minclient_Session *)o;
	*addr = self->cgopy;
	return 1;
}

static PyObject*
cgopy_cnv_c2py_minclient_Session(cgo_type_minclient_Session *addr) {
	PyObject *o = cpy_func_minclient_Session_new(&cpy_type_minclient_SessionType, 0, 0);
	if (o == NULL) {
		return NULL;
	}
	((cpy_type_minclient_Session*)o)->cgopy = *addr;
	return o;
}


/* check-type function for minclient.Session */
static int
cpy_func_minclient_Session_check(PyObject *self) {
	return PyObject_TypeCheck(self, &cpy_type_minclient_SessionType);
}


/* pythonization of: minclient.NewClient */
static PyObject*
cpy_func_minclient_NewClient(PyObject *self, PyObject *args) {
	GoString c_pkiAddress;
	GoString c_pkiKey;
	cgo_type_minclient_LogConfig c_logConfig;
	struct cgo_func_minclient_NewClient_return c_gopy_ret;
	
	if (!PyArg_ParseTuple(args, "O&O&O&", cgopy_cnv_py2c_string, &c_pkiAddress, cgopy_cnv_py2c_string, &c_pkiKey, cgopy_cnv_py2c_minclient_LogConfig, &c_logConfig)) {
		return NULL;
	}
	
	
	c_gopy_ret = cgo_func_minclient_NewClient(c_pkiAddress, c_pkiKey, c_logConfig);
	
	if (!_cgopy_ErrorIsNil(c_gopy_ret.r1)) {
		const char* c_err_str = _cgopy_ErrorString(c_gopy_ret.r1);
		PyErr_SetString(PyExc_RuntimeError, c_err_str);
		free((void*)c_err_str);
		return NULL;
	}
	
	PyObject *o = cpy_func_minclient_Client_new(&cpy_type_minclient_ClientType, 0, 0);
	if (o == NULL) {
		return NULL;
	}
	((cpy_type_minclient_Client*)o)->cgopy = c_gopy_ret.r0;
	return o;
}


/* pythonization of: minclient.GenKey */
static PyObject*
cpy_func_minclient_GenKey(PyObject *self, PyObject *args) {
	struct cgo_func_minclient_GenKey_return c_gopy_ret;
	
	c_gopy_ret = cgo_func_minclient_GenKey();
	
	if (!_cgopy_ErrorIsNil(c_gopy_ret.r1)) {
		const char* c_err_str = _cgopy_ErrorString(c_gopy_ret.r1);
		PyErr_SetString(PyExc_RuntimeError, c_err_str);
		free((void*)c_err_str);
		return NULL;
	}
	
	PyObject *o = cpy_func_minclient_Key_new(&cpy_type_minclient_KeyType, 0, 0);
	if (o == NULL) {
		return NULL;
	}
	((cpy_type_minclient_Key*)o)->cgopy = c_gopy_ret.r0;
	return o;
}


/* pythonization of: minclient.StringToKey */
static PyObject*
cpy_func_minclient_StringToKey(PyObject *self, PyObject *args) {
	GoString c_keyStr;
	struct cgo_func_minclient_StringToKey_return c_gopy_ret;
	
	if (!PyArg_ParseTuple(args, "O&", cgopy_cnv_py2c_string, &c_keyStr)) {
		return NULL;
	}
	
	
	c_gopy_ret = cgo_func_minclient_StringToKey(c_keyStr);
	
	if (!_cgopy_ErrorIsNil(c_gopy_ret.r1)) {
		const char* c_err_str = _cgopy_ErrorString(c_gopy_ret.r1);
		PyErr_SetString(PyExc_RuntimeError, c_err_str);
		free((void*)c_err_str);
		return NULL;
	}
	
	PyObject *o = cpy_func_minclient_Key_new(&cpy_type_minclient_KeyType, 0, 0);
	if (o == NULL) {
		return NULL;
	}
	((cpy_type_minclient_Key*)o)->cgopy = c_gopy_ret.r0;
	return o;
}


/* functions for package minclient */
static PyMethodDef cpy_minclient_methods[] = {
	{"NewClient", cpy_func_minclient_NewClient, METH_VARARGS, "NewClient(str pkiAddress, str pkiKey, object logConfig) object, object\n\nNewClient configures the pki to be used\n"},
	{"GenKey", cpy_func_minclient_GenKey, METH_VARARGS, "GenKey() object, object\n\nGenKey creates a new ecdh key\n"},
	{"StringToKey", cpy_func_minclient_StringToKey, METH_VARARGS, "StringToKey(str keyStr) object, object\n\nStringToKey builds a Key from a string\n"},
	{NULL, NULL, 0, NULL}        /* Sentinel */
};

PyMODINIT_FUNC
initminclient(void)
{
	PyObject *module = NULL;
	
	/* make sure Cgo is loaded and initialized */
	cgo_pkg_minclient_init();
	
	if (PyType_Ready(&cpy_type_minclient_ClientType) < 0) { return; }
	if (PyType_Ready(&cpy_type_minclient_KeyType) < 0) { return; }
	if (PyType_Ready(&cpy_type_minclient_LogConfigType) < 0) { return; }
	if (PyType_Ready(&cpy_type_minclient_SessionType) < 0) { return; }
	if (PyType_Ready(&cpy_type_minclient_ClientType) < 0) { return; }
	if (PyType_Ready(&cpy_type_minclient_KeyType) < 0) { return; }
	if (PyType_Ready(&cpy_type_minclient_LogConfigType) < 0) { return; }
	if (PyType_Ready(&cpy_type_minclient_SessionType) < 0) { return; }
	module = Py_InitModule3("minclient", cpy_minclient_methods, "Package minclient provides a mixnet minimal client library\n");
	
	Py_INCREF(&cpy_type_minclient_ClientType);
	PyModule_AddObject(module, "Client", (PyObject*)&cpy_type_minclient_ClientType);
	
	Py_INCREF(&cpy_type_minclient_KeyType);
	PyModule_AddObject(module, "Key", (PyObject*)&cpy_type_minclient_KeyType);
	
	Py_INCREF(&cpy_type_minclient_LogConfigType);
	PyModule_AddObject(module, "LogConfig", (PyObject*)&cpy_type_minclient_LogConfigType);
	
	Py_INCREF(&cpy_type_minclient_SessionType);
	PyModule_AddObject(module, "Session", (PyObject*)&cpy_type_minclient_SessionType);
	
	Py_INCREF(&cpy_type_minclient_ClientType);
	PyModule_AddObject(module, "Client", (PyObject*)&cpy_type_minclient_ClientType);
	
	Py_INCREF(&cpy_type_minclient_KeyType);
	PyModule_AddObject(module, "Key", (PyObject*)&cpy_type_minclient_KeyType);
	
	Py_INCREF(&cpy_type_minclient_LogConfigType);
	PyModule_AddObject(module, "LogConfig", (PyObject*)&cpy_type_minclient_LogConfigType);
	
	Py_INCREF(&cpy_type_minclient_SessionType);
	PyModule_AddObject(module, "Session", (PyObject*)&cpy_type_minclient_SessionType);
	
}

