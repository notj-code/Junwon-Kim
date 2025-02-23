#include <bits/stdc++.h>

using namespace std;

vector<int> solve(vector<int>& FjFavCows) {
    int N = FjFavCows.size();
    vector<int> result;

    for (int i = 0; i < N; i++) {
        int value = FjFavCows[i];
        vector<int> temp = FjFavCows;
        temp.erase(temp.begin() + i);
        
        for (int j = 0; j <= i; j++) {
            vector<int> current = temp;
            current.insert(current.begin() + j, value);
            
            vector<int> b;
            vector<int> a = current;
            while (!a.empty()) {
                if (b.empty() || a.back() >= b.back()) {
                    b.push_back(a.back());
                }
                a.pop_back();
            }
            reverse(b.begin(), b.end());
            
            if (b > result) {
                result = b;
            }
        }
    }
    
    vector<int> noMoveB;
    vector<int> a = FjFavCows;
    while (!a.empty()) {
        if (noMoveB.empty() || a.back() >= noMoveB.back()) {
            noMoveB.push_back(a.back());
        }
        a.pop_back();
    }
    reverse(noMoveB.begin(), noMoveB.end());
    
    return max(result, noMoveB);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        vector<int> FjFavCows(N);
        for (int i = 0; i < N; i++) {
            cin >> FjFavCows[i];
        }
        vector<int> result = solve(FjFavCows);
        for (int i = 0; i < result.size(); i++) {
            cout << result[i] << (i < result.size() - 1 ? " " : "\n");
        }
    }
    return 0;
}
