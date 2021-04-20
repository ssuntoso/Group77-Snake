# SNAKE
> COMP2113 Course Project (2020-21)
> 
Group: **77**<br/>
<br/>
Group members<br/>
:panda_face: Rafael Matthew Susanto Kwan - 3035742425<br/>
:llama: Sean Michael Suntoso - 3035742437

## Game Description
A single-player game in which the user inputs an `w` `a` `s` `d` and enter to move a snake which moves constantly forward towards the input direction. The game challenges the user to keep the snake alive by eating a randomized food($) position and not to eat its own body. To make the game dynamic and hard, the snake’s length will increase as it eat food($) and if the snake touches its own body, the snake will die. Highest score will be counted as the snake touches food, this increases the competitiveness of the user while playing the game. At the end of the game, it will tell whether the player beat the highest score or not and show the leaderboard.

## Rules & How To Play
1. Game starts from the center of the board when the player clicks one of the `w` `a` `s` `d` buttons.
2. The snake will move at constant speed and only move up, down, left, and right.
3. Food will appear at a random position everytime the snake touch the position of the food. If players manage to eat it—by passing the snake head on the food during that time frame, the snake will get longer for one square and the player receives 10 points.
4. There is only one food at a time. 
5. If the snake runs to the edge of the box, it will continue to the other side(bottom of the box will continue from the top, left will continue at right, and vice-versa). 
6. Game ends when the snake eats their own body.

## Feature
1. Player will get 10$ when the snake manages to eat one food
2. Menu, Loading screen, Leaderboard, Highest score indication
3. Move up, down, left, and right using `w` `a` `s` `d`
4. Limited playing area (for the boundary of food appearance)
5. Snake’s constant moves if the player does not input anything
6. Randomized food location
7. Food appears randomly after it has been eaten
8. Game over when snake touches its own body or press `q`

## Coding Requirements
| Checklist  | Requirement | Remark |
| :-------------: | ------------- | ------------- |
| ✔️ | Generation of random game sets or events | - `<cstdlib>` to use `rand()` and `srand()` for random food location<br>- `<ctime>` to generate seed for `srand()`<br>- `<iomanip>` to set width<br>- `<string>` for string manipulation<br>- Using switches, if-statements, and loops|
| ✔️ | Data structures for storing game status | - Using `bool`, `int`, `array`, `struct`, and other basic data types<br>- Use 2D arrays or structs for storing data |
| ✔️ | Dynamic memory management | - Use `<vector>` to store a dynamic array of the players in the leaderboard |
| ✔️ | File input/output (e.g., for loading/saving game status) | - For loading(extracting and inserting) high score and leaderboard |
| ✔️ | Program codes in multiple files | - Implement codes header, custom classes(interface and implementation), struct, and functions separated from the main file |
| ✔️ | Proper indentation and naming styles |  |
| ✔️ | In-code documentation |  |

## Remark
use `make all` to compile game in Linux and `make clean` to remove all compiled item.
