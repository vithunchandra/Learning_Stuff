#include <iostream>

void bubble_sort(int arr[])
{
    int size=5;
    for(int i=0; i<size; i++)
    {
        int count=0;
        for(int j=0; j<(size-i-1); j++)
        {
            if(arr[j]>arr[j+1])
            {
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
            else{count++;}
        }
        if(count==(size-i-1)){std::cout<<"Success\n"; return;}
        std::cout<<"Iteration ="<<i<<"\n";
    }
}

int main()
{
    int arr[5];
    std::cout<<"Input Ten Element To The List\n";
    for(int i=0; i<5; i++)
    {
        std::cin>>arr[i];
    }
    bubble_sort(arr);
    std::cout<<"Sorted Data =(";
    for(int i=0; i<5; i++)
    {
        std::cout<<arr[i]<<", ";
    }
    std::cout<<")\n";

    return 0;
}