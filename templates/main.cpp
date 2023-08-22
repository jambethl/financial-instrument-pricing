#include <iostream>
using namespace std;

template <class Type> class Range {
    private:
        Type hi;
        Type lo;

    public:

        Range();
        Range(const Type& low, const Type& high);
        Range(const Range<Type>& ran2);

        virtual ~Range();

        void low(const Type& t1);
        void high(const Type& t1);

        Type low() const;
        Type high() const;

        Type spread() const;

        bool left(const Type& value) const;
        bool right(const Type& value) const;
        bool contains(const Type& value) const;
};

template <class Type> Range<Type>::Range(const Type& low, const Type& high) {
    lo = low;
    hi = high;
}

template <class Type> Range<Type>::Range(const Range<Type>& r2) {
    lo = r2.lo;
    hi = r2.hi;
}

template <class Type> Range<Type>::~Range() {
    cout << "Destructor called" << endl;
}

template <class Type> bool Range<Type>::left(const Type& value) const {
    return value < lo;
}

template <class Type> bool Range<Type>::right(const Type& value) const {
    return value > hi;
}

template <class Type> Type Range<Type>::spread() const {
    return hi - lo;
}

template <class Type> bool Range<Type>::contains(const Type& t) const {
    if ((lo <= t) && (hi >= t)) {
        return true;
    }
    return false;
}

template <class Any> void swapper(Any& first, Any& second) {
    Any tmp = first;

    first = second;
    second = tmp;
}


int main() {

    double closingPrice(45.7);
    double openingPrice(60.0);
    Range<double> bearish(closingPrice, openingPrice);

    double currentPrice = 50.0;

    bool test1 = bearish.left(currentPrice);
    bool test2 = bearish.right(currentPrice);
    bool test3 = bearish.contains(currentPrice);

    if (test1 == false && test2 == false && test3) {
        cout << "Everything OK\n";
    }

    int i = 10;
    int j = -1435;
    swapper(i, j);

    if (j == 10 && i == -1435) {
        cout << "Template function OK" << endl;
    }
    return 0;
}
