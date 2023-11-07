class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char, int> alienOrder;
        
        // Populate the alienOrder map with the order of characters in the alien language.
        for (int i = 0; i < order.size(); i++) {
            alienOrder[order[i]] = i;
        }
        
        for (int i = 0; i < words.size() - 1; i++) {
            if (!compareWords(words[i], words[i + 1], alienOrder)) {
                return false; // The words are not sorted in the alien language order.
            }
        }
        
        return true; // All words are sorted correctly.
    }
    
    bool compareWords(const string& word1, const string& word2, const unordered_map<char, int>& alienOrder) {
        int len1 = word1.size();
        int len2 = word2.size();
        
        for (int i = 0; i < min(len1, len2); i++) {
            char char1 = word1[i];
            char char2 = word2[i];
            
            if (alienOrder.at(char1) < alienOrder.at(char2)) {
                return true; // The order of these characters is correct.
            } else if (alienOrder.at(char1) > alienOrder.at(char2)) {
                return false; // The order of these characters is incorrect.
            }
        }
        
        // If all characters compared so far are the same, check the lengths.
        return len1 <= len2;
    }
};
