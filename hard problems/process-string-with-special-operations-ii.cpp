//https://leetcode.com/contest/weekly-contest-458/problems/process-string-with-special-operations-ii/submissions/1701323439/

class Solution {
public:
    long long count(string &s){
        long long ans=0;
        for(char &ch:s){
            if(ch=='*'){
                if(ans)ans--;
            }
            else if(ch=='#')ans*=2;
            else if(ch=='%')continue;
            else ans+=1;
        }
        return ans;
    }
    char processStr(string s, long long k) {
        long long len=count(s);
        if(k>=len)return '.';
        for(int i=s.size()-1;i>=0;i--){
            if(s[i]=='*')len++;
            else if(s[i]=='#'){
                if(k>=len/2)k-=len/2;
                len/=2;
            }
            else if(s[i]=='%')k=len-1-k;
            else{
                if(k+1==len)return s[i];
                len--;
            }
        }
        return '.';
    }
};