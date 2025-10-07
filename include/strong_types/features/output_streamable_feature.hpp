#pragma once

#include <concepts>
#include <ostream>

namespace strong_types {

template <typename TDerived, typename T>
class output_streamable
{
public:
    constexpr friend std::ostream& operator<<(std::ostream& o, TDerived const& v)
    requires requires(std::ostream& os, T const& rhs) {
        { os << rhs } -> std::same_as<std::ostream&>;
    }
    {
        o << v.underlying_value();
        return o;
    }
};

} // namespace strong_types
