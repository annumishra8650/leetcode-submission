
class Solution {
public:
    int firstUniqChar(string s) {
        int freq[26] = {0};

        // Step 1: Count frequency
        for (int i = 0; i < s.length(); i++) {
            freq[s[i] - 'a']++;
        }

        // Step 2: Find first non-repeating character
        for (int i = 0; i < s.length(); i++) {
            if (freq[s[i] - 'a'] == 1) {
                return i;
            }
        }

        return -1;
    }
};
