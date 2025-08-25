/*
There is a game dungeon comprised of n x n rooms arranged in a grid.

You are given a 2D array fruits of size n x n, where fruits[i][j] represents the number of fruits in the room (i, j). Three children will play in the game dungeon, with initial positions at the corner rooms (0, 0), (0, n - 1), and (n - 1, 0).

The children will make exactly n - 1 moves according to the following rules to reach the room (n - 1, n - 1):

The child starting from (0, 0) must move from their current room (i, j) to one of the rooms (i + 1, j + 1), (i + 1, j), and (i, j + 1) if the target room exists.
The child starting from (0, n - 1) must move from their current room (i, j) to one of the rooms (i + 1, j - 1), (i + 1, j), and (i + 1, j + 1) if the target room exists.
The child starting from (n - 1, 0) must move from their current room (i, j) to one of the rooms (i - 1, j + 1), (i, j + 1), and (i + 1, j + 1) if the target room exists.
When a child enters a room, they will collect all the fruits there. If two or more children enter the same room, only one child will collect the fruits, and the room will be emptied after they leave.

Return the maximum number of fruits the children can collect from the dungeon.

 

Example 1:

Input: fruits = [[1,2,3,4],[5,6,8,7],[9,10,11,12],[13,14,15,16]]

Output: 100

Explanation:



In this example:

The 1st child (green) moves on the path (0,0) -> (1,1) -> (2,2) -> (3, 3).
The 2nd child (red) moves on the path (0,3) -> (1,2) -> (2,3) -> (3, 3).
The 3rd child (blue) moves on the path (3,0) -> (3,1) -> (3,2) -> (3, 3).
In total they collect 1 + 6 + 11 + 16 + 4 + 8 + 12 + 13 + 14 + 15 = 100 fruits.

Example 2:

Input: fruits = [[1,1],[1,1]]

Output: 4

Explanation:

In this example:

The 1st child moves on the path (0,0) -> (1,1).
The 2nd child moves on the path (0,1) -> (1,1).
The 3rd child moves on the path (1,0) -> (1,1).
In total they collect 1 + 1 + 1 + 1 = 4 fruits.
*/
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    struct Child {
            int id;
            int x;
            int y;
            int fruits;
            vector<pair<int, int>> movements;
        };

    void collectFruits(vector<vector<int>>& fruits, Child& child){
        // cout<<"Child "<<child.id<<" pos ("<<child.x<<","<<child.y<<") | Collected: "<<fruits[child.x][child.y]<<" fruits"<<endl;
        child.fruits += fruits[child.x][child.y];
        fruits[child.x][child.y] = 0;
    }

    pair<int, int> findBestMove(vector<vector<int>>& fruits, Child& child){
        int maxFruits = 0;
        pair<int, int> bestMove = {0, 0};
        for (const auto& move : child.movements) {
            int newX = child.x + move.first;
            int newY = child.y + move.second;
            if (
                newX >= 0 && newX < fruits.size() &&
                newY >= 0 && newY < fruits[0].size() && 
                fruits[newX][newY] > maxFruits
            ){
                maxFruits = fruits[newX][newY];
                bestMove = move;
            }
        }
        return bestMove;
    }

    void moveChild(vector<vector<int>>& fruits, Child& child){
        pair<int, int> bestMove = findBestMove(fruits, child);
        child.x += bestMove.first;
        child.y += bestMove.second;
    }

    int maxCollectedFruits(vector<vector<int>>& fruits) {
        int n = fruits.size();
        Child child1 = {1, 0, 0, 0,     {{ 0, 1}, {1, 0}, {1, 1}}};
        Child child2 = {2, 0, n - 1, 0, {{ 1,-1}, {1, 0}, {1, 1}}};
        Child child3 = {3, n - 1, 0, 0, {{-1, 1}, {0, 1}, {1, 1}}};


        while (child1.x != n-1 || child1.y != n-1 
            || child2.x != n-1 || child2.y != n-1 
            || child3.x != n-1 || child3.y != n-1){
            collectFruits(fruits, child1);
            collectFruits(fruits, child2);
            collectFruits(fruits, child3);
            
            moveChild(fruits, child1);
            moveChild(fruits, child2);
            moveChild(fruits, child3);
        }

        return child1.fruits + child2.fruits + child3.fruits + fruits[n-1][n-1];
    }
};

int main() {
    // Input: 2D vector of fruits
    vector<vector<int>> fruits = {
        {1, 2, 3, 4},
        {5, 6, 8, 7},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };

    Solution sol;
    int result = sol.maxCollectedFruits(fruits);

    cout << "Maximum fruits collected: " << result << endl;  // Should print 100

    return 0;
}
