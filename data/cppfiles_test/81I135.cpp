#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define pi 3.141592653589793238
#define ll long long
#define ld long double
#define rep(i, a, b) for (long long i = a; i <= b; i++)
#define mod 998244353
#define INF 1000000000000000000
#define pb push_back
#define ff first
#define ss second
#define endl '\n'
#define all(x) (x).begin (), (x).end ()
#define sz(x) (ll) (x).size ()
#define rank rnk
#define log lg
#define fast                                                                  \
    ios_base::sync_with_stdio (false);                                        \
    cin.tie (NULL);                                                           \
    cout.tie (NULL)

using namespace std;
using namespace __gnu_pbds;
typedef tree<ll, null_type, less<ll>, rb_tree_tag,
             tree_order_statistics_node_update>
    ordered_set;

ll absl(ll x)
{
    return x>0?x:-x;
}

template <class T> class sparse_table {
  public:
    vector<vector<T>> st;
    ll N, K;
    vector<ll> log;
    const T &(*f)(const T &, const T &);

    sparse_table(T array[], ll n, const T &(*_f)(const T &, const T &),
                 ll k = 25) {
        N = n;
        K = k;

        f = _f;

        for (ll i = 0; i <= N; i++) {
            vector<T> v(K + 1);
            st.push_back(v);
        }

        for (ll i = 0; i < N; i++)
            st[i][0] = array[i];

        build();
    }

    sparse_table(vector<T> &array, const T &(*_f)(const T &, const T &),
                 ll k = 25) {
        N = (ll)array.size();
        K = k;

        f = _f;

        for (ll i = 0; i <= N; i++) {
            vector<T> v(K + 1);
            st.push_back(v);
        }

        for (ll i = 0; i < N; i++)
            st[i][0] = array[i];

        build();
    }

    void build() {
        log.assign(N + 1, 0);

        for (ll i = 2; i <= N; i++)
            log[i] = log[i >> 1] + 1;

        for (ll j = 1; j <= K; j++)
            for (ll i = 0; i + (1 << j) <= N; i++)
                st[i][j] = f(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
    }

    T in_range(ll L, ll R) {
        ll j = log[R - L + 1];
        return f(st[L][j], st[R - (1 << j) + 1][j]);
    }
};

ll f(ll x)
{
    ll v=x/2;
    if(v%2==0)
    return v;
    else
    return v+1;
}

signed
main ()
{
    fast;

    ll tst;
    cin>>tst;
    while(tst--)
    {
        ll n,q;
        cin>>n>>q;

        string str;
        cin>>str;

        char arr[n+1];
        rep(i,1,n)
        arr[i]=((str[i-1]=='+')?+1:-1);

        ll odd[n+1],even[n+1];
        odd[0]=even[0]=0;
        odd[1]=even[1]=0;

        if(arr[1]==1)
        odd[1]++;
        else
        odd[1]--;

        odd[2]=odd[1];
        even[2]=even[1];

        if(arr[2]==1)
        even[2]++;
        else
        even[2]--;

        rep(i,3,n)
        {
            if(i%2)
            {
                odd[i]=odd[i-2]+arr[i];
                even[i]=even[i-1];
            }
            else
            {
                even[i]=even[i-2]+arr[i];
                odd[i]=odd[i-1];
            }
        }

        ll val[n+1];
        rep(i,1,n)
        val[i]=-(odd[i-1]+odd[i]-even[i-1]-even[i]);

        sparse_table <ll> mn(val,n+1,min), mx(val,n+1,max);

        while(q--)
        {
            ll l,r;
            cin>>l>>r;

            if((r-l+1)%2==0)
            {
                ll v1=even[r]-even[l-1];
                ll v2=odd[r]-odd[l-1];
                cout<<f(absl(v1-v2))<<endl;
            }
            else
            {
                ll close=even[l-1]+even[r]-odd[l-1]-odd[r];
                ll up=mx.in_range(l,r);
                ll down=mn.in_range(l,r);

                if(down<=close && close<=up)
                {
                    cout<<1<<endl;
                }
                else if(close<down)
                {
                    cout<<1+f(absl(close-down))<<endl;
                }
                else if(close>up)
                {
                    cout<<1+f(absl(up-close))<<endl;
                }
            }
        }

        // rep(i,1,n)
        // cout<<odd[i]<<" "<<even[i]<<endl;
    }

    return 0;
}