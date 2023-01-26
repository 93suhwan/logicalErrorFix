#include <bits/stdc++.h>
#define int long long
#define float double
#define sz 100005
#define all(a) a.begin(), a.end()
#define mod 1000000007
using namespace std;
#define vi vector<int>
#define vvi vector<vector<int>>
#define debug cout << "here" << endl;
#define rep(i, n) for (int i = 0; i < n; ++i)
#define pb push_back
#define ff first
#define ss second
#define pi pair<int, int>
using namespace std;

#define deb(...) logger(#__VA_ARGS__, __VA_ARGS__)
template<typename ...Args>
void logger(string vars, Args&&... values) {
    cout << vars << " = ";
    string delim = "";
    (..., (cout << delim << values, delim = ", "));
}

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};


void enumerateSubmasks(int m)
{
    // visits submasks without repetition and in descending order
    for (int s = m;; s = (s - 1) & m)
    {

        if (s == 0)
        {
            //...
            break;
        }
    }
}

int mpow(int a, int b, int m)
{
    if (b == 0)
        return 1;
    int x = mpow(a, b / 2, m);
    x = (x * x) % m;
    if (b % 2)
    {
        x = (x * a) % m;
    }
    return x;
}

void printBinaryString(int n)
{
    vi temp;
    while (n)
    {
        if (n & 1)
            temp.pb(1);
        else
            temp.pb(0);
        n = n >> 1;
    }
    reverse(temp.begin(), temp.end());
    for (auto node : temp)
        cout << node << " ";
    cout << endl;
}

void readVector(vi &a)
{
    int n = a.size();
    rep(i, n) cin >> a[i];
}

int build(int s,int e,int index, vi &seg,vi &arr){

    if(s > e) return 0;

    if(s == e){
        return seg[index] = arr[s];
    }

    int mid = (s+e)/2;

    return seg[index] = __gcd(build(s,mid,2*index,seg,arr),build(mid+1,e,2*index+1,seg,arr));

}

int query(int s,int e,int qs,int qe,int index, vi &seg){
    if(qs > e || qe < s) return 0;
    if(s > e) return 0;

    if(qs <=s && qe >= e) return seg[index];

    int mid = (s+e)/2;

    return __gcd(query(s,mid,qs,qe,2*index,seg),query(mid+1,e,qs,qe,2*index+1,seg));

}

//vi primes;
//vi primesVisited(sz,false);
int32_t main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    //    for(int i = 2 ; i < sz ; i++){
    //        if(primesVisited[i]) continue;
    //        primes.pb(i);
    //        for(int j = i*i ; j < sz ; j+=i) primesVisited[j] = true;
    //    }

    int tc;
    cin >> tc;
    while(tc--){
        int x,n;
        cin >> x >> n;
        int sum = 0;



        int v = (n/4)*(-1);

        if(n%4 == 0) v =0;
        if(n%4 == 1) v = -n;
        if(n%4 == 2) {
            v = 1;
        }
        if(n%4 == 3) v = n;
//
//        if(n%4 == 1) v += n;
//        if(n%4 == 2) v += ( 2*n - 1);
//        if(n%4 == 3) v += (n-2 + n-1 - n);

        if(x%2 == 0){
            cout << x + v << endl;
        }else cout << x-v << endl;
    }
}
