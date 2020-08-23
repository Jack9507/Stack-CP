#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007

int sum_of_subarrays_minimum(vector<int> arr)
{
       int n=arr.size();

      vector<int> g1(n,-1);  // stores index of next smaller element
      vector<int> g2(n,-1);  // stores index of previous smaller element

    stack<int> s1;
    // finding the index of next smaller element
    for(int i=0; i<n; i++)
    {
        while(!s1.empty() && arr[i] < arr[s1.top()])
        {
            g1[s1.top()]= i ;
            s1.pop();
        }
        s1.push(i);
    }
    // now finding the index of previous smaller element
    stack<int> s2;
    for(int i=n-1; i>=0; i--)
    {
        while(!s2.empty() && arr[i] <= arr[s2.top()])  // '=' because 2 element scan be same in array
        {
            g2[s2.top()] = i;
            s2.pop();
        }
        s2.push(i);
    }

   int res=0;
    for(int i=0; i<n; i++)
    {
      int next_nums= n-i-1;
      int prev_nums=i;
        if(g1[i] != -1)
            next_nums = g1[i] - i -1;
        if(g2[i] != -1)
            prev_nums = i -g2[i]-1;

      res += arr[i] * (next_nums + 1)* (prev_nums + 1);
        res %=mod;
    }

    return res;

}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> arr={3,1,2,4};

    cout<<sum_of_subarrays_minimum(arr)<<endl;



    return 0;
}

/*
example for understanding : -
for element '2'  find the number of elements greater than '2' in right hand and left hand side
    find the index of next smaller element than '2', the next smaller element form '2' is 1 which is at index 8
    so numbers which are greater than '2' on its right are = (8 - 4)-1=3; where  '4' is the index of '2'.
    if we don't get the next smaller element than all the elements on right are bigger than '2' so total will be = (n-4)-1; , where n is size of array

    similarly find the prev smaller element than '2'
    here prev smaller element is 1 which is at index '1' so total number of elements bigger than '2' on left = (4-1)-1 =2;
     if we don't get the prev smaller element than all the elements on left are  bigger than '2' so total becomes the current index of '2' i.e 4 elements.

arr= 3,1,4,5,2,6,4,3,1
452
4526
45264
452643
52
526
5264
52643
2
26
264
2643
total =12 subarrays in which '2' will be minimum
number of elements greater than'2' in right =3 i.e(6,4,3)
number of elements greater than'2' in left =2 i.e(4,5)
so total possible subarrays in which '2' will be min is (2+1)* (3+1) = 12
so the contribution in sum for element '2' will be 2* (2+1) * (3+1);
*/
