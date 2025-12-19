struct Foo
{
    int memberValue;

    void bar(int param)
    {
        int localVar = 10;
        auto sum = localVar + param + memberValue;
    }
};