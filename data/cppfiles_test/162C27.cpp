#include <bits/stdc++.h>
using namespace std;
string to_string(pair<int, int> p) {
  return '(' + to_string(p.first) + ',' + to_string(p.second) + ')';
}
template <typename A>
string to_string(A v) {
  int cnt = 0;
  string res;
  for (const auto& x : v) {
    if (cnt++) res += " ";
    res += to_string(x);
  }
  return "[" + res + "]";
}
string to_string(const string& s) { return '"' + s + '"'; }
string to_string(const char* s) { return to_string((string)s); }
void debug_out() { cerr << endl; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr << " " << to_string(H);
  debug_out(T...);
}
template <typename T>
void output_vector(const vector<T>& v, int start = 0, int end = -1) {
  if (end < 0) end = int(v.size());
  for (int i = start; i < end; i++) cout << v[i] << (i < end - 1 ? ' ' : '\n');
}
int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  cin.exceptions(cin.failbit);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<long long> Orig(n);
    for (int i = 0; i < (n); i++) cin >> Orig[i];
    long long sm = 0;
    for (auto& x : Orig) sm += x;
    long long a = 1;
    long long b = sm + 1;
    while (a + 1 < b) {
      long long mid = (a + b) / 2;
      bool can = true;
      vector<long long> Changes(n, 0);
      for (int i = n - 1; i >= 0; i--) {
        if (Orig[i] + Changes[i] < mid) {
          can = false;
          break;
        }
        if (i >= 2) {
          long long budget = max(0ll, Orig[i] + Changes[i] - mid);
          budget = min(Orig[i], budget);
          long long d = budget / 3ll;
          if (d > 0) {
            Changes[i - 1] += d;
            Changes[i - 2] += 2ll * d;
          }
        }
      }
      if (can)
        a = mid;
      else
        b = mid;
    }
    cout << a << "\n";
  }
}
