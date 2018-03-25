# AirportCustomerArrival-Queue

//CMPT-225, FALL 2017:
A program that implements the queue and simulates customers entering and leaving the queue. Input into the queue should be the ticket number and a timestamp when the ticket was entered into the queue. A ticket and its corresponding timestamp is removed when a customer service agent handles the next customer. The program should save the length of time the last three customers spent waiting in the queue. Every time a ticket is removed from the queue, update these times and output the average of the last three customers as an estimate of how long it will take until the next customer is handled. If nobody is in the queue, output that the line is empty.

The time(NULL) function returns the number of seconds since January 1, 1970, on most implementations of C++:

#include <ctime>
...
int main()
{
long seconds;
seconds = static_cast<long>(time(NULL));
cout << "Seconds since 1/1/1970: " << seconds << endl;
return 0;
}
