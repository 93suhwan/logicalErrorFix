
//Alhamdulillah for everything you gave

#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#include <bits/stdc++.h>
#include <cmath>/*
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/trie_policy.hpp>*/

namespace _template
{
using namespace std;/*
using namespace __gnu_pbds;
template <typename T>  using ordered_set =
   tree<T, null_type, less<T>,
   rb_tree_tag, tree_order_statistics_node_update>; */
typedef long long Long;
#define PB push_back
#define MP make_pair
#define FF first
#define SS second
#define bal pair<int, int>

#define FOR(a, n) for(int i=a;i<n;i++)
#define mm(a, n) memset(a, n, sizeof(a))
#define printCase cout<<"Case "<<i<<": "
#define DIC() ({int a; cin>>a; a;})

template <class A, class B> ostream& operator << (ostream& out, const pair<A, B> &a) {return out<<"("<<a.FF<<", "<<a.SS<<")"; }
template <class A> ostream& operator << (ostream& out, const vector<A> &v) { out<<"[ "; for(int i=0; i<(int)v.size(); i++) { if(i) out<<", "; out<<v[i]; } return out << "]"; }
template <class A> ostream& operator << (ostream&out, const set<A> &s) { out<<"{ "; for(auto i:s) if(i!=*s.rbegin()) cout<<i<<", "; else cout<<i<<" "; return out<<"}";}
#define chka(a) cout<<endl<<"values of:  "<<(#a)<<endl;for(int i=0, n=sizeof(a)/sizeof(a[0]); i<n; i++) cout<<a[i]<<" "; cout<<endl;
#define chk(a) cout<<(#a)<<" = "<<a<<endl;
#define mara cout<<"mara"<<endl;

#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL);

#define MOD 100000007
#define pi 3.141592653589793
} using namespace _template;

void solve()
{
    int n; cin>>n;
    vector<pair<int, int> > vp;
    FOR(0, n)
    {
        int k; cin>>k;
        map<int, int> m;
        FOR(0, k)
        {
            int x; cin>>x;
            m[x]=i;
        }
        int minimumToDhuka=max(m.rbegin()->FF+2-m.rbegin()->SS, 0);
        vp.PB(make_pair(minimumToDhuka, k));

    }
    sort(vp.begin(), vp.end());
    Long mid;
    for(Long l=vp.begin()->FF, r=vp.rbegin()->FF, z=0; z<=30; z++)
    {
        mid=(l+r)/2;
        Long cur=mid;
        int cnt=0;
        for(auto i:vp)
        {
            if(cur<=i.FF)
            {
                break;
            }
            cur+=i.SS;
            cnt++;
        }
        if(cnt==vp.size())
        {
            r=mid-1;
        }
        else
        {
            l=mid+1;
        }
    }
    cout<<mid<<endl;
}
int ETC=1;
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r+", stdin);
    freopen("output.txt", "w+", stdout);
    #endif
// **Bismillahir Rahmanir Rahim ***
    FastIO;

    for(int i=1, t=(ETC?DIC():1); i<=t; i++) //check here if test case is enabled
    {
        solve();
    }
    return 0;
 }
