// class Solution {
// public:
//     int countDistinct(vector<int>& nums, int k, int p) 
//     {
//         unordered_set<string> s; 
//         int n=nums.size();
        
//         for(int i=0;i<n;i++)
//         {
//             int count=0;
//             string str="";
            
//             for(int j=i;j<n;j++)
//             {
//                 if(nums[j]%p==0)
//                     count++;
                
//                 if(count>k)
//                     break;
                
//                 str+=to_string(nums[j])+"->";
//                 s.insert(str);
//             }
//         }
//         return s.size();
//     }
// };

class Solution {
public:
    class trie {
        public:
            unordered_map < int , trie* > next;
            int c;
            trie() {
            }
    };
    int countDistinct(vector<int>& nums, int k, int p) {
        trie *root = new trie();
        int n = nums.size();
        int ans = 0;
        for(int i = 0;i<n;i++){

            trie *temp = root;

            int count = 0;
            for(int j = i;j<n;j++){
                if(nums[j] % p == 0)
                    count++; 
                if(count > k)
                    break;
                if(!temp->next[nums[j]]){
                    temp->next[nums[j]] = new trie();
                    ans++;
                }
                temp = temp->next[nums[j]];
            }
        }
        return ans;
    }
};