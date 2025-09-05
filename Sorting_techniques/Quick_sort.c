#include<stdio.h>

int partition(int arr[], int low, int high){
    int pivot=arr[low];
    int i=low+1;
    int j=high;
    do{
    while(arr[i]<=pivot){
        i++;
    }
    while(arr[j]>pivot){
        j--;
    }
    if(i<j){
        int temp=arr[i];
        arr[i]=arr[j];
        arr[j]=temp;
    }
    }while(i<j);
    //swap arr[low] and arr[j]
    int temp=arr[low];
    arr[low]=arr[j];
    arr[j]=temp;
    return j;        

}
void quicksort(int arr[], int low, int high){
    int partitionIndex;   //index of pivot after partition
    if(low<high){
        partitionIndex=partition(arr,low,high);
        quicksort(arr,low,partitionIndex-1);   //sort left subarray
        quicksort(arr,partitionIndex+1,high);  //sort right subarray
    }
}
int main()
{
int arr[]={12,45,34,56,2,45,34,43,13,68,5,6,98};
int size=sizeof(arr)/sizeof(arr[0]);
int low=0;
int high=size-1;
quicksort(arr,low,high);
for(int i=0; i<size; i++){
    printf("%d\n",arr[i]);
}

return 0;
}