#include "language_framework.hpp"
function_helper fH;

void interpreter_helper::setup(std::string file_name, bool live_session){
    if (!live_session){
        this->read_file(file_name);
    }
}

void interpreter_helper::run(std::string file_name, bool live_session){
    this->setup(file_name, live_session);

    if (!live_session){
        if (file_name.find(PROGRAMMING_LANGUAGE_EXTENSION) == std::string::npos){ std::cout << "Warning: Not the correct file extension!" << std::endl; }
        while(this->curr_line < this->file_gut.size()){ this->interpret_line(this->file_gut); }
    }
    else{
        bool run = true;
        std::string line = "";
        while(run){
            std::cout << LIVE_SESSION_INDI;
            std::getline(std::cin, line);
            if (line == LIVE_SESSION_HELP && LIVE_SESSION_HELP_COMMAND){ this->run_help(); }
            else if (line == LIVE_SESSION_QUIT){ run = false; }
            else if (line == LIVE_SESSION_HISTORY && LIVE_SESSION_HELP_COMMAND){ this->run_history(); }
            else if (line == LIVE_SESSION_ABOUT){ this->run_about(); }
            else if (line.find(LIVE_SESSION_WRITE) != std::string::npos){ this->run_write(line.substr(line.find(" ")+1)); }
            else{
                this->file_gut.push_back(line);
                this->interpret_line(this->file_gut);
            }
        }
    }
}
void interpreter_helper::run_help(void){
    int index = 1;
    std::cout << "### Help ###" << std::endl;
    std::cout << "\n## Predefined commands" << std::endl;
    std::cout << "1] Help - This screen" << std::endl;
    std::cout << "2] History - Shows the last " << LIVE_SESSION_HISTORY_MAX << " lines" << std::endl;
    std::cout << "3] About - Shows some information about the program" << std::endl;
    std::cout << "4] write <file_name> - Saves all the information that has been written into the live session down to a local file" << std::endl;
    std::cout << "5] Quit - Quits the program" << std::endl;

    std::cout << "\n## Programming language syntaxes" << std::endl;
    std::cout << index << "] Comments are defined by the character " << COMMENT << std::endl; index++;
    if (!std::string(LINE_TERM).empty()){ std::cout << "2] Lines are terminated with " << LINE_TERM << std::endl; }
    else{ std::cout << "2] Lines are automatically terminated" << std::endl; }
    index++;
    std::cout << index << "] Values are printed by the "<< PRINT << "<value>" << LINE_TERM << std::endl; index++;

    if (FUNC_COMMAND){
        std::cout << index << "] Functions are defined by " << FUNC_DEF << "func_name"<< FUNC_LEFT_WING << "<params>" << FUNC_RIGHT_WING << FUNC_LEFT_OPEN_WING << "<code>" << FUNC_RIGHT_CLOSE_WING << std::endl; index++;
        std::cout << index << "] Functions are called by func_name" << FUNC_LEFT_WING << "<params>" << FUNC_RIGHT_WING << LINE_TERM << std::endl; index++;
    }else{ std::cout << index << "] There are no functions" << std::endl; index++; }
    if (VAR_COMMAND){
        std::cout << index << "] Variables are defined by " << VAR_DEF << "var_name " << VAR_ASS_OP << " <value>" << LINE_TERM << std::endl; index++;
        std::cout << index << "] Variables are accessed by " << VAR_VALUE << "var_name"  << LINE_TERM << std::endl; index++;
    }else{ std::cout << index << "] There are no variables" << std::endl; index++; }
    if (CONST_COMMAND){
        std::cout << index << "] Const variables are defined by " << CONST_DEF << "const_name " << CONST_ASS_OP << " <value>" << LINE_TERM << std::endl; index++;
        std::cout << index << "] Const variables are accessed by " << CONST_VALUE << "var_name"  << LINE_TERM << std::endl; index++;
    }else{ std::cout << index << "] There are no const variables" << std::endl; index++; }
    if (IF_COMMAND){
        std::cout << index << "] If statemens are defined by " << IF_DEF << IF_LEFT_WING << "<condition>" << IF_RIGHT_WING << IF_LEFT_OPEN_WING << "<code>" << IF_RIGHT_CLOSE_WING << std::endl; index++;
    }else{ std::cout << index << "] There are no if statements" << std::endl; index++; }
    if (ELSE_IF_COMMAND){
        std::cout << index << "] Else if statemens are defined by " << ELSE_IF_DEF << IF_LEFT_WING << "<condition>" << IF_RIGHT_WING << IF_LEFT_OPEN_WING << "<code>" << IF_RIGHT_CLOSE_WING << std::endl; index++;
    }else{ std::cout << index << "] There are no else-if statements" << std::endl; index++; }
    if (ELSE_COMMAND){
        std::cout << index << "] else statemens are defined by " << ELSE_DEF << IF_LEFT_OPEN_WING << "<code>" << IF_RIGHT_CLOSE_WING << std::endl; index++;
    }else{ std::cout << index << "] There are no else statements" << std::endl; index++; }
    if (GOTO_COMMAND){ std::cout << index << "] goto statemens are defined by " << GOTO_DEF << " <index>" << LINE_TERM << std::endl; index++; }
    else{ std::cout << index << "] There are no goto statements" << std::endl; index++; }

}
void interpreter_helper::run_history(void){
    for (unsigned int i = 0; i < LIVE_SESSION_HISTORY_MAX && i < this->file_gut.size(); i++){
        std::cout << i+1 << "] " << file_gut[i] << std::endl;
    }
}
void interpreter_helper::run_about(void){
    std::cout << "## Programming language ##" << std::endl;
    std::cout << "Name: " << PROGRAMMING_LANGUAGE_NAME << std::endl;
    std::cout << "Version: " << PROGRAMMING_LANGUAGE_VERSION << std::endl;
    std::cout << "Ext: " << PROGRAMMING_LANGUAGE_EXTENSION << std::endl;
    std::cout << "Auhor: " << PROGRAMMING_LANGUAGE_AUTHOR << std::endl;
    std::cout << "\n## Mainframe ##" << std::endl;
    std::cout << "Version: " << FRAMEWORK_VERSION << std::endl;
    std::cout << "Author: @s9rA16Bf4" << std::endl;
}
void interpreter_helper::run_write(std::string file_name){
    std::fstream openFile(file_name+"."+PROGRAMMING_LANGUAGE_EXTENSION, std::fstream::out);
    std::string line = "";
    for(std::string e:this->file_gut){ openFile << e << std::endl; }
    openFile.close();
}

