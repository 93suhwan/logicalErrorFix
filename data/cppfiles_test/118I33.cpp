#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
 
typedef long long ll;
typedef unsigned long long ull;
typedef vector<ll> vl;
typedef pair<ll,ll> pll;
typedef vector<pll> vp;
typedef long long db;
#define INF 1e9
#define EPS 1e-7
#define ALL(x) x.begin() , x.end()
#define ALLR(x) x.rbegin() , x.rend()
#define UNIQUE(c) (c).resize(unique(ALL(c)) - (c).begin())
#define PI acos(-1.0)


ll M = 998244353;

#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define repx(i, a, b) for (int i = (int)a; i < (int)b; i++)

#define M_PIl 3.141592653589793238462643383279502884L

typedef complex<double> C;
typedef vector<long double> vd;

void fft(vector<C> &a)
{
    int n = a.size(), L = 31 - __builtin_clz(n);
    static vector<complex<long double>> R(2, 1);
    static vector<C> rt(2, 1);
    for (static int k = 2; k < n; k *= 2)
    {
        R.resize(n);
        rt.resize(n);
        auto x = polar(1.0L, M_PIl / k);
        repx(i, k, 2 * k) rt[i] = R[i] = i & 1 ? R[i / 2] * x : R[i / 2];
    }
    vector<int> rev(n);
    rep(i, n) rev[i] = (rev[i / 2] | (i & 1) << L) / 2;
    rep(i, n) if (i < rev[i]) swap(a[i], a[rev[i]]);
    for (int k = 1; k < n; k *= 2) for (int i = 0; i < n; i += 2 * k) rep(j, k)
    {
        auto x = (double *)&rt[j + k], y = (double *)&a[i + j + k];
        C z(x[0] * y[0] - x[1] * y[1], x[0] * y[1] + x[1] * y[0]);
        a[i + j + k] = a[i + j] - z;
        a[i + j] += z;
    }
}

vl conv(const vl &a, const vl &b, int M)
{
    if (a.empty() || b.empty()) return {};
    vl res(a.size() + b.size() - 1);
    int B = 32 - __builtin_clz(res.size()), n = 1 << B, cut = int(sqrt(M));
    vector<C> L(n), R(n), outs(n), outl(n);
    rep(i, a.size()) L[i] = C((int)a[i] / cut, (int)a[i] % cut);
    rep(i, b.size()) R[i] = C((int)b[i] / cut, (int)b[i] % cut);
    fft(L), fft(R);
    rep(i, n)
    {
        int j = -i & (n - 1);
        outl[j] = (L[i] + conj(L[j])) * R[i] / (2.0 * n);
        outs[j] = (L[i] - conj(L[j])) * R[i] / (2.0 * n) / 1i;
    }
    fft(outl), fft(outs);
    rep(i, res.size())
    {
        ll av = ll(real(outl[i]) + .5), cv = ll(imag(outs[i]) + .5);
        ll bv = ll(imag(outl[i]) + .5) + ll(real(outs[i]) + .5);
        res[i] = ((av % M * cut + bv) % M * cut + cv) % M;
    }
    return res;
}


ll n;
vl ch;
vector<vl> g;

const ll MAXN = 250000;
ll F[MAXN];
// ...

vl build(ll l, ll r)
{
    if(l==r)
    {
        vl aux;
        aux.push_back(1);
        aux.push_back(ch[l]);
        return aux;
    }

    vl v1 = build(l,(l+r)/2);
    vl v2 = build((l+r)/2+1,r);

    vl res = conv(v1, v2, M);
    

    return res;

}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    F[0] = 1; for(ll i = 1; i < MAXN; i++) F[i] = F[i-1]*i %M;



    cin >> n;
    ch.assign(n, 0);
    g.assign(n, vl());
    for(int i = 0; i < n-1; i++)
    {
        ll x, y;
        cin >> x >> y;
        g[x-1].push_back(y-1);
        g[y-1].push_back(x-1);
    }
    ch[0] = g[0].size();
    for(ll i = 1; i < n; i++)
    {
        ch[i] = g[i].size()-1;
    }
    vl ans = build(0, n-1);
    ll res = 0;
    for(ll i = 0; i < ans.size(); i++)
    {
        if(i %2 == 0)
        {
            res += (ans[i] * F[n - i])%M;
        }
        else
        {
            res -= (ans[i] * F[n - i])%M;
            res += 2*M;
        }
        res %= M;
    }
    cout << res << "\n";
    

    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
}
