#include "iostream"
using namespace std;

void quickSort(int *arr, int begin, int end)
{
    if(begin<end)
    {
        int pivot = arr[end];
        int i=0;
        int j=end-1;
        while(1)
        {
            while(arr[i] < pivot)
                i++;
            while(arr[j] > pivot)
                j--;
            if(i<j)
                swap(arr[i], arr[j]);
            else
                break;
        }
        swap(arr[i], arr[end]);
        
        quickSort(arr, begin, i-1);
        quickSort(arr, i+1, end);
    }
}

void shellSort(int *arr, int len) 
{ 
    for(int gap=len/2; gap>=1; gap/=2) 
    { 
        for(int i=gap; i<len; i++) 
        { 
            int pivot = arr[i]; 
            int j=i-gap; 
            for(; j>=0 && arr[j]<pivot; j-=gap) 
                arr[j+gap] = arr[j]; 
            arr[j+gap] = pivot; 
        } 
    } 
} 

void merge(int *arr, int *temp, int lstart, int lend, int rend)
{
    int rstart = lend+1;
    int index = lstart;
    int i = lstart;
    int j = rstart;
    while(i<=lend && j<=rend)
    {
        if(arr[i] > arr[j])
            temp[index++] = arr[i++];
        else
            temp[index++] = arr[j++];
    }
    while(i<=lend)
        temp[index++] = arr[i++];
    while(j<=rend)
        temp[index++] = arr[j++];
    for(int i=lstart; i<=rend; i++)
        arr[i] = temp[i];
}



void mergeSort(int *arr, int start, int end)
{
    int *temp = new int[end-start+1];
    if(start<end)
    {
        int mid = (start+end)/2;
        mergeSort(arr, start, mid);
        mergeSort(arr, mid+1, end);
        merge(arr, temp, start, mid, end);
    }
    delete[] temp;
}

class heap
{
public:
    heap(int size=10)
    {
        Maxsize = size;
        array = new int[Maxsize+1];
        tail = 0;
    }
    ~heap(){delete[] array;}
    bool insert(int x)
    {
        if(tail == Maxsize)
            return false;
        array[++tail] = x;
        siteup(tail);
        return true;
    }
    bool pop(int &x)
    {
        if(tail == 0)
            return false;
        swap(array[1], array[tail]);
        tail--;
        sitedown(1, tail);
        x = array[tail+1];
        return true;
    }
    void heapSort()
    {
        int x;
        int num = tail;
        for(int i=0; i< num; i++)
        {
            pop(x);
            cout<<x<<" ";
        }
        cout<<endl;
    }


private:
    void sitedown(int hole, int size);
    void siteup(int hole);
    int Maxsize;
    int *array;
    int tail;
};
    
void heap::sitedown(int hole, int size)
{
    int pivot = array[hole];
    int child;
    for(; hole*2<=size; hole=child)
    {
        child = hole*2;
        if(child < size && array[child]<array[child+1])
            child++;
        if(array[child] > pivot)
            array[hole] = array[child];
        else
            break;
    }
    array[hole] = pivot;
}

void heap::siteup(int hole)
{
    int pivot = array[hole];
    int parent;
    for(; hole>1; hole=parent)
    {
        parent = hole/2;
        if(array[parent] < pivot)
            array[hole] = array[parent];
        else
            break;
    }
    array[hole] = pivot;
}



int main()
{
    const int size =5;
    int a[size] = {0};
    for(int i=0;i<size;i++)
        cin>>a[i];


    //quickSort(a, 0, size-1);
    //shellSort(a, size);
    mergeSort(a, 0, size-1);
    //heap maxheap;
    //for(int i=0;i<size;i++)
    //    maxheap.insert(a[i]);
    //maxheap.heapSort();


    for(int i=0;i<size;i++)
        cout<<a[i]<<" ";
    cout<<endl;
    return 0;
}

