/*
 * @Date         : 2021-08-02 21:52:21
 * @Author       : ssyze
 * @Description  : 
 */
#include<bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#define dbg(x...) do { cout << "\033[32;1m " << #x << " -> "; err(x); } while (0) 
void err() { cout << "\033[39;0m" << endl; }
template<template<typename...> class T, typename t, typename... A>
void err(T<t> a, A... x) { for (auto v: a) cout << v << ' '; err(x...); }
template<typename T, typename... A>
void err(T a, A... x) { cout << a << ' '; err(x...); }
#else
#define dbg(...)
#endif
typedef long long ll;
typedef pair<int,int> pi;
typedef vector<int> vi;
template<class T> using vc=vector<T>;
template<class T> using vvc=vc<vc<T>>;
template<class T> void mkuni(vector<T>&v)
{
    sort(v.begin(),v.end());
    v.erase(unique(v.begin(),v.end()),v.end());
}
ll rand_int(ll l, ll r)
{
    static mt19937_64 gen(chrono::steady_clock::now().time_since_epoch().count());
    return uniform_int_distribution<ll>(l, r)(gen);
}
template<class T>
void print(T x,int suc=1)
{
    cout<<x;
    if(suc==1) cout<<'\n';
    else cout<<' ';
}
template<class T>
void print(const vector<T>&v,int suc=1)
{
    for(int i=0;i<v.size();i++)
    print(v[i],i==(int)(v.size())-1?suc:2);
}

const int maxn = 2e5 + 5;
ll t, n, a[maxn], dif[maxn];
ll stgcd[maxn][20],mn[maxn];

void init(){
    mn[0]=-1;
    for(int i=1;i<=n;i++){
        mn[i]=((i&(i-1))==0)?mn[i-1]+1:mn[i-1];
        stgcd[i][0]=dif[i];
    }
    for(int j=1;j<=mn[n];j++)
        for(int i=1;i+(1<<j)-1<=n;i++){
            stgcd[i][j]=__gcd(stgcd[i][j-1],stgcd[i+(1<<(j-1))][j-1]);
        }
}

int qry(int left,int right){
    int k=mn[right-left+1];
    return __gcd(stgcd[left][k],stgcd[right-(1<<k)+1][k]);
}

bool check(int x)
{
    for (int i = 1; i + x - 1 <= n; i++) {
        if (qry(i,i+x-1) != 1) return 1;
    }
    return 0;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        if (n == 1) {
            cout << 1 << '\n';
            continue;
        }
        n--;
        for (int i = 1; i <= n; i++) 
            dif[i] = abs(a[i] - a[i + 1]);
        init();
        int l = 2, r = n, ans = -1;
        while (l <= r) {
            int mid = l + r >> 1;
            if (check(mid)) {
                l = mid + 1;
                ans = mid;
            }
            else r = mid - 1;
        }
        n++;
        if (ans != -1) cout << ans + 1 << '\n';
        else {
            bool ok = 0;
            for (int i = 1; i < n; i++) {
                if (dif[i] != 1) ok = 1;
            }
            if (ok) cout << 2 << '\n';
            else cout << 1 << '\n';
        }
    }
}