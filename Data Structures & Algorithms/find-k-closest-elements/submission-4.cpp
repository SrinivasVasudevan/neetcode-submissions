class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int> res;
        int n = arr.size();
        int l = 0, r = n-1;
        while(l<r){
            int mid = (l+r)/2;
            if(arr[mid] < x){
                l = mid+1;
            }else if(arr[mid] > x){
                r = mid-1;
            }else{
                l = mid;
                r = mid;
                break;
            }
        }
        int i = -1, j=-1, count = k;

        if(l == r){
            int left_val = INT_MAX, right_val = INT_MAX;
            if(l-1>=0) left_val = abs(arr[l-1]-x);
            if(r+1<=n-1) right_val = abs(arr[l+1]-x);
            if(left_val <= right_val){
                j=l;
                i=l-1;
            }else{
                i=l;
                j=l+1;
            }
        }else{
            i=min(l,r);
            j=max(l,r);
        }

        while(i>=0 && j<=n-1 && k){
            cout<<(abs(arr[i]-x) <= abs(arr[j]-x))<<" "<<i<<" "<<j<<" "<<k<<endl;
            if(abs(arr[i]-x) <= abs(arr[j]-x)){
                res.push_back(arr[i]);
                i--;
            }else{
                res.push_back(arr[j]);
                j++;
            }
            k--;
        }

        while(k && i>=0){
            res.push_back(arr[i--]);
            k--;
        }
        while(k && j<=n-1){
            res.push_back(arr[j++]);
            k--;
        }

        sort(res.begin(), res.end());
        return res;
    }
};