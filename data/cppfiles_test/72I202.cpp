#include <bits/stdc++.h>
#include<iostream>
#include<string.h>
#include <chrono>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace  __gnu_pbds;
using namespace std::chrono;

#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")

#define int long long
#define ll long long
#define lcm(a,b) a*b/__gcd(a,b)
#define gcd(a,b) __gcd(a,b)

//vectors & pairs
#define all(a) a.begin(),a.end()
#define pb(x) push_back(x)
#define eb(x,y) emplace_back(x,y)
#define vi  vector<int>
#define vvi vector<vector<int>>
#define vp vector<pair<int,int>>
#define sortVA(a) sort(a.begin(),a.end())
#define sortVD(a) sort(a.rbegin(),a.rend())
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

//pair
// #define f first
// #define s second

//constants
int MOD = 1000000007;
int INF = (1e18 + 5);
#define endl "\n"

//loop
#define vff(a) for(auto &x: a)
#define read(a) for(auto &x: a) cin>>x;
#define put(a) for(auto &x: a) cout<<x<<" "; cout<<endl;;

//debug
#define deb1(x)             cout<<#x<<"="<<x<<endl
#define deb2(x, y)          cout<<#x<<"="<<x<<" "<<#y<<"="<<y<<endl
#define deb3(x, y, z)       cout<<#x<<"=" <<x<<" "<<#y<<"="<<y<<" "<<#z<<"="<<z<<endl
#define deb4(a,b,c,d)       cout<<#a<<"="<<a<<" "<<#b<<"="<<b<<" "<<#c<<"="<<c<<" "<<#d<<"="<<d<<endl
#define deb5(a,b,c,d,e)     cout<<#a<<"="<<a<<" "<<#b<<"="<<b<<" "<<#c<<"="<<c<<" "<<#d<<"="<<d<<" "<<#e<<"="<<e<<endl
#define deb6(a,b,c,d,e,f)   cout<<#a<<"="<<a<<" "<<#b<<"="<<b<<" "<<#c<<"="<<c<<" "<<#d<<"="<<d<<" "<<#e<<"="<<e<<" "<<#f<<"="<<f<<endl
#define GET_MACRO(_1,_2,_3,_4,_5,_6,NAME,...) NAME
#define deb(...) GET_MACRO(__VA_ARGS__,deb6,deb5, deb4, deb3, deb2, deb1)(__VA_ARGS__)

template<typename T> using ordered_set = tree<T, null_type,less<T>, rb_tree_tag,tree_order_statistics_node_update>;


//helper functions
ll ceil_div(ll x, ll y){
    return (x + y - 1) / y;
}


//coding starts here
void test_cases(){

    string s;
    int k;
    cin>>s>>k;

    int n = s.length();

    set<char> st;
    string ans;
    map<int,int> mp;
    // int flag=0;
    for(int i=0; i<n; i++){
        st.insert(s[i]);
        mp[s[i]]++;
        if((int)st.size()>k){
            // flag=1;
            st.erase(s[i]);
            char chh = '1';
            if(s[i] < *prev(st.end())){
                vff(st){
                    if(x > s[i]){
                        chh = x;
                        break;
                    }
                }
                ans.pb(chh);
                for(int j=i+1; j<n; j++){
                    ans.pb(*st.begin());
                }
            }
            else{
                set<int> here;
                string anshere;
                int p=0;
                auto it = st.upper_bound(s[i-1]);
                if(it==st.end()){
                    for(int j=0; j<n; j++){
                        here.insert(s[j]);
                        if((int)here.size()>k-1){
                            here.erase(s[j]);
                            char cc = (char)(s[j]+1);
                            if(here.find(cc) != here.end()){
                                here.insert('0');
                            }
                            else{
                                here.insert(cc);
                            }
                            anshere.pb(cc);
                            p=j+1;
                            // anshere.pb(s[i]);
                            break;
                        }
                        anshere.pb(s[j]);
                    }
                    // deb(anshere, p);
                    for(int j=p; j<n; j++){
                        anshere.pb(*here.begin());
                    }
                    ans = anshere;
                }
                else{
                    // cout<<"YES"<<endl;
                    if(mp[ans.back()]==1){
                        ans.back() = (*it);
                        for(int j=i; j<n; j++){
                            ans.pb('0');
                        }
                    }
                    else{
                        ans.back() = (*it);
                        for(int j=i; j<n; j++){
                            ans.pb(*st.begin());
                        }
                    }
                }
            }
            break;
        }
        ans.pb(s[i]);
    }
    cout<<ans<<endl;
    // }
    // else{
    //     string anshere;
    //     set<char> ss;
    //     int p=n;
    //     for(int i=1; i<n; i++){
    //         if(s[i]<=s[0]){
    //             ss.insert(s[i]);
    //             anshere.pb(s[i]);
    //         }
    //         else{
    //             anshere.pb(s[i]);
    //             p=i+1;
    //             break;
    //         }
    //     }
    //     for(int i=p; i<n; i++){
    //         anshere.pb(*ss.begin());
    //     }
    //     cout<<anshere<<endl;
    // }
    return;
}


int32_t main()
{

    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T=1;
    cin>>T;
    while(T--){
        test_cases();
    }
    return 0;
}
