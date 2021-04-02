#include <Account.h>
#include <Transaction.h>
#include <stdexcept>

#include <gtest/gtest.h>

TEST(Transaction, Make)
{
  Account a1(1, 100);
  Account a2(2, 200);
  
  Transaction t1;
  
  EXPECT_EQ(t1.Make(a2, a1, 100), true);
  EXPECT_EQ(a1.GetBalance(), 200);
  EXPECT_EQ(a2.GetBalance(), 99);
}
