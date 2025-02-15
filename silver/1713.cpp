#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int recom[1001];
vector<int> cand = vector<int>();
int vote[101];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cand.push_back(0);

    int N;
    int count;

    cin >> N;
    cin >> count;

    for (int i = 1; i <= 100; i++) {
        vote[i] = 0;
    }

    for (int i = 1; i <= count; i++) {
        cin >> recom[i];
    }

    for (int i = 1; i <= count; i++) {
        vote[recom[i]] += 1;
        bool exists = false;

        for (int j = 1; j <= N; j++) {
            if(cand[j] == recom[i]) exists = true;
        }

        if (exists) continue;

        if (cand.size() == N + 1) {
            int min = 1000;
            int drop_cand = 0;
            int min_index = 0;
            for (int j = 1; j <= N; j++) {
                if (vote[cand[j]] < min) {
                    drop_cand = cand[j];
                    min = vote[cand[j]];
                    min_index = j;
                }
            }
            vote[drop_cand] = 0;
            cand.erase(cand.begin() + min_index);
            cand.push_back(recom[i]);
        } else {
            cand.push_back(recom[i]);
        }
    }

    sort(cand.begin() + 1, cand.end());

    for (int i = 1; i <= N; i++) {
        if (cand[i] != 0) {
            cout << cand[i] << ' ';
        }
    }
}