class Solution {
public:
    string convertToTitle(int columnNumber) {
        //calibrate for 0 - 25
        
        string res="";
        
        while(columnNumber){
            columnNumber--;
            int temp=columnNumber%26;
            columnNumber/=26;
            res+=(temp+'A');
        }
        reverse(res.begin(), res.end());
        return res;

    }
};