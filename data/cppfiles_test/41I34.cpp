//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define FIO ios_base::sync_with_stdio(false); cin.tie(0);
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define endl "\n"
#define case(t) cout << "Case #" << (t) << ": "
#define pii pair<int, int>
#define pb push_back
#define mp make_pair
#define st first
#define nd second
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef long double ld;
typedef cc_hash_table<int,int,hash<int>> ht;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> oset;
const double pi = acos(-1);
const int mod = 1e9 + 7;
const int inf = 1e9 + 7;
const int N = 1e6 + 5;
const ld eps = 1e-9;

template<class T> void read(T& x) { cin >> x; }
template<class X, class Y> void read(pair<X,Y>& a) { read(a.first), read(a.second); }
template<class T, size_t U> void read(array<T,U>& x) { for (int i = 0; i < U; i++) read(x[i]); }
template<class T> void read(vector<T>& x) { for(auto& y: x) read(y); }
template<class T, class... O> void read(T& x, O&... y) { read(x), read(y...); }

string to_string(const char& x) { return string(1,x); }
string to_string(const char*& x) { return (string)x; }
string to_string(const string& x) { return x; }
template<class T, class U> string to_string(const pair<T,U>& x) { return to_string(x.first) + " " + to_string(x.second); }
template<class T, size_t U> string to_string(const array<T,U>& x) { string ret = ""; for (int i = 0; i < U; i++) ret += (!i ? "" : " ") + to_string(x[i]); return ret; }
template<class T> string to_string(const vector<T>& x) { string ret = ""; bool f = 0; for(auto& y: x) ret += (!f ? "" : " ") + to_string(y), f = 1; return ret; }
template<class T> string to_string(const set<T>& x) { string ret = ""; bool f = 0; for(auto& y: x) ret += (!f ? "" : " ") + to_string(y), f = 1; return ret; }
void print() { cout << endl; }
template<class T> void pr(const T& x) { cout << to_string(x); }
template<class T, class... O> void print(const T& x, const O&... y) { pr(x); if (sizeof...(y)) pr(" "); print(y...); }

int main() {
  FIO
  int n, k; read(n, k);
  print((n + k - 1) / k);
  for (int i = 1; i <= n; i++) {
    for (int j = i + 1; j <= n; j++) {
      pr((j - 1) / k + 1), pr(" ");
    }
  }
}
