#include <iostream>
#include <algorithm>
#include <vector>

using std::vector;

enum CELL_TYPE
{
    FLOOR = 0,
    WALL,
    PATH
};

class Node
{
private:
    int x_, y_;     // ノードの座標
    int rCost_;     // 実コスト値
    int hCost_;     // 推定コスト値
    Node* parent_;  // 親ノード

public:
    Node(int x, int y, int rCost, int hCost, Node* parent) : x_(x), y_(y), rCost_(rCost), hCost_(hCost), parent_(parent) {}
    ~Node() {}

    // 合計コストを計算する関数
    int getCost() { return rCost_ + hCost_; }

    // X座標取得
    int getX() { return x_; }

    // Y座標取得
    int getY() { return y_; }

    // ノード取得用
    Node* getParent() { return parent_; }
};

class Astar
{
private:
    // 比較する
    struct CompareNodeCost
    {
        bool operator()(Node* lhs, Node* rhs)
        {
            return lhs->getCost() > rhs->getCost();
        }
    };

    // 移動方向 (上下左右)
    const int dx[4] = { -1, 0, 1, 0 };
    const int dy[4] = { 0, -1, 0, 1 };

public:
    // A*アルゴリズムの実装
    std::vector<std::vector<int>> findShortestPath(std::vector<std::vector<int>>& maze, int startX, int startY, int goalX, int goalY);

    // 結果を表示
    void displayMaze(std::vector<std::vector<int>>& maze);
};