// Combination Sum III

/*
Intuition :- We want to find all the combinations that makes a sum of n by taking exactly k numbers, such that the numbers are from 1 to 9 &
we can take a number exactly once.Since for making any combinations we are having two possibilities i.e. we can either take the current value
or we won't take the current value,since we are having options, so we'll make use of recursion.

1) If we take the current value, then decrement target by current value and decrement k by 1(since we have used one number) and we'll simply
move to the next number by incrementing current value.
2) If we won't take the current value, then we will simply move to the next value by incrementing current value.
3) If at any point target == 0 && k ==0, then it implies that we have got a valid combination, so add it to ans.
4) If at any point k == 0 OR current > 9, then it means that we haven't got a valid combination, so simply return.

Time Complexity = 2^min(k,9)
=>its because if k>9,then we'll explore each element but if k<=9, we won't explore all the elements because value of k won't allow us.

Space Complexity = O(m); for storing the currentAns
*/

class Solution
{
public:
    // function to find all the combinations that makes target with exact k numbers
    void findCombinations(int current, int target, int k, vector<int> &currentAns, vector<vector<int>> &ans)
    {
        // we have got a valid combination
        if (target == 0 && k == 0)
        {
            ans.push_back(currentAns);
            return;
        }

        // invalid
        if (k == 0 || current > 9)
            return;

        // take
        if (current <= target)
        {
            currentAns.push_back(current);
            findCombinations(current + 1, target - current, k - 1, currentAns, ans);
            currentAns.pop_back();
        }

        // not take
        findCombinations(current + 1, target, k, currentAns, ans);

        return;
    }

    vector<vector<int>> combinationSum3(int k, int n)
    {
        vector<vector<int>> ans;
        vector<int> currentAns;

        findCombinations(1, n, k, currentAns, ans);

        return ans;
    }
};