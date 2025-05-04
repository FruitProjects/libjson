project('libjson', 'cpp',
  version : '0.1',
  default_options : ['warning_level=3',
                     'cpp_std=c++17'])

incdir = include_directories('include')

test_value_constructor = executable(
  'test_value_constructor',
  'tests/test_constructors.cpp',
  include_directories: incdir
)
test('value_constructor', test_value_constructor)

test_value_serialize_basetypes = executable(
  'test_value_serialize_basetypes',
  'tests/test_value_serialize_basetypes.cpp',
  include_directories: incdir
)
test('value_serialize_basetypes', test_value_serialize_basetypes)

test_value_serialize_list = executable(
  'test_value_serialize_list',
  'tests/test_value_serialize_list.cpp',
  include_directories: incdir
)
test('value_serialize_list', test_value_serialize_list)

test_value_serialize_object = executable(
  'test_value_serialize_object',
  'tests/test_value_serialize_object.cpp',
  include_directories: incdir
)
test('value_serialize_object', test_value_serialize_object)