#include <bits/stdc++.h>

#define int long long

using namespace std;

#ifdef LOCAL 
#include "/media/brayand/BrayanD/debugger.h"
#else
#define db(...) false
#define dbl(...) false
#define dbg(...) false
#define dbm(...) false
#define dbs(...) false
#define dbas(...) false
#endif

const int MOD = 998244353;

struct COMBINATORIAL_SET
{
    typedef long long ll;

    ll MOD;

    ll sz;

    vector<ll> _fact, _inum, _ifact, _pw2;

    vector<vector<ll>> _dp, _stirling1, _stirling2, _pascal;

    ll _update_dp_value;
    bool _update_dp_value_flag;

    COMBINATORIAL_SET(ll m)
    {
        init(m);
    }

    void init(ll m)
    {
        MOD = m;
        sz = 1;
        _fact = {1,1};
        _inum = {0,1};
        _ifact = {1,1};
        _pw2 = {1};
        _dp = {{1}};
        _stirling1 = {{1}};
        _stirling2 = {{1}};
        _pascal = {{1}};
        _update_dp_value_flag = false;
        _update_dp_value = 0;
    }

    ll mod(ll x)
    {
        x %= MOD;
        if(x < 0)x += MOD;
        return x;
    }

    ll qpow(ll a, ll b)
    {
        a = mod(a);
        ll res = 1;
        while(b)
        {
            if(b&1)res = res*a%MOD;
            a = a*a%MOD;
            b >>= 1;
        }
        return res;
    }

    ll inv(ll x)
    {
        x = mod(x);
        if(x <= sz)return _inum[x];
        return qpow(x, MOD-2);
    }

    ll fact(int x)
    {
        update(x);
        return _fact[x];
    }

    ll inum(int x)
    {
        update(x);
        return _inum[x];
    }

    ll ifact(int x)
    {
        update(x);
        return _ifact[x];
    }

    void update(int n)
    {
        while(sz < n)
        {
            sz++;
            _fact.push_back(_fact.back()*sz%MOD);
            _inum.push_back((MOD-MOD/sz)*_inum[MOD%sz]%MOD);
            _ifact.push_back(_ifact.back()*_inum.back()%MOD);
        }
    }

    ll summation(ll n, int k)
    {
        if(n <= 0)return 0;
        vector<ll> sum(k+1), sum2(k+1);
        n = (n-1)%MOD;
        sum[0] = n+1;
        for(int i = 1 ; i <= k ; i++)
        {
            for(int j = 0 ; j < i-1 ; j++)
            {
                sum[i] = (sum[i]+(sum2[j]+MOD-sum[j])*comb(i,j))%MOD;
            }
            sum[i] = ((sum[i]+(sum[i-1]*(ll)i%MOD)*n)%MOD)*inum(i+1)%MOD;
            sum2[i-1] = (sum[i-1]*(n+1)+MOD-sum[i])%MOD;
        }
        return sum[k];
    }

    void update_summation(int n, int k, int a = 0, int b = 1)
    {
        a = mod(a), b = mod(b);
        if(!_update_dp_value_flag)
        {
            _update_dp_value_flag = true;
            _update_dp_value = b;
        }
        else
        {
            if(_update_dp_value != b)
            {
                _update_dp_value = b;
                _dp = {{1}};
            }
        }
        int tn = _dp.size(), tk = _dp[0].size();
        n = max(n, tn-1), k = max(k, tk-1);
        while((int)_pw2.size() <= n)
        {
            _pw2.push_back(_pw2.back()*2ll%MOD);
        }
        function<void(int,int)> f = [&](int n, int k)
        {
            _dp[n][k] = _dp[n-1][k];
            ll x = 1;
            ll pw = (b*_pw2[n-1])%MOD;
            for(int i = 0 ; i <= k ; i++)
            {
                _dp[n][k] = (_dp[n][k]+(comb(k,i)*x%MOD)*_dp[n-1][k-i])%MOD;
                x = (x*pw)%MOD;
            }
        };
        if(tk <= k)
        {
            _dp[0].resize(k+1);
            for(int i = 1 ; i < tn ; i++)
            {
                _dp[i].resize(k+1);
                for(int j = tk ; j <= k ; j++)
                {
                    f(i,j);
                }
            }
        }
        for(int i = tn ; i <= n ; i++)
        {
            _dp.emplace_back();
            _dp.back().resize(k+1);
            for(int j = 0 ; j <= k ; j++)
            {
                f(i,j);
            }
        }
    }

