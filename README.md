# SNAKE
> COMP2113 Course Project (2020-21)
> 
Group: **77**<br/>
<br/>
Group members<br/>
:panda_face: Rafael Matthew Susanto Kwan - 3035742425<br/>
:llama: Sean Michael Suntoso - 3035742437

## Game Description
A single-player game in which the user inputs an arrow key to move a snake which moves constantly forward towards the input direction. The game challenges the user to keep the snake alive by touching a randomized food position since there is a countdown which can change the food position randomly. To make the game dynamic and hard, the snake’s length will increase as it touches food and if the snake touches its own body, the snake will die. Highest score will be counted as the snake touches food, this increases the competitiveness of the user while playing the game.

## Rules & How To Play
1. Game starts from the center of the board when the player clicks one of the arrow buttons.
2. The snake will move at constant speed and only move up, down, left, and right.
3. Food will appear at a random location for 30 seconds. If players manage to eat it—by passing the snake head on the food during that time frame, the snake will get longer for one square and the player receives 1 point. Otherwise, food will move to different locations.
4. There is only one food at a time. 
5. If the snake runs to the edge of the box, it will continue to the other side(bottom of the box will continue from the top, left will continue at right, and vice-versa). 
6. Game ends when the snake eats their own body.

## Feature
1. Score 1 point when the snake manages to eat one food
2. Leaderboard
3. Move up, down, left, and right using arrow
4. Limited playing area (For the boundary of food appearance)
5. Snake’s constant moves
6. Randomized food location (will change location when not get eaten in 30 seconds)
7. Food appears randomly after it has been eaten
8. Game over when snake touches its own body

## Coding Requirements
| Checklist  | Requirement | Remark |
| :-------------: | ------------- | ------------- |
| ✔️ | Generation of random game sets or events | - `<cstdlib>` to use `rand()` and `srand()` for random food location<br>- `<ctime>` to generate seed for `srand()`<br>- `<iomanip>` to set width<br>- `<string>` for string manipulation<br>- Using switches, if-statements, and loops|
| ✔️ | Data structures for storing game status | - Using `bool`, `int`, `array`, `struct`, and other basic data types<br>- Use 2D arrays or structs for storing data |
| ✔️ | Dynamic memory management | - Use `new` and `delete` operator to store temporary game state array |
| ✔️ | File input/output (e.g., for loading/saving game status) | - For loading(extracting and inserting) high score and leaderboard |
| ✔️ | Program codes in multiple files | - Implement codes header, custom classes(interface and implementation) or functions will be separated from the main file |

## Remark
use `$ g++ -pthread -pedantic-errors -std=c++11 snake.cpp -o snake` to compile game in Linux.
