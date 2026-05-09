class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st;
        int maxi = 0;
        int count = 0;
        for (int i = 0; i < nums.size(); i++) {
            st.insert(nums[i]);
        }

        for (auto it : st) {
            if (st.find(it-1) == st.end()) {
                count = 1;
                int x = it;
                while (st.find(x + 1) != st.end()) {
                    count++;
                    x = x + 1;
                }
                maxi = max(maxi, count);
            }
        }
        return maxi;
    }
};
