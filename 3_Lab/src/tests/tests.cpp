#include "../tests/arrayTests.hpp"
#include "../tests/quadangleTests.hpp"
#include "../tests/rectangleTests.hpp"
#include "../tests/squareTests.hpp"
#include "../tests/trapezoidTests.hpp"
#include "../tests/vectorTests.hpp"

int main(){
    ::testing::InitGoogleTest();

    return RUN_ALL_TESTS();
}
