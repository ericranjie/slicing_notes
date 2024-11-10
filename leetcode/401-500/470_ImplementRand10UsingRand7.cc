// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7

class Solution {
public:
    int rand10() {
        /** Deprecated:
        int s = rand7();
        return (s * 7 + 1) / 5;
        */
        /**
         * @brief Grandyang's Rejecting Sample Solution:
         */
        int n = 0;
        while (true) {
            n = (rand7() - 1) * 7 + rand7();
            if (n <= 40) return n % 10 + 1;
        }
    }
};