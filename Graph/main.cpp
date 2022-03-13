#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

// M x N matrix
#define M 10
#define N 10

// Below arrays details all 8 possible movements from a cell
// (top, right, bottom, left and 4 diagonal moves)
int row[] = { -1, -1, -1, 0, 1, 0, 1, 1 };
int col[] = { -1, 1, 0, -1, -1, 1, 0, 1 };

// Function to check if it is safe to go to position (x, y)
// from current position. The function returns false if (x, y)
// is not valid matrix coordinates or (x, y) represents water or
// position (x, y) is already processed
bool isSafe(int mat[M][N], int x, int y, bool processed[M][N])
{
	return (x >= 0) && (x < M) && (y >= 0) && (y < N) &&
		(mat[x][y] && !processed[x][y]);
}

void BFS(int mat[M][N], bool processed[M][N], int i, int j)
{
	// create an empty queue and enqueue source node
	queue<pair<int, int>> q;
	q.push(make_pair(i, j));

	// mark source node as processed
	processed[i][j] = true;

	// run till queue is empty
	while (!q.empty())
	{
		// pop front node from queue and process it
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		// check for all 8 possible movements from current cell
		// and enqueue each valid movement
		for (int k = 0; k < 8; k++)
		{
			// skip if location is invalid or it is already
			// processed or consists of water
			if (isSafe(mat, x + row[k], y + col[k], processed))
			{
				// mark it processed & push it into the queue
				processed[x + row[k]][y + col[k]] = 1;
				q.push(make_pair(x + row[k], y + col[k]));
			}
		}
	}
}

int main()
{
	int mat[M][N]=
	{
		{ 1, 0, 1, 0, 0, 0, 1, 1, 1, 1 },
		{ 0, 0, 1, 0, 1, 0, 1, 0, 0, 0 },
		{ 1, 1, 1, 1, 0, 0, 1, 0, 0, 0 },
		{ 1, 0, 0, 1, 0, 1, 0, 0, 0, 0 },
		{ 1, 1, 1, 1, 0, 0, 0, 1, 1, 1 },
		{ 0, 1, 0, 1, 0, 0, 1, 1, 1, 1 },
		{ 0, 0, 0, 0, 0, 1, 1, 1, 0, 0 },
		{ 0, 0, 0, 1, 0, 0, 1, 1, 1, 0 },
		{ 1, 0, 1, 0, 1, 0, 0, 1, 0, 0 },
		{ 1, 1, 1, 1, 0, 0, 0, 1, 1, 1 }
	};

	// stores if cell is processed or not
	bool processed[M][N];

	// mark all cells as unprocessed
	memset(processed, 0, sizeof(processed));

	int island = 0;
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			// start BFS from each unprocessed node and
			// increment island count
			if (mat[i][j] && processed[i][j] == 0)
			{
				BFS(mat, processed, i, j);
				island++;
			}
		}
	}

	cout << "Number of islands are " << island << '\n';

	return 0;
}