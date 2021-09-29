#include <iostream>

void count_sort(int arr[], int size, int divide)
{
    int output[size];
    int count_sort[10];
    for(int i=0; i<10; i++){count_sort[i]=0;}
    for(int i=0; i<size; i++){count_sort[(arr[i]/divide)%10]++;}
    for(int i=1; i<10; i++){count_sort[i]=count_sort[i]+count_sort[(i-1)];}
    for(int i=(size-1); i>=0; i--)
    {
        output[count_sort[(arr[i]/divide)%10]-1]=arr[i];
        count_sort[(arr[i]/divide)%10]--;
    }
    for(int i=0; i<size; i++){arr[i]=output[i];}
}

void radix_sort(int arr[], int size, int max)
{
    for(int divide=1; max/divide>0; divide*=10){count_sort(arr,size,divide);}
}

int main ()
{
    int max=0;
    int size;
    std::cout<<"Size Of Elements ="; std::cin>>size;
    int arr[size];
    std::cout<<"Input "<<size<<" Elements =\n";
    for(int i=0; i<size; i++)
    {
        std::cin>>arr[i];
        if(arr[i]>max){max=arr[i];}
    }
    std::cout<<"Data Before Sorted =(";
    for(int i=0; i<size; i++)
    {
        std::cout<<arr[i]<<" ";
    }
    std::cout<<")\n";
    radix_sort(arr,size,max);
    std::cout<<"Data After Sorted =(";
    for(int i=0; i<size; i++)
    {
        std::cout<<arr[i]<<" ";
    }
    std::cout<<")\n";

    return 0;
}