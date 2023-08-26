#include <vector>
#include <iostream>
#include <algorithm>
#include <time.h>

using namespace std;

bool binary_search(const vector<int>& input, const int target) {

    int l = 0;
    int r = input.size() - 1;

    while (l <= r) {
        unsigned int pivot = (l + r) / 2;

        if (input[pivot] == target) {
            return true;
        }

        if (input[pivot] < target) {
            l = pivot + 1;
        } else {
            r = pivot - 1;
        }
    }
    return false;
}

void print(const vector<int>& v) {
    vector<int>::const_iterator i;

    cout << "[";

    for (i = v.begin(); i != v.end(); ++i) {
        cout << *i << ", ";
    }

        cout << "]" << endl;
}

int main() {
    // Create a 'seed' at the current time so that
    // the random numbers will be different each time
    // that the generator is run
    srand((unsigned) time (NULL));

    int Size = 5;
    vector<int> v1, v2;
    int i;
    for (i = 0; i <= Size; i++) {
        v1.push_back(rand());
    }
    for (i = 0; i < Size; i++) {
        v2.push_back(rand());
    }

    cout << "Two random lists" << endl;
    print(v1);
    print(v2);

    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());

    cout << "Two sorted lists" << endl;
    print(v1);
    print(v2);

    vector<int> v3(v1.size() + v2.size());
    cout << endl << "Merge the two lists" << endl;
    merge(v1.begin(), v1.end(), v2.begin(), v2.end(), v3.begin());
    print(v3);

    vector<int> input;
    input.push_back(1);
    input.push_back(2);
    input.push_back(3);
    input.push_back(3);
    input.push_back(5);
    input.push_back(8);

    for (int j = 0; j <= 10; j++) {
        cout << "\nSearching for: " << j << ":";
        if (binary_search(input, j)) {
            cout << "present";
        } else {
            cout << "not present";
        }
    }

    return 0;
}
