#include <iostream>

void fill (int arr[], int size)
{
    for(int i=0; i<size; i++)
    {
        arr[i]=i;
    }
    std::cout<<"Array Ready\n";
}

int binary_search(int arr[], int search, int right)
{
    int left=0;
    int mid;
    while(left<=right)
    {
        mid=(right+left)/2; 
        std::cout<<"mid ="<<mid<<"\n";
        if(arr[mid]==search)
        {
            std::cout<<"arr ="<<arr[mid]<<std::endl;
            return arr[mid];
        }
        else if(arr[mid]<search)
        {
            left=mid+1;
            std::cout<<"left ="<<left<<std::endl;
        }
        else
        {
            right=mid-1;
            std::cout<<"right ="<<right<<std::endl;
        }
    }
    return -1;
}

int main()
{
    int size=10;
    int array[size];
    int search;
    fill(array,size);

    std::cout<<"Input Number That You Want to Search ="; std::cin>>search;
    int results=binary_search(array,search,size);
    if(results==-1)
    {
        std::cout<<"Number is Not In The List\n";
    }
    else
    {
        std::cout<<"Number Found ="<<results<<std::endl;
    }

    return 0;
}