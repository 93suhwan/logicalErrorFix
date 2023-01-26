#include <bits/stdc++.h>
using ll = long long int;
using ld = long double;
using namespace std;
ll fastpow(ll b, ll e) {
  if (!e) {
    return 1;
  }
  if (e % 2) {
    return b * fastpow(b, e - 1);
  }
  ll x = fastpow(b, e / 2);
  return x * x;
}
ll PowMod(ll b, ll e, ll M) {
  if (!e) {
    return 1;
  }
  ll p = PowMod((b * b) % M, e / 2, M);
  return (e % 2) ? (p * b) % M : p;
}
struct Node {
  Node* left = NULL;
  Node* right = NULL;
  ll data;
  Node(ll d) { data = d; }
};
int calcDist(string n, string x) {
  int i = 0, j = 0;
  int taken = 0;
  while (i < n.size() && j < x.size()) {
    if (n[i] == x[j]) {
      taken++;
      i++;
      j++;
    } else
      i++;
  }
  return n.size() + x.size() - 2 * taken;
}
int min(int x, int y, int z) { return min(min(x, y), z); }
int main() {
  int t;
  cin >> t;
  vector<string> matches;
  int i = 0;
  ll curr_power = fastpow(2, 0);
  matches.push_back(to_string(curr_power));
  while (curr_power < 1e18) {
    i++;
    curr_power = fastpow(2, i);
    matches.push_back(to_string(curr_power));
  }
  while (t--) {
    ll n;
    cin >> n;
    string curr = to_string(n);
    ll best_scroe = calcDist(curr, matches[0]);
    string best = matches[0];
    for (int i = 1; i < 32; i++) {
      int curr_score = calcDist(curr, matches[i]);
      if (curr_score < best_scroe) {
        best_scroe = curr_score;
        best = matches[i];
      }
    }
    cout << best_scroe << '\n';
  }
}
