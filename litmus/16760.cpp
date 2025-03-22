#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<string, int>> students;
    string name;
    int score;

    for (int i = 0; i < n; i++) {
        cin >> name >> score;
        students.push_back({name, score});
    }

    sort(students.begin(), students.end(), [](const auto& a, const auto& b) {
        return a.second > b.second;
    });

    for (int i = 0; i < n; i++) {
        cout << i + 1 << ", " << students[i].first << ": " << students[i].second << endl;
    }

    return 0;
}