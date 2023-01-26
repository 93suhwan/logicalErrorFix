#include <bits/stdc++.h>
using namespace std;
template <class T>
void read(vector<T> &a) {
  for (auto &i : a) cin >> i;
}
template <class T>
void read1(vector<T> &a, int n) {
  for (int i = 1; i <= n; i++) cin >> a[i];
}
template <class T>
void _print(T x) {
  cerr << x << endl;
}
template <class S, class T>
void _print(pair<S, T> x) {
  cerr << "{" << x.first << "," << x.second << "}" << endl;
}
template <class T>
void _print(vector<T> x) {
  cerr << "[";
  for (auto i : x) cerr << i << ", ";
  cerr << "]\n";
}
template <class S, class T>
void _print(vector<pair<S, T>> x) {
  for (auto i : x) cerr << "[" << i.first << "," << i.second << "]" << endl;
}
template <class T>
void _print(set<T> x) {
  cerr << "{ ";
  for (auto i : x) cerr << i << ", ";
  cerr << "}\n";
}
template <class S, class T>
void _print(map<S, T> x) {
  for (auto i : x) {
    cerr << i.first << ": " << i.second << endl;
  }
}
long long exp(int a, int b, int p) {
  long long res = 1;
  a = a % p;
  while (b) {
    if (b & 1) res = (res * a) % p;
    a = ((long long)a * a) % p;
    b = b >> 1;
  }
  return res;
}
long long mmiPrime(int a, int p) { return exp(a, p - 2, p); }
pair<int, int> extendedGCD(int a, int b) {
  if (b == 0) {
    pair<int, int> ans;
    ans.first = 1;
    ans.second = 0;
    return ans;
  }
  pair<int, int> temp = extendedGCD(b, a % b);
  pair<int, int> ans;
  ans.first = temp.second;
  ans.second = temp.first - (a / b) * temp.second;
  return ans;
}
int mmi(int a, int m) {
  pair<int, int> tmp = extendedGCD(a, m);
  return tmp.first;
}
void solve() {
  int n;
  cin >> n;
  vector<int> a(n + 1, 0);
  vector<int> bad;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    if (x >= 1 && x <= n && a[x] != 1)
      a[x] = 1;
    else
      bad.push_back(x);
  }
  int ans = 0;
  sort(bad.begin(), bad.end());
  int j = 0;
  for (int i = 1; i <= n; i++) {
    if (a[i] != 1) {
      if (j >= bad.size()) {
        cout << -1 << endl;
        return;
      }
      int x = bad[j];
      int rem = x / 2;
      if (x % 2 == 0) rem--;
      if (i > rem) {
        cout << -1 << endl;
        return;
      } else {
        a[i] = 1;
        j++;
        ans++;
      }
    }
  }
  cout << ans << '\n';
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  clock_t time = clock();
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  time = clock() - time;
  return 0;
}
