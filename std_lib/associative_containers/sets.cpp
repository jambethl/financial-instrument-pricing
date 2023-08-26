#include <set>
#include <iostream>
#include <string>

using namespace std;

template <class T> void print(const set<T>& mySet, const string& name) {
    cout << endl << name << ", size of set " << mySet.size() << "\n[";
    typename set<T>::const_iterator i;

    for (i = mySet.begin(); i != mySet.end(); ++i) {
        cout << (*i) << ",";
    }
    cout << "]\n";
}

int main() {

    set<string> first;
    first.insert("Interest rate");
    first.insert("Expiry date");
    first.insert("Volatility");

    cout << "First Size: " << first.size() << endl;
    set<string> second (first); // Copy ctor 

    second.insert("Interest rate");
    second.insert("Strike price");
    second.insert("Current underlying price");
    second.insert("Cost of carry");

    cout << "Second Size: " << second.size() << endl;

    if (first == second) {
        cout << "Sets have same elements" << endl;
    } else {
        cout << "Not same elements" << endl;
    }

    swap(first, second);

    set<string> third = first;

    print(first, "First set");
    print(second, "Second set");
    print(third, "Third set");

    return 0;
}
