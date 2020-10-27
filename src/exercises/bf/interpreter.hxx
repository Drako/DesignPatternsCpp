#pragma once

#ifndef BF_INTERPRETER_HXX
#define BF_INTERPRETER_HXX

#include "instruction.hxx"
#include "vm.hxx"

#include <map>

struct interpreter {

  template<typename Iterator>
  inline scope build_scope(Iterator& it, Iterator end, std::ostream& out)
  {
    std::vector<instruction*> instructions;
    std::map<char, std::function<instruction*()>> mapping{
        {'+', [] { return new value_modification{1}; }},
        {'-', [] { return new value_modification{-1}; }},
        {'>', [] { return new pointer_modification{1}; }},
        {'<', [] { return new pointer_modification{-1}; }},
        {'.', [&out] { return new value_output{out}; }},
    };

    for (; it!=end; ++it) {
      char c = *it;
      auto found = mapping.find(c);
      if (found!=mapping.end()) {
        instructions.push_back(found->second());
      }
      else if (c=='[') {
        instructions.push_back(new loop{
            build_scope(++it, end, out)
        });
      }
      else if (c==']') {
        break;
      }
    }

    return scope{std::move(instructions)};
  }

  template<typename Iterator>
  void interpret(Iterator begin, Iterator end, std::ostream& out)
  {
    vm state{};
    build_scope(begin, end, out).apply_to(state);
  }
};

#endif // BF_INTERPRETER_HXX
