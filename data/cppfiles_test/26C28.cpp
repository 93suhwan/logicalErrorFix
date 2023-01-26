#include <bits/stdc++.h>
using namespace std;
vector<long long> graph[100005];
bool vis[100005];
long long disc[100005];
long long low[100005];
vector<long long> art_pt;
long long t = 0;
vector<pair<long long, long long> > bridge;
long long prime[1000005];
long long bitTree[100005];
long long bitTreeArray[100005];
void AddBitTree(long long diff, long long n, long long pos) {
  while (pos <= n) {
    bitTree[pos] += diff;
    pos += (pos & -pos);
  }
}
long long getSumBitTree(long long n, long long r) {
  long long sum = 0;
  while (r > 0) {
    sum += bitTree[r];
    r -= (r & -r);
  }
  return sum;
}
long long power(long long a, long long b) {
  if (b == 0) return 1;
  long long x = power(a, b / 2);
  x = (x * x) % 1000000007;
  if (b % 2) return (x * (a % 1000000007)) % 1000000007;
  return x;
}
void sieve() {
  prime[0] = prime[1] = 1;
  for (long long i = 2; i * i < 1000005; i++) {
    if (prime[i] == 0) {
      for (long long j = i * i; j < 1000005; j += i) prime[j] = 1;
    }
  }
}
void dfs(long long node, long long par) {
  vis[node] = true;
  long long child = 0;
  t++;
  disc[node] = low[node] = t;
  for (auto i : graph[node]) {
    if (!vis[i]) {
      child++;
      dfs(i, node);
      low[node] = min(low[node], low[i]);
      if (par == -1 and child > 1) {
        art_pt.push_back(node);
      }
      if (par != -1 and low[i] >= disc[node]) {
        art_pt.push_back(node);
      }
      if (low[i] > disc[node]) {
        bridge.push_back({node, i});
      }
    } else {
      if (par != i) {
        low[node] = min(low[node], disc[i]);
      }
    }
  }
}
long long func2(string s) {
  long long a1 = 0, a2 = 0, c1 = 5, c2 = 5;
  for (long long i = 0; i < 10; i++) {
    if (i % 2) {
      c2--;
      a2 += (s[i] - '0');
    } else {
      c1--;
      a1 += (s[i] - '0');
    }
    if (c1 < a2 - a1) {
      return i + 1;
    }
    if (c2 < a1 - a2) {
      return i + 1;
    }
  }
  return 10;
}
void func(string s, long long ind, long long &ans) {
  if (ind == 10) {
    ans = min(ans, func2(s));
    return;
  }
  if (s[ind] == '?') {
    s[ind] = '0';
    func(s, ind + 1, ans);
    s[ind] = '1';
    func(s, ind + 1, ans);
    s[ind] = '?';
  } else {
    func(s, ind + 1, ans);
  }
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    long long ans = INT_MAX;
    func(s, 0, ans);
    cout << ans << endl;
  }
}
