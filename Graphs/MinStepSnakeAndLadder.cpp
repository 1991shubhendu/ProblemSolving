#include <iostream>
#include <queue>
#include <vector>

// We 'll use objects of this structure, to identify a cell 
// and minimum steps required to reach this cell
struct cell_information {
    int cell_number;
    int steps_req_to_reach;
};


void create_snake_positions(std::vector<int>& board_game) {

  
    board_game[26] = 0; 
    board_game[20] = 8; 
    board_game[16] = 3; 
    board_game[18] = 6; 

    //board_game[12] = 2;
    //board_game[14] = 11;
    //board_game[17] = 4;
    //board_game[31] = 19;
    //board_game[35] = 22;

    //board_game[99] = 54;
    //board_game[70] = 55;
    //board_game[52] = 42;
    //board_game[25] = 2;
    //board_game[95] = 72;
}

void create_ladder_positions(std::vector<int>& board_game) {

    board_game[2] = 21; 
    board_game[4] = 7; 
    board_game[10] = 25; 
    board_game[19] = 28; 

   // board_game[3] = 16;
   // board_game[5] = 7;
   // board_game[15] = 25;
   // board_game[18] = 20;
   // board_game[21] = 32;
        
   //  board_game[6] = 25;
   //  board_game[11] = 40;
   //  board_game[60] = 85;
   //  board_game[46] = 90;
   //  board_game[17] = 69;
}

int get_min_steps(const std::vector<int>& board_game) {

    int total_cells = board_game.size();
    //Track whether a cell has been visited or not
    std::vector<bool> is_visited(total_cells, false);
    std::queue<cell_information> cell_queue;
    struct cell_information node = {0,0};
    is_visited[0] = true;
    //Once a node is visited, we push it in queue
    cell_queue.push(node); 

    //Perform Breadth first search
    while (!cell_queue.empty()) {
        node = cell_queue.front();
        int cell_number = node.cell_number;
        //If front node of queue has last cell number, 
        //then we have reached last cell
        if (cell_number == total_cells-1) {
            break;
        }
        //Remove the node from the queue before exploring its neighbours
        cell_queue.pop();
        //A throw of dice results in either among 1, 2, 3, 4, 5, 6
        for (int current = cell_number+1; current <= cell_number+6; \
                ++current) {
            //If the cell was visited before then we already know the minimum
            //steps required to reach it, (as another iteration will just 
            //add 1 more).
            //steps required
            if (!is_visited[current]) {
                struct cell_information current_node;
                //Steps required to reach current node plus(+)
                //one step lands us in current cell 
                current_node.steps_req_to_reach = 1 + node.steps_req_to_reach;
                //In case of snake or ladder, the current cell lands
                //us in the cell that snake or ladder takes us to
                //else we just stay in current cell 
                if (board_game[current] != -1) {
                    current_node.cell_number = board_game[current];
                }
                else {
                    current_node.cell_number = current;
                }
                is_visited[current] = true;
                cell_queue.push(current_node);
            }
        }
    }
    return node.steps_req_to_reach;

}

int main() {

    int total_board_cells = 30;
    std::vector<int> board_game;
    //Initialize every cell with -1 which will be used to identify whether
    //a cell is normal cell, or  has a snake or ladder
    board_game.resize(total_board_cells,-1);
    //Initialize snake positions
    create_snake_positions(board_game);
    //Initialize ladder positions
    create_ladder_positions(board_game);
    int min_steps = get_min_steps(board_game);

    std::cout << "To reach from (cell: 1) to (cell: " << total_board_cells \
        << ") minimum " << min_steps << " steps are required" << std::endl;

    return 0;
}
