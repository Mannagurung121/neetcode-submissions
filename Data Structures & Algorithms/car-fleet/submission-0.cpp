class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n=position.size();
        vector<pair<int,double>>Cars;
        for(int i=0; i<n; i++){
            double time=(double)(target-position[i])/speed[i];
            Cars.push_back({position[i],time});
        }
       sort(Cars.rbegin(), Cars.rend());
        int fleet=0;
        double timeFleet=0.0;
        for(auto car:Cars){
            double timee=car.second;
            if(timee>timeFleet){
                fleet++;
                timeFleet=timee;
            }

        }

return fleet;

    }
};
