#include <gtest/gtest.h>
#include <gmock/gmock.h>
using testing::NiceMock;
using testing::StrictMock;

#include <string>

class Foo
{
public:

  virtual ~Foo(){}
 
  virtual int GetSize() const = 0;
  virtual std::string Describe( const char* name ) = 0;
  virtual std::string Describe( int type ) = 0;
  //virtual bool Proecss( Bar elem, int count ) = 0;
  virtual bool Process( int elem, int count ) = 0;
};

class MockFoo : public Foo
{
public:

  MOCK_CONST_METHOD0( GetSize, int() );
  MOCK_METHOD1( Describe, std::string( const char* name ) );
  MOCK_METHOD1( Describe, std::string( int type ) );
  MOCK_METHOD2( Process, bool( int elem, int count ) );
};

TEST( gmockSample, Mocking_a_normal_Class )
{
  NiceMock< MockFoo > nice_mock;
  StrictMock< MockFoo > strict_mock;
}
