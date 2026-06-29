class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1 == "0" || num2 == "0") return "0";
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());

        vector<int> res(num1.size()+num2.size(),0);

        for(int i=0;i<num1.size();i++){
            for(int j=0;j<num2.size();j++){
                int temp = (num1[i]-'0')*(num2[j]-'0');
                res[i+j] += temp;
            }
        }

        for(int i=0;i<res.size()-1;i++){
            res[i+1] += res[i]/10;
            res[i] %= 10; 
        }

        stringstream resS;

        int loc = res.size()-1;
        
        while(loc>=0 && res[loc] == 0){
            loc--;
        }

        while(loc>=0){
            resS << (res[loc--]);
        }

        return resS.str();

    }
};
