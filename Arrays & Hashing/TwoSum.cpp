
class Solution {
public:
    // Given a vector of numbers and a target value, find the indices: i, j such that: nums[i] + nums[j] = target
    vector<int> twoSum(vector<int>& nums, int target) {
        
        // Create a vector of (value, index) pairs based on input vector
        vector<pair<int, int>> valueIndex;
        
        // Loop through nums and add each pair
        for (int i = 0; i < nums.size(); i++)
        {
            // Add (value, index) pairs to our new vector
            valueIndex.push_back({nums.at(i), i});
        }

        // Sort new vector based on values, not indices
        sort(valueIndex.begin(), valueIndex.end());

        int left = 0;
        int right = nums.size() - 1;

        // Two pointer solution - gives directionality to the list, reduces random guessing
        while (left < right)
        {
            // Find the current sum of two values
            int curr = valueIndex[left].first + valueIndex[right].first;
            if (curr == target)
            {
                // return the indices
                return {min(valueIndex[left].second, valueIndex[right].second)),
                        max(valueIndex[left].second, valueIndex[right].second)};
            }
            else if (curr < target) // if current sum is smaller than target sum
            {
                left++;             // shoot for a larger sum
            }
            else                    // if current sum is larger than target sum
            {
                right--;            // shoot for a smaller sum
            }
        }
        return {};                  // return an empty vector otherwise
    }
};
