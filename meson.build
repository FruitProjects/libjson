project('libjson', 'cpp',
  version : '0.1',
  default_options : ['warning_level=3',
                     'cpp_std=c++14'])

incdir = include_directories('include')

value_constructor_test = executable('libjson', 'tests/test_constructors.cpp', include_directories: incdir)
test('value_constructor_test', value_constructor_test)
