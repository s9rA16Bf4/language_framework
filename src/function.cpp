#include "language_framework.hpp"

interpreter_helper iH;

void function_t::run(){ iH.interpret_line(gut); }

void function_helper::run_func(std::string func_name){
    if (!this->find_func(func_name)){ err.error("Function "+func_name+" has not been defined!"); }
}
void function_helper::create_func(std::string func_name, std::string returnType, std::vector<std::string> params, std::vector<std::string> guts){
    function_t* new_func = new function_t();
    new_func->name = func_name;
    new_func->returnType = returnType;
    new_func->params = params;
    new_func->gut = guts;
    new_func->gut_size = guts.size();
    this->func_jail.push_back(new_func);
}
void function_helper::destroy_func(std::string func_name){
    if (!this->find_func(func_name)){ err.error("Function "+func_name+" has not been defined!"); }
    function_t* func_ = return_func(func_name);
    func_->name = "";
    func_->returnValue = "";
    func_->returnType = "";
    func_->gut_size = -1;
    func_->gut.clear();
    func_->params.clear();
}
bool function_helper::find_func(std::string func_name){
    bool toReturn = false;
    for (unsigned int i = 0; i < func_jail.size(); i++){
        if (func_jail[i]->name == func_name){ toReturn = true; break; }
    }
    return toReturn;
}
function_t* function_helper::return_func(std::string func_name){
    function_t* toReturn = nullptr;
    for (unsigned int i = 0; i < func_jail.size(); i++){
        if (func_jail[i]->name == func_name){ toReturn = func_jail[i]; break; }
    }
    return toReturn;
}

int function_helper::get_func_size(std::string func_name){
    if (!this->find_func(func_name)){ err.error("Function "+func_name+" has not been defined!"); }
    function_t* func_ = return_func(func_name);
    return func_->gut.size();
}
void function_helper::print_func_gut(std::string func_name){
    if (!this->find_func(func_name)){ err.error("Function "+func_name+" has not been defined!"); }
    function_t* func_ = return_func(func_name);
    for (std::string e:func_->gut){ std::cout << e << std::endl; }
}
std::vector<std::string> function_helper::return_func_gut(std::string func_name){
    if (!this->find_func(func_name)){ err.error("Function "+func_name+" has not been defined!"); }
    return (return_func(func_name))->gut;
}
std::string function_helper::return_func_gut_line(std::string func_name, unsigned int index){
    if (!this->find_func(func_name)){ err.error("Function "+func_name+" has not been defined!"); }
    function_t* func_ = return_func(func_name);
    if (index > func_->gut.size()){ err.error("Index is out-of-bounds"); }
    return (return_func(func_name))->gut[index];
}

int function_helper::get_amount_of_funcs(void){ return this->func_jail.size(); }
