vector<ll> primeFactors(ll n)
{
    vector<ll > factors;
    for(auto & p: primes)
    {
        if(1LL*p*p>n) break;
        if(n%p==0)
        {
            while(n%p==0)
            {
                factors.push_back(p);
                n=n/p;
            }
        }
    }
    if(n>1) factors.push_back(n);
    return factors;

}
