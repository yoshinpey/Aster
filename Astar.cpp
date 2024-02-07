#include "Astar.h"

Astar::Astar()
{
}

Astar::~Astar()
{
}

// A*アルゴリズムの実装
vector<vector<int>> Astar::findShortestPath(vector<vector<int>>& maze, int startX, int startY, int goalX, int goalY)
{
    // 初期化
    vector<vector<int>> result(maze);
    vector<vector<bool>> visited(maze.size(), vector<bool>(maze[0].size(), false));
    vector<Node*> openSet;

    Node* startNode = new Node(startX, startY, 0, 0, nullptr);
    openSet.push_back(startNode);

    while (!openSet.empty())
    {
        // オープンセットから最小コストのノードを取得
        auto minIt = std::min_element(openSet.begin(), openSet.end(), CompareNodeCost());
        Node* current = *minIt;
        openSet.erase(minIt);

        // ゴールに到達したら経路を返して終了
        if (current->getX() == goalX && current->getY() == goalY)
        {
            while (current != nullptr)
            {
                result[current->getX()][current->getY()] = 2; // 最短経路の印をつける
                Node* temp = current;
                current = current->getParent();
                delete temp;
            }
            // openSetに残っているノードも解放
            for (auto node : openSet)
            {
                delete node;
            }
            return result;
        }

        // すでに訪れたノードはスキップ
        if (visited[current->getX()][current->getY()])
        {
            continue;
        }

        visited[current->getX()][current->getY()] = true;

        // 隣接するノードを調査
        for (int i = 0; i < 4; ++i)
        {
            int nx = current->getX() + dx[i];
            int ny = current->getY() + dy[i];

            // 迷路の範囲内かつ通行可能な場合
            if (nx >= 0 && nx < maze.size() && ny >= 0 && ny < maze[0].size() && maze[nx][ny] == CELL_TYPE::FLOOR)
            {
                int newRCost = current->getCost() + 1;
                int newHCost = std::abs(nx - goalX) + std::abs(ny - goalY);

                Node* neighbor = new Node(nx, ny, newRCost, newHCost, current);

                openSet.push_back(neighbor);

                // ノードをコストでソート
                std::sort(openSet.begin(), openSet.end(), CompareNodeCost());
            }
        }
    }

    // ゴールに到達できない場合
    // openSetに残っているノードを解放
    for (auto node : openSet)
    {
        delete node;
    }
    return result; // 全てのセルが0で初期化されている
}


// 結果を表示
void Astar::displayMaze(vector<vector<int>>& maze)
{
    for (auto& row : maze)
    {
        for (int cell : row)
        {
            if (cell == CELL_TYPE::FLOOR)
            {
                std::cout << "  ";
            }
            else if (cell == CELL_TYPE::WALL)
            {
                std::cout << "■";
            }
            else if (cell == CELL_TYPE::PATH)
            {
                std::cout << "☆";
            }
        }
        std::cout << std::endl;
    }
}
