#include <catch2/catch_test_macros.hpp>

#include "view_controller.hpp"

TEST_CASE( "Regular operations", "[regular_ops]" ) {
    
    ViewController vc;

    REQUIRE(std::stod(vc.get_buffer()) == 0.0);

    vc.five();
    vc.four();
    vc.three();

    REQUIRE(std::stod(vc.get_buffer()) == 543.0);

    vc.minus();
    vc.two();
    vc.three();

    REQUIRE(std::stod(vc.get_buffer()) == 23.0);

    vc.equals();
    
    REQUIRE(std::stod(vc.get_buffer()) == 520.0);

    vc.plus();

    REQUIRE(std::stod(vc.get_buffer()) == 520.0);

    vc.two();
    REQUIRE(std::stod(vc.get_buffer()) == 2.0);

    vc.three();
    REQUIRE(std::stod(vc.get_buffer()) == 23.0);

    vc.mult();
    REQUIRE(std::stod(vc.get_buffer()) == 543.0);

    vc.two();
    REQUIRE(std::stod(vc.get_buffer()) == 2.0);

    vc.equals();
    REQUIRE(std::stod(vc.get_buffer()) == 1086.0);

    vc.div();
    REQUIRE(std::stod(vc.get_buffer()) == 1086.0);

    vc.two();
    REQUIRE(std::stod(vc.get_buffer()) == 2.0);

    vc.plus();
    REQUIRE(std::stod(vc.get_buffer()) == 543.0);

    vc.three();
    REQUIRE(std::stod(vc.get_buffer()) == 3.0);

    vc.equals();
    REQUIRE(std::stod(vc.get_buffer()) == 546.0);
}