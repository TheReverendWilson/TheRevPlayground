from setuptools import find_packages, setup, Extension

extra_compile_args = ['-std=c99']
extra_link_args = []
lang = 'c99'

client_extension = Extension('revchatclient',
                             sources=['client/client.c'],
                             extra_compile_args=extra_compile_args,
                             extra_link_args=extra_link_args)
server_extension = Extension('revchatserver',
                             sources=['server/server.c'],
                             extra_compile_args=extra_compile_args,
                             extra_link_args=extra_link_args)

pkgname = 'RevChat'

setup(
    name='RevChat',
    version='0.0.1',
    packages=find_packages(include=[pkgname,
                                    f'{pkgname}.*']),
    install_requires=[],
    python_requires='>=3.7',
    description='Chat program using C-Extensions and PyQt for the interface.',
    ext_modules=[client_extension, server_extension]
)
