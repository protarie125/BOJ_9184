#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <tuple>
#include <utility>
#include <vector>

using namespace std;

using ll = long long;
using vb = vector<bool>;
using vvb = vector<vb>;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
using vvl = vector<vl>;
using pii = pair<int, int>;
using vii = vector<pii>;
using pll = pair<ll, ll>;
using vll = vector<pll>;

using W = vector<vvl>;

W dp = W(21, vvl(21, vl(21, -1)));

ll getW(ll a, ll b, ll c) {
	if (a <= 0 || b <= 0 || c <= 0) {
		return 1;
	}

	if (20 < a || 20 < b || 20 < c) {
		return getW(20, 20, 20);
	}

	if (dp[a][b][c] < 0) {
		if (a < b && b < c) {
			dp[a][b][c] = getW(a, b, c - 1) + getW(a, b - 1, c - 1) - getW(a, b - 1, c);
		}
		else {
			dp[a][b][c] = getW(a - 1, b, c) + getW(a - 1, b - 1, c) + getW(a - 1, b, c - 1) - getW(a - 1, b - 1, c - 1);
		}
	}

	return dp[a][b][c];
}

int main() {
	ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	ll a, b, c;
	cin >> a >> b >> c;
	while (!(-1 == a && -1 == b && -1 == c)) {
		cout << "w(" << a << ", " << b << ", " << c << ") = " << getW(a, b, c) << '\n';

		cin >> a >> b >> c;
	}

	return 0;
}