/* created by "@princecodes" */
/*        "@mojkrdibete" */

/*--------------------------------------------------------------------------*/

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <functional>
using namespace std;
/* using namespace __gnu_pbds; */

#define IOS                                                                    \
  ios_base::sync_with_stdio(false);                                            \
  cin.tie(0);                                                                  \
  cout.tie(0);
#define int long long
#define nline "\n"
#define pb push_back
#define pob pop_back
#define mp make_pair
#define ff first
#define ss second
#define lb lower_bound
#define ub upper_bound
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define PI 3.141592653589793
#define MOD 1000000007
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) a *b / gcd(a, b)

typedef vector<int> vi;
typedef set<int> si;
typedef pair<int, int> pi;
typedef vector<vi> vvi;
typedef vector<pi> vp;
typedef map<int, vi> mv;
typedef map<int, int> mi;
typedef priority_queue<int> pq;
typedef priority_queue<int, vi, greater<int>> pqr;
/* typedef tree<int, null_type, less<int>, rb_tree_tag, */
/*              tree_order_statistics_node_update>pbds; */

/*--------------------------------------------------------------------------*/

void bhaag_bsdk() {

  int n;
  cin >> n;
  string s;
  cin >> s;

  vi arr;
  for (int i = 0; i < n; i++)
    if (s[i] == '1')
      arr.pb(i);

  vector<vector<char>> ans(n, vector<char>(n, '.'));
  for (int i = 0; i < n; i++) {
    ans[i][i] = 'X';
  }
  for (int i : arr) {
    for (int j = 0; j < n; j++)
      if (ans[i][j] != 'X')
        ans[i][j] = '+', ans[j][i] = '-';
  }
  for (int i = 0; i < arr.size(); i++)
    for (int j = 0; j < arr.size(); j++)
      if (i != j)
        ans[arr[i]][arr[j]] = '=';

  for (int i = 0; i < n; i++) {
    bool flg = false;
    for (int j = 0; j < n; j++) {
      if (ans[i][j] == '+') {
        flg = true;
        break;
      }
      if (ans[i][j] == '.') {
        ans[i][j] = '+';
        ans[j][i] = '-';
        flg = true;
        break;
      }
    }
    if (!flg && s[i] != '1') {
      cout << "NO" << nline;
      return;
    }
  }
  cout << "YES" << nline;
  for (auto k : ans) {
    for (auto m : k)
      cout << (m == '.' ? '-' : m);
    cout << nline;
  }
}
/*--------------------------------------------------------------------------*/

signed main() {
  /* auto start=chrono::high_resolution_clock::now(); */
  /* freopen("input.txt", "r", stdin); */
  /* freopen("output.txt", "w", stdout); */
  IOS;
  int t = 1;
  cin >> t;
  while (t--) {
    bhaag_bsdk();
  }
  /* auto stop=chrono::high_resolution_clock::now(); */
  /* auto duration=chrono::duration_cast<chrono::microseconds>(stop-start); */
  /* cerr<<duration.count/1e3<<"ms\n" */
}
