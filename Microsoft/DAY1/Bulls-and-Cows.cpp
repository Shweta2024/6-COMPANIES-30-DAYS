/*
Intuition :- 
bulls->number of guess digits that are present in secret & are at right position.
cows-> the number of guess digits that are present in secret but are at wrong position.

1) If we'll get secrets[index] == guess[index],then it implies that we have got a digit in guess which is present in its corret
position, so it means its a bull.So, increment bulls count.
2) If secrets[index] != bulls[index], then we'll store the frequecies of those characters in different maps.
3) Traverse over the guess map & check if the charater is present in secrect map then increment the count of cows by minimum of the 
frequency in bulls & cows map.We are taking minimum because non-bulls characters can only be rearranged to form bull.

Time Complexity = O(n)
Space Complexity = O(2n)

minimum ishiliye le re h kyuki arag mere pass secrect wale map mai one 1 h aur guess wale map mai two 1 h , iska matlb ye h
ki bas one 1 hi misplaced h aur dusra 1 to secret mai present hi ni h na.Aur cows ky h, cows vo misplaed digits h jo secret mai present ho, but
second wala 1 to present hi ni h.
*/

class Solution
{
public:
    string getHint(string secret, string guess)
    {
        int bulls = 0;
        int cows = 0;
        unordered_map<char, int> memo1;
        unordered_map<char, int> memo2;

        for (int index = 0; index < secret.size(); index++)
        {
            if (secret[index] == guess[index])
                bulls++;

            else
            {
                memo1[secret[index]]++;
                memo2[guess[index]]++;
            }
        }
        for (auto current : memo2)
        {
            if (memo1.find(current.first) != memo1.end())
                cows += min(memo1[current.first], memo2[current.first]);
        }
        string ans = to_string(bulls) + "A" + to_string(cows) + "B";
        return ans;
    }
};