from distutils.core import setup, Extension

# the c++ extension module
extension_mod = Extension("pytivsmapi",
        sources = ["main.c", "wrapper.c", "generators.c", "helper.c"],
        include_dirs = ["/opt/tivoli/tsm/client/api/bin64/sample"],
        libraries = ["ApiTSM64"])


setup(name = "tivsmapi",
        version = "0.1",
        description = "Python bindings for TSM API",
        ext_modules=[extension_mod])
