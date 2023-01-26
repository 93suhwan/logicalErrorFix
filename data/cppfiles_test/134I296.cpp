
		#include <bits/stdc++.h>
	using namespace std;
	typedef long long int ll;
	
	ll mcd(vector<ll>v){
	    ll res = v[0];
	    for (int i = 1; i < v.size(); i++){
	        res = __gcd(v[i], res);
	        if(res == 1){
	           return 1;
	        }
	    }
	    return res;
	}
	
	int main(){
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
		
		int t; cin>>t;
		while(t--){
			int n; cin>>n;
			vector<ll>a,b,v;
			for(int i=0; i<n; i++){
				ll x; cin>>x;
				v.push_back(x);
				if(i%2==0)a.push_back(x);
				else b.push_back(x);
			}
			bool flag = true;
			ll div1 = mcd(a);
			ll div2 = mcd(b);
			//cout<<div1<<" "<<div2;
			if(div1!=1){
					for(int i=0; i<n; i++){
						if(i%2==1){								
							if(v[i]%div1 == 0){
								flag = false;
								break;
							}
						}
					}
				if(flag) cout<<div1;
			}
			
			if(div2!=1){
				flag = true;
				for(int i=0; i<n; i++){
					if(i%2==0){
						if(v[i]%div2 == 0){
								flag = false;
								break;
						}
					}
				}
				
				if(flag) cout<<div2;
			}
			
			if(!flag || (div2 == 1 && div1 == 1))cout<<0;
			cout<<"\n";
		}		
	}