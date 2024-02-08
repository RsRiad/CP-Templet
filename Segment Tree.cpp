struct SegmentTree {
    ll n;
    vector<ll> st;

    void init(ll _n) {
        n = _n;
        st.resize(4 * n, 0);
    }

    void build(ll node, ll s, ll e, vector<ll> &v) {
        if (s == e) {
            st[node] = v[s];
            return;
        }
        ll mid = (s + e) >> 1;
        ll l = node << 1;
        ll r = l | 1;
        build(l, s, mid, v);
        build(r, mid + 1, e, v);
        st[node] = st[l] + st[r];
    }

    ll query(ll node, ll s, ll e, ll i, ll j) {
        if (s > j || e < i) {
            return 0;
        }
        if (s >= i && e <= j) {
            return st[node];
        }
        ll mid = (s + e) >> 1;
        ll l = node << 1;
        ll r = l | 1;
        ll q1 = query(l, s, mid, i, j);
        ll q2 = query(r, mid + 1, e, i, j);
        return q1 + q2;
    }

    void update(ll node, ll s, ll e, ll index, ll value) {
        if (s == e) {
            st[node] = value;
            return;
        }
        ll mid = (s + e) >> 1;
        ll l = node << 1;
        ll r = l | 1;
        if (index <= mid) update(l, s, mid, index, value);
        else update(r, mid + 1, e, index, value);
        st[node] = st[l] + st[r];
    }

    void build(vector<ll> &v) {
        build(1, 0, n - 1, v);
    }

    ll query(ll l, ll r) {
        return query(1, 0, n - 1, l, r);
    }

    void update(ll x, ll y) {
        update(1, 0, n - 1, x, y);
    }
};
