# SnowmanTree
Christmas tree program with snowmans





# Christmas Tree
![Graphical User Interface](https://user-images.githubusercontent.com/69432977/113629073-895bdd00-966e-11eb-98a9-6b995000f436.png)
![Graphical User Interface](https://user-images.githubusercontent.com/69432977/113629059-85c85600-966e-11eb-84a5-6fbbdcaac805.png) 

## Description
First task in C++ with upgrades just for fun.
The program creat a christmas tree that has snowmans under him in ASCII.
You can custom your own snowman with items from the inventory. 

![3](https://user-images.githubusercontent.com/69432977/113629938-c8d6f900-966f-11eb-88a0-9afee84fec10.png)


To do so, you must enter a number in an eight character string (via stdin or command line) in the format HNLRXYTB, where each letter is a digit from 1 to 4 that denotes which preset to use for the corresponding section of the snowman.
H = Hat
N = Nose
L = Left Eye
R = Right Eye
X = Left Arm
Y = Right Arm
T = Torso
B = Base


Template:

HHHHHH
HHHHHH
X(LNR)Y
X(TTT)Y
 (BBB)



## Technologies
- C++:
  - Standard library [iostream, fstream, iomanip]
  - Object-oriented programming
  - [-std=c++11]
## Features
* Decorating the Christmas tree with:
  * star
  * chains
  * glass balls
  * candies
  * lights
* Creating a snowman from the inventory under the tree
* Exporting the card to text file

## Project structure
- tree.h
- tree.cpp
- floor.h
- floor.cpp
- main.cpp
## How to run?
- In Linux open the terminal and enter
  ```sh
  make
  ./christmas-tree
  ```
