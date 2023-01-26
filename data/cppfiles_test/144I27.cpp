#include <bits/stdc++.h>
using namespace std;
int t, n, m, K;
template <typename T>
inline void r(T &I) {
  T w = 1;
  I = 0;
  char ch = getchar();
  while (!isdigit(ch) && ch != EOF) {
    if (ch == '-') w = -w;
    ch = getchar();
  }
  while (isdigit(ch) && ch != EOF) {
    I = (I << 3) + (I << 1) + (ch & 15);
    ch = getchar();
  }
  I = I * w;
}
void solve() {
  int ta = n / m, tb = ceil(1.0 * n / m);
  if (ta == tb) {
    for (int i = 1; i <= K; i++) {
      int cnt = 0;
      for (int j = 1; j <= m; j++) {
        cout << ta << " ";
        for (int k = 1; k <= ta; k++) {
          cout << (++cnt) << " ";
        }
        cout << "\n";
      }
    }
    return;
  }
  int da = m * tb - n, db = n - m * ta;
  deque<int> qa, qb;
  queue<int> q;
  for (int i = 1; i <= ta * da; i++) qa.push_back(i);
  for (int i = ta * da + 1; i <= n; i++) qb.push_back(i);
  for (int k = 1; k <= K; k++) {
    for (int i = 1; i <= da; i++) {
      cout << ta << " ";
      for (int j = 1; j <= ta; j++) {
        cout << qa.front() << " ";
        q.push(qa.front());
        qa.pop_front();
      }
      cout << "\n";
    }
    while (!q.empty() && qb.size() < ((tb * db) << 1)) {
      qb.push_back(q.front());
      q.pop();
    }
    while (!q.empty()) {
      qa.push_front(q.front());
      q.pop();
    }
    for (int i = 1; i <= db; i++) {
      cout << tb << " ";
      for (int j = 1; j <= tb; j++) {
        cout << qb.front() << " ";
        q.push(qb.front());
        qb.pop_front();
      }
      cout << "\n";
    }
    while (!q.empty() && qa.size() < (ta * da)) {
      qa.push_back(q.front());
      q.pop();
    }
    while (!q.empty()) {
      qb.push_front(q.front());
      q.pop();
    }
  }
}
int main() {
  r(t);
  while (t--) {
    r(n);
    r(m);
    r(K);
    solve();
    cout << "\n";
  }
  return 0;
}
