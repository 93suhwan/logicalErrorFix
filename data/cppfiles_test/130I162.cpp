#include <bits/stdc++.h>
using namespace std;
struct P {
  int x, y;
  bool operator<(const P &p) {
    if (x != p.x)
      return x < p.x;
    else
      return y < p.y;
  }
};
int main() {
  int T;
  cin >> T;
  for (int t = 0; t < T; ++t) {
    int n;
    cin >> n;
    int bsz = n / 3;
    vector<int> buf(bsz);
    for (int i = 0; i < n / 3; ++i) {
      cout << "? " << 3 * i + 1 << " " << 3 * i + 2 << " " << 3 * i + 3 << endl;
      cout.flush();
      cin >> buf[i];
      if (buf[i] == -1) {
        break;
      }
    }
    int ind0, ind1;
    for (int i = 0; i < bsz; ++i) {
      int indl = i;
      int indr = (i + 1) % bsz;
      if (buf[indl] != buf[indr]) {
        vector<int> tbuf(6);
        tbuf[0] = buf[indl];
        for (int j = 1; j <= 5; ++j) {
          int v1 = (3 * indl + j) % n + 1;
          int v2 = (3 * indl + j + 1) % n + 1;
          int v3 = (3 * indl + j + 2) % n + 1;
          cout << "? " << v1 << " " << v2 << " " << v3 << endl;
          cout.flush();
          cin >> tbuf[j];
          if (tbuf[j] == -1) {
            break;
          }
          if (tbuf[j - 1] != tbuf[j]) {
            if (tbuf[j - 1] == 0) {
              ind0 = (3 * indl + j - 1) % n + 1;
              ind1 = v3;
            } else {
              ind1 = (3 * indl + j - 1) % n + 1;
              ind0 = v3;
            }
            break;
          }
        }
        break;
      }
    }
    vector<int> mapping(n);
    mapping[ind1 - 1] = 1;
    for (int i = 0; i < bsz; ++i) {
      int v1 = 3 * i + 1;
      if (v1 != ind0 && v1 != ind1) {
        cout << "? " << ind0 << " " << ind1 << " " << v1 << endl;
        cout.flush();
        cin >> mapping[v1 - 1];
        if (mapping[v1 - 1] == -1) {
          break;
        }
      }
      int v2 = 3 * i + 2;
      if (v2 != ind0 && v2 != ind1) {
        cout << "? " << ind0 << " " << ind1 << " " << v2 << endl;
        cout.flush();
        cin >> mapping[v2 - 1];
        if (mapping[v2 - 1] == -1) {
          break;
        }
      }
      int v3 = 3 * i + 3;
      if (v3 != ind0 && v3 != ind1) {
        cout << "? " << ind0 << " " << ind1 << " " << v3 << endl;
        cout.flush();
        cin >> mapping[v3 - 1];
        if (mapping[v3 - 1] == -1) {
          break;
        }
      }
    }
    vector<int> fake;
    for (int i = 0; i < n; ++i) {
      if (mapping[i] == 0) {
        fake.push_back(i + 1);
      }
    }
    cout << "! " << fake.size();
    for (int i = 0; i < fake.size(); ++i) {
      cout << " " << fake[i];
    }
    cout << endl;
    cout.flush();
  }
  return 0;
}
