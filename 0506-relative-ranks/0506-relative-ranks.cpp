class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int lenScore = score.size();
        vector<string> answer(lenScore);
        priority_queue<pair<int, int>> maxHeap; 

        for (int i = 0; i < lenScore; ++i) {
            maxHeap.push({score[i], i});
        }

        vector<string> rank = {"Gold Medal", "Silver Medal", "Bronze Medal"};

        int number = 1;
        while (!maxHeap.empty()) {
            auto top = maxHeap.top();
            maxHeap.pop();
            int index = top.second;
            if (number < 4) {
                answer[index] = rank[number - 1];
            } else {
                answer[index] = to_string(number);
            }
            number++;
        }

        return answer;
    }
};