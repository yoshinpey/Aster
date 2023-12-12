#include "MazeGenerator.h"

MazeGenerator::MazeGenerator(vector<vector<int>>& mazeData, int mazeW, int mazeH)
	:mazeData_(mazeData), mazeWidth_(mazeW), mazeHeight_(mazeH)
{
}

MazeGenerator::~MazeGenerator()
{
}

void MazeGenerator::Initialize()
{
    //外壁の生成
    // 上と下(X軸の最初と最後)を壁にする
    for (int i = 0; i < mazeWidth_; i++)
    {
        mazeData_[0][i] = CELL_TYPE::WALL;
        mazeData_[mazeHeight_ - 1][i] = CELL_TYPE::WALL;
    }
    // 右と左(Y軸の最初と最後)を壁にする
    for (int j = 0; j < mazeHeight_; j++)
    {
        mazeData_[j][0] = CELL_TYPE::WALL;
        mazeData_[j][mazeWidth_ - 1] = CELL_TYPE::WALL;
    }

    // スタート地点とゴール地点を床にする
    mazeData_[0][1]= CELL_TYPE::FLOOR;
    mazeData_[mazeHeight_ - 1][mazeWidth_ - 2] = CELL_TYPE::FLOOR;

    // 壁を立てる
    for (int y = 2; y < mazeHeight_ - 1; y += 2)
    {
        for (int x = 2; x < mazeWidth_ - 1; x += 2)
        {
            mazeData_[y][x]= CELL_TYPE::WALL;
        }
    }
}

void MazeGenerator::RodKnockDownAlgorithm()
{

    for (int y = 2; y < mazeHeight_ - 1; y += 2)
    {
        for (int x = 2; x < mazeWidth_ - 1; x += 2)
        {
            while (true)
            {
                int dir = 0;

                if (y == 2)
                    dir = rand() % RANDOM_DIRECTION::MAX;
                else
                    dir = rand() % RANDOM_DIRECTION::MAX - 1;

                int xx = x;
                int yy = y;

                switch (dir)
                {
                case RANDOM_DIRECTION::LEFT:
                    xx++;
                    break;
                case RANDOM_DIRECTION::DOWN:
                    yy++;
                    break;
                case RANDOM_DIRECTION::RIGHT:
                    xx--;
                    break;
                case RANDOM_DIRECTION::UP:
                    yy--;
                    break;
                default:
                    break;
                }

                if (mazeData_[yy][xx] != CELL_TYPE::WALL)
                {
                    mazeData_[yy][xx] = CELL_TYPE::WALL;
                    break;
                }
            }
        }
    }
}

vector<vector<int>> MazeGenerator::Generate()
{
    Initialize();
    RodKnockDownAlgorithm();
    return mazeData_;
}