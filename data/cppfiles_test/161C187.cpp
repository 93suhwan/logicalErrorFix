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
int n;
bool mk[1005][1005];
pair<int, int> a[maxn];
bool by_dist(pair<int, int> u, pair<int, int> v) {
  return (u.second - u.first > v.second - v.first);
}
void Main_Process() {
  for (int i = 1; i <= n; i++) mk[a[i].first][a[i].second] = 0;
  cin >> n;
  for (int i = 1; i <= n; i++)
    cin >> a[i].first >> a[i].second, mk[a[i].first][a[i].second] = 1;
  sort(a + 1, a + n + 1, by_dist);
  for (int i = 1; i <= n; i++) {
    cout << a[i].first << " " << a[i].second << " ";
    if (a[i].first == a[i].second) {
      cout << a[i].first << "\n";
      continue;
    }
    if (mk[a[i].first + 1][a[i].second])
      cout << a[i].first << "\n";
    else if (mk[a[i].first][a[i].second - 1])
      cout << a[i].second << "\n";
    else
      for (int j = a[i].first + 1; j < a[i].second; j++) {
        if (mk[a[i].first][j - 1] && mk[j + 1][a[i].second]) {
          cout << j << "\n";
          break;
        }
      }
  }
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
