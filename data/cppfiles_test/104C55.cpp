#include <bits/stdc++.h>
std::mt19937 rng(
    (unsigned int)std::chrono::steady_clock::now().time_since_epoch().count());
using namespace std;
void solve(int ttt) {
  long long int n, m;
  cin >> n >> m;
  vector<long long int> a(n), b(n);
  for (long long int i = 0; i < n; i++) cin >> a[i] >> b[i];
  long long int mx = 0, mn = 0;
  long long int sum = 0;
  vector<long long int> valL(n), valR(n);
  for (long long int i = 0; i < n; i++) {
    sum -= a[i];
    sum += b[i];
    long long int lft = max(0ll, m - a[i]);
    long long int rght = min(b[i], m);
    valL[i] = lft;
    valR[i] = rght;
    mx += 2ll * rght - m;
    mn += 2ll * lft - m;
  }
  if (mn <= sum && sum <= mx) {
    long long int cur = mx;
    long long int req;
    if ((mx & 1) ^ sum & 1) {
      req = sum + 1;
      cout << "1\n";
    } else {
      req = sum;
      cout << "0\n";
    }
    for (int i = 0; i < n; i++) {
      long long int canGo = cur + 2ll * valL[i] - 2ll * valR[i];
      long long int rem = max(req, canGo);
      long long int changeInY = (cur - rem) / 2;
      cur = cur - 2ll * valR[i] + m + (2ll * (valR[i] - changeInY) - m);
      cout << m - valR[i] + changeInY << " " << valR[i] - changeInY << "\n";
    }
  } else if (sum > mx) {
    cout << abs(sum - mx) << "\n";
    for (long long int i = 0; i < n; i++) {
      cout << m - valR[i] << " " << valR[i] << "\n";
    }
  } else {
    cout << abs(mn - sum) << "\n";
    for (long long int i = 0; i < n; i++) {
      cout << m - valL[i] << " " << valL[i] << "\n";
    }
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int ttt;
  ttt = 1;
  cin >> ttt;
  for (long long int i = 0; i < ttt; i++) solve(i);
}
