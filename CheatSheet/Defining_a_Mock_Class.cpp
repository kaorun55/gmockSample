#include <gtest/gtest.h>
#include <gmock/gmock.h>
using testing::NiceMock;
using testing::StrictMock;

#include "Foo.h"
#include "MockFoo.h"

#include "StackInterface.h"
#include "MockStack.h"

// モックの実態化
TEST( gmockSample, Mocking_a_normal_Class )
{
  NiceMock< MockFoo > nice_mock;
  StrictMock< MockFoo > strict_mock;
}

// クラステンプレートに対するモックの作成
// モックの実態化
TEST( gmockSample, Mocking_a_Class_Template )
{  
  NiceMock< MockStack< double > > nice_mock;
  StrictMock< MockStack< int > > strict_mock;
}


