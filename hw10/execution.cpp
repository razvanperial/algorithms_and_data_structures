#include <iostream>
#include "methods.cpp"

using namespace std;

int main(){
    RedBlackTree t;
    for(int i = 1; i <= 10; i++){
        t.insertRB(i);
    }

    for(int i = 1; i <= 10; i++){
        Node *y = new Node();
        y = t.search(i);
        cout<<"Data: "<<y->data<<" Color: "<<y->color<<" ";
        
        if(y->parent)
            cout<<"Parent data: "<<y->parent->data<<" ";

        if(y->left)
            cout<<"Left kid data: "<<y->left->data<<" ";

        if(y->right)
            cout<<"Right kid data: "<<y->right->data;

        cout<<endl; 
    }

    cout<<"-------------------------"<<endl;

    Node *y = new Node();

    y = t.search(9);
    t.deleteRB(y);

    for(int i = 1; i <= 10; i++){
        Node *y = new Node();
        y = t.search(i);
            if(y){
            cout<<"Data: "<<y->data<<" Color: "<<y->color<<" ";
            
            if(y->parent)
                cout<<"Parent data: "<<y->parent->data<<" ";

            if(y->left)
                cout<<"Left kid data: "<<y->left->data<<" ";

            if(y->right)
                cout<<"Right kid data: "<<y->right->data;

            cout<<endl; 
        }
    }

    /*for(int i = 1; i <= 10; i++){
        cout<<"Deleting node "<<i<<" || ";
        Node *y = new Node();
        y = t.search(i);
        t.deleteRB(y);
        cout<<"new root: "<<t.getRoot()->data<<endl;    
    }
    */
    return 0;
}