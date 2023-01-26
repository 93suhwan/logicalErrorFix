#include<bits/stdc++.h>
using namespace std;
#define ll long long int 
#define ld long double
#define pb push_back
#define ss second
#define ff first 
#define ub upper_bound
#define lb lower_bound
ll mod=1000000007;
const ll inf=1000000000000000000;
long double pi=3.1415926535897932384626433832795;
#define all(X) (X).begin(),(X).end()
ll infn=-inf;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define os tree<ll, null_type,less<ll>, rb_tree_tag,tree_order_statistics_node_update>
#define osp tree<pair<ll,ll>, null_type,less<pair<ll,ll>>, rb_tree_tag,tree_order_statistics_node_update>
ll ncr(ll n,ll r){if(r>n)return 0;if(r > n - r) r = n - r;ll ans = 1;
ll i;for(i = 1; i <= r; i++){ans *= n - r + i;ans /= i;}return ans;}
ll power(ll x,ll n,ll m){if(n==0)return 1;else if(n%2==0)return (power(((x%m)*(x%m))%m,n/2,m))%m;else return ((x%m)*(power(x,n-1,m)%m))%m;}
ll dx[] = {1,-1,0,0}; 
ll dy[] = {0,0,1,-1};
ll modInverse(ll a,ll m){ll m0=m;ll y=0,x=1;if(m==1)return 0;while(a>1){ 
ll q=a/m;ll t=m;m=a%m,a=t;t=y;y=x-q*y;x=t;}if(x<0)x+=m0;return x;} 
string binary(ll n,ll k){
if(n==0){
string ans;
for(int i=1; i<=k; i++)
ans.pb('0');
return ans;
return "0";
}
string ans;
while(n>0){
if(n&1)
ans.pb('1');
else
ans.pb('0');
n=n>>1;
}
ll l=ans.length();
for(int j=1; j<=k-l; j++)
ans.pb('0');
reverse(ans.begin(),ans.end());
return ans;
}
bool is_prime(ll n){
if(n==1)
return 0;
for(ll i=2; i*i<=n; i++){
if(n%i==0)
return 0;
}
return 1;
}
ll sum_digit(ll n){
ll ans=0;
while(n>0){
ans+=(n%10);
n/=10;
}
return ans;
}
ll len_digit(ll n){
ll ans=0;
while(n>0){
ans+=1;
n/=10;
}
return ans;
}
ll to_decimal(string &str,ll k){
ll ans=0,d=1;
for(int i=str.length()-1; i>=0; i--){
ans+=d*(str[i]-48);
d*=k;
}
return ans;
}
ld round(ld var){
ld value = (ll)(var * 100 + .5);
return (ld)value / 100;
}


// HLD
// const ll h=200005;
// ll num[h];
// ll n;
// segtree s(h);
// vector<ll>adj[h];
// ll par[h][22];//stores 2^ith parent of every node
// ll level[h];//level[i] gives us distance from root node
// ll heavy[h];//heavy[i] gives us the heavy child of the node i
// ll chain[h];//chain[i] gives me the node at the top of the chain,initially every node points to itself
// ll label[h];//label[i] gives us the index in the segment tree
// void lca_init(){
// for(int i=1; i<=20; i++){
// for(int j=1; j<=n; j++){
// if(par[j][i-1]!=-1)
// par[j][i]=par[par[j][i-1]][i-1];
// else
// par[j][i]=-1;
// }
// }
// }
// ll get_lca(ll a,ll b){
// if(level[b]>level[a])
// swap(a,b);

// ll d=level[a]-level[b];

// for(int i=20; i>=0; i--){
// if((1<<i)&d)
// a=par[a][i];
// }

// if(a==b)
// return a;

// for(int i=20; i>=0; i--){
// if(par[a][i]!=-1&&par[a][i]!=par[b][i])
// a=par[a][i],b=par[b][i];
// }


// return par[a][0];

