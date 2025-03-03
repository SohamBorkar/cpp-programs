#include <iostream>
#include <vector>
using namespace std;

struct Node{
    public:
    int data;
    Node* next;
    
    public:
    Node(int data, Node* next){
        this -> data = data;
        this -> next = next;
    }
};

int main(){
    vector<int> v = {1,2,3,4,5};
    Node* y = new Node(v[0], nullptr);
    cout << y << endl;
    return 0;
}