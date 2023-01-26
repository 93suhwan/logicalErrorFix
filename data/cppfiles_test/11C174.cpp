#include <bits/stdc++.h>
using namespace std;
void _print(long long t) { cerr << t; }
void _print(int t) { cerr << t; }
void _print(string t) { cerr << t; }
void _print(char t) { cerr << t; }
void _print(long double t) { cerr << t; }
void _print(double t) { cerr << t; }
void _print(unsigned long long t) { cerr << t; }
template <class T, class V>
void _print(pair<T, V> p);
template <class T>
void _print(vector<T> v);
template <class T>
void _print(set<T> v);
template <class T, class V>
void _print(map<T, V> v);
template <class T, class V>
void _print(unordered_map<T, V> v);
template <class T>
void _print(multiset<T> v);
template <class T, class V>
void _print(pair<T, V> p) {
  cerr << "{";
  _print(p.first);
  cerr << ",";
  _print(p.second);
  cerr << "}";
}
template <class T>
void _print(vector<T> v) {
  cerr << "[ ";
  for (T i : v) {
    _print(i);
    cerr << " ";
  }
  cerr << "]";
}
template <class T>
void _print(set<T> v) {
  cerr << "[ ";
  for (T i : v) {
    _print(i);
    cerr << " ";
  }
  cerr << "]";
}
template <class T, class V>
void _print(unordered_map<T, V> v) {
  cerr << "[ ";
  for (auto i : v) {
    _print(i);
    cerr << " ";
  }
  cerr << "]";
}
template <class T>
void _print(multiset<T> v) {
  cerr << "[ ";
  for (T i : v) {
    _print(i);
    cerr << " ";
  }
  cerr << "]";
}
template <class T, class V>
void _print(map<T, V> v) {
  cerr << "[ ";
  for (auto i : v) {
    _print(i);
    cerr << " ";
  }
  cerr << "]";
}
void ip() {}
void time() {}
vector<unsigned long long> fact;
void factor_Calculate(unsigned long long n) {
  for (unsigned long long i = 2; i <= sqrt(n); i++) {
    if (n % i == 0) {
      if (n / i == i)
        fact.push_back(i);
      else {
        fact.push_back(i);
        fact.push_back(n / i);
      }
    }
  }
}
int calc(string& a, int c) {
  int ans = 0;
  for (auto i : a) {
    if (i == (c + 'a')) {
      ++ans;
    } else {
      --ans;
    }
  }
  return ans;
}
int Calculate(int ch, vector<string>& A) {
  int n = A.size();
  vector<int> B;
  for (int i = 0; i < n; i++) {
    string s = A[i];
    B.push_back(calc(A[i], ch));
  }
  sort(B.begin(), B.end(), greater<int>());
  int max_length = 0;
  int cnt = 0;
  int count = 0;
  for (int i = 0; i < B.size(); i++) {
    if (count + B[i] > 0) {
      count = count + B[i];
      cnt++;
    } else {
      break;
    }
  }
  return cnt;
}
void solve() {
  long long n;
  cin >> n;
  vector<string> A(n);
  for (int i = 0; i < n; i++) {
    cin >> A[i];
  }
  long long ans = 0;
  for (int i = 0; i < 5; i++) {
    ans = max(ans, (long long)Calculate(i, A));
  }
  cout << ans << "\n";
  ;
}
int main() {
  ip();
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  for (int i = 1; i <= t; i++) {
    solve();
  }
  time();
}
