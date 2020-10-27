#pragma once

#ifndef ITERATOR_INT_RANGE_HXX
#define ITERATOR_INT_RANGE_HXX

#include <iterator>

class int_range final {
  int from;
  int to;

public:
  explicit int_range(int to);

  int_range(int from, int to);

  class iterator final: public std::iterator<std::bidirectional_iterator_tag, int, int, int const*, int const&> {
    int current;

  public:
    explicit iterator(int current) noexcept;

    iterator(iterator const&) = default;
    iterator& operator=(iterator const&) = default;

    iterator operator+(int rhs) const noexcept;
    iterator& operator+=(int rhs) noexcept;
    iterator& operator++() noexcept;
    iterator const operator++(int) noexcept;

    iterator operator-(int rhs) const noexcept;
    iterator& operator-=(int rhs) noexcept;
    iterator& operator--() noexcept;
    iterator const operator--(int) noexcept;

    bool operator==(iterator const& rhs) const noexcept;
    bool operator!=(iterator const& rhs) const noexcept;
    bool operator>(iterator const& rhs) const noexcept;
    bool operator<(iterator const& rhs) const noexcept;
    bool operator>=(iterator const& rhs) const noexcept;
    bool operator<=(iterator const& rhs) const noexcept;

    int const& operator*() const;
  };

  iterator begin() const;
  iterator end() const;
};

#endif // ITERATOR_INT_RANGE_HXX
