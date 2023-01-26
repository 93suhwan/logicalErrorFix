#include <bits/stdc++.h>
using namespace std;
vector<long long int> graph[51];
vector<bool> visited(51);
struct custom_hash {
  static uint64_t splitmix64(uint64_t x) {
    x += 0x9e3779b97f4a7c15;
    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
    x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
    return x ^ (x >> 31);
  }
  size_t operator()(uint64_t x) const {
    static const uint64_t FIXED_RANDOM =
        chrono::steady_clock::now().time_since_epoch().count();
    return splitmix64(x + FIXED_RANDOM);
  }
};
bool sortbysecdesc(const pair<long long int, long long int> &a,
                   const pair<long long int, long long int> &b) {
  return a.first > b.first;
}
void add_edge(vector<int> adj[], int src, int dest) {
  adj[src].push_back(dest);
}
long long int isKthBitSet(int n, int k) {
  if (n & (1 << (30 - k)))
    return 1;
  else
    return 0;
}
long long int ans = 0;
long long gcd(long long int a, long long int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long lcm(long long int a, long long int b) { return (a / gcd(a, b)) * b; }
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int t;
  cin >> t;
  while (t--) {
    long long int n, m;
    cin >> n >> m;
    vector<long long int> A(m), B(m);
    for (long long int i = 0; i < m; i++) cin >> A[i];
    B = A;
    sort(B.begin(), B.end());
    vector<long long int> C(m, 0);
    long long int ans = 0;
    unordered_map<long long int, long long int, custom_hash> mp;
    for (long long int i = 0; i < m; i++) {
      long long int a = upper_bound(B.begin(), B.end(), A[i]) - B.begin() - 1;
      a -= mp[A[i]];
      for (long long int j = 0; j < a; j++)
        if (C[j] == 1) ans++;
      mp[A[i]]++;
      C[a] = 1;
    }
    cout << ans << "\n";
  }
}
