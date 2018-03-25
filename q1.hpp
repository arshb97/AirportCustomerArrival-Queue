
//  Created by Arshdeep Singh Bhullar on 2017-10-25.
//  Copyright © 2017 Arshdeep Singh Bhullar. All rights reserved.
//


#ifndef q1_hpp
#define q1_hpp
#include <iostream>

namespace QueueArshdeep
{
    
    struct QueueNode
    {
        long data;
        QueueNode *link;
        
    };
    
    typedef QueueNode* QueueNodePtr;
    
    class Queue
    {
        
    public:
        Queue();
        void add(long &seconds);
        long remove(long &seconds);
        bool empty();
        long updateWaitTime(long &newTime);
        ~Queue();
        
    private:
        QueueNodePtr front;
        QueueNodePtr back;
        long wait[3] = {0,0,0};
    };
}

#endif /* q1_hpp */
