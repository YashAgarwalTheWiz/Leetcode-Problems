class UnionFind
{
public:
	UnionFind(int n, vector<int> initialSizes)
		: data(n)
	{
        for (int i = 0; i < n && i < initialSizes.size(); ++i)
            data[i].size = initialSizes[i];
	}

	int findSet(int x)
	{
		if (data[x].parent < 0)
			return x;

		return data[x].parent = findSet(data[x].parent);
	}

	void unionSets(int x, int y)
	{
		x = findSet(x);
		y = findSet(y);

		if (x == y)
			return;

		if (data[x].size < data[y].size)
			swap(x, y);

		data[y].parent = x;
		data[x].size += data[y].size;
	}

	long long size(int x)
	{
		return data[findSet(x)].size;
	}

	int countSets()
	{
		unordered_set<int> roots;
		for (int i = 0; i < data.size(); ++i)
		{
			roots.insert(findSet(i));
		}
		return roots.size();
	}

private:
	struct Data
	{
		int parent = -1;
		long long size = 1;
	};
	vector<Data> data;
};

vector<vector<int>> edgeListToAdjacencyList(int n, const vector<vector<int>>& edges)
{
	vector<vector<int>> graph(n, vector<int>());
	for (const auto& edge : edges)
	{
		graph[edge[0]].push_back(edge[1]);
		graph[edge[1]].push_back(edge[0]);
	}
	return graph;
}

class Solution
{
public:
	int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k)
	{
		vector<vector<int>> graph = edgeListToAdjacencyList(n, edges);
		UnionFind components(n, values);
		findComponents(0, -1, graph, k, components);
		return components.countSets();
	}

	void findComponents(int cur, int prev, vector<vector<int>>& graph, int k, UnionFind& components)
	{
        // If leaf node
		if (graph[cur].size() == 1 && graph[cur][0] == prev)
		{
			if (components.size(cur) % k != 0)
			{
				components.unionSets(prev, cur);
			}
			return;
		}

		for (int n : graph[cur])
		{
            if (n == prev)
				continue;
            
			findComponents(n, cur, graph, k, components);
			if (components.size(n) % k != 0)
				components.unionSets(cur, n);
		}
	}
};