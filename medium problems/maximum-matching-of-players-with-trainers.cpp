//https://leetcode.com/problems/maximum-matching-of-players-with-trainers/description/?envType=daily-question&envId=2025-07-13

class Solution {
public:
    int search(int &st,vector<int>& trainers,int tar){
        int idx=-1;
        int l=st,h=trainers.size()-1;
        while(l<=h){
            int mid=l+(h-l)/2;
            if(trainers[mid]>=tar){
                idx=mid;
                h=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return idx;
    }
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        int m=players.size(),n=trainers.size();
        sort(players.begin(),players.end());
        sort(trainers.begin(),trainers.end());
        int ans=0,start=0;
        for(int i=0;i<m;i++){
            int idx=search(start,trainers,players[i]);
            if(idx!=-1){
                ans++;
                start=idx+1;
            }
            else break;
        }
        return ans;
    }
};