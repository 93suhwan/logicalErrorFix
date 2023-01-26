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

const int N=100000;
const int L=400;
Fp solve1(vector<int>& a){
   Fp freq[N+5],buf[N+5];
   for(auto& x:a)freq[x]+=1;
   Fp res;
   for(int g=N;g>=1;g--){
      for(int i=g;i<=N;i+=g)buf[g]+=freq[i];
      buf[g]*=buf[g];
      for(int h=g*2;h<=N;h+=g)buf[g]-=buf[h];
      res+=buf[g]*g;
   }
   return res;
}
Fp solve2(vector<int>& a){
   Fp res;
   int n=a.size();
   rep(i,0,n)res+=a[i]*2;
   rep(i,0,n)rep(j,0,i)res+=gcd(a[i],a[j]);
   return res;
}

int main(){
   int n=100000;
   cin>>n;
   vector<int> a(n);
   rep(i,0,n)a[i]=100000-i,cin>>a[i];

   vector<Fp> buf(n+1);
   Fp res;
   for(int g=n;g>=1;g--){
      vector<int> b;
      for(int i=g-1;i<n;i+=g)b.push_back(a[i]);
      if(g<=L)buf[g]=solve1(b);
      else buf[g]=solve2(b);
      for(int h=g*2;h<=n;h+=g)buf[g]-=buf[h];
      res+=buf[g]*g;
   }
   cout<<res.v<<'\n';
   return 0;
}