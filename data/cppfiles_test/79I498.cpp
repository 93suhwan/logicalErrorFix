#include <bits/stdc++.h>
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("O3")
#pragma GCC target("avx2")
using namespace std;
template <class T>
void debug(vector<T> &arr) {
  cerr << "[ ";
  for (auto &i : arr) {
    cerr << i << " ";
  }
  cerr << "]" << endl;
}
template <class T>
void debug(T &a) {
  cerr << a << endl;
}
template <class T1, class T2>
ostream &operator<<(ostream &out, pair<T1, T2> &P) {
  cout << "{" << P.first << ", " << P.second << "}";
  return out;
}
template <class T1, class T2>
void debug(pair<T1, T2> &P) {
  cerr << "{" << P.first << ", " << P.second << "}" << endl;
}
string P = "2357";
bool isPrime(long long X) {
  for (long long i = 2; i * i <= X; i++) {
    if (X % i == 0) return false;
  }
  return true;
}
void solve() {
  long long N;
  cin >> N;
  string S;
  cin >> S;
  for (auto &i : S) {
    if (!binary_search(P.begin(), P.end(), i)) {
      cout << 1 << endl << i << endl;
      return;
    }
  }
  sort(S.begin(), S.end());
  for (auto &i : P) {
    long long n = count(S.begin(), S.end(), i);
    if (n >= 2) {
      cout << n << endl;
      for (long long j = 0; j < n; j++) {
        cout << i;
      }
      cout << endl;
      return;
    }
  }
  string::iterator it = unique(S.begin(), S.end());
  S.resize(distance(S.begin(), it));
  for (auto &i : S) {
    for (auto &j : S) {
      if (i != j) {
        string T;
        T += i;
        T += j;
        long long X = stoi(T);
        if (!isPrime(X)) {
          cout << T.size() << endl;
          cout << X << endl;
          return;
        }
      }
    }
  }
  cout << -1 << endl;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  clock_t begin = clock();
  long long t = 1;
  cin >> t;
  for (long long i = 0; i < t; i++) {
    cerr << "Testcase #" << i + 1 << endl;
    solve();
    cerr << endl;
  }
  return 0;
}
