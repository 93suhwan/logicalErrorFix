#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#define izq nod * 2
#define der nod * 2 + 1
#define mid (( a + b ) >> 1)
#define oo (1<<30)
#define oo64 (1LL<<62LL)
#define fr first
#define sc second
#define pb push_back
#define m_p make_pair
#define len(X) ((int)((X).size()))
#define all(X) (X).begin(), (X).end()
#define YES cout<<"YES"<<'\n'
#define NO cout<<"NO"<<'\n'
#define NO1 cout<<'-'<<'1'<<'\n'

using namespace std;

typedef long long int64;
typedef unsigned long long unt64;
typedef pair<int, int> pii;
typedef pair<int64, int64> pll;


const int MX = 400005;
const int64 MOD = 1000000007; 

int64 A[MX],B[MX];

struct node{
	int64 ci = 0;
    int64 cf = 0;
    int64 fn = 0;
    int64 val = 0;
    int64 tot = 0;
    
    int64 sum ( int64 f ){
	      return f * (f+1ll)/2ll;
	}
    
    node operator & (const node &p){
        node ans;
        
        ans.val = val + p.val;
        
        if ( A[fn] <= A[fn+1] ){
	        ans.val += cf * p.ci;
	    }
	    
	    ans.ci = ci;
	    if ( ci == tot && A[fn] <= A[fn+1] ){
	        ans.ci += p.ci;
	    } 
        ans.cf = p.cf;
        if ( p.cf == p.tot && A[fn] <= A[fn+1] ){
	        ans.cf += cf;
	    } 
	    ans.tot = tot + p.tot;
	    ans.fn = p.fn;
	    return ans;
    }
    
};

struct st_vectores{
    vector<node> T;
    vector<int64> mk;
    vector<pii>P;
    int tot;
    int64 neutro_lazy = oo64;
    
    st_vectores(): T(2), mk(2, neutro_lazy), P(2,{0,0}), tot(1){}
    
    void verificar ( int nod ){
	     if ( P[nod].fr == 0 ){
			 P.pb({0,0}); P.pb({0,0}); T.pb({}); T.pb({});
			 mk.pb ( neutro_lazy ); mk.pb ( neutro_lazy );
			 tot += 2;P[nod].fr=tot-1,P[nod].sc=tot;
		 }
    }
    
    void lazy(int64 a, int64 b, int nod){
         
         A[a] = {mk[nod]};
         
         if ( a != b ){  verificar ( nod );
			     if ( mk[P[nod].fr] != neutro_lazy )mk[P[nod].fr] = mk[nod];
	             else mk[P[nod].fr] = neutro_lazy;
	             if ( mk[P[nod].sc] != neutro_lazy )mk[P[nod].sc] = mk[nod];
	             else mk[P[nod].sc] = neutro_lazy;}
	     mk[nod] = neutro_lazy;}
	     
    node build( int64 a, int64 b, int nod ){
        
        if ( a == b ){
	        return T[nod] = { 1, 1, a, 1, 1 };
	    }
         
        verificar ( nod );
        return T[nod] = build(a, mid, P[nod].fr) & 
                        build(mid+1, b, P[nod].sc);}
    
    node update( int64 a, int64 b, int nod, int64 in, int64 fn, int64 val ){
        //if( mk[nod] != neutro_lazy )
            //lazy(a, b, nod);
            
        if( a > fn || b < in )
            return T[nod];
            
        if( a >= in && b <= fn ){
               mk[nod] = val;  lazy ( a,b,nod );
             //  A[a] = val;
            return T[nod];    }
            
        verificar ( nod );
        return T[nod] = update(a, mid, P[nod].fr, in, fn, val) & 
                        update(mid+1, b, P[nod].sc, in, fn, val);}
    
    node query(int64 a, int64 b, int nod, int64 in, int64 fn){
        if( mk[nod] != neutro_lazy )
            lazy(a, b, nod);
            
        if( a >= in && b <= fn ){
            return T[nod]; }    
        verificar ( nod );
        
        if ( mid < in )return query(mid+1, b, P[nod].sc, in, fn);
        if ( mid+1 > fn )return query(a, mid, P[nod].fr, in, fn );
        
        return query(a, mid, P[nod].fr, in, fn ) & 
               query(mid+1, b, P[nod].sc, in, fn);    }
};

void solve(){
     
     int n,q;
     cin>>n>>q;
     
     for ( int i = 1; i <= n; i++ ){
	      cin>>A[i];
	 }
	
	 st_vectores ds;
	 
	 ds.build ( 1,n,1 );
	 
	 for ( int i = 1; i <= q; i++ ){
	     int x;
	     cin>>x;
	     
	     if ( x == 2 ){ 
	     int l,r;
	     cin>>l>>r;
	     
	     cout<<ds.query ( 1,n,1,l,r ).val<<'\n';   
	     }
	     else {
		    int id,va;
		    cin>>id>>va;
		    
		    ds.update ( 1,n,1,id,id,va );
		 }
	 }
     
}

int main(){
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
    //int t; cin>>t;
    //while( t-- ) 
          solve(); 	
	
return 0;	
}
