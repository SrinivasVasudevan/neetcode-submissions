class Solution {
public:
    int N;
    string passedString;
    string generatePalindrome(int a, int b){
        while(a >= 0 && b < N){
            if(passedString[a] == passedString[b]){
                a--;
                b++;
            }else{
                break;
            }
        }
        return passedString.substr(a+1, b-a-1);
    }

    string longestPalindrome(string s) {
        N = s.length();
        passedString = s;
        string longestString = "";
        for(int i=0;i<N;i++){
            string temp1 = generatePalindrome(i, i);
            if(temp1.length() > longestString.length()){
                longestString = temp1;
            }
            if(i+1<N && s[i] == s[i+1])
            {
                string temp2 = generatePalindrome(i, i+1);
                if(temp2.length() > longestString.length()){
                    longestString = temp2;
                }
            }
            
        }
        return longestString;
    }
};
