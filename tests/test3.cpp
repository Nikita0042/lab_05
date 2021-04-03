#include <Account.h>
#include <Transaction.h>
#include <stdexcept>

#include <gtest/gtest.h>
#include <gmock/gmock.h>

class MockTransaction : public Transaction {
  public:
  MOCK_METHOD3(SaveToDataBase, void(Account& from, Account& to, int sum));
};

using ::testing::AtLeast;

TEST(Transaction, MakeMock)
{
  MockTransaction t1;
  
  Account a1(1, 100);
  Account a2(2, 200);
  
  EXPECT_CALL(t1, SaveToDataBase).Times(AtLeast(1));
  t1.Make(a2, a1, 100);
  EXPECT_EQ(a1.GetBalance(), 200);
  EXPECT_EQ(a2.GetBalance(), 99);
}

