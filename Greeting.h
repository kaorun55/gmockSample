
// インタフェース
class Hello {
public:
    virtual std::string say() = 0;
};

// テストしたいクラス
class Greeting
{
    Hello* hello_;

public:
    Greeting( Hello* hello ) : hello_( hello ) {}

    // あいさつ
    std::string hello() { return hello_->say(); }

    // 3回挨拶
    std::string hello3Times() {
        return hello_->say() + hello_->say() + hello_->say();
    }
};
