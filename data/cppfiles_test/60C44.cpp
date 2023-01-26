#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 7;
const int mod = 998244353;
const int infi = (2e9 + 69);
const long long infy = (2e16 + 69);
const int base = 311;
const long long MM = 7ll * mod * mod;
const int addition = 1e6 + 5e5;
const double eps = 1e-9;
const string numd[10] = {"1110111", "0010010", "1011101", "1011011", "0111010",
                         "1101011", "1101111", "1010010", "1111111", "1111011"};
const int dx[] = {-1, 0, 1, 1, 1, 0, -1, -1};
const int dy[] = {1, 1, 1, 0, -1, -1, -1, 0};
const double pi = 3.14159265358980;
const string P1 = "ALICE";
const string P2 = "BOB";
const string spmcode =
    "My power does not end. Ask for aid and you will receive it.\n";
int ct = 0;
template <typename Num>
void maximize(Num &x, Num y) {
  x = mx(x, y);
}
template <typename Num>
void minimize(Num &x, Num y) {
  x = min(x, y);
}
void exit_with_runtime() {
  double x = 1.0 * clock() / CLOCKS_PER_SEC;
  cerr << "\n\n---------------------\nTime elapsed: " << x << " s.\n\n";
  exit(0);
}
void decorate() {
  cerr << "KienNguyen246\n";
  chrono::system_clock::time_point today = chrono::system_clock::now();
  time_t tt = chrono::system_clock::to_time_t(today);
  cerr << ctime(&tt);
  cerr << "\nProcessing...\n\n";
}
int n, a[maxn];
map<int, int> M;
void Main_Process() {
  cin >> n;
  double SS = 0;
  long long sum = 0;
  M.clear();
  for (int i = 1; i <= n; i++) cin >> a[i], SS += a[i], sum += a[i], M[a[i]]++;
  SS = SS / n * (n - 2);
  long long S = SS;
  if (abs(SS - S) > 1e-13) {
    cout << 0 << "\n";
    return;
  }
  sum -= S;
  long long res = 0;
  for (auto i : M) {
    long long t = i.first;
    if (sum - t != t)
      res += 1ll * M[t] * M[sum - t];
    else
      res += 1ll * M[t] * (M[t] - 1);
  }
  cout << res / 2 << "\n";
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  decorate();
  int test = 1;
  cin >> test;
  while (test--) {
    ct++;
    Main_Process();
  }
  exit_with_runtime();
}
