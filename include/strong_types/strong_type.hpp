#pragma once

#include <concepts>
#include <tuple>

namespace strong_types {

template <typename TTag, typename T, template <typename, typename> typename... Features>
class strong_type : public Features<strong_type<TTag, T, Features...>, T>...
{
public:
    using self_type = strong_type<TTag, T, Features...>;
    using features = std::tuple<Features<self_type, T>...>;
    using value_type = T;
    using reference = T&;
    using const_reference = T const&;
    using pointer = T*;
    using const_pointer = T const*;

    constexpr strong_type()
    requires std::default_initializable<T>
    = default;

    template <typename U>
    constexpr strong_type(U&& value)
    requires std::convertible_to<std::decay_t<U>, value_type>
        : value_{std::forward<U>(value)}
    {}

    template <typename... Ts>
    constexpr strong_type(Ts&&... values)
    requires std::constructible_from<T, Ts...> && (sizeof...(values) > 1)
        : value_{std::forward<Ts>(values)...}
    {}

    constexpr reference underlying_value() { return value_; }
    constexpr const_reference underlying_value() const { return value_; }
    constexpr pointer operator->() { return &value_; }
    constexpr const_pointer operator->() const { return &value_; }
private:
    value_type value_;
};

} // namespace strong_types
