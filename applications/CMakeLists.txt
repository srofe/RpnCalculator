project(RpnCalc)

add_executable(RpnCalc main.cc
        common/Stack.h common/Stack.cc
        common/Publisher.h common/Publisher.cc
        common/Observer.h common/Observer.cc
        common/StackErrorData.h common/StackErrorData.cc
        common/Exception.h)
