#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define int long long
#define IOS std::ios::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
#define pb push_back
#define mod 1000000007ll //998244353ll

using namespace std;




int32_t main()
{  IOS;
   int t;
   cin>>t;

   for(int i=0;i<t;i++)
   {
     int n;
     cin>>n;
     vector<int>v(n);
     for(int j=0;j<n;j++)
     {
         cin>>v[j];
     }
     int sum=0,d=0,j=0;
     while(true)
     {   int c=0;
         for(int k=j;k<n;k+=2)
         {
             if(v[k]>v[k+1])
             {c++;
              swap(v[k],v[k+1]);

             }

         }
         if(j==0)
            j=1;
         else
            j=0;
         if(c==0)
         { break; }
         else
            d++;
     }
     cout<<d<<"\n";}

    return 0;

    }













