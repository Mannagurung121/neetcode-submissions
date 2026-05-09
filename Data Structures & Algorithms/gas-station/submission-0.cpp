class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int start=0;
        int balance=0;
        int require=0;
        int i=0;
        while(i<gas.size()){
        balance+=gas[i]-cost[i];
        if(balance<0){
            require+=balance;
            start=i+1;
           balance=0;
        }
        i++;
        }


        if(require+balance>=0){
            return start;
        }
        else{
            return -1;
        }
    }
};