    ll summation_dp(ll n, int k, int a = 0, int b = 1)
    {
        //Remember to rebuild the dp when we use "Fn = a + b*n" for different values of "b"
        if(n <= 0)return 0;
        a = mod(a), b = mod(b);
        update_summation(__lg(n), k, a, b);
        ll res = 0, pos = 0;
        for(int j = __lg(n) ; j >= 0 ; j--)
        {
            if(n&(1ll<<j))
            {
                ll x = 1;
                ll pw = (a+b*pos)%MOD;
                for(int i = 0 ; i <= k ; i++)
                {
                    res = (res+(comb(k,i)*x%MOD)*_dp[j][k-i])%MOD;
                    x = (x*pw)%MOD;
                }
                pos = (pos+_pw2[j])%MOD;
            }
        }
        return res;
    }

    ll stirling1(ll n, ll k)
    {
        int k2 = n-k;
        ll res = 0;
        for(int i = 0 ; i <= 2*k2 ; i++)
        {
            int tot = 0;
            for(int j = 0 ; j <= i ; j++)
            {
                if(i-j-k2 < 0)break;
                if(j&1)tot = mod(tot - comb(i,j)*stirling1_dp(i-j,i-j-k2));
                else tot = mod(tot + comb(i,j)*stirling1_dp(i-j,i-j-k2));
            }
            res = mod(res + tot*comb2(n,i));
        }
        return res;
    }

    vector<ll> stirling1_fast(ll n, ll k)
    {
        vector<ll> ans;
        int k2 = n-k;
        if(k2 < 0)return ans;
        vector<ll> dp(k2+1);
        vector<ll> iv(k2+1);
        for(int i = 1 ; i <= k2 ; i++)iv[i] = inum(i);
        dp[0] = 1;
        ll pt = 0;
        for(int i = __lg(n) ; i >= 0 ; i--)
        {
            vector<ll> big(k2+1), pw(k2+1), tmp(k2+1);
            pw[0] = 1;
            for(int j = 1 ; j <= k2 ; j++)pw[j] = (pt%MOD)*pw[j-1]%MOD;

            int sz = min((ll)k2,pt)+1;

            vector<vector<ll>> ncr(sz,vector<ll>(sz));

            for(int j = 0 ; j < sz ; j++)
            {
                ncr[j][0] = 1;
                for(int l = 1 ; l < sz ; l++)
                {
                    ncr[j][l] = (pt-j-l+1)%MOD*ncr[j][l-1]%MOD*iv[l]%MOD;
                }
            }

            for(int j = 0 ; j <= min((ll)k2,pt) ; j++)
            {
                for(int l = 0 ; l <= j ; l++)
                {
                    big[j] = (big[j] + ncr[l][j-l]*pw[j-l]%MOD*dp[l])%MOD;
                }
            }

            for(int j = 0 ; j <= k2 ; j++)
            {
                for(int l = 0 ; l <= j ; l++)
                {
                    tmp[j] = (tmp[j] + dp[l]*big[j-l])%MOD;
                }
            }

            dp = tmp;
            pt *= 2;

            if(n&(1ll<<i))
            {
                tmp.assign(k2+1,0);
                tmp[0] = 1;
                for(int j = 1 ; j <= k2 ; j++)
                {
                    tmp[j] = (dp[j] + (pt%MOD)*dp[j-1])%MOD;
                }
                dp = tmp;
                pt++;
            }
        }
        ans = dp;
        return ans;
    }

    void update_stirling1(int n, int k)
    {
        int tn = _stirling1.size(), tk = _stirling1[0].size();
        n = max(n, tn-1), k = max(k, tk-1);
        function<void(int,int)> f = [&](int n, int k)
        {
            _stirling1[n][k] = (_stirling1[n-1][k-1]+_stirling1[n-1][k]*(n-1))%MOD;
        };
        if(tk <= k)
        {
            _stirling1[0].resize(k+1);
            for(int i = 1 ; i < tn ; i++)
            {
                _stirling1[i].resize(k+1);
                for(int j = tk ; j <= k ; j++)
                {
                    f(i,j);
                }
            }
        }
        for(int i = tn ; i <= n ; i++)
        {
            _stirling1.emplace_back();
            _stirling1.back().resize(k+1);
            for(int j = 1 ; j <= k ; j++)
            {
                f(i,j);
            }
        }
    }

