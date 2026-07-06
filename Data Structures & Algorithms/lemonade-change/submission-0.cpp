class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        unordered_map<int, int> mp;
        for(auto bill: bills){
            cout<<bill<<endl;
            if(bill == 5){
                mp[bill]+=1;
            }else if(bill == 10){
                if(mp.count(5)){
                    mp[5]--;
                    if(!mp.count(5)) mp.erase(5);
                }else{
                    return false;
                }
                mp[10]++;
            }else{
                if((mp.count(10) && mp[10] >= 1 && mp.count(5) && mp[5] >= 1)){
                    mp[10]--;
                    mp[5]--;
                }else if((mp.count(5) && mp[5] >= 3)){
                    mp[5]-=3;
                }else{
                    return false;
                }
                if(!mp.count(5)) mp.erase(5);
                if(!mp.count(10)) mp.erase(10);
                mp[20]++;
            }
        }
        return true;
    }
};