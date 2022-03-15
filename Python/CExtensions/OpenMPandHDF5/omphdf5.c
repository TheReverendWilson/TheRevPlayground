#include <Python.h>
#include "hdf5.h"

#define FILE "file.h5"

void open_mp_test(int n, float *a, float *b) {
    int i;

    #pragma omp parallel for
    for (i = 1; i < n; ++i)
        b[i-1] = (a[i] + a[i - 1]) / 2.0;
}

void hdf5_test() {
    hid_t file_id;
    herr_t status;

    file_id = H5Fcreate(FILE, H5F_ACC_TRUNC, H5P_DEFAULT, H5P_DEFAULT);

    status = H5Fclose(file_id);
}

static PyObject* method_open_mp_test(PyObject *self, PyObject *args) {
    float *a;
    float *b;
    int n;

    n = 25;
    a = malloc(sizeof(int*) * n);
    b = malloc(sizeof(int*) * (n - 1));

    int i;
    for (i = 0; i < n; ++i)
        a[i] = i;

    open_mp_test(n, a, b);

    for (i = 0; i < (n - 1); ++i)
        printf("%d: %f\n", i, b[i]);

    free(a);
    free(b);
    Py_INCREF(Py_None);
    return Py_None;
}

static PyObject* method_hdf5_test(PyObject *self, PyObject *args) {
    hdf5_test();
    Py_INCREF(Py_None);
    return Py_None;
}

static PyMethodDef omphdf5Methods[] = {
    {"hdf5_test", method_hdf5_test, METH_VARARGS, "Test HDF5 for C."},
    {"open_mp_test", method_open_mp_test, METH_VARARGS, "Test OpenMP for C."},
    {NULL, NULL, 0, NULL}
};

static strict PyModuleDef omphdf5module = {
    PyModule_Def_HEAD_INIT,
    "omphdf5",
    NULL,
    -1,
    omphdf5Methods
};

PyMODINIT_FUNC PyInit_omphdf5(void) {
    return PyModule_Create(&omphdf5module);
}
