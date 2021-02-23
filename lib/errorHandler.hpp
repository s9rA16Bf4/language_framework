#ifndef ERRORHANDLER_HPP

/*MIT License

Copyright (c) 2020 --///--//--

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

#include <string>
#include <iostream>

class errorHandler{
private:
  std::string getColor(std::string);
  std::string endDec(void);
public:
  void error(std::string, std::string);
  void error(std::string);
};

std::string errorHandler::getColor(std::string colorName){ // Returns the color code assocciated with the name
  std::string toReturn = "";
  if (colorName == "Red" || colorName == "red"){toReturn =  "\033[;31m";}
  else if  (colorName == "Blue" || colorName == "blue"){toReturn =  "\033[;34m";}
  else if  (colorName == "Magenta" || colorName == "magenta"){toReturn =  "\033[;35m";}
  return toReturn;
}

std::string errorHandler::endDec(void){ return "\033[0m"; }

void errorHandler::error(std::string errorMsg, std::string funcName){
  std::cerr << getColor("red") << "######## Error ########" << endDec() << std::endl;
  std::cerr << "* Msg: " << getColor("blue") << errorMsg << endDec() << std::endl;
  std::cerr << "* Func: "<< getColor("magenta") << funcName << endDec() << std::endl;
}

void errorHandler::error(std::string errorMsg){ error(errorMsg, "Not provided"); }
#endif
