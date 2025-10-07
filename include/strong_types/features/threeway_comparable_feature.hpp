#pragma once

#include <concepts>
#include <compare>

namespace strong_types {

template <typename TDerived, typename T>
class threeway_comparable_feature
{
public:
    constexpr friend auto operator <=>(TDerived const& lhs, TDerived const& rhs)
    requires std::three_way_comparable<T>
    {
        return lhs.underlying_value() <=> rhs.underlying_value();
    }

};

} // namespace strong_types
