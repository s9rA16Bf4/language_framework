#ifndef INTERPRETER_HPP
#define INTERPRETER_HPP

#include <string>
#include <fstream>
#include <vector>

class interpreter_helper{
    private:
        std::vector<std::string> file_gut; // All the contents of the file
        int get_size(void);
        unsigned int curr_line = 0;

    public:
        void setup(std::string, bool);
        void run(std::string, bool);
        void run_help(void);
        void run_history(void);
        void run_about(void);
        void run_write(std::string); // Writes the contents that has been entered into the live session

        void read_file(std::string); // Reads the entire file

        void interpret_line(std::vector<std::string>);
        std::vector<std::string> interpret_function(std::vector<std::string>);

        std::string get_line(int); // Gets the line at the provided int
        std::string get_line(void); // Gets the current line
        void next_line(void); // Increments one step
        void past_line(void); // Decrements one step
        void set_line(int); // Jump to the provided line
        int current_line(void); // Returns the current index

        void print_file_content(void); // Prints all the lines that was read
};

#endif
