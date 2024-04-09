#include <utils/utils.h>
#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <vector>

TEST(utils, fmap_return_0_when_zero_line)
{
    std::pair<float, float> A {0.0f, 0.0f};
    std::pair<float, float> B {100.0f, 0.0f};

    float result = vaf::fip::fmapExt(25, A, B);
    
    ASSERT_FLOAT_EQ(0.0f, result);
}

