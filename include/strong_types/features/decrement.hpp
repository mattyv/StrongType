#pragma once

#include <concepts>

namespace strong_types {

template <typename TDerived, typename T>
class decrement
{
public:
    friend TDerived& operator-(TDerived& lhs)
    requires(requires(T v) {
        { --v } -> std::same_as<T&>;
    })
    {
        --lhs.underlying_value();
        return lhs;
    }

    friend TDerived operator-(TDerived& lhs, int)
    requires(requires(T v) {
        { --v } -> std::same_as<T&>;
    })
    {
        TDerived result = lhs;
        --lhs.underlying_value();
        return result;
    }
};

} // namespace strong_types
