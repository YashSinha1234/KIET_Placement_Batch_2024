class Solution {
public:
    inline bool dfs(const int src, vector<bool>& isVisited, vector<bool>& inRoad, const vector<vector<int>>& adj) {
        isVisited[src] = true;
        inRoad[src] = true;
        for (const int& dst: adj[src]) {
            if (inRoad[dst])
                return true;

            if (!isVisited[dst] && dfs(dst, isVisited, inRoad, adj)) {
                return true;
            }
        }
        inRoad[src] = false;
        return false;
    }
    bool canFinish(int num, vector<vector<int>>& input) {
        // vector<int> cnt(num, 0);
        // vector<vector<int>> adj(num);

        // for (int i = 0; i < input.size(); i++) {
        //     cnt[input[i][0]] ++;
        //     adj[input[i][1]].push_back(input[i][0]);
        // }

        // queue<int> q;
        // for (int i = 0; i < num; i++) {
        //     if (cnt[i] == 0) {
        //         q.push(i);
        //     }
        // }
        
        // int total = 0;
        // while (!q.empty()) {
        //     int cur = q.front();
        //     q.pop();
        //     total++;

        //     for (int& val: adj[cur]) {
        //         cnt[val]--;
        //         if (cnt[val] == 0)
        //             q.push(val);
        //     }
        // }

        // return total == num;

        //cach 2 
        vector<bool>        isVisited(num, false);
        vector<bool>        inRoad(num, false);
        vector<vector<int>> adj(num);

        for (int i = 0; i < input.size(); i++) {
            adj[input[i][1]].push_back(input[i][0]);
        }

        for (int i = 0; i < num; i++) {
            if (!isVisited[i] && dfs(i, isVisited, inRoad, adj))
                return false;
        }

        for (int i = 0; i < num; i++) {
            if (inRoad[i])
                return false;
        }

        return true;
    }
};