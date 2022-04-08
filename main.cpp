#include "Machine.h"
#include <cstdio>
#include <cstdlib>

int main() {
    
    std::cout << " compiler version " << __cplusplus << std::endl;
  //std::string instructionSet = {"4 5 - DUP 9 + REM"};
 // std::string instructionSet = { "4 5 - DUP 9 + REM -" }; // Stack out of size Instruction at the end
 // std::string instructionSet = { "4 - 5 - DUP 9 + REM -" }; // stack out of size Instruction in the middle 
 //   std::string instructionSet = { "2147483646  1 +  DUP 9 + REM " }; // Integer overflow  
    std::string instructionSet = { "-2147483648  1 -  DUP 9 + REM " }; // Integer underflow

  std::FILE * file = std::fopen("../instruction.txt", "r");

  if(!file)
  {
    std::cout << " File does not exist hard coded instruction will be consider " << std::endl;
    for(auto s:instructionSet)
    {
      std::cout<< s;
    }
    std::cout << std::endl;
  }
  else
  {
    instructionSet.clear();

    fseek(file, 0, SEEK_END);

    // get current file position which is end from seek
    auto size = ftell(file);

    // allocate string space and set length
    instructionSet.resize(static_cast<unsigned long>(size));

    // go back to beginning of file for read
    rewind(file);

    // read 1*size bytes from sfile into ss
    fread(&instructionSet[0], 1, static_cast<size_t>(size), file);

    // close the file
    fclose(file);
  }

    Machine  machine{instructionSet};
    auto result = machine.Execute();
    if (std::get<1>(result) == ResultCodes::OK)
    {
#ifdef _HAS_CXX17
        std::cout << " Result  " << std::get<0>(result).value() << std::endl;
#else
        std::cout << " Result  " << std::get<0>(result) << std::endl;
#endif // _HAS_CXX17

        
    }
    else
    {
        switch (std::get<1>(result))
        {
        case ResultCodes::INTEGER_OVERFLOW :
            std::cout << "Error Interger OverFlow" << std::endl;
            break;
        case ResultCodes::INTEGER_UNDERFLOW:
            std::cout << "Error Interger UnderFlow" << std::endl;
            break;
        case ResultCodes::STACKOUTSIZE:
            std::cout << "Error Stack Out of Size" << std::endl;
            break;
        case ResultCodes::UNDEFINE_INSTRUCTION:
            std::cout << "Error Stack Out of Size" << std::endl;
            break;
        }
    }
  return 0;
}


