#ifndef STACKINTERFACE_H_INCLUDE
#define STACKINTERFACE_H_INCLUDE

// とあるクラステンプレート
template< typename Elem >
class StackInterface
{
public:

  virtual ~StackInterface(){}

  virtual int GetSize() const = 0;
  virtual void Push( const Elem& x ) = 0;
};

#endif