    ll stirling1_dp(int n, int k)
    {
        update_stirling1(n,k);
        return _stirling1[n][k];
    }

    ll stirling2(ll n, int k)
    {
        ll res = 0;
        for(int i = 0 ; i <= k ; i++)
        {
            if(i&1)res = (res + MOD - comb(k,i)*qpow(k-i,n)%MOD)%MOD;
            else res = (res + comb(k,i)*qpow(k-i,n))%MOD;
        }
        return res*ifact(k)%MOD;
    }

    void update_stirling2(int n, int k)
    {
        int tn = _stirling2.size(), tk = _stirling2[0].size();
        n = max(n, tn-1), k = max(k, tk-1);
        function<void(int,int)> f = [&](int n, int k)
        {
            _stirling2[n][k] = (_stirling2[n-1][k-1]+_stirling2[n-1][k]*k)%MOD;
        };
        if(tk <= k)
        {
            _stirling2[0].resize(k+1);
            for(int i = 1 ; i < tn ; i++)
            {
                _stirling2[i].resize(k+1);
                for(int j = tk ; j <= k ; j++)
                {
                    f(i,j);
                }
            }
        }
        for(int i = tn ; i <= n ; i++)
        {
            _stirling2.emplace_back();
            _stirling2.back().resize(k+1);
            for(int j = 1 ; j <= k ; j++)
            {
                f(i,j);
            }
        }
    }

    ll stirling2_dp(int n, int k)
    {
        update_stirling2(n,k);
        return _stirling2[n][k];
    }

    void update_pascal(int n, int k)
    {
        int tn = _pascal.size(), tk = _pascal[0].size();
        n = max(n, tn-1), k = max(k, tk-1);
        function<void(int,int)> f = [&](int n, int k)
        {
            _pascal[n][k] = (_pascal[n-1][k]+_pascal[n-1][k-1])%MOD;
        };
        if(tk <= k)
        {
            _pascal[0].resize(k+1);
            for(int i = 1 ; i < tn ; i++)
            {
                _pascal[i].resize(k+1);
                for(int j = tk ; j <= k ; j++)
                {
                    f(i,j);
                }
            }
        }
        for(int i = tn ; i <= n ; i++)
        {
            _pascal.emplace_back();
            _pascal.back().resize(k+1);
            _pascal.back()[0] = 1;
            for(int j = 1 ; j <= k ; j++)
            {
                f(i,j);
            }
        }
    }

    ll comb_dp(int n, int k)
    {
        update_pascal(n,k);
        return _pascal[n][k];
    }

    ll extended_binomial(ll n, ll x, int k)
    {
        //x != (MOD-1)
        x = mod(x);
        if(x == 0 && k == 0)return 1;
        x = (inv(x)+1ll)%MOD;
        ll val = inv(x), res = 0, pw = 1;
        for(int i = 0 ; i <= k ; i++)
        {
            res = (res + stirling2_dp(k,i)*pw)%MOD;
            pw = (pw*(n-i)%MOD)*val%MOD;
        }
        res = res*qpow(x*inv((x+MOD-1)%MOD)%MOD,n)%MOD;
        return res;
    }

    ll lagrange_interpolation_arithmetic(const vector<ll> &y, ll T, ll a = 0, ll d = 1)
    {
        T = mod(T), a = mod(a), d = mod(d);

        int N = (int)y.size()-1;
        if(a == 0 && d == 1 && T <= N)return y[T];

        vector<ll> dp(N+1, 1), pd(N+1, 1);
        for(int i = 0 ; i < N ; i++)dp[i+1] = dp[i]*(T+MOD-(a+d*i)%MOD)%MOD;
        for(int i = N ; i > 0 ; i--)pd[i-1] = pd[i]*(T+MOD-(a+d*i)%MOD)%MOD;

        vector<ll> fact(N+1, 1), finv(N+1, 1);

        for(int i = 1 ; i <= N ; i++)fact[i] = fact[i-1]*d%MOD*i%MOD;
        finv[N] = finv[N]*inv(fact[N])%MOD;
        for(int i = N ; i >= 1 ; i--)finv[i-1] = finv[i]*d%MOD*i%MOD;

        ll ret = 0;

        for(int i = 0 ; i <= N ; i++)
        {
            ll tmp = y[i]*dp[i]%MOD*pd[i]%MOD*finv[i]%MOD*finv[N-i]%MOD;
            if((N-i)&1)ret = (ret+MOD-tmp)%MOD;
            else ret = (ret+tmp)%MOD;
        }

        return ret;
    }

