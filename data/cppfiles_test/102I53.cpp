//code by thesixpathguy 

//libraries
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

//fast code execution
#pragma GCC optimize("Ofast")
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")


//namespaces
using namespace std;
using namespace __gnu_pbds;

//template
#define lint                     long long 
#define setbits(x)              __builtin_popcountll(x)
#define zrbits(x)               __builtin_ctzll(x)
#define zlbits(x)               __builtin_clzll(x)
#define parsbits(x)             __builtin_parityll(x)
#define mem(a, b)               memset(a, (b), sizeof(a))
#define high(a,b)               (lint)ceil((long double)a/(long double)b)
#define low(a,b)                (lint)floor((long double)a/(long double)b)
#define MOD                     1000000007
#define prime_1                 911382323
#define prime_2                 972663749 //use as mod in string hashing
#define inf                     1e17 
#define neginf                  -1e17 
#define sp(x,y)                 fixed<<setprecision(x)<<y
#define testcase(t)             lint t; cin>>t; while(t--)
#define all(v)                  v.begin(),v.end()   
#define power(a,b)              (double)pow((double)a,(double)b)
#define FOR(i,n)                for(lint i=0;i<n;i++)
#define gcd(a,b)                __gcd(a,b)
#define PI                      3.1415926535
#define endl                    "\n"
#define pb                      push_back
#define ss                      second
#define ff                      first
#define XX                      real()
#define YY                      imag()
#define umap                    unordered_map           
#define ummap                   unordered_multimap
#define uset                    unordered_set
#define umset                   unordered_multiset
#define pq_greater              priority_queue <lint, vector<lint>, greater<lint>>
             
typedef unsigned long long   ull;

typedef tree<lint,null_type,less<lint>,rb_tree_tag,
tree_order_statistics_node_update> indexed_set;
//member functions :
//1. order_of_key(k) : number of elements strictly lesser than k
//2. find_by_order(k) : k-th element in the set, counting from 0
//less_equal

//debug statements start (does not debug array)
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
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif
void debug_array(lint *arr,lint n)
{
    cerr<<"[";
    for(lint i=0;i<n;i++)
    {
        cerr<<arr[i]<<" ";
    }
    cerr<<"]";
    cerr<<endl;
}
//debug statements end
 
//fast input output and file handling         
void c_p_c()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("C:\\Users\\pranjal bhatt\\Desktop\\code contests\\input1cc.txt", "r", stdin);
    freopen("C:\\Users\\pranjal bhatt\\Desktop\\code contests\\output1cc.txt", "w", stdout);
    #endif
}

//directions
//up,right,down,left (clockwise)
lint dx[]={0,1,0,-1};
lint dy[]={1,0,-1,0};

//useful functions
lint me(lint x, lint y, lint p)  
{  
    // (x^y)%p
    lint res=1;     
    x=x%p;           
    if(x==0)return 0;          
    while(y>0)  
    {                  
        if(y&1)  
        res=(res*x)%p;  
        y=y>>1;  
        x=(x*x)%p;  
    }  
    return res;  
}

lint  modInverse(lint a, lint m) 
{ 
    lint GCD=__gcd(a, m); 
    if (GCD!=1) 
        return -1;
    else
    { 
        return me(a, m-2, m); 
    } 
} 

//O(log m)
lint  modDivide(lint a,lint b,lint m) 
{   
    //(a/b)%m
    a=a%m; 
    lint inv=modInverse(b,m); 
    if (inv==-1) 
       return -1;
    else
       return (inv*a)%m; 
}

    /*---------------------------SOLUTION---------------------------------*/

//solve function
void solve(lint tc)
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    lint n,m;
    cin>>n>>m;
    string s;
    cin>>s;
    lint len=s.length();


    lint r=1;
    lint c=1;
    lint sr1=1;
    lint sc1=1;
    lint c1=0;
    for(lint i=0;i<len;i++)
    {
        if(s[i]=='L')
            c--;
        if(s[i]=='R')
            c++;
        if(s[i]=='U')
            r--;
        if(s[i]=='D')
            r++;
        if(r<1)
        {
            r=1;
            if(sr1==n)
                break;
            sr1++;
        }
        if(c<1)
        {
            if(sc1==m)
                break;
            c=1;
            sc1++;
        }
        if(c>m)
            break;
        if(r>n)
            break;
        c1++;
    }






    r=1;
    c=m;
    lint sr2=1;
    lint sc2=m;
    lint c2=0;
    for(lint i=0;i<len;i++)
    {
        if(s[i]=='L')
            c--;
        if(s[i]=='R')
            c++;
        if(s[i]=='U')
            r--;
        if(s[i]=='D')
            r++;
        if(r<1)
        {
            if(sr2==n)
                break;
            r=1;
            sr2++;
        }
        if(c>m)
        {
            if(sc2==1)
                break;
            c=m;
            sc2--;
        }
        if(c<1)
        {
            break;
        }
        if(r>n)
            break;
        c2++;
    }


    r=n;
    c=m;
    lint sr3=n;
    lint sc3=m;
    lint c3=0;
    for(lint i=0;i<len;i++)
    {
        if(s[i]=='L')
            c--;
        if(s[i]=='R')
            c++;
        if(s[i]=='U')
            r--;
        if(s[i]=='D')
            r++;
        if(r>n)
        {
            if(sr3==1)
                break;
            r=n;
            sr3--;
        }
        if(c>m)
        {
            if(sc3==1)
                break;
            c=m;
            sc3--;
        }
        if(c<1)
            break;
        if(r<1)
            break;
        c3++;
    }



    r=n;
    c=1;
    lint sr4=n;
    lint sc4=1;
    lint c4=0;
    for(lint i=0;i<len;i++)
    {
        if(s[i]=='L')
            c--;
        if(s[i]=='R')
            c++;
        if(s[i]=='U')
            r--;
        if(s[i]=='D')
            r++;
        if(r>n)
        {
            if(sr4==1)
                break;
            r=n;
            sr4--;
        }
        if(c<1)
        {
            if(sc4==m)
                break;
            c=1;
            sc4++;
        }
        if(c>m)
            break;
        if(r<1)
            break;
        c4++;
    }

    if(c1>=max(c2,max(c3,c4)))
    {
        cout<<sr1<<" "<<sc1<<endl;
    }
    else if(c2>=max(c1,max(c3,c4)))
    {
        cout<<sr2<<" "<<sc2<<endl;
    }
    else if(c3>=max(c1,max(c2,c4)))
    {
        cout<<sr3<<" "<<sc3<<endl;
    }
    else
    {
        cout<<sr4<<" "<<sc4<<endl;
    }


}

//main function
int main()
{
    c_p_c();
    lint flg99=1;
    if(flg99==1)
    {
        lint tc=1;
        testcase(t)
        {
            solve(tc);
            tc++;
        }
    }
    else
    {
        lint tc=1;
        solve(tc);
    }
    return 0;
            
}
