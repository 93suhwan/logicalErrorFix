#include<bits/stdc++.h>
using namespace std;
#define  ll  long long int
#define  ld  long double
#define fastio      ios_base::sync_with_stdio(false); cin.tie(NULL);
#define  endl        "\n"
#define setbits(x)   __builtin_popcount(x)
#define gcd(a,b)     __gcd(a,b)
#define minv(v)      *min_element(v.begin(), v.end())
#define maxv(v)      *max_element(v.begin(), v.end())
const int mod        = 1e9+7;
const int bit        = 31;
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
//macro definition
#define ordered_set tree<int>, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
void PrimeSieve(vector<int> &p)
{
  //mark all odd numbers as prime hi hi captain
  for(int i=3; i<=1000000; i+=2)
  {
    p[i] = 1;
  }
  // iterate over the potential primes and mark multiples as not prime
  for(ll i=3; i<=1000000; i+=2)
  {
    if(p[i] == 1)
    {
      for(ll j=i*i; j<1000000; j+=i)
        p[j] = 0;
    }
  }
  //some special cases
  p[2] = 1;
  p[0] = p[1] = 0;
}
ll fastmodExp(ll a, ll b)
{
  a %= mod;
  b %= mod;
  ll res = 1;
  while(b > 0)
  {
    if(b&1)
    res = (res*a)%mod;
    b = b>>1;
    a = (a*a)%mod;
  }
  return res;
} 
//__________________________________________________________________________________________________________________

int main()
{
  fastio;
  int t;
  cin>>t;
  while(t--)
  {
    int n;
    cin>>n;
    string bin;
    cin>>bin;
    for(int i=0; i<n; i++)
    {
      if(bin[i] == '0')
      {
        if(i < n/2)
        {
          cout<<i+2<<" "<<n<<" "<<i+1<<" "<<n<<endl;
        }
        else
        {
          cout<<1<<" "<<i+1<<" "<<1<<" "<<i<<endl;
        }
        break;
      }
    }
  }
  return 0;
}