class Solution {
public:
    bool isPathCrossing(string path) {
        int x=0, y=0;
        vector<string> storer;
        string temp = to_string(x) + "," + to_string(y);
        storer.push_back(temp);
        for(int i=0; i<path.length(); i++){
            switch(path[i]){
                case 'N':
                    y++;
                    break;
                case 'E':
                    x++;
                    break;
                case 'W':
                    x--;
                    break;
                case 'S':
                    y--;
                    break;
            }
            temp = to_string(x) + "," + to_string(y);
            if(find(storer.begin(), storer.end(), temp) != storer.end())
                return 1;
            storer.push_back(temp);
        }
        return 0;
    }
};