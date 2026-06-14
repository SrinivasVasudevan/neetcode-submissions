class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size()>nums2.size()){
            return findMedianSortedArrays(nums2,nums1);
        }
        int l=0,r=nums1.size();
        int m=nums1.size(),n=nums2.size();
        int c=(m+n)/2;
        while(l<=r){
            int mid=(l+r)/2;
            int l1=mid==0?INT_MIN:nums1[mid-1];
            int r1=mid==m?INT_MAX:nums1[mid];
            int l2=c-mid==0?INT_MIN:nums2[c-mid-1];
            int r2=c-mid==n?INT_MAX:nums2[c-mid]; 
            cout<<l1<<" "<<r1<<endl;
            cout<<l2<<" "<<r2<<endl;

            if(l1<=r2 && l2<=r1){
                if((m+n)%2 == 0) return (max(l1,l2)+min(r1,r2))/(double)2;
                else return min(r1,r2);
            }else if(l2 > r1){
                l=mid+1;
            }else if(l1 > r2){
                r=mid-1;
            }
        }
        return -1;
    }
};
