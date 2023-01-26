#include<bits/stdc++.h> 
#define rg register 
#define fp( i , x , y ) for( rg int i=(x); i<=(y); ++i ) 
#define fq( i , x , y ) for( rg int i=(y); i>=(x); --i ) 
#define i60 long long 
#define dou double  
#define ls k<<1 
#define rs k<<1|1 
using namespace std ; 
const int N = 1e5+10 , mod=1e9+7 ; 
int n , a[N] , pri[N] , len , vi[N] , phi[N] , lis[N] , sz[N] , cnt[N] ; 
vector <int> v[N] ; 
i60 nw ; 
void prep( int m ) { 
  phi[1]=1 ; 
  fp( i , 2 , m ) { 
    if( !vi[i] ) { 
      vi[i] = i ; pri[++len] = i ; 
      phi[i] = i-1 ; 
	} 
	fp( j , 1 , len ) { 
	  if( i*pri[j] > m || pri[j] > vi[i] ) break ; 
	  vi[i*pri[j]] = pri[j] ; 
	  phi[pri[j]*i] = phi[i] * ( i%pri[j] ? pri[j]-1 : pri[j] ) ;  
	} 
  } 
  fp( i , 1 , m ) { 
    for(int j=i; j<=m; j+=i) v[j].push_back(i) ; 
    sz[i] = v[i].size() ;  
  } 
} 
void add( int x , int z ) { 
  int j ; 
  fp( i , 1 , sz[x] ) { 
    j = v[x][i-1] ; 
    if( z==1 ) nw -= 1ll * cnt[j] * cnt[j] * phi[j] ; 
	cnt[j] += z ;  
    if( z==1 ) nw += 1ll * cnt[j] * cnt[j] * phi[j] ; 
  } 
} 
i60 solve( ) { 
  nw=0 ; 
  fp( i , 1 , len ) add( lis[i] , 1 ) ; 
  i60 tp=nw ; 
  fp( i , 1 , len ) add( lis[i] , -1 ) ; 
  return tp ;  
} 
signed main( ) { 
  ios::sync_with_stdio(false) ; 
  cin.tie(0) ; 
  cin >> n ; int m=0 ; 
  fp( i , 1 , n ) cin >> a[i] , m=max( m , a[i] ) ;  
  prep( m ) ; i60 ans=0 ; 
  fp( i , 1 , n ) { 
    len=0 ;  
    for(int j=i; j<=n; j+=i) lis[++len]=a[j] ; 
    ans += 1ll*phi[i]*(solve()%mod)%mod ; 
  } 
  cout << ans << '\n' ; 
  return 0 ; 
} 
/*

4
4 2 2 4



*/