    ll lagrange_interpolation(vector<pair<ll,ll>> p, ll z)
    {
        int n = p.size();
        ll l, val = 0;

        for(int i = 0 ; i < n ; i++)
        {
            p[i].first = mod(p[i].first);
            p[i].second = mod(p[i].second);
        }

        z = mod(z);

        for(int i = 0 ; i < n ; i++)
        {
            l = p[i].second;
            for(int j = 0 ; j < n ; j++)
            {
                if(i != j)
                {
                    l = l*(z+MOD-p[j].first)%MOD*inv(p[i].first+MOD-p[j].first)%MOD;
                }
            }
            val = (val+l)%MOD;
        }
        return val;
    }

    //Intersection value when you do inclusion and exclusion
    //principle with all subsets of size K of a set of N elements
    ll intersection_value(ll N, ll K)
    {
        if(N < K)return 0;
        if(K == 0)
        {
            if(N == 0)return 1;
            return 0;
        }
        if((N-K)&1)return mod(-comb(N-1,K-1));
        return comb(N-1,K-1);
    }

    ll catalan(int n)
    {
        return comb(2*n,n)*inum(n+1)%MOD;
    }

    ll comb_small_mod(ll n, ll k)
    {
        if(n < k)return 0;

        update(MOD-1);

        function<ll(ll)> f = [&](ll x)
        {
            ll pw = 1, tot = 0;

            while(pw <= x/MOD)
            {
                pw *= MOD;
                tot += x/pw;
            }

            return tot;
        };

        function<ll(ll)> g = [&](ll x)
        {
            ll tot = 1;

            while(x)
            {
                if(x/MOD%2 == 1)tot = (MOD-tot)%MOD;
                tot = tot*_fact[x%MOD]%MOD;
                x /= MOD;
            }

            return tot;
        };

        if(f(n) != f(n-k)+f(k))return 0;

        ll res = g(n)*inv(g(n-k)*g(k)%MOD)%MOD;

        return res;
    }

    ll comb(int n, int k)
    {
        if(n < k)return 0;
        update(n);
        return (_fact[n]*_ifact[n-k]%MOD)*_ifact[k]%MOD;
    }

    ll comb2(ll n, int k)
    {
        if(n < k)return 0;
        k = min((ll)k, n-k);
        update(k);
        ll res = 1;
        for(ll i = n ; i > n-k ; i--)res = i%MOD*res%MOD;
        return res*_ifact[k]%MOD;
    }
}math(MOD);

typedef long long ll;

template<typename T, typename Q>
struct SEGMENT_TREE
{
    ll Li, Ri;

    int pt = 0;

    vector<T> ST;
    vector<int> L;
    vector<int> R;
    vector<bool> lazy;

    T query_res;
    bool query_flag, bs_flag;

    void new_node(int a, int b)
    {
        ST.push_back(T{});
        ST.back().L = a;
        ST.back().R = b;
        ST.back().sum = b-a+1;
        L.push_back(0);
        R.push_back(0);
        lazy.push_back(false);
    }

    SEGMENT_TREE()
    {

    }

    SEGMENT_TREE(ll a, ll b)
    {
        init(a,b);
    }

    void clear()
    {
        pt = 0;
        ST.clear();
        L.clear();
        R.clear();
        lazy.clear();
        new_node(Li,Ri);
    }

    void init(ll a, ll b)
    {
        assert(a <= b);
        Li = a, Ri = b;
        clear();
    }

    void build(vector<T> &vect)
    {
        assert(Ri-Li+1 == (ll)vect.size());
        ST_build(0,Li,Ri,vect);
    }

    void insert(ll x, T nod)
    {
        ST_insert(0,Li,Ri,x,nod);
    }

