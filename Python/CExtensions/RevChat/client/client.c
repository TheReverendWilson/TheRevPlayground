#include <stdio.h>
#include <Python.h>

static PyObject* method_test_client(PyObject *self, PyObject *args){
    printf("Test Client\n");
    Py_INCREF(Py_None);
    return Py_None;
}

static PyMethodDef revchatclientMethods[] = {
    {"test_client", method_test_client, METH_VARARGS, "Test Client C-Extension"},
    {NULL, NULL, 0, NULL}
};

static struct PyModuleDef revchatclientmodule = {
    PyModuleDef_HEAD_INIT,
    "revchatclient",
    NULL,
    -1,
    revchatclientMethods
};

PyMODINIT_FUNC PyInit_revchatclient(void) {
    return PyModule_Create(&revchatclientmodule);
}
