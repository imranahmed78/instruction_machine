#ifndef INSTRUCTIONMACHINE_MACHINE_H
#define INSTRUCTIONMACHINE_MACHINE_H

#include <iostream>
#include <stack>
#include <string>
#include <algorithm>
#include <vector>
#include <tuple>
#include <regex>
#ifdef  _HAS_CXX17
 #include <functional>
 #include <optional>
#endif //  _HAS_CXX17

enum class ResultCodes{OK, STACKOUTSIZE, INTEGER_OVERFLOW, INTEGER_UNDERFLOW, UNDEFINE_INSTRUCTION};

#ifdef  _HAS_CXX17
using Result = std::tuple<std::optional<int>, ResultCodes>;
#else
using Result = std::tuple<int, ResultCodes>;
#endif //  _HAS_CXX17


class Machine
{
 public:

  Machine(std::string& instructions);
  Result Execute();

 private:
  // Instruction Set
  std::vector<std::string> const instructionSet_={{"-"}, {"+"} ,{"DUP"}, {"REM"}};

  // referenc to instructions
  std::string &instructions_;

  std::stack<int> stackOfint{};



};

#endif //INSTRUCTIONMACHINE_MACHINE_H
