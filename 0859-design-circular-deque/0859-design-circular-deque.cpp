class DQueue
{
    public:
    DQueue * next;
    DQueue * rear;
    int val;

    DQueue(int v)
    {
        val = v;
        next = NULL;
        rear = NULL;
    }
};

class MyCircularDeque {
public:
    DQueue * headFront;
    DQueue * headRear;
    int size;
    int maxSize;

    MyCircularDeque(int k) {
        headFront = NULL;
        headRear = NULL;
        size = 0;
        maxSize = k;
    }
    
    bool insertFront(int value) {
        if(size == maxSize)
            return false;

        DQueue * temp = new DQueue(value);
        if(headFront == NULL)
        {
            headRear = temp;
            headFront = temp;
        }
        else
        {
            headFront->rear = temp;
            temp->next = headFront;
            headFront = temp;
        }

        
        size += 1;
        return true;
    }
    
    bool insertLast(int value) {
        if(size == maxSize)
            return false;

        DQueue * temp = new DQueue(value);
        if(headRear == NULL)
        {
            headRear = temp;
            headFront = temp;
        }
        else
        {
            headRear->next = temp;
            temp->rear = headRear;
            headRear = temp;
        }
        size += 1;
        return true;
    }
    
    bool deleteFront() {
        if(headFront == NULL)
            return false;

        DQueue * temp = headFront;
        headFront = temp->next;
        temp = NULL;
        delete temp;
        size -= 1;

        if(size == 0)
        {
            headFront = NULL;
            headRear = NULL;
        }
        return true;
    }
    
    bool deleteLast() {
        if(headRear == NULL)
            return false;

        DQueue * temp = headRear;
        headRear = temp->rear;
        temp = NULL;
        delete temp;

        size -= 1;

         if(size == 0)
        {
            headFront = NULL;
            headRear = NULL;
        }
        return true;
    }
    
    int getFront() {
        return headFront == NULL ? -1 :  headFront->val;
    }
    
    int getRear() {
        return headRear == NULL ? -1 : headRear->val;
    }
    
    bool isEmpty() {
        return size == 0 ? true:false;
    }
    
    bool isFull() {
        return size == maxSize ? true:false;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */