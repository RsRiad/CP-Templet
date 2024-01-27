#include <bits/stdc++.h>
using namespace std;
//PBDS
#include<ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

typedef tree<long long , null_type, less<long long>, rb_tree_tag,tree_order_statistics_node_update> ordered_set;

#define order(s, x) s.order_of_key(x) // return the number of elements in the set that are smaller than x
#define elemat(s ,x) s.find_by_order(x) // return pointer to element at index x
// Macros
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define ll long long
#define fl(i,n) for(int i=0;i<n;i++)
#define rl(i,m,n) for(int i=n;i>=m;i--)
#define yes cout<<"YES\n";
#define endl "\n"
#define pm cout<<"-1\n";
#define no cout<<"NO\n";
#define all(v) v.begin(),v.end()
#define allr(v) v.end(),v.begin()
#define unq(x) x.erase(unique(x.begin(),x.end()),x.end())
#define mem(a,b) memset(a, b, sizeof(a) )
#define fraction() cout.unsetf(ios::floatfield); cout.precision(10); cout.setf(ios::fixed,ios::floatfield);
#define file() freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#define RIAD ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
//Debug
#define dbg(args...) do {cerr << #args << " : "; faltu(args); } while(0)
void faltu () {            cerr << endl;}
template < typename T, typename ... hello>void faltu( T arg, const hello &... rest) {cerr << arg << ' ';faltu(rest...);}

//Constants
const double PI = acos(-1);
const double eps = 1e-9;
const ll INF= LONG_LONG_MAX;
const ll MOD=1e9+7;

//TypeDEf
typedef pair<ll, ll> pll;
typedef vector<ll> vll;
typedef vector<pll> vpll;
typedef vector<string> vs;
typedef unordered_map<ll,ll> umll;
typedef map<ll,ll> mll;

// Operator overloads
template<typename T1, typename T2> // cin >> pair<T1, T2>
istream& operator>>(istream &istream, pair<T1, T2> &p) { return (istream >> p.first >> p.second); }
template<typename T> // cin >> vector<T>
istream& operator>>(istream &istream, vector<T> &v){for (auto &it : v)cin >> it;return istream;}
template<typename T1, typename T2> // cout << pair<T1, T2>
ostream& operator<<(ostream &ostream, const pair<T1, T2> &p) { return (ostream << p.first << " " << p.second); }
template<typename T> // cout << vector<T>
ostream& operator<<(ostream &ostream, const vector<T> &c) { for (auto &it : c) cout << it << " "; return ostream; }
//sort vector of pair 2nd element
template <class T1, class T2, class Pred = std::less<T2> >struct sort_pair_second {bool operator()(const std::pair<T1,T2>&left, const std::pair<T1,T2>&right) {Pred p;return p(left.second, right.second);}};

// Utility functions
template <typename T>
void print(T &&t)  { cout << t << "\n"; }
void printarr(ll arr[], ll n){fl(i,n) cout << arr[i] << " ";cout << "\n";}
template<typename T>
void printvec(vector<T>v){ll n=v.size();fl(i,n)cout<<v[i]<<" ";cout<<"\n";}
template<typename T>
ll sumvec(vector<T>v){ll n=v.size();ll s=0;fl(i,n)s+=v[i];return s;}
vector<ll> prefixSum(const vector<ll>& nums){ll n = nums.size()+1;vector<ll> prefix(n, 0);if (n == 0)return prefix;prefix[0] = 0;for (int i = 1; i < n; ++i){prefix[i] = prefix[i - 1] + nums[i-1];}return prefix;}

// Mathematical functions
ll gcd(ll a, ll b){if (b == 0)return a;return gcd(b, a % b);} //__gcd
ll lcm(ll a, ll b){return (a/gcd(a,b)*b);}
ll moduloMultiplication(ll a,ll b,ll MOD){ll res = 0;a %= MOD;while (b){if (b & 1)res = (res + a) % MOD;b >>= 1;}return res;}
ll powermod(ll x, ll y, ll p){ll res = 1;x = x % p;if (x == 0) return 0;while (y > 0){if (y & 1)res = (res*x) % p;y = y>>1;x = (x*x) % p;}return res;}
inline bool isLeapYear(ll year) { return (year%400==0) or (year%4==0 && year%100!=0); }
inline void normal(ll &a) { a %= MOD; (a < 0) && (a += MOD); }
inline ll modMul(ll a, ll b) { a %= MOD, b %= MOD; normal(a), normal(b); return (a*b)%MOD; }
inline ll modAdd(ll a, ll b) { a %= MOD, b %= MOD; normal(a), normal(b); return (a+b)%MOD; }
inline ll modSub(ll a, ll b) { a %= MOD, b %= MOD; normal(a), normal(b); a -= b; normal(a); return a; }
inline ll modPow(ll b, ll p) { ll r = 1; while(p) { if(p&1) r = modMul(r, b); b = modMul(b, b); p >>= 1; } return r; }
inline ll modInverse(ll a) { return modPow(a, MOD-2); }
inline ll modDiv(ll a, ll b) { return modMul(a, modInverse(b)); }
//Sorting
bool sorta(const pair<int,int> &a,const pair<int,int> &b){return (a.second < b.second);}
bool sortd(const pair<int,int> &a,const pair<int,int> &b){return (a.second > b.second);}

//Bits
string decToBinary(int n){string s="";int i = 0;while (n > 0) {s =to_string(n % 2)+s;n = n / 2;i++;}return s;}
ll binaryToDecimal(string n){string num = n;ll dec_value = 0;int base = 1;int len = num.length();for(int i = len - 1; i >= 0; i--){if (num[i] == '1')dec_value += base;base = base * 2;}return dec_value;}

//Check
bool isPrime(ll n){if(n<=1)return false;if(n<=3)return true;if(n%2==0 or n%3==0)return false;for(int i=5;i*i<=n;i=i+6)if(n%i==0 or n%(i+2)==0)return false;return true;}
bool isPowerOfTwo(int n){if(n==0)return false;return (ceil(log2(n)) == floor(log2(n)));}
bool isPerfectSquare(ll x){if (x >= 0) {ll sr = sqrt(x);return (sr * sr == x);}return false;}
bool isPalindrome(string& str, int start = 0){int end = str.length() - 1 - start;if(start >= end){return true;}if(str[start] != str[end]) {return false;}return isPalindrome(str, start + 1);}


/**============================START============================**/

const int lim=200005;
vector<int>adj[lim];
bool visit[lim];

//Code
void solve()
{
    ll n;
    cin>>n;
    


}
//Main
int main()
{
    #ifndef ONLINE_JUDGE
    file()
    #endif
    RIAD
    ll t=1;
    cin>>t;
    fl(i,t)
    {
        solve();
    }
    return 0;
}
//End
