#ifndef FOO_H_INCLUDE
#define FOO_H_INCLUDE

#include <string>

// 通常のクラスに対するモックの作成
// とあるクラス
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

#endif
