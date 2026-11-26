class Solution {
public:
    bool solve(int n, int stones) {
        // If Alice gets neg, then bob lost
        if (n < 0) return true;

        // If Alice gets stones less
        if (n < stones) return false;

        return solve(n-(2*stones) + 1 , stones-2);
    }

    bool canAliceWin(int n) {
        return solve(n, 10);
    }
};