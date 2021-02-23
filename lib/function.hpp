#ifndef FUNCTION_HPP
#define FUNCTION_HPP

#include <string>
#include <vector>
#include <iostream>

struct function_t{
    std::string name;
    std::string returnValue;
    std::string returnType;
    int gut_size;
    std::vector<std::string> gut; // This will contain all the code, that was found within
    std::vector<std::string> params;
    void run(); // Runs the function
};

class function_helper{
    private:
        std::vector<function_t*> func_jail;
    public:
        void run_func(std::string); // Runs the code found within the function
        void create_func(std::string, std::string, std::vector<std::string>, std::vector<std::string>); // Creates a function
        void destroy_func(std::string); // Deletes a function
        bool find_func(std::string); // Checks if the function exists
        function_t* return_func(std::string); // Returns the specificed function, make sure that you have checked that it exists before hand

        int get_func_size(std::string); // Returns the functions size, this returns all the chars that were found
        void print_func_gut(std::string); // Prints all the lines that was found within a function
        std::vector<std::string> return_func_gut(std::string); // Returns all the lines that was found within a function
        std::string return_func_gut_line(std::string, unsigned int); // Returns a specific line found within a function

        int get_amount_of_funcs(); // Returns the amount of defined functions
};

#endif
