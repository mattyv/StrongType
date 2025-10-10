#pragma once

#include <concepts>

namespace strong_types {

template <typename TDerived, typename T>
class xor_feature
{
public:
    friend TDerived operator^(TDerived const& lhs, TDerived const& rhs)
    requires(requires(T v) {
        { v ^ v } -> std::same_as<T>;
    })
    {
        return TDerived(lhs.underlying_value() ^ rhs.underlying_value());
    }
};

} // namespace strong_types
