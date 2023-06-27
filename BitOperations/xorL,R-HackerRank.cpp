
int maximizingXor(int l, int r) {
    int p=l^r;
    int res=1;
    while(p){
        p>>=1;
        res<<=1;
    }
    return res-1;
}
