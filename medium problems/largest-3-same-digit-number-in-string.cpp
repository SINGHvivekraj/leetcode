//https://leetcode.com/problems/largest-3-same-digit-number-in-string/?envType=daily-question&envId=2025-08-14
class Solution {
public:
    string largestGoodInteger(string num) {
        string res;
        int n=num.size();
        int i=0,j=0;
        int ans=-1;
        vector<int>freq(10,0);
        while(j<n){
            char ch=num[j];
            freq[ch-'0']++;
            if((j-i+1)>3){
                freq[num[i]-48]--;
                i++;
            }
            if((j-i+1)==3){
                if(freq[ch-48]==3){
                    string t(3,ch);
                    // t.push_back(ch);
                    // t.push_back(ch);
                    // t.push_back(ch);
                    int number=stoi(t);
                    if(ans<number){
                        ans=number;
                        res=t;
                    }
                }
            }
            j++;
        }
        return res;

    }
};