# SNAKE
> COMP2113 Course Project (2020-21)
> 
Group: **77**<br/>
<br/>
Group members<br/>
:panda_face: Rafael Matthew Susanto Kwan - 3035742425<br/>
:llama: Sean Michael Suntoso - 3035742437

## Game Description
A single-player game in which the user inputs `w` `a` `s` `d` and enter to change the snake movement which moves constantly forward towards the input direction. The game challenges the user to beat the highscore by eating a randomized food ($) position and keep the snake alive by not touching its own tails. To make the game dynamic and hard, the snake’s tails will increase as it eat food ($) and if the snake touches its own tails, the snake will die. Highest score will be counted as the snake touches food, this increases the competitiveness of the user while playing the game. At the end of the game, it will tell whether the player beat the highest score or not and show the leaderboard.

## Quick Start Guide
1. Use `make all` to compile the program.
2. To execute the program use command `./snake`.
3. Follow the on screen instructions.
4. Use `w` `a` `s` `d` then `enter` to move the snake and `q` then `enter` to end the game.
5. After finish, `make clean` command is available to clean all the output file and remove the leaderboard file.
6. Make sure to recompile using `make all` again after clean using `make clean` before repeat step 2.  

## Rules & How To Play
1. Game starts from the center of the board when the player clicks one of the `w` `a` `s` `d` and then `enter` buttons.
2. The snake will move at the constant speed of a character / half a second and only move up, down, left, and right.
3. Food will appear at a random position everytime the snake touch the position of the food. If players manage to eat it—by passing the snake head on the food during that time frame, the snake will get longer for one square and the player receives 10 points.
4. There is only one food at a time. 
5. If the snake runs to the edge of the box, it will continue to the other side(bottom of the box will continue from the top, left will continue at right, and vice-versa). 
6. Game ends when the snake eats their own body.

## Feature
1. Player will get 10$ when the snake manages to eat one food
2. Menu, loading screen, leaderboard which display 10 top players
3. Beat 'the highest score or not' indication
4. Move up, down, left, and right using `w` `a` `s` `d`
5. Limited playing area (for the boundary of food appearance)
6. Snake’s constant moves if the player does not input anything
7. Randomized food location (using time as the seed)
8. Food appears randomly after it has been eaten
9. Game over when snake touches its own body or press `q`

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
| ✔️ | Tested on `academy11` server |  |

## References
Nvitanovic. <i>Simple Snake Game Part 1</i>. https://youtu.be/E_-lMZDi7Uw<br>
Nvitanovic. <i>Simple Snake Game Part 2</i>. https://youtu.be/W1e5wO7XR2w<br>
Nvitanovic. <i>Simple Snake Game Part 3</i>. https://youtu.be/PSoLD9mVXTA<br>
