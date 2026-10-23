#include <iostream>
#include <map>
#include <tuple>
#include <string>
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
    int f;
    string s;
    string sp;
    string ca;
    while(c != 6){
        cout << endl;
        cout << "1. Add vilager" << endl;
        cout << "2. Remove villager" << endl;
        cout << "3. Increase Friendship" << endl;
        cout << "4. Decrease Friendship" << endl;
        cout << "5. Search for Villager" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter choice: ";
        cin >> c;

        if(c == 1){
            cout << "Villager name: ";
                cin >> s;
                cout << "Friendship level: ";
                cin >> f;
                cout << "Species: ";
                cin >> sp;
                cout << "Catchphrase: ";
                cin.ignore();
                getline(cin,ca);

                v[s] = make_tuple(f,sp,ca);
                cout << s << " added." << endl;
        } else { 
            cout << "Name: ";
            cin >> s;
            auto it = v.find(s);

            if(c==2){
                if(v.erase(s)){
                    cout <<  s << "deleted" << endl;
                } else {
                    cout << "Not found" << endl;
                }
            } else if(it == v.end()) {
                cout << "N/A" << endl;
            } else if(c==3 && get<0>(it->second) < 10){ //prevents freindlyness overflow
                get<0>(it->second)++;
            } else if(c==4 && get<0>(it->second) > 0){ //prevents unfreindlyness overflow
                get<0>(it->second)--;
            } else if (c == 5) {
                cout << it->first << " [" << get<0>(it->second) << ", " << get<1>(it->second) << ", " << get<2>(it->second) << "]" << endl;
            }
         }

         cout << "_______ LIST ______" << endl;
         for(auto p : v){
            cout << p.first << " [" << get<0>(p.second) << ", " << get<1>(p.second) << ", " << get<2>(p.second) << "]" << endl;
         }

        
    }

    return 0;
}