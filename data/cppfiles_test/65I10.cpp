#include <bits/stdc++.h>
using namespace std;
template <typename... Args>
void logger(string vars, Args&&... values) {}
template <typename T>
inline void maxa(T& a, T b) {
  a = max(a, b);
}
template <typename T>
inline void mina(T& a, T b) {
  a = min(a, b);
}
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int mxN = 2e5 + 5;
const int mod = 1e9 + 7;
void f(vector<int> a, queue<pair<int, char>> ch) {
  sort(a.begin(), a.end());
  deque<int> dq, dq2;
  int n = (int)(a.size());
  long long add = 0;
  long long sub = 0;
  char lst = 'L';
  for (int i = 0; i < n; i++) {
    if (add >= sub + a[i]) {
      int k = dq.front();
      dq.pop_front();
      while (add >= sub + a[i]) {
        add -= dq.front();
        sub += dq.front();
        dq2.push_front(dq.front());
        dq.pop_front();
      }
      dq.push_front(k);
    }
    dq.push_front(a[i]);
    add += a[i];
    if (ch.front().first == i) {
      lst = ch.front().second;
      ch.pop();
      add -= a[i];
      sub += a[i];
      assert(sub > add);
      add = sub - add;
      dq2.push_front(dq.front());
      dq.pop_front();
      while ((int)(dq.size())) {
        cout << dq.back() << " " << (lst == 'L' ? 'R' : 'L') << "\n";
        dq.pop_back();
      }
      while ((int)(dq2.size())) {
        cout << dq2.back() << " " << lst << "\n";
        dq2.pop_back();
      }
    }
  }
  while ((int)(dq.size())) {
    cout << dq.back() << " " << lst << "\n";
    dq.pop_back();
  }
  while ((int)(dq2.size())) {
    cout << dq2.back() << " " << lst << "\n";
    dq2.pop_back();
  }
}
int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int& i : a) cin >> i;
  queue<pair<int, char>> q;
  string s;
  cin >> s;
  for (int i = 1; i < n; i++) {
    if (s[i] != s[i - 1]) {
      q.push({i, s[i]});
    }
  }
  f(a, q);
}
