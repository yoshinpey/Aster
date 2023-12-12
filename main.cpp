#include "Astar.h"
#include "MazeGenerator.h"

// メイン関数
int main()
{
    srand(static_cast<unsigned int>(time(nullptr)));
    // デフォルトの迷路を定義
    int mazeWidth_ = 15;     // 行数
    int mazeHeight_ = 15;    // 列数
    int cellType_ = 0;      // 構成値(0:床, 1:壁)
    enum CELL_TYPE
    {
        FLOOR = 0,
        WALL,
        PATH
    };

    // 迷路のスタートとゴール地点
    int startX = 0;
    int startY = 1;
    int goalX = mazeWidth_ - 1;
    int goalY = mazeHeight_ - 2;

    vector<vector<int>> mazeData;   // 初期の迷路データ
    vector<vector<int>> result;     // 最短経路を含む完成形の迷路データ

    // 初期の迷路データを指定されたサイズで初期化しておく
    mazeData.assign(mazeWidth_, vector<int>(mazeHeight_, cellType_));

    // コンストラクタに迷路情報を渡す
    MazeGenerator* pMazeGenerator = new MazeGenerator(mazeData, mazeWidth_, mazeHeight_);

    // 変更した迷路データを受け取る
    mazeData = pMazeGenerator->Generate();

    // 経路探索のインスタンスを作成
    Astar* pAstar = new Astar();
    result = pAstar->findShortestPath(mazeData, startX, startY, goalX, goalY);

    // 結果を表示
    pAstar->displayMaze(result);

    delete pMazeGenerator;
    delete pAstar;

    return 0;
}