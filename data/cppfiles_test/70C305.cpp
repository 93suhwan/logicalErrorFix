#include <bits/stdc++.h>
using namespace std;
void __print(long long x) { cerr << x; }
void __print(unsigned long long x) { cerr << x; }
void __print(long double x) { cerr << x; }
void __print(char x) { cerr << '\'' << x << '\''; }
void __print(const char *x) { cerr << '\"' << x << '\"'; }
void __print(const string &x) { cerr << '\"' << x << '\"'; }
void __print(bool x) { cerr << (x ? "true" : "false"); }
template <typename T, typename V>
void __print(const pair<T, V> &x) {
  cerr << '{';
  __print(x.first);
  cerr << ',';
  __print(x.second);
  cerr << '}';
}
template <typename T>
void __print(const T &x) {
  int f = 0;
  cerr << '{';
  for (auto &i : x) cerr << (f++ ? "," : ""), __print(i);
  cerr << "}";
}
void _print() { cerr << "]\n"; }
template <typename T, typename... V>
void _print(T t, V... v) {
  __print(t);
  if (sizeof...(v)) cerr << ", ";
  _print(v...);
}
const long double pi = acos(-1.0);
long long int inf = 0x3f3f3f3f3f3f3f3f;
const long long int mod = 1e9 + 7;
const long long int mx = 5 * 1000000;
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int t;
  cin >> t;
  while (t--) {
    string a;
    cin >> a;
    map<char, long long int> cnt;
    vector<char> aa;
    for (auto i : a) {
      cnt[i]++;
      aa.push_back(i);
    }
    vector<char> ans2;
    long long int poss = 1;
    long long int i;
    long long int n = a.size();
    map<char, long long int> vis;
    for (long long int i = n - 1; i >= 0; i--) {
      if (!vis[a[i]]) {
        ans2.push_back(a[i]);
        vis[a[i]] = 1;
      }
    }
    reverse(ans2.begin(), ans2.end());
    vector<long long int> count;
    long long int block = 1;
    for (auto i : ans2) {
      if (cnt[i] % block == 0)
        count.push_back(cnt[i] / block);
      else {
        poss = 0;
        break;
      }
      block++;
    }
    reverse(count.begin(), count.end());
    long long int extra = 0;
    for (long long int i = 1; i < count.size(); i++) {
      count[i] += count[i - 1];
    }
    long long int remove = 0;
    long long int till = 0;
    for (auto i : count) {
      till += i;
      if (till >= n) {
        break;
      }
      remove = till;
    }
    if (poss) {
      vector<char> ans1, ans3;
      for (long long int i = 0; i < n - remove; i++) {
        ans1.push_back(a[i]);
      }
      block = ans2.size();
      vis.clear();
      long long int idx = 0;
      while (block--) {
        for (auto i : ans1) {
          if (!vis[i]) {
            ans3.push_back(i);
          }
        }
        vis[ans2[idx++]] = 1;
      }
      if (aa == ans3) {
        for (auto i : ans1) {
          cout << i;
        }
        cout << " ";
        for (auto i : ans2) {
          cout << i;
        }
        cout << endl;
      } else {
        cout << "-1\n";
      }
    } else {
      cout << "-1\n";
    }
  }
}
