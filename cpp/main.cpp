/*!
    \file "main.cpp"

    Author: Matt Ervin <matt@impsoftware.org>
    Formatting: 4 spaces/tab (spaces only; no tabs), 120 columns.
    Doc-tool: Doxygen (http://www.doxygen.com/)

    https://leetcode.com/problems/rotting-oranges/
*/

//!\sa https://github.com/doctest/doctest/blob/master/doc/markdown/main.md
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "utils.hpp"

/*
    You are given an m x n grid where each cell can have one of three values:

        * 0 representing an empty cell,
        * 1 representing a fresh orange, or
        * 2 representing a rotten orange.

    Every minute, any fresh orange that is 4-directionally adjacent to a 
    rotten orange becomes rotten.

    Return the minimum number of minutes that must elapse until no cell has 
    a fresh orange. If this is impossible, return -1.

    Constraints:

        * m == grid.length
        * n == grid[i].length
        * 1 <= m, n <= 10
        * grid[i][j] is 0, 1, or 2.
*/

/*
    Use breadth first search.
    Initially populate queue with all rotten oranges.
    Each cycle through the queue represents one minute.
    Return the cycle count if no fresh oranges exist after 
    the breadth first search, else return -1.

    Time = O(m*n + V + E)
           => O(m*n + m*n + 4*m*n)
           => O(6*m*n) => O(m*n)

    Space = O(max(n,m))
             - or -
            O(m*n) when all oranges start rotten and no empty spots.
*/
class Solution1_BFS {
    static constexpr int neighbors_[][2] = {{0, -1}, {-1, 0}, {1, 0}, {0, 1}};
public:
    int orangesRotting(vector<vector<int>>& grid) {
        auto const rows = grid.size(); // m == grid.length; 1 <= m
        auto const cols = grid[0].size(); // n == grid[i].length; n <= 10
        constexpr int const fresh = 1;
        constexpr int const rotten = 2;
        using point_t = tuple<int, int>;
        deque<point_t> que{};
        int freshOranges = 0;

        for (size_t iy = 0; rows > iy; ++iy) {
            for (size_t ix = 0; cols > ix; ++ix) {
                switch (grid[iy][ix]) {
                    case fresh: ++freshOranges; break;
                    case rotten: que.emplace_back(make_tuple(ix, iy)); break;
                }
            }
        }

        int minutes = que.empty() ? 0 : -1;
        
        while (!que.empty()) {
            for (auto queCnt = que.size(); queCnt; --queCnt) {
                auto const [x, y] = que.front();
                que.pop_front();
                for (auto const [dx, dy] : neighbors_) {
                    auto const nx = x + dx;
                    auto const ny = y + dy;
                    if (0 <= nx && cols > nx && 0 <= ny && rows > ny) {
                        if (fresh == grid[ny][nx]) {
                            que.emplace_back(make_tuple(nx, ny));
                            grid[ny][nx] = rotten;
                            --freshOranges;
                        }
                    }
                }
            }

            ++minutes;
        }

        return 0 < freshOranges ? -1 : minutes;
    }
};

// [----------------(120 columns)---------------> Module Code Delimiter <---------------(120 columns)----------------]

namespace doctest {
    const char* testName() noexcept { return doctest::detail::g_cs->currentTest->m_name; }
} // namespace doctest {

TEST_CASE("Case 1")
{
    cerr << doctest::testName() << '\n';
    auto grid = vector<vector<int>>{
        {2,1,1},
        {1,1,0},
        {0,1,1}
    };
    int expected = 4;
    auto solution = Solution1_BFS{};
    { // New scope.
        auto const start = std::chrono::steady_clock::now();
        auto const result = solution.orangesRotting(grid);
        CHECK(expected == result);
        cerr << "Elapsed time: " << elapsed_time_t{start} << '\n';
    }
    cerr << "\n";
}

TEST_CASE("Case 2")
{
    cerr << doctest::testName() << '\n';
    auto grid = vector<vector<int>>{
        {2,1,1},
        {0,1,1},
        {1,0,1}
    };
    int expected = -1;
    auto solution = Solution1_BFS{};
    { // New scope.
        auto const start = std::chrono::steady_clock::now();
        auto const result = solution.orangesRotting(grid);
        CHECK(expected == result);
        cerr << "Elapsed time: " << elapsed_time_t{start} << '\n';
    }
    cerr << "\n";
}

TEST_CASE("Case 3")
{
    cerr << doctest::testName() << '\n';
    auto grid = vector<vector<int>>{
        {0,2},
    };
    int expected = 0;
    auto solution = Solution1_BFS{};
    { // New scope.
        auto const start = std::chrono::steady_clock::now();
        auto const result = solution.orangesRotting(grid);
        CHECK(expected == result);
        cerr << "Elapsed time: " << elapsed_time_t{start} << '\n';
    }
    cerr << "\n";
}

TEST_CASE("Case 4")
{
    cerr << doctest::testName() << '\n';
    auto grid = vector<vector<int>>{
        {2,1,1},
        {1,1,1},
        {0,1,2}
    };
    int expected = 2;
    auto solution = Solution1_BFS{};
    { // New scope.
        auto const start = std::chrono::steady_clock::now();
        auto const result = solution.orangesRotting(grid);
        CHECK(expected == result);
        cerr << "Elapsed time: " << elapsed_time_t{start} << '\n';
    }
    cerr << "\n";
}

TEST_CASE("Case 5")
{
    cerr << doctest::testName() << '\n';
    auto grid = vector<vector<int>>{
        {0},
    };
    int expected = 0;
    auto solution = Solution1_BFS{};
    { // New scope.
        auto const start = std::chrono::steady_clock::now();
        auto const result = solution.orangesRotting(grid);
        CHECK(expected == result);
        cerr << "Elapsed time: " << elapsed_time_t{start} << '\n';
    }
    cerr << "\n";
}

/*
    End of "main.cpp"
*/
