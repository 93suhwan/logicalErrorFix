#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<string>
#include<cstring>
#include<cmath>
#include<vector>

using namespace std;

typedef long long ll;


int main()
{
    ios::sync_with_stdio(false);
    int t=1;
    //cin>>t;
    while(t--)
    {
        int n,i,j;
        cin>>n;
        int c[n+3]={0};
        ll ans=0;
        ll now=0,next=0;
        for(i=1;i<=n;i++)
        {
            cin>>c[i];
        }
        for(i=1;i<=n;i+=2)
        {
            ans+=min(c[i],c[i+1]);
            now=c[i]-c[i+1];
            if(c[i]>=c[i+1])
            for(j=i+2;j<=n;j+=2)
            {
                if(now<0)
                {
                    break;
                }
                if(c[j]>c[j+1])
                {
                    next+=(c[j]-c[j+1]);
                }
                else
                {
                    ll x=(ll)(c[j+1]-c[j]);
                    if(x>=next)
                    {
                        x-=next;
                        next=0;
                        if(x<now)
                        {
                            ans+=(x+1);
                        }
                        else
                        {
                            ans+=(now+1);
                        }
                        now-=x;
                    }
                    else
                    {
                        next-=x;
                    }
                }
            }
        }
        cout<<ans;
    }
    return 0;
}