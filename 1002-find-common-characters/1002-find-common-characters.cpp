class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        bool flag=false;
        vector<string> result;
        unordered_map<char,int> h1,h2;

        for(int i=0 ; i<words[0].size() ; i++)
        {
            flag=true;
            char s=words[0][i];
            h1[s]++;
            for(int j=1 ; j<words.size() ; j++)
            {
                bool found=false;
                int count=0;
                for(int k=0 ; k<words[j].size() ; k++)
                {
                    if(words[j][k]==s)
                    {
                        found=true;
                        if(count==h1[s])
                            break;
                        count++;
                    }
                }
                if(h1[s]!=count)
                {
                    flag=false;
                    break;
                    
                }
                if(!found)
                {
                    flag=false;
                    break;
                }
            }
            if(flag)
            {
                string temp;
                temp+=s;
                result.push_back(temp);
            }
        }
        return result;
    }
};