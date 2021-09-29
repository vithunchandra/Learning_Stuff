#include <iostream>
#include <cmath>

class MinHeap
{
    public:
        int *harray;
        int capacity;
        int heap_size;

        MinHeap(int cap)
        {
            capacity = cap;
            heap_size = 0;
            harray = new int[capacity];
        }

        int Linear_search(int value)
        {
            for(int i=0; i<heap_size; i++){if(harray[i]==value){return i;}}
            return -1;
        }

        void Print_Heap()
        {
            std::cout<<"(";
            for(int i=0; i<heap_size; i++){std::cout<<harray[i]<<" ";}
            std::cout<<")\n";
        }

        int Height(){return std::ceil(std::log2(heap_size+1))-1;}
        int parent(int value){return (value-1)/2;}
        int left_child(int value){return (value*2)+1;}
        int right_child(int value){return (value*2)+2;}

        void Insert(int value)
        {
            if(heap_size==capacity){std::cout<<"Heap Is Full\n"; return ;}
            else
            {
                harray[heap_size]=value;
                heap_size++;
                int pointer=heap_size-1;
                while(pointer!=0  && harray[pointer] < harray[(pointer-1)/2])
                {
                    int temp=harray[(pointer-1)/2];
                    harray[(pointer-1)/2]=harray[pointer];
                    harray[pointer]=temp;
                    pointer=(pointer-1)/2;
                }
            }
        }

        void Heapify(int parent)
        {
            while((left_child(parent)<heap_size && right_child(parent)<heap_size))
            {
                if(harray[left_child(parent)]<harray[right_child(parent)] && harray[left_child(parent)]<harray[parent])
                {
                    int temp=harray[parent];
                    harray[parent]=harray[left_child(parent)];
                    harray[left_child(parent)]=temp;
                    parent=left_child(parent);
                }
                else
                {
                    int temp=harray[parent];
                    harray[parent]=harray[right_child(parent)];
                    harray[right_child(parent)]=temp;
                    parent=right_child(parent);
                }
            }
        }

        void Heapify_Recursion(int index)
        {
            int left=left_child(index);
            int right=right_child(index);
            int smallest=index;
            if(left<heap_size && harray[left]<harray[smallest]){smallest=left;}
            if(right<heap_size && harray[right]<harray[smallest]){smallest=right;}
            if(smallest!=index)
            {
                int temp=harray[index];
                harray[index]=harray[smallest];
                harray[smallest]=temp;
                Heapify_Recursion(smallest);
            }
        }

        int Delete(int index)
        {
            if(heap_size==1)
            {
                int temp=harray[index];
                heap_size--; 
                std::cout<<"Delete Success\n";
                return temp;
            }
            else
            {
                int temp=harray[index];
                harray[index]=harray[heap_size-1];
                heap_size--;
                Heapify_Recursion(index);
                return temp;
            }
        }

        int Extract_Min()
        {
            if(heap_size==0){std::cout<<"Test\n"; return -1;}
            else if(heap_size==1)
            {
                heap_size--;
                return harray[heap_size];
            }
            else
            {
                int temp=harray[0];
                heap_size--;
                harray[0]=harray[heap_size];
                Heapify_Recursion(0);
                return temp;
            }
        }

        void GetUnsortedArray()
        {
            std::cout<<"Input "<<capacity<<" Elements Of Array =\n";
            for(int i=0; i<capacity; i++)
            {
                std::cin>>harray[i];
                heap_size++;
            }
        }

        void Sorted_Array()
        {
            for(int index=(heap_size-2)/2;index>=0;index--){Heapify(index);}
        }

        void Heap_Sort()
        {
            std::cout<<"[";
            while(heap_size!=0)
            {
                int temp=Extract_Min();
                std::cout<<temp<<" ";
                Heapify_Recursion(heap_size);
            }
            std::cout<<"]\n";
        }
};

int main ()
{
    int size;
    std::cout<<"Input Size Of Array ="; std::cin>>size;
    MinHeap heap(size);
    heap.GetUnsortedArray();
    std::cout<<"Before Sorted =";
    heap.Print_Heap();
    heap.Sorted_Array();
    heap.Print_Heap();
    heap.Heap_Sort();
    std::cout<<"After Sorted =";
    heap.Print_Heap();

    return 0;
}