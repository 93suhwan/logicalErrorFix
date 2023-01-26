#include <bits/stdc++.h>
using namespace std;
#define PI 3.14159265358979323846
//#define ll long long int
#define int long long int 

 /* vector<int> t,arr;*/
  int k=998244353;
/*
 int combine(int x,int y)
 {
    int p=x+y;
    p%=k;
    return p;
 }
void build(int v, int tl, int tr) {
    if (tl == tr) {
        t[v] = arr[tl];
    } else {
        int tm = (tl + tr) / 2;
        build( v*2, tl, tm);
        build( v*2+1, tm+1, tr);
        t[v] =combine( t[v*2] , t[v*2+1]);
    }
}
 
int query(int v, int tl, int tr, int l, int r) {
    if (l > r) 
        return 0;
    if (l == tl && r == tr) {
        return t[v];
    }
    int tm = (tl + tr) / 2;
    return combine(query(v*2, tl, tm, l, min(r, tm)),
           query(v*2+1, tm+1, tr, max(l, tm+1), r));
}
void update_one(int v, int tl, int tr, int pos, int newVal){
        if(tl==tr){
            t[v] = newVal;
            // check whether the newVal is added or updated
            return;
        }
        int mid=(tl+tr)/2;
        if(pos<=mid)    update_one(2*v,tl,mid,pos,newVal);
        else    update_one(2*v+1,mid+1,tr,pos,newVal);
        t[v] = combine( t[2*v] , t[2*v+1] );
    }

    */


int power(int x,int y)
{
    int res = 1; // Initialize result
 
    x = x % k; // Update x if it is more than or
    // equal to p
 
    while (y > 0)
    {
 
        // If y is odd, multiply x with result
        if (y & 1)
            res = (res * x) % k;
 
        // y must be even now
        y = y >> 1; // y = y/2
        x = (x * x) %k;
    }
    return res;
}
 main(){
   
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

   int test = 1;
   cin>>test;


   while(test--){
            
               int n;
               cin>>n;

             //  t.resize(4LL*n+10,0);
               
               int a[n];
               vector<int> dp(n+3,0);
               for(int i=0;i<n;i++)
                cin>>a[i]; 

            

               int ans=0;
              for(int i=0;i<n;i++){
                 

               //  cout<<dp[a[i]].first<<" "<<dp[a[i]].second<<"\n";

                
               // dp[a[i]+1]+=dp[a[i]];
               // dp[a[i]+1]%=k;

                dp[a[i]+1]+=dp[a[i]+1]%k;
                  dp[a[i]+1]%=k;
                
                if(a[i]>0){
                dp[a[i]-1]+=dp[a[i]-1]%k;
                    dp[a[i]-1]%=k;

                }

                                         dp[a[i]+1]+=dp[a[i]];
                        dp[a[i]+1]%=k;

                

                
                        if(a[i]==0 || a[i]==1){
                            dp[1-a[i]]++;
                            dp[1-a[i]]%=k;
                                                    }

                                                    
                            

                   









                 /* dp[a[i]].first+=dp[a[i]].first;
                   dp[a[i]].first%=k;
                    if(a[i]==0)
                    dp[a[i]].first++,dp[a[i]].first%=k;
                     
                  if(a[i]>0){
                  dp[a[i]].first+=dp[a[i]-1].first;
                  dp[a[i]].first%=k;
              }

                 dp[a[i]].second+=dp[a[i]].second;
                  dp[a[i]].second%=k;
                  
                  if(a[i]>1){
                  dp[a[i]].second+=dp[a[i]-2].first;
                     dp[a[i]].second%=k;  
              }

              int y=query(0,0,n+1,a[i]+1,n+1)%k;
                cout<<dp[a[i]].first<<" "<<dp[a[i]].second<<" "<<y<<"\n";

                 dp[a[i]].first+=y;
                  dp[a[i]].first%=k;
           
              int temp=0;
               temp+=dp[a[i]].first;
                  temp%=k;
                  temp+=dp[a[i]].second;
                  temp%=k;

                  update_one(0,0,n+1,a[i],temp);

                  


                  ans+=dp[a[i]].first;
                  ans%=k;
                  ans+=dp[a[i]].second;
                  ans%=k;
                 // ans+=y;
                  ans%=k;*/
              }

             
            for(int i=0;i<=n+2;i++){

              ans+=dp[i];
              ans%=k;

          }

              cout<<ans;




             cout<<"\n";













                    
   }
    //return 0;
}