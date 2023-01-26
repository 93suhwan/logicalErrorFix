#include <bits/stdc++.h>

#define MAXN 200005
#define MOD 998244353

typedef long long ll;

using namespace std;
vector<int> save;
vector<int> losers;
ll hashC = 0;
map<array<ll, 2>, vector<int>> imp;
//hash, last
ll powA[18];
ll k, a, h;

void simulate(int place) {
	int teams = save.size();
	if (teams == 1) {
		//	cout << hashC << "\n";
		hashC += save[0] * powA[place] % MOD;
		hashC %= MOD;
		//	cout<<losers.size()<<"\n";
		if (!imp.count({hashC, save[0]}))
			imp[ { hashC, save[0] }].insert(imp[ { hashC, save[0] }].end(),
					losers.begin(), losers.end());
		return;
	}
	vector<int> old = save;
	vector<int> oldLosers = losers;
	int oldHash = hashC;
	for (int poss = 0; poss <= (1 << (teams / 2)) - 1; poss++) {
		save.clear();
		losers = oldLosers;
		for (int i = 0; i < teams / 2; i++) {
			if (poss & (1 << i)) {
				save.push_back(old[i * 2 + 1]);
				hashC += powA[place] * old[i * 2];
				hashC %= MOD;
				losers.push_back(old[i * 2]);
			} else {
				save.push_back(old[i * 2]);
				hashC += powA[place] * old[i * 2 + 1];
				hashC %= MOD;
				losers.push_back(old[i * 2 + 1]);
			}
		}
		simulate((place > 2) ? place / 2 + 1 : 1);
		hashC = oldHash;
	}
}
int main() {
#ifdef orange
    freopen("input.txt", "r", stdin);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> k >> a >> h;
	powA[0] = 1;
	for (int i = 1; i < 18; i++)
		powA[i] = powA[i - 1] * a % MOD;
	if (k == 5) {
		imp.clear();
		for (int i = 1; i <= 16; i++)
			save.push_back(i);
		simulate(17);
		map<array<ll, 2>, vector<int>> imp1;
		map<ll, int> imp1C, impC;
		for (auto entry : imp) {
			//		cout<<entry.second.size()<<"\n";
			imp1[entry.first] = entry.second;
			imp1C[entry.first[0]] = entry.first[1];
		}

		save.clear();
		imp.clear();
		losers.clear();
		hashC = 0;
		for (int i = 17; i <= 32; i++)
			save.push_back(i);
		simulate(17);
		for (auto entry : imp) {
			impC[entry.first[0]] = entry.first[1];
		}
		for (int z = 0; z < 2; z++) {
			for (auto entry : imp) {
				ll totalH = (entry.first[0] + MOD
						- powA[2] * entry.first[1] % MOD
						+ a * entry.first[1] % MOD) % MOD;
				ll otherH = (h - totalH + MOD) % MOD;
				if (imp1C.count(otherH)) {
					int oL = imp1C[otherH];
					auto saveL = imp1[ { otherH, oL }];
					int ans[32] { };
					int losers = 16;
					ans[entry.first[1] - 1] = 1;
					ans[oL - 1] = 2;

					int idx = 0, idx1 = 0;
					while (losers >= 1) {
						for (int z = 0; z < losers / 2; z++) {
							ans[saveL[idx++] - 1] = losers + 1;
						}
						for (int z = 0; z < losers / 2; z++) {
							ans[entry.second[idx1++] - 1] = losers + 1;
						}
						losers /= 2;
					}
					for (int a : ans)
						cout << a << " ";
					cout << "\n";
					return 0;
				}
			}
		}
	} else {
		int teams = (1 << k);
		for (int i = 1; i <= teams; i++)
			save.push_back(i);
		simulate(teams / 2 + 1);
		for (int i = 1; i <= teams; i++) {
			if (imp.count( { h, i })) {
				int ans[teams] { };
				ans[i - 1] = 1;
				vector<int> impT = imp[ { h, i }];
				int losers = teams / 2;
				int place = teams / 2 + 1;
				int idx = 0;
				while (losers >= 1) {
					for (int z = 0; z < losers; z++) {
						ans[impT[idx++] - 1] = place;
					}
					place = place / 2 + 1;
					losers /= 2;
				}
				for (int a : ans)
					cout << a << " ";
				cout << "\n";
				return 0;
			}
		}
	}
	cout << -1 << "\n";
}
