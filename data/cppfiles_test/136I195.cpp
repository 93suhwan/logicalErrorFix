#include <bits/stdc++.h>

using namespace std;

#define int                     long long
#define ll                      long long
#define ld                      long double
#define pb                      push_back
#define mp                      make_pair
#define f                       first
#define s                       second
#define all(x)                  (x).begin(), (x).end()
#define LOL                     cout << '\n';
#define kill(x)                 {cout << x << '\n'; return;}
#define sz(x)                   ((int)(x).size())
#define deb(x)                  cout << "[" << (#x) << " = " << (x) << "]" << '\n'
#define deb2(x, y)              cout << "[" << (#x) << " = " << (x) << "] [" << (#y) << " = " << (y) << "]" << '\n'
#define deb3(x, y, z)           cout << "[" << (#x) << " = " << (x) << "] [" << (#y) << " = " << (y) << "] [" << (#z) << " = " << (z) << "]" << '\n'
#define deb4(x, y, z, p)        cout << "[" << (#x) << " = " << (x) << "] [" << (#y) << " = " << (y) << "] [" << (#z) << " = " << (z) << "] [" << (#p) << " = " << (p) << "]"<< '\n'
#define deb5(x, y, z, p, q)     cout << "[" << (#x) << " = " << (x) << "] [" << (#y) << " = " << (y) << "] [" << (#z) << " = " << (z) << "] [" << (#p) << " = " << (p) << "] [" << (#q) << " = " << (q) << "]"<< '\n'
#define deb6(x, y, z, p, q, r)  cout << "[" << (#x) << " = " << (x) << "] [" << (#y) << " = " << (y) << "] [" << (#z) << " = " << (z) << "] [" << (#p) << " = " << (p) << "] [" << (#q) << " = " << (q) << "] [" << (#r) << " = " << (r) << "]"<< '\n'

const int M     = 1e9 + 7;
const int MOD   = 998244353;
const int INF   = 0x7f7f7f7f'7f7f7f7f;
const int Nmax  = 2e5 + 15;


void solve() {

  int N; cin >> N;
  std::vector<int> v(N);
  int S = 0;
  for(auto &el:v) cin>> el, S += el;

  std::vector<int> ok;

  int e = N * (N + 1) / 2;
  
  for(int i = 0; i < N; i++)
  {
    int j = (((i - 1) % N) + N ) % N;
    int y = S + v[j] * e - v[i] * e;
    // deb(y);
    if(y == 0 || y % ((N * N * (N + 1)) / 2) != 0) kill("NO");
    ok.pb((y / (( N * N * (N + 1)) / 2)) );
  }

  cout << "YES"; LOL
  for(auto &el:ok) cout << el << ' ';LOL



}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  #ifdef Kaushal_26
    freopen("a.in", "r", stdin); 
    freopen("b.out", "w", stdout);  
    freopen("e.out", "w", stderr);
  #endif
  int _ = 1; cin >> _;
  for(int i = 1 ; i <= _ ; i++){
      // cout << "\nCase #" << i << ": \n";
      solve();
  }
  return 0;
}

// 1.77245