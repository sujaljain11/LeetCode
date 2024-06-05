class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int maxArea = 0;
        stack<int> st;
        int n = heights.size();
        for(int i = 0; i <= n; i++) {
            if(i == n) {
                while(!st.empty()) {
                    int x = heights[st.top()];
                    st.pop();
                    int width;
                    if(st.empty()) width = i;
                    else width = i - st.top() -1;
                    maxArea = max(maxArea, x * width);
                }
            }
            else if(st.empty()) st.push(i);
            else {
                while(!st.empty() && heights[i] <= heights[st.top()]) {
                    int x = st.top();
                    st.pop();
                    int width;
                    if(st.empty()) width = i;
                    else width = i - st.top() - 1;
                    maxArea = max(maxArea, heights[x] * width);
                }
                st.push(i);
            }
        }
        return maxArea;
    }
};




/*
int largestRectangleArea(vector < int > & histo) {
      stack < int > st;
      int maxA = 0;
      int n = histo.size();
      for (int i = 0; i <= n; i++) {
        while (!st.empty() && (i == n || histo[st.top()] >= histo[i])) {
          int height = histo[st.top()];
          st.pop();
          int width;
          if (st.empty())
            width = i;
          else
            width = i - st.top() - 1;
          maxA = max(maxA, width * height);
        }
        st.push(i);
      }
      return maxA;
    }
*/