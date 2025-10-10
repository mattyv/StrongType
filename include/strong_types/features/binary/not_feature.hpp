#pragma once

#include <concepts>

namespace strong_types {

template <typename TDerived, typename T>
class not_feature
{
public:
    friend TDerived operator~(TDerived const& lhs)
    requires(requires(T v) {
        { ~v } -> std::same_as<T>;
    })
    {
        return TDerived(~lhs.underlying_value());
    }
};

} // namespace strong_types
