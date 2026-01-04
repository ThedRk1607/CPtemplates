

int n,q,a[N];

struct Fenwick{
    int sum[N];
    void inline add(int x,int k){
        while(x<=500001){
            sum[x]+=k;
            x+=lowbit(x);
        }
    }
    int inline ask(int x){
        int res=0;
        while(x){
            res+=sum[x];
            x^=lowbit(x);
        }
        return res;
    }
    int inline ask(int l,int r){
        return ask(r)-ask(l-1);
    }
}t1,t2;


void solve(){
	int n,q;cin>>n>>q;
	rep(i,1,n+1){
		cin>>a[i];t1.add(a[i]+1,1);t2.add(a[i]+1,a[i]);
	}
	while(q--){
		 int op;
        cin >> op;
        if(op==2){
            int l,r;
            cin >> l >> r;
            if(l>r){
                cout << l*n << endl;
            }else{
                cout << t1.ask(l)*l+t2.ask(l+1,r+1)+t1.ask(r+2,500001)*r << endl;
            }
        }else{
            int x,y;
            cin >> x >> y;
            t1.add(a[x]+1,-1);
            t2.add(a[x]+1,-a[x]);
            t1.add(y+1,1);
            t2.add(y+1,y);
            a[x]=y;
        }
	}
}



template <class T> class BIT {
  private:
	int size;
	vector<T> bit;
	vector<T> arr;

  public:
	BIT(int size) : size(size), bit(size + 1), arr(size) {}

	/** Sets the value at index ind to val. */
	void set(int ind, T val) { add(ind, val - arr[ind]); }

	/** Adds val to the element at index ind. */
	void add(int ind, T val) {
		arr[ind] += val;
		ind++;
		for (; ind <= size; ind += ind & -ind) { bit[ind] += val; }
	}

	/** @return The sum of all values in [0, ind]. */
	T pref_sum(int ind) {
		ind++;
		T total = 0;
		for (; ind > 0; ind -= ind & -ind) { total += bit[ind]; }
		return total;
	}
};
