cmake_minimum_required(VERSION 3.17)
project(Statistical_Financial_Data)

set(CMAKE_CXX_STANDARD 14)

add_executable(Statistical_Financial_Data main.cpp
            HTTPRequest.cpp HTTPRequest.h JSON.h Stock.cpp Stock.h Portfolio.cpp Portfolio.h
            FundamentalsCalc.cpp FundamentalsCalc.h MACalculator.cpp MACalculator.h
        PriceHistoryOneMonth.cpp PriceHistoryOneMonth.h Quotes.cpp Quotes.h Charts.cpp Charts.h
        Node.h LinkedList.cpp LinkedList.h MainMenu.cpp MainMenu.h
        LineChart.cpp LineChart.h ChartData.h Interfaces.cpp Interfaces.h SingleStockAnalysis.cpp SingleStockAnalysis.h States.h TextBox.cpp TextBox.h PriceHistoryYTD.cpp PriceHistoryYTD.h PriceHistoryTwoYears.cpp PriceHistoryTwoYears.h)

set(CURL_LIBRARY "-lcurl")
find_package(CURL REQUIRED)

include_directories(${CURL_INCLUDE_DIR})
target_link_libraries(Statistical_Financial_Data sfml-graphics sfml-audio ${CURL_LIBRARIES})

find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)