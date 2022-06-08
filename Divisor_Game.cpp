https://leetcode.com/problems/divisor-game/

class Solution {
public:
    bool divisorGame(int n) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        if(n&1)
            return false;
        return true;
    }
};

/*

   Alice will start the game
   0<x<n and n%x==0
   n-=x;
*/
