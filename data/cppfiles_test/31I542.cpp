//BISMILAHIRAHMANIR RAHIM
#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define int               long long int
#define endl        "\n"
#define pb                push_back
#define ppb               pop_back
#define pf                push_front
#define ppf               pop_front
#define all(x)            (x).begin(),(x).end()
#define allr(x)       (x).rbegin(),(x).rend()
#define uniq(v)           (v).erase(unique(all(v)),(v).end())
#define sz(x)             (int)((x).size())
#define fr                first
#define sc                second
#define pii               pair<int,int>
#define loop(i,a,b)        for(int i=a;i<b;i++)
#define mem1(a)           memset(a,-1,sizeof(a))
#define mem0(a)           memset(a,0,sizeof(a))
#define ppc               __builtin_popcount
#define ppcll             __builtin_popcountll
#define br                break
#define con               continue


// typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
template<typename T1,typename T2>istream& operator>>(istream& in,pair<T1,T2> &a){in>>a.fr>>a.sc;return in;}
template<typename T1,typename T2>ostream& operator<<(ostream& out,pair<T1,T2> a){out<<a.fr<<" "<<a.sc;return out;}
template<typename T,typename T1>T amax(T &a,T1 b){if(b>a)a=b;return a;}
template<typename T,typename T1>T amin(T &a,T1 b){if(b<a)a=b;return a;}
template <typename T> using ordered_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
const long long INF=1e18;
const int32_t M=1e9+7;
const int32_t MM=998244353;
 
// priority_queue<pii, vector<pii>, greater<pii> >q;
const int mx = 2e5+5;
int phi[1000000];
int mark[1000000];
vector<int>prime;
const int N = 10000;
int lp[10005];
vector<int> pr;
int bigmod(int base,int power,int mod){
 int res =1;
 while(power>0){
     if(power%2) res = ((res%mod) * (base%mod))%mod;
 
     base = ((base%mod)*(base%mod))%mod;
     power/=2;
 }
 return res;
}

void euler_phi(){
 for(int i=1;i<=mx;i++)phi[i]=i;
 for(int i=2;i<=mx;i++){
     if(phi[i]==i){
         phi[i]=i-1;
         for(int j=i;j<=mx;j+=i)phi[j]=(phi[j]/i)*(i-1);
     }
 }
}


void linear_seive(){
 
 for (int i=2; i<=N; ++i) {
     if (lp[i] == 0) {
         lp[i] = i;
         pr.push_back (i);
     }
     for (int j=0; j<(int)pr.size() && pr[j]<=lp[i] && i*pr[j]<=N; ++j)
         lp[i * pr[j]] = pr[j];
 }
}


void seive(){
 for(int i=2;i<=mx;i++){
     if(mark[i]==0){
         prime.pb(i);
         for(int j=i+i;j<=mx;j+=i)mark[j]=1;
     }
 }
}



signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output1.txt","w",stdout);
    #endif

    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;

        int a[n+1];
        for(int i=1;i<=n;i++)cin>>a[i];

        if(n%2){
            if(a[1]+a[2]!=0){
                cout<<-a[3]<<" "<<-a[3]<<" "<<a[1]+a[2]<<" ";
            }else if(a[1]+a[3]!=0){
                cout<<-a[2]<<" "<<a[1]+a[3]<<" "<<-a[2]<<" ";
            }else cout<<a[2]+a[3]<<" "<<-a[1]<<" "<<-a[1]<<" ";

            for(int i=4;i+1<=n;i++)cout<<-a[i+1]<<" "<<a[i]<<" ";
            cout<<endl;
        }
        else{
            for(int i=1;i+1<=n;i++)cout<<-a[i+1]<<" "<<a[i]<<" ";
            cout<<endl;
        }

    }

    


    
    
}
///ALHAMDULILLAH//