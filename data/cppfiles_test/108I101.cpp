#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define FAST ios_base::sync_with_stdio(false);cin.tie(NULL)

int32_t main()
{
    FAST;
    int t;
    cin>>t;
    while(t--)
    {

        int n;
        cin>>n;
         vector<pair<int,int>>a(n);
         vector<pair<int,int>>b(n);
         for(int i=0;i<n;i++)
            {
                cin>>a[i].first;
                a[i].second=i+1;
            }  
        sort(a.begin(),a.end());
      for(int i=0;i<n;i++)
        {
            cin>>b[i].first;
            b[i].second=i+1;
        }     
     sort(b.begin(),b.end());
     bool ans[n+1]={false};
     
    //   reverse(a.begin(),a.end());
      vector<int>ma(n);
         for(int i=0;i<n;i++)
             ma[i]=a[i].second;
        // reverse(b.begin(),b.end());
       vector<int>mb(n);
      
          for(int i=0;i<n;i++)
              mb[i]=b[i].second;

        ans[ma[n-1]]=true;
       ans[mb[n-1]]=true;
        int i=n-1;
        set<int>x;
        x.insert(ma[i]);
        set<int>y;
        y.insert(mb[i]);
        while(x!=y && i>=0)
        {
            ans[ma[i]]=true;
            ans[mb[i]]=true;
            if(mb[i]==ma[i])
                {
                    x.erase(ma[i]);
                    y.erase(mb[i]);
                }
            i--;
             
        }
        for(int i=1;i<=n;i++)
           cout<<ans[i];
        cout<<"\n";
    }
}