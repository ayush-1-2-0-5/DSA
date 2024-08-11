class MinStack {
    private:
    int mini=INT_MAX;
    stack<pair<int,int>> st;
public:
    MinStack() {
     
    }
    
    void push(int val) {
      if(st.empty())
      st.push({val,val});
      else
      {
      auto it=st.top();
      int minele=it.second;
      if(minele>val)
      st.push({val,val});
      else
      st.push({val,minele});
      }
    }
    
    void pop() {
        st.pop();
    }
    
    int top() {
        int a=st.top().first;
        return a;
    }
    
    int getMin() {
        int b=st.top().second;
        return b;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */