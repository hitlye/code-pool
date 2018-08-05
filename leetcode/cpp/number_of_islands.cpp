// Copyright 2018 Leo - All Rights Reserved
// Author: Leo
// Best solution time: O(n * m) n row * m col
// Best solution space: O(1)

// Solution dependencies
#include<string>
#include<vector>

using std::string;
using std::vector;

// Core: DFS find all lands(1) belong to current islands
//
// Trick: Set visited (i,j) = '0' to avoid using extra map.
//
// Time: O(n * m)
// Space: O(1)
class Solution {
 public:
  int numIslands(vector<vector<char>>& grid) { // NOLINT(*)
    int island_num = 0;
    int row_num = grid.size();
    int col_num = grid.empty() ? 0 : grid[0].size();

    for (int i = 0; i < row_num; ++i) {
      for (int j = 0; j < col_num; ++j) {
        // lands mean new islands
        if (grid[i][j] == '1') ++island_num;

        // dfs search this island's all lands
        dfs(grid, row_num, col_num, i, j);
      }
    }
    return island_num;
  }

  void dfs(vector<vector<char>> &grid, const int &row_num,   //  NOLINT(*)
           const int &col_num, int i, int j) {
    // Boundary check
    if (i < 0 or i >= row_num or j < 0 or j >= col_num or grid[i][j] == '0') // NOLINT(*)
      return;
    // use origin map as a cache
    grid[i][j] = '0';
    // up
    dfs(grid, row_num, col_num, i - 1, j);
    // down
    dfs(grid, row_num, col_num, i + 1, j);
    // left
    dfs(grid, row_num, col_num, i, j - 1);
    // right
    dfs(grid, row_num, col_num, i, j + 1);
  }
};


// Core: Union Find to calculate final connected componets via islands
//       A new land will cause num of islands + 1, but if it can be connected
//       with other lands, then num of islands - 1.
// Time: O(n * m)
// Space: O(n * m)
class UnionFind {
 public:
  vector<int> ids;
  int connected_components;

 public:
  explicit UnionFind(int size) {
    ids.resize(size);
    for (int i = 0; i < size; ++i) ids[i] = i;
    connected_components = 0;
  }

  void connect(int p, int q) {
    int rootp = find(p);
    int rootq = find(q);
    if (rootp == rootq) return;
    ids[rootp] = rootq;
    --connected_components;
  }

  int find(int p) {
    int rootp = p;
    while (rootp != ids[rootp]) {
      rootp = ids[rootp];
    }
    // path compression
    while (p != ids[p]) {
      int newp = ids[p];
      ids[p] = rootp;
      p = newp;
    }
    return rootp;
  }
};

class Solution2 {
 public:
  int numIslands(const vector<vector<char>>& grid) {
    int row_num = grid.size();
    int col_num = grid.empty() ? 0 : grid[0].size();
    UnionFind uf(row_num * col_num);
    for (int i = 0; i < row_num; ++i) {
      for (int j = 0; j < col_num; ++j) {
        // lands mean new islands
        if (grid[i][j] == '0') continue;
        ++uf.connected_components;

        // up
        if (i > 0 && grid[i - 1][j] == '1')
          uf.connect((i - 1) * col_num + j, i * col_num + j);
        // left
        if (j > 0 && grid[i][j - 1] == '1')
          uf.connect(i * col_num + j - 1, i * col_num + j);
      }
    }
    return uf.connected_components;
  }
};
