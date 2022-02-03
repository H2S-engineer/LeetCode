class Solution {
public:
    int removeDuplicates(vector<int>& nums) 
    {
        int i=0;
        int j=1;
        
        while (j<nums.size())
        {
            if (nums[j]==nums[i])
            {
                j++;
            }
            else
            {
                i++;
                swap(nums[i],nums[j]);
                j++;
            }
        }
        return i+1;
    }
};
