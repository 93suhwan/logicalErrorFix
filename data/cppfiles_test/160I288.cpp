#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;
int main() {
  ll T;
  cin >> T;
  for (long long t = 0; t < (long long)(T); t++) {
    ll N, M, A, B, C, D;
    cin >> N >> M >> A >> B >> C >> D;
    ll DY = 1, DX = 1;
    for (long long i = 0; i < (long long)(1000); i++) {
      if (A == C || B == D) {
        cout << i << endl;
        break;
      }
      A += DY;
      B += DX;
      if (A == N || A == 1) {
        DY *= -1;
      }
      if (B == M || B == 1) {
        DX *= -1;
      }
    }
  }
}
