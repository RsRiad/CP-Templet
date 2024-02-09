struct SegmentTree {
    int N;
    vector<int> st;

    void init(int _n) {
        N = _n;
        st.resize(4 * N, 0);
    }

    void build(int n, int s, int e, vector<int> &v) {
        if (s == e) {
            st[n] = v[s];
            return;
        }
        int mid = (s + e) >> 1;
        int l = n << 1;
        int r = l | 1;
        build(l, s, mid, v);
        build(r, mid + 1, e, v);
        st[n] = st[l] + st[r];
    }

    int query(int n, int s, int e, int i, int j) {
        if (s > j || e < i) {
            return 0;
        }
        if (s >= i && e <= j) {
            return st[n];
        }
        int mid = (s + e) >> 1;
        int l = n << 1;
        int r = l | 1;
        int q1 = query(l, s, mid, i, j);
        int q2 = query(r, mid + 1, e, i, j);
        return q1 + q2;
    }

    void update(int n, int s, int e, int index, int value) {
        if (s == e) {
            st[n] = value;
            return;
        }
        int mid = (s + e) >> 1;
        int l = n << 1;
        int r = l | 1;
        if (index <= mid) update(l, s, mid, index, value);
        else update(r, mid + 1, e, index, value);
        st[n] = st[l] + st[r];
    }

    void build(vector<int> &v) {
        build(1, 0, N - 1, v);
    }

    int query(int l, int r) {
        return query(1, 0, N - 1, l, r);
    }

    void update(int x, int y) {
        update(1, 0, N - 1, x, y);
    }
}s;
