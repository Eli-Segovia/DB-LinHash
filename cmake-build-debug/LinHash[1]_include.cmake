if(EXISTS "/home/osboxes/Documents/School_Stuff/File_DB/DB-LinHash/cmake-build-debug/LinHash[1]_tests.cmake")
  include("/home/osboxes/Documents/School_Stuff/File_DB/DB-LinHash/cmake-build-debug/LinHash[1]_tests.cmake")
else()
  add_test(LinHash_NOT_BUILT LinHash_NOT_BUILT)
endif()