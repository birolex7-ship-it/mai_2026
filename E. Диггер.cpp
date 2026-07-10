#include <bits/stdc++.h>
 
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;
using pll = array<ll, 2>;
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
 
    ll n, m;
    cin >> n >> m;
 
    ll sum = 0;
 
    // Матрица для хранения количества золота в каждой клетке
    vector<vector<ll>> grid(n, vector<ll>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }
 
    // Матрица для расчета максимального золота на пути из (0,0)
    vector<vector<ll>> dp(n, vector<ll>(m, 0));
    dp[0][0] = grid[0][0];
 
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) { 
            if (i == 0 && j == 0) {
                continue;
            }
            
            ll from_top = 0;
            ll from_left = 0;
            ll from_diag = 0;
            
            // Проверка и получение значений из допустимых предыдущих состояний
            if (i - 1 >= 0) {
                from_top = dp[i - 1][j];
            }
            if (j - 1 >= 0) {
                from_left = dp[i][j - 1];
            }
            if (i - 1 >= 0 && j - 1 >= 0) {
                from_diag = dp[i - 1][j - 1];
            }
 
            // Выбор лучшего пути и добавление золота текущей ячейки
            dp[i][j] = max({from_top, from_left, from_diag}) + grid[i][j];
        }
    }
    cout << dp[n - 1][m - 1] << '\n';
 
    return 0;
}
