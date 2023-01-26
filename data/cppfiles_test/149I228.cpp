#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main()
{
    ios::sync_with_stdio(false) ;
    cin.tie(0) ;
    cout.tie(0) ;

    int t;
    cin>>t;
    while(t--)
    {
        int n,k,x;
        cin>>n>>k>>x;
        //x--;
        string s;
        cin>>s;
        int pstarcount=0;
        int starcount=0;
        int val=1;
        //v.push_back(0);
        vector<int> v;
        for(int i=n-1;i>=0;i--)
        {
            if(s[i]=='*')
            {
                pstarcount++;
            }
            else
            {   
                if(pstarcount)
                {
                    starcount++;
                    val*=(pstarcount*k+1);
                    v.push_back(val);
                    pstarcount=0;
                }
                
            }
        }
        if(pstarcount)
        {
            starcount++;
            val*=(pstarcount*k+1);
            v.push_back(val);
        }
        int pos=starcount;
        int count[starcount]={0};
        pos--;
        int end=v.size();
        end--;
        for(int i=0;i<=end;i++)
            cout<<v[i]<<' ';
        cout<<'\n';
        while(x)
        {
            int hi=end;
            int lo=0;
            int ans=-1;
            while(lo<=hi)
            {
                int mid=(hi+lo)/2;
                if(x>=v[mid])
                {
                    ans=mid;
                    lo=mid+1;
                }
                else
                {
                    hi=mid-1;
                }
            }
            if(ans==-1)
            {
                count[pos]=x-1;
                x=0;
            }
            else 
            {   
                //cout<<ans<<' ';
                if(x==v[ans])
                {
                    if(ans)
                        count[pos-ans]=(v[ans]/v[ans-1]-1);
                    else count[pos-ans]=(v[ans]-1);
                    x=0;
                }
                else
                {
                    //cout<<x<<' '<<v[ans]<<'\n';
                    count[pos-ans-1]=(x-1)/v[ans];
                    x-=v[ans]*((x-1)/v[ans]);
                }   
            }
        }
        //cout<<'\n';
        // for(int i=0;i<starcount;i++)
        //     cout<<count[i]<<' ';
        // cout<<'\n';
        bool prev=false;
        int posi=0;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='a')
            {
                if(prev)
                {
                    for(int j=0;j<count[posi];j++)
                        cout<<'b';
                    posi++;
                }
                cout<<'a';
                prev=false;
            }
            else 
            {
                prev=true;
            }
        }
        if(prev)
        {
            for(int j=0;j<count[posi];j++)
                    cout<<'b';
            posi++;
        }
        cout<<'\n';
    }

    return 0;
}