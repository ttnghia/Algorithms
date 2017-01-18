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
void find_queen_position(int board_size, std::vector<int>& queen_positions, int row)
{
    if(row >= board_size)
    {
        DataWriter::print_vector<int>(queen_positions);
        return;
    }

    for(int col = 0; col < board_size; ++col)
    {
        int valid = true;
        for(int prev_row = 0; prev_row < row; ++prev_row)
        {
            if(queen_positions[prev_row] == col ||
               queen_positions[prev_row] == col - (row - prev_row) ||
               queen_positions[prev_row] == col + (row - prev_row))
            {
                valid = false;
                break;
            }

        }

        if(valid)
        {
            queen_positions[row] = col;
            find_queen_position(board_size, queen_positions, row + 1);
        }
    }
}
//------------------------------------------------------------------------------------------
void find_queens(int board_size)
{
    std::vector<int> queen_positions;
    queen_positions.assign(board_size, -1000);

    find_queen_position(board_size, queen_positions, 0);
}

//------------------------------------------------------------------------------------------
TEST_CASE("Tested nQueens")
{
    find_queens(8);
}

//------------------------------------------------------------------------------------------
#endif // __nQueens__                                         