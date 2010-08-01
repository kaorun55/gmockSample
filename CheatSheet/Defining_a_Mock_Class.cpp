#include <gtest/gtest.h>
#include <gmock/gmock.h>
using testing::NiceMock;
using testing::StrictMock;

#include "Foo.h"

// とあるクラスのモック
class MockFoo : public Foo
{
public:

  MOCK_CONST_METHOD0( GetSize, int() );
  MOCK_METHOD1( Describe, std::string( const char* name ) );
  MOCK_METHOD1( Describe, std::string( int type ) );
  MOCK_METHOD2( Process, bool( int elem, int count ) );
};

// モックの実態化
TEST( gmockSample, Mocking_a_normal_Class )
{
  NiceMock< MockFoo > nice_mock;
  StrictMock< MockFoo > strict_mock;
}



// クラステンプレートに対するモックの作成
// とあるクラステンプレート
template< typename Elem >
class StackInterface
{
public:

  virtual ~StackInterface(){}

  virtual int GetSize() const = 0;
  virtual void Push( const Elem& x ) = 0;
};


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


