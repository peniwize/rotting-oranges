# Start of "solution.py".

from collections import deque
import inspect
import time
from typing import List
from typing import Set

"""
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
"""

"""
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
"""
class Solution1_BFS:
    def orangesRotting(self, grid: List[List[int]]) -> int:
        ROWS = len(grid) # m == grid.length; 1 <= m
        COLS = len(grid[0]) # n == grid[i].length; n <= 10
        if 0 >= COLS: return -1

        que = deque()
        freshCnt = 0 # Number of fresh oranges.

        # Populate queue with all rotten oranges.
        for iy in range(ROWS):
            for ix in range(COLS):
                if 1 == grid[iy][ix]: # Orange is fresh.
                    freshCnt += 1
                if 2 == grid[iy][ix]: # Orange is rotten.
                    que.append((ix, iy))
        
        minutes = -1 if 0 < len(que) else 0

        while 0 < len(que):
            # Rot adjacent oranges (1 step).
            for _ in range(len(que), 0, -1):
                x, y = que.popleft()
                for dx, dy in [
                             [ 0, -1],
                    [-1,  0],         [ 1,  0],
                             [ 0,  1]
                ]:
                    nx, ny = x + dx, y + dy
                    if 0 <= nx < COLS and 0 <= ny < ROWS:
                        if 1 == grid[ny][nx]: # Orange is fresh.
                            que.append((nx, ny))
                            grid[ny][nx] = 2 # Make orange rotten.
                            freshCnt -= 1
            
            minutes += 1

        return -1 if 0 < freshCnt else minutes

def test1(solution):
    grid = [
        [2,1,1],
        [1,1,0],
        [0,1,1]
    ]
    expected = 4
    startTime = time.time()
    result = solution.orangesRotting(grid)
    endTime = time.time()
    print("{}:{}({:.6f} sec) result = {}".format(inspect.currentframe().f_code.co_name, type(solution), endTime - startTime, result))
    assert(expected == result)

def test2(solution):
    grid = [
        [2,1,1],
        [0,1,1],
        [1,0,1]
    ]
    expected = -1
    startTime = time.time()
    result = solution.orangesRotting(grid)
    endTime = time.time()
    print("{}:{}({:.6f} sec) result = {}".format(inspect.currentframe().f_code.co_name, type(solution), endTime - startTime, result))
    assert(expected == result)

def test3(solution):
    grid = [
        [0,2]
    ]
    expected = 0
    startTime = time.time()
    result = solution.orangesRotting(grid)
    endTime = time.time()
    print("{}:{}({:.6f} sec) result = {}".format(inspect.currentframe().f_code.co_name, type(solution), endTime - startTime, result))
    assert(expected == result)

def test4(solution):
    grid = [
        [2,1,1],
        [1,1,1],
        [0,1,2]
    ]
    expected = 2
    startTime = time.time()
    result = solution.orangesRotting(grid)
    endTime = time.time()
    print("{}:{}({:.6f} sec) result = {}".format(inspect.currentframe().f_code.co_name, type(solution), endTime - startTime, result))
    assert(expected == result)

def test5(solution):
    grid = [
        [0]
    ]
    expected = 0
    startTime = time.time()
    result = solution.orangesRotting(grid)
    endTime = time.time()
    print("{}:{}({:.6f} sec) result = {}".format(inspect.currentframe().f_code.co_name, type(solution), endTime - startTime, result))
    assert(expected == result)

if "__main__" == __name__:
    test1(Solution1_BFS())
    test2(Solution1_BFS())
    test3(Solution1_BFS())
    test4(Solution1_BFS())
    test5(Solution1_BFS())

# End of "solution.py".
