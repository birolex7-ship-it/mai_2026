#include <bits/stdc++.h>
 
using ll = long long;
using namespace std;
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
 
    int t;
    if (cin >> t) {
        while (t--) {
 
            int n;
            cin >> n;
            
            vector<ll> a(n);
            for (int i = 0; i < n; ++i) {
                cin >> a[i];
            }
 
            ll swaps = 0; 
            // Сортировка пузырьком с подсчетом числа перестановок
            for (int i = 0; i < n; ++i) {
                bool changed = false; // Флаг отслеживания обменов за текущий проход
                for (int j = 0; j < n - 1; ++j) {
                    if (a[j] > a[j + 1]) {
                        swap(a[j], a[j + 1]);
                        swaps++;
                        changed = true;
                    }
                }
                // Прерывание цикла, если за проход не было обменов
                if (!changed) {
                    break;
                }
            }
            
            cout << swaps << "\n";
        }
    }
 
    return 0;
}