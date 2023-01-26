#include <bits/stdc++.h>
using namespace std;
 #include <ext/pb_ds/assoc_container.hpp> 
using namespace __gnu_pbds;
using namespace std;
#define ll long long int
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;
typedef tree<long long, null_type, less_equal<>, rb_tree_tag, tree_order_statistics_node_update> indexed_multiset; 
#define sor(vec) sort(vec.begin(), vec.end())
#define rever(vec) reverse(vec.begin(), vec.end())
#define trav(x , p) for(auto &x : p)
#define ull  unsigned long long
 #define MAXN 200005
 #define fi first
#define se second
const ll mod =998244353; 
#define dbg(i,j,k)  cout<<"("<<i<<","<<j<<")"<<" "<<k<<" "
#define dbgp(i,j)   cout<<i<<" "<<j<<endl
#define print cout<<"**"<<endl;
 const int inf=1e9+7;
 void vcin(vector<ll> &n){for(int i=0;i<int(n.size());i++) cin>>n[i];}
 void vcout(vector<ll> &n){for(int i=0;i<int(n.size());i++){cout<<n[i]<<" ";}cout<<endl;}
const ll MOD = 1e9+7;
double eps = 0.0000001;
 //member functions :
//1. order_of_key(k) : number of elements strictly lesser than k
//2. find_by_order(k) : k-th element in the set
// cout<<"Case #"<<p<<": "<<ans<<endl;


           
void solve() 
{
    int n;
    cin>>n;
    vector<int> v(n);
    for(auto &i:v)
    cin>>i;
    vector<int> b(n,0);
    if(n%2==0)
    {
        for(int i=0;i<n;i+=2)
        {
            // if(v[i]>0 && v[i+1]>0) 
            // {
            //     b[i]=-v[i+1];
            //     b[i+1]=v[i];
            // }
            // else if(v[i]<0 && v[i+1]<0) 
            // {
            //       b[i]=-v[i+1];
            //       b[i+1]=v[i];
            // }
            // else if((v[i]>0 && v[i+1]<0)|| (v[i+1]>0 && v[i]<0))
            // {
            //     b[i]=v[i+1];
            //     b[i+1]=v[i];
            // }
            b[i]=-v[i+1];
            b[i+1]=v[i];
        }
        for(auto i:b)
        cout<<i<<" ";
        cout<<endl;
    }
    else
    {
        for(int i=0;i<n-3;i+=2)
        {
             b[i]=-v[i+1];
             b[i+1]=v[i];
        }
        if(v[n-3]+v[n-2]!=0)
        {
            int sum=v[n-2]+v[n-3];
            
            
            int j=1;
           int x=-v[n-1]*sum-v[n-2]*j;
           
           
           while(x%v[n-3]!=0)
           {
               j++;
              x=-v[n-1]*sum-v[n-2]*j;
           }
           b[n-3]=(x/v[n-3]);
           b[n-2]=j;
           b[n-1]=(v[n-3]+v[n-2]);
           for(auto i:b)
            cout<<i<<" ";
            cout<<endl;
             return ;
        }
        if(v[n-3]+v[n-1]!=0)
        {
            int sum=v[n-3]+v[n-1];
            int j=1;
            int x=-v[n-2]*sum-v[n-1]*j;
            while(x%v[n-3]!=0)
            {
                j++;
                x=-v[n-2]*sum-v[n-1]*j;
            }
            b[n-2]=v[n-3]+v[n-1];
            b[n-1]=j;
            b[n-3]=(x/v[n-3]);
            for(auto i:b)
            cout<<i<<" ";
            cout<<endl;
             return ;
        }
        if(v[n-2]+v[n-1]!=0)
        {
            int sum=v[n-2]+v[n-1];
            int j=1;
            int x=-v[n-3]*sum-v[n-2]*j;
            while(x%v[n-1]!=0)
            {
                j++;
                x=-v[n-3]*sum-v[n-2]*j;
            }
            b[n-2]=j;
            b[n-3]=v[n-2]+v[n-1];
            b[n-1]=(x/v[n-1]);
            for(auto i:b)
            cout<<i<<" ";
            cout<<endl;
            return ;
        }
    }

}
// 1  2  3  4  5  6  7
// -7 -  -  -  -  -  1
// -7 -3 -9 -2 7  1  1
// proof=(1)*(-7)+(2)*(-3)+(3)*(-9)+(4)*(-2)+(6)*(1)+(7)*(1)
// => -7-6+-27-8+35+6+7
//=> (-7+7)+(6-6)+(35-27-8)==0
// hence proved
// 2 test case
// -9 -2 4 5 10
// -   - - -2 1
//         -2 1 // for size==3
//abs(-9-2)==11 
int32_t main()  
{
  
  
	 ios::sync_with_stdio(false);
     std::cin.tie(nullptr);
     
         int t;
         cin>>t;
      
   
         while(t--)
         {
            solve();
         }
   
}

// 10*2+4*1-36
