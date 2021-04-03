#include <Account.h>
#include <stdexcept>

#include <gtest/gtest.h>

TEST(Account, id)
{
  Account a1(1, 100);
  Account a2(2, 200);

  EXPECT_EQ(a1.id(), 1);
  EXPECT_EQ(a2.id(), 2);
}

TEST(Account, GetBalance)
{
  Account a1(1, 100);
  Account a2(2, 200);

  EXPECT_EQ(a1.GetBalance(), 100);
  EXPECT_EQ(a2.GetBalance(), 200);
}

TEST(Account, LockingAndChangeBalance)
{
  Account a1(1, 100);
  Account a2(2, 200);
  
  try {
   a1.ChangeBalance(300);
  }
  catch(std::runtime_error& e) {
   EXPECT_EQ(a1.GetBalance(), 100);
   EXPECT_EQ(a2.GetBalance(), 200);
  }
  
  a1.Lock();
  a2.Lock();
  a1.ChangeBalance(300);
  a2.ChangeBalance(-100);
  EXPECT_EQ(a1.GetBalance(), 400);
  EXPECT_EQ(a2.GetBalance(), 100);
  a1.Unlock();
  a2.Unlock();
  
  try {
   a1.ChangeBalance(200);
  }
  catch(std::runtime_error& e) {
   EXPECT_EQ(a1.GetBalance(), 400);
  }
}
