#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define ll long long 
#define FI first 
#define SE second
#define pb push_back 
#define eb emplace_back
#define mod 1000000007
#define all(c) (c).begin(),(c).end()
#define LB  lower_bound
#define UB  upper_bound
#define max3(a,b,c) max(c,max(a,b))
#define min3(a,b,c) min(c,min(a,b))
#define mems(s, n) memset(s, n, sizeof(s))
#define NINF -1e18
#define INF 1e18
#define int ll int
#define endl '\n'
#define double long double
#define OOK order_of_key  //no of elements strictly less than
#define FBO find_by_order //iterator pointing kth element;indexing starts from 0
#define CK3(x,y,z) cout<<(x)<<" "<<(y)<<" "<<(z)<<endl
#define CK4(a,b,c,d) cout<<(a)<<" "<<(b)<<" "<<(c)<<" "<<(d)<<endl

typedef pair<int,int> PII;
typedef pair<pair<int,int>,int> PPII;
typedef pair<int,pair<int,int>> PIPI;
typedef map<int,int>MII;
typedef vector<int> VI;
template <typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

/*int power(int a, int b)
{int x=1,y=a;while(b>0){if(b%2){x =(x*y)%mod;}y =(y*y)%mod;b/=2;}return x%mod;}
*/


signed main()
{
ios::sync_with_stdio(false); cin.tie(0);
int T=1,T1=0;cin>>T;
while(T1++<T)
{//cout<<"Case #"<<T1<<": ";
    int n;
    cin>>n;
    string s1,s2;
    cin>>s1>>s2;
    int ans=0,flag=0;
    for(int i=0;i<n;i++)
    {
        if(flag==0)
        {
            if(s1[i]!=s2[i])
            ans+=2;
            else if(s1[i]=='1')
            flag=1;
            else
            flag=2;
        }
        else if(flag==1)
        {
            if(s1[i]=='0'||s2[i]=='0')
            {
                ans+=2;
                flag=0;
            }
        }
        else
        {
            if(s1[i]=='1'||s2[i]=='1')
            {
                ans+=2;
                flag=0;
            }
            else
            ans++;
        }
        //CK3(i,flag,ans);
    }
    if(flag==2)
    ans++;
    cout<<ans<<endl;
}


return 0;
}



