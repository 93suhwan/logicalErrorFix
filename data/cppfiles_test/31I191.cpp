#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>
int32_t mod = 1e9 + 7;
ll findlcm(vector<ll> arr, ll n)
{
    ll ans = arr[0];
    for (ll i = 1; i < n; i++)
        ans = (((arr[i] * ans)) / (__gcd(arr[i], ans)));
    return ans;
}
void solveCase()
{
    ll n = 0;
    cin >> n;
    vector<ll> a(n);
    for(ll i=0;i<n;i++) cin>>a[i];
    vector<ll> b(n);
    ll cp=0,cn=0;
    for(ll i=0;i<n;i++){
        b[i]=abs(a[i]);
        if(a[i]<0) cn++;
        else cp++;
    }
    ll f= findlcm(b,n);
    vector<ll> ans(n);
    if(n%2==0)
    for(ll i=0;i<n;i++){
        if(i%2==0){
            b[i]=f/a[i];
        }
        else {
            b[i]= (-1)*f/a[i];
        }
    }
    else{
        for(ll i=0;i<n;i++){
        if(i%2==0){
            b[i]=f/a[i];
        }
        else {
            b[i]= (-1)*f/a[i];
        }
    }
    b[1]=-2*f/a[1];
    }
    ll sum=0;
    for(ll i=0;i<n;i++){ cout<<b[i]<<" ";  sum+=a[i]*b[i]; }
   // cerr<<sum<<endl;
    cout << "\n";
}

int32_t main()
{
    ll t = 0;
    cin >> t;
    while (t--)
        solveCase();
}