         #include<bits/stdc++.h>
         using namespace std;
 
         #define ios ios_base::sync_with_stdio(false);cin.tie(NULL);
         #define ll long long int
         #define max3(a,b,c) max(max((a),(b)),(c))
         #define max4(a,b,c,d) max(max((a),(b)),max((c),(d)))
         #define min3(a,b,c) min(min((a),(b)),(c))
         #define min4(a,b,c,d) min(min((a),(b)),min((c),(d)))
   
         #define all(v) v.begin(),v.end()
         #define rall(v) v.rbegin(),v.rend()
         typedef pair<int,int> pii;
         typedef pair<ll,ll> pll;
         
         //PBDS
         // #include <ext/pb_ds/assoc_container.hpp>
         // #include <ext/pb_ds/tree_policy.hpp>
         // using namespace __gnu_pbds;
         // template<typename T>
         // using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
         
         #define fbo find_by_order
         #define ook order_of_key
         const long double PI = 3.14159265358979323846264338;
         const long long INF = 1000000000000000000;
         const long long INF1 = 1000000000;
         const long long MOD = 1000000007;
      
         ll _pow(ll a,ll b){
         if(!b)
            return 1;
         ll temp = _pow(a, b/2);
         temp = (temp * temp)%MOD;
         // In case of larger powers MOD can be added here.
            if(b%2)
         return (a * temp)%MOD;
         return temp;
         } 
         int inv(int x , int cnt){return _pow(x , cnt-2); }

         vector<ll> fact(1002,1) , ifact(1002,1);
         void calc(){
            for(int i = 1 ; i<1002 ; i++)fact[i] = (fact[i-1]*i)%MOD;
            for(int i = 1 ; i<1002 ; i++)ifact[i] = inv(fact[i],MOD);
    
         }
         int npr(int n , int r){
            if(r>n)return 0;
            return (fact[n]*ifact[n-r])%MOD;

         }
         int ncr(int n , int r){
           if(r>n)return 0;
           return (npr(n,r)*ifact[r])%MOD;
         }
         
         int gcd(int a , int b){return __gcd(a,b);}
         int lcm(int a , int b){return (a/gcd(a,b))*b;}
        
        
        void solve(){
           int n,m;
           cin>>n>>m;
           int dp[n+2]={};
           int pref[n+2]={};
           dp[n] = 1;
           pref[n] = dp[n];
           for(int i=n-1;i>=1;i--){
             dp[i]+=pref[i+1];
             dp[i]%=m;
             int j = 2;
             while(i*j<=n){
               int mn = min(i*j+j-1,n);
               dp[i]+=(pref[i*j]-pref[mn+1]);
               dp[i]%=m;
               j++;
             }
             pref[i] = pref[i+1]+dp[i];
             pref[i]%=m;
           }
           cout<<(dp[1]+m)%m;
         

           
        }
           
        
              
         signed main(){
            ios
      #ifndef ONLINE_JUDGE
      // for getting input from input.txt
      // freopen("input.txt", "r", stdin);
      // freopen("output.txt" , "w" , stdout);
      #endif
     
        int t;
        t=1;
        while(t--){
          solve();
        
   }
         }