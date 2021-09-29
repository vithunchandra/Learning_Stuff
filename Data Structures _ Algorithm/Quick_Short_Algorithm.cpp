#include <iostream>

int partition(int arr[], int start, int end)
{
    int pivot=arr[end];
    int position=start;
    for(int i=start; i<end; i++)
    {
        if(arr[i]<=pivot)
        {
            int temp=arr[position];
            arr[position]=arr[i];
            arr[i]=temp;
            position++;
        }
    }
    int temp=arr[position];
    arr[position]=pivot;
    arr[end]=temp;
    return position;
}

void quick_sort(int arr[], int start, int end)
{
    if(start<end)
    {
        int p=partition(arr, start, end);
        quick_sort(arr,start,(p-1));
        quick_sort(arr, (p+1), end);
    }
}

int main ()
{
    int start=0;
    int end=5;
    int arr[5];
    std::cout<<"Input 5 Elements\n";
    for(int i=0; i<5; i++)
    {
        std::cin>>arr[i];
    }
    std::cout<<"Data Before Sorted =(";
    for(int i =0; i<5; i++)
    {
        std::cout<<arr[i]<<" ";
    }
    std::cout<<")\n";
    quick_sort(arr, start, end);
    std::cout<<"Data After Sorted =(";
    for(int i=0; i<5; i++)
    {
        std::cout<<arr[i]<<" ";
    }
    std::cout<<")\n";

    return 0;
}