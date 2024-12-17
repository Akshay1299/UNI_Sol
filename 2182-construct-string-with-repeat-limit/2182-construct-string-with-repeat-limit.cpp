class Solution {
public:
    string repeatLimitedString(const string &s, int repeatLimit)
    {
        int dict[26] = {};
        bool has_lim = true;
        bool take_max = true;
        int previous = -1;
        int lim;
        string new_str = "";

        for(const auto &chr : s)
        {
            ++dict[chr - 'a'];
        }

        while(has_lim)
        {
            has_lim = true;
            take_max = true;
            previous = -1;

            for(int16_t i = 25; i >= 0; --i)
            {
                if(dict[i] == 0)
                {
                    continue;
                }
                has_lim = false;
                lim = repeatLimit;

                // check last letter
                if(!new_str.empty() && i + 'a' == new_str.back())
                {
                    has_lim = true;
                    break;
                }

                if(take_max)
                {
                    while(dict[i] > 0 && lim > 0)
                    {
                        new_str += i + 'a';
                        --dict[i];
                        --lim;
                    }
                    if(dict[i] > 0)
                    {
                        take_max = false;
                        previous = i + 1;
                    }
                    else
                    {
                        previous = 26;
                    }
                }
                else
                {
                    new_str += i + 'a';
                    --dict[i];
                    take_max = true;
                    i = previous;
                    previous = 26;
                }
            }
        }
        return new_str;
    }
};