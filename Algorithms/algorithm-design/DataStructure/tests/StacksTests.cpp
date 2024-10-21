#include <gtest/gtest.h>

#include "Stacks.h"

TEST(StacksTests, SimlpleAssertion) {
  EXPECT_EQ(1, 1);
}


TEST(StacksTests, simpleMethodReturning1){

    StackClass ST;

    EXPECT_EQ(ST.return1ToTest(), 1);
}

// --------------------------------------------------------

TEST(StacksTests, validateEmptyStackCreation){

    StackClass SC;

    EXPECT_TRUE(SC.getStack().empty());
}

TEST(StacksTests, addElementInAnEmptyStack){

    StackClass SC;
    const int elementToPush = 10;

    SC.pushElementToTheStack(elementToPush);

    

    ASSERT_EQ(SC.getStack().top(), elementToPush);

}

TEST(StacksTests, removeElementOfAStackWithOneElement){

    StackClass SC;
    const int elementToPush = 10;

    SC.pushElementToTheStack(elementToPush);

    ASSERT_FALSE(SC.getStack().empty());

    SC.popElementOfTheStack();
    
    ASSERT_TRUE(SC.getStack().empty());
}

TEST(StacksTests, removeElementOfAnEmptyStack){

    StackClass SC;

    SC.popElementOfTheStack();
    
    ASSERT_TRUE(SC.getStack().empty());
}
