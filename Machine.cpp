#include "Machine.h"
Machine::Machine(std::string& instructions):
instructions_(instructions)
{}

Result Machine::Execute() {
  
  std::tuple<int, ResultCodes> result{};
  auto addition = [this](){
    if(stackOfint.size() >=2 )
    {
      auto num1 =  stackOfint.top();
      stackOfint.pop();
      auto num2 =  stackOfint.top();
      stackOfint.pop();
      if(num2 <= (std::numeric_limits<int>::max()- num1))
      {
        stackOfint.push(num1+num2);
        return ResultCodes::OK;
      }
      else
      {
          return ResultCodes::INTEGER_OVERFLOW;
      }
      
    }
    else
    {
        return ResultCodes::STACKOUTSIZE;
    }
  };

  auto substraction = [this]() {
      if (stackOfint.size() >= 2)
      {
        auto num1 = stackOfint.top();
        stackOfint.pop();
        auto num2 = stackOfint.top();
        stackOfint.pop();
        if (num2 >= (num1 - std::numeric_limits<int>::min()))
        {
        stackOfint.push(num1 - num2);
        return ResultCodes::OK;
        }
        else
        {
            return ResultCodes::INTEGER_UNDERFLOW;
        }

      }
      else
      {
       return ResultCodes::STACKOUTSIZE;
      }
  };


std::regex instructionsReg("([A-Z0-9-+]+)");
  auto words_begin = std::sregex_iterator(instructions_.begin(), instructions_.end(), instructionsReg);
  auto words_end = std::sregex_iterator();
  for (std::sregex_iterator i = words_begin; i != words_end; ++i) {
    std::smatch match = *i;
    std::string match_str = match.str();
    std::cout << "  " << match_str << '\n';
    if(match_str == instructionSet_[0])   //substract
    {
        auto additionResult = substraction();
        if (additionResult == ResultCodes::OK)
        {
            std::cout << "Subtraction  " << stackOfint.top() << std::endl;
        }
        else
        {
            return Result({}, additionResult);
        }
    }
    else if(match_str == instructionSet_[1]) // addition
    {
        auto additionResult = addition();
        if (additionResult == ResultCodes::OK)
        {
            std::cout << "Addition " << stackOfint.top() << std::endl;
        }
        else
        {
            return Result({}, additionResult);
        }
    }
    else if(match_str == instructionSet_[2]) // Duplicate
    {
      //
      stackOfint.push(stackOfint.top());
      std::cout << "Duplicate  " <<stackOfint.top()   << std::endl;

    }
    else if(match_str == instructionSet_[3]) // Remove
    {
      std::cout << "Remove  " << stackOfint.top() << std::endl;
      if (stackOfint.empty())
      {
          Result(0, ResultCodes::STACKOUTSIZE);
      }
      else
      {
          stackOfint.pop();
      }
    }
    else
    {
        stackOfint.push(std::stoi(match_str));
    }

  }

  return Result(stackOfint.top(), ResultCodes::OK);


}