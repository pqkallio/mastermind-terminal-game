# Mastermind - Terminal version

A terminal version of the game [Mastermind](https://en.wikipedia.org/wiki/Mastermind_(board_game)).

## Installation

1. Install dependency [ncurses](https://invisible-island.net/ncurses/) (e.g. `sudo apt install lib64ncurses5-dev` for Debian/Ubuntu Linux).
1. Run `make` in the source folder.

## Playing the game

Run the executable (e.g. `./mastermind` in Linux).

You have 12 tries to guess the secret 4-piece color combination. There are eight different colors and none of them can appear more than once in the secret pattern.

Use arrow keys to for selection:
- &#8593; and &#8595; to select the color
- &#8592; and &#8594; to select between the different pieces

After all the colors in a row have been chosen, hit `RETURN` key to see the result:
- A **red** marker means you have the right color in the right position
- A **white** marker means you have the right color in the wrong place

**Have fun!**
