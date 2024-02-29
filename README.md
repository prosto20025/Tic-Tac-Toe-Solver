# Tic-Tac-Toe-Solver
Tic-Tac-Toe game solver using the Min-Max algorithm

## Commands
### `SOLVE_GAME_STATE N M K ActivePLayer Board` - Checks if it is possible to win the game for some player and displays which player can win.
  where:
    N - Number of rows,
    M - Number of columns,
    K - Defines how many marks player needs to win,
    ActivePlayer - Whose turn is it now,
    Board - Current board game

    Examples:
    
    SOLVE_GAME_STATE 2 2 2 2
    1 0
    0 0

    Program result: FIRST_PLAYER_WINS

    SOLVE_GAME_STATE 2 2 2 2
    2 1
    1 0

    Program result: FIRST_PLAYER_WINS

    SOLVE_GAME_STATE 4 4 4 1
    1 0 0 2
    1 0 2 0
    1 0 2 0
    0 0 0 0

    Program result: FIRST_PLAYER_WINS

### `GEN_ALL_POS_MOV N M K ActivePLayer` - Displass number and all move possibilites.


    Examples:

    GEN_ALL_POS_MOV 2 2 2 1
    0 1
    0 2

    Program result:
    2 //Number of move possiblities

    1 1 //First possibility
    0 2

    0 1 //Second possibility
    1 2


### 'GEN_ALL_POS_MOV_CUT_IF_GAME_OVER N M K ActivePlayer` - Displays a move that will end the game

    Examples:

    GEN_ALL_POS_MOV_CUT_IF_GAME_OVER 3 3 3 1
    1 0 0
    2 1 0
    2 0 0

    Program result:
    1 
    
    1 0 0
    2 1 0
    2 0 1



### Launch info

### `git clone https://github.com/prosto20025/Tic-Tac-Toe-Solver.git`
After download open the NMKSolver.sln in Visual Studio and run the program.


