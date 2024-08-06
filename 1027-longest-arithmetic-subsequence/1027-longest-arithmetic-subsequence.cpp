class Solution {
public:
    int longestArithSeqLength(vector<int>& A) {
	int n = A.size();
	vector<unordered_map<int, int>> len(n);
	for(int i = 1; i < n; i++) {
		for(int j = 0; j < i; j++) {
			int diff = A[i] - A[j];
			if(len[j].find(diff) != len[j].end()) len[i][diff] = len[j][diff] + 1;
			else len[i][diff] = 2;
		}
	}
	int ans = 2;
	for(auto mp : len) {
		for(auto p : mp) ans = max(ans, p.second);
	}
	return ans;
}
};