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
        
        auto lowb=lower_bound(ma.begin(),ma.end(),mb[n-1]);
        int p=(lowb-ma.begin());
        auto lowa=lower_bound(mb.begin(),mb.end(),ma[n-1]);
         int q=(lowa - mb.begin());
       
       for(int i=n-2;i>=0;i--)

        {
                if(!ans[ma[i]])
                {
                    int index=lower_bound(mb.begin(),mb.end(),ma[i])-mb.begin();
                      if(index>q)
                            ans[ma[i]]=true;
                }
        }
         for(int i=n-2;i>=0;i--)

        {
                if(!ans[mb[i]])
                {
                    int index=lower_bound(ma.begin(),ma.end(),mb[i])-ma.begin();
                      if(p<index)
                            ans[mb[i]]=true;
                }
        }

        for(int i=1;i<=n;i++)
           cout<<ans[i];
        cout<<"\n";
    }
}