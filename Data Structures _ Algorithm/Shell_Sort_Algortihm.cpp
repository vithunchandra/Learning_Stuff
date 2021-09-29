#include <iostream>

void shell_sort(int arr[], int size)
{
    for(int gap=size/2; gap>0; gap/=2)
    {
        for(int i=gap; i<size; i++)
        {
            for(int j=i; j>0 && arr[j-gap]>arr[j]; j-=gap)
            {
                int temp=arr[j];
                arr[j]=arr[j-gap];
                arr[j-gap]=temp;
            }
        }
    }
}
int main ()
{
    int size;
    std::cout<<"Input Size Of Elements ="; std::cin>>size;
    int arr[size];
    std::cout<<"Input "<<size<<" Elements =\n";
    for(int i=0; i<size; i++){std::cin>>arr[i];}
    std::cout<<"Data Before Sorted=\n(";
    for(int i=0; i<size; i++){std::cout<<arr[i]<<" ";}
    std::cout<<")\n";

    shell_sort(arr,size);
    std::cout<<"Data After Sorted=\n(";
    for(int i=0; i<size; i++){std::cout<<arr[i]<<" ";}
    std::cout<<")\n";

    return 0;
}