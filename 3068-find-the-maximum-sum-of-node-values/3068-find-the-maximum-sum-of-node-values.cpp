class Solution {
public:
    long long maximumValueSum(vector<int>& elements, int k, vector<vector<int>>& edges) {
        int len = elements.size();
        vector<int> adjacencyList[len];
        int i = 0;
        while(i < len - 1)
        {
            adjacencyList[edges[i][0]].push_back(edges[i][1]);
            adjacencyList[edges[i][1]].push_back(edges[i][0]);
            i++;
        }
        vector<int> increaseSet;
        i = 0;
        while(i < len)
        {
            long long val = (long long)elements[i] ^ k;
            if(val > elements[i])
            {
                increaseSet.push_back(i);
            }
            i++;
        }
        int sz = increaseSet.size();
        if(sz % 2 == 0)
        {
            long long answer = 0;
            i = 0;
            while(i < len)
            {
                answer += elements[i];
                i++;
            }
            i = 0;
            while(i < increaseSet.size())
            {
                answer -= elements[increaseSet[i]];
                long long add = (long long)elements[increaseSet[i]] ^ k;
                answer += add;
                i++;
            }
            return answer;
        }
        else
        {
            long long answer = 0;
            i = 0;
            while(i < len)
            {
                answer += (long long)elements[i];
                i++;
            }
            long long max_sum = answer;
            
            i = 0;
            while(i < increaseSet.size())
            {
                answer -= elements[increaseSet[i]];
                long long add = (long long)elements[increaseSet[i]] ^ k;
                answer += add;
                i++;
            }
            i = 0;
            while(i < sz)
            {
                long long add = (long long)elements[increaseSet[i]] ^ k;
                long long current_sum = answer - add + elements[increaseSet[i]];
                max_sum = max(max_sum, current_sum);
                i++;
            }
            
            vector<int> visited(len,0);
            long long sum = 0;
            i = 0;
            while(i < sz)
            {
                visited[increaseSet[i]]=1;
                i++;
            }
            i = 0;
            while(i < len)
            {
                if(visited[i]==0)
                {
                    long long add = (long long)elements[i] ^ k;
                    long long current_sum = answer - elements[i] + add;
                    max_sum = max(max_sum, current_sum);
                }
                i++;
            }
           
           
            return max_sum;
        }
    }
};
