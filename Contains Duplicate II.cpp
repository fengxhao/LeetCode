//Contains Duplicate 2
// Given an array of integers and an integer k, 
//find out whether there are two distinct indices i and j in the array such that
// nums[i] = nums[j] and the difference between i and j is at most k.
//题目主要是查找vector中两个数相等在下标之差不大于k的情况的时候
//采用hashmap,来存数组值和下标，然后通过遍历来查找后面有没有相同的值且下标之差不大于k的。
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int ,int> mp;
        for (int i=0;i<nums.size();i++)
        {
            if(mp.find(nums[i])!=mp.end()&&i-mp[nums[i]]<=k)
              return true;
            else
                mp[nums[i]]=i;
        }
        return false;
    }
};

//Contains Duplicate 1
//如果给定的数组里面都是唯一值得话return FALSE，如果有有值超过两个的话return true;
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int ,int> mp;
        if(nums.size()<2)
        return false;
        for (int i=0;i<nums.size();i++)
        {
            mp[nums[i]]++;
        }
        for (auto &i :mp)
        {
            if(i.second>1)
            return true;
        }
        return false;
        
    }
};