void merge(int arr[], int s, int m, int e){

    int aux[e-s];

    for (int i=s; i<=e; i++){
        aux[i] = arr[i];
    }

    int i = s;//index for left half
    int j = m+1;//index for right half

    for (int k = s; k<=e; k++){
        if (i > m) arr[k] = aux[j++];//right side is bigger then left side array
        if (j > e) arr[k] = aux[i++];//left side is bigger then right side array
        if (aux[i] < aux[j]) arr[k] = aux[i++];
        if (aux[j] < aux[i]) arr[k] = aux[j++];
        
    }
}
void mergeSort(int arr[], int s, int e){
    if (s < e){
        int m = s+(e-s)/2;
        mergesort(arr, s, m);
        mergesort(arr, m+1, e);
        merge(arr, s, m, e);
    } 
}
