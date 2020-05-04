class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegree(numCourses,0);
        vector<bool> visited(numCourses,false);
        vector<vector<int>> grid(numCourses,vector<int>());
        for(auto vec :prerequisites){
            //���
            indegree[vec[0]]++;
            //ѧ�� 0����ѧ1
            grid[vec[1]].push_back(vec[0]);
        }
        queue<int> q;
        //û���Ⱦ�����
        for (int i = 0; i < indegree.size(); ++i)
        {
            if (indegree[i]==0)
            {
                q.push(i);
            }
        }
        while(!q.empty()){
            int idx=q.front();q.pop();
            visited[idx]=true;
            for (int i = 0; i < grid[idx].size(); ++i)
            {
                indegree[grid[idx][i]]--;
                if (indegree[grid[idx][i]]==0&&!visited[grid[idx][i]])
                {
                    q.push(grid[idx][i]);
                }
            }
        }
        //bian li visited
        for (auto b:visited)
        {
            if (!b)
            {
                return false;
            }
        }
        return true;
        
    }
};