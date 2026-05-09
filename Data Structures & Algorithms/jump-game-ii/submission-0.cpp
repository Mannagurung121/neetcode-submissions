class Solution {
public:
    int jump(vector<int>& arr) {
        int jump=0;
    
        int left=0;
        int right=0;
        
        while(right<arr.size()-1){
            
        int currentFar=0;
        
        for(int i=left; i<=right; i++){
            currentFar=max(currentFar,i+arr[i]);
        }
            left=right+1;
             jump++;
            right=currentFar;
           
            if(right>arr.size()-1){
                return jump;
            }
            
        }
        
    
        return jump;
    }
};
