#include <stdio.h>
#include <Python.h>

static PyObject* method_test_server(PyObject *self, PyObject *args){
    printf("Test Server\n");
    Py_INCREF(Py_None);
    return Py_None;
}

static PyMethodDef revchatserverMethods[] = {
    {"test_server", method_test_server, METH_VARARGS, "Test Server C-Extension"},
    {NULL, NULL, 0, NULL}
};

static struct PyModuleDef revchatservermodule = {
    PyModuleDef_HEAD_INIT,
    "revchatserver",
    NULL,
    -1,
    revchatserverMethods
};

PyMODINIT_FUNC PyInit_revchatserver(void) {
    return PyModule_Create(&revchatservermodule);
}
