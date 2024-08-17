#include<iostream>
#include<math.h>
using namespace std;

// Get Bit
int getBit(int n, int po) {

    int ans = ((n & (1 << po)) != 0);

    return ans;
}


// set bit
int setBit(int n, int po) {

    int ans = (n | (1 << po));

    return ans;
}

// clear bit
int clearBit(int n, int po) {

    int mask = ~(1 << po);

    return (n & mask);

}

// update bit
int updateBit(int n, int po, int val) {
    int mask = ~(1 << po);
    n = n & mask;
    return (n | (val << po));
}




int main()
{


    cout << "Get Bit at 2nd position: " << getBit(5, 2) << endl;
    cout << "Set Bit 1 at 1st position: " << setBit(5, 1) << endl;
    cout << "Clear Bit 0 at 2nd position: " << clearBit(5, 2) << endl;
    cout << "Update Bit: " << updateBit(5, 1, 1) << endl; // 5 = 0101= 0111


    return 0;
}