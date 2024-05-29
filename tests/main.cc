#define CATCH_CONFIG_MAIN //This tells Catch to provide a main() - only do this in one cpp file
#include <catch2/catch_test_macros.hpp>
#include "my_mathlib.h"

TEST_CASE( "Factorials are computed", "[factorial]" ) {
    REQUIRE( Math::Factorial(0) == 1 );
    REQUIRE( Math::Factorial(2) == 2 );
    REQUIRE( Math::Factorial(3) == 6 );
    REQUIRE( Math::Factorial(10) == 3628800 );
}

TEST_CASE( "Addition works", "[add]" ) {
    REQUIRE( Math::Add(2,3) == 5 );
    REQUIRE( Math::Add(2.0f,3.0f) == 5.0f );
    REQUIRE( Math::Add(2.0,3.0) == 5.0 );
}

TEST_CASE ( "Subtraction works", "[subtract]" ) {
    REQUIRE( Math::Subtract(10,5) == 5 );
    REQUIRE( Math::Subtract(10.0f,5.0f) == 5.0f );
    REQUIRE( Math::Subtract(10.0,5.0) == 5.0 );
}

TEST_CASE ( "Multiplication works", "[multiply]" ) {
    REQUIRE( Math::Multiply(5,5) == 25 );
    REQUIRE( Math::Multiply(5.0f,5.0f) == 25.0f );
    REQUIRE( Math::Multiply(5.0,5.0) == 25.0 );
}

TEST_CASE ( "Division works", "[divide]" ) {
    REQUIRE( Math::Divide(50,5) == 10 );
    REQUIRE( Math::Divide(50.0f,5.0f) == 10.0f );
    REQUIRE( Math::Divide(50.0,5.0) == 10.0 );
}