    template<class F>
    bool binary_search_right(ll a, ll b, F f, T &tp)
    {
        query_res = T{};
        query_flag = false;
        bs_flag = false;
        ST_binary_search_right(0,Li,Ri,a,b,f);
        if(bs_flag)
        {
            tp = query_res;
            return true;
        }
        else
        {
            tp = T{};
            return false;
        }
    }

    template<class F>
    bool binary_search_left(ll a, ll b, F f, T &tp)
    {
        query_res = T{};
        query_flag = false;
        bs_flag = false;
        ST_binary_search_left(0,Li,Ri,a,b,f);
        if(bs_flag)
        {
            tp = query_res;
            return true;
        }
        else
        {
            tp = T{};
            return false;
        }
    }

    void update(ll x, Q &up)
    {
        ST_update(0,Li,Ri,x,x,up);
    }

    void update(ll a, ll b, Q &up)
    {
        ST_update(0,Li,Ri,a,b,up);
    }

    T query(ll x)
    {
        query_res = T{};
        query_flag = false;
        ST_query(0,Li,Ri,x,x);
        return query_res;
    }

    T query(ll a, ll b)
    {
        query_res = T{};
        query_flag = false;
        ST_query(0,Li,Ri,a,b);
        return query_res;
    }

    void ST_build(int node, ll l, ll r, vector<T> &vect)
    {
        if(l == r)
        {
            ST[node] = vect[l-Li];
            return;
        }
        else
        {
            L[node] = ++pt;
            new_node(l,(l+r)/2);
            R[node] = ++pt;
            new_node((l+r)/2+1,r);
        }

        ll mid = (l+r)/2;

        ST_build(L[node],l,mid,vect);
        ST_build(R[node],mid+1,r,vect);

        ST[node].merge(ST[L[node]],ST[R[node]]);
    }

    void ST_insert(int node, ll l, ll r, ll x, T &nod)
    {
        if(l != r)
        {
            if(L[node] == 0)
            {
                L[node] = ++pt;
                new_node(l,(l+r)/2);
            }
            if(R[node] == 0)
            {
                R[node] = ++pt;
                new_node((l+r)/2+1,r);
            }
        }

        if(lazy[node])
        {
            if(l != r)
            {
                ST[node].propagation(ST[L[node]],ST[R[node]]);
                lazy[L[node]] = true;
                lazy[R[node]] = true;
            }
            ST[node].update(l,r);
            lazy[node] = false;
        }

        if(l == r)
        {
            ST[node] = nod;
            return;
        }

        ll mid = (l+r)/2;

        if(x <= mid)ST_insert(L[node],l,mid,x,nod);
        else ST_insert(R[node],mid+1,r,x,nod);

        ST[node].merge(ST[L[node]],ST[R[node]]);
    }

    template<class F>
    void ST_binary_search_right(int node, ll l, ll r, ll a, ll b, F &f)
    {
        if(l != r)
        {
            if(L[node] == 0)
            {
                L[node] = ++pt;
                new_node(l,(l+r)/2);
            }
            if(R[node] == 0)
            {
                R[node] = ++pt;
                new_node((l+r)/2+1,r);
            }
        }

        if(lazy[node])
        {
            if(l != r)
            {
                ST[node].propagation(ST[L[node]],ST[R[node]]);
                lazy[L[node]] = true;
                lazy[R[node]] = true;
            }
            ST[node].update(l,r);
            lazy[node] = false;
        }

        if(a <= l && r <= b)
        {
            T query_temp = query_res;
            bool flag_temp = query_flag;
            if(query_flag)
            {
                T temp;
                temp.merge(query_res, ST[node]);
                query_res = temp;
            }
            else
            {
                query_res = ST[node];
                query_flag = true;
            }
            if(f(query_res))
            {
                query_res = query_temp;
                query_flag = flag_temp;
                ST_binary_search_into_right(node,l,r,f);
                bs_flag = true;
            }
            return;
        }

        ll mid = (l+r)/2;

        if(a <= mid)ST_binary_search_right(L[node],l,mid,a,b,f);
        if(bs_flag)return;
        if(b > mid)ST_binary_search_right(R[node],mid+1,r,a,b,f);
    }

