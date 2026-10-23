#include <iostream>
#include <map>
#include <tuple>
using namespace std;

int main() {
    // declarations
    map<string, tuple<int, string, string>> villagerColors;

    // insert elements into the map
    // note how the right-hand side of the assignment are the vector elements
    villagerColors["Audie"] = make_tuple(5, "Wolf", "Foxtrot");
    villagerColors["Raymond"] = make_tuple(8, "Cat", "Nice fit");
    villagerColors.insert({"Marshal", make_tuple(7, "Squirrel", "Sulky")});

    // access the map using a range-based for loop
    cout << "Villagers: " << endl;
    for (auto pair : villagerColors) {
        cout << pair.first << ": ";
        cout << get<0>(pair.second) << ", ";
        cout << get<1>(pair.second) << ", ";
        cout << get<2>(pair.second) << ", ";
        cout << endl;
    }

    // access the map using iterators
    cout << "\nVillagers:" << endl;
    for (map<string, tuple<int,string,string>>::iterator it = villagerColors.begin(); 
            it != villagerColors.end(); ++it) {
        cout << it->first << ": ";
        cout << get<0>(it->second) << ", ";
        cout << get<1>(it->second) << ", ";
        cout << get<2>(it->second);
        cout << endl;
    }

    // delete an element
    villagerColors.erase("Raymond");

    // search for an element using .find() to avoid errors
    string searchKey = "Audie";
    auto it = villagerColors.find(searchKey);
    if (it != villagerColors.end()) {  // the iterator points to beyond the end of the map
                                       // if searchKey is not found
        cout << "\nFound " << searchKey << "'s favorite colors: ";
        for (auto color : it->second)  // range loop to traverse the value/vector
            cout << color << " ";
        cout << endl;
    } else
        cout << endl << searchKey << " not found." << endl;

    // report size, clear, report size again to confirm map operations
    cout << "\nSize before clear: " << villagerColors.size() << endl;
    villagerColors.clear();
    cout << "Size after clear: " << villagerColors.size() << endl;

    return 0;
}