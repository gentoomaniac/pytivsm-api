from distutils.core import setup, Extension

# the c++ extension module
extension_mod = Extension("tivsmapi",
        sources = ["src/main.c", "src/wrapper.c", "src/generators.c", "src/helper.c"],
        include_dirs = ["/opt/tivoli/tsm/client/api/bin64/sample"],
        libraries = ["ApiTSM64"])


setup(name = "tivsmapi",
        version = "0.1",
        description = "Python bindings for TSM API",
        ext_modules=[extension_mod])
