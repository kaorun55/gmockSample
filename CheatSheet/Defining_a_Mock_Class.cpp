#include <gtest/gtest.h>
#include <gmock/gmock.h>
using testing::NiceMock;
using testing::StrictMock;

#include "Foo.h"
#include "MockFoo.h"

#include "StackInterface.h"

// モックの実態化
TEST( gmockSample, Mocking_a_normal_Class )
{
  NiceMock< MockFoo > nice_mock;
  StrictMock< MockFoo > strict_mock;
}



// クラステンプレートに対するモックの作成
// とあるクラステンプレートのモック
template< typename Elem >
class MockStack : public StackInterface< Elem >
{
public:

  MOCK_CONST_METHOD0_T( GetSize, int() );
  MOCK_METHOD1_T( Push, void( const Elem& x ) );
};

// モックの実態化
TEST( gmockSample, Mocking_a_Class_Template )
{  
  NiceMock< MockStack< double > > nice_mock;
  StrictMock< MockStack< int > > strict_mock;
}


