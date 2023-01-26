#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma,tune=native")
typedef long long lld;
typedef double lf;
typedef long double llf;
typedef pair<int,int> pii;
typedef pair<lld,lld> pll;
#define For(i,s,a) for(int i = (int)s; i < (int)a; ++i)
#define rpt(s, it) for(auto it = s.begin(); it != s.end(); ++it)
#define brpt(s, it) for(auto it = s.rend(); it != s.rbegin(); --it)
#define sz size()
#define pb push_back
#define eb emplace_back
#define ff first
#define dd second
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define make_unique(x) (x).erase( unique(all(x)), (x).end())
#define popcnt(x) __builtin_popcount(x)
 
template<typename Ta, typename Tb>
ostream & operator <<(ostream & os, pair<Ta, Tb> x){
	return os << x.ff << " " << x.dd;
}

const int N = 6e5 + 1;
const lld mod = 998244353;
int fu[N];
bitset<N>banned, banned_word, used;
vector<int> words_containing_a_letter[N];

int find(int x) {
	if(fu[x] == x)
		return x;
	fu[x] = find(fu[x]);
	return fu[x];
}

void unio(int x, int y) {
	x = find(x);
	y = find(y);
	fu[y] = x;
}

struct node {
	int size;
	vector<int>contents;
	cc_hash_table<int, int>pos;
}word[N];

priority_queue<pii>R;
int items[N];
lld dp[N];
pii itemct[N];

struct late_letter_comparator {
	int letter;
	late_letter_comparator(int letter):letter(letter){}
	bool operator() (int a, int b) {
		assert(word[a].pos[letter] != 0 && word[b].pos[letter] != 0);
		return word[a].pos[letter] > word[b].pos[letter] || (
		word[a].pos[letter] == word[b].pos[letter] && word[a].contents.size() > word[b].contents.size());
	}
};

