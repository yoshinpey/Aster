#include "Astar.h"

// ���C���֐�
int main()
{
    // ���H���` (0: �ʘH, 1: ��Q��)
    int mazeWidth_ = 0;
    int mazeHeight_ = 0;
    vector<vector<int>> maze;       // ���H�f�[�^
    vector<vector<int>> result;     // �����������H

    // �J�n�n�_�ƃS�[���n�_�̍��W���`
    //getter����


    // �ŒZ�o�H�������Č��ʂ��擾
    Astar* pAstar = new Astar();
    result = pAstar->findShortestPath(maze, startX, startY, goalX, goalY);

    // ���ʂ�\��
    pAstar->displayMaze(result);

    delete pAstar;
    return 0;
}