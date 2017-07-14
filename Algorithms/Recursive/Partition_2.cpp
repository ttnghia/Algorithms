#include <iostream>
#include <algorithm>
#include <vector>
#include <cassert>

using namespace std;

bool canDivide(const vector<int>& A, int& sum)
{
    sum = 0;
    
    for(int x : A)
        sum += x;
    
    return !(sum % 1);
}

void printPartitions(const vector<int>& A, const vector<int>& group)
{
    assert(A.size() == group.size());
    
    cout << "Group 0: " << endl;
    for(size_t i = 0; i < A.size(); ++i)
        if(group[i] == 0)
            cout << A[i] << " - ";
    
    cout << "Group 1: " << endl;
    for(size_t i = 0; i < A.size(); ++i)
        if(group[i] == 1)
            cout << A[i] << " - ";
        
    cout << endl;
}     

void partition(const vector<int>& A, vector<int>& group, int currentSum, int i)
{
    if(i == int(A.size()))
    {
        if(currentSum == 0)
            printPartitions(A, group);
        return;
    }
       
    group[i] = 0;
    partition(A, group, currentSum, i + 1);
    group[i] = 1;
    partition(A, group, currentSum - A[i], i + 1);
}

bool partition_DP(const vector<int>& A, const vector<int>& group, int sum)
{
    int N = static_cast<int>(A.size());
    bool** L = new bool*[N + 1];
    for(int i = 0; i <= N; ++i)
        L[i] = new bool[sum + 1];
    
    // 0 item must sum to 0
    for(int j = 1; j <= sum; ++j)
        L[0][j] = false;
    
    // sum to 0 can be achieved by any number of items
    for(int i = 0; i <= N; ++i)
        L[i][0] = true;
    
    for(int i = 1; i <= N; ++i)
    {
        for(int j = 1; j <= sum; ++j)
        {
            if(A[i - 1] > j)
                L[i][j] = L[i - 1][j];
            else
                L[i][j] = L[i - 1][j] || L[i][j - A[i - 1]];
        }
    }
    
    return L[N][sum];
}



int main()
{
    vector<int> A = { 7, 3, 1, 5, 4, 8 };
    vector<int> group(A.size());
    int sum;
     
    if(!canDivide(A, sum))
        cout << "Cannot divide!" << endl;
    else
    {
        if(partition_DP(A, group, sum / 2))
            cout << "Success!" << endl;
        else
            cout << "Failed!" << endl;
        
        partition(A, group, sum / 2, 0);
    }
    
    return 0;
}