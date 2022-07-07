#include "lib/interface/interface.hpp"
#include "lib/common/stack/stack_smart_pointer.hpp"
#include <iostream>

using namespace std;

int main(int argc, char** argv)
{
    linuy::StackSmartPointer<int> numberStack;

    numberStack.push(128);
    numberStack.push(64);
    numberStack.push(32);
    numberStack.push(16);
    numberStack.push(8);
    numberStack.push(4);
    numberStack.push(2);
    numberStack.push(1);

    numberStack.pop();
    numberStack.pop();
    numberStack.pop();
    numberStack.pop();
    numberStack.pop();

    cout << numberStack.top() << endl;

    cout << numberStack.getSize() << endl;
    cout << numberStack.getLength() << endl;

    cout << "add(1, 2) = " << add(1, 2) << endl;
    return 0;
}
