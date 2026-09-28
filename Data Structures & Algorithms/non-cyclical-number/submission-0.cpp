class Solution {
public:

    int getsquare(int k) {
        int sum = 0;

        while (k != 0) {
            int s = k % 10;
            sum += s * s;
            k /= 10;
        }

        return sum;
    }

    bool isHappy(int n) {

        unordered_set<int> cycle = {
            4, 16, 37, 58, 89, 145, 42, 20
        };

        while (n != 1) {

            if (cycle.count(n))
                return false;

            n = getsquare(n);
        }

        return true;
    }
};