
#include <ext/pb_ds/assoc_container.hpp>
#include<bits/stdc++.h>
 
using namespace std;
using namespace __gnu_pbds;
 
#define ff              first
#define ss              second
#define int             long long
#define pb              push_back
#define mp              make_pair
#define mt              make_tuple
#define pii             pair<int,int>
#define vi              vector<int>
#define mii             map<int,int>
#define pqb             priority_queue<int>
#define pqs             priority_queue<int,vi,greater<int> >
#define setbits(x)      __builtin_popcountll(x)
#define MOD             1000000007
#define inf             1e18
#define range(a,b)        substr(a,b-a+1)
#define w(t)            int t; cin>>t; while(t--)
#define trace(x)         cerr<<#x<<": "<<x<<" "<<endl;
#define FIO             ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define endl "\n"
 
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
int mod_add(int a, int b, int m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
int mod_mul(int a, int b, int m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
int expo(int a, int b, int mod) {int res = 1; while (b > 0) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1;} return res;}
vector<int> sieve(int n) {int*arr = new int[n + 1](); vector<int> vect; for (int i = 2; i <= n; i++)if (arr[i] == 0) {vect.push_back(i); for (int j = 2 * i; j <= n; j += i)arr[j] = 1;} return vect;}
bool isPrime(int n) 
{ 
    if (n <= 1)  return false; 
    if (n <= 3)  return true; 
  
    if (n%2 == 0 || n%3 == 0) return false; 
  
    for (int i=5; i*i<=n; i=i+6) 
        if (n%i == 0 || n%(i+2) == 0) 
           return false; 
  
    return true; 
} 
 

 
 
 void solve(){
   
   string s;
   cin>>s;
   
   int cnt[2] = {0};
   
   if(s[0] == '?')cnt[1] = 1;
   for(int i=1;i<=10;i++){
      
      if(i == 1 && s[i-1] == '?')continue;
      
       if(s[i - 1] == '?'){
           
           if(i%2)
           {
               if(cnt[1] > cnt[0])cnt[1]++;
           }
           else
           {
               if(cnt[0] > cnt[1])cnt[0]++;
           }
       }
       
       else if(s[i - 1] != '?') {
           cnt[i%2] += (s[i - 1] - '0');
       }
       
       
       int left = 10 - i;
       
       if(i%2){
           int c1 = cnt[1];
           int c2 = cnt[0];
           
           if(c1 > c2){
              int diff = c1 - c2;
              
              if(c1 > c2 + (left)/2 + 1){
                  cout<<i<<endl;
                  return;
              }
           }
           else{
               
               int diff = c2 - c1;
               
              if(c2 > c1 + left/2){
                  cout<<i<<endl;
                  return;
              }
               
               
           }
          
       }
       else{
           
           
           int c1 = cnt[1];
           int c2 = cnt[0];
           
           if(c1 > c2){
              int diff = c1 - c2;
              if(c1 > c2 + (left)/2){
                  cout<<i<<endl;
                  return;
              }
           }
           else{
              int diff = c2 - c1;
              if(c2 > c1 + left/2){
                  cout<<i<<endl;
                  return;
              }
           }
       }
       
       
   }
   
   cout<<10<<endl;
   
   
}

 
int32_t main()
{
FIO;
 
 
w(t){
solve();
}
 
 
return 0;
}