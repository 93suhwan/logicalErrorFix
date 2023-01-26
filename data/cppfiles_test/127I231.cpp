#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds; 
#define mod 1000000007
#define int int64_t
#define bin(n) std::bitset<32>(n).to_string()
#define str(n) to_string(n)

#define Randomize mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define Rand(a,b) uniform_int_distribution<int>(a,b)(rng)

void inout();
 
void solution()
{
    string s;
    cin>>s;
    string t;
    cin>>t;
    unordered_map<char,int>m;
    for(int i = 0;i<s.length();i++)
    m[s[i]]++;
    string res = "";
    if(t[0]=='a')
    {
        for(int i = 1;i<=m['b'];i++)
        {
           res.push_back('b');
        }
        for(int i = 1;i<=m['c'];i++)
        res.push_back('c');
        for(int i = 1;i<=m['a'];i++)
        res.push_back('a');
    }
    else{
         for(int i = 1;i<=m['a'];i++)
        res.push_back('a');
        for(int i = 1;i<=m['b'];i++)
        {
           res.push_back('b');
        }
         for(int i = 1;i<=m['c'];i++)
        res.push_back('c');
    }
    m.erase('a');
    m.erase('b');
    m.erase('c');
    for(auto x:m)
    {
        for(int i = 1;i<=x.second;i++)
        res.push_back(x.first);
    }
    cout<<res<<endl;
}
 
int32_t main()
{
    inout();
    int TC = 1;
    cin >> TC;
    for(int tt=1;tt<=TC;tt++)
    {
        
        solution();
    }
 
    return 0;
}
 
void inout()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}