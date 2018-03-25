
//  Created by Arshdeep Singh Bhullar on 2017-10-25.
//  Copyright © 2017 Arshdeep Singh Bhullar. All rights reserved.
//

#include "q1.hpp"
#include <iostream>
#include <ctime>
using namespace std;
using namespace QueueArshdeep;

Queue::Queue()
{
    front = nullptr;
    back = nullptr;
}

void Queue::add(long &seconds)
{
    if(empty())
    {
        front = new QueueNode;
        front->data = seconds;
        front->link = nullptr;
        back = front;
    }
    else
    {
        QueueNodePtr temp_ptr;
        temp_ptr = new QueueNode;
        temp_ptr->data = seconds;
        temp_ptr->link = nullptr;
        back->link = temp_ptr;
        back = temp_ptr;
    }
}


long Queue::remove(long &seconds)
{
    long waitTime;
    if (empty())
    {
        cout << "The line is empty" << endl;
        exit(1);
    }
    else
    {
        waitTime = seconds - front->data;               // the time specific customer was waiting in the queue
        /
        QueueNodePtr discard;
        discard = front;
        front = front->link;
        if(front == nullptr)
        {
            back = nullptr;
        }
        delete discard;
        return waitTime;
    }
}

long Queue::updateWaitTime(long& newTime)
{
    long averageWaitTime;
    int count = 0;
    for(int i = 2; i > 0; i--)
    {
        wait[i] = wait[i-1];
    }
    wait[0] = newTime;
    for(int i = 1; i < 3; i++)
    {
        if(wait[i] == 0)
        {
            count++;
        }
    }
    averageWaitTime = (wait[2]+wait[1]+wait[0])/(3-count);
    return averageWaitTime;
}

bool Queue::empty()
{
    return (front == nullptr);
}

Queue::~Queue()
{
    while (!empty())
    {
        QueueNodePtr discard;
        discard = front;
        front = front->link;
        if(front == nullptr)
        {
            back = nullptr;
        }
        delete discard;
    }
}



