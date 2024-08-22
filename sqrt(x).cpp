class Solution {
public:
    int mySqrt(int x) {
        if (x == 0 || x == 1) return x;

        int left = 1, right = x / 2, result = 0;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            // Check if mid*mid is less than or equal to x
            if (mid <= x / mid) {
                result = mid;  // mid might be the answer, so save it
                left = mid + 1; // search in the right half
            } else {
                right = mid - 1; // search in the left half
            }
        }

        return result;
    }
};
