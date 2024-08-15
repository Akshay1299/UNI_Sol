class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        if(bills[0]!=5){
            return false;
        }
        int count5 = 1;
        int count10 = 0;
        for(int i = 1 ; i < bills.size() ; i++){
            if(bills[i]!=5){
                if(bills[i]!=20){
                    count10++;
                    if(count5>0){
                        count5--;
                    }
                    else{
                        return false;
                    }
                }
                else{
                    if(count10>0){
                        count10--;
                        if(count5>0){
                            count5--;
                        }
                        else{
                            return false;
                        }
                    }
                    else{
                        if(count5>2){
                            count5 = count5 - 3;
                        }
                        else{
                            return false;
                        }
                    }
                }
            }
            else{
                count5++;
            }
            cout<<count5<<" "<<count10<<" "<<endl;
        }
        return true;
    }
};