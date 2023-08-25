#include <list>
#include <string>
#include <iostream>

using namespace std;

int main() {

    list<int> list1;

    size_t n = 10;
    double val = 3.14;
    list<double> list2(n, val); // Creates n copies of val
    list<double> list3(list2);  // Creates a copy of list2
    
    cout << "Size of list1 " << list1.size() << endl;
    cout << "Size of list2 " << list2.size() << endl;
    cout << "Size of list3 " << list3.size() << endl;

    list<double>::const_iterator i;
    for (i = list2.begin(); i != list2.end(); ++i) {
        cout << *i << ",";
    }
    cout << endl;

    list<double> list4;
    for (i = list2.begin(); i != list2.end(); ++i) {
        list4.push_back(*i);
    }

    for (i = list4.begin(); i != list4.end(); ++i) {
        cout << *i << ",";
    }
    cout << endl;
    return 0;
}
