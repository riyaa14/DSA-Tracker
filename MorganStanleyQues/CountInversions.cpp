class Solution{
public:
    long long merge(long long *arr, int left, int right, int mid){
        int i=left, j=mid+1, k=0;
        long long inv = 0;

        long long *temp = new long long[right-left+1];

        while(i<=mid and j<=right){
            if(arr[i] > arr[j]){
                inv += mid-i+1;
                temp[k++] = arr[j++];
            }else{
                temp[k++] = arr[i++];
            }
        } 

        while(i<=mid){
            temp[k++] = arr[i++];
        }

        while(j<=right){
            temp[k++] = arr[j++];
        }

        k=0;
        for(int x=left; x<=right; x++){
            arr[x] = temp[k++];
        }  
        
        delete[] temp;

        return inv;            
    }

    long long mergeSort(long long *arr, int left, int right){
        if(left == right) return 0;

        int mid = ((right-left)/2) + left;

        long long x = mergeSort(arr, left, mid);
        long long y = mergeSort(arr, mid+1, right);

        long long z = merge(arr, left, right, mid);

        return x+y+z;
    }
    
    long long int inversionCount(long long arr[], long long N){
        return mergeSort(arr, 0, N-1);
    }
};
