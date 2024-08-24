class Solution {
public:
    long helper(long num, bool iseven){
        long resnum=num;
        if(iseven==false){
            num/=10;
        }
        while(num>0){
            int digit=num%10;
            resnum=(resnum*10)+digit;
            num/=10;
        }
        return resnum;
    }
    string nearestPalindromic(string n) {
        int l=n.size();
        int mid=l/2;
        int firsthalflen=(l%2==0)?mid: (mid+1);
        long firsthalf=stol(n.substr(0,firsthalflen));
        vector<long> res;

        res.push_back(helper(firsthalf,l%2==0));
        res.push_back(helper(firsthalf+1,l%2==0));
        res.push_back(helper(firsthalf-1,l%2==0));
        res.push_back((long)pow(10,l-1)-1);
        res.push_back((long)pow(10,l)+1);

        long diff=LONG_MAX;
        long result=INT_MAX;

        long originalnum=stol(n);
        for(long num: res){
            if(num==originalnum){
                continue;
            }
            if(abs(num-originalnum)<diff){
                diff=abs(num-originalnum);
                result=num;
            }
            else if(abs(num-originalnum)==diff){
                result=min(result,num);
            }
        }
    return to_string(result);
    }
};