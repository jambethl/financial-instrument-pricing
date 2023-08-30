#include <vector>
#include <iostream>
#include <numeric>

using namespace std;

template <class T> void print(const vector<T>& my_set) {
    typename vector<T>::const_iterator i;
    for (i = my_set.begin(); i != my_set.end(); ++i) {
        cout << (*i) << ",";
    }
    cout << "]" << endl;
}

int main() {

    vector<double> vec1(4, 2.0);
    vector<double> vec2(4, 4.0);

    double init = 0.0;
    double summation = accumulate (vec1.begin(), vec1.end(), init);

    cout << "Sum of elements of vector 1: " << summation << endl;

    double ip = inner_product(vec1.begin(), vec1.end(), vec2.begin(), init);
    cout << "Inner product of vec1 and vec2: " << ip << endl;

    int size = 6;
    int seed_value = 2;
    vector<int> vec3(size, seed_value);
    vector<int> result(size);
    partial_sum(vec3.begin(), vec3.end(), result.begin());

    cout << "The partial sum of vec3 is: " << endl;
    print(result);

    int sz = 10;
    int value = 2;
    vector<int> vec4(sz);

    vector<int>::iterator it;
    for (it = vec4.begin(); it != vec4.end(); it++) {
        (*it) = value;
        value++;
    }
    vector<int> result2(vec4.size());
    adjacent_difference(vec4.begin(), vec4.end(), result2.begin());
    cout << "The adjacent difference of the vector is:" << endl;
    print(result2);

    return 0;
}
