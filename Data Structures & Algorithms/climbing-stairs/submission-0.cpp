class Solution {
public:
    int climbStairs(int n) {
        vector<int> sol(n+1, 0);
        sol[n]=1;
        for(int k=n;k>=0;k--){
            for(int jump=1;jump<=2;jump++){
                if(k+jump<=n){
                    cout<<k<<" "<<jump<<" "<<sol[k+jump]<<endl;
                    sol[k]+=sol[k+jump];
                }
            }
        }
        return sol[0];
    }
};
