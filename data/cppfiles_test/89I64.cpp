#include <bits/stdc++.h>
#include <iomanip>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

#define ninja ios_base::sync_with_stdio(false);cin.tie(NULL);
#define tc int test_cases; cin >> test_cases; while(test_cases--)
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
#define ll long long
#define ld long double
#define ul unsigned long long
#define mod 1000000007

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}

void AilaJaadu()
{
    ninja;
    #ifndef ONLINE_JUDGE
        freopen("error.txt", "w", stderr);
        #define debug(x...) cerr << "[" << #x << "] = ["; _print(x);
    #else
        #define debug(x...)
    #endif
}

bool pr[(int)1e5+1];
vector<int>v;
int main()
{
    AilaJaadu();
    for(int i=2; i<=(int)1e5; i++)
    {
        for(int j=2*i; j<=(int)1e5; j+=i)
            pr[j] = true;
    }
    for(int i=2; i<=(int)1e5; i++)
        if(pr[i] == false)v.push_back(i);
    tc
    {
        int n; cin >> n;
        ll a[n+1];
        for(int i=1; i<=n; i++)
            cin >> a[i];
        bool poss = true;
        for(int i=1; i<=n; i++)
        {
            if(a[i]%2 != 0)
                continue;
            else
            {
                int num = -1;
                for(auto &j : v)
                {
                    if(j > i+1)
                        break;
                    if(a[i]%j != 0)
                    {
                        num = j;
                        break;
                    }
                }
                if(num == -1)
                {
                    debug(a[i] , num, i);
                    poss = false;
                    break;
                }
            }
        }

        if(poss)
            cout <<"YES\n";
        else
            cout << "NO\n";
    }
}