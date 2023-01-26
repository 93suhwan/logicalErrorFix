#include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#define dbg(x...) do { cout << #x << " -> "; err(x); } while (0)
void err() { cout << endl; }
template<template<typename...> class T, typename t, typename... A>
void err(T<t> a, A... x) { for (auto v: a) cout << v << ' '; err(x...); }
template<typename T, typename... A>
void err(T a, A... x) { cout << a << ' '; err(x...); }
#define Tst clock_t z=clock()
#define Tend printf("Total Time: %.3f\n", (double)(clock() - z) / CLOCKS_PER_SEC)
#else
#define dbg(...)
#define Tst
#define Tend
#endif
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
mt19937 mrand(random_device{}());
int rnd(int x) { return mrand() % x;}
const int maxn=1e6+7,inf=0x3f3f3f3f,mod=1e9+7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int kase;
    cin>>kase;
    while(kase--) {
        int n,m;
        cin>>n>>m;
        vector a(n,vector<int>(m));
        for(auto &row:a) for(auto &it:row) cin>>it;
        vector premn(a),premx(a),sufmn(a),sufmx(a);
        for(int i=0;i<n;++i) {
            for(int j=1;j<m;++j) {
                premn[i][j]=min(premn[i][j],premn[i][j-1]);
                premx[i][j]=max(premx[i][j],premx[i][j-1]);
            }
            for(int j=m-2;j>=0;--j) {
                sufmn[i][j]=min(sufmn[i][j],sufmn[i][j+1]);
                sufmx[i][j]=max(sufmx[i][j],sufmx[i][j+1]);
            }
        }
        bool ok=0;
        for(int k=0;k<m-1;++k) {
            vi p(n);
            iota(p.begin(),p.end(),0);
            sort(p.begin(),p.end(),[&](int x,int y) {
                return premx[x][k]<premx[y][k];
            });
            vi ppremx(n),psufmn(n),spremn(n),ssufmx(n);
            for(int i=0;i<n;++i) {
                ppremx[i]=premx[p[i]][k];
                if(i) ppremx[i]=max(ppremx[i-1],ppremx[i]);
                psufmn[i]=sufmn[p[i]][k+1];
                if(i) psufmn[i]=min(psufmn[i-1],psufmn[i]);
            }
            for(int i=n-1;i>=0;--i) {
                spremn[i]=premn[p[i]][k];
                if(i<n-1) spremn[i]=min(spremn[i+1],spremn[i]);
                ssufmx[i]=sufmx[p[i]][k+1];
                if(i<n-1) ssufmx[i]=max(ssufmx[i-1],ssufmx[i]);
            }
            for(int i=0;i<n-1;++i) {
                if(ppremx[i]<spremn[i] && ssufmx[i]<psufmn[i]) {
                    cout<<"YES\n";
                    string S(n,'R');
                    for(int j=0;j<=i;++j) S[p[j]]='B';
                    cout<<S<<" "<<k+1<<'\n';
                    ok=1;
                    break;
                }
            }
            if(ok) break;
        }
        if(!ok) cout<<"NO\n";
    }
    return 0;
}