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
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int tc = 1;
  cin >> tc;
  while (tc--) {
    long long n, k, x;
    cin >> n >> k >> x;
    string second;
    cin >> second;
    vector<int> astericks;
    int cnt = 0;
    for (int i = n - 1; i >= 0; i--) {
      if (second[i] == '*') {
        cnt += k;
        if (i == 0) astericks.push_back(cnt);
      } else if (second[i] == 'a') {
        if (cnt) astericks.push_back(cnt);
        cnt = 0;
      }
    }
    if (x == 1) {
      for (int i = 0; i < n; i++)
        if (second[i] == 'a') cout << second[i];
      cout << "\n";
      continue;
    }
    vector<long long> dp(astericks.size(), LLONG_MAX);
    dp[0] = astericks[0] + 1;
    for (int i = 1; i < dp.size(); i++) {
      if (x / (astericks[i] + 1) < dp[i - 1]) break;
      dp[i] = (astericks[i] + 1) * dp[i - 1];
    }
    reverse(astericks.begin(), astericks.end());
    reverse(dp.begin(), dp.end());
    vector<int> ch(astericks.size());
    bool st = 0;
    for (int i = 0; i < ch.size(); i++) {
      if (x == dp[i]) {
        x = 0;
        for (int j = i; j < ch.size(); j++) ch[j] = astericks[j];
        break;
      } else if (x - dp[i] >= 1) {
        while (x - dp[i] >= 1) x -= dp[i], ch[i - 1]++;
        i--;
      } else if (i == ch.size() - 1)
        ch[ch.size() - 1] = x - 1;
    }
    int idx = 0;
    for (int i = 0; i < n; i++) {
      if (second[i] == '*') {
        while (i < n && second[i] == '*') i++;
        i--;
        if (idx >= ch.size()) {
          cout << n << k << x << second << "\n";
          break;
        }
        for (int j = 0; j < ch[idx]; j++) cout << (char)('b');
        idx++;
      } else
        cout << (char)('a');
    }
    cout << "\n";
  }
}
