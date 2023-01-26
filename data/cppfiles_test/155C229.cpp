#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 7;
const int mod = 1e9 + 7;
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
int bit(int k, int x) { return (x >> k) & 1; }
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
int n, a[maxn], s[maxn], ans[maxn];
set<int> S;
void Main_Process() {
  cin >> n;
  for (int i = 0; i <= n + 4; i++) ans[i] = 0;
  S.clear();
  for (int i = 1; i <= n; i++) cin >> a[i], S.insert(i);
  int m = 0;
  for (int i = 1; i <= n; i++) {
    char x;
    cin >> x;
    s[i] = x - '0';
    m += (s[i] == 0);
  }
  for (int i = 1; i <= n; i++) {
    if (s[i] == 0 && a[i] <= m) ans[i] = a[i], S.erase(a[i]);
    if (s[i] == 1 && a[i] > m) ans[i] = a[i], S.erase(a[i]);
  }
  for (int i = 1; i <= n; i++) {
    if (ans[i]) continue;
    if (s[i] == 0) {
      int x = *S.begin();
      ans[i] = x;
      S.erase(x);
    } else {
      int x = *S.rbegin();
      ans[i] = x;
      S.erase(x);
    }
  }
  for (int i = 1; i <= n; i++) cout << ans[i] << " ";
  cout << "\n";
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
