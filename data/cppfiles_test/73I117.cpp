#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
const int INF = 0x3fffffff;
#define ll long long
#define cell(a,b) int((a+(b-1))/b)
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define nl '\n'
#define inf 1e9+7

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

bool sortbyPair(const pair<int,int>&a,const pair<int,int>&b)
{
    return (a.second<b.second);
}



typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

/*bool sortbyPair(const pair<int,int>&a,const pair<int,int>&b)
{
    return (a.second<b.second);
}
*/




int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,i,c=0;
        cin>>n;
        int a[n];
        for(int &it:a) cin>>it;
        int temp;
        for(i=0;i<n;i++)
        {
            bool f=false;
            if(i%2==0)
            {
                for(int j=0;j<n-1;j+=2)
            {
                if(a[j]>a[j+1])
                {
                    f=true;
                    temp=a[j];
                    a[j]=a[j+1];
                    a[j+1]=temp;
                    j++;
                }
            }
             if(f) c++;
            }
            else
            {
                for(int j=1;j<n-1;j+=2)
            {
                if(a[j]>a[j+1])
                {
                    f=true;
                    temp=a[j];
                    a[j]=a[j+1];
                    a[j+1]=temp;
                    j++;
                }
            }
             if(f) c++;
            }

        }
        cout<<c<<nl;
    }
}