void solve(void) {
	int n, destlen, k;
	scanf("%d%d%d", &n, &destlen, &k);
	//n = destlen = k = 3e5;
	//n = 1;
	++k;
	For(i, 0, n)
		fu[i] = i;
	For(i, 0, n) {
		scanf("%d", &word[i].size);
		//word[i].size = k - 1;
		word[i].contents.resize(word[i].size);
		For(j, 0, word[i].size) {
			scanf("%d", &word[i].contents[j]);
			//word[i].contents[j] = min(j + 2, k - 1);
			if(word[i].pos[word[i].contents[j]] == 0)
				word[i].pos[word[i].contents[j]] = j + 1;
			else
				banned[word[i].contents[j]] = 1;
			words_containing_a_letter[word[i].contents[j]].pb(i);
			used[word[i].contents[j]] = 1;
		}
	}
	/*For(i, 1, k) {
		word[i + n - 1].size = 1;
		word[i + n - 1].contents.resize(1);
		word[i + n - 1].contents[0] = i;
		word[i + n - 1].pos[i] = 1;
		words_containing_a_letter[i].pb(i + n - 1);
	}*/
		
	For(i, 1, k)
		R.push(mp(words_containing_a_letter[i].sz, i));
	
	while(!R.empty()) {
		int letter = R.top().dd, hlet = R.top().ff;
	//	cout<<letter<<" litera i jej liczba "<<hlet<<endl;
		R.pop();
		if(hlet < 2)
			continue;
		
		bool any_banned_char = 0;
		For(i, 0, words_containing_a_letter[letter].sz) {
	//		cout<<words_containing_a_letter[letter][i]<<" "<<find(words_containing_a_letter[letter][i])<<endl;
			if(find(words_containing_a_letter[letter][i]) != words_containing_a_letter[letter][i]) {
				swap(words_containing_a_letter[letter][i], words_containing_a_letter[letter].back());
				words_containing_a_letter[letter].pop_back();
				--i;
				continue;
			}
			any_banned_char |= banned_word[words_containing_a_letter[letter][i]];
			if(!any_banned_char)
			for(auto l : word[words_containing_a_letter[letter][i]].contents)
				any_banned_char |= banned[l];
			
		}
		
		if(any_banned_char) {
			For(i, 0, words_containing_a_letter[letter].sz) {
				for(auto l : word[words_containing_a_letter[letter][i]].contents)
					banned[l] = 1;
				banned_word[words_containing_a_letter[letter][i]] = 1;
				word[words_containing_a_letter[letter][i]].contents.clear();
			}
			continue;
		}
		
		sort(all(words_containing_a_letter[letter]), late_letter_comparator(letter));
		
	/*	cout<<letter<<" words:\n";
		for(auto wor : words_containing_a_letter[letter]) {
			for(auto s : word[wor].contents)
				cout<<s<<" ";
			puts("");
		}
		puts("");
	*/	
		int nr_first_word = words_containing_a_letter[letter][0];
		int where_letter_first_word = word[nr_first_word].pos[letter] - 1;
		while(words_containing_a_letter[letter].sz > 1) {
	//		cout<<words_containing_a_letter[letter].sz<<" so fk me up "<<endl;
			int nr_last_word = words_containing_a_letter[letter].back();
			int where_letter = word[nr_last_word].pos[letter] - 1;
			bool eq = 1;
			int len = min(word[nr_last_word].contents.size(), 
			              word[nr_first_word].contents.size() - where_letter_first_word + where_letter);
	/*		cout<<"comparing words\n";
			for(auto s : word[nr_first_word].contents)
				cout<<s<<" ";
			puts("");
			for(auto s : word[nr_last_word].contents)
				cout<<s<<" ";
			puts("");
	*/	              
			For(i, 0, len) {
	//			cout<<word[nr_first_word].contents[i + where_letter_first_word - where_letter]<<" cmpcmp "<<word[nr_last_word].contents[i]<<endl;
				eq &= word[nr_first_word].contents[i + where_letter_first_word - where_letter] ==
					  word[nr_last_word].contents[i];
	//			cout<<eq<<" "<<word[nr_first_word].contents[i + where_letter_first_word - where_letter]<<" "<<word[nr_last_word].contents[i]<<endl;
				if(!eq)
					break;
			}
			
	//		cout<<eq<<" haha "<<endl;
			
			if(!eq) {
				//cout<<"banning: "<<nr_first_word<<endl;
				banned_word[nr_first_word] = 1;
	//			banned[nr_last_word] = 1;
				R.push(mp(696969696, letter));
				break;
			}
			
	///		cout<<nr_first_word<<" murg "<<nr_last_word<<endl<<endl;
			unio(nr_first_word, nr_last_word);
			
			if(len == (int)word[nr_last_word].contents.size()) {
				words_containing_a_letter[letter].pop_back();
				continue;
			}
			
			For(i, word[nr_first_word].contents.size() - where_letter_first_word, word[nr_last_word].contents.size()) {
				int pushed_letter = word[nr_last_word].contents[i];
				word[nr_first_word].contents.pb(pushed_letter);
				if(word[nr_first_word].pos[pushed_letter] != 0)
					banned_word[nr_first_word] = 1;
				word[nr_first_word].pos[pushed_letter] = word[nr_first_word].contents.size();
			}
			words_containing_a_letter[letter].pop_back();
			
			if(banned_word[nr_first_word]) {
				R.push(mp(696969696, letter));
				break;
			}
	//		cout<<words_containing_a_letter[letter].sz<<" before I go go \n\n";
		}
	}
	
	For(i, 1, k)
		if(!banned[i] && !used[i])
			++items[1];
	For(i, 0, n)
		if(fu[i] == i && !banned_word[i]) {
	/*		cout<<i<<endl;
			for(auto s : word[i].contents)
				cout<<s<<" ";
			puts("\n");
	*/		++items[word[i].contents.size()];
		}
	
	/*For(i, 0, destlen + 1)
		cout<<items[i]<<" ";
	puts("");*/
	
	dp[0] = 1;
	int ileitems = 0;
	For(i, 0, destlen + 1)
	if(items[i])
		itemct[ileitems++] = mp(i, items[i]);
	
	For(i, 0, destlen + 1) {
		For(j, 0, ileitems) {
			if(i - itemct[j].ff < 0)
				break;
			(dp[i] += dp[i - itemct[j].ff] * (lld)itemct[j].dd) %= mod;
		}
	}
	
	printf("%lld\n", dp[destlen]);
}
/*
abcdef
    efgh
   defghijklmnopqrst
*/

int32_t main(void){
	int tt = 1;
	//scanf("%d", &tt);
	while(tt--) 
		solve();
}

/*
11 3 52
2 18 9
3 36 12 35
1 38
1 43
3 20 32 24
3 21 7 37
2 12 36
1 50
3 11 26 17
3 29 11 29
2 47 38

11 3 52
2 18 9
X 3 36 12 35
A 1 38
1 43
3 20 32 24
3 21 7 37
X 2 12 36
1 50
3 11 26 17
3 29 11 29
2 47 38

*/

/*
3 50 20
6 1 2 3 4 5 6
4         5 6 7 8
10      4 5 6 7 8 9 10 12 13 14
*/
