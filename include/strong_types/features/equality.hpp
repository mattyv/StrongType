#pragma once

#include <concepts>

namespace strong_types {

template <typename TDerived, typename T>
class equality_feature
{
public:
    constexpr friend bool operator==(TDerived const& lhs, TDerived const& rhs)
    requires(requires(T v) {
        { v == v } -> std::same_as<bool>;
    })
    {
        return lhs.underlying_value() == rhs.underlying_value();
    }

    constexpr friend bool operator!=(TDerived const& lhs, TDerived const& rhs)
    requires(requires(T v) {
        { v != v } -> std::same_as<bool>;
    })
    {
        return lhs.underlying_value() != rhs.underlying_value();
    }
};

} // namespace strong_types
