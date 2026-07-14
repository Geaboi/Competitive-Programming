class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        /*
            0: 1   #1
            1: 0   #2
            2: 1   #0
 

        */

        //or store the bfs and that should work

        vector<int> res;
        vector<int> in_degree(numCourses, 0);
        queue<int> q;
        //I want to build the b -> a map

        unordered_map<int,vector<int>> edges;

        for(auto it: prerequisites){
            int a = it[0];
            int b = it[1];

            edges[b].push_back(a);
            in_degree[a]++;
        }

        for(int i = 0 ; i < in_degree.size(); i++){
            if(in_degree[i] == 0) q.push(i);
        }


        while(!q.empty()){
            int cur = q.front();
            q.pop();

            res.push_back(cur);
            for(auto it : edges[cur]){
                in_degree[it]--;
                if(in_degree[it] == 0) q.push(it);
            }
        }

        return res.size() == numCourses ? res : vector<int>{};
    }
};