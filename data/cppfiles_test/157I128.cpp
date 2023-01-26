#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef tree<long long,null_type,less_equal<long long>,rb_tree_tag,tree_order_statistics_node_update> pbds_mset;
typedef tree<long long,null_type,less<long long>,rb_tree_tag,tree_order_statistics_node_update> pbds_set;
template<typename T> // cin >> vector<T>
istream& operator>>(istream &istream, vector<T> &v) { for (auto &it : v) cin >> it; return istream; }
template<typename T> // cout << vector<T>
ostream& operator<<(ostream &ostream, const vector<T> &c) { for (auto &it : c) cout << it << " "; return ostream; }
#define ll long long
#define pb push_back
#define f first
#define s second
#define mod 1000000007
#define mod2 998244353
#define vll vector<ll>
#define pll pair<ll,ll>
#define vpll vector<pair<ll,ll>>
#define pqmax priority_queue<ll>
#define pqmin priority_queue<ll,vll,greater<ll>>
#define val_at find_by_order
//*st.find_by_order(n)
#define less_than order_of_key
//st.order_of_key(n)

ll power(ll x,ll y, ll p)
{
    ll res = 1;

    x = x % p;


    while (y > 0)
    {


        if (y & 1)
            res = (res * x) % p;


        y = y >> 1;
        x = (x * x) % p;
    }
    return res;
}

ll modInverse(ll n, ll p)
{
    return power(n, p - 2, p);
}

ll nCr(ll n,ll r, ll p=mod2)
{
    if (n < r)
        return 0;
    if (r == 0)
        return 1;

   ll fac[n + 1];
    fac[0] = 1;
    for (int i = 1; i <= n; i++)
        fac[i] = (fac[i - 1] * i) % p;

    return (fac[n] * modInverse(fac[r], p) % p
            * modInverse(fac[n - r], p) % p)
           % p;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll t;
	t=1;
	//cin>>t;
	start:
	while(t--){

            ll n,k;
    cin>>n>>k;
    string s;
    cin>>s;

    if(k==0){
        cout<<"1"<<endl;
        goto start;
    }

    ll sum=0,st=-1;

    for(ll i=0;i<s.size();i++){
        sum+=(s[i]-'0');
        if(sum>k){
            st=i;
            break;
        }
    }

    if(st==-1 && sum<k){
        cout<<"1"<<endl;
        goto start;
    }

    ll ans=nCr(st,k),len=st;

    for(ll i=st;i<n;i++){
        if(s[i]=='0'){
            len++;
            ans=(ans+nCr(len-1,k-1))%mod2;
        }
        else ans=(ans+nCr(len-1,k))%mod2;
    }

    cout<<ans%mod2<<endl;



	}
	return 0;

}
