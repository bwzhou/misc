class MinStack {
    stack<int> mins;
    stack<int> all;
public:
    void push(int x) {
        if (mins.empty() || mins.top() >= x) {
            mins.push(x);
        }
        all.push(x);
    }

    void pop() {
        if (all.empty()) {
            return;
        }
        if (!mins.empty() && mins.top() == all.top()) {
            mins.pop();
        }
        all.pop();
    }

    int top() {
        if (all.empty()) {
            return 0;
        }
        return all.top();
    }

    int getMin() {
        if (mins.empty()) {
            return 0;
        }
        return mins.top();
    }
};
