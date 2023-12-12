#include <iostream>
#include <algorithm>
#include <vector>

using std::vector;

class Node
{
private:
    int x_, y_;     // �m�[�h�̍��W
    int rCost_;     // ���R�X�g�l
    int hCost_;     // ����R�X�g�l
    Node* parent_;  // �e�m�[�h

public:
    Node(int x, int y, int rCost, int hCost, Node* parent) : x_(x), y_(y), rCost_(rCost), hCost_(hCost), parent_(parent) {}
    ~Node() {}

    // ���v�R�X�g���v�Z����֐�
    int getCost() { return rCost_ + hCost_; }

    // X���W�擾
    int getX() { return x_; }

    // Y���W�擾
    int getY() { return y_; }

    // �m�[�h�擾�p
    Node* getParent() { return parent_; }
};

class Astar
{
private:

    enum CELL_TYPE
    {
        FLOOR = 0,
        WALL,
        PATH
    };

    // ��r����
    struct CompareNodeCost
    {
        bool operator()(Node* lhs, Node* rhs)
        {
            return lhs->getCost() > rhs->getCost();
        }
    };

    // �ړ����� (�㉺���E)
    const int dx[4] = { -1, 0, 1, 0 };
    const int dy[4] = { 0, -1, 0, 1 };

public:
    Astar();
    ~Astar();
    // A*�A���S���Y���̎���
    vector<vector<int>> findShortestPath(vector<vector<int>>& maze, int startX, int startY, int goalX, int goalY);

    // ���ʂ�\��
    void displayMaze(vector<vector<int>>& maze);
};