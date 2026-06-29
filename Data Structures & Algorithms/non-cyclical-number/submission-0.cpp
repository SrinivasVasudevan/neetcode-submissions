class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> numberSeen;
        int num=n;
 
        while(true){
            int interNum = 0;
            while(num){
                int temp=num%10;
                interNum+=pow(temp,2);
                num/=10;
            }
            if(interNum==1) return true;
            else if(numberSeen.contains(interNum)){
                return false;
            }
            else{
                num=interNum;
                numberSeen.insert(num);
            }
            
        }
        return false;
    }
};
