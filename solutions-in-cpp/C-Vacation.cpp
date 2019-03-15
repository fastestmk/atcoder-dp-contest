#include<iostream>
#include<vector>

using namespace std;

#define ll long long 

const int INF = 1e9+5;

int main(){
	//freopen("tree.in","r",stdin);
    //freopen("tree.out","w",stdout);
    //freopen("input.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    //cin.tie(0);

	int n;
	cin >> n;

	vector<int> dp(3);
	
	for(int day = 0; day < n; ++day){
		vector<int> new_dp(3, 0);
		vector<int> act(3);

		for(int i = 0; i < 3; ++i){
			cin >> act[i];
		}

		for(int i = 0; i < 3; ++i){
			for(int j = 0; j < 3; ++j){
				if(i != j){
					new_dp[j] = max(new_dp[j], dp[i]+act[j]); // avoiding consecutive activities
				}
			}
		}		
		//cout << new_dp[0] << " " << new_dp[1] << " " << new_dp[2] << endl;
		dp = new_dp;
	}
	cout << max(dp[0], max(dp[1], dp[2])) << endl;
}