project(RpnCalculatorTests)

include_directories(/usr/local/lib/googletest/googlemock/include)
include_directories(/usr/local/lib/googletest/googletest/include)

link_directories(/usr/local/lib/googletest/build/lib)

set(sources
        main.cc
        doubles/PublisherObserverMocks.h
        StackTests.cc
        PublisherObserverTests.cc
        StackErrorDataTests.cc)

set(app_sources
        ../applications/common/Stack.cc
        ../applications/common/Publisher.cc
        ../applications/common/Observer.cc
        ../applications/common/StackErrorData.cc)

add_executable(RpnCalcTests ${sources} ${app_sources} )

target_link_libraries(RpnCalcTests gmock)
target_link_libraries(RpnCalcTests gtest)
