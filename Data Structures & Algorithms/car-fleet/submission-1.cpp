class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,int>> p;
        for(int i=0;i<position.size();i++){
            p.push_back(std::make_pair(position[i],speed[i]));
        }
        sort(p.begin(), p.end());
        int n=p.size();
        float slowestSoFar;
        int fleet=0;
        for(int i=n-1;i>=0;i--){
            if(fleet==0){
                slowestSoFar=(float)(target-p[i].first)/(float)p[i].second;
                fleet++;
            }else{
                float newSpeed=(float)(target-p[i].first)/(float)p[i].second;
                if(newSpeed > slowestSoFar){
                    fleet++;
                    slowestSoFar=newSpeed;
                }
            }
        }
        return fleet;
    }
};
