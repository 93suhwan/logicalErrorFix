
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
	
	unordered_set<ll> div(ll n){
		unordered_set<ll> v;
	    for (int i = 2; i <= sqrt(n); i++) {
	        if (n % i == 0) {
		            if (n / i != i)
	                v.insert(n / i);
	            }
	    }
	    v.insert(n);
	    return v;
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
			
			//obtener los divisores, y después buscar que los otros
			//numeros restantes sean distintos de tal divisor.. 
			bool flag = true;
			
			ll div1 = mcd(a);
			ll div2 = mcd(b);

			unordered_set<ll>dd1 = div(div1);
			unordered_set<ll>dd2 = div(div2);	
			
			//cout<<div1<<" "<<div2<<"\n";
			
			if(div1!=1){
				
					for(int i=0; i<n; i++){
						if(i%2==1){							
							if(dd1.size() == 0){
								flag = false;
								break;
							}
							vector<ll>eliminar;
							for(auto a:dd1){
								if(v[i]%a==0){
									eliminar.push_back(a);
								}
							}
							for(auto a:eliminar){
								dd1.erase(a);
							}
						}
					}
				
				if(flag){
					for(auto a:dd1){
								cout<<a<<" ";
								break;
						}
				}
			}
			
			if(div2!=1 && (dd1.size()==0 || div1==1)){
				flag = true;
				for(int i=0; i<n; i++){
					if(i%2==0){
						if(dd2.size() == 0){
							flag = false;
							break;
						}
						vector<ll>eliminar;
						for(auto a:dd2){
							if(v[i]%a==0){
								eliminar.push_back(a);
							}
						}
						for(auto a:eliminar){
							dd2.erase(a);
						}
					}
				}
				if(flag){
					for(auto a:dd2){
							cout<<a<<" ";
							break;
					}
				}
			}
			
			if(!flag)cout<<0;
			cout<<"\n";
		}		
	}