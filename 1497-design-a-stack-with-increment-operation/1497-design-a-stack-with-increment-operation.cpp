class CustomStack {
public:
    vector<int>currentStack;
    int capacity;

    CustomStack(int maxSize) {
        currentStack.clear();
        capacity = maxSize;
    }
    
    void push(int x) {
    if(currentStack.size() == capacity)
        return;

    currentStack.push_back(x);
    }
    
   int pop() {
    if(currentStack.size() == 0)
        return -1;

    int res = currentStack[currentStack.size()-1];
    currentStack.pop_back();
    return res;
    }
    
    void increment(int k, int val) 
    {
    int end = min((int)(currentStack.size()), k);
    for(int i=0;i<end;i++)
    {
        currentStack[i] += val;
    }
    return;
    }
};
/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */