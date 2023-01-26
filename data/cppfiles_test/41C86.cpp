#include <bits/stdc++.h>
using namespace std;
void _print(bool t) { cerr << t; }
void _print(long long t) { cerr << t; }
void _print(string t) { cerr << t; }
void _print(char t) { cerr << t; }
void _print(double t) { cerr << t; }
template <class T>
void _print(vector<T> v) {
  cerr << "[  ";
  for (T i : v) {
    _print(i);
    cerr << "  ";
  }
  cerr << "]\n";
}
template <class T, class V>
void _print(pair<T, V> p) {
  cerr << "{";
  _print(p.first);
  cerr << ", ";
  _print(p.second);
  cerr << "}";
}
template <class T>
void _print(set<T> v) {
  cerr << "[  ";
  for (T i : v) {
    _print(i);
    cerr << "  ";
  }
  cerr << "]\n";
}
template <class T>
void _print(multiset<T> v) {
  cerr << "[  ";
  for (T i : v) {
    _print(i);
    cerr << "  ";
  }
  cerr << "]\n";
}
template <class T, class V>
void _print(map<T, V> v) {
  cerr << "[  ";
  for (auto i : v) {
    _print(i);
    cerr << "  ";
  }
  cerr << "]\n";
}
template <class T>
void _print(T v[], long long n) {
  cerr << "[  ";
  for (long long i = 0; i < n; i++) {
    _print(v[i]);
    cerr << "  ";
  }
  cerr << "]\n";
}
void run() {
  long long n, m;
  cin >> n >> m;
  string s;
  cin >> s;
  string p1, p2, p3, p4, p5, p6;
  long long cur = 0;
  for (long long i = 0; i < n; i++) {
    p1 += (char)(cur + 'a');
    cur = (cur + 1) % 3;
  }
  cur = 1;
  for (long long i = 0; i < n; i++) {
    p2 += (char)(cur + 'a');
    cur = (cur + 1) % 3;
  }
  cur = 2;
  for (long long i = 0; i < n; i++) {
    p3 += (char)(cur + 'a');
    cur = (cur + 1) % 3;
  }
  string cmp = "cba";
  cur = 0;
  for (long long i = 0; i < n; i++) {
    p4 += cmp[cur];
    cur = (cur + 1) % 3;
  }
  cmp = "bac";
  cur = 0;
  for (long long i = 0; i < n; i++) {
    p5 += cmp[cur];
    cur = (cur + 1) % 3;
  }
  cmp = "acb";
  cur = 0;
  for (long long i = 0; i < n; i++) {
    p6 += cmp[cur];
    cur = (cur + 1) % 3;
  }
  long long pref1[n], pref2[n], pref3[n], pref4[n], pref5[n], pref6[n];
  pref1[0] = (p1[0] == s[0] ? 0 : 1);
  for (long long i = 1; i < n; i++) {
    pref1[i] = pref1[i - 1];
    if (s[i] != p1[i]) pref1[i]++;
  }
  pref2[0] = (p2[0] == s[0] ? 0 : 1);
  for (long long i = 1; i < n; i++) {
    pref2[i] = pref2[i - 1];
    if (s[i] != p2[i]) pref2[i]++;
  }
  pref3[0] = (p3[0] == s[0] ? 0 : 1);
  for (long long i = 1; i < n; i++) {
    pref3[i] = pref3[i - 1];
    if (s[i] != p3[i]) pref3[i]++;
  }
  pref4[0] = (p4[0] == s[0] ? 0 : 1);
  for (long long i = 1; i < n; i++) {
    pref4[i] = pref4[i - 1];
    if (s[i] != p4[i]) pref4[i]++;
  }
  pref5[0] = (p5[0] == s[0] ? 0 : 1);
  for (long long i = 1; i < n; i++) {
    pref5[i] = pref5[i - 1];
    if (s[i] != p5[i]) pref5[i]++;
  }
  pref6[0] = (p6[0] == s[0] ? 0 : 1);
  for (long long i = 1; i < n; i++) {
    pref6[i] = pref6[i - 1];
    if (s[i] != p6[i]) pref6[i]++;
  }
  while (m--) {
    long long l, r;
    cin >> l >> r;
    l--, r--;
    long long ans1 = pref1[r] - (l == 0 ? 0 : pref1[l - 1]);
    long long ans2 = pref2[r] - (l == 0 ? 0 : pref2[l - 1]);
    long long ans3 = pref3[r] - (l == 0 ? 0 : pref3[l - 1]);
    long long ans4 = pref4[r] - (l == 0 ? 0 : pref4[l - 1]);
    long long ans5 = pref5[r] - (l == 0 ? 0 : pref5[l - 1]);
    long long ans6 = pref6[r] - (l == 0 ? 0 : pref6[l - 1]);
    vector<long long> v = {ans1, ans2, ans3, ans4, ans5, ans6};
    cout << *min_element(v.begin(), v.end()) << '\n';
  }
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0), cout.tie();
  long long t;
  t = 1;
  while (t--) {
    run();
  }
}
