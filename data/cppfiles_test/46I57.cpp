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
       ll num=0;
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
           if(i+1<=n&&c[i]>=c[i+1])
           for(j=i+2;j<=n;j+=2)
           {
               if(j+1>n)
                break;
               l+=c[j],r+=c[j+1];
               if(l-c[i]+c[i+1]<=r&&c[j+1]>=c[j]&&l>=r-c[j+1]+c[j])
               {
                   ll x=r-l+c[i];
                   if(x>c[i])
                    x=c[i];
                   if(x<1)
                    num++;
                   else
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