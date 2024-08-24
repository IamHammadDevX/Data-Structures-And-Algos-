#include<iostream>
using namespace std;


// struct of PetrolPump
struct petrolPump
{
    int petrol;
    int distance;
};

class circularTour
{

public:
    int tour(petrolPump arr[], int n)
    {
        int deficit = 0; //kami
        int balance = 0;
        int start = 0;


        // traverse the pumps
        for (int i = 0; i < n; i++)
        {
            balance += arr[i].petrol - arr[i].distance;
            if (balance < 0)
            {
                // kami kitne ki hai
                deficit += balance;
                start = i + 1;
                balance = 0;
            }

        }

        balance + deficit >= 0 ? return start : return -1;

    }


};




int main()
{

    circularTour cT;
    cT.tour(arr, 5);


    return 0;
}