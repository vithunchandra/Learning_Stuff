#include <iostream>

void search(int arr[5], int pick)
{
    int temp=-1;
    for(int i=0; i<5; i++)
    {
        if(pick==arr[i])
        {
            std::cout<<"Element Found at Location ="<<(i+1)<<std::endl;
            temp=0;
        }
    }
    if(temp==-1)
    {
        std::cout<<"Element Didn't Found\n";
    }
}

int main()
{
    int arr[5];
    for(int i=0; i<5; i++)
    {
        std::cout<<"Input 5 Element To Array ="; std::cin>>arr[i];
    }
    int pick;
    std::cout<<"Input Element You Want to Input ="; std::cin>>pick;
    search(arr,pick);

    return 0;
}