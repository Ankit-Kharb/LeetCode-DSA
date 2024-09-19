class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
        int st=m-1;
        int en=n-1;
        
        int pos=m+n-1;
        
        while(st>=0 and en>=0)
        {
            if(nums1[st]>nums2[en])
            {
                nums1[pos]=nums1[st];
                st--;
                pos--;
            }
            else
            {
                nums1[pos]=nums2[en];
                en--;
                pos--;
            }
        }
        while(st>=0)
        { nums1[pos]=nums1[st];
                st--;
                pos--;
            
        }
        while(en>=0)
        {
             nums1[pos]=nums2[en];
                en--;
                pos--;
        }
    }
};