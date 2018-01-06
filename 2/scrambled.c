//#define identical_h


int scrambled(unsigned int a[], unsigned int b[], unsigned int len)
{
    int c[100];
    int d[100];
    int i=0;
    //initialization
    for (i=0; i<100; i++) {
        c[i]=0;
        d[i]=0;
    }
    //check in
    for (i=0; i<len; i++) {
        c[a[i]]+=1;
        d[b[i]]+=1;
    }
    
    for(i=0; i<100; i++){
        if (c[i]!=d[i]) {
            return 0;
        }
    }
    return 1;
    
}