    template<class F>
    void ST_binary_search_into_right(int node, ll l, ll r, F &f)
    {
        if(l != r)
        {
            if(L[node] == 0)
            {
                L[node] = ++pt;
                new_node(l,(l+r)/2);
            }
            if(R[node] == 0)
            {
                R[node] = ++pt;
                new_node((l+r)/2+1,r);
            }
        }

        if(lazy[node])
        {
            if(l != r)
            {
                ST[node].propagation(ST[L[node]],ST[R[node]]);
                lazy[L[node]] = true;
                lazy[R[node]] = true;
            }
            ST[node].update(l,r);
            lazy[node] = false;
        }

        ll mid = (l+r)/2;

        if(l == r)
        {
            if(query_flag)
            {
                T temp;
                temp.merge(query_res, ST[node]);
                query_res = temp;
            }
            else
            {
                query_res = ST[node];
                query_flag = true;
            }
            return;
        }

        T query_temp = query_res;
        bool flag_temp = query_flag;
        if(query_flag)
        {
            T temp;
            temp.merge(query_res, ST[L[node]]);
            query_res = temp;
        }
        else
        {
            query_res = ST[L[node]];
            query_flag = true;
        }

        if(f(query_res))
        {
            query_res = query_temp;
            query_flag = flag_temp;
            ST_binary_search_into_right(L[node],l,mid,f);
        }
        else
        {
            ST_binary_search_into_right(R[node],mid+1,r,f);
        }
    }

    template<class F>
    void ST_binary_search_left(int node, ll l, ll r, ll a, ll b, F &f)
    {
        if(l != r)
        {
            if(L[node] == 0)
            {
                L[node] = ++pt;
                new_node(l,(l+r)/2);
            }
            if(R[node] == 0)
            {
                R[node] = ++pt;
                new_node((l+r)/2+1,r);
            }
        }

        if(lazy[node])
        {
            if(l != r)
            {
                ST[node].propagation(ST[L[node]],ST[R[node]]);
                lazy[L[node]] = true;
                lazy[R[node]] = true;
            }
            ST[node].update(l,r);
            lazy[node] = false;
        }

        if(a <= l && r <= b)
        {
            T query_temp = query_res;
            bool flag_temp = query_flag;
            if(query_flag)
            {
                T temp;
                temp.merge(query_res, ST[node]);
                query_res = temp;
            }
            else
            {
                query_res = ST[node];
                query_flag = true;
            }
            if(f(query_res))
            {
                query_res = query_temp;
                query_flag = flag_temp;
                ST_binary_search_into_left(node,l,r,f);
                bs_flag = true;
            }
            return;
        }

        ll mid = (l+r)/2;

        if(b > mid)ST_binary_search_left(R[node],mid+1,r,a,b,f);
        if(bs_flag)return;
        if(a <= mid)ST_binary_search_left(L[node],l,mid,a,b,f);
    }

    template<class F>
    void ST_binary_search_into_left(int node, ll l, ll r, F &f)
    {
        if(l != r)
        {
            if(L[node] == 0)
            {
                L[node] = ++pt;
                new_node(l,(l+r)/2);
            }
            if(R[node] == 0)
            {
                R[node] = ++pt;
                new_node((l+r)/2+1,r);
            }
        }

        if(lazy[node])
        {
            if(l != r)
            {
                ST[node].propagation(ST[L[node]],ST[R[node]]);
                lazy[L[node]] = true;
                lazy[R[node]] = true;
            }
            ST[node].update(l,r);
            lazy[node] = false;
        }

        ll mid = (l+r)/2;

        if(l == r)
        {
            if(query_flag)
            {
                T temp;
                temp.merge(query_res, ST[node]);
                query_res = temp;
            }
            else
            {
                query_res = ST[node];
                query_flag = true;
            }
            return;
        }

        T query_temp = query_res;
        bool flag_temp = query_flag;
        if(query_flag)
        {
            T temp;
            temp.merge(query_res, ST[R[node]]);
            query_res = temp;
        }
        else
        {
            query_res = ST[R[node]];
            query_flag = true;
        }

        if(f(query_res))
        {
            query_res = query_temp;
            query_flag = flag_temp;
            ST_binary_search_into_left(R[node],mid+1,r,f);
        }
        else
        {
            ST_binary_search_into_left(L[node],l,mid,f);
        }
    }

