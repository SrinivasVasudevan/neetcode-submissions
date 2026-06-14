class Solution {
public:
    int N;
    string S;
    int countPalindrome(int a, int b){
        int count=0;
        while(a >=0 && b < N){
            if(S[a] == S[b]){
                a--;
                b++;
                count++;
            }else{
                break;
            }
        }
        return count;
    }
    int countSubstrings(string s) {
        N = s.length();
        S=s;
        int sol=0;
        for(int i=0;i<N;i++){
            int count = countPalindrome(i, i);
            //cout<<sol<<" "<<count<<endl;
            sol+=count;
            if(i+1<N && s[i] == s[i+1]){
                count = countPalindrome(i,i+1);
                //cout<<count<<endl;
                sol+=count;
            }
            //cout<<sol<<endl;
        }
        return sol;
    }
};
