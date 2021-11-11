project('ex6.3', 'cpp')

rangev3 = dependency('range-v3', required : true)

inc = include_directories('./include')
exe = executable('ex6.3',
  'source/application.cpp',
  'source/book.cpp',
  'source/library.cpp',
  'source/main.cpp',
  'source/user.cpp',
  include_directories : inc,
  install: true
)
