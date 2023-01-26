#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp>
typedef long long ll;
#define pb push_back
#define ff first
#define ss second
const int N=2e5+7;
const int mod=998244353;
const double eps=1e-6;
const double pi=	3.14159265358979323846;
using namespace std;  
using namespace __gnu_pbds;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag,
             tree_order_statistics_node_update>
    op_set;
 
int32_t main() 
{
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   
   int t;
   cin >> t;
   while(t--)
   {
       ll n,m;
       cin >> n >> m;
       vector< std::array<ll,2> > input(n) ;
       ll suma=0;
       ll sumb=0;
       ll sum_lower=0;
       ll sum_upper=0;
       vector< std::array<ll,2> > limits(n) ;
       for(int i=0;i<n;i++)
       {
           ll a,b;
           cin >>  a >> b;
           ll upper=std::min(a,m);
           ll lower=std::max(0ll,m-b);
           limits[i]={lower,upper};
           input[i]={a,b};
           
           suma+=a;
           sumb+=b;
           sum_lower+=lower;
           sum_upper+=upper;
       }
       ll k=n*m;
       k=k+suma-sumb;

       if( sum_lower*2<=k && sum_upper*2>=k )
       {
                cout << k%2 << "\n";
                ll to_get=k/2;
                ll left=0;
                for(int i=0;i<n;i++)
                        left+=limits[i][0];
                
                for(int i=0;i<n;i++)
                {
                    int taken=limits[i][0];
                    if( to_get>left )
                    {
                        taken=std::min( limits[i][1],taken+to_get-left);
                    }
                    to_get-=taken;
                    left-=taken;
                    if(left<0)
                            left=0;
                    cout << taken << " " << (m-taken) << "\n";
                }
       }
       else if(k>2*sum_upper)
       {
                cout << abs(k-2*sum_upper) << "\n";
                for(int i=0;i<n;i++)
                        cout << limits[i][1] << " " <<  ( m-limits[i][1] ) << "\n";
       }
       else
       {
                cout << abs(k-2*sum_lower) << "\n";
                for(int i=0;i<n;i++)
                        cout << limits[i][0] << " " <<  ( m-limits[i][0] ) << "\n";
       }
       cout << "\n";
   }
}
// maths behind this 
// let us take xi amount of fish
// so fish left is ai-xi and meat left will be bi-(m-xi)
// so we need to find sigma ai - sigma bi
// that means sigma(ai-xi)-sigma(bi-(m-xi))
// that equates to sigma(ai)-sigma(bi)+m*n - 2*sigma(xi)
// now some limits on xi ai-xi>=0 i.e xi<=ai
// b-(m-xi)>=0 xi>=(m-bi)
// this means that the value xi can be any value in the the range [m-bi,ai]
// now the reason the limits are correct as it is bcz else it would be ai<(m-bi) (ai+bi) < m not possible
// so we can place limits on the xi and hence sigma (xi) 

//thanks to UG's video editorial