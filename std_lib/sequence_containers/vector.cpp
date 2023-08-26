#include <vector>
#include <string>
#include <iostream>

using namespace std;

template <class T> void print(const vector<T>& l) {
    cout << endl << "Size of vector is " << l.size() << "\n[";
    typename vector<T>::const_iterator i;
    for (i = l.begin(); i != l.end(); ++i) {
        cout << *i << ",";
    }
    cout << "]\n";
}

int main() {

    size_t n = 10;
    double val = 3.14;
    vector<double> vector2(n, val);

    cout << "Size of vector2 " << vector2.size() << endl;

    print(vector2);

    vector2[0] = 2.0;
    vector2[1] = 456.76;

    int last_element = vector2.size() - 1;
    vector2[last_element] = 55.66;

    print(vector2);

    return 0;
}
