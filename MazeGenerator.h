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

    int mazeWidth_;                 // ��
    int mazeHeight_;                // ����
    vector<vector<int>> mazeData_;  // �X�e�[�W

public:
    MazeGenerator(vector<vector<int>>& mazeData, int mazeW, int mazeH);
    ~MazeGenerator();

    void Initialize();
    void RodKnockDownAlgorithm();
    vector<vector<int>> Generate();
};