    void ST_update(int node, ll l, ll r, ll a, ll b, Q &up)
    {
        if(l != r)
        {
            if(L[node] == 0)
            {
                L[node] = ++pt;
                new_node(l,(l+r)/2);
            }
            if(R[node] == 0)
            {
                R[node] = ++pt;
                new_node((l+r)/2+1,r);
            }
        }

        if(lazy[node])
        {
            if(l != r)
            {
                ST[node].propagation(ST[L[node]],ST[R[node]]);
                lazy[L[node]] = true;
                lazy[R[node]] = true;
            }
            ST[node].update(l,r);
            lazy[node] = false;
        }

        if(r < a || l > b)return;

        if(a <= l && r <= b)
        {
            ST[node].push(up);
            if(l != r)
            {
                ST[node].propagation(ST[L[node]],ST[R[node]]);
                lazy[L[node]] = true;
                lazy[R[node]] = true;
            }
            ST[node].update(l,r);
            return;
        }

        ll mid = (l+r)/2;

        ST_update(L[node],l,mid,a,b,up);
        ST_update(R[node],mid+1,r,a,b,up);

        ST[node].merge(ST[L[node]],ST[R[node]]);
    }

    void ST_query(int node, ll l, ll r, ll a, ll b)
    {
        if(l != r)
        {
            if(L[node] == 0)
            {
                L[node] = ++pt;
                new_node(l,(l+r)/2);
            }
            if(R[node] == 0)
            {
                R[node] = ++pt;
                new_node((l+r)/2+1,r);
            }
        }

        if(lazy[node])
        {
            if(l != r)
            {
                ST[node].propagation(ST[L[node]],ST[R[node]]);
                lazy[L[node]] = true;
                lazy[R[node]] = true;
            }
            ST[node].update(l,r);
            lazy[node] = false;
        }

        if(a <= l && r <= b)
        {
            if(query_flag)
            {
                T temp;
                temp.merge(query_res, ST[node]);
                query_res = temp;
            }
            else
            {
                query_res = ST[node];
                query_flag = true;
            }
            return;
        }

        ll mid = (l+r)/2;

        if(a <= mid)ST_query(L[node],l,mid,a,b);
        if(b > mid)ST_query(R[node],mid+1,r,a,b);
    }
};

struct QUERY
{
};

struct NODE
{
    int sum;
    int L, R;
    bool lazy = false;

    void merge(NODE &H1, NODE &H2)
    {
        sum = H1.sum + H2.sum;
        L = H1.L;
        R = H2.R;
    }
    void push(QUERY &Q)
    {
        lazy = true;
    }
    void update(ll l, ll r)
    {
        sum = 0;
        lazy = false;
    }
    void propagation(NODE &H1, NODE &H2)
    {
        H1.lazy |= lazy;
        H2.lazy |= lazy;
    }
};

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;

    while(T--)
    {
    	int N, M;
    	cin >> N >> M;

    	SEGMENT_TREE<NODE,QUERY> ST(1,N);

    	auto f = [&](int x)
    	{
    		auto fff = [&](NODE tp)
    		{
    			if(tp.sum >= x)
    			{
    				return true;
    			}
    			return false;
    		};

    		NODE tp;

    		if(!ST.binary_search_right(1,N,fff,tp))return -1ll;
    		return tp.R;
    	};

        auto eliminar = [&](int a, int b)
        {
            QUERY tp;
            ST.update(a,b,tp);
        };

        vector<pair<int,int>> vect;

    	for(int i = 1 ; i <= M ; i++)
    	{
    		int a, b;
    		cin >> a >> b;
            vect.push_back({a,b});
    	}

        reverse(vect.begin(), vect.end());

        int temp = N;
        int tam = N;

        set<int> st;

        for(auto x : vect)
        {
            if(temp-x.first > 0)
            {
                int cont = temp-x.first;
                int pos = f(tam-cont+1);
                eliminar(pos,N);

                tam -= cont;
            }
            temp = x.first-1;

            if(x.second != tam)
            {
                int pos2 = f(x.second+1);

                st.insert(pos2);
            }

            int pos = f(x.second);

            eliminar(pos,pos);
        }

        int K = st.size();

        int res = math.comb(N+N-K-1,N);

        cout << res << '\n';
    }

    return 0;
}