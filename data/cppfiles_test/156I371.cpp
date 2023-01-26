#include <bits/stdc++.h>
using namespace std;
void _print(long long int x) { cerr << x << " "; }
void _print(float x) { cerr << x << " "; }
void _print(double x) { cerr << x << " "; }
void _print(char x) { cerr << x << " "; }
void _print(string x) { cerr << x << " "; }
void _print(bool x) { cerr << x << " "; }
template <class T, class V>
void _print(pair<T, V> x) {
  cerr << "{";
  _print(x.first);
  cerr << ",";
  _print(x.second);
  cerr << "}";
}
template <class T>
void _print(vector<T> x) {
  cerr << "[ ";
  for (T i : x) {
    _print(i);
    cerr << " ";
  }
  cerr << "]";
}
template <class T>
void _print(set<T> x) {
  cerr << "[ ";
  for (T i : x) {
    _print(i);
    cerr << " ";
  }
  cerr << "]";
}
template <class T>
void _print(multiset<T> x) {
  cerr << "[ ";
  for (T i : x) {
    _print(i);
    cerr << " ";
  }
  cerr << "]";
}
template <class T, class V>
void _print(map<T, V> x) {
  cerr << "[ ";
  for (auto i : x) {
    _print(i);
    cerr << " ";
  }
  cerr << " ]";
}
void solve() {
  long long int n, k;
  cin >> n >> k;
  vector<long long int> a(n);
  long long int sum = 0;
  for (long long int i = 0; i <= n - 1; i++) {
    cin >> a[i];
    sum += a[i];
  }
  if (sum <= k) {
    cout << 0 << endl;
    return;
  }
  sort(a.begin(), a.end(), greater<long long int>());
  long long int ans = 1e17;
  long long int i = -1, j = sum - k + 1;
  while (i <= j) {
    long long int mid = (i + j) / 2;
    ;
    long long int s = sum - mid;
    long long int ops = mid;
    for (long long int t = 0; t <= n - 2; t++) {
      if (s <= k) {
        break;
      }
      s -= a[t];
      s += a[n - 1] - mid;
      ops++;
    };
    ;
    ;
    ;
    if (s <= k && ops < ans) {
      j = mid;
      ans = min(ops, ans);
    } else {
      i = mid + 1;
    }
  }
  cout << ans << endl;
}
signed main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  clock_t start, end;
  start = clock();
  long long int t;
  cin >> t;
  while (t--) {
    solve();
  }
  end = clock();
  double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
  cerr << "Time taken by program is : " << fixed << time_taken
       << setprecision(5);
  cerr << " sec " << endl;
  return 0;
}
