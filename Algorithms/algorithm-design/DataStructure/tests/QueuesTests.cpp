#include <gtest/gtest.h>

#include "Queues.h"

TEST(QueuesTests, SimlpleAssertion) {
  EXPECT_EQ(1, 1);
}


TEST(QueuesTests, simpleMethodReturning1){

    QueueClass QT;

    EXPECT_EQ(QT.return1ToTest(), 1);
}

// --------------------------------------------------------