#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization ("unroll-loops")

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#include <fstream>
#include<string.h>
#include <algorithm>
#include<math.h>
#include<vector>
#include <queue>
#include <deque> 
#define ll long long
#define ld long double
#define M 1000000007 
#define MM 998244353
#define INF 4e18
using namespace std;

int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    /*freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);*/
    ll tc,tcitr;
    cin>>tc;
    //tc=1;
    tcitr=0;
    while(tcitr<tc)
    {
        //cout<<"Case #"<<tcitr+1<<": ";
        ll n,i,j,k,m,f,p;
        cin>>n>>m>>k;
        if(n%2)
        {
            ll req=m/2;
            if(k<req)cout<<"NO\n";
            else
            {
                req-=k;
                if(req%2 || k*2 > n*m)cout<<"NO\n";
                else 
                {
                    cout<<"YES\n";
                    ll a[n][m]={};
                    p=0;
                    f=0;
                    for(i=1;i<n;i+=2)
                    {
                        p=f;
                        for(j=0;j<m;j++)
                        {
                            a[i][j]=p;
                            a[i+1][j]=p;
                            p^=1;
                        }
                        f^=1;
                    }
                    for(j=0;j<m;j+=2)
                    {
                        k--;
                        a[0][j]=25-p;
                        a[0][j+1]=25-p;
                        p^=1;
                    }
                    for(i=1;i<n && k>0;i+=2)
                    {
                        f=0;
                        p=f;
                        for(j=0;j<m && k>0;j+=2)
                        {
                            k-=2;
                            if(p==0)
                            {
                                a[i][j]=25;
                                a[i][j+1]=25;
                                a[i+1][j]=24;
                                a[i+1][j+1]=24;
                            }
                            else
                            {
                                a[i][j]=24;
                                a[i][j+1]=24;
                                a[i+1][j]=25;
                                a[i+1][j+1]=25;
                            }
                            p^=1;
                        }
                        f^=1;
                    }
                    for(i=0;i<n;i++)
                    {
                        for(j=0;j<m;j++)cout<<(char)('a'+a[i][j]);
                        cout<<"\n";
                    }
                }
            }
        }
        else
        {
            if(k*2 > n*m || k > n*(m/2))cout<<"NO\n";
            else
            {
                if(k%2==n%2)
                {
                    cout<<"YES\n";
                    ll a[n][m]={};
                    p=0;
                    f=0;
                    for(i=0;i<n;i+=2)
                    {
                        p=f;
                        for(j=0;j<m;j++)
                        {
                            a[i][j]=p;
                            a[i+1][j]=p;
                            p^=1;
                        }
                        f^=1;
                    }
                    for(i=0;i<n && k>0;i+=2)
                    {
                        f=0;
                        p=f;
                        for(j=0;j<m && k>0;j+=2)
                        {
                            k-=2;
                            if(p==0)
                            {
                                a[i][j]=25;
                                a[i][j+1]=25;
                                a[i+1][j]=24;
                                a[i+1][j+1]=24;
                            }
                            else
                            {
                                a[i][j]=24;
                                a[i][j+1]=24;
                                a[i+1][j]=25;
                                a[i+1][j+1]=25;
                            }
                            p^=1;
                        }
                        f^=1;
                    }
                    for(i=0;i<n;i++)
                    {
                        for(j=0;j<m;j++)cout<<(char)('a'+a[i][j]);
                        cout<<"\n";
                    }
                }
                else cout<<"NO\n";
            }
        }
        tcitr++;
    }
    return 0;
}
