#include "interpreter.hpp"
#include "errorHandler.hpp"
#include <iostream>

int main(int argv, char** argc){
    interpreter_helper i;
    if (argv > 1){ i.run(argc[1], false); }
    else{
        std::cout << "No file was provided, dropping into live session" << std::endl;
        i.run("", true);
    }

    return 0;
}
