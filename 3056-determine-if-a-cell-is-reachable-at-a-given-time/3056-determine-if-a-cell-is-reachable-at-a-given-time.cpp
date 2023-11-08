class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        if ((sx == fx) && (sy == fy)) return (t != 1);
        int dx = abs(sx - fx);
        int dy = abs(sy - fy);
        int min_time = max(dx, dy);
        return (t >= min_time);
    }
};