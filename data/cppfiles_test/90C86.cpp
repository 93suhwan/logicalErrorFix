#include <bits/stdc++.h>
using namespace std;
const long long int MAX = 1e18;
const int MAXN = 202020;
struct dat {
  int type;
  long long int s, e;
  dat() {
    type = 0;
    s = 0;
    e = 0;
  }
  dat(int _type, long long int _s, long long int _e) {
    type = _type;
    s = _s;
    e = _e;
  }
};
int T;
int N, M;
int S;
vector<bool> del;
vector<long long int> arr;
vector<pair<long long int, long long int> > segm;
vector<dat> vect;
vector<int> nd;
vector<int> pd;
long long int DT[MAXN * 2][2];
void getdel() {
  set<int> st;
  vector<pair<long long int, long long int> > tosort;
  long long int med = MAX;
  for (int i = M - 1; i >= 0; i--) {
    if (med <= segm[i].second) del[i] = 1;
    med = min(med, segm[i].second);
    tosort.push_back(pair<long long int, long long int>(segm[i].first, -i - 1));
    tosort.push_back(
        pair<long long int, long long int>(segm[i].second, +i + 1));
  }
  for (int i = 0; i < N; i++)
    tosort.push_back(pair<long long int, long long int>(arr[i], 0));
  sort(tosort.begin(), tosort.end());
  for (auto [a, b] : tosort) {
    if (b == 0) {
      for (auto i : st) {
        del[i] = true;
      }
      st.clear();
    } else if (b > 0) {
      b--;
      st.erase(b);
    } else {
      b = -b - 1;
      st.insert(b);
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> T;
  while (T--) {
    cin >> N >> M;
    del = vector<bool>(M, false);
    arr.resize(N);
    segm.resize(M);
    vect.clear();
    for (int i = 0; i <= M + N; i++) DT[i][0] = DT[i][1] = MAX;
    for (int i = 0; i < N; i++) {
      cin >> arr[i];
    }
    for (int i = 0; i < M; i++) {
      long long int a, b;
      cin >> a >> b;
      segm[i] = pair<long long int, long long int>(a, b);
    }
    sort(segm.begin(), segm.end(),
         [&](pair<long long int, long long int> a,
             pair<long long int, long long int> b) {
           if (a.first != b.first) return a.first < b.first;
           return a.second > b.second;
         });
    getdel();
    for (int i = 0; i < N; i++) {
      vect.push_back(dat(0, arr[i], arr[i]));
    }
    for (int i = 0; i < M; i++) {
      if (del[i]) continue;
      vect.push_back(dat(1, segm[i].first, segm[i].second));
    }
    sort(vect.begin(), vect.end(), [&](dat a, dat b) { return a.s < b.s; });
    S = vect.size();
    nd = vector<int>(S, -1);
    pd = vector<int>(S, -1);
    for (int i = 0; i < S - 1; i++) {
      if (vect[i].type == 0)
        pd[i + 1] = i;
      else {
        pd[i + 1] = pd[i];
      }
    }
    for (int i = S - 1; i > 0; i--) {
      if (vect[i].type == 0)
        nd[i - 1] = i;
      else {
        nd[i - 1] = nd[i];
      }
    }
    DT[0][0] = DT[0][1] = 0;
    for (int i = 0; i < S; i++) {
      dat now = vect[i];
      if (now.type == 0) {
        DT[i + 1][0] = min({DT[i][0], DT[i + 1][0], DT[i][1]});
        DT[i + 1][1] = min(DT[i + 1][1], DT[i][1]);
      } else {
        if (pd[i] != -1) {
          DT[i + 1][0] =
              min({DT[i + 1][0], DT[pd[i]][1] + 2 * (now.s - vect[pd[i]].s),
                   DT[pd[i]][0] + (now.s - vect[pd[i]].s)});
        }
        if (nd[i] != -1) {
          DT[nd[i]][1] = min(DT[nd[i]][1], (vect[nd[i]].e - now.e) + DT[i][0]);
          DT[nd[i]][0] =
              min(DT[nd[i]][0], 2 * (vect[nd[i]].e - now.e) + DT[i][0]);
        }
      }
    }
    cout << min(DT[S][0], DT[S][1]) << '\n';
  }
  return 0;
}
