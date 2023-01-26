#include <bits/stdc++.h>
using namespace std;
typedef struct node {
  int P, i;
} node;
long long pwmd(long long a, long long b) {
  long long c = 1, m = a;
  while (b) {
    if (b & 1) c = ((c * m)) % 1000000007;
    m = (m * m) % 1000000007;
    b /= 2;
  }
  return c;
}
long long gcd(long long a, long long b) {
  if (b == 0)
    return a;
  else
    return gcd(b, a % b);
}
double roundd(double x, int k) {
  x = (int)(x * pow(10, k) + 0.5);
  x = (double)(x / pow(10, k));
  return x;
}
void solve() {
  int n, m;
  cin >> n >> m;
  vector<int> V;
  vector<int> V2;
  unordered_map<int, int> M;
  for (int i = 0; i < m; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    if (M[a] == 0 && M[b] == 0 && M[c] == 0) {
      V.push_back(a);
      M[a] = V.size();
      V.push_back(c);
      M[c] = V.size();
      V.push_back(b);
      M[b] = V.size();
    } else if (M[a] == 0 && M[b] == 0 && M[c] != 0) {
      V.push_back(a);
      M[a] = V.size();
      V.push_back(b);
      M[b] = V.size();
    } else if (M[a] == 0 && M[b] != 0 && M[c] == 0) {
      V.push_back(a);
      M[a] = V.size();
      V.push_back(c);
      M[c] = V.size();
    } else if (M[a] == 0 && M[b] != 0 && M[c] != 0) {
      if (M[b] > M[c]) {
        V2.push_back(a);
        M[a] = -V2.size();
      } else {
        V.push_back(a);
        M[a] = V.size();
      }
    } else if (M[a] != 0 && M[b] == 0 && M[c] == 0) {
      V.push_back(c);
      M[c] = V.size();
      V.push_back(b);
      M[b] = V.size();
    } else if (M[a] != 0 && M[b] == 0 && M[c] != 0) {
      V.push_back(b);
      M[b] = V.size();
    } else if (M[a] != 0 && M[b] != 0 && M[c] == 0) {
      if (M[a] > M[b]) {
        V.push_back(c);
        M[c] = V.size();
      } else {
        V2.push_back(c);
        M[c] = -V2.size();
      }
    }
  }
  for (int i = V2.size() - 1; i >= 1; i--) {
    cout << V2[i] << " " << V2[i - 1] << "\n";
  }
  if (V2.size() > 0) {
    cout << V2[0] << " " << V[0] << "\n";
  }
  for (int i = 0; i < (V.size() - 1); i++) {
    cout << V[i] << " " << V[i + 1] << "\n";
  }
  return;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
