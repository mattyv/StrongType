#pragma once
#include <concepts>

namespace strong_types {

template <typename TDerived, typename T>
class conjunction_feature
{
public:

    friend bool operator&&(TDerived const& lhs, TDerived const& rhs)
    requires(requires(T const& v) {
        { v && v } -> std::same_as<bool>;
    })
    {
        return lhs.underlying_value() && rhs.underlying_value();
    }
};

} // namespace strong_types
