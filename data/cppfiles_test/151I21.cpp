#include <bits/stdc++.h>
using namespace std;
FILE* in = stdin;
FILE* out = stdout;
const int MAX = 500005;
struct Link {
  int index, prev;
  Link(int index_ = 0, int prev_ = -1) : index(index_), prev(prev_){};
};
int n;
Link a[MAX];
int start[MAX], last[MAX];
void addLink(int value, int idx) {
  a[idx] = Link(idx, start[value]);
  start[value] = idx;
  if (last[value] == -1) last[value] = idx;
}
void reLink(int oldValue, int newValue) {
  if (oldValue == newValue) return;
  if (start[oldValue] == -1) return;
  if (start[newValue] != -1) {
    a[last[oldValue]].prev = start[newValue];
  }
  start[newValue] = start[oldValue];
  start[oldValue] = -1, last[oldValue] = -1;
}
int main(void) {
  memset(start, -1, sizeof(start));
  memset(last, -1, sizeof(last));
  int numQueries;
  fscanf(in, "%d", &numQueries);
  int nextIdx = 0;
  for (int i = 0; i < numQueries; i++) {
    int type;
    fscanf(in, "%d", &type);
    if (type == 1) {
      int value;
      fscanf(in, "%d", &value);
      addLink(value, nextIdx++);
    } else {
      int oldValue, newValue;
      fscanf(in, "%d %d", &oldValue, &newValue);
      reLink(oldValue, newValue);
    }
  }
  vector<int> ans(nextIdx);
  for (int value = 0; value < MAX; value++) {
    for (int idx = start[value]; idx != -1; idx = a[idx].prev) {
      ans[a[idx].index] = value;
    }
  }
  for (int i = 0; i < (int)ans.size(); i++)
    fprintf(out, "%d%c", ans[i], i + 1 == (int)ans.size() ? '\n' : ' ');
  return 0;
}
