add_test( [==[Test One - Base Test]==] /Users/kadenluang/CLionProjects/Page-Rank-Project/cmake-build-debug/Tests [==[Test One - Base Test]==]  )
set_tests_properties( [==[Test One - Base Test]==] PROPERTIES WORKING_DIRECTORY /Users/kadenluang/CLionProjects/Page-Rank-Project/cmake-build-debug)
add_test( [==[Test Two - Empty Out-degree Connections]==] /Users/kadenluang/CLionProjects/Page-Rank-Project/cmake-build-debug/Tests [==[Test Two - Empty Out-degree Connections]==]  )
set_tests_properties( [==[Test Two - Empty Out-degree Connections]==] PROPERTIES WORKING_DIRECTORY /Users/kadenluang/CLionProjects/Page-Rank-Project/cmake-build-debug)
add_test( [==[Test Three - Single Connection]==] /Users/kadenluang/CLionProjects/Page-Rank-Project/cmake-build-debug/Tests [==[Test Three - Single Connection]==]  )
set_tests_properties( [==[Test Three - Single Connection]==] PROPERTIES WORKING_DIRECTORY /Users/kadenluang/CLionProjects/Page-Rank-Project/cmake-build-debug)
add_test( [==[Test Four - Cyclical Connection]==] /Users/kadenluang/CLionProjects/Page-Rank-Project/cmake-build-debug/Tests [==[Test Four - Cyclical Connection]==]  )
set_tests_properties( [==[Test Four - Cyclical Connection]==] PROPERTIES WORKING_DIRECTORY /Users/kadenluang/CLionProjects/Page-Rank-Project/cmake-build-debug)
add_test( [==[Test Five - Large Cyclical Graph]==] /Users/kadenluang/CLionProjects/Page-Rank-Project/cmake-build-debug/Tests [==[Test Five - Large Cyclical Graph]==]  )
set_tests_properties( [==[Test Five - Large Cyclical Graph]==] PROPERTIES WORKING_DIRECTORY /Users/kadenluang/CLionProjects/Page-Rank-Project/cmake-build-debug)
set( Tests_TESTS [==[Test One - Base Test]==] [==[Test Two - Empty Out-degree Connections]==] [==[Test Three - Single Connection]==] [==[Test Four - Cyclical Connection]==] [==[Test Five - Large Cyclical Graph]==])
