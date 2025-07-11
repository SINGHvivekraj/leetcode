/*https://leetcode.com/problems/reschedule-meetings-for-maximum-free-time-ii/?envType=daily-question&envId=2025-07-10 */



class Solution {
public:
    int maxFreeTime(int eventTime, vector<int>& startTime, vector<int>& endTime) {
        int n=startTime.size();
        vector<int>freetime;
        freetime.push_back(startTime[0]);
        for(int end=0;end<=(n-2);end++)freetime.push_back(startTime[end+1]-endTime[end]);
        freetime.push_back(eventTime-endTime[n-1]);
        int m=freetime.size();

        vector<int>lf(m),rt(m);
        lf[0]=freetime[0];
        for(int i=1;i<m;i++){
            lf[i]=max(lf[i-1],freetime[i]);
        }

        rt[m-1]=freetime[m-1];
        for(int i=m-2;i>=0;i--){
            rt[i]=max(rt[i+1],freetime[i]);
        }
        int ans=0;
        for(int i=0;i<n;i++){
            int duration=endTime[i]-startTime[i];
            int mxfree=max((i>=1)?lf[i-1]:0,(i+2<m)?rt[i+2]:0);
            if(mxfree>=duration){
                ans=max(ans,freetime[i]+freetime[i+1]+duration);
            }
            else{
                ans=max(ans,freetime[i]+freetime[i+1]);
            }
        }
        return ans;

    }
};