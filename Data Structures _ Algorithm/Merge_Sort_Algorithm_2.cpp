#include <iostream>

void merge(int arr[], int left, int mid, int right);
void merge_sort(int arr[],int left, int right);

void merge_sort(int arr[],int left, int right)
{
    if(left<right)
    {
        int mid=(right+left)/2;
        merge_sort(arr,left,mid);
        merge_sort(arr,(mid+1),right);
        merge(arr,left,mid,right);
    }
}

void merge(int arr[], int left, int mid, int right)
{
    int amount = right-left;
    int *temp=new int[amount];
    int i=left;
    int j=mid+1;
    int k=0;
    while(i<=mid && j<=right)
    {
        if(arr[i] <= arr[j])
        {
            temp[k]=arr[i];
            i++; k++;
        }
        else
        {
            temp[k]=arr[j];
            j++; k++;
        }
    }
    while(i<=mid)
    {
        temp[k]=arr[i];
        i++; k++;
    }
    while(j<=right)
    {
        temp[k]=arr[j];
        j++; k++;
    }
    for(int a=0; a<amount; a++)
    {
        arr[left+a]=temp[a];
    }
}

int main()
{
    int left=0;
    int right=10;
    int arr[10];

    std::cout<<"Input Ten ELement To The Array =\n";
    for(int i=0; i<right; i++)
    {
        std::cin>>arr[i];
    }

    std::cout<<"Data Before Sorted =(";
    for(int i=0; i<right; i++)
    {
        std::cout<<arr[i]<<" ";
    }
    merge_sort(arr,left,right-1);
    std::cout<<")\n";
    std::cout<<"Data After Sorted =(";
    for(int i=0; i<10; i++)
    {
        std::cout<<arr[i]<<" ";
    }
    std::cout<<")\n";

    return 0;
}