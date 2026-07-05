class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> st;
        for(auto operation: operations){
            if(operation == "+"){
                int one = st.top();
                st.pop();
                int two = st.top();
                st.pop();
                st.push(two);
                st.push(one);
                st.push(one+two);
                //cout<<one<<two<<endl;
            }else if(operation == "D"){
                int no = st.top();
                st.push(no*2);
            }else if(operation == "C"){
                st.pop();
            }else{
                st.push(stoi(operation));
            }
            
        }
        int res = 0;
        while(!st.empty()){
            //cout<<st.top()<<endl;
            res+=st.top();
            st.pop();
        }
        return res;
    }
};