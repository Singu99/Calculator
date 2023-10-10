
#include <iostream>
#include <string>


enum class Event {
    NUMBER_INPUT,
    OPERATION_INPUT 
};

enum class Operation {
    PLUS,
    MINUS,
    MULT,
    DIV,
    MOD,
    EQUALS,
    NOP
};

class ViewController {

public:
    ViewController();
    ~ViewController() = default;

    /* Numbers */
    void zero();
    void coma();
    void one();
    void two();
    void three();
    void four();
    void five();
    void six();
    void seven();
    void eight();
    void nine();

    /* Operations */
    void ac();
    void plus();
    void minus();
    void mult();
    void div();
    void mod();
    void equals();

    const std::string& get_buffer() const;

private:
    std::string internal_buffer;
    double storage;

    void new_event(Event event, const char* type, Operation new_op = Operation::NOP);
    void perform_operation(Operation new_op);

    uint64_t state; 
    Operation op;

};