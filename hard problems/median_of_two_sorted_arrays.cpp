//https://leetcode.com/problems/median-of-two-sorted-arrays/
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size(),n2=nums2.size();
        if(n1>n2)return findMedianSortedArrays(nums2,nums1);
        int left=(n1+n2+1)/2,total=n1+n2;
        int l=0,h=n1;
        while(l<=h){
            int mid1=(l+h)/2;
            int mid2=left-mid1;
            int l1=INT_MIN,l2=INT_MIN,r1=INT_MAX,r2=INT_MAX;
            if(mid1<n1)r1=nums1[mid1];
            if(mid2<n2)r2=nums2[mid2];
            if(mid1>=1)l1=nums1[mid1-1];
            if(mid2>=1)l2=nums2[mid2-1];
            if(l1>r2){
                h=mid1-1;
            }
            else if(l2>r1){
                l=mid1+1;
            }
            else{
                if(total%2==0){
                    return (double)((max(l1,l2)+min(r1,r2))/2.0);
                }
                return (double)max(l1,l2);
            }
        }
        return -1;
    }
};