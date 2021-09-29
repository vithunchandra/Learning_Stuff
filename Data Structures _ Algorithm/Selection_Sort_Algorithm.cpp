#include <iostream>

void selection_sort(int arr[], int size)
{
    int current;
    for(int i=0 ;i<size-1; i++)
    {
        current=i;
        for(int j=i+1; j<size; j++)
        {
            if(arr[current]>arr[j]){current=j;}
        }

        if(current!=i)
        {
            int temp=arr[current];
            arr[current]=arr[i];
            arr[i]=temp;
        }
    }

}

int main ()
{
    int arr[10];
    int size=10;
    std::cout<<"Fill The Array Ten Times\n";

    for(int i=0; i<10; i++)
    {
        std::cin>>arr[i];
    }

    selection_sort(arr,size);
    std::cout<<"(";
    for(int i=0; i<10; i++)
    {
        std::cout<<arr[i]<<", ";
    }
    std::cout<<")\n";

    return 0;
}