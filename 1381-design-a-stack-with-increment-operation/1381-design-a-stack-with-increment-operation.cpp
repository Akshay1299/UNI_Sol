class CustomStack {
public:
vector<int>helper;
int cp;
    CustomStack(int maxSize) {
       helper.resize(maxSize,-1) ;
        cp=-1;
    }
    
    void push(int x) {
        if(cp+1<helper.size()) {
            cp+=1;
            helper[cp]=x;
        }
    }
    
    int pop() {
        int ans=-1;
        if(cp>=0){
            ans=helper[cp];
            helper[cp]=-1;
            cp-=1;
        }
        return ans;
    }
    
    void increment(int k, int val) {
        k=min(cp+1,k);
        for(int i=0;i<k;i++) helper[i]+=val;
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */