// https://leetcode.com/problems/remove-sub-folders-from-the-filesystem/description/?envType=daily-question&envId=2025-07-19

class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        vector<string> ans;
        sort(folder.begin(),folder.end());
        ans.push_back(folder[0]);
        for(int i=1;i<folder.size();i++){
            string recent=ans[ans.size()-1];
            recent.push_back('/');
            if(folder[i].find(recent)!=0)ans.push_back(folder[i]);
        }
        return ans;
    }
};