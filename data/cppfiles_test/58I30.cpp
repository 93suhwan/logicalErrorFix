#include <bits/stdc++.h>
#include<ext/rope>
using  namespace __gnu_cxx;

//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>

//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")
//#pragma GCC optimize("-O3")

#define F first
#define S second
#define PB push_back
#define M ll(998244353)
#define N 200500
#define pri(x) cout << x << endl
#define sz(x) int(x.size())
//#define endl '\n'
#define _ << " " <<
#define pri(x) cout << x << endl
#define all(x) x.begin(), x.end()

using namespace std;

//using namespace __gnu_pbds;
typedef long long ll;
//typedef tree <ll, null_type, less <ll> , rb_tree_tag, tree_order_statistics_node_update> ordered_set;

typedef double ld;
typedef short int si;
typedef unsigned long long ull;

int mlt(int x, int y)
{
    return 1ll * x * y % M;
}

int binpow(int x, int y)
{
    if (y == 0)
        return 1;

    int s = binpow(x, y >> 1);

    s = mlt(s, s);

    if (y & 1)
        s = mlt(s, x);

    return s;
}

int fact[N + N], mk[N], id;

int C(int n, int k)
{
    return mlt(fact[n], binpow(mlt(fact[n - k], fact[k]), M - 2));
}

struct node
{
    node *l, *r;

    int k, y;

    node(): l(nullptr), r(nullptr), k(0) {}

    node(int _k, int _y): l(nullptr), r(nullptr), k(_k), y(_y) {}
};

typedef node *item;

int kol(item v)
{
    return v ? v->k : 0;
}

void upd(item &v)
{
    v->k = 1 + kol(v->l) + kol(v->r);
}

void merge(item &v, item l, item r)
{
    if (!l)
        v = r;
        else
    if (!r)
        v = l;
        else
        {
            if (l->y > r->y)
            {
                v ->l = l->l;

                merge(v->r, l->r, r);
            }
            else
            {
                v ->r = r->r;

                merge(v->l, l, r->l);
            }
        }

    upd(v);
}

void split(item v, item &l, item &r, int key, int dob)
{
    if (!v)
        {
            l = r = nullptr;

            return;
        }

    int cur_key = dob + kol(v->l);

    if (key <= cur_key)
    {
        split(v->l, l, v->l, key, dob);

        r = v;
    }
    else
    {
        split(v->r, v->r, r, key, cur_key + 1);

        l = v;
    }

    upd(v);
}

void inser(item &v, int key, item db)
{
    if (!v)
        v = db;
    else if (v->y > db->y)
    {
        int sk = kol(v->l);

        if (key <= sk)
        {
            inser(v->l, key, db);
        }
        else
        {
            inser(v->r, key - sk, db);
        }
    }
    else
    {
        split(v, db->l, db->r, key, 0);

        v = db;
    }

    upd(v);
}

void eras(item &v, int key)
{
    if (key == v->k)
    {
        merge(v, v->l, v->r);
    }
    else
    {
        int sk = kol(v->l);

        if (key <= sk)
            eras(v->l, key);
        else
        {
            key -= sk;

            eras(v->r, key);
        }
    }

    upd(v);
}

item fnd(item &v, int key, int dob)
{
    if (v->k + dob == key)
        return v;

    int cur_key = dob + kol(v->l);

    if (cur_key >= key)
        return fnd(v->l, key, dob);
            else
            {
                return fnd(v->r, key, cur_key);
            }
}

unordered_map <int, int> mp;

mt19937 rnd(228);

item root;

int main()
{
	ios_base::sync_with_stdio(0); istream::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//	freopen("1.in", "r", stdin);
//	out("mantan.out");

    fact[0] = 1;

    for (int i = 1; i < N + N; i++)
        fact[i] = mlt(fact[i - 1], i);

    int q;

    cin >> q;

    rope <int> r1(N, 0), r2(N, 0);

    while(q--)
    {
        int n, m;

        cin >> n >> m;

        int c = 0;

        r1 = r2;

        while(m--)
        {
            int x, y;

            cin >> x >> y;

            if(!r1[y - 1]) c++;

            r1.replace(y - 1, 1, 1);
        }

        pri(C(n + n - c - 1, n));
    }
}