void interpreter_helper::interpret_line(std::vector<std::string> lines){
    for (; curr_line < lines.size(); this->next_line()){
        std::string current_line = lines[curr_line];
        if (std::isspace(current_line[current_line.size()-1])){ current_line.pop_back(); } // Removes the last character if it's a space

        if (!std::string(LINE_TERM).empty() && current_line.find(LINE_TERM) == std::string::npos && current_line.find(FUNC_DEF) == std::string::npos){ err.error("Missing terminating character on line '"+current_line+"'"); }
        else{
            if (!std::string(LINE_TERM).empty() && current_line.find(FUNC_DEF) == std::string::npos){ current_line.pop_back(); } // Removes the LINE_TERM if it exists
            if (current_line.find(PRINT) != std::string::npos){ std::cout << current_line.substr(current_line.find(PRINT)+std::string(PRINT).size()) << std::endl; }
            else if (current_line.find(FUNC_DEF) != std::string::npos && current_line.find(FUNC_LEFT_WING)
            != std::string::npos && current_line.find(FUNC_RIGHT_WING) != std::string::npos && FUNC_COMMAND){
                std::vector<std::string> local_function_gut = this->interpret_function(lines);
                std::string function_name = current_line.substr(current_line.find(" ")+1, current_line.find(FUNC_LEFT_WING));
                std::cout << function_name << std::endl;
                fH.create_func("test", "hej", local_function_gut, local_function_gut);
            }
            else{ err.error("Unknown command: "+current_line); }
        }
    }
}
std::vector<std::string> interpreter_helper::interpret_function(std::vector<std::string> file){
    std::vector<std::string> local_vector;
    unsigned wings = 1;
    this->next_line();
    while(wings != 0){
        for (unsigned int x = this->current_line(); x < file.size(); x++){
            std::string e = file[x];
            for (unsigned int i = 0; i < e.size(); i++){
                if (e[i] == '{'){ wings++; }
                else if (e[i] == '}'){ wings--; }
            }
            if (e != "{" && e != "}"){ local_vector.push_back(e); }
        }
        this->next_line();
    }
    return local_vector;
}

int interpreter_helper::get_size(void){ return file_gut.size(); }

void interpreter_helper::read_file(std::string file){
    std::fstream openFile(file, std::fstream::in);
    if (!openFile.is_open()){ err.error("Failed to open: "+file); return; }
    std::string line = "";
    while(std::getline(openFile, line)){
        if (line.find(COMMENT) != std::string::npos){ line = line.substr(0, line.find(COMMENT)); } // No point in saving comments
        if (!line.empty()){ this->file_gut.push_back(line); } // No point in saving empty lines
    }
    openFile.close();
}


std::string interpreter_helper::get_line(int index){
    if (index > this->get_size()){ err.error("The requested index is out-of-bounds", "get_line"); return ""; }
    return this->file_gut[index];
}
std::string interpreter_helper::get_line(void){ return this->get_line(this->current_line()); }

void interpreter_helper::next_line(void){
    if (this->current_line()+1 > this->get_size()){ err.error("The index becomes out-of-bounds", "next_line"); return; }
    this->curr_line++;
}
void interpreter_helper::past_line(void){
    if (this->current_line()-1 < 0){ err.error("The index becomes out-of-bounds", "past_line"); return; }
    this->curr_line--;
}
void interpreter_helper::set_line(int index){
    if (index > this->get_size()){ err.error("The index is out-of-bounds", "set_line"); return; }
    this->curr_line = index;
}
int interpreter_helper::current_line(void){ return this->curr_line; }

void interpreter_helper::print_file_content(void){
    for (std::string e:this->file_gut){
        std::cout << e << std::endl;
    }
}
