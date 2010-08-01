#ifndef MOCKFOO_H_INCLDUE
#define MOCKFOO_H_INCLUDE

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

#endif
