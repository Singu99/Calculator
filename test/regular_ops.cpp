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

}


TEST_CASE( "Regular operations part II", "[regular_ops_pII]" ) {
    
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

    vc.plus();
    
    REQUIRE(std::stod(vc.get_buffer()) == 520.0);

    vc.plus();

    REQUIRE(std::stod(vc.get_buffer()) == 520.0);

    vc.two();
    REQUIRE(std::stod(vc.get_buffer()) == 2.0);

    vc.three();
    REQUIRE(std::stod(vc.get_buffer()) == 23.0);

    vc.equals();
    REQUIRE(std::stod(vc.get_buffer()) == 543.0);

}


TEST_CASE( "Regular operations part III", "[regular_ops_pIII]" ) {
    
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

    vc.plus();
    
    REQUIRE(std::stod(vc.get_buffer()) == 520.0);

    vc.plus();

    REQUIRE(std::stod(vc.get_buffer()) == 520.0);

    vc.two();
    REQUIRE(std::stod(vc.get_buffer()) == 2.0);

    vc.three();
    REQUIRE(std::stod(vc.get_buffer()) == 23.0);

    vc.plus();
    REQUIRE(std::stod(vc.get_buffer()) == 543.0);

    vc.one();
    REQUIRE(std::stod(vc.get_buffer()) == 1.0);

    vc.equals();
    REQUIRE(std::stod(vc.get_buffer()) == 544.0);

}