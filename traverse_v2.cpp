#include <vector>
#include <iostream>
#include <stdlib.h>
 
bool check(const std::vector<int>& a)
{
    bool res = (rand() % 100) > 79; // random result: P{res==0} = 80, P{res==1} = 20
    for(int i=0; i<a.size(); ++i)
        std::cout << a[i] << " ";
    std::cout << ( res ? "true" : "false") << std::endl;
    return res;
}

bool traverse(const std::vector<int>& a)
{ // depth-first search with conditional branching
    bool res = true;

    if(a.size() == 2)
    {
        return check(a); // leaf reached
    }

    if(!check(a))
    {
        // generate & traverse subsets
        for(int i=0; i<a.size(); ++i)
        {
            std::vector<int> sub_a(a);
            sub_a.erase(sub_a.begin() + i);
            res &= traverse(sub_a);
        }
        return res; // return from lower layer
    }
    else
        return true; // return on success
    
}

int main()
{
    srand(12434);

    size_t n = 5;
    int raw_a[] = {0,1,2,3,4}; //{0,1,2,3,4,5,6,7,8,9,10,11};

    std::vector<int> a(raw_a+0,raw_a+n);
    
    bool result = traverse(a);
    std::cout << "------------------------------" << std::endl;
    std::cout << "Result: " << result << std::endl;

    return 0;
}