#include <iostream>
#include <map>
#include <tuple>
using namespace std;

int main() {
    // declarations
    map<string, tuple<int, string, string>> v;

    // insert elements into the map
    // note how the right-hand side of the assignment are the vector elements
    v["Audie"] = make_tuple(5, "Wolf", "Foxtrot");
    v["Raymond"] = make_tuple(8, "Cat", "Nice fit");
    v.insert({"Marshal", make_tuple(7, "Squirrel", "Sulky")});

    int c = 0;
    int s;
    while(c != 4){
        cout << endl;
        cout << "1. Increase Friendship" << endl;
        cout << "2. Decrease Friendship" << endl;
        cout << "3. Search for Villager" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter choice: ";
        cin >> c;

        if(c == 1 || c == 2) {
            
        }
        
    }


    // access the map using a range-based for loop
    cout << "Villagers: " << endl;
    for (auto pair : v) {
        cout << pair.first << ": ";
        cout << get<0>(pair.second) << ", ";
        cout << get<1>(pair.second) << ", ";
        cout << get<2>(pair.second) << ", ";
        cout << endl;
    }

    // access the map using iterators
    cout << "\nVillagers:" << endl;
    for (map<string, tuple<int,string,string>>::iterator it = v.begin(); 
            it != v.end(); ++it) {
        cout << it->first << ": ";
        cout << get<0>(it->second) << ", ";
        cout << get<1>(it->second) << ", ";
        cout << get<2>(it->second);
        cout << endl;
    }

    // delete an element
    v.erase("Raymond");

    // search for an element using .find() to avoid errors
    string searchKey = "Audie";
    auto it = v.find(searchKey);
    if (it != v.end()) {  // the iterator points to beyond the end of the map
                                       // if searchKey is not found
        cout << "\nFound " << searchKey << ": ";
        cout << get<0>(it->second) << ", ";
        cout << get<1>(it->second) << ", ";
        cout << get<2>(it->second);
        cout << endl;
    } else
        cout << endl << searchKey << " not found." << endl;

    // report size, clear, report size again to confirm map operations
    cout << "\nSize before clear: " << v.size() << endl;
    v.clear();
    cout << "Size after clear: " << v.size() << endl;

    return 0;
}