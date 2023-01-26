#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define PI 3.141592653589793238462
#define pb push_back
#define all(x) x.begin(), x.end()
typedef long long ll;
const ll MOD = 1e9+7;

#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x)
#endif
 
void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(double t) {cerr << t;}


template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
ll lcm(ll a, ll b){ ll prod = a*b; return prod/__gcd(a, b); }
int getTest(){ return rand()%100; }

void solve()
{
    string a, s;
    cin>>a>>s;
    int l1 = a.length(), l2 = s.length();
    
    string b = "";
    int i = l1-1, j = l2-1;
    while(i>= 0 and j>=0){
        int num1 = a[i] - '0';
        int num2 = s[j] - '0';
        debug(num1); debug(num2);
        if (num2 < num1 and j > 0) {
            j--;
            int x = s[j] - '0';
            num2 = x * 10 + num2;
            debug(num2);
            int diff = num2 - num1;
            if (num2 > 9 and num2 <= 18) {
                b.pb(diff + '0');
            }
            else {
                cout << -1 << endl;
                return;
            }
        }
        else{
            b.pb((num2 - num1) + '0');
        }

        i--; j--;
    }
    while(j >= 0)
        b.pb(s[j--]);

    if (i >= 0){ 
        cout<<-1<<endl;
    }
    else{
        while(b.back() == '0'){
         b.pop_back();
        }
        reverse(all(b));
        cout<<b<<endl;
    }
}


int main()
{
    #ifndef ONLINE_JUDGE
    freopen("Error.txt", "w", stderr);
    #endif
    IOS;
    int t;
    cin >> t;
    while(t--)
    {
      solve();
    }
    return 0;
}