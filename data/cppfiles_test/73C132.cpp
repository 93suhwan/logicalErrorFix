#include <bits/stdc++.h>
using namespace std;
template <typename S, typename T>
ostream& operator<<(ostream& out, const pair<S, T> p) {
  out << "(" << p.first << "," << p.second << ")";
  return out;
}
template <typename T>
ostream& operator<<(ostream& out, const vector<T>& v) {
  for (auto a : v) out << a << " ";
  return out;
}
template <typename T>
ostream& operator<<(ostream& out, const set<T>& S) {
  for (auto a : S) cout << a << " ";
  return out;
}
template <typename T>
ostream& operator<<(ostream& out, const multiset<T>& S) {
  for (auto a : S) cout << a << " ";
  return out;
}
template <typename S, typename T>
ostream& operator<<(ostream& out, const map<S, T>& M) {
  for (auto m : M) cout << "(" << m.first << "->" << m.second << ") ";
  return out;
}
template <typename S, typename T>
pair<S, T> operator+(pair<S, T> a, pair<S, T> b) {
  return make_pair(a.first + b.first, a.second + b.second);
}
template <typename S, typename T>
pair<S, T> operator-(pair<S, T> a, pair<S, T> b) {
  return make_pair(a.first - b.first, a.second - b.second);
}
void solve(int cas) {
  int n;
  cin >> n;
  vector<int> A(n);
  for (int i = 0; i < n; i++) {
    cin >> A[i];
  }
  int ans = 0;
  while (1) {
    bool ok = true;
    for (int i = 1; i < n; i++) {
      if (A[i] < A[i - 1]) {
        ok = false;
      }
    }
    if (ok) {
      break;
    }
    if (ans % 2 == 0) {
      for (int i = 0; i < n; i += 2) {
        if (i + 1 < n) {
          if (A[i] > A[i + 1]) {
            swap(A[i], A[i + 1]);
          }
        }
      }
    } else {
      for (int i = 1; i < n; i += 2) {
        if (i + 1 < n) {
          if (A[i] > A[i + 1]) {
            swap(A[i], A[i + 1]);
          }
        }
      }
    }
    ans++;
  }
  cout << ans << endl;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    solve(i);
  }
  return 0;
}
