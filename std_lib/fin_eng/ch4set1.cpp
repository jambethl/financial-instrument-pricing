
#include <set>
#include <iostream>
#include <string>

using namespace std;

template <class T> void print(const set<T>& my_set, const string& name) {
    cout << endl << name << ", size of set: " << my_set.size() << endl << "[";

    typename set<T>::const_iterator i;
    for (i = my_set.begin(); i != my_set.end(); ++i) {
        cout << (*i) << ",";
    }
    cout << "]" << endl;
}

int main() {
    set<string> first;
    first.insert("r");
    first.insert("T");
    first.insert("sigma");

    cout << "First size: " << first.size() << endl;

    set<string> second (first);

    second.insert("r");
    second.insert("K");
    second.insert("S");
    second.insert("b");

    cout << "Second size " << second.size() << endl;

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

    set<string> exec_option(first);

    exec_option.insert("lambda");

    print(exec_option, "An executive option");

    return 0;
}
