  // TUMHARE BAAP KA CODE HAI
#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define max3(a,b,c) max(a,max(b,c))
#define min3(a,b,c) min(a,min(b,c))
#define lcm(a,b) ((a*b)/(__gcd(a,b)))
#define rep(i,n) for(ll i=0;i<n;i++)
#define REP(i,z,n) for(ll i=z; i<=n; i++)
#define MM 1000000007
using namespace std;
 
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
  
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
 
 
 
 ull binpow(ull x, ull y)
{
    if(y==0)
    {
        return 1;
    }
    ull temp=binpow(x,y/2);
    temp=temp*temp;
    if(y%2!=0)
    {
        temp=x*temp;
    }
    return temp;
} 
ll search(vector<ll> &v,ll a,ll n){
    ll begin=0,end=n-1;
    while(begin<=end){
        ll mid=(begin+end)/2;
        if(v[mid]==a)
        {
            if(mid==n-1)
            return 1e12;
            else return v[mid+1]; 
        }else if(v[mid]<a)
        {
            begin=mid+1;
        }else
        end=mid-1;
    }
    return 1;
}
 
 
int mini(vector<int> &v,int i){
    int index =-1;ll min=1e12;
    for(int j=i;j<v.size();j++){
        if(v[j]<min){
            min=v[j];
            index=j;
        }
    }
        return index;
}
 
 
void solve(){
    ll n,k;
    cin>>n;
    ll b[n];
    ull sum=0;
    rep(i , n){
        cin>>b[i];
        sum+=b[i];
    }
    ll cal=(n*(n+1))/2;
    ll correct[n];
    ll ques=sum/cal;
    if(sum%cal==0 && sum/cal>=n){
        rep(i , n){
            if(i==0){
                ll res=(b[n-1]-b[0]+ques)/n;
                if((b[n-1]-b[0]+ques)%n!=0){
                    cout<<"NO"<<endl;
                    return;
                }
                correct[i]=res;
                continue;
            }
            else {
               ll res=(b[i-1]-b[i]+ques)/n;
               if((b[i-1]-b[i]+ques)%n!=0 || res<=0){
                    cout<<"NO"<<endl;
                    return;
                }
                correct[i]=res;
            }
            }
            cout<<"YES"<<endl;
            rep(i , n){
                cout<<correct[i]<<" ";
            }
            cout<<endl;
            return;
    }
    else{
        cout<<"NO"<<endl;
    }
}
 
 
int main()
   {
ios::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
int testcase;
cin>>testcase;
while(testcase--){
          solve();
   }
cout<<endl;
cerr<<"time taken : "<<(float)clock()/CLOCKS_PER_SEC<<" secs"<<endl;
    return 0;
   }