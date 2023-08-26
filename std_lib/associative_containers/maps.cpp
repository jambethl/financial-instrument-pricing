#include <map>
#include <iostream>
#include <string>

using namespace std;

int main() {

    map<string, double> option;

    option["r"] = 0.10;     // interest rate
    option["sig"] = 0.28;   // volatility
    option["K"] = 19.0;     // strie price
    option["T"] = 0.75;     // expiry date
    option["S"] = 19.0;     // underlying asset
    
    cout << "Size of map: " << option.size() << endl;

    map<string, double>::iterator i = option.begin();
    while (i != option.end()) {
        cout << "Element pair [" << (*i).first << "," << (*i).second << "]" << endl;
        i++;
    }

    return 0;
}
