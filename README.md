# cub3D

Cub3D is a 42 school team project to create a dynamic view inside a 3D maze. Using the [MiniLibX library](https://github.com/42Paris/minilibx-linux), we must implement raycasting in the style of the famous [Wolfenstein 3D](http://users.atw.hu/wolf3d/) game, the first true FPS in videogame history.

## Compile and Run

There are two versions of the program, the mandatory part and the bonus part. The bonus part adds wall collision, a minimap, and the ability to rotate the view by moving the mouse.
Furthermore, we made the bonus part out to be a FPS game. It is pretty fun to play !

To compile the mandatory part, `cd` into the cloned directory and:

```shell
make
```

To compile the bonus part, `cd` into the cloned directory and:

```shell
make bonus
```


To run the basic program:

```shell
./cub3D <path/to/map.cub>
```

To run the bonus part (the game), don't use any arg:
```shell
./cub3D_bonus
```

The program takes a map file as an argument. Maps are available in the `maps` directory. There are good maps which the program should run smoothly with, and bad maps which the program should reject.
For example:

- `./cub3d maps/big_map.cub` should run.

- `./cub3d maps/bad/filetype_wrong.buc` should print an error and abort.

## Controls

Controls for movement and rotation are:

- `W`: move forward
- `S`: move backward
- `A`: strafe left
- `D`: strafe right
- `left arrow`: rotate left
- `right arrow`: rotate right
- `mouse`: rotate by moving the mouse (bonus only)
- `H`: displays a help menu with all available commands (bonus only)
- `ESC`: pause/exit the game
- `Space`: attack
- `1` and `2`: switch weapons (sword and shotgun)
- Many others (see help menu ingame)

## Gameplay

When launching the bonus part, you will have three difficulties available.
You will always start at level 1.
Every level spawns you on a map that will contain ennemies for you to kill.

Every 4 seconds, ennemis will spawn other ennemies nearby themselves. Soon, they will be everywhere on the map! And if they do, you lose.

You go to the next level by killing every ennemy on the map.

Be carefull, some levels can be quite challenging.. But wounded ennemies have different states, maybe some of them could come in handy ? ..


## Game screeshots

At launch:
![image](https://github.com/willrsq1/cub3d/assets/117649637/b9486d67-831c-4a0c-9d09-ec7961efa1d1)
![image](https://github.com/willrsq1/cub3d/assets/117649637/7a0ee485-3f9c-4dc3-af9c-dde976419012)

First level:
![image](https://github.com/willrsq1/cub3d/assets/117649637/c1515ecb-687e-40ae-b0c8-cfba8d469af8)

Second level:
![image](https://github.com/willrsq1/cub3d/assets/117649637/360ef754-69a1-4553-aef5-6b6a38d81f0a)

Third level:
![image](https://github.com/willrsq1/cub3d/assets/117649637/e903a5a4-5f2e-43f2-ba1c-d958d69b8582)

Help and escape menus:
![image](https://github.com/willrsq1/cub3d/assets/117649637/82ad5696-5f36-4009-ab97-f860074635e2)
![image](https://github.com/willrsq1/cub3d/assets/117649637/af014e18-f5d3-4866-80e3-ba2b98d70646)

Wounded ennemies:
![image](https://github.com/willrsq1/cub3d/assets/117649637/c0a9c1af-9819-4e31-b863-e116be461288)

Final level:
![image](https://github.com/willrsq1/cub3d/assets/117649637/91f0e175-aebf-4ced-b7fb-50e8f0a49ab9)

Have fun ! :)



# 💪 Contributers
[ABDYLI Arbesa](https://github.com/aarbesa)<br/>
&emsp;42intra profile : [aabdyli](https://profile.intra.42.fr/users/aabdyli) <br/>
<br/>
[RUET SUQUET William](https://github.com/willrsq1)
<br/>
&emsp;42intra profile : [wruet-su](https://profile.intra.42.fr/users/wruet-su)
<br/>

# Peer review
![image](https://github.com/willrsq1/cube/assets/117649637/d8328d3b-ae80-4a6c-9949-25a14724bcdc)

# Final Grade
![image](https://github.com/willrsq1/cube/assets/117649637/07efd9c4-a182-44b1-9fa5-903511eccbda)

Description inspired by mcombeau
