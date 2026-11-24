class Solution {
public:
    int maxLength(vector<int>& nums) {
        int result = 0;
        
        for (int i=0; i<nums.size(); i++) {
            int prod = nums[i];
            int gcdVal = nums[i];
            int lcmVal = nums[i];

            for (int j=i+1; j<nums.size(); j++) {
                prod *= nums[j];
                gcdVal = gcd(gcdVal, nums[j]);
                lcmVal = lcm(lcmVal, nums[j]);

                if (prod > gcdVal * lcmVal) break;

                if (prod == gcdVal * lcmVal) {
                    result = max(result, j-i+1);
                }
            }
        }

        return result;
    }
};