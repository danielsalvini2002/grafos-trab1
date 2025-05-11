#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class AnimalGroups {
public:
    int numGroups;
    vector<vector<int>> relations;

    AnimalGroups(int numGroups) {
        this->numGroups = numGroups;
        relations.resize(numGroups, vector<int>(numGroups, 0));
    }

    void addRelation(int X, int Y, char attack) {
        if (attack == 'A') {
            relations[X][Y] = 1;
            relations[Y][X] = 1;
        }
    }

    bool isBipartite_1() {
        vector<int> group(numGroups, -1);
        for (int i = 0; i < numGroups; i++) {
            if (group[i] == -1) {
                if (!dfs_recursive(i, group, 0)) {
                    return false;
                }
            }
        }
        return true;
    }

    bool dfs_recursive(int v, vector<int>& group, int color) {
        group[v] = color;

        for (int u = 0; u < numGroups; u++) {
            if (relations[v][u] == 1) {
                if (group[u] == -1) {
                    if (!dfs_recursive(u, group, 1 - color)) {
                        return false;
                    }
                } else if (group[u] == group[v]) {
                    return false;
                }
            }
        }
        return true;
    }

    bool isBipartite_2() {
        vector<int> group(numGroups, -1);
        for (int i = 0; i < numGroups; i++) {
            if (group[i] == -1) {
                if (!dfs_iterative(i, group)) {
                    return false;
                }
            }
        }
        return true;
    }

    bool dfs_iterative(int start, vector<int>& group) {
        stack<int> s;
        s.push(start);
        group[start] = 0;

        while (!s.empty()) {
            int v = s.top();
            s.pop();

            for (int u = 0; u < numGroups; u++) {
                if (relations[v][u] == 1) {
                    if (group[u] == -1) {
                        group[u] = 1 - group[v];
                        s.push(u);
                    } else if (group[u] == group[v]) {
                        return false;
                    }
                }
            }
        }
        return true;
    }
};

int main() {
    int A, R;
    cin >> A >> R;

    AnimalGroups groups(A);

    for (int i = 0; i < R; i++) {
        int X, Y;
        char Z;
        cin >> X >> Y >> Z;
        groups.addRelation(X, Y, Z);
    }

    if (groups.isBipartite_1()) {
        cout << "SIM" << endl;
    } else {
        cout << "NAO" << endl;
    }

    if (groups.isBipartite_2()) {
        cout << "SIM" << endl;
    } else {
        cout << "NAO" << endl;
    }

    return 0;
}
