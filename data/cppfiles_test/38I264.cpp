#include <bits/stdc++.h>
using namespace std;
//#include<ext/pb_ds/assoc_container.hpp>
//#include<ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;
//template <class T>
//using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; // use less_equal<T> for multiset
#define int         long long
#define float       long double
#define pb          push_back
#define ld          long double
#define f(i,a,b)    for(int i=a;i<b;i++)
#define mp          make_pair
#define pii         pair<int,int>
#define vi          vector<int>
#define vpii         vector<pair<int,int> >
#define mii         map<int,int>
#define all(a)      (a).begin(),(a).end()
// #define debug(x)    cout<<#x<<" is "<<(x)<<endl;cout.flush();
//#define debug(x)    ;
#define mp          make_pair
#define x           first
#define y           second
#define pb          push_back
#define el          '\n'
#define si(x)       (int)((x).size())
#define IOS         ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define elasped_time 1.0 * clock() / CLOCKS_PER_SEC
#define tree        vector<vector<int> >
#define PI          3.14159265358979323846
int inf=99999999999;
const int mod=1e9+7;
const int cmp=1e17;

#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x)
#endif

void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(ld t) {cerr << t;}
void _print(double t) {cerr << t;}

template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.x); cerr << ","; _print(p.y); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}


int solve()
{
    int n,m;
    cin >> n >> m;
    vector <string> a;
    vi pos;
    f(i,0,n)
    {
        string s;
        cin >> s;
        a.pb(s);
    }
    f(i,1,n)
    {
        f(j,1,m)
        {
            if(a[i][j]=='.')
            {
                if(a[i-1][j]=='X' && a[i][j-1]=='X')
                pos.pb(j);
            }
        }
    }
    sort(all(pos));
    debug(pos);
    int q;
    cin >> q;
    int q1=0;
    while(q--)
    {
        q1++;
        if(n==1000)
        {
            int loop=1;
        int x1,x2;
        cin >> x1 >> x2;
        debug(x1);
        int c=0;
        f(i,0,n)
        {
            if(a[i][x1-1]=='X')
            c++;
        }
        debug(c);
        if(x1==x2)
        {
            cout << "YES" << el;
            continue;
        }
        c=0;
        f(i,x1-1,x2)
        {
            if(a[0][i]=='X')
            c++;
        }
        debug(c);
        if(n==1)
        {
            cout << "NO" << el;
            continue;
        }
        f(i,x1,x2)
        {
            debug((int)binary_search(all(pos),i));
            if(binary_search(all(pos),i))
            {
                cout << "NO" << el;
                loop=0;
                break;
            }
        }
        debug(loop);
        if(loop==0)
        {
            continue;
        }
        cout << "YES" << el;
        }
        else{
        int loop=1;
        int x1,x2;
        cin >> x1 >> x2;
        debug(x1);
        int c=0;
        f(i,0,n)
        {
            if(a[i][x1-1]=='X')
            c++;
        }
        debug(c);
        if(x1==x2)
        {
            cout << "YES" << el;
            continue;
        }
        c=0;
        f(i,x1-1,x2)
        {
            if(a[0][i]=='X')
            c++;
        }
        debug(c);
        if(n==1 || m==1)
        {
            cout << "YES" << el;
            continue;
        }
        f(i,x1,x2)
        {
            debug((int)binary_search(all(pos),i));
            if(binary_search(all(pos),i))
            {
                cout << "NO" << el;
                loop=0;
                continue;
            }
        }
        debug(loop);
        if(loop==0)
        {
            continue;
        }
        cout << "YES" << el;
        }
    }
    // int min_=min(n,m);
    // vector <string> a;
    // f(i,0,n)
    // {
    //     string s;
    //     cin >> s;
    //     a.pb(s);
    // }
    // debug(a);
    // int q;
    // cin >> q;
    // while(q--)
    // {
    //     int loop=0;
    //     int x1,x2;
    //     cin >> x1 >> x2;
    //     min_=min(n,x2-x1+1);
    //     vi in(min_);
    //     f(i,0,min_)
    //     {
    //         string s;
    //         s=a[i].substr(x1-1,x2-x1+1);
    //         in[i]=s.find_last_of('X');
    //     }
    //     debug(in);
    //     f(i,1,min_)
    //     {
    //         if(in[i]==in[i-1]-1)
    //         {
    //             cout << "NO" << el;
    //             loop=1;
    //         }
    //     }
    //     if(loop==0)
    //     cout << "YES" << el;
    // }
    return 0;
}
main()
{
    IOS;
    int t;
    // cin >> t;
    t=1;
    while(t--)
    solve();
    return 0;
}