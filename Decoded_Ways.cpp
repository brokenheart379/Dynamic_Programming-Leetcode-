https://leetcode.com/problems/decode-ways/

//Using Recurssion
class Solution {
public:
    int decodedhelper(int i,string &s){
        //Using Recurssion---> Gives TLE
        if(i>=s.size())
            return 1;
        int option1=s[i]-'0';
        int option2=0,count=0;
        if(i<s.size()-1){
            option2=(s[i]-'0')*10+s[i+1]-'0';
        }
        if(option1>0){
            count+=decodedhelper(i+1,s);
        }
        if(option1!=0 and option2>0 and option2<=26){
            count+=decodedhelper(i+2,s);
        }
        return count;
        
    }
    int numDecodings(string s) {
       return  decodedhelper(0,s);
    }
};


//Top-Down Approach
class Solution {
public:
    int decodedhelper(int i,string &s,vector<int> &dp){
        //Using Recurssion---> Gives TLE
        if(i>=s.size())
            return 1;
        if(dp[i]!=-1)
            return dp[i];
        int option1=s[i]-'0';
        int option2=0,count=0;
        if(i<s.size()-1){
            option2=(s[i]-'0')*10+s[i+1]-'0';
        }
        if(option1>0){
            count+=decodedhelper(i+1,s,dp);
        }
        if(option1!=0 and option2>0 and option2<=26){
            count+=decodedhelper(i+2,s,dp);
        }
        return dp[i]=count;
        
    }
    int numDecodings(string s) {
        vector<int> dp(101,-1);
       return  decodedhelper(0,s,dp);
    }
};



//Bottom-Up Approach
class Solution {
public:
    int numDecodings(string s) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        vector<int> dp(s.size()+2,0);
        int n=s.size();
        dp[n+1]=1;
        dp[n]=1;
        for(int i=n-1;i>=0;i--){
            int option1=s[i]-'0';
            int option2=0;
            if(i<s.size()-1){
                option2=(s[i]-'0')*10+s[i+1]-'0';
            }
            if(option1>0)
                dp[i]+=dp[i+1];
            if(option1>0 and option2>0 and option2<=26)
                dp[i]+=dp[i+2];
        }
        return dp[0];
    }
};
