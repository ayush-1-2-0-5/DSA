class FreqStack {
private:
    map<int, stack<int>> mpp; 
    map<int, int> fmpp;       
    int maxfreq;              

public:
    FreqStack() {
        maxfreq = 0;
    }

    void push(int val) {
        int a = fmpp[val] + 1;
        fmpp[val] = a; // Increment the frequency of the element
        mpp[a].push(val); // Push the element to the stack corresponding to its frequency
        
        if (a > maxfreq) {
            maxfreq = a; // Update maxfreq if the current element's frequency is higher
        }
    }

    int pop() {
        int val = mpp[maxfreq].top();
        mpp[maxfreq].pop(); // Pop the element from the stack with the highest frequency
        
        fmpp[val]--; // Decrement the frequency of the popped element
        
        // If the stack corresponding to maxfreq becomes empty, reduce maxfreq
        if (mpp[maxfreq].empty()) {
            maxfreq--;
        }
        
        return val;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */
