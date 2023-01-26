#include<bits/stdc++.h>
#define ll long long int
#define endl "\n"
#define pb push_back
#define mod 1000000007
using namespace std;


vector<ll>primes;

void sieve()
{
    bool prime[10000001];
    memset(prime,true,sizeof(prime));
    prime[0]=prime[1]=false;
    
    for(ll i=2;i*i<=10000001;i++)
    {
        if(prime[i])
        {
            for(ll j=i*i;j<10000001;j+=i)
            prime[j]=false;
        }
    }
   
    ll count=0;
    for(ll i=0;i<10000001;i++)
    {
       if(prime[i])
         count++;
        primes.pb(count);
    }
}


void solve()
{
  ll n;
  cin>>n;
  ll arr[n];
  for(ll i=0;i<n;i++)
  cin>>arr[i];
  
  ll ev_gcd = arr[1] , od_gcd = arr[0];
  
  for(ll i=2;i<n;i+=2){
    od_gcd = __gcd(od_gcd,arr[i]);
    ev_gcd = __gcd(ev_gcd,arr[i-1]);
  }
  
  if(ev_gcd==od_gcd)
  {
      cout<<0<<"\n";
  }
  else
  {
          for(ll i=1;i<n;i+=2)
           {
               if(arr[i]%od_gcd==0)
                {
                    for(ll i=0;i<n;i+=2)
                    {
                        if(arr[i]%ev_gcd==0)
                        {
                            cout<< 0 <<"\n";
                            return;
                        }
                    }
                    
                    cout<< ev_gcd <<"\n";
                    return;
                }
           }
           
           cout<< od_gcd <<"\n";
  }
}

int main()
{    
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll t=1;
    cin>>t;
    while(t--)
    {
       solve();
    }
}
