class MedianFinder {
public:
int find( int a , int b){
if(a==b){
    return 0;
}
else if( a>b){
    return 1;
}
else{
    return-1;
}
}

void helper(double elm, double &median,priority_queue<double> &maxHeap,priority_queue<double,vector<double>,greater<double>>&minHeap )
{
switch (find(maxHeap.size(),minHeap.size())){

case 0: if(elm>median){
    minHeap.push(elm);
    median=minHeap.top();
}
else{
    maxHeap.push(elm);
    median=maxHeap.top();
}
break;


case 1: if(elm>median){
    minHeap.push(elm);
    median=(minHeap.top()+maxHeap.top())/2;
}
else{
   minHeap.push(maxHeap.top());
   maxHeap.pop();
   maxHeap.push(elm);
    median=(minHeap.top()+maxHeap.top())/2;
}
break;

case -1: if(elm>median){
    maxHeap.push(minHeap.top());
    minHeap.pop();
    minHeap.push(elm);
      median=(minHeap.top()+maxHeap.top())/2;
}
else{
   maxHeap.push(elm);
    median=(minHeap.top()+maxHeap.top())/2;
}
}
}


priority_queue<double> maxHeap;
priority_queue<double,vector<double>,greater<double>>minHeap;
double median=0;
    MedianFinder() {
    }
    
    void addNum(int num) {
     helper(num,median,maxHeap,minHeap);
    }
    
    double findMedian() {
    

        
        return median;
    

    }
};
