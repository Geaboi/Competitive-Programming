
class Solution {
public:
    string longestPrefix(string s) {
        int n = s.length();
        if (n == 0) return "";
        
        // lps[i] will store the length of the longest happy prefix for s[0...i]
        vector<int> lps(n, 0);
        
        // i iterates through the suffix, j tracks the prefix length
        for (int i = 1, j = 0; i < n; i++) {
            // If characters don't match, pull j back to the previous match
            while (j > 0 && s[i] != s[j]) {
                j = lps[j - 1];
            }
            
            // If characters match, increment the prefix length
            if (s[i] == s[j]) {
                j++;
                lps[i] = j;
            }
        }
        
        // The last value in the LPS array is the length of the longest happy prefix
        int length = lps[n - 1];
        return s.substr(0, length);
    }
};