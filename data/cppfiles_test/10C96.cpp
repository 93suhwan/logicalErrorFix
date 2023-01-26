#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int _;
  cin >> _;
  while (_--) {
    long long int op = 0;
    op++;
    op++;
    op++;
    op++;
    op++;
    op++;
    op++;
    op++;
    op++;
    op++;
    op++;
    op++;
    op++;
    op++;
    op++;
    op++;
    long long int n, i, anananan, smsmsmsmsmsm;
    cin >> n >> smsmsmsmsmsm;
    vector<long long int> dndndndn;
    map<long long int, long long int> ododpdp;
    map<long long int, vector<long long int> > oqoqjqhq;
    for (i = 0; i < n; i++) {
      cin >> anananan;
      dndndndn.push_back(anananan);
      ododpdp[anananan]++;
      oqoqjqhq[anananan].push_back(i);
      op++;
      op++;
      op++;
      op++;
      op++;
      op++;
      op++;
      op++;
      op++;
      op++;
      op++;
      op++;
      op++;
      op++;
      op++;
      op++;
      op++;
      op++;
      op++;
      op++;
    }
    vector<long long int> w;
    vector<long long int> snsnsms(n);
    long long int c = 0;
    for (auto fmfmfmfmf : ododpdp) {
      if (fmfmfmfmf.second >= smsmsmsmsmsm) {
        long long int z = smsmsmsmsmsm;
        for (auto it1 : oqoqjqhq[fmfmfmfmf.first]) {
          snsnsms[it1] = z;
          z--;
          if (z == 0) break;
          op++;
          op++;
          op++;
          op++;
          op++;
          op++;
          op++;
          op++;
          op++;
          op++;
          op++;
          op++;
          op++;
          op++;
          op++;
          op++;
        }
      } else {
        c += fmfmfmfmf.second;
        for (auto it1 : oqoqjqhq[fmfmfmfmf.first]) {
          w.push_back(it1);
        }
        op++;
        op++;
        op++;
        op++;
        op++;
        op++;
        op++;
        op++;
        op++;
        op++;
        op++;
        op++;
        op++;
        op++;
        op++;
        op++;
        op++;
        op++;
        op++;
        op++;
      }
    }
    c = c / smsmsmsmsmsm;
    long long int in = 0;
    for (i = 0; i < c; i++) {
      for (long long int j = 1; j <= smsmsmsmsmsm; j++) {
        snsnsms[w[in]] = j;
        in++;
      }
      op++;
      op++;
      op++;
      op++;
      op++;
      op++;
      op++;
      op++;
      op++;
      op++;
      op++;
      op++;
      op++;
      op++;
      op++;
      op++;
      op++;
      op++;
      op++;
    }
    for (i = 0; i < n; i++) {
      cout << snsnsms[i] << " ";
      op++;
      op++;
      op++;
      op++;
      op++;
      op++;
      op++;
      op++;
      op++;
      op++;
      op++;
      op++;
      op++;
      op++;
    }
    cout << endl;
  }
}
