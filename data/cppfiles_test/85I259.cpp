#include   <bits/stdc++.h>
#include   <algorithm>
#include   <sys/time.h>
#include   <ext/pb_ds/assoc_container.hpp>
#include   <stdio.h>
#include   <string.h>
#include   <stdlib.h>
#include   <iomanip>
#define    FAST       ios::sync_with_stdio(0);cin.tie(0);
#define    pb         push_back
#define    mp         make_pair
#define    ff         first
#define    ss         second
#define    el         "\n"
#define    ii         int
#define    ll         long long
#define    ld         long double
#define    pii        pair<ii,ii>
#define    pll        pair<ll,ll>
#define    vcii       vector<ii>
#define    vcll       vector<ll>
#define    vcd        vector<double>
#define    vcs        vector<string>
#define    vpii       vector<pii>
#define    vpll       vector<pll>
#define    gcd(x,y)   __gcd(x,y)
#define    lcm(x,y)   ( x*y)/__gcd(x,y)
#define    stl_sort(v)   sort(v.begin(),v.end())
#define    stl_revsort(v)   sort(v.rbegin(),v.rend())
#define    stl_rev(v)    reverse(v.begin(),v.end())
#define    rep(i,x,y) for(ll i=x;i<y;i++)
#define    scll(x)    scanf("%lld",&x)
#define    pfll(x)    printf("%lld",x)
#define    scd(x)     scanf("%llf",&x)
#define    pfd(x)     prinf("%0.5llf\n",x)
#define    MOD        (ll)(1e9+7)
#define    MAX        1000000000000000000
#define    MIN        -1000000000000000000
#define    yes       cout<<"YES\n";
#define     no        cout<<"NO\n";

using namespace std;


int main()
{
    /* freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout); */

   // FAST

    ll a,b,d,c,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z,sum,sum1,sum2;
    ll A,B,C,D,E,F,G,H,I,J,K,L,M,N,O,P,Q,R,S,T,U,V,W,X,Y,Z,SUM,SUM1,SUM2;

     cin>>t;
     while(t--)
	 {
       string st;
       cin>>st;
       a=0;
       b=0;
       ll sz=st.size();
       rep(i,0,sz)
       {
       	 if(st[i]=='0')a++;
       	 else b++;
       }
       if(a==0)
	   {
	   	cout<<0<<el;
	   	continue;
	   }
	   else if(b==0)
	   {
	   	   cout<<1<<el;
	   	   continue;
	   }
	   else if(a>0&&b>0)
	   {
	   	f=0;
	   	g=0;
		rep(i,0,sz)
       {
       	 if(st[i]=='0')
			break;
		f++;
       }
         for(j=sz-1;j>=0;j--){
			if(st[j]=='0')
			break;
			g++;
         }
         if(f==b||g==b)
			cout<<1<<el;
		 else if(a>=2)cout<<2<<el;
	   	 else cout<<a<<el;
	   }

	 }



    return 0;

}

