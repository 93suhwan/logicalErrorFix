#include <bits/stdc++.h>
using namespace std;
vector<int> noprimes(1000001);
void seive(vector<int> &primes, int n) {
  vector<bool> ntprimes(n + 1, false);
  ntprimes[0] = ntprimes[1] = true;
  for (int i = 2; i * i <= n; i++) {
    if (!ntprimes[i]) {
      for (int j = i * i; j <= n; j += i) {
        ntprimes[j] = true;
      }
    }
  }
  int x = 0;
  for (int i = 2; i <= n; i++) {
    if (!ntprimes[i]) {
      primes.push_back(i);
      x++;
      noprimes[i] = x;
    } else
      noprimes[i] = x;
  }
}
long long pow(long long x, long long n) {
  long long res = 1;
  while (n) {
    if (n % 2 == 0) {
      n = n / 2;
      x = x * x;
    } else {
      res *= x;
      n--;
    }
  }
  return res;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int W, H, x1, y1, x2, y2, w, h;
    cin >> W >> H >> x1 >> y1 >> x2 >> y2 >> w >> h;
    int freewt = W - x2;
    int freewb = x1;
    if (freewt >= w || freewb >= w) {
      cout << 0 << endl;
      continue;
    } else {
      int req = w - max(freewb, freewt);
      if (req <= min(freewb, freewt)) {
        cout << req << endl;
        continue;
      }
    }
    int freeht = H - y2;
    int freehb = y1;
    if (freeht >= h || freehb >= h) {
      cout << 0 << endl;
      continue;
    } else {
      int req = h - max(freehb, freeht);
      if (req <= min(freehb, freeht)) {
        cout << req << endl;
        continue;
      } else {
        cout << -1 << endl;
      }
    }
  }
  return 0;
}
