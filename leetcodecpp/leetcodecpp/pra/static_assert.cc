#define STATIC_ASSERT(x) \
    do {typedef int a[(x) ? 1 : -1]; } while(0)

int main() {
    STATIC_ASSERT(sizeof(int) <= sizeof(long));
    STATIC_ASSERT(sizeof(int) > sizeof(long));
}
