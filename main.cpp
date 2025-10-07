#include <iostream>

#include <strong_types/features/comparable.hpp>
#include <strong_types/features/output_streamable.hpp>
#include <strong_types/features/threeway_comparable.hpp>
#include <strong_types/strong_type.hpp>

using kilometer = strong_types::strong_type<struct kilometer_tag, double, strong_types::regular>;
using miles = strong_types::strong_type<
    struct miles_tag,
    double,
    strong_types::regular,
    strong_types::threeway_comparable_feature,
    strong_types::output_streamable>;

int main(int argc, char** argv)
{
    {
        constexpr kilometer k1{100.};
        constexpr kilometer k2{200.};
        constexpr kilometer k3{100.};

        static_assert(k1 < k2);
        static_assert(k1 <= k2);

        static_assert(k2 > k1);
        static_assert(k2 >= k1);

        static_assert(k1 == k3);
        static_assert(k1 != k2);

        static_assert(k1.underlying_value() == k3.underlying_value());
    }

    {
        constexpr miles k1{100.};
        constexpr miles k2{200.};
        constexpr miles k3{100.};

        static_assert(k1 < k2);
        static_assert(k1 <= k2);

        static_assert(k2 > k1);
        static_assert(k2 >= k1);

        static_assert(k1 == k3);
        static_assert(k1 != k2);

        static_assert(k1.underlying_value() == k3.underlying_value());

        static_assert((k1 <=> k3) == 0);
        static_assert((k1 <=> k2) < 0);
        static_assert((k2 <=> k1) > 0);

        std::cout << k1 << ", " << k2 << std::endl;
    }

    return 0;
}
