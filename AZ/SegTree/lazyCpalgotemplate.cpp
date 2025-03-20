const int N=300300;
int t[4*N],lazy[4*N];

int add(int a,int b){
	return (a+b);
}


void build(int a[], int v, int tl, int tr) {
    if (tl == tr) {
        t[v] = a[tl];
    } else {
        int tm = (tl + tr) / 2;
        build(a, v*2, tl, tm);
        build(a, v*2+1, tm+1, tr);
        t[v] = add(t[v*2], t[v*2 + 1]);
    }
}

void push(int v, int tl, int tr, int tm)
{
    int val = lazy[v];
    t[v*2] += (tm-tl+1)*val;
    lazy[v*2] += val;
    t[v*2+1] += (tr-tm)*val;
    lazy[v*2+1] += val;
    lazy[v] = 0;
}

void update(int v, int tl, int tr, int l, int r, int addend) {
    if (l > r) 
        return;
    if (l == tl && tr == r) {
        t[v] += (tr-tl+1)*addend;
        lazy[v] += addend;
    } else {
        int tm = (tl + tr) / 2;
        push(v, tl, tr, tm);
        update(v*2, tl, tm, l, min(r, tm), addend);
        update(v*2+1, tm+1, tr, max(l, tm+1), r, addend);
        t[v] = add(t[v*2], t[v*2+1]);
    }
}


int query(int v, int tl, int tr, int l, int r) {
    if (l > r)
        return 0;
    if (l == tl && tr == r)
        return t[v];
    int tm = (tl + tr) / 2;
    push(v, tl, tr, tm);
    return add(query(v*2, tl, tm, l, min(r, tm)), 
               query(v*2+1, tm+1, tr, max(l, tm+1), r));
}
