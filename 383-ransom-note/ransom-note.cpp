class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char,int> magHash;
        for(char c: magazine){
            magHash[c]++;
        }
        for(char c: ransomNote){
            if(magHash[c]<=0)
            return false;

            magHash[c]--;
        }
        return true;
        
    }
};