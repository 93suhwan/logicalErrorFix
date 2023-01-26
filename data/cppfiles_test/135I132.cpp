#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
#define endl "\n"
#define ll long long int
#define ld long double
#define pb push_back
#define mp make_pair
#define vll vector<ll>
#define vpll vector<pair<ll,ll>>
#define all(x) x.begin(),x.end()
ll mod=1000000007;

using namespace std;

int main()
{
    fastio;
    ll t;
    cin >> t;
    while (t--)
    {
        ll n,k;
        cin >> n >> k;
        vll v(n);
        for (ll i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        sort(all(v));
        deque<ll> v1;
        for (ll i = 0; i < size(v); i++)
        {
            v1.pb(v[i]);
        }
        ll ans=0,ans1=0,a=k;
        while (a--)
        {
            ans+=v[size(v)-2]/v[size(v)-1];
            v.pop_back();
            v.pop_back();
        }
        while (k--)
        {
            ans1+=v1[0]/v1[size(v1)-1];
            v1.pop_back();
            v1.pop_front();
        }
        for (ll i = 0; i < size(v); i++)
        {
            ans+=v[i];
        }
        for (ll i = 0; i < size(v1); i++)
        {
            ans1+=v1[i];
        }
        cout << min(ans,ans1) << endl;
    }
    return 0;
}