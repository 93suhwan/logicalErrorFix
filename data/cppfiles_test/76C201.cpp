#include <bits/stdc++.h>
using namespace std;
const unsigned int ev = 0xAAAAAAAA;
const unsigned int od = 0x55555555;
void kmp(long long n, long long a[], string s) {
  a[0] = 0;
  for (auto i = 1; i < n; i++) {
    long long j = a[i - 1];
    while (j > 0 && s[j] != s[i]) {
      j = a[j - 1];
    }
    if (s[i] == s[j]) {
      j++;
    }
    a[i] = j;
  }
}
void dfsUtil(vector<long long> adj[], bool visited[], long long s) {
  visited[s] = true;
  for (auto pro : adj[s]) {
    if (!visited[pro]) dfsUtil(adj, visited, pro);
  }
}
long long fp(long long x, long long n, long long MOD) {
  long long ans = 1;
  while (n > 0) {
    if (n & 1) ans *= x;
    x *= x;
    ans %= MOD;
    x %= MOD;
    n /= 2;
  }
  return ans;
}
void mobiusmu(long long n, long long vals[], bool comps[]) {
  vals[1] = 1;
  vector<long long> primevec;
  for (auto i = 2; i <= n; i++) {
    if (!comps[i]) {
      primevec.push_back(i);
      vals[i] = -1;
    }
    for (auto j = 0; j < primevec.size() && (primevec[j]) * i <= n; j++) {
      if (i % (primevec[j]) == 0) {
        vals[i * (primevec[j])] = 0;
        break;
      } else {
        vals[i * (primevec[j])] = vals[i] * vals[primevec[j]];
      }
    }
  }
}
void makesegtree(vector<long long> &segtree, long long n,
                 vector<long long> &a) {
  for (auto i = n; i <= 2 * n - 1; i++) {
    segtree[i] = a[i - n];
  }
  for (long long i = n - 1; i > 0; i--) {
    segtree[i] = max(segtree[2 * i], segtree[2 * i + 1]);
  }
}
void update(vector<long long> &segtree, long long n, long long l,
            long long al) {
  l -= 1;
  l += n;
  segtree[l] = al;
  while (l / 2 > 0) {
    if (l % 2) {
      segtree[l / 2] = max(segtree[l - 1], segtree[l]);
    } else {
      segtree[l / 2] = max(segtree[l], segtree[l + 1]);
    }
    l /= 2;
  }
}
long long operate(vector<long long> &segtree, long long n, long long x) {
  long long begin = 1;
  if (segtree[begin] < x) return -1;
  while (2 * begin + 1 < 2 * n) {
    if (segtree[2 * begin] >= x) {
      begin *= 2;
    } else {
      begin *= 2;
      begin += 1;
    }
  }
  return begin - n;
}
bool compare(string a, string b) {
  if (a.size() > b.size())
    return false;
  else {
    if (a.size() < b.size())
      return true;
    else {
      for (auto i = 0; i < a.size(); i++) {
        if (a[i] > b[i]) return false;
        if (a[i] < b[i]) return true;
      }
    }
  }
  return false;
}
long long get(long long i, long long arr[]) {
  if (arr[i] != i) {
    return get(arr[i], arr);
  }
  return i;
}
long long getpoints(long long x, long long arr[], long long curr[],
                    long long diff[]) {
  if (arr[x] == x) {
    return curr[x];
  } else {
    return diff[x] + getpoints(arr[x], arr, curr, diff);
  }
}
void unionn(long long u, long long v, long long curr[], long long arr[],
            long long diff[], long long sizes[]) {
  long long a, b;
  a = get(u, arr);
  b = get(v, arr);
  if (a == b) return;
  if (sizes[a] > sizes[b]) {
    swap(a, b);
  }
  arr[a] = b;
  sizes[b] += sizes[a];
  diff[a] = curr[a] - curr[b];
}
void add(long long x, long long v, long long arr[], long long curr[]) {
  long long a = get(x, arr);
  curr[a] += v;
}
bool truth(multiset<pair<long long, long long>> &ss, long long power) {
  for (auto it = ss.begin(); it != ss.end(); it++) {
    if (power > (it->first)) {
      power += (it->second);
    } else {
      return false;
    }
  }
  return true;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long n, m;
  cin >> n >> m;
  long long dp[n + 1];
  dp[0] = 0;
  dp[1] = 1;
  dp[2] = 3;
  dp[2] %= m;
  for (auto i = 3; i <= n; i++) {
    dp[i] = 2 * dp[i - 1];
    for (long long j = 2, la; j <= i; j = la + 1) {
      la = i / (i / j);
      dp[i] += (dp[i / j] - dp[i / j - 1]) * (la - j + 1);
      dp[i] %= m;
    }
  }
  cout << (m + dp[n] - dp[n - 1]) % m << endl;
}
