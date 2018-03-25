
//  tryyhome
//
//  Created by Arshdeep Singh Bhullar on 2017-10-25.
//  Copyright © 2017 Arshdeep Singh Bhullar. All rights reserved.
//

#include <iostream>
#include <string>
#include <cmath>
#include <ctime>
#include "q1.hpp"

using namespace std;
using namespace QueueArshdeep;
int main()
{
    Queue customer;
    long seconds;
    long waitTime;
    long averageWaitTime;
    int input;
    int count1;
    int count2;
    count1 = 1;
    count2 = 1;
    seconds = static_cast<long>(time(NULL));
   
    cout << "The line is empty " << endl;

    cout << "Enter '1' to simulate a customer's arrival, '2' to help the next customer, or '3' to quit." << endl;
    cin >> input;

    while (input != 3)
    {
        seconds = static_cast<long>(time(NULL));
        if (input == 1)
        {
            cout << "Customer " << count1 << " entered the queue at " << seconds << " seconds. " << endl;
            count1++;
            customer.add(seconds);
        }

        else if (input == 2)
        {
            if(customer.empty())
            {
                cout << "The line is empty" << endl;
            }
            else
            {
                waitTime = customer.remove(seconds);
                cout << "Customer " << count2 << " is being helped at time " << seconds << " seconds. " << "Wait Time = " << waitTime << endl;
                count2++;
                averageWaitTime = customer.updateWaitTime(waitTime);
                if(customer.empty())
                {
                    cout << "The line is empty" << endl;
                }
                else
                {
                    cout << "The estimated wait time for customer " << count2 << " is " << averageWaitTime << endl;     
                }
            }
        }

        else if (input == 3)
        {
            break;
        }
        else
        {
            cout << "Please enter a valid input." << endl;
        }
        cout << "Enter '1' to simulate a customer's arrival, '2' to help the next customer, or '3' to quit." << endl;
        cin >> input;
        cout << endl;
    }
    return 0;
}

