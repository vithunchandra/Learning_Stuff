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
    int size,input,value;
    std::cout<<"Input The Size Of Heap ="; std::cin>>size;
    MinHeap heap(size);
    do
    {
        std::cout<<"What Operation Do You Want To Perform ?\n";
        std::cout<<"0. Exit Program\n";
        std::cout<<"1. Insert Key/Node\n";
        std::cout<<"2. Search Key/Node\n";
        std::cout<<"3. Delete Key Node\n";
        std::cout<<"4. Get Min\n";
        std::cout<<"5. Extract Min\n";
        std::cout<<"6. Height Of Heap\n";
        std::cout<<"7. Print Heap Values\n";
        std::cout<<"8. Clear Screen\n";
        std::cout<<"9. Heap Sort\n";
        std::cout<<"Select ="; std::cin>>input;

        switch(input)
        {
            case 0:
            {
                break;
            }
            case 1:
            {
                std::cout<<"// INSERT\n";
                std::cout<<"Input Value Of Node ="; std::cin>>value;
                heap.Insert(value);
                break;
            }
            case 2:
            {
                std::cout<<"// SEARCH\n";
                std::cout<<"Input Value Of Node To Search ="; std::cin>>value;
                int search=heap.Linear_search(value);
                if(search==-1){std::cout<<"Value Doesn't Exist\n";}
                else{std::cout<<"Value Found. Value ="<<search<<std::endl;}
                break;
            }
            case 3:
            {
                std::cout<<"// DELETE\n";
                std::cout<<"Input Value Of Node To Delete ="; std::cin>>value;
                int index=heap.Linear_search(value);
                if(heap.heap_size==0){std::cout<<"Heap Is Empty\n";}
                else if(index==-1){std::cout<<"Value Doesn't Exist\n";}
                else
                {
                    std::cout<<"Index ="<<index<<std::endl;
                    int delete_value=heap.Delete(index);
                    std::cout<<"Delete Success\n";
                    std::cout<<"Delete Value ="<<delete_value<<std::endl;
                }
                break;
            }
            case 4:
            {
                std::cout<<"// GET MIN\n";
                std::cout<<"Minimum Value ="<<heap.harray[0]<<std::endl;
                break;
            }
            case 5:
            {
                std::cout<<"// EXTRACT MIN\n";
                int min=heap.Extract_Min();
                if(min==-1){std::cout<<"Heap Empty\n";}
                else{std::cout<<"Min Value ="<<min<<std::endl;}
                break;
            }
            case 6:
            {
                std::cout<<"// HEIGHT\n";
                std::cout<<"Height ="<<heap.Height()<<std::endl;
                break;
            }
            case 7:
            {
                std::cout<<"// PRINT\n";
                heap.Print_Heap();
                break;
            }
            case 8:
            {
                system("CLS");
                break;
            }
            case 9:
            {
                heap.Heap_Sort();
                break;
            }
            default:
            {
                std::cout<<"Input Invalid\n";
                break;
            }
        }
    }while(input!=0);
    std::cout<<"Exit Program\n";

    return 0;
}