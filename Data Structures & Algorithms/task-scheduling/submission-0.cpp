class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        std::priority_queue<int> pq;
        std::unordered_map<char,int> mp;
        std::queue<pair<int,int>> q;
        for(auto t: tasks){
            mp[t]++;
        }
        for(auto &[k,v]:mp){
            pq.push(v);
        }
        cout<<pq.size()<<endl;
        int t=1;
        while(!(q.empty() && pq.empty())){
            if(q.size()>0&&q.front().second<=t){
                pq.push(q.front().first);
                q.pop(); 
            }
            if(pq.size()>0){
                int v=pq.top();
                //cout<<v<<" "<<t<<endl;
                pq.pop();
                if(v-1>0) q.push(std::make_pair(v-1,t+n+1));
            }
            //cout<<q.front().first<<q.front().second<<endl;
            t++;
            //if(t==4) break;
        }
        return t-1;
    }
};
