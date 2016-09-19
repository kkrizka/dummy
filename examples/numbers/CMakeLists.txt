CMAKE_MINIMUM_REQUIRED(VERSION 2.6)
PROJECT(numbers)

SET(numbers_SRC
  main.cxx
  MNISTData.cxx
  MNISTDigit.cxx
  )

ADD_EXECUTABLE(numbers ${numbers_SRC})
