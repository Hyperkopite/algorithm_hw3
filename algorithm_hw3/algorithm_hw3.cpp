#include <iostream>
using namespace std;

#define NUM 12
#define MAX_PATH 100

struct Node
{
	int key;
	int flag;
	Node()
	{
		flag = 0;
	}
};

class Graph
{
	public:
		int resultPath[MAX_PATH][NUM];
		int result[NUM + 1];
		int value[NUM + 1];
		int k;

		Node headNode;
		Node endNode;
		int pathNum;
		int nPos;
		bool Mark[NUM];

	public:
		Graph(int kk)
		{
			for (int i = 0; i < NUM; i++)
			{
				for (int j = 0; j < MAX_PATH; j++)
				{
					resultPath[j][i] = 0;
				}
				result[i] = 0;

				Mark[i] = false;
			}
			result[NUM] = 0;
			pathNum = 0;
			nPos = 0;
			value[1] = 7;
			value[2] = 5;
			value[3] = 5;
			value[4] = 13;
			value[5] = 3;
			value[6] = 8;
			value[7] = 9;
			value[8] = 8;
			value[9] = 6;
			value[10] = 12;
			value[11] = 10;
			value[12] = 8;
			k = kk;
		}

		void test()
		{
			int Matrix[NUM][NUM] = {
				{0,1,0,0,1,0,0,0,0,0,0,0},
				{1,0,1,0,0,1,0,0,0,0,0,0},
				{0,1,0,1,0,0,1,0,0,0,0,0},
				{0,0,1,0,0,0,0,1,0,0,0,0},
				{1,0,0,0,0,1,0,0,1,0,0,0},
				{0,1,0,0,1,0,1,0,0,1,0,0},
				{0,0,1,0,0,1,0,1,0,0,1,0},
				{0,0,0,1,0,0,1,0,0,0,0,1},
				{0,0,0,0,1,0,0,0,0,1,0,0},
				{0,0,0,0,0,1,0,0,0,0,1,0},
				{0,0,0,0,0,0,1,0,0,1,0,1},
				{0,0,0,0,0,0,0,1,0,0,1,0}
			};
			headNode.key = 1;
			endNode.key = 12;
			headNode.flag = 1;

			FindAllPath(Matrix, headNode, endNode);
			//cout << "Number of routes：" << pathNum << endl;
			for (int i = 0; i < pathNum; i++)
			{
				int sum = 0;
				//cout << "Route " << i << ": ";
				//for (int j = 0; j < NUM; j++)
				//{
				//	if (resultPath[i][j] == 0)
				//	{
				//		break;
				//	}
				//	j == NUM - 1 || resultPath[i][j+1] == 0 ? cout << resultPath[i][j] << endl : cout << resultPath[i][j] << "->";
				//}
				//cout << endl;
				for (int j = 0; j < NUM; j++)
				{
					if (resultPath[i][j] == 0)
					{
						break;
					}
					sum += value[resultPath[i][j]];
				}
				//cout << sum << endl;
				if (sum == k)
				{
					for (int j = 0; j < NUM; j++)
					{
						if (resultPath[i][j] == 0)
						{
							break;
						}
						j == NUM - 1 || resultPath[i][j + 1] == 0 ? cout << value[resultPath[i][j]] << endl : cout << value[resultPath[i][j]] << "->";
					}
				}
			}
		}

		void FindAllPath(int Matrix[NUM][NUM], Node startNodeKey, Node endNodeKey)
		{
			result[nPos] = startNodeKey.key;
			Mark[startNodeKey.key - 1] = true;
			nPos++;
			while (nPos != 0)
			{
				int tempVal = result[nPos - 1];  
				if (tempVal == endNodeKey.key)
				{
					for (int j = 0; j < nPos; j++)
					{
						resultPath[pathNum][j] = result[j];
					}
					nPos--;
					result[nPos] = 0;
					pathNum++;
					Mark[endNodeKey.key - 1] = false;
					break;
				}
				while (startNodeKey.flag < NUM)  
				{
					if (Matrix[tempVal - 1][startNodeKey.flag] == 1)
					{
						if (Mark[startNodeKey.flag] == false)
						{
							Node tempNode;
							tempNode.key = startNodeKey.flag + 1;
							FindAllPath(Matrix, tempNode, endNodeKey); 
						}
					}
					startNodeKey.flag++;
				}

				if (startNodeKey.flag == NUM)  
				{
					nPos--;
					startNodeKey.flag = 0;
					result[nPos] = 0;
					Mark[startNodeKey.key - 1] = false;
					break;
				}
			}
		}
};

int main()
{
	int k;
	cout << "k: ";
	cin >> k;
	Graph g(k);
	g.test();

	return 0;
}