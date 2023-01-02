// Time Complexity = O(n^2)
//Space Complexity = O(1)

class Solution
{
public:
    int rotationFunction(int index, vector<int> &nums)
    {
        int currentAns = 0;
        int current = nums.size() - index;
        for (int i = 0; i < nums.size(); i++)
        {
            if (current == nums.size())
                current = 0;

            currentAns += i * nums[current];
            current++;
        }
        return currentAns;
    }

    int maxRotateFunction(vector<int> &nums)
    {
        int n = nums.size();
        int ans = INT_MIN;
        for (int index = 0; index < n; index++)
        {
            ans = max(ans, rotationFunction(index, nums));
        }
        return ans;
    }
};