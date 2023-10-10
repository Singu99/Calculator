#include <iostream>

#include "view_controller.hpp"



ViewController::ViewController() 
    : internal_buffer("0"), state(0), op(Operation::NOP), storage(0.0)
{}

void ViewController::zero()
{
    new_event(Event::NUMBER_INPUT, "0");
}

void ViewController::coma()
{
    new_event(Event::NUMBER_INPUT, ",");
}

void ViewController::one()
{
    new_event(Event::NUMBER_INPUT, "1");
}

void ViewController::two()
{
    new_event(Event::NUMBER_INPUT, "2");
}

void ViewController::three()
{
    new_event(Event::NUMBER_INPUT, "3");    
}

void ViewController::four()
{
    new_event(Event::NUMBER_INPUT, "4");
}

void ViewController::five()
{
    new_event(Event::NUMBER_INPUT, "5");
}

void ViewController::six()
{
    new_event(Event::NUMBER_INPUT, "6");
}

void ViewController::seven()
{
    new_event(Event::NUMBER_INPUT, "7");
}

void ViewController::eight()
{
    new_event(Event::NUMBER_INPUT, "8");
}

void ViewController::nine()
{
    new_event(Event::NUMBER_INPUT, "9");
}

void ViewController::ac()
{
    new_event(Event::OPERATION_INPUT, "AC");
}

void ViewController::plus()
{
    new_event(Event::OPERATION_INPUT, "+", Operation::PLUS);
}

void ViewController::minus()
{
    new_event(Event::OPERATION_INPUT, "-", Operation::MINUS);
}

void ViewController::mult()
{
    new_event(Event::OPERATION_INPUT, "*", Operation::MULT);
}

void ViewController::div()
{
    new_event(Event::OPERATION_INPUT, "/",  Operation::DIV);
}

void ViewController::mod()
{
    new_event(Event::OPERATION_INPUT, "%", Operation::MOD);
}

void ViewController::equals()
{
    new_event(Event::OPERATION_INPUT, "=", Operation::EQUALS);
}

const std::string& ViewController::get_buffer() const
{
    return internal_buffer;
}


// State machine emulating the behavior the ios calculator
void ViewController::new_event(Event event, const char* type, Operation new_op)
{
    if ("AC" == type)
    {
        internal_buffer = "0";
        state = 0;
        return;
    }

    switch (state)
    {
    case 0:                 // State 0: initial state
        if (event == Event::NUMBER_INPUT)
        {
            internal_buffer = type;
            state++;
        }
        else if (event == Event::OPERATION_INPUT)
        {
            // TODO
            op = new_op;
        }
        break;
    case 1:                 // State 1: First input
        if (event == Event::NUMBER_INPUT)
        {
            internal_buffer.append(type);
        }
        else if (event == Event::OPERATION_INPUT)
        {
            op = new_op;
            state++;
        }
        break;
    case 2:                 // State 2: First input + operation
        if (event == Event::NUMBER_INPUT)
        {
            storage = std::stod(internal_buffer);
            internal_buffer = type;
            state++;
        } 
        else if (event == Event::OPERATION_INPUT)
        {
            // Override to new operation
            op = new_op;
        }
        break;
    case 3:                 // State 3: First input + operation + second input
        if (event == Event::NUMBER_INPUT)
        {
            internal_buffer.append(type);
        }
        else if (event == Event::OPERATION_INPUT)
        {
            perform_operation(new_op);
            state = 1;
        }
        break;

    default:
        break;
    }
}

void ViewController::perform_operation(Operation new_op)
{
    double current = std::stod(internal_buffer);
    switch (op)
    {
    case Operation::PLUS:
        storage += current;
        break;
    case Operation::MINUS:
        storage -= current;
        break;
    case Operation::MULT:
        storage *= current;
        break;
    case Operation::DIV:
        storage /= current;
        break;
    case Operation::MOD:
        storage = std::fmod(storage, current);
        break;
    default:
        break;
    }

    internal_buffer = std::to_string(storage);
    op = new_op;
    storage = 0.0;
}
