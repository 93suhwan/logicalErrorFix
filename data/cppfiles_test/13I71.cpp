/***
**   AUTHOR::ASHUTOSH MOUDGIL
***/

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define pb push_back
#define mp make_pair
#define IOS                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
#define F first
#define S second
#define int long long
//#define ll long long
#define all(x) x.begin(), x.end()
#define rsort(x)  \
    sort(all(x)); \
    reverse(all(x));
#define endl '\n'
#define vi vector<int>
#define pii pair<int, int>
#define piii pair<int, pair<int, int>>
#define mod 1000000007
#define deb(x) cout << #x << " : " << x << endl;
#define PI 3.141592654
#define deb1(x) cout << #x << "=" << x << endl;
#define deb2(x, y) cout << #x << "=" << x << ", " << #y << "=" << y << endl;
#define deb3(x, y, z) cout << #x << "=" << x << ", " << #y << "=" << y << ", " << #z << "=" << z << endl;
#define deb4(x, y, z, a) cout << #x << "=" << x << ", " << #y << "=" << y << ", " << #z << "=" << z << ", " << #a << "=" << a << endl;
#define debarr(x)               \
    cout << #x << "::" << endl; \
    for (int i : x)             \
    {                           \
        cout << i << " ";       \
    }                           \
    cout << endl;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

inline int add(int a, int b)
{
    a = (a + b);
    if (a >= mod)
        a -= mod;
    return a;
}
inline int sub(int a, int b)
{
    a = a - b;
    if (a < 0)
        a += mod;
    return a;
}
inline int mul(int a, int b)
{
    a = (a * b) % mod;
    return a;
}
inline int power(int x, int y)
{
    int res = 1, temp = x;
    while (y > 0)
    {
        if (y & 1)
            res *= temp;
        temp *= temp; 
        y /= 2;
    }
    return res;
}
inline int power(int x, int y, int m)
{
    if (y == 0)
        return 1;
    int p = power(x, y / 2, m) % m;
    p = (p * p) % m;
    return (y % 2 == 0) ? p : (x * p) % m;
}

void mymain(){
    int n,m,k;
    cin >> n >> m >> k;
    int h = 0, v = 0;
    vector<vector<char>> arr(n,vector<char>(m,'0'));
    if(n%2){
        h = m/2;
        char x = 'a';
        for(int j=0;j<m;j+=2){
            arr[n-1][j] = x;
            arr[n-1][j+1] = x;
            if(x == 'a') x= 'b';
            else x = 'a';
        }
        n--;
    }else if(m%2){
        v = n/2;
        char x = 'a';
        for(int i=0;i<n;i+=2){
            arr[i][m-1] = x;
            arr[i+1][m-1] = x;
            if(x == 'a') x= 'b';
            else x = 'a';
        }
        m--;
    }
    int sq = (n*m)/4;
    if(k < h || (k-h)&1 || (k-h) > 2*sq){
        cout << "NO" << endl;
        return;
    }

    k -= h;
    h = k;
    v = 2*sq - h;
    vector<vector<char>> hh = {{'c', 'd'},{'g', 'h'}}, vv = {{'e', 'f'},{'i', 'j'}};
    int idx = 0;
    for(int i=0;i<n;i+=2){
        for(int j=0;j<m;j+=2){
            if(h > 0){
                arr[i][j] = hh[idx][0];
                arr[i][j+1] = hh[idx][0];
                arr[i+1][j] = hh[idx][1];
                arr[i+1][j+1] = hh[idx][1];
                swap(hh[0],hh[1]);
                h-=2;
            }else{
                arr[i][j] = vv[idx][0];
                arr[i+1][j] = vv[idx][0];
                arr[i][j+1] = vv[idx][1];
                arr[i+1][j+1] = vv[idx][1];
                swap(vv[0],vv[1]);
                v-=2;
            }
        }
        idx ^= 1;
    }

    cout << "YES" << endl;
    for(int i=0;i<arr.size();i++){
        for(int j=0;j<arr[0].size();j++){
            cout << arr[i][j];
        }
        cout << endl;
    }
}   

signed main()
{
    IOS;
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int t = 1;
    cin >> t;

    for (int tt = 0; tt < t; tt++)
    {
        // cout << "Case #" << tt+1 <<": " ;
        mymain();
    }

    return 0;
}
/*

*/