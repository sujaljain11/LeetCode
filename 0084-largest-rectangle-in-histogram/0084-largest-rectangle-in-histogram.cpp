class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack <int> stack1;
        int result = 0;
        int n = heights.size();
        vector<int> leftSmallest(n, -1), rightSmallest(n, -1);
        for(int i = 0; i < n; i++) {
            while(!stack1.empty() && heights[stack1.top()] >= heights[i]) {
                stack1.pop();
            }
            if(stack1.empty()) leftSmallest[i] = 0;
            else leftSmallest[i] = stack1.top() + 1;
            stack1.push(i);
        }
        while(!stack1.empty()) stack1.pop();
        for(int i = n-1; i > -1; i--) {
            while(!stack1.empty() && heights[stack1.top()] >= heights[i]) {
                stack1.pop();
            }
            if(stack1.empty()) rightSmallest[i] = n-1;
            else rightSmallest[i] = stack1.top() - 1;
            stack1.push(i);
        }
        for(int i = 0; i < n; i++) {
            result = max(result, heights[i] * (rightSmallest[i] - leftSmallest[i] + 1));
        }
        return result;
    }
};