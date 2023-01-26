#include <bits/stdc++.h>
using namespace std;
const long long CPU_TIME = 3;
const long long MAX_FILE_SIZE = 1024 * 1024;
template <typename Arg1>
void ZZ(const char* name, Arg1&& arg1) {
  std::cerr << name << " = " << arg1 << '\n';
}
template <typename Arg1, typename... Args>
void ZZ(const char* names, Arg1&& arg1, Args&&... args) {
  const char* comma = strchr(names + 1, ',');
  std::cerr.write(names, comma - names) << " = " << arg1;
  ZZ(comma, args...);
}
const long long MOD = 1000000007LL;
const long long MAX = 100010LL;
template <class T>
T abs(T x) {
  return x > 0 ? x : -x;
}
template <typename T>
T gcd(T a, T b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
template <typename T>
T power(T x, T y, long long m = MOD) {
  T ans = 1;
  x %= m;
  while (y > 0) {
    if (y & 1LL) ans = (ans * x) % m;
    y >>= 1LL;
    x = (x * x) % m;
  }
  return ans % m;
}
template <typename T>
T ceiling(T numerator, T denominator) {
  return (numerator + denominator - 1) / denominator;
}
template <typename T>
T inverse(T num, long long m = MOD) {
  return ((num == 1)
              ? 1
              : (MOD - ((MOD / num) * inverse(MOD % num)) % MOD + MOD) % MOD);
}
template <typename T>
istream& operator>>(istream& cin, vector<T>& a) {
  for (auto& i : a) cin >> i;
  return cin;
}
template <typename T>
ostream& operator<<(ostream& cout, vector<T>& a) {
  for (auto& i : a) cout << i << " ";
  return cout;
}
template <typename T, typename A>
ostream& operator<<(ostream& cout, pair<T, A>& a) {
  cout << "(" << a.first << "," << a.second << ")";
  return cout;
}
template <typename T>
ostream& operator<<(ostream& cout, set<T>& a) {
  for (auto& i : a) cout << i << " ";
  return cout;
}
template <typename T, typename A>
ostream& operator<<(ostream& cout, map<T, A>& a) {
  for (auto& i : a) cout << "(" << i.first << "," << i.second << ") ";
  return cout;
}
void solve() {
  int n;
  cin >> n;
  vector<vector<int> > a;
  for (int i = 0; i < n; i++) {
    int m;
    cin >> m;
    vector<int> arr(m);
    for (int j = 0; j < m; j++) {
      int k;
      cin >> k;
      arr[j] = k - j;
    }
    a.push_back(arr);
  }
  sort((a).begin(), (a).end(), [](vector<int>& x, vector<int>& y) {
    return (max(*max_element((x).begin(), (x).end()),
                *max_element((y).begin(), (y).end()) - (int)x.size()) <
            max(*max_element((y).begin(), (y).end()),
                *max_element((x).begin(), (x).end()) - (int)y.size()));
  });
  int ans = 0;
  int cur_level = 0;
  for (int i = 0; i < n; i++) {
    ans = max(ans, *max_element((a[i]).begin(), (a[i]).end()) - cur_level);
    cur_level += a[i].size();
  }
  cout << ans + 1 << '\n';
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
