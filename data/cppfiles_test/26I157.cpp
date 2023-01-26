#include<bits/stdc++.h>
#include <unordered_map>
#define ll long long

#define test() int t;cin>>t;while(t--)
#define KStest() int t,t1;cin>>t;t1=t;while(t--)
#define KScout cout<<"Case #"<<t1-t<<": "

// int dx {0, 1, 0, -1};
// int dy{1, 0, -1, 0};
const int mod = 1e9 + 7, MAX = 1e6 + 5;
const ll inf = 1e18 + 5;
const double pi = 3.14159265358979323846;

// int dx[4] = {0, 1, 0, -1};
// int dy[4] = {1, 0, -1, 0};
using namespace std;
bool correct(int i , int j, int n, int m) {

    if (i < 0 || i >= n || j < 0 || j >= m) {
        return false;
    }
    return true;
}
ll gcd(ll a, ll b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int lcm(int a, int b)
{
    return (a / gcd(a, b)) * b;
}
ll power(ll x, ll y)
{
    ll temp = 1ll;

    while (y)
    {
        if (y & 1) temp = (temp * x);
        //temp%=mod;
        x = (x * x);
        y = y >> 1;
    }
    return temp;
}


bool sieve[10000002];
vector<ll> primes;
void makeSieve()
{
    int N = 1e5 + 1;
    for (int i = 0; i < N; i++)
    {
        if (i & 1)
            sieve[i] = true;
        else
            sieve[i] = false;
    }
    sieve[1] = false;
    sieve[2] = true;
    for (int i = 3; i * i <= N; i += 2)
    {
        if (sieve[i])
        {
            for (int j = i * i; j <= N; j += (2 * i))
                sieve[j] = false;
        }
    }
    for (int i = 3; i < N; i++)
    {
        if (sieve[i])
            primes.push_back(i);
    }
}
bool pot(ll n)
{
    if (n == 0)
        return 0;
    while (n != 1)
    {
        if (n % 2 != 0)
            return 0;
        n = n / 2;
    }
    return 1;
}

bool comparer(pair<int, int > a, pair<int, int>b) {
    if (a.first == b.first) {
        return a.second < b.second;
    }
    return a.first > b.first;
}

//array of vectors vector<int>* arr=new vector<int>[n];
//Vai Sublime mei dikkat nahi h, tere code mei dikkat h
//upsolve krle vai plis 八(＾□＾*)

string decToBinary(int n)
{
    // Size of an integer is assumed to be 32 bits
    string ans = "";
    for (int i = 101; i >= 0; i--) {
        int k = n >> i;
        if (k & 1)
            ans += '1';
        else
            ans += '0';
    }
    return ans;
}

//     int** a = new int*[n];

//     for (int i = 0; i < n; i++) {

//         // Declare a memory block
//         // of size n
//         a[i] = new int[m];
//     }


ll factorial(ll n)
{
    ll res = 1, i;
    for (i = 2; i <= n; i++) {
        res = (res * i);
        res %= mod;
    }
    return res % mod;
}
ll nCr(ll n, ll r)
{

    long long p = 1, k = 1;
    if (n - r < r)
        r = n - r;

    if (r != 0) {
        while (r) {
            p *= n % mod;
            k *= r % mod;


            long long m = __gcd(p, k);


            p /= m;
            k /= m;

            n--;
            r--;
        }


    }

    else
        p = 1;


    return p;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    test() {
        ll n;
        cin >> n;
        ll temp = nCr(2 * n - 1, n) % mod;
        temp = temp * (factorial(n) % mod) % mod;
        temp = temp * (factorial(n) % mod) % mod;
        cout << temp  << endl;
    }

    return 0;

}