#include <stack>

class MyQueue {
private:
    std::stack<int> inputStack;
    std::stack<int> outputStack;

    void transferIfNeeded() {
        if (outputStack.empty()) {
            while (!inputStack.empty()) {
                outputStack.push(inputStack.top());
                inputStack.pop();
            }
        }
    }

public:
    MyQueue() {}
    
    void push(int x) {
        inputStack.push(x);
    }
    
    int pop() {
        transferIfNeeded();
        int frontElement = outputStack.top();
        outputStack.pop();
        return frontElement;
    }
    
    int peek() {
        transferIfNeeded();
        return outputStack.top();
    }
    
    bool empty() {
        return inputStack.empty() && outputStack.empty();
    }
};
