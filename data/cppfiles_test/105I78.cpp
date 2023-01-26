#include<bits/stdc++.h>
using namespace std;
const int N = 1e6+5;
#define fi(i,a,b)  for(int i = (a); i <= (b); i++)
typedef long long ll;
ll a[N], b[N], c[N];
struct P{
	int x, y, id;
}p[N <<1];
int com(P a, P b){
	if(a.y != b.y)return a.y < b.y;
	if(a.x != b.x)return a.x < b.x;
}
vector <P> vec[N << 1];
int flag[N << 1];
vector<int> flagvec;
int da[N], db[N];
int main(){
    // freopen("in.txt", "r", stdin);
    int t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        fi(i,1,n){
        	cin >> a[i] >> b[i] >> c[i];
        	int tmpa = min(c[i], a[i]), tmpb = min(c[i], b[i]);
        	if(!flag[a[i] + b[i] - c[i]])flagvec.push_back(a[i] + b[i] - c[i]);
        	flag[a[i] + b[i] - c[i]] = 1;
        	vec[a[i] + b[i] - c[i]].push_back({max(0ll, a[i]-c[i]), a[i] - min(c[i] - b[i], 0ll), i});
		}
		int num = 0;
		for(auto i:flagvec){
			sort(vec[i].begin(), vec[i].end(), com);
			int pre = 0;
			int len = vec[i].size();
			for(int l = 0, r; l < len; l = r+1){
				int lmax = vec[i][l].x, rmin = vec[i][l].y;
				r = l + 1;
				while(r < len && (max(lmax, vec[i][r].x) <= min(rmin, vec[i][r].y))){
					lmax = max(lmax, vec[i][r].x);
					rmin = min(rmin, vec[i][r].y);
					r++;
				}
				r--;
				num++;
				fi(j,l,r){
					int id = vec[i][j].id;
					da[id] = a[id] - lmax;
					db[id] = c[id] - da[id];
				}
			}
//			num -= ans - 1;
////			cout << i << ' ' << ansc << ' ' << ansa <<  ' ' << ansb << "------" << '\n';
//			for(auto v:vec[i]){
//				da[v.id] = a[v.id] - ansa;  db[v.id] = b[v.id] - ansb;
//			}
		}
//		cout << "_------\n";
		cout << num << '\n';
//		cout << ansa << " " << ansb  << ' ' << ansc << '\n';
		fi(i,1,n){
			cout << da[i] << ' ' << db[i] << '\n';
//			if(a[i] + b[i] - c[i] == ansc){
//				cout << a[i] - ansa << ' ' << b[i] - ansb << '\n';
//			}else{
//				cout << min(a[i], c[i]) << ' ' << c[i] - min(a[i], c[i]) << '\n'; 
//			}
		}
		for(auto i:flagvec){
			flag[i] = 0;
			vec[i].clear();
		}
		flagvec.clear();
    }
    return 0;
}