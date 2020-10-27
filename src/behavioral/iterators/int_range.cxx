#include "int_range.hxx"

int_range::int_range(int to)
    :from{0}, to{to}
{
}

int_range::int_range(int from, int to)
    :from{from}, to{to}
{
}

int_range::iterator int_range::begin() const
{
  return int_range::iterator{from};
}

int_range::iterator int_range::end() const
{
  return int_range::iterator{to};
}

int_range::iterator::iterator(int current) noexcept
    :current{current}
{
}

int_range::iterator int_range::iterator::operator+(int rhs) const noexcept
{
  return int_range::iterator{current+rhs};
}

int_range::iterator& int_range::iterator::operator+=(int rhs) noexcept
{
  current += rhs;
  return *this;
}

int_range::iterator& int_range::iterator::operator++() noexcept
{
  ++current;
  return *this;
}

int_range::iterator const int_range::iterator::operator++(int) noexcept
{
  return int_range::iterator{current++};
}

int_range::iterator int_range::iterator::operator-(int rhs) const noexcept
{
  return int_range::iterator{current-rhs};
}

int_range::iterator& int_range::iterator::operator-=(int rhs) noexcept
{
  current -= rhs;
  return *this;
}

int_range::iterator& int_range::iterator::operator--() noexcept
{
  --current;
  return *this;
}

const int_range::iterator int_range::iterator::operator--(int) noexcept
{
  return int_range::iterator{current--};
}

bool int_range::iterator::operator==(const int_range::iterator& rhs) const noexcept
{
  return current==rhs.current;
}

bool int_range::iterator::operator!=(const int_range::iterator& rhs) const noexcept
{
  return current!=rhs.current;
}

bool int_range::iterator::operator>(const int_range::iterator& rhs) const noexcept
{
  return current>rhs.current;
}

bool int_range::iterator::operator<(const int_range::iterator& rhs) const noexcept
{
  return current<rhs.current;
}

bool int_range::iterator::operator>=(const int_range::iterator& rhs) const noexcept
{
  return current>=rhs.current;
}

bool int_range::iterator::operator<=(const int_range::iterator& rhs) const noexcept
{
  return current<=rhs.current;
}

int const& int_range::iterator::operator*() const
{
  return current;
}
