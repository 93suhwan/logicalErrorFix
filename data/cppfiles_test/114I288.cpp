// Author : [SAURAV KUMAR]
  
#include<bits/stdc++.h>
using namespace std;
#define         fastI_O ios_base::sync_with_stdio(false);cin.tie(NULL)
#define         ll             long long
#define         pb             push_back
#define         pob            pop_back
#define         str            string
#define         mp             make_pair
#define         vt             vector
#define         is(a)          to_string(a)  // integer to string
#define         repj(i,a,b,c)  for(ll i=a; i<b; i+=c)
#define         read(a)        long long a; cin>>a
#define         reads(a)       string a; cin>>a
#define         rep(i,a,b)     for(ll i=a;i<b;i++)
#define         repr(i,a,b)    for(ll i=a;i>=b;i--)
#define         input(v,n)     vector <ll> v(n); rep(i,0,n) cin>>v[i];
#define         all(v)         v.begin(),v.end()
#define         allr(v)        v.begin(),v.end(),greater<ll>()
#define         tr(it,a)       for(auto it = a.begin(); it != a.end(); it++)
#define         prnt(a)        cout<<a<<endl
#define         PI             3.1415926535897932384626
#define         setbits(x)     __builtin_popcountll(x)
//_______________________________________________________________________
const  int MOD = 1e9 +7;
const int N = 200005;
                       
char upper(char c){ // check upper char isupper(x) 
return 'A'+(c-'a');
    }
                   
char lower(char c){  // check upper char islower(x), 
   return 'a'+(c-'A');
   }
          
 
ll factorial(ll n)
{
if (n == 0)
return 1;
return (n * factorial(n - 1));
}
 
bool is_palindrom_number(ll n)
{
ll num, digit, rev = 0;
num = n;
while (num != 0)
{
digit = num % 10;
rev = (rev * 10) + digit;
num /= 10;
}
return (num == n ? true : false);
}
int facto(int n){if (n <= 1)return 1;return n * facto(n - 1);}int nPr(int n, int r){return facto(n) / facto(n - r);}
int fact(int n);int nCr(int n, int r){return fact(n) / (fact(r) * fact(n - r));}int fact(int n){int res = 1;for (int i = 2; i <= n; i++)res = res * i;return res;}
bool isPrime(ll n){if (n < 2)return false;for (ll i = 2; i * i <= n; i++)if (n % i == 0)return false;return true;}
void SieveOfEratosthenes(int n)
{
 bool prime[n+1];
    memset(prime, true, sizeof(prime));
prime[0]=prime[1]=false;
for (int p = 2; p * p <= n; p++)
{
if (prime[p] == true)
{
for (int i = p * p; i <= n; i += p)
prime[i] = false;
}
}
}
 
bool isPalindrome(string str)
{
int l = 0;
int h = str.length() - 1;
while (h > l)
{
if (str[l++] != str[h--])
{
return false;
}
}
return true;
}
 
ll power(ll base,ll ex,ll N=MOD){
if(base == 0)
return 0;
if(ex == 0)
return 1;
ll y;
if((ex & 1) == 0){
y = power(base,ex/2);
y = (y * y) % N;
}
else{
y = base % N;
y = (y * power(base,ex-1) % N) % N;
           }
return (y+N)%N;
      }
 
int gcdExtended(int a, int b, int *x, int *y)
{
if (a == 0)
{
*x = 0;
*y = 1;
return b;
    }
int x1, y1;
int gcd = gcdExtended(b%a, a, &x1, &y1);
*x = y1 - (b/a) * x1;
*y = x1;
return gcd;
}
 
long long lcm(int a, int b)
{
return (a / __gcd(a, b)) * b;
}
//ll a=0,b=0,c=0,d=0,e=0,f=0,g=0,h=0,i=0,j=0,k=0,l=0,m=0,n=0,o=0,p=0,q=0,r=0,s=0,t=0,u=0,v=0,w=0,x=0,y=0,z=0;
/*void findMissing(int a[], int b[],int n, int m)
{
for (int i = 0; i < n; i++)
{
int j;
for (j = 0; j < m; j++)
if (a[i] == b[j])
break;
if (j == m)
cout << a[i] <<endl;
}
}*/
//_______________________________________________________________________
void solve(){
        read(n);
        input(v,n);
        sort(all(v));
        rep(i,0,n/2){ 
            cout<<v[n-1]<<" "<<v[i]<<"\n";
        }
 }
 
signed main(){
         fastI_O;
          read(tt);
           while(tt--){
              solve();
           }      
}
















