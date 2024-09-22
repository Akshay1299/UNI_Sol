class Solution {
public:
    long long calculateSteps(int current, int n) {
        long long steps = 0;
        long long first = current; 
        long long last = current; 
        
        while (first <= n) {
            steps += min((long long)n + 1, last + 1) - first;
            
            first *= 10; 
            last = last * 10 + 9; 
        }
        
        return steps;
    }
    
    int findKthNumber(int n, int k) {
        int current = 1;  
        k--;
        while (k > 0) {
            long long steps = calculateSteps(current, n);
            
            if (steps <= k) {
                current++; 
                k -= steps;  
            } else {
                current *= 10; 
                k--;  
            }
        }
        
        return current; 
    }
};