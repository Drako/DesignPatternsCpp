#pragma once

#ifndef BF_INSTRUCTION_HXX
#define BF_INSTRUCTION_HXX

#include <cstdint>
#include <iosfwd>
#include <vector>

struct vm;

struct instruction {
  virtual ~instruction() = default;

  virtual void apply_to(vm&) = 0;
};

class value_modification: public instruction {
  int modifier;

public:
  explicit value_modification(int modifier);

  void apply_to(vm&) override;
};

class pointer_modification: public instruction {
  std::int16_t modifier;

public:
  explicit pointer_modification(std::int16_t modifier);

  void apply_to(vm&) override;
};

class value_output: public instruction {
  std::ostream& out;
public:

  explicit value_output(std::ostream& out);

  void apply_to(vm&) override;
};

class scope: public instruction {
  std::vector<instruction*> instructions;

public:
  explicit scope(std::vector<instruction*> instructions);

  scope(scope&&) = default;

  ~scope() override;

  void apply_to(vm&) override;
};

class loop: public instruction {
  scope body;

public:
  explicit loop(scope body);

  void apply_to(vm&) override;
};

#endif // BF_INSTRUCTION_HXX
