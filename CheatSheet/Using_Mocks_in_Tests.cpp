#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "MockFoo.h"

using ::testing::Return;

std::string MyProductionFunction( Foo* foo )
{
  // GetSizeは1を返す
  if ( foo->GetSize() != 1 ) {
    return "bad";
  }

  // Describeは4回呼び出してもだめだし、引数5以外で呼び出してもだめ
  //foo->Describe( 5 );
  foo->Describe( 5 );
  foo->Describe( 5 );
  foo->Describe( 5 );
  //foo->Describe( 4 );

  return "good";
}

TEST( gmockTest, Using_Mocks_in_Tests )
{
  MockFoo foo;
 
  // GetSizeは1を返す
  ON_CALL( foo, GetSize() )
    .WillByDefault( Return( 1 ) );

  // Describeを引数5で3回呼び出す
  EXPECT_CALL( foo, Describe( 5 ) )
    .Times( 3 )
    .WillRepeatedly( Return( "Category 5" ) );

  EXPECT_EQ( 1, foo.GetSize() );
  
  EXPECT_EQ( "good", MyProductionFunction( &foo ) );
}
