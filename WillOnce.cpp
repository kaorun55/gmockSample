#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "Greeting.h"

using testing::Return;

// インタフェースのモック
class MockHello : public Hello {
public:
    MOCK_METHOD0( say, std::string () );
};

// 英語であいさつ
TEST( HelloTest,  English ) {
    // モックを作って、返したいものを入れる
    MockHello mock_hello;	
    EXPECT_CALL( mock_hello, say()).WillOnce( Return( "hello" ) );

    // テストする
    Greeting greeting( &mock_hello );
    EXPECT_EQ( greeting.hello(), "hello" );
}


// 日本語であいさつ
TEST( HelloTest,  Japanese ) {
    // モックを作って、返したいものを入れる
    MockHello mock_hello;	
    EXPECT_CALL( mock_hello, say()).WillOnce( Return( "こんにちは" ) );

    // テストする
    Greeting greeting( &mock_hello );
    EXPECT_EQ( greeting.hello(), "こんにちは" );
}


// 英語であいさつ(日本語で挨拶してしまった)
TEST( HelloTest,  English_Error ) {
    // モックを作って、返したいものを入れる
    MockHello mock_hello;	
    EXPECT_CALL( mock_hello, say()).WillOnce( Return( "こんにちは" ) );

    // テストする
    Greeting greeting( &mock_hello );
    EXPECT_EQ( greeting.hello(), "hello" );
}

