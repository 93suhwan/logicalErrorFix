#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<cmath>
#include<string>
#include<algorithm>
#include<cstring>
#include<vector>

using namespace std;

typedef long long ll;



int main()
{
    ios::sync_with_stdio(false);
    int t=1;
    int n;
    int i,j;
  // cin>>t;
    while(t--)
    {
       cin>>n;
       ll c[n+3]={0};
       for(i=1;i<=n;i++)
       {
           cin>>c[i];
       }
       if(i==1)
        cout<<0<<endl;
       else
       {
       unsigned long long num=0;
       for(i=1;i<=n;i+=2)
       {
           if(i==n)
            break;
           if(c[i]<c[i+1])
            num+=c[i];
           else
            num+=c[i+1];
           ll l,r;
           l=c[i],r=c[i+1];
           if(c[i]>=c[i+1])
           for(j=i+2;j<=n;j+=2)
           {
               if(j+1>n)
                break;
               l+=c[j],r+=c[j+1];
               if(l-c[i]+c[i+1]<=r)
               {
                   ll x=0,x1,x2,ymin,ymax;
                 x2=r,x1=r-c[j+1]+c[j];
                 ymin=x1+c[i]-l,ymax=x2+c[i]-l;
                 if(ymin<c[i+1])
                    x=c[i+1]-ymin;
                 x=ymax-ymin+1-x;
                   if(x>c[i]-c[i+1]+1)
                    x=(c[i]-c[i+1]+1);

                    num+=x;
               }
               if(l<r)
                break;
           }
       }
       cout<<num<<endl;
       }
    }
    return 0;
}