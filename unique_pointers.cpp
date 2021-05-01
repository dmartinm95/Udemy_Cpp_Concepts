#include <iostream>
#include <memory>
using namespace std;

// Unique pointers (smart pointers) behave like a normal pointer but handles the deallocation of memory for you
// It will return memory once the variable goes out of scope

// Shared pointers are very similar to unique pointer but they don't delete the memory associated with your objects until all the pointers
// that point at that object have gone out of scope

class Test {
public:
    Test() {
        cout << "Created" << endl;
    }
    void greet() {
        cout << "Hello" << endl;
    }
    ~Test() {
        cout << "Destroyed" << endl;
    }
};

class Temp {

private:
    unique_ptr<Test[]> pTest;

public:
    Temp() : pTest(new Test[2]) {
    }
};

int main() {

    // auto_ptr works in the same way but it is deprecated (replaced by unique_ptr in C++11)
    unique_ptr<Test[]> pTest(new Test[2]);

    pTest[1].greet();

    cout << "Finished" << endl;

    // Entire array of pointers will also get cleaned out once it goes out of scope

    Temp temp;

    Test *pTest1 = new Test;

    unique_ptr<Test> pNumber(pTest1);

    // Using shared pointers

    shared_ptr<Test> pTest3(nullptr);

    {
        shared_ptr<Test> pTest2 = make_shared<Test>();
        pTest3 = pTest2;
    }

    cout << "Finished #2" << endl;

    return 0;
}