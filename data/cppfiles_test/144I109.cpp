//Template begins
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#define fio ios_base::sync_with_stdio(false); cin.tie(NULL)
#define int long long
#define db long double
#define lb lower_bound
#define ub upper_bound
#define pb push_back
#define fo(i,a,b) for(int i=a; i<b; i++)
#define all(v) (v).begin(),(v).end()
typedef pair<int,int> pii;
#define d0(x) cout<<(x)<<" "
#define d1(x) cout<<(x)<<endl
#define d2(x,y) cout<<(x)<<" "<<(y)<<endl
#define max3(a,b,c) max(max((a),(b)),(c))
#define max4(a,b,c,d) max(max((a),(b)),max((c),(d)))
#define min3(a,b,c) min(min((a),(b)),(c))
#define min4(a,b,c,d) min(min((a),(b)),min((c),(d)))
template<typename T>
using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
/*
    find_by_order() - Returns an iterator to the k-th largest element (counting from zero)
    order_of_key()  - The number of items in a set that are strictly smaller than our item
    Rest same as set
*/
const long double PI = 3.14159265358979323846264338;
const long long INF = 1000000000000000000;
const long long INF1 = 1000000000;
const long long mod = 1000000007;
// const long long mod = 998244353;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
int mpow(int a, int b){
    a %= mod;
    if(!b)
        return 1;
    int temp = mpow(a, b/2);
    temp = (temp*temp) % mod;
    if(b%2)
        return (a * temp) % mod;
    return temp;
}
 
 
int _pow(int a, int b){
    if(!b)
        return 1;
    int temp = _pow(a, b/2);
    temp = (temp * temp);
    if(b%2)
        return (a * temp);
    return temp;
}
 
int mod_in(int n){
    return mpow(n, mod-2);
}
 
int cl(int a, int b){
    if(a%b)
        return 1 + a/b;
    return a/b;
}
 
int gcd(int a,int b){if(b==0) return a;return gcd(b,a%b);}
//Template ends



signed main()
{
    fio;
    #ifndef ONLINE_JUDGE 
        freopen("input.txt", "r", stdin); 
        freopen("output.txt", "w", stdout); 
    #endif
    int T=1;
    cin>>T;
    while(T--)
    {
        int n,m,k;
        cin>>n>>m>>k;
        int ex=n%m;
        int num=n/m;
        int p=0;
        for(int i=0; i<k; i++)
        {
            for(int j=0; j<ex; j++)
            {
                cout<<num+1<<" ";
                for(int k=0; k<num+1; k++)
                {
                    cout<<p+1<<" ";
                    p+=1;
                    p%=n;
                }
                cout<<"\n";
            }
            for(int j=ex; j<m; j++)
            {
                cout<<num<<" ";
                for(int k=0; k<num; k++)
                {
                    cout<<p+1<<" ";
                    p+=1;
                    p%=n;
                }
                cout<<"\n";
            }
        }
    }	
    
}