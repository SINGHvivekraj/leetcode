// https://leetcode.com/problems/reschedule-meetings-for-maximum-free-time-i/
// sliding window technique to find the maximum sum subarray of free times with no meetings scheduled.
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        int n=startTime.size();
        vector<int>freetime;
        if(startTime[0]>0)freetime.push_back(startTime[0]);
        for(int end=0;end<=(n-2);end++)if(startTime[end+1]>=endTime[end])freetime.push_back(startTime[end+1]-endTime[end]);
        if(endTime[n-1]<eventTime)freetime.push_back(eventTime-endTime[n-1]);
        int i=0,j=k;
        long long sum=0;
        int sz=freetime.size();
        while(i<sz and i<=j){
            sum+=freetime[i];
            i++;
        }
        long long ans=sum;
        i=1;
        j++;
        
        //cout<<ans<<endl;
       // for(int ele:freetime)cout<<ele<<" ";
        while(j<sz){
            sum += freetime[j];
            sum -= freetime[i-1];
            //cout<<sum<<" ";
            ans=max(ans,sum);
            j++;i++;
        }

        return ans;

    }
};