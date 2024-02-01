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
    Time = O(?)

    Space = O(?)
*/
class Solution1_BFS {
public:
    int orangesRotting(vector<vector<int>>& grid) {

//
//!\todo TODO: >>> Under Construction <<<
//
return -1;

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

/*
    End of "main.cpp"
*/
