#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class GradeManagementSystem {
private:
    map<string, int> students;
    map<int, set<string>, greater<int>> scoreToStudents;

public:
    void addOrUpdateStudent(const string& name, int score) {
        auto it = students.find(name);
        if (it != students.end()) {
            scoreToStudents[it->second].erase(name);
            if (scoreToStudents[it->second].empty()) {
                scoreToStudents.erase(it->second);
            }
        }
        students[name] = score;
        scoreToStudents[score].insert(name);
    }

    void getStudentScore(const string& name) {
        auto it = students.find(name);
        if (it != students.end()) {
            cout << it->second << endl;
        } else {
            cout << "None" << endl;
        }
    }

    void printSortedStudents() {
        if (students.empty()) {
            cout << "None" << endl;
            return;
        }
        for (const auto& score : scoreToStudents) {
            for (const auto& name : score.second) {
                cout << name << " ";
            }
        }
        cout << endl;
    }
};

int main() {
    GradeManagementSystem gms;
    int choice;
    string name;
    int score;

    while (true) {
        cin >> choice;
        switch (choice) {
            case 1:
                cin >> name >> score;
                gms.addOrUpdateStudent(name, score);
                break;
            case 2:
                cin >> name;
                gms.getStudentScore(name);
                break;
            case 3:
                gms.printSortedStudents();
                break;
            case 4:
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}