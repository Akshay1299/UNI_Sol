class Solution {
public:
vector<int> v;
void sol(int i,int n)
{
    if(i>n)
    {
        return;
    }
    int curr=i;
    v.push_back(curr);
    for(int i=0;i<=9;i++)
    {
        string temp = to_string(curr) + to_string(i);
        sol(stoi(temp),n);
    }
}
    vector<int> lexicalOrder(int n) {
        for(int i=1;i<=9;i++)
        {
            sol(i,n);
        }
        return v;
    }
};