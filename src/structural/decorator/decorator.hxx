#pragma once

#ifndef DECORATOR_PRINTER_DECORATOR_HXX
#define DECORATOR_PRINTER_DECORATOR_HXX

template<typename Base>
class decorator: public Base {
protected:
  Base& base;

public:
  inline explicit decorator(Base& base) noexcept
      :base{base}
  {
  }

  virtual ~decorator() = default;
};

#endif // DECORATOR_PRINTER_DECORATOR_HXX
