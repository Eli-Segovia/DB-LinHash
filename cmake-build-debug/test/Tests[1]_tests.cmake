add_test( LinearHashTests.Counting_100 /home/osboxes/Documents/School_Stuff/File_DB/DB-LinHash/cmake-build-debug/test/Tests [==[--gtest_filter=LinearHashTests.Counting_100]==] --gtest_also_run_disabled_tests)
set_tests_properties( LinearHashTests.Counting_100 PROPERTIES WORKING_DIRECTORY /home/osboxes/Documents/School_Stuff/File_DB/DB-LinHash/cmake-build-debug/test)
add_test( LinearHashTests.Counting_1000 /home/osboxes/Documents/School_Stuff/File_DB/DB-LinHash/cmake-build-debug/test/Tests [==[--gtest_filter=LinearHashTests.Counting_1000]==] --gtest_also_run_disabled_tests)
set_tests_properties( LinearHashTests.Counting_1000 PROPERTIES WORKING_DIRECTORY /home/osboxes/Documents/School_Stuff/File_DB/DB-LinHash/cmake-build-debug/test)
set( Tests_TESTS LinearHashTests.Counting_100 LinearHashTests.Counting_1000)