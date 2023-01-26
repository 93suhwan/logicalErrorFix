#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define ALL(v) (v).begin(),(v).end()
using ll=long long int;
const int inf = 0x3fffffff; const ll INF = 0x1fffffffffffffff; const double eps=1e-12;
template<typename T>inline bool chmax(T& a,T b){if(a<b){a=b;return 1;}return 0;}
template<typename T>inline bool chmin(T& a,T b){if(a>b){a=b;return 1;}return 0;}

template<int mod=1000000007>struct fp {
   int v; static int get_mod(){return mod;}
   int inv() const{
      int tmp,a=v,b=mod,x=1,y=0;
      while(b)tmp=a/b,a-=tmp*b,swap(a,b),x-=tmp*y,swap(x,y);
      if(x<0){x+=mod;} return x;
   }
   fp(ll x=0){init(x%mod+mod);}
   fp& init(int x){v=(x<mod?x:x-mod); return *this;}
   fp operator-()const{return fp()-*this;}
   fp pow(ll t){fp res=1,b=*this; while(t){if(t&1)res*=b;b*=b;t>>=1;} return res;}
   fp& operator+=(const fp& x){return init(v+x.v);}
   fp& operator-=(const fp& x){return init(v+mod-x.v);}
   fp& operator*=(const fp& x){v=ll(v)*x.v%mod; return *this;}
   fp& operator/=(const fp& x){v=ll(v)*x.inv()%mod; return *this;}
   fp operator+(const fp& x)const{return fp(*this)+=x;}
   fp operator-(const fp& x)const{return fp(*this)-=x;}
   fp operator*(const fp& x)const{return fp(*this)*=x;}
   fp operator/(const fp& x)const{return fp(*this)/=x;}
   bool operator==(const fp& x)const{return v==x.v;}
   bool operator!=(const fp& x)const{return v!=x.v;}
}; using Fp=fp<>;
template<typename T>struct factorial {
   vector<T> Fact,Finv,Inv;
   factorial(int maxx){
      Fact.resize(maxx); Finv.resize(maxx); Inv.resize(maxx);
      Fact[0]=Fact[1]=Finv[0]=Finv[1]=Inv[1]=1;
      rep(i,2,maxx){Fact[i]=Fact[i-1]*i;} Finv[maxx-1]=Fact[maxx-1].inv();
      for(int i=maxx-1;i>=2;i--){Finv[i-1]=Finv[i]*i; Inv[i]=Finv[i]*Fact[i-1];}
   }
   T fact(int n,bool inv=0){if(n<0)return 0; return (inv?Finv[n]:Fact[n]);}
   T inv(int n){if(n<0)return 0; return Inv[n];}
   T nPr(int n,int r,bool inv=0){if(n<0||n<r||r<0)return 0; return fact(n,inv)*fact(n-r,inv^1);}
   T nCr(int n,int r,bool inv=0){if(n<0||n<r||r<0)return 0; return fact(n,inv)*fact(r,inv^1)*fact(n-r,inv^1);}
   T nHr(int n,int r,bool inv=0){return nCr(n+r-1,r,inv);}
};

template<typename T>struct BIT{
   int n; T all=0; vector<T> val;
   BIT(int _n):n(_n),val(_n+10){}
   void clear(){val.assign(n+10,0); all=T();}
   void add(int i,T x){
      for(i++;i<=n;i+=(i&-i))val[i]+=x;
      all+=x;
   }
   T sum(int i){
      T res=0;
      for(i++;i;i-=(i&-i))res+=val[i];
      return res;
   }
};

class CentroidDecomposition{
   void get(int v,int p){
      sz[v]=1;
      for(auto& to:g[v])if(to!=p and !used[to]){
         get(to,v);
         sz[v]+=sz[to];
      }
   }
   int dfs(int v,int p,int rt){
      for(auto& to:g[v])if(to!=p and !used[to]){
         if(sz[to]>(sz[rt]>>1))return dfs(to,v,rt);
      }
      return v;
   }
public:
   int n;
   vector<vector<int>> g;
   vector<int> sz,used;
   CentroidDecomposition(int n_):n(n_),g(n),sz(n),used(n){}
   void add_edge(int u,int v){
      g[u].push_back(v);
      g[v].push_back(u);
   }
   int find(int rt){
      get(rt,-1);
      int res=dfs(rt,-1,rt);
      used[res]=1;
      return res;
   }
};

int main(){
   int n,k;
   cin>>n>>k;
   using P=pair<int,int>;
   vector g(n,vector<P>());
   CentroidDecomposition base(n);
   vector<int> a(n);
   rep(i,0,n)cin>>a[i];
   rep(_,0,n-1){
      int u,v,c;
      cin>>u>>v>>c;
      u--; v--;
      g[u].push_back({v,c});
      g[v].push_back({u,c});
      base.add_edge(u,v);
   }

   Fp res;
   auto rec=[&](auto& f,int rt)->void{
      int cen=base.find(rt);
      vector<vector<Fp>> way,cost;
      vector<int> col;
      auto dfs=[&](auto& ff,int v,int p,Fp w,int c,int pre)->void{
         while((int)way.back().size()<=c)way.back().push_back(0);
         while((int)cost.back().size()<=c)cost.back().push_back(0);
         way.back()[c]+=1;
         cost.back()[c]+=w;
         for(auto& [to,tc]:g[v])if(to!=p and !base.used[to]){
            ff(ff,to,v,w+a[to],c+(tc!=pre),tc);
         }
      };
      int cnt=0;
      for(auto& [to,c]:g[cen])if(!base.used[to]){
         cost.push_back({});
         way.push_back({});
         col.push_back(c);
         cnt++;
         dfs(dfs,to,cen,a[to],0,c);
      }

      //from center
      int mx=0;
      rep(i,0,cnt){
         rep(j,0,min(k+1,(int)cost[i].size())){
            res+=cost[i][j]+way[i][j]*a[cen];
         }
         chmax(mx,(int)cost[i].size());
      }

      vector Sum(2,BIT<Fp>(mx)),Cnt(2,BIT<Fp>(mx));
      res+=Fp(a[cen]);
      rep(i,0,cnt){
         int sz=cost[i].size();

         //same
         rep(c,0,min(k+1,sz)){
            res+=Sum[col[i]].sum(k-c);
            res+=cost[i][c]*Cnt[col[i]].sum(k-c);
            res+=way[i][c]*Cnt[col[i]].sum(k-c)*a[cen];
         }
         //diff
         rep(c,0,min(k,sz)){
            res+=Sum[col[i]^1].sum(k-c-1);
            res+=cost[i][c]*Cnt[col[i]^1].sum(k-c-1);
            res+=way[i][c]*Cnt[col[i]^1].sum(k-c-1)*a[cen];
         }

         rep(c,0,sz){
            Sum[col[i]].add(c,cost[i][c]);
            Cnt[col[i]].add(c,way[i][c]);
         }
      }

      for(auto& to:base.g[cen])if(!base.used[to]){
         f(f,to);
      }
   };
   rec(rec,0);
   cout<<res.v<<'\n';
   return 0;
}