// }
// ll hld_dfs_size(ll n,ll p,ll l){
// par[n][0]=p;
// level[n]=l;
// ll hc=-1,f=-1,siz=1;
// for(int i=0; i<adj[n].size(); i++){
// if(adj[n][i]!=p){
// ll d=hld_dfs_size(adj[n][i],n,l+1);
// siz+=d;
// if(d>f){
// f=d;
// hc=adj[n][i];
// }
// }
// }
// heavy[n]=hc;
// return siz;
// }

// void hld_dfs_decompose(ll n,ll p){
// if(heavy[n]!=-1)
// chain[heavy[n]]=chain[n];
// for(int i=0; i<adj[n].size(); i++){
// if(adj[n][i]!=p)
// hld_dfs_decompose(adj[n][i],n);
// }
// }

// void hld_dfs_labels(ll n,ll p,ll &l){
// label[n]=l;
// //here you can inisialize your data-structure because now you have labels
// //depending on question
// s.update(l,1,1,h,num[n]);
// l+=1;
// if(heavy[n]!=-1){
// hld_dfs_labels(heavy[n],n,l);//going to heavy child first so that lables get in continuos manner of heavy chains
// }
// for(int i=0; i<adj[n].size(); i++){
// if(adj[n][i]!=p&&adj[n][i]!=heavy[n])
// hld_dfs_labels(adj[n][i],n,l);
// }
// }
// void hld_init(){ 
// for(int i=1; i<=n; i++)
// hld_dfs_size(1,-1,0);

// hld_dfs_decompose(1,-1);

// ll gg=1;
// hld_dfs_labels(1,-1,gg);

// lca_init();
// }
// ll get_kth_parent(ll n,ll k){
// for(int i=20; i>=0; i--){
// if((1<<i)&k)
// n=par[n][i];
// }
// return n;
// }
// ll hld_query(ll n,ll lca){
// //here lca is not included in answer
// ll ans=0;
// while(n!=-1&&level[n]>level[lca]){
// ll top=chain[n];
// if(level[top]<=level[lca]){
// ll diff=label[n]-label[lca]-1;
// top=get_kth_parent(n,diff);
// }
// // ans+=[label[top],label[n]] this is the range which you can find answer 
// //with the help of your data-structure
// ll l=label[top];
// ll r=label[n];
// //write the code for query

// ans=max(ans,s.query(l,r,1,h,1));

// n=par[top][0];
// }
// return ans;
// }
// void hld_lca_update(ll n,ll lca,ll x){
// //here lca is not updated
// while(n!=-1&&level[n]>level[lca]){
// ll top=chain[n];
// if(level[top]<=level[lca]){
// ll diff=label[n]-label[lca]-1;
// top=get_kth_parent(n,diff);
// }
// //[label[top],label[n]] this is the range which you can update with the help of your data-structure
// //write the update code

// }
// }
// void hld_point_update(ll n,ll x){
// ll index=label[n];
// s.update(index,1,1,h,x);
// }





//sqrt-decomposition


//CAUTION:think it like if we have some answers then how merging those answers gives us the actual answer
//eg- numnber of distinct elements from l to r in this it is very difficult to merge not as easy as in sum,min,max

//KEY-IDEA
//divide the whole array into sqrt(n) blocks each of size sqrt(n) store the answer for each block so that it 
// can use in future also good for updates for sum o(1) just sqrt[i/block]-=num[x]+y be carefull in min,max
//  update in O(sqrt(n)) as we have to traverse in the whole block 

//implementation detail for sqrt
//block is actually block_size


// l,r is the query range


// for(int i=l; i<=r; ){
// if(i%block==0&&i+block-1<=r)
// ans=min(ans,sqrt[i/block]),i+=block;  //if the block is fully included in the query range
// else
// ans=min(ans,num[i]),i+=1;       //moving in the block if it don't include fully in query
// }

// block_index=i/block
// start_index_of_block=block_index*block
// end_index_of_block=start_index_of_block+block-1






//moss-algoritm

//CAUTION:NO UPDATES,OFFLINE QUERIES

