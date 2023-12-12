#include "Astar.h"

// メイン関数
int main()
{
    // 迷路を定義 (0: 通路, 1: 障害物)
    int mazeWidth_ = 0;
    int mazeHeight_ = 0;
    vector<vector<int>> maze;       // 迷路データ
    vector<vector<int>> result;     // 完成した迷路

    // 開始地点とゴール地点の座標を定義
    //getterつかう


    // 最短経路を見つけて結果を取得
    Astar* pAstar = new Astar();
    result = pAstar->findShortestPath(maze, startX, startY, goalX, goalY);

    // 結果を表示
    pAstar->displayMaze(result);

    delete pAstar;
    return 0;
}