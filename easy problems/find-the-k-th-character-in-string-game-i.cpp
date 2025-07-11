// https://leetcode.com/problems/find-the-k-th-character-in-string-game-i/description/?envType=daily-question&envId=2025-07-03

class Solution {
public:
    string mx="a";
    int round=1;
    void fun(string &mx,int round){
        if(round==15)return;
        string transformed=mx;
        for(char ch:mx){
            if(ch==122)transformed.push_back('a');
            else transformed.push_back(char(ch+1));
        }
        mx=transformed;
        fun(mx,round+1);
    }

    char kthCharacter(int k) {
        fun(mx,round);
        return mx[k-1];

    }
};