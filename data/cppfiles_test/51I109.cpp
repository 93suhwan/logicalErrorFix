//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx,avx2,fma")

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <chrono>

using namespace __gnu_pbds;
using namespace std;


#define int long long int
#define newl cout << "\n"
#define endl "\n"
#define deb(x) cerr <<#x<<" = "<<x << endl
#define deb2(x, y) cerr<<#x<<" = "<<x<<" & "<<#y<<" = "<<y<<endl
#define priority_queue_small priority_queue<int, vi, greater<int>>
#define pii pair<int, int>
#define ff first
#define ss second
#define fastio ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define PI 3.1415926535897932384626433832795
#define MOD 1000000007
#define INF LONG_LONG_MAX
#define all(x) x.begin(), x.end()
#define state(x) {cout << x << endl; return 0;}
#define addCP cout << "checkpt : " << cpcnt++ << endl
#define smaller_than(x, y) lower_bound(all(x), y) == x.begin() ? x.end() : -- lower_bound(all(x), y)


int cpcnt;
mt19937                 rng(chrono::steady_clock::now().time_since_epoch().count());
void io();
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;

template <typename T>ostream& operator<<(ostream& os, const vector<T>& v){os << "[";for (int i = 0; i < v.size(); ++i) {os << v[i];if (i != v.size() - 1)os << ", ";}os << "]\n";return os;}
template <typename T>ostream & operator << (std::ostream & os, const vector<vector<T>> & matrix){for(int i = 0 ; i < matrix.size(); i++){os<<"[";for (int j = 0; j < matrix.at(i).size(); j++){os<<matrix[i][j];if (j != matrix.at(i).size() - 1) os<<", ";}os<<"]\n";}os<<endl;return os;}
template <typename T>ostream& operator<<(ostream& os, const set<T>& v){os << "[";for (auto it : v) {os << it;if (it != *v.rbegin())os << ", ";}os << "]\n";return os;}
template <typename T>ostream& operator<<(ostream& os, const multiset<T>& v){int s = v.size();os << "[";for (auto it : v) {os << it;if (--s != 0)os << ", ";}os << "]\n";return os;}
template <typename T, typename S>ostream& operator<<(ostream& os, const map<T, S>& v){for (auto it : v) os << it.first << " : " << it.second << "\n";return os;}
template <typename T, typename S>ostream& operator<<(ostream& os, const pair<T, S>& v){os << "(";os << v.first << ", " << v.second << ")";return os;}
template <typename T>ostream& operator<<(ostream& os, const unordered_set<T>& v){os << "(";int size = v.size();for (auto it : v) {os << it;if (size -- != 1)os << ", ";}os << ")\n";return os;}
template <typename T, typename S>ostream& operator<<(ostream& os, const unordered_map<T, S>& v){for (auto it : v) os << it.first << " : " << it.second << "\n";return os;}


void solve(){
    int n;
    cin >> n;

    cout << "-" << n - 1 << " " << n << endl;
}

int32_t main(){
    auto s = chrono::high_resolution_clock::now();
    fastio;
    int t = 1;
    cin >> t;
    while(t--){
        cpcnt = 1;
        solve();
    }
    auto f = chrono::high_resolution_clock::now();
    double tt = chrono::duration_cast<chrono::nanoseconds>(f - s).count();
    cerr << "Execution time: " << fixed << tt * (1e-9) << setprecision(9), cerr << " sec" << endl;
    return 0;
}

void io(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    #endif
}
