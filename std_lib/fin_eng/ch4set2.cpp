#include <set>
#include <iostream>

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

    set<int> first;

    first.insert(1);
    first.insert(2);
    first.insert(3);

    print(first, "First set");

    set<int> second (first);

    second.erase(3);
    second.insert(999);
    print(second, "Second set");

    set<int> my_intersect;
    set<int>::iterator i = my_intersect.begin();
    insert_iterator<set<int> > insert_iterator_2(my_intersect, i);

    set_intersection(first.begin(), first.end(), second.begin(), second.end(), insert_iterator_2);

    print(my_intersect, "Intersection");
    return 0;
}
