#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair

#define collect(v, n)            \
    for (ll i = 0; i < n; i++) { \
        cin >> v[i];             \
    }
//sort(a.rbegin(), a.rend());

using namespace std;


void fast()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

ll min(ll a, ll b)
{
    if (a < b) return a;
    return b;
}

void amax(ll &a, ll b) { a = max(a, b); }
void amin(ll &a, ll b) { a = min(a, b); }
void updateArray(ll arr[], ll N)
{
    //  convert array into prefix sum array
    for (ll i = 1; i < N; i++)
        arr[i] += arr[i - 1];
}


int count_digits(int n)
{
    string num = to_string(n);
    return num.size();
}






/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


ll GcdOfArray(vector<ll>& arr, ll idx)
{
    if (idx == arr.size() - 1) {
        return arr[idx];
    }
    ll a = arr[idx];
    ll b = GcdOfArray(arr, idx + 1);
    return __gcd(
        a, b); // __gcd(a,b) is inbuilt library function
}

void solve(){


ll n;
cin>>n;
ll arr[n];
ll b[n];
ll sum=0;

for(ll i=0;i<n;i++)
{
    cin>>arr[i];
    sum+=arr[i];
}
ll result=(n*(n+1))/2;
if(sum%result!=0)
{
    cout<<"NO"<<endl;
    return;
}

else
{
    result=sum/result;
    b[0]=(arr[n-1]+result-arr[0])/n;
    if(b[0]==0||((arr[n-1]+result-arr[0])%n!=0))
    {cout<<"NO"<<endl;
            return;
        
    }
    for(ll i=1;i<n;i++)
    {
        if((result-arr[i]+arr[i-1])%n!=0)
        {
            cout<<"NO"<<endl;
            return;
        }

        b[i]=(result-arr[i]+arr[i-1])/n;
        if(b[i]==0)
        {
            cout<<"NO"<<endl;
            return;
        }



    }
}
cout<<"YES"<<endl;
for(ll i=0;i<n;i++)
{
    cout<<b[i]<<" ";
}
cout<<endl;
}


int main()
{
    fast();


ll t;
cin>>t;
for(ll y=0;y<t;y++)
{

       solve();

}

}
