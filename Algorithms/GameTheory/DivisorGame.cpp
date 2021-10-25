// https://leetcode.com/problems/divisor-game/

class Solution {
public:
    bool divisorGame(int n) {
        vector<bool> state(n + 10, false);
        
        state[2] = true;
        for (int i = 2; i <= n; i++) {
            bool isWin = false;
            for (int j = 1; j < i; j++) {
                if (i % j == 0 && state[i - j] == false) {
                    isWin = true;
                    break;
                }
            }
            state[i] = isWin;
        }
        
        return state[n];
    }
};
