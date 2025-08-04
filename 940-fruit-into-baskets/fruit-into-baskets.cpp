class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int, int> fruitCount; // To store the frequency of each fruit type in the current window
        int left = 0;                       
        int maxFruits = 0;                  

        for (int right = 0; right < fruits.size(); ++right) {
            // Add the current fruit to the window
            fruitCount[fruits[right]]++;

            // If the window has more than two types of fruits, we need to shrink it from the left
            while (fruitCount.size() > 2) {
                fruitCount[fruits[left]]--;        // Decrement the count of the leftmost fruit
                if (fruitCount[fruits[left]] == 0) {
                    fruitCount.erase(fruits[left]); // Remove the fruit type if its count drops to zero
                }
                left++;                            // Move the left pointer to the right
            }

            // Update the maximum number of fruits picked so far
            maxFruits = max(maxFruits, right - left + 1);
        }

        return maxFruits;
    }
};