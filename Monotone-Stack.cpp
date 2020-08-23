#include<bits/stdc++.h>
using namespace std;

void  next_greater_element(int arr[], int n)
{
    // maintain decreasing stack
    stack<int> s;
    vector<int> res(n,-1);

    for(int i=0; i<n; i++)
    {
        while(!s.empty() && arr[i] > arr[s.top()])
        {
            res[s.top()]=arr[i];
            s.pop();
        }
        s.push(i);
    }
    for(auto x: res)
        cout<<x<<'\t';
    cout<<endl;

}

void prev_greater_element(int arr[], int n)
{
    //this is same as next greater element just traverse the array from right
    // maintain decreasing stack for previous greater element
    stack<int> s;
    vector<int> res(n,-1);
    for(int i=n-1; i>=0; i--)    //running n times
    {
        while(!s.empty() && arr[i] > arr[s.top()])
        {
            res[s.top()]= arr[i];
            s.pop();
        }
        s.push(i);

    }

    for(auto x: res)
        cout<<x<<'\t';
    cout<<endl;


}
int next_smaller_element(int arr[], int n)
{
    //  here we have to maintain the stack in increasing order and the rest concept is same
    stack<int> s;
    vector<int> res(n, -1);

    for(int i=0; i<n; i++)
    {
        while(!s.empty() && arr[i] < arr[s.top()])  // pop when current array element becomes less then the element on stack top.
        {
            res[s.top()] = arr[i];
            s.pop();
        }
        s.push(i);
    }

    for(auto x : res)
      cout<<x<<'\t';
      cout<<endl;
}


int prev_smaller_element(int arr[], int n)
{
    // same concept as next smaller element just traverse the array from right
    stack<int> s;
    vector<int> res(n, -1);
    for(int i=n-1; i>=0; i--)
    {
        while(!s.empty() && arr[i] < arr[s.top()])
        {
            res[s.top()]= arr[i];
            s.pop();
        }
        s.push(i);
    }

    for(auto x: res)
        cout<<x<<'\t';
    cout<<endl;

}


int32_t main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

     //int arr[]={2,1,3,4,1,2,6};
     int arr[]={71,55,82,55};
     int n=sizeof(arr)/sizeof(arr[0]);
     for(int x: arr)
        cout<<x<<'\t';
     cout<<endl<<endl;
      next_greater_element(arr,n);
      cout<<endl;
      prev_greater_element(arr,n);
      cout<<endl;
      next_smaller_element(arr,n);
      cout<<endl;
      prev_smaller_element(arr,n);
      cout<<endl;

    return 0;
}

