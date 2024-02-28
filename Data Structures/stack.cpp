#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

template <typename DataType>

class Stack{
    private:
        vector<DataType> stack;

    public:
        void push(const DataType& element){
            stack.push_back(element);
        }

        DataType& top(){
            if (!stack.empty()){
                return stack.back();
            }
            else{
                std::cerr << "Stack is empty.\n";
                exit(EXIT_FAILURE);
            }
        }

        void pop(){
            if (!stack.empty()){
                stack.pop_back();
            }
            else{
                std::cerr << "Stack is empty.\n";
            }
        }

        bool is_empty(){
            if (stack.empty()) return true;
            else return false;
        }
};

int main(){

    Stack<int> stack;

    cout<<stack.is_empty()<<endl;
    
    for (int i=1; i<11; i++){
        stack.push(pow(i,2));
        cout<<stack.top()<<endl;
    }

    cout<<stack.is_empty()<<endl;
    stack.pop();
    stack.pop();
    stack.pop();
    cout<<stack.top()<<endl;;
}