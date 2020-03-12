class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int>s1;
        unordered_set<int>s2;
        for(int i=0;i<nums1.size();i++)
            s1.insert(nums1[i]);
        for(int i=0;i<nums2.size();i++)
            s2.insert(nums2[i]);
        vector<int>v;
        for(auto x :s2){
            if(s1.count(x)){
                v.push_back(x);
                s1.erase(x);
            }
        }
        return v;
    }
};