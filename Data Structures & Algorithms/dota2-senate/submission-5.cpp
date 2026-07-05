class Solution {
public:
    string predictPartyVictory(string senate) {
        int n = senate.size();
        vector<int> rights(n, 1);
        int r_index = 0, d_index = 0;
        int r_vote = 0, d_vote = 0;
        
        for(auto party: senate){
            if(party == 'R'){
                r_vote++;
            }else{
                d_vote++;
            }
        }

        while(r_vote && senate[r_index%n] != 'R'){
            r_index++;
        }
        while(d_vote && senate[d_index%n] != 'D'){
            d_index++;
        }
        int i=0;
        while(r_vote && d_vote){
            if(!rights[i%n]){
                i++;
                continue;
            }
            if(senate[i%n] == 'R'){
                rights[d_index%n] = 0; 
                d_vote--;
            }else{
                rights[r_index%n] = 0;
                r_vote--;
            }
            r_index++;
            d_index++;
            while(r_vote){
                if(senate[r_index%n] == 'R' && rights[r_index%n]) break;
                r_index++;
            }
            while(d_vote){
                if(senate[d_index%n] == 'D' && rights[d_index%n]) break;
                d_index++;
            }
            //cout<<r_vote<<" "<<d_vote<<" "<<i%n<<endl;
            i++;
            
        }

        return r_vote > d_vote ? "Radiant" : "Dire";
    }
};