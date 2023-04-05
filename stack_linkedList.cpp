#include <iostream>
#include <chrono>
#include <random>
using namespace std;
using namespace std::chrono;

//Building the linked list.
struct Node{
    int val;
    struct Node *next;
};

struct Node *top = NULL;

// isEmpty()- To check whether a stack is empty or not.
bool isEmpty(){
    if (top == NULL){          
        return true ;
    }
    else{
        return false;
    } 
}

//Push()- To insert data into the stack.
void push(int value){
    struct Node *newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode -> val = value;
    newNode -> next = top;
    top = newNode;
}

//Pop()- To remove/delete data from the stack.
void pop(){
    if (isEmpty()){
        cout << "Stack underflowed!!" << endl;
    }
    else{
        cout << "The popped element is "<< top->val;
        top = top->next;
    }
}

//StackTop()- To find what is at the top of the stack.
void stackTop(){
    cout << top -> val;
}

//Display()- To print elements in the stack.
void display(){
    struct Node *ptr;
    if (isEmpty()){
        cout << "Null!!" << endl;
    }
    else{
        ptr = top;
        cout << "Stack elements are: ";
        while(ptr!=NULL){
            cout << ptr -> val << " ";
            ptr = ptr->next;
        }
    }
}


int main(){
    auto start = high_resolution_clock::now();
        push(8);
        push(10);
        push(5);
        push(11);
        push(15);
        push(23);
        push(6);
        push(18);
        push(20);
        push(17);
        display();
        pop(); pop(); pop(); pop();pop();
        display();
        push(4);
        push(30);
        push(3);
        push(1);
        display();
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end - start);
    cout << "" << endl;
    cout << "The time taken is: " << duration.count();
    return 0;
}
