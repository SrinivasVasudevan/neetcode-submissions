class TimeMap {
public:
    unordered_map<string,vector<pair<int,string>>> mp;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back(make_pair(timestamp,value));
    }
    
    string get(string key, int timestamp) {
        int l=0,r=mp[key].size()-1;
        string out="";
        while(l<=r){
            int mid=(l+r)/2;
            if(timestamp>=mp[key][mid].first){
                out=mp[key][mid].second;
                l=mid+1;
            }
            else{
                r=mid-1;
            }
        }
        return out;
    }
};
