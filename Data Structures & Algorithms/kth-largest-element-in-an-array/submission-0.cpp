class Solution {
public:
    int findKthLargest(vector<int>& arr, int k) {
      priority_queue<int,vector<int>,greater<int>>pq;
    for(int i=0; i<arr.size();i++){
        pq.push(arr[i]);
    }
    
    for(int i=k; i<arr.size(); i++){
        int front=pq.top();
        pq.pop();
    }
    return pq.top();  
    }
};
