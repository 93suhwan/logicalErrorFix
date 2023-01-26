#include<iostream>
#include<algorithm>
#include<vector>
#pragma GCC optimize("Ofast")

using namespace std;
class config {
public:
	int hi;
	int lo;
	int last_value;
	config* last_node;
};

bool comp(config* c1, config* c2) {
	if (c1->hi != c2->hi) return c1->hi < c2->hi;
	if (c1->lo != c2->lo) return c1->lo < c2->lo;
	if (c1->last_value != c1->last_value) return c1->last_value < c2->last_value;
	if (c1->last_node != c2->last_node) return c1->last_node < c2->last_node;
	return false;
}

int p[1000001];
int ans[1000001];
char output[10000000];
int outp;

int main() {
	cin.sync_with_stdio(false);
	outp = 0;
	int t, n;
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> p[i];
		}
		vector<config*> configs;
		configs.push_back(new config{ -1000001, -1000002, 0, 0});
		for (int k = 0; k < n; k++) {
			int i = p[k];
			vector<config*> next;
			for (auto c : configs) {
				//cout << "checking: "<< c->hi << " " << c->lo << endl;
				if (i > c->hi) next.push_back(new config{ i, c->lo, i, c });
				else if (i > c->lo) next.push_back(new config{ c->hi, i, i, c });

				if (-i > c->hi) next.push_back(new config{ -i, c->lo, -i, c });
				else if (-i > c->lo) next.push_back(new config{ c->hi, -i, -i, c });
			}
			sort(next.begin(), next.end(), comp);
			//for (auto c : next) cout << c->hi << " " << c->lo << endl;
			//cout << endl;
			configs.clear();
			for (config* c : next) {
				if (configs.size() == 0) {
					configs.push_back(c);
				}
				else if (configs.back()->hi < c->hi && configs.back()->lo > c->lo) {
					configs.push_back(c);
				}
			}
		}

		if (configs.size()) {
			outp += sprintf_s(&output[outp], 3000000-outp, "YES\n");
			config c = *configs.back();
			for (int i = n - 1; i >= 0; i--) {
				ans[i] = c.last_value;
				c = *c.last_node;
			}
			for (int i = 0; i < n; i++) {
				outp += sprintf_s(&output[outp], 3000000 - outp, "%d ", ans[i]);
			}
			outp += sprintf_s(&output[outp], 3000000 - outp, "\n");
		}
		else {
			outp += sprintf_s(&output[outp], 3000000 - outp, "NO\n");
		}
	}
	cout << output;
}