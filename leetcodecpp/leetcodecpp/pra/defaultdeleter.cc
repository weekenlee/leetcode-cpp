
class A {
    public:
        A() = default;
        A& operator=(const A&) = delete;
        A(const A&) = delete;

        void func(double);
        void func(int) = delete;
};

int main() {
    A t;
    t.func(1.0);
    t.func(1);
}
