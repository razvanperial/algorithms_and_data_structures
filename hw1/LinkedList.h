    template <class T>
    struct node
    {
        T value;
        node* prev;
        node* next;
    };

    template <typename T> class List{
        private:
            int size;
            node<T> *head;
        public:
            List();                     //empty constructor
            List(int size, T array[]);  //parameter constructor
            ~List();                    //destructor
            //push elements
            void push_front(T element);
            void push_back(T element);
            //pop elements
            T pop_front(void);
            T pop_back(void);
            //get elements
            T get_front(void);
            T get_back(void);
            //get the number of elements
            int get_size();
    };

    template <class T>
    List<T>::List() {
        std::cout<<"Empty Constructor called"<<std::endl;
        size = 0; 
        head = new node<T>;
        if(head == nullptr){
            exit(1);
        }
        head->next = nullptr;
        head->prev = nullptr;
    }

    template <class T>
    List<T>::List(int size, T array[]) {
        std::cout<<"Parameter Constructor called"<<std::endl;
        this->size = size;
        node<T> *aux1;
        node<T> *aux2;
        head = new node<T>;
        if(head == nullptr){
            exit(1);
        }
        aux1 = new node<T>;
        if(aux1 == nullptr){
            exit(1);
        }
        head = aux1;
        aux1->value = array[0];
        aux1->prev = nullptr;
        for(int i = 1; i < size; i++){
            aux2 = new node<T>;
            if(aux2 == nullptr){
                exit(1);
            }
            aux1->next = aux2;
            aux2->value = array[i];
            aux2->prev = aux1;
            aux1=aux2;
        }
        aux2->next = nullptr;
    }

    template <class T>
    List<T>::~List() {
        std::cout<<"Destructor called"<<std::endl;
        while(head != nullptr){
            node<T> *aux = head;
            aux = head;
            head = head->next;
            delete aux;  
        }
    }

    template <class T>
    void List<T>::push_front(T element) {
        std::cout<<"Pushing "<<element<<" in front."<<std::endl;
        node<T> *aux = new node<T>;
        if(aux == nullptr){
            exit(1);
        }
        size++;
        aux->value = element;
        aux->prev = nullptr;
        aux->next = head;
        head->prev = aux;
        head = aux;
    }
    template <class T>
    void List<T>::push_back(T element) {
        std::cout<<"Pushing "<<element<<" in back."<<std::endl;
        node<T> *aux = new node<T>;
        if(aux == nullptr){
            exit(1);
        }
        node<T> *c = head;
        aux->value = element;
        aux->next = nullptr;
        while(c->next != nullptr){
            c = c->next;
        }
        size++;
        aux->prev = c;
        c->next = aux;
    }

    template <class T>
    T List<T>::pop_front() {
        T x = head->value;
        std::cout<<"Popping "<<x<<" from front."<<std::endl;
        node<T> *aux = head->next;
        aux->prev = nullptr;
        size--;
        delete head;
        return x;
    }

    template <class T>
    T List<T>::pop_back() {
        T x;
        node<T> *c = head;
        while(c->next != nullptr){
            c = c->next;
        }
        size--;
        x = c->value;
        std::cout<<"Popping "<<x<<" from back."<<std::endl;
        c->prev->next = nullptr;
        delete c;
        return x;
    }

    template <class T>
    T List<T>::get_front() {
        return head->value;
    }

    template <class T>
    T List<T>::get_back() {
        node<T> *c = head;
        while(c->next != nullptr){
            c = c->next;
        }
        return c->value;
    }

    template <class T>
    int List<T>::get_size() {
        return size;
    }

