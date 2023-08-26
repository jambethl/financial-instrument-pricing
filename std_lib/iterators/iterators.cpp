/**
 * Testing the following iterators:
 *  - Bidirectional random access iterators
 *  - Reverse iterators
 *  - Const iterators
 */

#include <vector>
#include <iostream>

using namespace std;

vector<double> make_vector(int size) {
    vector<double> result;
    for (int i = 1; i <= size; i++) {
        result.push_back(double(i));
    }
    return result;
}

void print(const vector<double>& l) {
    cout << "Size of vector is: " << l.size() << endl;

    vector<double>::const_iterator i;
    for (i = l.begin(); i != l.end(); i++) {
        cout << (*i) << " ";
    }
    cout << endl;
}

int main() {
    vector<double> vector1 = make_vector(5);

    // Bidirectional iterator 
    vector<double>::iterator bi;

    cout << "Traverse forward" << endl;

    bi = vector1.begin();
    while (bi != vector1.end()) {
        cout << (*bi++) << " ";
    }
    cout << endl << endl;

    cout << "Traverse backward" << endl;
    bi = vector1.end();
    do {
        cout << (*--bi) << " ";
    } while (bi != vector1.begin());
    cout << endl << endl;

    cout << "Traverse random" << endl;
    bi = vector1.begin();
    cout << *bi << " ";
    cout << *(bi += 3) << " ";
    cout << *(bi--) << " ";
    cout << bi[-1] << " ";
    cout << bi[1] << endl << endl;

    // Create bidirectional iterator
    vector<double>::reverse_iterator ri;

    cout << "Traverse reverse forward" << endl;
    ri = vector1.begin();
    while (ri != vector1.rend()) {
        cout << (*ri++) << " ";
    }
    cout << endl << endl;

    cout << "Traverse reverse backward" << endl;
    ri = (vector1.rend());
    do {
        cout << (*--ri) << " ";
    } while (ri != vector1.begin());
    cout << endl << endl;

    cout << "Traverse reverse random" << endl;
    cout << *ri << " ";
    cout << *(ri+=3) << " ";
    cout << *(ri--) << " ";
    cout << ri[-1] << " ";
    cout << ri[1] << endl << endl;

    cout << "Change first element with mutable iterator" << endl;
    bi = vector1.begin();
    *bi = double(99);
    print(vector1);

    cout << "Change first element with const iterator" << endl;
    vector<double>::const_iterator ci;
    ci = vector1.end();
    ci--;
    cout << *ci << endl;

    return 0;
}
