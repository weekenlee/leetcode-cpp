class [[deprecated("this was not a good idea to begin with")]]
stream {

};

int main() {
    [[deprecated("dong use this anymore")]];
    auto make_stream = [](){
        return stream();
    };
    make_stream();
    return 0;
}
