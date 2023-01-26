#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace std::chrono;
using namespace __gnu_pbds;


// https://codeforces.com/contest/1407/problem/D
// agr set ki tarah krna hai to less vrna agr multiset ki tarah to less_equal
#define ordered_set tree<long long int, null_type,less_equal<long long int>, rb_tree_tag,tree_order_statistics_node_update>

const long long int mod97 = 1000000007;
const long long int modg = 998244353;
const long long int inf = 1e17;
// const long long int M = 1e8;
double pi = 3.1415926536;

bool rev(long long int a, long long int b) {if (a > b)return true; else return false;}

long long int powerm(long long int a, long long int n, long long int modn)
{
    if (n == 0)return 1; if (n % 2 == 0) {long long int val = powerm(a, n / 2, modn); val = (val * val) % modn; return val;}
    else {long long int val = powerm(a, n / 2, modn); val = ((val * val) % modn * a) % modn; return val;}
}
long long int power(long long int a, long long int n)
{
    if (n == 0)return 1; if (n % 2 == 0) {long long int val = power(a, n / 2); val = (val * val); return val;}
    else {long long int val = power(a, n / 2); val = ((val * val) * a) ; return val;}
}

//https://codeforces.com/contest/670/problem/E;https://codeforces.com/contest/670
//https://www.hackerearth.com/problem/algorithm/easy-queries-751f9372/?source=list_view  lower and upper bound auto it=s.lower_bound(x),(*(it--)) mtlb x se just chota number ,it0=s.upper_bound(x);(*it0) mtlb x se just badda number
//lower bound of p mtlb p se just badda ya uske equal agr lower bound ke it ko -- kra to just chota milega agr ye it s.end hai to mtlb vo element ya usse badda element nhi hai aur agr ye sbegin hai to uss element se chota element nhi hai
//upper bound of p mtlb p se just badda uske equal nhi agr ye s.end() hai to mtlb uss element se badda element nhi hai aur agr iske it ko it-- kre to uss p se just chota ya uske equal element milega but agr ye s.begin hai to usme koi bhi element p ya p se chota nhi hai

long long int fac[1000009];
long long int fexp(long long int a, long long int b, long long int m)
{int ans = 1; while (b) {if (b & 1)ans = ans * a % m; b /= 2; a = a * a % m;} return ans;}
long long int inverse(int a, int p) {return fexp(a, p - 2, p);}
long long int ncr(long long int n, long long int r, long long int p)
{if (r == 0) return 1; return (fac[n] * inverse(fac[r], p) % p * inverse(fac[n - r], p) % p) % p;}

const long long int N = 100;

long long int spf[N];
long long int prime[N];
vector<long long int>pr;


void solve()
{
    int n; cin >> n;
    string s; cin >> s;
    int c = 0;
    for (auto x : s)if (x == '0')c = 1;
    if (c == 0)
    {
        if (n % 2 == 0)
        {
            cout << 1 << " " << n << " " << 1 << " " << n / 2 << endl;
        }
        else
        {
            cout << 1 << " " << n - 1 << " " << 1 << " " << n / 2 << endl;
        }
    }
    else
    {
        int ct = 0, ne = n / 2;
        for (int i = 1; i <= n; i++)
        {
            if (s[i - 1] == '0')
            {
                if (ct > ne)
                {
                    cout << 1 << " " << i << " " << 1 << " " << i - 1 << endl;
                }
                else
                {
                    cout << i << " " << n << " " << i + 1 << " " << n << endl;
                }
                return;
            }
            else ct++;
        }
    }
}




int main()
{
    auto start = high_resolution_clock::now();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r" , stdin);
    freopen("output.txt", "w", stdout);
#endif


    // fac[0] = 1; fac[1] = 1; for (long long int i = 2; i < 1000009; i++)fac[i] = (fac[i - 1] * i) % modg;
    int tc, ct = 0;

    tc = 1;

    //sieve
    for (long long int i = 0; i < N; i++)prime[i] = 1, spf[i] = i;
    for (long long int p = 2; p * p < N; p++)if (prime[p] == 1)for (long long int i = p * p; i < N; i += p)prime[i] = 0, spf[i] = p; prime[1] = prime[0] = 0;
    for (long long int i = 0; i < N; i++)if (prime[i])pr.push_back(i);

    cin >> tc;

    while (tc--)
    {
        solve();
    }
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cerr << "Time taken : " << duration.count() / 1000000.0 << "seconds" << "\n";
}