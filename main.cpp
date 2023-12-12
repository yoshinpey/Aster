#include "Astar.h"
#include "MazeGenerator.h"

// ���C���֐�
int main()
{
    srand(static_cast<unsigned int>(time(nullptr)));
    // �f�t�H���g�̖��H���`
    int mazeWidth_ = 15;     // �s��
    int mazeHeight_ = 15;    // ��
    int cellType_ = 0;      // �\���l(0:��, 1:��)
    enum CELL_TYPE
    {
        FLOOR = 0,
        WALL,
        PATH
    };

    // ���H�̃X�^�[�g�ƃS�[���n�_
    int startX = 0;
    int startY = 1;
    int goalX = mazeWidth_ - 1;
    int goalY = mazeHeight_ - 2;

    vector<vector<int>> mazeData;   // �����̖��H�f�[�^
    vector<vector<int>> result;     // �ŒZ�o�H���܂ފ����`�̖��H�f�[�^

    // �����̖��H�f�[�^���w�肳�ꂽ�T�C�Y�ŏ��������Ă���
    mazeData.assign(mazeWidth_, vector<int>(mazeHeight_, cellType_));

    // �R���X�g���N�^�ɖ��H����n��
    MazeGenerator* pMazeGenerator = new MazeGenerator(mazeData, mazeWidth_, mazeHeight_);

    // �ύX�������H�f�[�^���󂯎��
    mazeData = pMazeGenerator->Generate();

    // �o�H�T���̃C���X�^���X���쐬
    Astar* pAstar = new Astar();
    result = pAstar->findShortestPath(mazeData, startX, startY, goalX, goalY);

    // ���ʂ�\��
    pAstar->displayMaze(result);

    delete pMazeGenerator;
    delete pAstar;

    return 0;
}