#include <bits/stdc++.h>
using namespace std;
//funnction to maxArea of histogram

int getArea(int arr[],int n)
{
   //create a empty stack
    stack<int> s;
    //we push -1 to the stack because for some elements there will be no previous
    //smaller element in the array and we can store -1 as the index for previous smaller.

    s.push(-1);
    //to calculate the area
    int area = arr[0];
    int i=0;
     //We declare left_smaller and right_smaller array of size n and initialize them with -1 and n as their default value.
    //left_smaller[i] will store the index of previous smaller element for ith element of the array.
    //right_smaller[i] will store the index of next smaller element for ith element of the array.
   //Vector is a template class in STL (Standard Template Library) of C++ programming language. C++ vectors are sequence containers that store elements.
    vector<int> left_smaller(n,-1),right_smaller(n,n);
    //ith is the base from which we have to find the boundary
    while(i<n)
    {
         //if the current element is smaller than element with index stored on the
            //top of stack then, we pop the top element and store the current element index
            //as the right_smaller for the poped element.
            //the third  condition is that it will iterate until it found current element greater than ith element
        while(!s.empty()&&s.top()!=-1&&arr[s.top()]>arr[i])
        {
            //if the current element is smaller than element with index stored on the
            //top of stack then, we pop the top element and store the current element index
            //as the right_smaller for the poped element.
            right_smaller[s.top()] = i;
            s.pop();

        }
        if(i>0 && arr[i]==arr[i-1])
        {
            //we use this condition to avoid the unnecessary loop to find the left_smaller.
            //since the previous element is same as current element, the left_smaller will always be the same for both.
            left_smaller[i] = left_smaller[i-1];
        }
        else
        {
            
            //Element with the index stored on the top of the stack is always smaller than the current element.
            //Therefore the left_smaller[i] will always be s.top().
            left_smaller[i] = s.top();
        }
        s.push(i);
    i++;
    }
    

    for(int j=0;j<n;j++)
    {
        area = max(area,arr[j]*(right_smaller[j]-left_smaller[j]-1));
    }
    return area;
    

}
int main(){
    int hist[] = {6, 2, 5, 4, 5, 1, 6};
    int n = sizeof(hist)/sizeof(hist[0]);
      cout << "maxArea = " << getArea(hist, n) << endl;
    

return 0;
}