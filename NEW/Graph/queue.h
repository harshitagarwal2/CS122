template <class T,int Maxsize>
class Queue
{
   T arr[Maxsize];
   int Front;
   int Rear;
public:
    Queue(){Front=Rear=-1;}
    bool IsEmpty(){ return Front==Rear;}
    bool IsFull(){return Rear==Maxsize-1;}
    void Insert(T item){
        if (IsFull()) {cout<<"Queue Overflow";return;}
        arr[++Rear]=item;
    }
    T Delete(){
        if (IsEmpty()){ cout<<"Queue Underflow";return -99;}
        return (arr[++Front]);
    }

};

