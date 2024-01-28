vector<ll> allDivisors(ll n) 
{ 
    int sz=(int)sqrt(n);
    vector<ll>a;
    for(ll i=1; i<=sz; i++) 
    { 
        if(n%i == 0) 
        { 
            if (n/i == i) a.push_back(i);
            else {
               a.push_back(i); 
               a.push_back(n/i); 
            }  
        } 
    } 
    return a;
}
