from distutils.core import setup, Extension

extra_compile_args = ['-std=c99', '-fopenmp']
extra_link_args = ['-lgomp', '-lhdf5']
lang = 'c99'

omphdf5_ext = Extension('omphdf5', sources=['omphdf5.c'], extra_compile_args=extra_compile_args, extra_link_args=extra_link_args)

setup(
    name='omphdf5',
    ext_modules=[omphdf5_ext]
)