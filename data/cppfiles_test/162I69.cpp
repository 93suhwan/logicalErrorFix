#include   <bits/stdc++.h>
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
#define    ii        int
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
#define    stl_sort(v)   sort(v.begin(),v.end())
#define    stl_rev(v)    reverse(v.begin(),v.end())
#define    rep(i,x,y) for(ll i=x;i<y;i++)
#define    scll(x)    scanf("%lld",&x)
#define    pfll(x)    printf("%lld",x)
#define    scd(x)     scanf("%llf",&x)
#define    pfd(x)     prinf("%0.5llf\n",x)
#define    MOD        (ll)(1e9+7)
#define    MAX        1000000000000000000
#define    yes       cout<<"YES\n";
#define     no        cout<<"NO\n";

using namespace std;

int main()
{
    /* freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout); */

    //FAST

    ll a,b,d,c,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z,sum,sum1,sum2,tc;
    ld A,B,C,D,E,F,G,H,I,J,K,L,M,N,O,P,Q,R,S,T,U,V,W,X,Y,Z,SUM,SUM1,SUM2;

    cin>>t;
    while(t--)
    {
    	cin>>n;
    	vcll vc(n);
    	rep(i,0,n)
    	{
    		cin>>vc[i];
    	}

    	l=*min_element(vc.begin(),vc.end());
    	r=200;
		while(l<r-1)
		{

			ll mid=(l+r)/2;

			bool chk=true;
			vcll add(n+1,0),final_arr(n+1,0);
			for(i=n-1;i>=2;i--)
			{
				if(vc[i]+add[i]-mid<0)
				{
					chk=false;
					break;
				}
				d=min(vc[i]/3,(vc[i]+add[i]-mid)/3);
				add[i-1]+=d;
				add[i-2]+=2*d;
				final_arr[i]=vc[i]+add[i]-3*d;
			}
			final_arr[0]=vc[0]+add[0];
			final_arr[1]=vc[1]+add[1];

			for(i=0;i<n;i++)
			{
				if(final_arr[i]<mid)
				{
					chk=false;
					break;
				}
			}
			if(chk)
			{
				//cout<<"mid "<<mid<<el;
				l=mid;
			}
			else{

				r=mid;
			}
		}
		cout<<l<<el;
    }

    return 0;
}