//MAIN-LOGIC:Quite logicial,kind of common sense its actually maintain curr_l and curr_r as the 
//curr-range in which we know our answer then for the next query from l to r
//its takes curr_l to l and curr_r to r and changes the answer as required so its 
//efficiency is only depend on the movement of curr_l and curr_r 
//optimal when query are sorted asceding order of block_size(from sqrt decomposition) of l
//if ties then on the basis of r


//Time Complexity-O(N*SQRT(N)+Q*SQRT(N)) N*SQRT(N) due to the movement of cur_r
// Q*SQRT(N) is due to curr_l


// It uses sqrt decomposition only in its logic of sorting the queries,otherwise in the implementation part
//it is entirely different from sqrt decomposition. In sqrt decomposition we cannot efficiently find
//the number of distinct elements in the range of [l,r] but using moss we can find it
//in offline mode 



//IMPLEMENTATION:
//1.Sorting of queries
// struct kap{
// ll l,r,ind;
// };
// bool cmp(kap k1,kap k2){
// if(k1.l/block<k2.l/block)
// return 1;
// if(k1.l/block==k2.l/block){
// if(k1.r<k2.r)
// return 1;
// return 0;
// }
// return 0;
// }


//2.initialising curr_r,curr_l,ans
// const ll block=700;
// ll curr_l=-1,curr_r=-1,ans=0; //just for making implementation better

//3.add,remove functions
// void add(ll ind){
// if(ind==-1)
// return;
// freq[num[ind]]++;
// if(freq[num[ind]]==1)
// ans+=1;
// }
// void remove(ll ind){
// if(ind==-1)
// return;
// freq[num[ind]]-=1;
// if(freq[num[ind]]==0)
// ans-=1;
// }

//4.moving of curr_l and curr_r to reach l and r respectively

// while(curr_l>l){
// curr_l-=1;
// add(curr_l);
// }

// while(curr_r<r){
// curr_r+=1;
// add(curr_r);
// }

// while(curr_l<l){
// remove(curr_l);
// curr_l+=1;
// }

// while(curr_r>r){
// remove(curr_r);
// curr_r-=1;
// }













//TEMPLATE FOR QUERIES ON TREES

// const ll h=100005;
// ll par[h][22];
// vector<ll>adj[h];
// ll n; // number of nodes
// ll s[h],e[h],fft[2*h],level[h];
// void lca_init(){
// for(int i=1; i<=20; i++){
// for(int j=1; j<=n; j++){
// if(par[j][i-1]!=-1)
// par[j][i]=par[par[j][i-1]][i-1];
// else
// par[j][i]=-1;
// }
// }
// }
// ll get_lca(ll a,ll b){
// if(level[b]>level[a])
// swap(a,b);

// ll d=level[a]-level[b];

// for(int i=20; i>=0; i--){
// if((1<<i)&d)
// a=par[a][i];
// }

// if(a==b)
// return a;

// for(int i=20; i>=0; i--){
// if(par[a][i]!=-1&&par[a][i]!=par[b][i])
// a=par[a][i],b=par[b][i];
// }


// return par[a][0];

// }
// void dfs(ll n,ll p,ll &timer,ll l){
// par[n][0]=p;
// s[n]=timer;
// level[n]=l;
// fft[timer]=n;
// timer+=1;
// for(int i=0; i<adj[n].size(); i++){
// if(adj[n][i]!=p)
// dfs(adj[n][i],n,timer,l+1);
// }
// e[n]=timer;
// fft[timer]=n;
// timer+=1;
// }


//sieve
// const ll h=1000000;
// ll prime[h+1];
// prime[1]=0;
// for(int i=2; i<=h; i++){
// prime[i]=i;
// }
// for(ll i=2; i*i<=h; i++){
// if(prime[i]==i){
// for(ll j=i*i; j<=h; j+=i){
// if(prime[j]==j)
// prime[j]=i;
// }
// }
// }

//fact
// const ll h=1000000;
// ll fact[h+1];
// fact[0]=1;
// for(int i=1; i<=h; i++){
// fact[i]=(i*fact[i-1])%mod;
// }


//binary-search on the time
// use 100 interations 
//use l=mid,r=mid not l=mid+1 and r=mid-1
// not use == sign use >= or <=


