class Solution {
public:
    bool isSelfCrossing(vector<int>& distance) {
        if (distance.size() <= 3) return false; 

        distance.insert(distance.begin(), 0);
        for (int i = 3; i < distance.size(); i++) {
            if (distance[i - 2] <= distance[i] && distance[i - 1] <= distance[i - 3]) return true;

            if (i >= 5) {
                if (distance[i - 1] <= distance[i - 3] && distance[i - 1] >= distance[i - 3] - distance[i - 5] 
                    && distance[i - 2] >= distance[i - 4] && distance[i - 2] <= distance[i - 4] + distance[i])
                    return true;
            }
        }
        return false;
    }
};



// class Solution {
    
// public:
    
//     bool isSelfCrossing(vector<int>& distance) {
    
//         int n = distance.size(); 
        
//         if(n < 2) return false;
        
//         int i = 2;
//         while(i < n && distance[i] >= distance[i - 2]) i++;
        
//         if(i < 4) {
            
//             while(i < n && distance[i] < distance[i - 2]) i++;
            
//             if(i != n) return true;
            
//         } else {
            
//             if(n == 4) {
                
//                 if(distance[i - 1] == distance[i - 3] && distance[i - 2] == distance[i - 4]) return true;
                
//             } else {
            
//                 if(i < n - 1) i++;

//                 if(i < n && distance[i - 2] - distance[i - 4] <= distance[i]) {
                    
//                     if(i >= 5) {
                        
//                         if(distance[i - 3] - distance[i - 1] <= distance[i - 5]) {
//                             return true;
//                         }
                        
//                     } else {
//                         return true;
//                     }
//                 }

//                 while(i < n && distance[i] < distance[i - 2]) i++;
//                 if(i != n)  
//                     return true;                 
//             }
//         }

//         return false;
//     }
// };