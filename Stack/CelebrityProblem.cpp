#include<iostream>
#include<stack>
#include<vector>
using namespace std;


// CELEBRITY PROBLEM
// 1 - CELEB. knows NO-ONE!
// 2 - EVERYONE KNOWS CELEB

// knows function
bool knows(vector<vector<int> >& matrix, int size, int a, int b) {
    if (matrix[a][b] == 1)
    {
        return true;
    }
    else
    {
        return false;
    }


}

int celebrity(vector<vector<int> >& matrix, int size) {

    // 1- putt all persons in stack
    stack<int> st;

    for (int i = 0; i < size; i++)
    {
        st.push(i);
    }

    // 2- jab tk 1 person stack me hai compare kerta ja
    while (st.size() > 1)
    {
        // take two persons and compare
        int person1 = st.top();
        st.pop();

        int person2 = st.top();
        st.pop();

        if (knows(matrix, size, person1, person2))
        {
            // person1 knows person2 = mean person2 will be celeb
            st.push(person2);
        }
        else
        {   // person1 will be CELEB!
            st.push(person1);
        }
    }
    // PROBABLY PERSON NIKAL LE
    int candidate = st.top();

    // 3 - jo single elem hai wo potential candidate hai
    // verify = celeb. rules

    // celeb kisi ko nahi janta mtlb rows 0's all
    int zeroCnt = 0;
    for (int i = 0; i < size; i++)
    {
        if (matrix[candidate][i] == 0)
            zeroCnt++;
    }

    // check whether all zero
    if (zeroCnt != size)
        return -1;


    // check col  all elems must b 1's except digonal elem
    int oneCnt = 0;
    for (int i = 0; i < size; i++)
    {
        if (matrix[i][candidate] == 1)
        {
            oneCnt++;
        }

    }

    // check digonal elem
    if (oneCnt != size - 1)
        return -1;


    return candidate;
}


int main()
{

    vector<vector<int> > matrix = {
                                    {0, 1, 0},
                                    {0, 0, 0},
                                    {0, 1, 0} };

    int size = 3;
    int celeb = celebrity(matrix, size);

    cout << "Celebrity is: " << celeb << endl;

    return 0;
}