#include "rbt_class.h"

using namespace std;

//transplant
void RedBlackTree::transplant(Node *&u, Node *&v){
    if(u->parent == nullptr)
        root = v;
    else if (u == u->parent->left)
        u->parent->left = v;
    else
        u->parent->right = v;
    if(v != nullptr)
        v->parent = u->parent;
}

//insert fixup
void RedBlackTree::insertFixupRB(Node *&z){
    Node*y = new Node;
    y->color=BLACK;
    while(z->parent->color == RED){
       if(z->parent == z->parent->parent->right){
            if(z->parent->parent->left!=nullptr){
                y = z->parent->parent->left;
            }            
            if(y->color == RED){
                z->parent->color=BLACK;
                y->color = BLACK;
                z->parent->parent->color = RED;
                z = z->parent->parent;
            } 
            else{
                if(z == z->parent->left){
                    z = z->parent;
                    rotateRight(z);
                }
                z->parent->color = BLACK;
                z->parent->parent->color = RED;
                rotateLeft(z->parent->parent);
            }
        }
        else{
            if(z->parent->parent->right!=nullptr){
                y=z->parent->parent->right;
            }
            if(y->color == RED){
                z->parent->color=BLACK;
                y->color = BLACK;
                z->parent->parent->color = RED;
                z = z->parent->parent;
            } 
            else{
                if(z == z->parent->right){
                    z = z->parent;
                    rotateLeft(z);
                }
                z->parent->color = BLACK;
                z->parent->parent->color = RED;
                rotateRight(z->parent->parent);
            }
        }
        if(z == this->root){
            break;
        }
    }
    
    this->root->color = BLACK;
}

//iterative tree search
Node * RedBlackTree::search(int k){
    Node * x = root;
    while( x != nullptr && k != x->data){
        if(k < x->data)
            x = x->left;
        else
            x = x->right;
    }
    return x;
}

//finding minimum
Node * RedBlackTree::getMinimum(Node *z){
    Node * x = z;
    if(x != nullptr){
        while(x->left != nullptr)
            x = x->left;
    }
    return x;
}

//finding maximum
Node * RedBlackTree::getMaximum(){
    Node *x = root;
    if(x != nullptr){
        while(x->right != nullptr)
            x = x->right;
    }
    return x;
}

//finding successor
Node * RedBlackTree::successor(const Node *&x){
    if(x->right != nullptr){
        Node * aux = x->right;
        while(aux->left != nullptr)
            aux = aux->left;
        return aux;
    }
    
    Node *y = x->parent;
    while( y != nullptr && x == y->right){
        x = y;
        y = y->parent;
    }
    return y;
}

//finding predecessor
Node * RedBlackTree::predecessor(const Node *&x){
    if(x->left != nullptr){
        Node * aux = root;
        while(aux->right != nullptr)
            aux = aux->right;
        return aux;
    }
    
    Node *y = x->parent;
    while( y != nullptr && x == y->left){
        x = y;
        y = y->parent;
    }
    return y;
}

//left-rotate
void RedBlackTree::rotateLeft(Node *&x){
    Node *y = new Node;
    y = x->right;
    x->right = y->left;
    if(y->left!=nullptr){
        y->left->parent = x;
    }
    
    Node *aux = new Node();
    aux = x;
    y->parent = x->parent;
    
    if(aux->parent == nullptr){
        root = y;
    }
    else if (aux == aux->parent->left){
       aux->parent->left = y;
    }
    else{
        aux->parent->right = y;
    }
    y->left = aux;
    aux->parent = y; 
}

//right-rotate 
void RedBlackTree::rotateRight(Node *&y){
    Node * x = y->left;
    y->left = x->right;

    if(x->right != nullptr)
        x->right->parent = y;

    Node *aux = new Node();
    aux = y;
    x->parent = y->parent;

    if(aux->parent == nullptr)
        root = x;
    else if (aux == aux->parent->right)
        aux->parent->right = x;
    else
        aux->parent->left = x;
    
    x->right = aux;
    aux->parent = x;
}

//insertion
void RedBlackTree::insertRB(int key){
    Node*x = new Node;
    Node*y = new Node;
    Node*z = new Node;
    x = this->root;
    y = nullptr;
    z->parent = nullptr;
    z->left = nullptr;
    z->right = nullptr;
    z->data=key;
    z->color = RED;
    while(x!=nullptr){
        y = x;
        if(z->data<x->data){
            x = x->left;
        }
        else{
            x = x->right;
        }
    }
    z->parent = y;
    if(y == nullptr){
        this->root = z;
    }
    else if (z->data<y->data){
        y->left = z;
    }
    else{
        y->right = z;
    }
    z->left = nullptr;
    z->right = nullptr;
    if(z->parent == nullptr){
        z->color= BLACK;
        return;
    }
    else if(z->parent->parent == nullptr){
        return;
    } 
    insertFixupRB(z);    
}

//deletion
void RedBlackTree::deleteRB( Node*&z ){
    Node *y = new Node;
    Node *x = new Node;
    y = z;
    Color y_original_color = y->color;
    if(z->left == nullptr){
        x = z->right;
        transplant(z, z->right);
    }
    else if(z->right == nullptr){
        x = z->left;
        transplant(z,z->left);
    }
    else{
        y = getMinimum(z->right);
        y_original_color = y->color;
        
        if(y->right)
            x = y->right;
        else{
            x->color = BLACK;
            x->parent = y;
        }
        
        if(y->parent == z){
            x->parent = y;
        }
        else{
            transplant(y,y->right);
            y->right = z->right;
            y->right->parent = y;
        }
        cout<<z->data<<" "<<y->data;
        transplant(z,y);
        y->left = z->left;
        y->left->parent = y;
        y->color = z->color;
    }
    if(y_original_color == BLACK)
        deleteFixupRB(x);
}

void RedBlackTree::deleteFixupRB(Node *x){
    cout<<x->color<<endl;
    while(x != nullptr && x->color == BLACK){
        if(x == x->parent->left){
            Node *w = new Node;
            w = x->parent->right;
            cout<<w->data;
        }
    }
}
