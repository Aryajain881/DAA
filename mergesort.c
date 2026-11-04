//FIND THE EXECUTION TIME OF MERGE SORT ALGORITHM
#include<stdio.h>
#include<time.h>

void merge(int arr[],int l,int mid,int r){
    int i=l,j=mid+1,k=0;
    int temp[r-l+1];

    while(i<=mid && j<=r){
        if(arr[i]<arr[j]){
            temp[k++]=arr[i++];
        }
        else{
            temp[k++]=arr[j++];
        }
    }

    while(i<=mid){
        temp[k++]=arr[i++];
    }

    while(j<=r){
        temp[k++]=arr[j++];
    }

    for(i=l,k=0;i<=r;i++,k++){
        arr[i]=temp[k];
    }
}

void merge_sort(int arr[],int l,int r){
    if(l<r){
        int mid=(l+r)/2;

        merge_sort(arr,l,mid);
        merge_sort(arr,mid+1,r);

        merge(arr,l,mid,r);
    }
}

int main(){
    int arr[]={10,9,8,7,6,5,4,3,2,1};
    int n=sizeof(arr)/sizeof(arr[0]);

    clock_t start,end;
    double cpu_time_used;

    start=clock();

    merge_sort(arr,0,n-1);

    end=clock();

    cpu_time_used=((double)(end-start))/CLOCKS_PER_SEC;

    printf("Sorted array: ");
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }

    printf("\n%f seconds\n",cpu_time_used);

    return 0;
}