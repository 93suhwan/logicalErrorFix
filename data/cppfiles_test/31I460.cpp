#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
#define mxx 200005
#define inf 2e18
ll dp[100005];
ll power[mxx];
ll factorial[mxx];

bool isPrime(ll n)
{
    if(n<=3)return true;
    else if(n%2==0 || n%3==0)
      return false;
    for(ll i=5;i*i<=n;i=i+6)
      if(n%i==0 || n%(i+2)==0)
         return false;
         return true;
}

ll powm(ll x,ll y)
{
   ll res=1;
   while(y>0)
   {
      if(y&1)
      res=(res*x)%mod;
      x=(x*x)%mod;y>>=1;
   }
return res;
}

ll poww(ll x,ll y)
{
   ll res=1;
   while(y>0)
   {
      if(y&1)
      res=(res*x);
      x=(x*x);y>>=1;
   }
return res;
}

ll mod_inverse(ll a)
{
   return poww(a ,mod-2);
}



void preComputeFactorial() {
    factorial[0]=power[0]=1;
    for(ll i=1; i<mxx; i++) {
        factorial[i]=(factorial[i-1]*i)%mod;
        power[i]=poww(factorial[i],mod-2);

    }
}

ll nCr(ll n, ll r) {
    return (factorial[n]*( (power[r]*power[n-r])%mod) )%mod;
}

///*****solve****** ///


void solve()
{
   ll n,i,j;
   cin>>n;
   ll arr[n];
   stack<ll>s;
   for(i=0;i<n;i++)
      cin>>arr[i];
   if(n&1)
   {
      
      for(j=n-1,i=0;i+2<j;i++,j--)
      {
         ll l=arr[i]*arr[j];
         if(l>0)
         {
            ll lcm=l/(__gcd(arr[i],arr[j]));
          cout<<lcm/arr[i]<<" ";
          s.push(-lcm/arr[j]);
         }
       else
       {
         if(arr[i]<0)
         {
             ll lcm=-l/(__gcd(-arr[i],arr[j]));
            cout<<lcm/arr[i]<<" ";
             s.push(-lcm/arr[j]);
         }
         else
         {
            ll lcm=-l/(__gcd(arr[i],-arr[j]));
            cout<<lcm/arr[i]<<" ";
             s.push(-lcm/arr[j]);
         }
       }
         
      }

      ll c=abs(arr[i]*arr[i+1]*arr[i+2]);
      ll gcd=__gcd(abs(arr[i+2]),__gcd(abs(arr[i]),abs(arr[i+1])));
      cout<<c/(arr[i]*gcd)<<" "<<-abs((2*c)/(gcd*arr[i+1]))<<" "<<c/(arr[i+2]*gcd)<<" ";
      while(s.size())
      {
         cout<<s.top()<<" ";
         s.pop();
      }
   }
   else
   {
      for(j=n-1,i=0;i<j;i++,j--)
      {
         if(arr[i]*arr[j]>0)
         {
          cout<<arr[j]<<" ";
          s.push(-arr[i]);
         }
       else
       {
         if(arr[i]<0)
         {
            cout<<-arr[j]<<" ";
            s.push(arr[i]);
         }
         else
         {
            cout<<arr[j]<<" ";
            s.push(-arr[i]);
         }
       }
         
      }
       while(s.size())
      {
         cout<<s.top()<<" ";
         s.pop();
      }
   }

   cout<<"\n";
}
 
int main()
{

ios::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);


ll t;
t=1;
cin>>t;
while(t--)
solve();
return 0;
}