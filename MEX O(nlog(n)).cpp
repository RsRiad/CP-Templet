ll mex(vector<ll>const& A) {
    set<ll> b(A.begin(), A.end());
    ll result = 0;
    while (b.count(result)) ++result;
    return result;
}
