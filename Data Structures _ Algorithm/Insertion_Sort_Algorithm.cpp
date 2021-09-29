#include <iostream>

void insertion_sort(int arr[])
{
    int key;
    int j=0;

    for(int i=1; i<10; i++)
    {
        key=arr[i];
        j=i-1;
        while(j>=0 && arr[j]>key)
        {
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
    }
    
}

int main()
{
    int arr[10];
    std::cout<<"Input Number To The Array =\n";
    for(int i=0; i<10; i++)
    {
        std::cin>>arr[i];
    }
    insertion_sort(arr);

    std::cout<<"(";
    for(int i=0; i<10; i++)
    {
        std::cout<<arr[i]<<", ";
    }
    std::cout<<")";

    return 0;
}