class sptable{
vector<vector<ll>>dp; // as 2^20>20000
vector<ll>num;
vector<ll>log_sp;//log_sp[i]=maximum value of such that 2^log_sp[i]<=i(use for answering queries for impodent functions in O(1))
public:
sptable(ll jum[],ll n){
for(int i=0; i<n; i++)
num.pb(jum[i]);
log_sp.assign(n+1,0);
dp.assign(n,vector<ll>(20,0));
build(n);
}
void build(ll n){
log_sp[1]=0;
for(int i=2; i<=n; i++)
log_sp[i]=log_sp[i/2]+1;//beautiful hack
for(int i=0; i<n; i++)
dp[i][0]=num[i];  //as individual elements are answer of themselves
//calculate from each index the answer of each 2^i power it is the same concept use in binary lifting
for(int j=1; j<20; j++){
for(int i=0; i+(1<<j)-1<n; i++){ //as we are finding answer from i to i+(1<<j)-1 so we find the value of l for that such thar r should be less than n
dp[i][j]=__gcd(dp[i][j-1],dp[i+(1<<(j-1))][j-1]);//here we have apply function like gcd in our case
}
}
}
ll query(ll l,ll r){
//we can represent any number in the powers of 2 and we have calculated the answer the answer from l to r so we represent the length in terms of it and just move same as we do in binary lifting
// per query-O(log2(r-l+1)*cost_of_operation)
 
 
//if function is non-impodent eg-sum
 
 
// ll k=r-l+1;
// ll ans=0;
// for(int i=19; i>=0; i--){
 
// if(((1<<i)&k)>0)
// ans=__gcd(ans,dp[l][i]),l+=(1<<i);
 
// }
 
// return ans;
 
 
 
// there is one catch for the functions that are impodent that is fun(A,A)=A that we don't care if the range merges so we don't need disjoint ranges eg- gcd,min,max,AND,OR   (not-eg-sum)
//per query-O(cost_of_operation) if we precompute log[i] values
 
ll d=log_sp[r-l+1];
 
// [l,l+(1<<d)] [r-(1<<d)+1,r]
 
return __gcd(dp[l][d],dp[r-(1<<d)+1][d]);  //return the function value
 
}
};
class dsu{
public:
vector<ll>par,size;
dsu(ll n){
par.assign(n+1,0);
size.assign(n+1,0);
for(int i=1; i<=n; i++){
par[i]=i;
size[i]=1;
}
}
ll find(ll n){
if(par[n]==n)
return n;
ll p=find(par[n]);
par[n]=p;
return p;
}
void merge(ll a,ll b){
a=find(a);
b=find(b);
if(a==b)
return;
if(size[b]>size[a])
swap(a,b);
size[a]+=size[b];
par[b]=a;
}
ll siz(ll n){
return size[n];
}
};
ll inversion_count(vector<ll>&vec){
osp s;
ll ans=0;
for(int i=vec.size()-1; i>=0; i--){
ll d=s.order_of_key({vec[i],infn});
ans+=d;
s.insert({vec[i],s.size()});
}
return ans;
}
class segtreel{
public:
vector<ll>seg,lazy;
segtreel(ll n){
seg.assign(4*n,0);
lazy.assign(4*n,0);
// build(1,1,n);
}
// void build(ll ind,ll l,ll r){
// if(l==r){
// seg[ind]=;
// return;
// }
// ll mid=(l+r)/2;
// build(2*ind,l,mid);
// build((2*ind)+1,mid+1,r);
// seg[ind]=inf;
// }
 
void push_down(ll ind,ll l,ll r){
seg[ind]=(r-l+1)*lazy[ind]+seg[ind];
if(l!=r)
lazy[2*ind]+=lazy[ind],lazy[2*ind+1]+=lazy[ind];
lazy[ind]=0;
}
 
void set_value(ll ind,ll val,ll l,ll r){
seg[ind]=(r-l+1)*val+seg[ind];
if(l!=r)
lazy[2*ind]+=val,lazy[2*ind+1]+=val;
}
 
ll query(ll ql,ll qr,ll l,ll r,ll ind){
 
push_down(ind,l,r);
 
if(ql<=l&&qr>=r)
return seg[ind];
if(ql>r||qr<l)
return 0;
ll mid=(l+r)/2;
ll k1=query(ql,qr,l,mid,2*ind);
ll k2=query(ql,qr,mid+1,r,(2*ind)+1);
return k1+k2;
}
void update(ll ql,ll qr,ll ind,ll l,ll r,ll val){
push_down(ind,l,r);
if(ql<=l&&qr>=r){
set_value(ind,val,l,r);
return;
}
if(ql>r||qr<l)
return;
ll mid=(l+r)/2;
update(ql,qr,2*ind,l,mid,val);
update(ql,qr,2*ind+1,mid+1,r,val);
seg[ind]=seg[2*ind]+seg[(2*ind)+1];
}
};
class segtree{
public:
vector<ll>seg;
segtree(ll n){
seg.assign(4*n,0);
build(1,1,n);
}
void build(ll ind,ll l,ll r){
if(l==r){
seg[ind]=0;
return;
}
ll mid=(l+r)/2;
build(2*ind,l,mid);
build((2*ind)+1,mid+1,r);
seg[ind]=seg[2*ind]+seg[(2*ind)+1];
}
ll query(ll ql,ll qr,ll l,ll r,ll ind){
if(ql<=l&&qr>=r)
return seg[ind];
if(ql>r||qr<l)
return 0;
ll mid=(l+r)/2;
ll k1=query(ql,qr,l,mid,2*ind);
ll k2=query(ql,qr,mid+1,r,(2*ind)+1);
return k1+k2;
}
void update(ll q,ll ind,ll l,ll r,ll val){
if(l==r){
seg[ind]+=val;
return;
}
if(q>r||q<l)
return;
ll mid=(l+r)/2;
if(mid>=q)
update(q,2*ind,l,mid,val);
else
update(q,(2*ind)+1,mid+1,r,val);
seg[ind]=seg[2*ind]+seg[(2*ind)+1];
}
};
int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL),cout.tie(NULL);
cout.precision(10);
cout<<fixed;
// std::rotate(vis.begin(), vis.begin()+rotL, vis.end());//rotl=no of left ro
// std::rotate(vis.begin(), vis.begin()+vis.size()-rotR, vis.end());
//transform(str.begin(),str.end(),str.begin(),::tolower);//also "toupper"
// to_string(ll),stoll(string)
//  priority_queue <T, vector<T>, greater<T> > pq;
// __builtin_popcountll()
//cout<<setprecision(15)<<fixed;



