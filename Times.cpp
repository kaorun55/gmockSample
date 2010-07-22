#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "Greeting.h"

using testing::Return;

// インタフェースのモック
class MockHello : public Hello {
public:
    MOCK_METHOD0( say, std::string () );
};

// 3回呼ぶ
TEST( HelloTest,  _3Times_Success ) {
    // モックを作って、返したいものを入れる
    MockHello mock_hello;	
    EXPECT_CALL( mock_hello, say())
        .Times( 3 )
        .WillRepeatedly( Return( "こんにちは" ) );

    // テストする
    Greeting greeting( &mock_hello );
    EXPECT_EQ( greeting.hello3Times(), "こんにちはこんにちはこんにちは" );
}

// 3回呼ぶ(と見せかけて一回しか呼ばない)
TEST( HelloTest,  _3Times_Error ) {
    // モックを作って、返したいものを入れる
    MockHello mock_hello;	
    EXPECT_CALL( mock_hello, say())
        .Times( 3 )
        .WillRepeatedly( Return( "こんにちは" ) );

    // テストする
    Greeting greeting( &mock_hello );
    EXPECT_EQ( greeting.hello(), "こんにちは" );
}

// 3回呼ぶ(3回呼ぶけど結果がダメ)
TEST( HelloTest,  _3Times_Error2 ) {
    // モックを作って、返したいものを入れる
    MockHello mock_hello;	
    EXPECT_CALL( mock_hello, say())
        .Times( 3 )
        .WillRepeatedly( Return( "こんにちは" ) );

    // テストする
    Greeting greeting( &mock_hello );
    EXPECT_EQ( greeting.hello3Times(), "hellohellohello" );
}
