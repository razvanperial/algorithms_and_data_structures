#include <iostream>

using namespace std;

enum Color {RED, BLACK};

struct Node{
    int data;
    Color color;
    Node *left;
    Node *right;
    Node *parent;
    Node(int data = 0)
    {
       this->data = data;
       left = right = parent = nullptr;
       this->color = RED;
    }
};

class RedBlackTree{
    private:
        Node *root;

    protected:
        void transplant(Node *&, Node *&); //done
        void insertFixupRB(Node *&);        //done
        void deleteFixupRB(Node *);        //done
        void rotateLeft( Node *&);         //done
        void rotateRight( Node *&);        //done
    
    public:
        RedBlackTree() {root = nullptr;}    //done
        Node * getRoot(){ return root; }    //done
        void insertRB(int);                 //done 
        void deleteRB( Node * &);           //TO DO 2
        Node * predecessor(const Node *&);  //done
        Node * successor(const Node *&);    //done
        Node * getMinimum(Node *z);        //done
        Node * getMaximum();                //done
        Node * search(int);                 //done
};