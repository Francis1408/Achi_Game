# Achi

This project has the goal of developing a game using the framework [Qt](https://qt.io/developers). The chosen to be built was [Achi](https://en.wikipedia.org/wiki/Achi_(game))

### Gameplay

The game begins with a blank board with 9 holes, just like it is pictured below:

![alt text](https://github.com/Francis1408/Achi_Game/tree/main/img/Begin.png)


In the first phase, two players take turns to place 3 pieces of their color in the blank spaces on the board. When all the 6 pieces are placed in positions of their choices, the second phase starts.

![alt text](https://github.com/Francis1408/Achi_Game/tree/main/img/Phase1.png)

In the second phase, te players move freely their pieces to blank adjacent holes. Thus, none of the players are allowed to skip spaces or move to holes that are already occupied to any piece. 

![alt text](https://github.com/Francis1408/Achi_Game/tree/main/img/Phase2_1.png)
![alt text](https://github.com/Francis1408/Achi_Game/tree/main/img/Phase2_2.png)

Whenever a player makes a straight line (Horizontally, Vertically or Diagonally) with his 3 pieces, the game ends he is the winner.

![alt text](https://github.com/Francis1408/Achi_Game/tree/main/img/End.png)

### How to run

Go to the [Qt_builder](https://github.com/Francis1408/Achi_Game/tree/main/Qt_builder) folder and simply run the executable file:

```
$ ./Achi
```