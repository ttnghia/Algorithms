//------------------------------------------------------------------------------------------
//            .-..-.
//           (-o/\o-)
//          /`""``""`\
//          \ /.__.\ /
//           \ `--` /                                                 Created on: 1/17/2017
//            `)  ('                                                    Author: Nghia Truong
//         ,  /::::\  ,
//         |'.\::::/.'|
//        _|  ';::;'  |_
//       (::)   ||   (::)                       _.
//        "|    ||    |"                      _(:)
//         '.   ||   .'                       /::\
//           '._||_.'                         \::/
//            /::::\                         /:::\
//            \::::/                        _\:::/
//             /::::\_.._  _.._  _.._  _.._/::::\
//             \::::/::::\/::::\/::::\/::::\::::/
//               `""`\::::/\::::/\::::/\::::/`""`
//                    `""`  `""`  `""`  `""`
//------------------------------------------------------------------------------------------

#include "../ProgramParameters.h"

#ifdef __nQueens__

#include "../GlobalParameters.h"

#include <vector>

//------------------------------------------------------------------------------------------
void print_queens(std::vector<int>& queen_positions)
{
    for(size_t i = 0; i < queen_positions.size() - 1; ++i)
    {
        printf("%d, ", queen_positions[i]);
    }
    printf("%d\n", queen_positions.back());
}
//------------------------------------------------------------------------------------------
void find_queen_position(int board_size, std::vector<int>& queen_positions, int row)
{
    if(row >= board_size)
        print_queens(queen_positions);

    for(int col = 0; col < board_size; ++col)
    {
        for(int prev = 0; prev < row; ++prev)
        {
            if(queen_positions[prev] == col ||
               queen_positions[prev] == col - prev + 1 ||
               queen_positions[prev] == col + prev - 1)
                continue;

            queen_positions[row] = col;
            find_queen_position(board_size, queen_positions, row + 1);
        }
    }
}
//------------------------------------------------------------------------------------------
void find_queens(int board_size)
{
    std::vector<int> queen_positions;
    queen_positions.assign(board_size, -1);

    for(int row = 0; row < board_size; ++row)
    {
        find_queen_position(board_size, queen_positions, row);
    }
}

//------------------------------------------------------------------------------------------
TEST_CASE("Tested nQueens")
{
    find_queens(5);
    find_queens(8);
    find_queens(10);
}

//------------------------------------------------------------------------------------------
#endif // __nQueens__                                         