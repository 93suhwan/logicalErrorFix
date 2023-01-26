#include <bits/stdc++.h>
using namespace std;
void debug_out() { cerr << endl; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr << ' ' << H;
  debug_out(T...);
}
const long long MOD = 1e9 + 7;
const int N = 2e5 + 1;
int l[N], r[N], lm[N], p[N][20], nxt[N], dept[N];
vector<bool> nxtpos(N + 1, 0);
vector<char> s(N);
int n, k;
void lmq(int cur) {
  lm[cur] = cur;
  if (l[cur] > 0) {
    dept[l[cur]] = dept[cur] + 1;
    p[l[cur]][0] = cur;
    lmq(l[cur]);
    lm[cur] = lm[l[cur]];
  }
  if (r[cur] > 0) {
    dept[r[cur]] = dept[cur] + 1;
    p[r[cur]][0] = cur;
    lmq(r[cur]);
  }
}
void setnext(int cur, int rlp) {
  if (r[cur] > 0) {
    nxt[cur] = lm[r[cur]];
    setnext(r[cur], rlp);
  } else {
    nxtpos[cur] = 1;
    nxt[cur] = rlp;
  }
  if (l[cur] > 0) setnext(l[cur], cur);
}
int main() {
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> s[i];
  }
  for (int i = 1; i <= n; i++) {
    cin >> l[i] >> r[i];
  }
  dept[1] = 1;
  lmq(1);
  setnext(1, 0);
  for (int i = 1; i < 20; i++) {
    for (int j = 1; j <= n; j++) {
      p[j][i] = p[p[j][i - 1]][i - 1];
    }
  }
  vector<bool> dup(n + 1, 0), ndup(n + 1, 0);
  int cur = lm[1];
  while (cur != 0) {
    if (dup[cur] || ndup[cur]) {
      cur = nxt[cur];
      continue;
    }
    if (s[cur] < s[nxt[cur]]) {
      int len = 0, temp = cur, i = 19;
      while (p[temp][0] > 0 && !dup[p[temp][0]]) {
        for (; i >= 0; i--) {
          if (p[temp][i] > 0 && !dup[p[temp][i]]) {
            len += (1 << i);
            temp = p[temp][i];
            break;
          }
        }
      }
      len++;
      temp = cur;
      if (len <= k) {
        k -= len;
        while (len--) {
          dup[temp] = 1;
          temp = p[temp][0];
        }
      }
    }
    if (s[cur] > s[nxt[cur]]) {
      queue<int> q;
      q.push(cur);
      while (!q.empty()) {
        int temp = q.front();
        q.pop();
        ndup[temp] = 1;
        if (l[temp] > 0) {
          q.push(l[temp]);
        }
        if (r[temp] > 0) {
          q.push(r[temp]);
        }
      }
    }
    cur = nxt[cur];
  }
  int start = lm[1];
  while (start != 0) {
    if (dup[start]) {
      cout << s[start] << s[start];
    } else {
      cout << s[start];
    }
    start = nxt[start];
  }
  cout << "\n";
  return 0;
}
