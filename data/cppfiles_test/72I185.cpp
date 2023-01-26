#include <bits/stdc++.h>
#include <fstream>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp>
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define xx first
#define yy second
#define mt make_tuple
const int BS=500;
using namespace std;
//using namespace __gnu_pbds;
#define be begin()
#define rb rbegin()
#define all(v) v.begin(),v.end() 
#define rep(i,start,lim) for(long long (i)=(start);i<(lim);i++)
#define nod int node,int l,int r
#define lson node*2,l,(l+r)/2
#define rson node*2+1,(l+r)/2+1,r
typedef long long ll;
typedef long double ld;
//typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> rbTree;
const ll inf= 1e9+400;
ll mod= 998244353;
const ll mxn= (1e5+10);
const int N= 1e6+5;
const double pi=3.141592653589793238;
#define mp make_pair
#define mp3(a,b,c) mp(a,mp(b,c))
typedef pair<int,int> pii;
typedef pair<int,pair<int,int> > piii;
typedef pair<ll, int> pli;
typedef pair<ll,ll> pll;
typedef pair<ll,pair<ll,ll> > plll;
int dx[]={0,1,0,-1,1,-1,1,-1};
int dy[]={1,0,-1,0,-1,1,1,-1};
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll n,m,k,q,x,y,z,w,x_,y_,z_,type;
const int H = 18;
int a[mxn], vis[10];
int get(){
    for(int i=0;i<10;i++) if(!vis[i]) { vis[i]=1; return i; }
    return -1;
}
int get(int x){
    for(int i=x+1;i<10;i++) if(vis[i]) return i;
    return -1;
}
int get_(){
    for(int i=0;i<10;i++) if(vis[i]) return i;
    return -1;
}
int get__(){
    for(int i=0;i<10;i++) if(!vis[i]) return i;
    return -1;
}
int pow(int num ,int to){
    int x=1;
    while(to--) x*=num;
    return x;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);  
    cin>>q;
    while(q--){ 
        cin>>n>>k;
        int len = 0;
        int n_=n;
        vector<int> digits;
        fill(vis, vis+10, 0);
        while(n_>0) digits.pb(n_%10), n_/=10, len++;
        if(len<k){
            // need more places anyway
            cout<<n<<endl;
        }
        else{
            reverse(all(digits));
            for(int i=0;i<len;i++) vis[digits[i]]=1;
            int cnt = accumulate(vis, vis+10, 0);
            for(int i=0;i<10;i++) vis[i]=0;
            int ans=inf, pre=0, prev=0;
            if(cnt<=k){
                cout<<n<<endl;
                continue;
            }
        //    It is always possible to make a number with existing conditions now
            for(int i=1;i<=len;i++){
                int dig = digits[i-1];
                int vis_[10];
                for(int i=0;i<10;i++) vis_[i]=vis[i];
                int nxt = get(dig);
                int nxtDig = (pre+1<=k?dig+1:nxt==-1?dig:nxt);
                int pre_=pre+(pre+1<=k?(vis[dig+1]==0?(vis[dig+1]=1):0):(nxt!=-1?0:(vis[dig]=1)));
                int curAns = (1LL*pow(10,len-i)*(nxtDig))+prev;
                if(pre_>k||dig==9) goto end;
                for(int j=i+1;j<=len;j++){
                    if(pre_<k){
                        int visited = get_(), unvisited = get__();
                        if(unvisited<visited) curAns+=pow(10, len-j)*get(), pre_++;
                        else curAns+=pow(10,len-j)*visited;
                    }
                    else curAns+=pow(10, len-j)*get_();
                    //cout<<curAns<<endl;
                }
                ans=min(ans, curAns);
                end:
                swap(vis_, vis);
                pre+=(vis[dig]==0?1:0);
                vis[dig]=1;
                prev+=pow(10, len-i)*dig;
            }
            cout<<ans<<endl;
        }
    }
}
