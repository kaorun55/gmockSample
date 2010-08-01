#ifndef MOCKSTACK_H_INCLUDE
#define MOCKSTACK_H_INCLUDE

// とあるクラステンプレートのモック
template< typename Elem >
class MockStack : public StackInterface< Elem >
{
public:

  MOCK_CONST_METHOD0_T( GetSize, int() );
  MOCK_METHOD1_T( Push, void( const Elem& x ) );
};

#endif
