 // @author : DEEP PATEL
 #include<bits/stdc++.h>
 using namespace std;


 //define shortcuts
 #define ll long long int
 #define fo(i,a,n) for(ll i=a;i<n;i++)
 #define rfo(i,a,n) for(ll i=n-1;i>=a;i--)
 #define all(a) a.begin(),a.end()
//change
 #define pb push_back
 #define ite(a) for(auto &x : a)
 #define fast ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
 #define ri reverse_iterator
 //defines finish

 //print function(degug)

bool isPrime(ll n)
{
// Corner cases
if (n <= 1)
    return false;
if (n <= 3)
    return true;

// This is checked so that we can skip
// middle five numbers in below loop
if (n % 2 == 0 || n % 3 == 0)
    return false;

for (int i = 5; i * i <= n; i = i + 6)
    if (n % i == 0 || n % (i + 2) == 0)
        return false;

return true;
}
 //floor and ceil for integer
 ll ceil(ll n,ll m) {if(n%m==0)return n/m; else return n/m+1;}

 //ncr Function
 ll mod = 1e9 + 7;
 ll MOD = mod;

 //ncr Function
 ll fact(ll n);

 ll nCr(ll n, ll r)
 {
     return fact(n) / (fact(r) * fact(n - r));
 }

 // Returns factorial of n
 ll fact(ll n)
 {
     int res = 1;
     for (int i = 2; i <= n; i++)
         res = res * i;
     return res;
 }
 ll lcm(ll n,ll m)
 {

   return (n*m)/__gcd(n,m);



 }




 bool seive(ll n)
 {
      ll prime[n+1];
      memset(prime,1,sizeof(prime));
      for(int i = 2;i * i <= n; i++)
      {
           if(prime[i] == 1)
           {
                for(int j = i * i; j <= n; j++)
                {
                     prime[i] = 0;
                }
           }
      }

      return prime[n];
 }

 void ret()
 {
      ll n,i,j,k,c=0,d=0;
      cin>>n>>k;
      vector<ll> a(n);
      for(i=0;i<n;i++)
      cin>>a[i];

      sort(all(a));
     vector<ll> l;
     vector<ll> r;

     for(i=0;i<n;i++)
     {
         if(a[i]<0)
         {
             l.push_back(a[i]);
         }
     }

     for(i=0;i<n;i++)
     {
         if(a[i]>0)
         {
             r.pb(a[i]);
         }
     }
     if(l.size()>0)
     {
     c +=abs(l[0]);
     for(i=k;i<l.size();i++)
     {

         c += 2*abs(l[i]);
         i +=(k-1);
     }
    }
     if(r.size()>0)
     {
     for(i=r.size()-1;i>=0;i--)
     {
         c +=2*abs(r[i]);
         i -=(k-1);
     }
    }
    ll ma = c;
    c = 0;


    if(r.size()>0)
    {
        if(l.size()>0)
        {
            for(i=0;i<l.size();i++)
            {
                c +=2*(abs(l[i]));
                i +=(k-1);
            }
        }

        c +=r[r.size()-1];
        for(i=r.size()-1-k;i>=0;i--)
        {
            c +=2*(r[i]);
            i -=(k-1);
        }

    }






cout<<min(c,ma)<<endl;




 }


 int main()
 {
      fast;
      ll t;
      t = 1;
      cin>>t;
      while(t--)
      ret();
 }
