#include "Astar.h"

Astar::Astar()
{
}

Astar::~Astar()
{
}

// A*�A���S���Y���̎���
vector<vector<int>> Astar::findShortestPath(vector<vector<int>>& maze, int startX, int startY, int goalX, int goalY)
{
    // ������
    vector<vector<int>> result(maze);
    vector<vector<bool>> visited(maze.size(), vector<bool>(maze[0].size(), false));
    vector<Node*> openSet;

    Node* startNode = new Node(startX, startY, 0, 0, nullptr);
    openSet.push_back(startNode);

    while (!openSet.empty())
    {
        // �I�[�v���Z�b�g����ŏ��R�X�g�̃m�[�h���擾
        auto minIt = std::min_element(openSet.begin(), openSet.end(), CompareNodeCost());
        Node* current = *minIt;
        openSet.erase(minIt);

        // �S�[���ɓ��B������o�H��Ԃ��ďI��
        if (current->getX() == goalX && current->getY() == goalY)
        {
            while (current != nullptr)
            {
                result[current->getX()][current->getY()] = 2; // �ŒZ�o�H�̈������
                Node* temp = current;
                current = current->getParent();
                delete temp;
            }
            // openSet�Ɏc���Ă���m�[�h�����
            for (auto node : openSet)
            {
                delete node;
            }
            return result;
        }

        // ���łɖK�ꂽ�m�[�h�̓X�L�b�v
        if (visited[current->getX()][current->getY()])
        {
            continue;
        }

        visited[current->getX()][current->getY()] = true;

        // �אڂ���m�[�h�𒲍�
        for (int i = 0; i < 4; ++i)
        {
            int nx = current->getX() + dx[i];
            int ny = current->getY() + dy[i];

            // ���H�͈͓̔����ʍs�\�ȏꍇ
            if (nx >= 0 && nx < maze.size() && ny >= 0 && ny < maze[0].size() && maze[nx][ny] == CELL_TYPE::FLOOR)
            {
                int newRCost = current->getCost() + 1;
                int newHCost = std::abs(nx - goalX) + std::abs(ny - goalY);

                Node* neighbor = new Node(nx, ny, newRCost, newHCost, current);

                openSet.push_back(neighbor);

                // �m�[�h���R�X�g�Ń\�[�g
                std::sort(openSet.begin(), openSet.end(), CompareNodeCost());
            }
        }
    }

    // �S�[���ɓ��B�ł��Ȃ��ꍇ
    // openSet�Ɏc���Ă���m�[�h�����
    for (auto node : openSet)
    {
        delete node;
    }
    return result; // �S�ẴZ����0�ŏ���������Ă���
}


// ���ʂ�\��
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
                std::cout << "��";
            }
            else if (cell == CELL_TYPE::PATH)
            {
                std::cout << "��";
            }
        }
        std::cout << std::endl;
    }
}
