class Solution {
public:
    int largestRectangleArea(vector<int>& heights) 
    {
        if(heights.size()==0)
            return 0;
        int n=heights.size();
        vector<int> next_smaller(n, -1);
        vector<int> prev_smaller(n, -1);
        
        stack<int> s1;
        stack<int> s2;
        for(int i=0; i<n; i++)
        {
            while(!s1.empty() && heights[i] < heights[s1.top()])
            {
                next_smaller[s1.top()] =i;
                s1.pop();
            }
            s1.push(i);
        }
        
        for(int i=n-1; i>=0; i--)
        {
            while(!s2.empty() && heights[i] < heights[s2.top()])
            {
                prev_smaller[s2.top()] =i;
                s2.pop();
            }
            s2.push(i);
        }
        
        int max_area=INT_MIN;
        
        for(int i=0; i<n; i++)
        {
            int g1=0;   // number of elements bigger than the current element on right hand side
            int g2=0;    // number of elements bigger on the left hand side
            if(next_smaller[i] != -1)
                g1= next_smaller[i] - i -1;
            else
                g1= n-i-1;
            if(prev_smaller[i] != -1)
                g2=  i -prev_smaller[i] -1;
            else
                g2= i;
            // calculating area 
            int length = heights[i];
            int width = g1+g2+1;
            max_area =max(max_area, length*width);   
        }
        return max_area;
    }
};
