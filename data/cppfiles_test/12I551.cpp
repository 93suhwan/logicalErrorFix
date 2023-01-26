#include <fstream>
#include <iostream>
#include <locale>
#include <stdlib.h>
#include <set>
#include <list>
//#include <tuple>
//#include <unordered_set>
//#include <unordered_map>
#include <vector>
#include <map>
#include <deque>
#include <queue>
#include <stack>
#include <math.h>
#include <stdio.h>
#include <sstream>
#include <conio.h>
#include <stdlib.h>
#include <cstdarg>
#include <ctime>

#define ll long long int
#define contains(st, el) (st.find(el) != st.end())
#define pcontains(st, el) (st->find(el) != st->end())
#define ncontains(st, el) (st.find(el) == st.end())
#define pncontains(st, el) (st->find(el) == st->end())

#define vct vector

#define MOD 1000000007l
#define MOD2 998244353l
#define MOD3 100000000l

#define nullptr 0

using namespace std;
template<class T>
T sgn(T x){
    if(x<0)
        return -1;
    else if(x)
         return 1;
    else return 0;
}

template<class T>
int cmp(const void* a, const void* b) {
    return sgn<T>(*((T*)a) - *((T*)b));
}
template<class T>
int rcmp(const void* a, const void* b) {
    return sgn<T>(*((T*)b) - *((T*)a));
}
int p_rcmp(const void* a, const void* b) {
    return (*((pair<int, int>*)b)).first - (*((pair<int, int>*)a)).first;
}
template<class T>
int p_cmp(const void* a, const void* b) {
    return (*((pair<T, T>*)a)).first - (*((pair<T, T>*)b)).first;
}
template<class T>
int p_cmp_dbl(const void* a, const void* b) {
    pair<T, T> left  = *((pair<T, T>*)a);
    pair<T, T> right = *((pair<T, T>*)b);
    if(left.first != right.first)
         return left.first  -  right.first;
    else return left.second - right.second;
}

template<class T>
int dblp_cmp(const void* a, const void* b) {
    return (*((pair<T, pair<T, T> >*)a)).first - (*((pair<T, pair<T, T> >*)b)).first;
}
ll min(ll a, ll b) {
    return (a < b) ? a : b;
}
ll max(ll a, ll b) {
    return (a > b) ? a : b;
}
int min(int a, int b) {
    return (a < b) ? a : b;
}
int max(int a, int b) {
    return (a > b) ? a : b;
}
void swap(ll& a, ll& b) {
    a ^= b; b ^= a; a ^= b;
}
void make_bond(int a, int b, list<int>* edges) {
    edges[a].push_back(b);
    edges[b].push_back(a);
}
void make_bond(int a, int b, set<int>* edges) {
    edges[a].insert(b);
    edges[b].insert(a);
}
void make_bond(char a, char b, set<char>* edges) {
    edges[a].insert(b);
    edges[b].insert(a);
}
ll gcd_(ll a, ll b) {
    return b ? gcd_(b, a % b) : a;
}
int gcd_(int a, int b) {
    return b ? gcd_(b, a % b) : a;
}
int abs_(int x) {
    return ((x < 0) ? (-x) : x);
}
ll abs_(ll x) {
    return ((x < 0) ? (-x) : x);
}
double abs_(double x){
    return ((x < 0) ? (-x) : x);
}
ll pwr(ll base, ll p, ll mod){
    ll res = 1;
    while(p-- > 0)
        res = (res*base)%mod;
    return res;
}
ll pwr_bin(ll base, ll p, ll mod){
    ll pwrs_[64] = {base};
    for(int i=1;i<64;i++)
        pwrs_[i]=(pwrs_[i-1]*pwrs_[i-1])%mod;
    ll res = 1, i=0;
    while(p>0){
        if(p%2 == 1)
            res = (res*pwrs_[i])%mod;
        p /= 2;
        i++;
    }
    return res;
}
ll lcm(ll a, ll b){
    return a*b/gcd_(a,b);
}
int sgn(int x){
    if(x<0)return -1;
    else return 1;
}
ll nat_sum(ll x){
    return x*(x+1)/2;
}
ll nat_sum_from_to(ll a, ll b){
    return nat_sum(b)-nat_sum(a-1);
}
ll get_rev_by_mod(ll a, ll x, ll mod){
    if(a%x == 0)
        return a/x;
    ll new_mod = x;
    ll new_x = mod%x;
    ll new_a = (x-(a%x))%x;
    ll new_res = (a+mod*get_rev_by_mod(new_a,new_x,new_mod))/x;
    return new_res;
}

ll A(ll n, ll m, ll mod){
    ll res = 1;
    for(ll i=n;i>m;i--)
        res = (res*i)%mod;
    return res;
}

ll P(ll n, ll mod){
    return A(n,0,mod);
}

ll C(ll n, ll m, ll mod){
    ll denominator = get_rev_by_mod(1,P(n-m,mod),mod);
    ll numerator   = A(n,m,mod);
    /*
    cout <<"Numerator: " <<numerator <<'\n';
    cout <<"Denominator: " <<denominator <<'\n';
    */
    ll res = (numerator*denominator)%mod;
    return res;
}

ll* sieve;
void init_sieve(ll n){
    sieve = new ll[n+1];
    for(ll i=2;i<=n;i++)
        if(!sieve[i])
        for(ll j=i;j<=n;j+=i)
            sieve[j]=i;
}
ll get_all_divisors_amount(ll x, ll mod){
    ll res = 1;
    while(x != 1){
        ll divisor = sieve[x];
        ll counter = 1;
        while(x%divisor == 0){
            x/=divisor;
            counter++;
        }
        res = (res*counter)%mod;
    }
    return res;
}


int main(){
    ll t=1;
    cin >>t;
    while(t-- > 0){
        int n, m, k;
        scanf("%d%d%d",&n,&m,&k);
        bool res = false;
        if(n%2==1){
            k -= m/2;
            if(k >= 0 && k%2 == 0)
                res = true;
        }
        else if(k >= 0 && k%2 == 0)
            res = true;
        printf(res?"YES\n":"NO\n");
    }
    return 0;
}
