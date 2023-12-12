#pragma once
#include <vector>
using std::vector;

class MazeGenerator
{
private:
    enum CELL_TYPE
    {
        FLOOR = 0,
        WALL,
        PATH
    };
    enum RANDOM_DIRECTION
    {
        LEFT = 0,
        DOWN,
        RIGHT,
        UP,
        MAX
    };

    int mazeWidth_;                 // 幅
    int mazeHeight_;                // 高さ
    vector<vector<int>> mazeData_;  // ステージ

public:
    MazeGenerator(vector<vector<int>>& mazeData, int mazeW, int mazeH);
    ~MazeGenerator();

    void Initialize();
    void RodKnockDownAlgorithm();
    vector<vector<int>> Generate();
};

