//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
//
//  Copyright (c) 2017 by
//       __      _     _         _____
//    /\ \ \__ _| |__ (_) __ _  /__   \_ __ _   _  ___  _ __   __ _
//   /  \/ / _` | '_ \| |/ _` |   / /\/ '__| | | |/ _ \| '_ \ / _` |
//  / /\  / (_| | | | | | (_| |  / /  | |  | |_| | (_) | | | | (_| |
//  \_\ \/ \__, |_| |_|_|\__,_|  \/   |_|   \__,_|\___/|_| |_|\__, |
//         |___/                                              |___/
//
//  <nghiatruong.vn@gmail.com>
//  All rights reserved.
//
//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+

#include <Common.h>
#include <queue>
#include <stack>

#define M 10
#define N 10

//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
bool canMove(int landMap[M][N], int visitedMap[M][N], int x, int y)
{
    return (x >= 0 && y >= 0 &&
            x < M && y < N &&
            landMap[x][y] && !visitedMap[x][y]);
}

void travelIsland_BFS(int landMap[M][N], int visitedMap[M][N], int i, int j, int island)
{
    std::queue<std::pair<int, int> > theQueue;
    theQueue.push(std::make_pair(i, j));

    while(!theQueue.empty())
    {
        int x = theQueue.front().first;
        int y = theQueue.front().second;
        theQueue.pop();

        for(int l1 = -1; l1 <= 1; ++l1)
        {
            for(int l2 = -1; l2 <= 1; ++l2)
            {
                int newX = x + l1;
                int newY = y + l2;
                if(canMove(landMap, visitedMap, newX, newY))
                {
                    visitedMap[newX][newY] = island;
                    theQueue.push(std::make_pair(newX, newY));
                }
            }
        }
    }
}

void travelIsland_DFS(int landMap[M][N], int visitedMap[M][N], int i, int j, int island)
{
    std::stack<std::pair<int, int> > theStack;
    theStack.push(std::make_pair(i, j));

    while(!theStack.empty())
    {
        int x = theStack.top().first;
        int y = theStack.top().second;

        bool moved = false;
        for(int l1 = -1; l1 <= 1; ++l1)
        {
            for(int l2 = -1; l2 <= 1; ++l2)
            {
                int newX = x + l1;
                int newY = y + l2;
                if(canMove(landMap, visitedMap, newX, newY))
                {
                    visitedMap[newX][newY] = island;
                    theStack.push(std::make_pair(newX, newY));
                    moved = true;
                }
            }
        }

        if(!moved)
            theStack.pop();
    }
}

//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
TEST_CASE("Test 1")
{
    int landMap[M][N] =
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

    // stores if cell is visitedMap or not
    int visitedMap[M][N];

    memset(visitedMap, 0, sizeof(visitedMap));

    int numIsland = 0;
    for(int i = 0; i < M; ++i)
    {
        for(int j = 0; j < N; ++j)
        {
            if(landMap[i][j] && !visitedMap[i][j])
            {
                ++numIsland;
                travelIsland_BFS(landMap, visitedMap, i, j, numIsland);
            }
        }
    }

    printf("Breath first travel\n");
    for(int i = 0; i < M; ++i)
    {
        for(int j = 0; j < N; ++j)
        {
            printf("%d, ", visitedMap[i][j]);
        }
        printf("\n");
    }

    printf("\n");
    printf("Num island: %d\n\n\n", numIsland);

    REQUIRE(numIsland == 5);
}

//-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
TEST_CASE("Test 2")
{
    int landMap[M][N] =
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

    // stores if cell is visitedMap or not
    int visitedMap[M][N];

    memset(visitedMap, 0, sizeof(visitedMap));

    int numIsland = 0;
    for(int i = 0; i < M; ++i)
    {
        for(int j = 0; j < N; ++j)
        {
            if(landMap[i][j] && !visitedMap[i][j])
            {
                ++numIsland;
                travelIsland_DFS(landMap, visitedMap, i, j, numIsland);
            }
        }
    }

    printf("Depth first travel\n");
    for(int i = 0; i < M; ++i)
    {
        for(int j = 0; j < N; ++j)
        {
            printf("%d, ", visitedMap[i][j]);
        }
        printf("\n");
    }

    printf("\n");
    printf("Num island: %d\n\n\n", numIsland);

    REQUIRE(numIsland == 5);
}
