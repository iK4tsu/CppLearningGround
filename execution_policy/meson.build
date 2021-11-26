project('execution-policy', 'cpp',
  version : '0.1',
  default_options : ['warning_level=3', 'cpp_std=c++17'])

libtbb = meson.get_compiler('cpp').find_library('tbb')
src = ['src/main.cpp']
exe = executable(
  'execution-policy',
  src,
  dependencies: [libtbb],
  install: true,
)
