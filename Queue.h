//
//  Queue.h
//  Assignment 10
//
//  Created by Leron Julian on 5/4/17.
//  Copyright © 2017 Leron Julian. All rights reserved.
//

#ifndef Queue_h
#define Queue_h

#include <iostream>
#include <string>
using namespace std;

#define ERROR

template <class XType>

class Queue

{
    
public:
    
    Queue();
    
    ~Queue();
    
    bool Is_Empty() const;
    
    bool Is_Full() const;
    
    void Enqueue( XType );
    
    XType Dequeue();
    
    int Size() const;
    
protected:
    
private:
    
    struct Queue_Node
    
    {
        
        XType Element;
        
        Queue_Node* Next;
        
    };
    
    typedef Queue_Node* Queue_Ptr;
    
    Queue_Ptr Front;
    
    Queue_Ptr Rear;
    
    int Q_Size;
};

template <class XType>

Queue<XType>::Queue()

{
    
    Q_Size = 0;
    
    Front = Rear = NULL;
    
}

template <class XType>

Queue<XType>::~Queue()

{
    
    Q_Size = 0;
    
    Front = Rear = NULL;
    
}

template <class XType>

bool Queue<XType>::Is_Empty() const

{
    
    return ( Q_Size == 0 &&
            
            Front == NULL &&
            
            Rear == NULL );
    
}

template <class XType>

bool Queue<XType>::Is_Full() const

{
    
    return ( false );
    
}

template <class XType>

int Queue<XType>::Size() const

{
    
    return (Q_Size);
    
}

template <class XType>

void Queue<XType>::Enqueue( XType item)

{
    
    if (!this->Is_Full())
        
    {
        
        ++Q_Size;
        
        Queue_Ptr QPtr = new Queue_Node;
        
        QPtr->Element = item;
        
        QPtr->Next = NULL;
        
        if (Rear == NULL)
        {
            Rear = Front = QPtr;
            
        }
        
        else
            
        {
            
            Rear->Next = QPtr;
            
            Rear = QPtr;
            
        }
        
    }
    
    else
        
    {
        
        cout << "QUEUE is full!";
        
        cout << "ENQUEUE operation is ignored." << endl;
        
    }
    
}

template <class XType>

XType Queue<XType>::Dequeue( )

{
    
    if (!this->Is_Empty())
        
    {
        
        --Q_Size;
        
        XType item = Front->Element;
        
        Front = Front->Next;
        
        if (Front == NULL)
            
            Rear = NULL;
        
        return item;
        
    }
    
    else
        
    {
        
        cout << "QUEUE is empty!";
        
        cout << "DEQUEUE operation is ignored." << endl;
        
        return ;
        
    }
    
}


#endif /* Queue_h */
