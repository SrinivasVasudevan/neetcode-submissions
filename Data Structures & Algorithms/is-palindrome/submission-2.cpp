class Solution {
public:
    bool isPalindrome(string s) {
        int n=s.length()/2;
        int rev=s.length()-1;
        for(int i=0;i<rev;){
            while(!isalnum(s[i]) && i!=rev) i++;
            while(!isalnum(s[rev]) && rev!=i) rev--;
            cout<<i<<" "<<rev<<" "<<s.length()<<endl;
            if(tolower(s[i])!=tolower(s[rev])){
                return false;
            }
            if(i==rev) break;
            i++;
            rev--;
        }
        return true;
    }
};
