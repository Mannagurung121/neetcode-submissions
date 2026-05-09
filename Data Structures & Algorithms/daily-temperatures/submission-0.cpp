class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& arr) {
        vector<int>ans(arr.size(),0);
        stack<int>st;

        for(int i=0; i<arr.size(); i++){
            while(!st.empty() && arr[i]>arr[st.top()] ){
                int preIndex= st.top();
                 ans[preIndex]=i-preIndex;
                st.pop();
              
            }
            st.push(i);
        }
        return ans;
    }
};
