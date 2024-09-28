public class Queue
{
    
    public Queue next;
    public Queue prev;
    public int val;
    public Queue(int v)
    {
        val = v;
        next = null;
        prev = null;
    }
}

public class MyCircularDeque {

    public int size;
    public int capacity;
    Queue front;
    Queue rear;

    public MyCircularDeque(int k) {
        size = 0;
        capacity = k;
        front = null;
        rear = null;
    }
    
    public bool InsertFront(int value) {
        if(IsFull())
        {
            return false;
        }
        if(IsEmpty())
        {
            Queue newFront = new Queue(value);
            front = newFront;
            rear = front;
        }
        else
        {
            Queue newFront = new Queue(value);
            newFront.next = front;
            front.prev = newFront;
            front = newFront;
        }
        size += 1;
        return true;
    }
    
    public bool InsertLast(int value) {
        if(IsFull())
        {
            return false;
        }
        if(IsEmpty())
        {
            Queue newFront = new Queue(value);
            front = newFront;
            rear = front;
        }
        else
        {
            Queue newRear = new Queue(value);
            newRear.prev = rear;
            rear.next = newRear;
            rear = newRear;
        }
        size += 1;
        return true;
    }
    
    public bool DeleteFront() {
        if(IsEmpty())
        {
            return false;
        }

        Queue temp = front;
        front = front.next;

        temp.next = null;
        temp.prev = null;
        temp = null;

        size -= 1;

        if(IsEmpty())
        {
            front = null;
            rear = null;
        }
        return true;
    }
    
    public bool DeleteLast() {
        if(IsEmpty())
        {
            return false;
        }

        Queue temp = rear;
        rear = rear.prev;

        temp.next = null;
        temp.prev = null;
        temp = null;

        size -= 1;

        if(IsEmpty())
        {
            front = null;
            rear = null;
        }
        return true;
    }
    
    public int GetFront() {
        if(IsEmpty())
        return -1;
        return front.val;
    }
    
    public int GetRear() {
        if(IsEmpty())
        {
            return -1;
        }
        return rear.val;
    }
    
    public bool IsEmpty() {
        if(size == 0)
        return true;
        return false;
    }
    
    public bool IsFull() {
        if(size == capacity)
        return true;
        return false;
    }
}

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque obj = new MyCircularDeque(k);
 * bool param_1 = obj.InsertFront(value);
 * bool param_2 = obj.InsertLast(value);
 * bool param_3 = obj.DeleteFront();
 * bool param_4 = obj.DeleteLast();
 * int param_5 = obj.GetFront();
 * int param_6 = obj.GetRear();
 * bool param_7 = obj.IsEmpty();
 * bool param_8 = obj.IsFull();
 */