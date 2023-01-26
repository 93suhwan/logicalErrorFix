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
int l[N], r[N], lm[N], p[N][20], nxt[N];
vector<char> s(N);
int n, k;
void lmq(int cur) {
  lm[cur] = cur;
  if (l[cur] > 0) {
    p[l[cur]][0] = cur;
    lmq(l[cur]);
    lm[cur] = lm[l[cur]];
  }
  if (r[cur] > 0) {
    p[r[cur]][0] = cur;
    lmq(r[cur]);
  }
}
void setnext(int cur, int rlp) {
  if (r[cur] > 0) {
    nxt[cur] = lm[r[cur]];
    setnext(r[cur], rlp);
  } else {
    nxt[cur] = rlp;
  }
  if (l[cur] > 0) setnext(l[cur], cur);
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> s[i];
  }
  for (int i = 1; i <= n; i++) {
    cin >> l[i] >> r[i];
  }
  lmq(1);
  setnext(1, 0);
  for (int i = 1; i < 20; i++) {
    for (int j = 1; j <= n; j++) {
      p[j][i] = p[p[j][i - 1]][i - 1];
    }
  }
  vector<bool> dup(n + 1, 0), ndup(n + 1, 0);
  vector<int> checkdup(n + 1, 0);
  int cur = lm[1];
  vector<int> seq;
  while (cur != 0) {
    seq.push_back(cur);
    cur = nxt[cur];
  }
  for (int ind = n - 1; ind > 0; ind--) {
    if (s[seq[ind]] > s[seq[ind - 1]]) {
      checkdup[seq[ind - 1]] = 1;
    }
    if (s[seq[ind]] == s[seq[ind - 1]]) {
      checkdup[seq[ind - 1]] = checkdup[seq[ind]];
    }
    if (s[seq[ind]] < s[seq[ind - 1]]) {
      checkdup[seq[ind - 1]] = -1;
    }
  }
  for (int ind = 0; ind < n && k > 0; ind++) {
    int cur = seq[ind];
    if (dup[cur] || ndup[cur]) {
      cur = nxt[cur];
      continue;
    }
    if (checkdup[cur] == 1) {
      int len = 1, temp = cur;
      for (int i = 19; i >= 0; i--) {
        if (p[temp][i] > 0 && !dup[p[temp][i]]) {
          len += (1 << i);
          temp = p[temp][i];
        }
      }
      if (len <= k) {
        k -= len;
        temp = cur;
        while (len--) {
          dup[temp] = 1;
          temp = p[temp][0];
        }
      }
      cur = nxt[cur];
    } else {
      queue<int> q;
      q.push(cur);
      while (!q.empty()) {
        int temp = q.front();
        q.pop();
        if (ndup[temp] == 1) continue;
        ndup[temp] = 1;
        if (l[temp] > 0) {
          q.push(l[temp]);
        }
        if (r[temp] > 0) {
          q.push(r[temp]);
        }
      }
      cur = nxt[cur];
    }
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
