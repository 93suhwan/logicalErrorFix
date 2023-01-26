/* Jyothi swaroop reddy*/

#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace chrono;
using namespace __gnu_pbds;

#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define MOD 1000000007
#define MOD1 998244353
#define INF 1e18
#define endl "\n"
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define ff first
#define ss second
#define PI 3.141592653589793238462
#define set_bits __builtin_popcountint
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define int long long
#define intl unsigned long long
#define ld long double
typedef tree < int ,  null_type ,  less<int>  ,  rb_tree_tag ,  tree_order_statistics_node_update> ordered_set; // find_by_order, order_of_key
template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
// void _print(pbds v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}

/*---------------------------------------------------------------------------------------------------------------------------*/
int gcd(int a, int b) {if (b > a) {return gcd(b, a);} if (b == 0) {return a;} return gcd(b, a % b);}
int expo(int a, int b, int mod) {int res = 1; while (b > 0) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1;} return res;}
void extendgcd(int a, int b, int*v) {if (b == 0) {v[0] = 1; v[1] = 0; v[2] = a; return ;} extendgcd(b, a % b, v); int x = v[1]; v[1] = v[0] - v[1] * (a / b); v[0] = x; return;} //pass an arry of size1 3
int mminv(int a, int b) {int arr[3]; extendgcd(a, b, arr); return arr[0];} //for non prime b
int mminvprime(int a, int b) {return expo(a, b - 2, b);}
bool revsort(int a, int b) {return a > b;}
void swap(int &x, int &y) {int temp = x; x = y; y = temp;}
int combination(int n, int r, int m, int *fact, int *ifact) {int val1 = fact[n]; int val2 = ifact[n - r]; int val3 = ifact[r]; return (((val1 * val2) % m) * val3) % m;}
void google(int t) {cout << "Case #" << t << ": ";}
vector<int> sieve(int n) {bool *arr = new bool[n + 1](); vector<int> vect; for (int i = 2; i <= n; i++)if (arr[i] == 0) {vect.push_back(i); for (int j = 2 * i; j <= n; j += i)arr[j] = 1;} return vect;}
int mod_add(int a, int b, int m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
int mod_mul(int a, int b, int m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
int mod_sub(int a, int b, int m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
int mod_div(int a, int b, int m) {a = a % m; b = b % m; return (mod_mul(a, mminvprime(b, m), m) + m) % m;}  //only for prime m
int phin(int n) {int number = n; if (n % 2 == 0) {number /= 2; while (n % 2 == 0) n /= 2;} for (int i = 3; i <= sqrt(n); i += 2) {if (n % i == 0) {while (n % i == 0)n /= i; number = (number / i * (i - 1));}} if (n > 1)number = (number / n * (n - 1)) ; return number;}
/*------------------------------------------------------------------------------------------------------------------------------------------------------------*/

void solve()
{
    int t=1;
    //cin>>t;
    while(t--)
    {
        string s1="",s2="";
        int n1,n2;cin>>n1>>n2;
        while(n1)
        {
            if(n1&1)
            {
                s1='1'+s1;
            }
            else{
                s1='0'+s1;
            }
            n1/=2;
        }
        while(n2)
        {
            if(n2&1)
            {
                s2='1'+s2;
            }
            else{
                s2='0'+s2;
            }
            n2/=2;
        }
        //cout<<s1<<" "<<s2<<endl;
        set<int> st;
        if(s1==s2)
        {
            cout<<"YES"<<endl;
            return;
        }
        for(int i=0;i<s2.size();i++)
        {
            if(s2[i]=='1')
            {
                st.insert(i);
            }
        }
        if(s1.size()>s2.size())
        {
            cout<<"NO"<<endl;
            return;
        }
       for(int i=0;i<s2.size()-s1.size();i++)
       {
           int f=0;
           for(int j=i;j<i+s1.size();j++)
           {
               if(s1[j]!=s2[j])
               {
                   f=1;
                   break;
               }
           }
           if(f==0 && *(--st.end())>=(i+(int)s1.size()))
           {
               cout<<"YES"<<endl;
               return;
           }
           /*f=0;
           for(int j=i;j<i+s1.size();j++)
           {
               if(s1[j]!=s2[i+(int)s1.size()-(int)1-j])
               {
                   f=1;
                   break;
               }
           }
           if(f==0 && *(--st.end())>=(i+(int)s1.size()))
           {
               cout<<"YES"<<endl;
               return;
           }*/
       }
        cout<<"NO"<<endl;
    }
    return;
}
int32_t main()
{
    fastio();
    auto start1 = high_resolution_clock::now();
    solve();
    auto stop1 = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop1 - start1);
}