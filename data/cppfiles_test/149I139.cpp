#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

#define ff              first
#define ss              second
#define int             long long
#define pb              push_back
#define mp              make_pair
#define mt              make_tuple
#define pii             pair<int,int>
#define vi              vector<int>
#define mii             map<int,int>
#define pqb             priority_queue<int>
#define pqs             priority_queue<int,vi,greater<int> >
#define setbits(x)      __builtin_popcountll(x)
#define mod             1000000007
#define inf             2e18
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mk(arr,n,type)  type *arr=new type[n];
#define range(a,b)      substr(a,b-a+1)
#define w(x)            int x; cin>>x; while(x--)
#define trace(x)        cerr<<#x<<": "<<x<<" "<<endl;
#define FIO             ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
mt19937                 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

int32_t main()
{
    FIO;
    w(t)
    {
        int n, k, x; cin >> n >> k >> x;
        string temp; cin >> temp;
        string s;
        vi v;

        for (char ch : temp)
            if (ch == 'a')
                s += 'a', v.pb(0);
            else if (s.empty() or ch != s.back())
                s += "*", v.pb(k);
            else
                v.back() += k;
        for(auto it : v)
            cout<<it<<" ";
        cout<<endl;
        cout<<s<<endl;

        n = s.length();

        /*for (int i = 0; i < n; ++i)
            cout << v[i] << ' ';
        cout << '\n';*/

        vi suf(n + 1);
        suf[n] = 1;

        for (int i = n - 1; i >= 0; --i)
            if (s[i] == 'a' or suf[i + 1] >= inf)
                suf[i] = suf[i + 1];
            else if (suf[i + 1] >= inf / (v[i] + 1))
                suf[i] = inf;
            else
                suf[i] = suf[i + 1] * (v[i] + 1);

        for(int i=0; i<=n; i++)
            cout<<suf[i]<<" ";
        cout<<endl;


        // for each *, find the smallest number s.t. total >= x and keep that
        temp = "";

        for (int i = 0; i < n; ++i)
        {
            if (s[i] == 'a')
                temp += "a";

            else if (suf[i + 1] >= x)
                continue;

            else
            {
                while (suf[i + 1] < x)
                    temp += "b", x -= suf[i + 1];
            }
        }

        cout << temp << '\n';
    }
    return 0;
}