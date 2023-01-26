#include <bits/stdc++.h>
using namespace std;
long long powerr(long long x, long long y) {
  if (y == 0) {
    return 1;
  }
  long long z = powerr(x, y / 2);
  z = z * z;
  z %= 998244353;
  if (y % 2) {
    z = z * x;
    z %= 998244353;
  }
  return z;
}
long long inv(long long x) { return powerr(x, 998244353 - 2); }
int32_t main() {
  long long k, a, h;
  cin >> k >> a >> h;
  long long n = (1 << (k));
  set<long long> ff;
  long long poss = 0;
  map<long long, vector<long long>> m1;
  if (n <= 16) {
    for (long long i = 0; i < (((long long)(1)) << (n - 1)); i++) {
      long long eliminated[n];
      memset(eliminated, 0, sizeof(eliminated));
      vector<long long> lefters;
      for (long long j = 0; j < n; j++) {
        lefters.push_back(j);
      }
      long long req = lefters.size() / 2;
      vector<long long> rems;
      long long curr = 0;
      long long stages = 0;
      for (long long j = 0; j < (n - 1); j++) {
        if (i & (1 << j)) {
          rems.push_back(lefters[curr]);
          eliminated[lefters[curr + 1]] = stages;
          curr += 2;
        } else {
          rems.push_back(lefters[curr + 1]);
          eliminated[lefters[curr]] = stages;
          curr += 2;
        }
        if (rems.size() == req) {
          curr = 0;
          stages++;
          lefters = rems;
          req = (lefters.size()) / 2;
          rems.clear();
        }
      }
      assert(lefters.size() == 1);
      eliminated[lefters[0]] = stages;
      for (long long j = 0; j < n; j++) {
        eliminated[j] = stages - eliminated[j];
      }
      long long hashes = 0;
      for (long long j = 0; j < n; j++) {
        if (eliminated[j] == 0) {
          eliminated[j] = 1;
        } else {
          eliminated[j] = (1 << (eliminated[j] - 1)) + 1;
        }
        long long z = (j + 1) * powerr(a, eliminated[j]);
        z %= 998244353;
        hashes += z;
        hashes %= 998244353;
      }
      if (hashes == h) {
        poss = 1;
        for (long long j = 0; j < n; j++) {
          cout << eliminated[j] << " ";
        }
        cout << "\n";
        break;
      }
    }
    if (poss == 0) {
      cout << "-1\n";
    }
    exit(0);
  }
  long long p = n / 2;
  for (long long i = 0; i < (((long long)(1)) << (p - 1)); i++) {
    long long eliminated[p];
    memset(eliminated, 0, sizeof(eliminated));
    vector<long long> lefters;
    for (long long j = 0; j < p; j++) {
      lefters.push_back(j);
    }
    long long req = lefters.size() / 2;
    vector<long long> rems;
    long long curr = 0;
    long long stages = 0;
    for (long long j = 0; j < (p - 1); j++) {
      if (i & (1 << j)) {
        rems.push_back(lefters[curr]);
        eliminated[lefters[curr + 1]] = stages;
        curr += 2;
      } else {
        rems.push_back(lefters[curr + 1]);
        eliminated[lefters[curr]] = stages;
        curr += 2;
      }
      if (rems.size() == req) {
        curr = 0;
        stages++;
        lefters = rems;
        req = (lefters.size()) / 2;
        rems.clear();
      }
    }
    assert(lefters.size() == 1);
    eliminated[lefters[0]] = stages;
    for (long long j = 0; j < p; j++) {
      eliminated[j] = stages - eliminated[j];
      eliminated[j]++;
    }
    long long hashes = 0;
    for (long long j = 0; j < p; j++) {
      if (eliminated[j] == 0) {
        eliminated[j] = 1;
      } else {
        eliminated[j] = (1 << (eliminated[j] - 1)) + 1;
      }
      long long z = (p + j + 1) * powerr(a, eliminated[j]);
      z %= 998244353;
      hashes += z;
      hashes %= 998244353;
    }
    vector<long long> yop;
    for (long long j = 0; j < p; j++) {
      yop.push_back(eliminated[j]);
    }
    m1[hashes] = yop;
  }
  for (long long i = 0; i < (((long long)(1)) << (p - 1)); i++) {
    long long eliminated[p];
    memset(eliminated, 0, sizeof(eliminated));
    vector<long long> lefters;
    for (long long j = 0; j < p; j++) {
      lefters.push_back(j);
    }
    long long req = lefters.size() / 2;
    vector<long long> rems;
    long long curr = 0;
    long long stages = 0;
    for (long long j = 0; j < (p - 1); j++) {
      if (i & (1 << j)) {
        rems.push_back(lefters[curr]);
        eliminated[lefters[curr + 1]] = stages;
        curr += 2;
      } else {
        rems.push_back(lefters[curr + 1]);
        eliminated[lefters[curr]] = stages;
        curr += 2;
      }
      if (rems.size() == req) {
        curr = 0;
        stages++;
        lefters = rems;
        req = (lefters.size()) / 2;
        rems.clear();
      }
    }
    assert(lefters.size() == 1);
    eliminated[lefters[0]] = stages;
    for (long long j = 0; j < p; j++) {
      eliminated[j] = stages - eliminated[j];
    }
    long long hashes = 0;
    for (long long j = 0; j < p; j++) {
      if (eliminated[j] == 0) {
        eliminated[j] = 1;
      } else {
        eliminated[j]++;
        eliminated[j] = (1 << (eliminated[j] - 1)) + 1;
      }
      long long z = (j + 1) * powerr(a, eliminated[j]);
      z %= 998244353;
      hashes += z;
      hashes %= 998244353;
    }
    req = 998244353 + h - hashes;
    req %= 998244353;
    if (m1.find(req) != m1.end()) {
      auto xx = m1[req];
      for (long long j = 0; j < p; j++) {
        cout << eliminated[j] << " ";
      }
      for (long long j = 0; j < p; j++) {
        cout << xx[j] << " ";
      }
      cout << "\n";
      exit(0);
    }
  }
}
