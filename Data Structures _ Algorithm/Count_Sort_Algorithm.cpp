#include <iostream>

void count_sort(int *arr, int size, int range)
{
    int *count_arr=new int[range];
    int *output=new int[size];
    for(int i=0; i<range; i++){count_arr[i]=0;}
    for(int i=0; i<size; i++){count_arr[arr[i]]++;}
    for(int i=0; i<range; i++){count_arr[i]=count_arr[i]+count_arr[(i-1)];}
    for(int i=0; i<size; i++)
    {
        output[count_arr[arr[i]]--] = arr[i];
    }
    for(int i=0; i<size; i++)
    {
        arr[i]=output[i];
    }
}

int main ()
{
    int size;
    int range;
    std::cout<<"Range Of Value For Elements ="; std::cin>>range;
    std::cout<<"Size Of Elements ="; std::cin>>size;
    int *arr=new int[size];
    std::cout<<"Input "<<size<<" Element =\n";
    for(int i=0; i<size; i++){std::cin>>arr[i];}
    
    std::cout<<"Data Before Sorted =(";
    for(int i=0; i<size; i++)
    {
        std::cout<<arr[i]<<" ";
    }
    std::cout<<")\n";
    
    count_sort(arr,size,range);

    std::cout<<"Data After Sorted =(";
    for(int i=0; i<size; i++)
    {
        std::cout<<arr[i]<<" ";
    }
    std::cout<<")\n";

    return 0;
}