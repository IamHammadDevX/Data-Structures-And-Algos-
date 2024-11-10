#include<iostream>
#include<map>
#include<unordered_map>
using namespace std;




int main()
{

    // Hashmaps Creation
    unordered_map<string, int> m;

    // Insertion
    // ways to insert into map
    // 1st way
    pair<string, int> p = make_pair("Virat", 5);
    m.insert(p);

    // 2nd way
    pair<string, int> pair2("Kohli", 6);
    m.insert(pair2);

    // 3rd way
    m["RunMachine"] = 18;
    // what will happen?????
    m["RunMachine"] = 100; //modify

    // Searching
    cout << m["Virat"] << endl;
    cout << m["Kohli"] << endl;
    cout << m.at("RunMachine") << endl;
    cout << m.at("Virat") << endl;

    // error and exceptions
    // cout << m.at("unknownKey") << endl; //terminate called after throwing an instance of 'std::out_of_range' what():  unordered_map::at

    cout << m["unknownKey"] << endl; //0 will occur because it will create entry 0 against this key

    // size
    cout << "Size: " << m.size() << endl;

    // count() = will give 0 for absent and 1 for present
    cout << m.count("Virat") << endl;
    cout << m.count("Gabba") << endl;

    cout << "Size: " << m.size() << endl;
    // Erase
    cout << m.erase("Gabba") << endl;
    cout << "Size: " << m.size() << endl;

    // iterators
    unordered_map<string, int> ::iterator it = m.begin();

    // due to unordered_map data will be printed in unordered form and if want to print in ordered then use map
    while (it != m.end())
    {
        cout << it->first << " " << it->second << endl;
        it++;
    }


    return 0;
}