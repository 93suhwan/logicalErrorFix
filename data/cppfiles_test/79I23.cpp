#include<bits/stdc++.h>
#define ll long long int
#define fab(a,b,i) for(int i=a;i<b;i++)
#define pb push_back
#define db double
#define mp make_pair
//#define endl "\n"
#define f first
#define se second
#define all(x) x.begin(),x.end()
#define vll vector<ll>
#define vi vector<int>
#define pii pair<int,int>
#define pll pair<ll,ll>
#define quick ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

using namespace std;

const int MOD = 1e9 + 7;

ll add(ll x, ll y) {ll res = x + y; return (res >= MOD ? res - MOD : res);}
ll mul(ll x, ll y) {ll res = x * y; return (res >= MOD ? res % MOD : res);}
ll sub(ll x, ll y) {ll res = x - y; return (res < 0 ? res + MOD : res);}
ll power(ll x, ll y) {ll res = 1; x %= MOD; while (y) {if (y & 1)res = mul(res, x); y >>= 1; x = mul(x, x);} return res;}
ll mod_inv(ll x) {return power(x, MOD - 2);}
ll lcm(ll x, ll y) { ll res = x / __gcd(x, y); return (res * y);}
class segtree
{
public:
    vector<int> seg;
    vector<int> a;
    int n;
    int placeHolder;

    segtree(int n, int placeHolder)
    {
        this->n = n;
        a.resize(n);
        seg.resize(2 * n);
        this->placeHolder = placeHolder;
        fill(seg.begin(), seg.end(), placeHolder);
    }
    segtree(vector<int> &v)
    {
        n = v.size();
        a = v;
        placeHolder = -1e9;
        seg.resize(2 * n);
    }

    int merge(int a, int b)
    {
        return min(a, b);
    }

//!-------- CAUTION this Tree works for [l,r) .... mind the open interval on r -------!
    void build( )
    {
        for (int i = 0; i < n; i++)
        {
            seg[i + n] = a[i];
        }
        for ( int i = n - 1; i > 0; i--)
        {
            seg[i] = merge(seg[2 * i] , seg[2 * i + 1]);
        }

    }

    void update( int ind , int val)
    {
        a[ind] = val;
        ind += n;
        seg[ind] = val;

        for ( ; ind > 1; ind >>= 1)
        {
            seg[ind >> 1] = merge(seg[ind] , seg[ind ^ 1]);
        }
    }
//!-------- CAUTION this function works for [l,r) .... mind the open interval on r -------!
    int query(int l, int r)
    {
        l += n;
        r += n;
        int ans = placeHolder;
        while (l < r)
        {
            if (l % 2)
            {
                ans = merge(ans, seg[l]);
                l++;
            }
            if (r % 2)
            {
                --r;
                ans =  merge(ans, seg[r]);
            }
            l >>= 1;
            r >>= 1;
        }
        return ans;

    }

};




int main()
{
    quick;
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    fab(0, n, i)
    {
        cin >> a[i];
    }

    fab(0, n, i)
    {
        cin >> b[i];
    }


    auto bfs = [&]()->vector<int> {

        queue<int> q;
        set<int> s;
        vector<int> vis(n, -1);
        fab(0, n, i)
        {
            s.insert(i);
        }

        q.push(n - 1);
        vis[n - 1] = n + 1;
        s.erase(n - 1);
        vector<int> parent(n);
        while (!q.empty())
        {

            int sz = q.size();
            for (int yy = 0; yy < sz; yy++)
            {
                auto p = q.front();
                q.pop();
                int up = p - a[p];
                if (up == -1)
                {
                    int curr = p;
                    vector<int> path;
                    while (curr != n - 1)
                    {
                        path.push_back(parent[curr] + 1);
                        curr = vis[curr];
                    }
                    return path;
                }
                auto it = s.lower_bound(up);
                while (it != s.end() and * it < p)
                {
                    int ind = *it;
                    int newPos = ind + b[ind];
                    if (vis[newPos] == -1)
                    {
                        q.push(newPos);
                        vis[newPos] = p;
                        parent[newPos] = ind;
                    }
                    it++;
                    s.erase(ind);


                }
            }

        }


        return {};

    };


    auto moves = bfs();
    if (moves.empty())
    {
        cout << -1 << endl;
    }
    else
    {
        cout << moves.size() + 1 << endl;
        for (int i = moves.size() - 1; i >= 0; i--)
        {
            cout << moves[i] << " ";
        }

        cout << "0" << endl;
    }

    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}