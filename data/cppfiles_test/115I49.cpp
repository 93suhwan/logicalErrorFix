#include <bits/stdc++.h>

using ll = long long;
#define MOD ll(998244353)

ll modpow(ll a, ll b) {
	ll ret = 1;
	while (b) {
		if (b & 1)
			ret = (ret * a) % MOD;
		a = (a * a) % MOD;
		b /= 2;
	}
	return ret;
}

ll mod_div2(ll val) {
	if (val & 1) val += MOD;
	return val / 2;
}
ll mod_mul(ll a, ll b){
	return (a * b) % MOD;
}

ll mod_div(ll a, ll b) {
	if (b == 1)
		return a;
	if (b == 2) {
		if (a & 1) a += MOD;
		return a / 2;
	}
	assert(false);
}

struct State {
	ll val;
	int val_fails = 0;
	int even1_fails = 0;
	int even2_fails = 0;
	static State from_pair(const std::pair<int, int> &p, int idx) {
		int sum = (bool(p.first) + bool(p.second));
		State state;
		state.val = sum == 0 ? 2 : 1;
		state.val_fails = sum == 2 ? 1 : 0;
		state.even1_fails = (sum == 2 ? 1 : (sum == 0 ? 0 : bool(p.first) == idx % 2));
		state.even2_fails = (sum == 2 ? 1 : (sum == 0 ? 0 : bool(p.first) != idx % 2));
		return state;
	}
};

#define PRINT(expr) (std::cerr << #expr " = " << (expr) << "\n")
struct Patern {
	int size;
	
	State state;

	std::vector<std::pair<int, int>> data;

	Patern(int size_) : size(size_), data(size, std::make_pair(0, 0)) {
		state.val = modpow(2, size);
	}

	void add(int idx, std::pair<int, int> val) {
		State old_state = State::from_pair(data[idx], idx);
		data[idx].first += val.first;
		data[idx].second += val.second;
		State new_state = State::from_pair(data[idx], idx);
		
		state.val = mod_div(state.val, old_state.val);
		state.val_fails -= old_state.val_fails;
		state.even1_fails -= old_state.even1_fails;
		state.even2_fails -= old_state.even2_fails;
		
		state.val = mod_mul(state.val, new_state.val);
		state.val_fails += new_state.val_fails;
		state.even1_fails += new_state.even1_fails;
		state.even2_fails += new_state.even2_fails;
	}
	
	ll get_val() {
		//PRINT(state.val_fails);
		if (state.val_fails)
			return 0;
		return state.val;
	}
	
	bool get_even1() {
		if (state.val_fails)
			return false;
		return state.even1_fails == 0;
	}

	bool get_even2() {
		if (state.val_fails)
			return false;
		return state.even2_fails == 0;
	}
};

std::pair<int, int> create_p(int idx, int v) {
	std::pair<int, int> p(0, 0);
	if (v == 0)
		p.first++;
	if (v == 1)
		p.second++;
	if (idx & 1)
		std::swap(p.first, p.second);
	return p;
}

std::pair<int, int> sub_p(auto p1, auto p2) {
	return std::make_pair(p1.first - p2.first, p1.second - p2.second);
}

#define PRINT(expr)

int main() {
	int xx, yy, k;
	std::cin >> xx >> yy >> k;

	Patern xp(xx);
	Patern yp(yy);
	std::map<std::pair<int, int>, int> mp;
	while (k--) {
		int x, y, v;
		std::cin >> x >> y >> v;
		x--, y--;
		std::pair<int, int> xy(x, y);
		auto it = mp.find(xy);
		if (it == mp.end())
			mp[xy] = -1;
		auto old_v = mp[xy];
		mp[xy] = v;

		auto convert_p_x = sub_p(create_p(y, v), create_p(y, old_v));
		auto convert_p_y = sub_p(create_p(x, v), create_p(x, old_v));
		//std::cerr << convert_p_y.first << " " << convert_p_y.second << "\n";
		xp.add(x, convert_p_x);
		yp.add(y, convert_p_y);
		//std::cerr << xp.get_val() << " " << yp.get_val() << "\n";
		ll tot = xp.get_val() + yp.get_val();
		PRINT(xp.state.even1_fails);
		PRINT(yp.state.even1_fails);
		//PRINT(xp.state.even2_fails);
		//PRINT(yp.state.even2_fails);
		PRINT(xp.get_even1());
		PRINT(yp.get_even1());
		//PRINT(xp.get_even2());
		//PRINT(yp.get_even2());
		PRINT(xp.state.val_fails);
		PRINT(yp.state.val_fails);
		if (xp.get_even1() && yp.get_even1()) tot--;
		if (xp.get_even2() && yp.get_even2()) tot--;
		std::cout << tot << "\n";
		//std::cout << xp.get_val() + yp.get_val() << "\n";

	}
}
