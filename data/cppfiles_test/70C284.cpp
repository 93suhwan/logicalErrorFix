#include <bits/stdc++.h>
using namespace std;
template <typename T>
istream &operator>>(istream &in, vector<T> &v) {
  for (auto &i : v) in >> i;
  return in;
}
template <typename A, typename B>
istream &operator>>(istream &in, pair<A, B> &a) {
  in >> a.first >> a.second;
  return in;
}
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
long long rand(long long l, long long r) {
  uniform_int_distribution<long long> uid(l, r);
  return uid(rng);
}
const string no = "No";
const string yes = "Yes";
void solve() {
  string s;
  cin >> s;
  long long n = (long long)(s).size();
  string order = "";
  vector<long long> freq(26);
  set<char> shouldbe;
  for (long long i = 0; i < n; i++) {
    freq[s[i] - 'a']++;
  }
  vector<long long> lol(26, 0);
  for (long long i = n - 1; i >= 0;) {
    vector<long long> now(26);
    shouldbe.insert(s[i]);
    long long j = i;
    while (j >= 0 && shouldbe.find(s[j]) != shouldbe.end()) {
      now[s[j] - 'a']++;
      j--;
    }
    for (long long j = 0; j < 26; j++) {
      if (now[j] && !lol[j]) {
        order += (char)(j + 'a');
        lol[j] = 1;
      }
    }
    i = j;
  }
  reverse(order.begin(), order.end());
  ;
  ;
  for (long long i = 0; i < (long long)(order).size(); i++) {
    if (freq[order[i] - 'a'] % (i + 1)) {
      cout << -1 << '\n';
      return;
    }
    freq[order[i] - 'a'] = freq[order[i] - 'a'] / (i + 1);
  };
  string willbe = "";
  vector<long long> got(26, 0);
  for (long long i = 0; i < n; i++) {
    got[s[i] - 'a']++;
    willbe += s[i];
    bool check = false;
    for (long long j = 0; j < 26; j++) {
      if (got[j] != freq[j]) {
        check = true;
      }
      if (got[j] > freq[j]) {
        cout << -1 << '\n';
        return;
      }
    }
    if (!check) break;
  }
  for (long long i = 0; i < 26; i++) {
    if (got[i] != freq[i]) {
      cout << -1 << '\n';
      return;
    }
  }
  string now = "";
  string willbe2 = willbe;
  long long pointer = 0;
  while ((long long)(now).size() < (long long)(s).size()) {
    now += willbe2;
    string hey = "";
    for (long long i = 0; i < (long long)(willbe2).size(); i++) {
      if (willbe2[i] == order[pointer]) continue;
      hey += willbe2[i];
    }
    pointer++;
    willbe2 = hey;
  }
  if (now != s) {
    cout << -1 << '\n';
    return;
  }
  cout << willbe << ' ' << order << '\n';
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t = 1;
  cin >> t;
  for (long long tc = 1; tc <= t; tc++) {
    ;
    solve();
  }
  return 0;
}
