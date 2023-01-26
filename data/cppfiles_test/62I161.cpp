#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define I_AM_SPEED ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);init_code();
#define asc(i,x,n) for(I i=x;i<n;i++)
#define dsc(i,x,n) for(I i=x;i>=n;i--)
#define all(x) (x).begin(),(x).end()
#define W(t) int t;cin>>t;while(t--)
#define printa(x); for(A n:x){cout<<n<<" ";}cout<<"\n";
#define U unsigned
#define I long long int
#define S string
#define C char
#define D double
#define A auto
#define B bool
#define yes cout<<"YES\n";
#define no cout<<"NO\n";
#define ff first 
#define ss second
#define pb push_back
#define mp make_pair
#define OS(x) set<x>
#define OM(x,y) map<x,y>
#define V(x) vector<x>
#define VP(x,y) vector<pair<x,y>>
#define lb lower_bound
#define ub upper_bound
#define PBS(x) tree<x,null_type,less<I>,rb_tree_tag,tree_order_statistics_node_update>
#define PBM(x,y) tree<x,y,less<I>,rb_tree_tag,tree_order_statistics_node_update>
#define digits(n) floor(log10(n)) + 1
#define isPerfectSq(x) ceil((D)sqrt((D)n))==floor((D)sqrt((D)n))
#define pi (D)acos(-1)
#define mod 1000000007
void init_code()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
}
void solve(){
    
}
int main()
{
    I_AM_SPEED

    W(t)
    {
        I n,i,c=0;
        cin>>n;
        I a[n];
        vector<I> v[n+2];
        for(i=0;i<n;i++)
        {
            cin>>a[i];
            if(a[i]==0)
                c++;
        }
        if(a[n-1]==0)
        {
            for(i=1;i<n+2;i++)
            {
                cout<<i<<" ";
            }
            cout<<endl;
            continue;
        }
        if(c==0)
        {
            cout<<-1<<endl;
            continue;
        }
        I j=0;
        B flag=false;
        for(i=0;i<n-1;i++)
        {
            if(a[i]==0 && a[i+1]==1)
            {
                j=i;
                flag=true;
                break;
            }
        }
        if(!flag)
        {
            cout<<-1<<endl;
            continue;
        }
        // cout<<j<<endl;
        for(i=0;i<n;i++)
        {
            cout<<i+1<<" ";
            if(i==j)
                cout<<n+1<<" ";
        }
        cout<<endl;
    }

    return 0;

    //Number of digits in N = floor(log10(N)) + 1;
    //Number is power of 2 : return x && (!(x&(x-1)));
    // order_of_key(k) find_by_order(k);
}
        