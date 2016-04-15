#include <vector>
#include <iostream>

 
bool check(const std::vector<int>& a)
{
    for(int i=0; i<a.size(); ++i)
        std::cout << a[i] << " ";
    std::cout << std::endl;
    return false;
}

void traverse(const std::vector<int>& a)
{
    if(a.size() == 2)
    {
        check(a);
        return;
    }

    if(!check(a))
    {
        // generate & traverse subsets
        for(int i=0; i<a.size(); ++i)
        {
            std::vector<int> sub_a(a);
            sub_a.erase(sub_a.begin() + i);
            traverse(sub_a);
        }
    }
    else
        return;
    
}

int main()
{
    size_t n = 5;
    int raw_a[] = {0,1,2,3,4};//{0,1,2,3,4,5,6,7,8,9,10,11};

    std::vector<int> a(raw_a+0,raw_a+n);
    
    traverse(a);

    return 0;
}