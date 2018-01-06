int identical(int a[], int b[], unsigned int len){
    int i=0;
    
    for(i=0; i<len; i++){
        if(len==0){
            return 1;
        }
        else if(a[i]!=b[i]){
            return 0;
        }
    }
    return 1;
}