// IMPROVEMENT IS JUST A MYTH 
// -Kapeesh Upadhyay
 
 
 
// There are 2 ways to win a race one is the put urself up and second is to put others down
// --Kapeesh Upadhyay
 
 
 
// cg is the criteria of rejection,not selection
// --Kapeesh Upadhyay
 
 
 
// what i think is that never thinks positive because "excitement leads to disappointment"(a very famous quote)
 


// freopen("input.txt","r",stdin);
// freopen("output.txt","w",stdout);




ll t,n,m;
string str;
cin>>t;
while(t--){
cin>>n>>m>>str;
n-=1,m-=1;
ll x=0,y=0,l,r,l1=0,d1=0,f=0;
for(int i=0; i<str.length(); i++){



if(str[i]=='L')
x-=1;
if(str[i]=='R')
x+=1;
if(str[i]=='D')
y-=1;
if(str[i]=='U')
y+=1;

if(x<=0)
l1=max(l1,abs(x));
if(y<=0)
d1=max(d1,abs(y));
// cout<<x<<" "<<y<<"\n";
 if(abs(y)<=n&&abs(x)<=m){
// cout<<l1<<" "<<d1<<"\n";
f+=1;
l=l1;
r=d1;
// cout<<l<<" "<<r<<"\n";
}else{
break;
}

}
// cout<<r<<" ";
if(f==0){
cout<<"1 1\n";
continue;
}

cout<<n+1-r<<" "<<l+1<<"\n";

}






return 0;
}