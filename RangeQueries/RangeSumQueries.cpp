template <class T> class SumSegmentTree {
  private:
	T comb(T a, T b) { return a + b; }
	const T DEFAULT = 0;

	vector<T> segtree;
	int len;

  public:
	SumSegmentTree(int len) : len(len), segtree(len * 2, DEFAULT) {}

	void set(int ind, T val) {
		assert(0 <= ind && ind < len);
		ind += len;
		segtree[ind] = val;
		for (; ind > 1; ind /= 2) {
			segtree[ind >> 1] = comb(segtree[ind], segtree[ind ^ 1]);
		}
	}

	T range_sum(int start, int end) {
		assert(0 <= start && start < len && 0 < end && end <= len);
		T sum = DEFAULT;
		for (start += len, end += len; start < end; start /= 2, end /= 2) {
			if ((start & 1) != 0) { sum = comb(sum, segtree[start++]); }
			if ((end & 1) != 0) { sum = comb(sum, segtree[--end]); }
		}
		return sum;
	}
};

//To understand how to use; or use usaco Gold-Range update;
SumSegmentTree<long long> segtree(arr_len);//set arr length;

segtree.set(i, n);//set value at index i;

cout << segtree.range_sum(start - 1, end) << '\n';//print range sum;
