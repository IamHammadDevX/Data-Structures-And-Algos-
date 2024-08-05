#include<iostream>
using namespace std;

#define PI 3.14
#define min(a,b) (((a) < (b) ? (a) : (b)))


int main() {

    int radius = 8;
    double area = PI * radius * radius;
    cout << "Area is => " << area << endl;
    int a = 18, b = 78;
    cout << "Minimum value between => " << a << " & " << b << " is =>" << min(a, b) << endl;

    return 0;
}