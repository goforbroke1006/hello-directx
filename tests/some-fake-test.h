//
// Created by GOFORBROKE on 15.09.2020.
//

#ifndef HELLO_DIRECTX_SOME_FAKE_TEST_H
#define HELLO_DIRECTX_SOME_FAKE_TEST_H

#include <gtest/gtest.h>

TEST(someFakeTestName, somePositiveOrNegativeCase) {
    ASSERT_EQ(
            std::set<int>({1, 2, 3, 4, 5}),
            std::set<int>({5, 4, 3, 2, 1})
    );
}

#endif //HELLO_DIRECTX_SOME_FAKE_TEST_H
