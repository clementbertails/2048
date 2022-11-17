# By Bertails Clément, Longuet Maxime and Maurer Pierrick

## Dependencies

- SDL2 librairie
- SDL2_image librairie extension

## Compilation

Go to the decompressed folder via a terminal. Execute "make".

## Generate Doxygen

If you want to generate the Doxygen, run "make docs". !! You will have to install the graphviz package to avoid errors when generating the doxygen !!

## Read doxygen

Open the doc/html/index.html page generated at the time of "make docs". The Doxyfile is also created with the above command.

## Delete unnecessary files

Run "make clean" : delete the bin folder containing the object files (*.o), the save folder containing a backup of the src folder, the doc folder containing the Doxygen, the last archive created by "make give", the src.old folder created by "make restore" and the executable.

## Create save

Run "make save": create the save folder if it doesn't exist and copy the src folder into it.

## Revert to last save

Run "make restore": restore the backup from the save folder.

## Archive the program

Run "make give": a ready-to-give archive is created.

## Game mode

There are two game modes that you can choose using the graphical interface:

- 4x4 grid (difficult)
- 8x8 gris (easy)

Play with the arrows of the keyboard and enjoy !