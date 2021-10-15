# Overview

## This is a simple program using C++ of a game of sudoku. 
#### I originally took on this challenge to expand my knowledge of other programming languages and to just generally better understand syntax of how other languages function

#### I only really knew Python and Some HTML, but now I'm safe to say that I understand C++ A lot more now that I have made this program for my understanding.

## This Program as Stated Earlier Is Sudoku

#### The game allows you to pick from 6 different difficulties and once your difficulty is chosen, it will generate a randomized sudoku board for you to complete.

#### It will then generate random points on the grid an amount of numbers according to the solution, giving you some numbers to work towards the final answer.

#### You are then given 3 options, insert a number, remove a number, or quit the game.

#### These features allow you to place a number via row/column input and is visualized within the program itself. You select the row and column and type in the number 1 - 9 to insert into the cell that you have selected. Vice-Versa for deleting a number, except no number needs to be specified, only the row and column.

[Software Demo Video](https://www.youtube.com/watch?v=CJSshWjJ0VM)

# Development Environment

* [CodeBlocks](https://www.codeblocks.org/)
* [Visual Studio Code](https://code.visualstudio.com/)
* [C++](https://www.cplusplus.com/)
* [Github Desktop](https://desktop.github.com/)
    * <table styles="display: grid, grid-template-columns: 1fr, 1fr, 1fr">Libraries Used
        <td>iostream</tr>
        <td>algorithm</tr>
        <td>stdlib.h</tr>
        <td>ctime</tr>
        <td>random</tr>
        <td>chrono</tr>
        <td>thread</tr>
        </table>

# Useful Websites

* [C++ Tutorial](https://www.youtube.com/watch?v=vLnPwxZdW4Y)
* [Randomize Via Time Input](https://en.cppreference.com/w/cpp/numeric/random/rand)
* [Randomize Via Seed Generation](https://www.cplusplus.com/reference/algorithm/shuffle/)
* [Sudoku Level Guide](https://www.researchgate.net/figure/Number-of-clues-for-each-difficulty-level_tbl1_259525699)

# Future Work

* Color Coded Numbers (To Visualize Correct and Incorrect placement)
* Difficulty Mode For Having x Amount of Lives
* Making it so that the user cannot remove numbers that were given to them, but can remove numbers that they placed onto the grid.