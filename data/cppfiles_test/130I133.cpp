#include <bits/stdc++.h>
using namespace std;
constexpr long long MAX_LL = 1e15;
constexpr int MOD = 1e9 + 7;
const int IMP = 0;
const int CREW = 1;
int query(int a, int b, int c) {
  cout << "? " << a << " " << b << " " << c << '\n';
  cout.flush();
  int d;
  cin >> d;
  if (d == -1) {
    exit(0);
  }
  return d;
}
void ans(const vector<int>& v) {
  cout << "! " << v.size() << " ";
  for (const auto& d : v) {
    cout << d << " ";
  }
  cout << '\n';
  cout.flush();
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> v(n, -1);
    vector<bool> bucketState(n / 3);
    int impBucket = -1;
    int crewBucket = -1;
    for (int i = 0; i < v.size(); i += 3) {
      bucketState[i / 3] = query(i + 1, i + 2, i + 3);
      if (bucketState[i / 3] == CREW) {
        crewBucket = i / 3;
      } else {
        impBucket = i / 3;
      }
    }
    int impIdx = -1;
    int crewIdx = -1;
    int p = query(impBucket * 3 + 1, impBucket * 3 + 2, crewBucket * 3 + 1);
    int q = query(impBucket * 3 + 1, impBucket * 3 + 2, crewBucket * 3 + 2);
    if (p == IMP && q == IMP) {
      v[impBucket * 3] = IMP;
      v[impBucket * 3 + 1] = IMP;
      impIdx = impBucket * 3;
      p = query(impBucket * 3 + 1, crewBucket * 3 + 1, crewBucket * 3 + 2);
      q = query(impBucket * 3 + 1, crewBucket * 3 + 2, crewBucket * 3 + 3);
      if (p == IMP && q == IMP) {
        v[crewBucket * 3] = CREW;
        v[crewBucket * 3 + 1] = IMP;
        v[crewBucket * 3 + 2] = CREW;
        crewIdx = crewBucket * 3;
      } else if (p == IMP && q == CREW) {
        v[crewBucket * 3] = IMP;
        v[crewBucket * 3 + 1] = CREW;
        v[crewBucket * 3 + 2] = CREW;
        crewIdx = crewBucket * 3 + 1;
      } else if (p == CREW && q == IMP) {
        v[crewBucket * 3] = CREW;
        v[crewBucket * 3 + 1] = CREW;
        v[crewBucket * 3 + 2] = IMP;
        crewIdx = crewBucket * 3;
      } else {
        v[crewBucket * 3] = CREW;
        v[crewBucket * 3 + 1] = CREW;
        v[crewBucket * 3 + 2] = CREW;
        crewIdx = crewBucket * 3;
      }
    } else if (p == CREW && q == IMP) {
      v[crewBucket * 3] = CREW;
      v[crewBucket * 3 + 1] = IMP;
      impIdx = crewBucket * 3 + 1;
      crewIdx = crewBucket * 3;
    } else if (p == IMP && q == CREW) {
      v[crewBucket * 3] = IMP;
      v[crewBucket * 3 + 1] = CREW;
      impIdx = crewBucket * 3;
      crewIdx = crewBucket * 3 + 1;
    } else {
      p = query(impBucket * 3 + 2, impBucket * 3 + 3, crewBucket * 3 + 1);
      q = query(impBucket * 3 + 2, impBucket * 3 + 3, crewBucket * 3 + 2);
      if (p == IMP && q == IMP) {
        v[impBucket * 3] = CREW;
        v[impBucket * 3 + 1] = IMP;
        v[impBucket * 3 + 2] = IMP;
        impIdx = impBucket * 3 + 1;
        crewIdx = impBucket * 3;
      } else if (p == CREW && q == IMP) {
        v[crewBucket * 3] = CREW;
        v[crewBucket * 3 + 1] = IMP;
        impIdx = crewBucket * 3 + 1;
        crewIdx = crewBucket * 3;
      } else if (p == IMP && q == CREW) {
        v[crewBucket * 3] = IMP;
        v[crewBucket * 3 + 1] = CREW;
        impIdx = crewBucket * 3;
        crewIdx = crewBucket * 3 + 1;
      } else {
        v[impBucket * 3] = IMP;
        v[impBucket * 3 + 1] = CREW;
        v[impBucket * 3 + 2] = IMP;
        impIdx = impBucket * 3;
        crewIdx = impBucket * 3 + 1;
      }
    }
    assert(impIdx != -1 && crewIdx != -1);
    for (int i = 0; i < v.size(); i += 3) {
      if (bucketState[i / 3] == CREW) {
        int p = query(impIdx + 1, i + 1, i + 2);
        int q = query(impIdx + 1, i + 2, i + 3);
        if (p == IMP && q == IMP) {
          v[i + 1] = IMP;
          v[i] = v[i + 2] = CREW;
        } else if (p == IMP && q == CREW) {
          v[i] = IMP;
          v[i + 1] = v[i + 2] = CREW;
        } else if (p == CREW && q == IMP) {
          v[i] = v[i + 1] = CREW;
          v[i + 2] = IMP;
        } else {
          v[i] = v[i + 1] = v[i + 2] = CREW;
        }
      } else {
        int p = query(crewIdx + 1, i + 1, i + 2);
        int q = query(crewIdx + 1, i + 2, i + 3);
        if (p == IMP && q == IMP) {
          v[i] = v[i + 1] = v[i + 2] = IMP;
        } else if (p == IMP && q == CREW) {
          v[i] = v[i + 1] = IMP;
          v[i + 2] = CREW;
        } else if (p == CREW && q == IMP) {
          v[i] = CREW;
          v[i + 1] = v[i + 2] = IMP;
        } else {
          v[i + 1] = CREW;
          v[i] = v[i + 2] = IMP;
        }
      }
    }
    vector<int> imposters;
    for (int i = 0; i < v.size(); ++i) {
      if (v[i] == IMP) {
        imposters.push_back(i + 1);
      }
    }
    ans(imposters);
  }
  return 0;
}
