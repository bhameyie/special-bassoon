cmake_minimum_required(VERSION 3.17)

set(RECEIPTSERVICETESTNAME "ReceiptServiceTestRunner")

set(CMAKE_CXX_STANDARD 17)

#build source
project(app 
    VERSION  0.1.0)
add_subdirectory(app)

#build tests
project(receiptservicetesting)

add_subdirectory(tests)
enable_testing()

add_test(${RECEIPTSERVICETESTNAME} ${RECEIPTSERVICETESTNAME})
