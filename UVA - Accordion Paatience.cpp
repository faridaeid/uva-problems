//
//  UVA - Accordion Paatience.cpp
//  ACM Training
//
//  Created by Farida Eid on 8/21/17.
//  Copyright © 2017 Farida Eid. All rights reserved.
//

#include <iostream>
#include <vector>

#define cmp(a,b) (a[0] == b[0] || a[1] == b[1])

using namespace std;

int main()
{
    string input;
    bool done = false;
    
    while(!done)
    {
        int i = 0;
        vector<string> stack;
        vector<int> count;
        
        for(i = 0; i < 52; i++)
        {
            cin>>input;
            
            bool pushInStack = true;
            
            if (input == "#")
            {
                break;
            }
            
            string back = input;
            int pile = 1;
            
            while ((stack.size() && cmp(back, stack.back())) || (stack.size() >= 3 && cmp(stack[stack.size() - 3], back)))
            {
                
                if ((stack.size() >= 3 && cmp(stack[stack.size() - 3], back)))
                {
                    stack[stack.size() - 3] = back;
                    count[stack.size() - 3]+= pile;
                }
                else
                {
                
                        stack.back() = back;
                        count.back()+= pile;
                
                }
                    
                
                back = stack.back();
                stack.pop_back();
                
                pile = count.back();
                count.pop_back();
                
            }
            
           stack.push_back(back);
            count.push_back(pile);
            
            
        }
        
        if (i != 52)
        {
            done = true;
        }
        else
        {
            for (int i =0; i < count.size(); i++)
                cout<<count[i]<<" ";
            
            cout<<endl;
        }
    }
}
