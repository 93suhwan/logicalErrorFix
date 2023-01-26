/********************************/
//                              //
// Code By-                     //
//                              //
// *******        ***           //
//    *          *              //
//    *          *   ***        //
//    * ushar     ***  * upta   //
//                              //
//    aka Algoristy  (अल्गोरिस्टी)//
//                              //
/********************************/

#include<bits/stdc++.h>
#include<stdio.h>
using namespace std;

typedef long long int in;
typedef unsigned long long ull;
typedef long double lld;
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

#define loop(i, b) for(in i=0;i<b;i++)
#define dloop(i, a, b) for(in i=a;i<=b;i++)
#define rloop(i,n) for(in i=n-1;i>=0;i--)
#define drloop(i, a, n) for(in i=n;i>=a;i--)
#define pb(a) push_back(a)
#define all(a) a.begin(),a.end()
#define trav(a,b) for(auto &a: b)
#define rtrav(a,b) for (auto a = b.rbegin(); a != b.rend(); a++) //use*a
#define mod1 1000000007
#define mod2 998244353
#define NO printf("No\n")
#define YES printf("Yes\n")
#define ff first
#define ss second
#define elif else if
#define gcd(a, b) (__gcd((a), (b)))
inline in lcm(in a, in b) {return a / gcd(a, b) * b;}
#define prec(n) fixed<<setprecision(n)
const in PI = acos((in) - 1);
in powerm(in x, in y, in m) {
    in res = 1; x = x % m; if (x == 0) return 0;
    while (y > 0) {if (y & 1) res = (res * x) % m; y = y >> 1; x = (x * x) % m;} return res;
}
in power(in x, in y) {
    in res = 1; if (x == 0) return 0;
    while (y > 0) {if (y & 1) res = (res * x); y = y >> 1; x = (x * x);} return res;
}
inline in fpow(in n, in k, in p = mod1) {in r = 1; for (; k; k >>= 1) {if (k & 1) r = r * n % p; n = n * n % p;} return r;}
inline in inv(in a, in p = mod1) {return fpow(a, p - 2, p);}
#define MAX 1000001
in summ(in a, in b, in m = mod1) {return (a % m + b % m) % m;}
in difm(in a, in b, in m = mod1) {return (a % m - b % m) % m;}
in mulm(in a, in b, in m = mod1) {return (a % m * b % m) % m;}

#ifndef ONLINE_JUDGE
#define debug(bnm) cerr << #bnm <<" "; _print(bnm); cerr << endl
#else
#define debug(bnm)
#endif

void _print(in t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(lld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}

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

in to_int(char c){
    return (in)(c - '0');
}

void Solve() {

    string s1,s2;
    cin>>s1>>s2;

    if(s1.size() < s2.size()){
        cout<<"NO"<<endl;
        return;
    }

    in pos = 0;
    string temp = "";
    loop(i, s1.size()){

        // cout<<"i: "<<i<<endl;

        in cnt1 = 0;
        in cnt2 = 1;

        if(s1[i] == s2[pos] && i == 0){
            in ind = 0;
            while(s1[ind] == s1[0]) cnt1++, ind++;
            cnt1--;
            ind = 0;
            while(s2[ind] == s2[0]) cnt2++, ind++;
            cnt2--;

            loop(i, cnt2) temp.pb(s1[0]);
            if(cnt1 < cnt2){
                i += cnt1;
                pos += cnt1;
            }
            else{
                i += cnt1;
                pos += cnt2;
            }
        }
        elif(s1[i] == s2[pos]){
            temp.pb(s1[i]);
            pos++;
        }
        elif(i == 0){
            while(s1[i] != s2[pos]) i++;
            i--;
        }
        else i++;
    }

    // cout<<"temp: "<<temp<<endl;

    if(temp == s2) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;

}


int main() {
#ifndef ONLINE_JUDGE
    freopen("Error.tbnmt", "w", stderr);
#endif
    in t;
    cin >> t;
    while(t--) 
        Solve();
    return 0;
}