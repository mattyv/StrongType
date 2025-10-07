#pragma once

#include <strong_types/features/equality_feature.hpp>

namespace strong_types {

template <typename TDerived, typename T>
class less_than_comparable_feature
{
public:
    constexpr friend bool operator<(TDerived const& lhs, TDerived const& rhs)
    requires(requires(T v) {
        { v < v } -> std::same_as<bool>;
    })
    {
        return lhs.underlying_value() < rhs.underlying_value();
    }
};

template <typename TDerived, typename T>
class less_than_equal_comparable_feature
{
public:
    constexpr friend bool operator<=(TDerived const& lhs, TDerived const& rhs)
    requires(requires(T v) {
        { v <= v } -> std::same_as<bool>;
    })
    {
        return lhs.underlying_value() <= rhs.underlying_value();
    }
};

template <typename TDerived, typename T>
class greater_than_comparable_feature
{
public:
    constexpr friend bool operator>(TDerived const& lhs, TDerived const& rhs)
    requires(requires(T v) {
        { v > v } -> std::same_as<bool>;
    })
    {
        return lhs.underlying_value() > rhs.underlying_value();
    }
};

template <typename TDerived, typename T>
class greater_than_equal_comparable_feature
{
public:
    constexpr friend bool operator>=(TDerived const& lhs, TDerived const& rhs)
    requires(requires(T v) {
        { v >= v } -> std::same_as<bool>;
    })
    {
        return lhs.underlying_value() >= rhs.underlying_value();
    }
};

template <typename TDerived, typename T>
class regular
    : public equality_feature<TDerived, T>
    , public less_than_comparable_feature<TDerived, T>
    , public greater_than_comparable_feature<TDerived, T>
    , public less_than_equal_comparable_feature<TDerived, T>
    , public greater_than_equal_comparable_feature<TDerived, T>
{};

} // namespace strong_types
