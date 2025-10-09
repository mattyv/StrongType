#include <strong_types/features/binary/and_feature.hpp>
#include <strong_types/features/binary/not_feature.hpp>
#include <strong_types/features/binary/or_feature.hpp>
#include <strong_types/features/binary/xor_feature.hpp>
#include <strong_types/features/comparable_feature.hpp>

#include <strong_types/strong_type.hpp>

#include <test_strong_types/test_features/test_features.hpp>

#include <cassert>
#include <cstdint>
#include <cstdio>

using EightBytes = strong_types::strong_type<
    struct eight_bytes_tag,
    std::uint64_t,
    strong_types::regular,
    strong_types::and_feature,
    strong_types::or_feature,
    strong_types::not_feature,
    strong_types::xor_feature>;

void test_binary_features()
{
    printf("> test_binary_features\n");
    const EightBytes mask{0x0F0F0F0F0F0F0F0FULL};
    const EightBytes maskAlternated{0xF0F0F0F0F0F0F0F0ULL};
    const EightBytes zero{0ULL};
    const EightBytes one{~zero};

    assert((mask & maskAlternated) == zero);
    assert((mask | maskAlternated) == one);
    assert((mask ^ mask) == zero);
    assert((mask ^ maskAlternated) == one);
    assert(~mask == maskAlternated);
}