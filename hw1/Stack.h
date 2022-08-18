const int initialSize = 200;

template <class T> class Stack{
    private:
        int maxSize;
        int currentSize;
        T array[initialSize];
    public:
        Stack() {                                           //empty constructor
            std::cout<<"Empty Constructor called"<<std::endl;
            maxSize = 10; currentSize = -1;
        }             
        Stack(const Stack& stk){                            //copy constructor
        std::cout<<"Copy Constructor called"<<std::endl;
            maxSize = stk.maxSize;
            currentSize = stk.currentSize;
            for(int i = 0; i < maxSize; i++)
                array[i] = stk.array[i];
        }
        Stack(int s){       //initializez size to s
            std::cout<<"Size Constructor called"<<std::endl;
            maxSize = s; currentSize = -1;
        }
        bool push(T element){                               //push element method
            if(currentSize == maxSize)
                return false;
            std::cout<<"Pushing "<<element<<std::endl;
            currentSize++;
            array[currentSize] = element;
            return true;
        }
        bool pop(T& out){              //pop element method
            if(currentSize == -1)
                return false;
            std::cout<<"Popping "<<array[currentSize]<<std::endl;
            out = array[currentSize];
            currentSize--;
            return true;
        }
        T back(void){
            return array[currentSize];
        }
        ~Stack(){std::cout<<"Destructor called"<<std::endl;};
};