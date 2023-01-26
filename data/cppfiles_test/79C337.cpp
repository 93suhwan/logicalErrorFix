#include <bits/stdc++.h>
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("O3")
#pragma GCC target("avx2")
using namespace std;
template <class T>
void debug(vector<T>& arr) {
  cerr << "[ ";
  for (auto& i : arr) {
    cerr << i << " ";
  }
  cerr << "]" << endl;
}
template <class T>
void debug(T& a) {
  cerr << a << endl;
}
template <class T1, class T2>
ostream& operator<<(ostream& out, pair<T1, T2>& P) {
  cout << "{" << P.first << ", " << P.second << "}";
  return out;
}
template <class T1, class T2>
void debug(pair<T1, T2>& P) {
  cerr << "{" << P.first << ", " << P.second << "}" << endl;
}
string prime = "2357";
bool isPrime(long long X) {
  for (long long i = 2; i * i <= X; i++) {
    if (X % i == 0) return false;
  }
  return true;
}
void solve() {
  long long n;
  cin >> n;
  string s;
  cin >> s;
  map<char, long long> cnt;
  for (auto& i : s) {
    if (!binary_search(prime.begin(), prime.end(), i)) {
      cout << 1 << endl;
      cout << i << endl;
      return;
    } else {
      cnt[i]++;
    }
  }
  for (auto& i : cnt) {
    if (i.second >= 2) {
      cout << 2 << endl;
      cout << i.first << i.first << endl;
      return;
    }
  }
  string::iterator it = unique(s.begin(), s.end());
  s.resize(distance(s.begin(), it));
  for (long long i = 0; i < n; i++) {
    for (long long j = 0; j < n; j++) {
      if (j != i) {
        string T;
        T += s[i];
        T += s[j];
        long long X = stoi(T);
        if (!isPrime(X)) {
          cout << T.size() << endl;
          cout << T << endl;
          return;
        }
      }
    }
  }
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
