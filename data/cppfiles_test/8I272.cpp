#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

#define w(x) int x; cin >> x; while (x--)
#define ll long long int
#define fo(i, k, n, x, type) for (type i = k; k < n ? i < n : i > n; k < n ? i += x : i -= x)
#define deb(x) cout << #x << "=" << x << endl
#define setbits(x) __builtin_popcountll(x)
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define mk(arr, n, type) type *arr = new type[n]
#define ios ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

typedef map<int, int> mii;
typedef unordered_map<int, int> umii;
typedef multimap<int, int> mmi;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;
typedef vector<pii> vpii;
typedef set<int> si;
typedef unordered_set<int> usi;
typedef multiset<int> msi;
typedef set<pii> spii;
typedef priority_queue<int> pqi;
typedef deque<int> dq;

const int mod = 1e9 + 7;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

int main()
{
    ios;

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    w(t)
    {
        int n;
        cin>>n;

        if(n%3==0)
            cout<<n/3<<" "<<n/3<<endl;
        else 
            cout<<n/3<<" "<<(n/3)+1<<endl;
    }
    return 0;
}