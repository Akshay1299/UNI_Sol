class Solution {
public:
    int minMovesToSeat(vector<int>& seats, vector<int>& students) {
        sort(seats.begin(), seats.end());
        sort(students.begin(), students.end());
        int minMoves = 0;
        int n = seats.size();
        for(int i=0;i<n;i++){
            if(i==0){
                minMoves = abs(students[0] - seats[0]);
                students[0] = INT_MAX;
            }
            else if(i==n-1){
                minMoves += abs(students[n-1] - seats[n-1]);
                students[n-1] = INT_MAX;
            }
            else{
                minMoves += min(abs(students[i-1] - seats[i]), abs(students[i] - seats[i]));
                if(minMoves==abs(students[i-1] - seats[i])){
                    students[i-1] = INT_MAX;
                }
                else{
                    students[i] = INT_MAX;
                }
            }
        }
        return minMoves;
    }
};