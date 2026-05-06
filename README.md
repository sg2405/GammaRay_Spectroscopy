Make a build/ directory in the project directory.

Execute the command "cmake ..". You should get no error/warning messages if it executes successfully.

Execute the command "make". It will create an executable named "gamma_ray" in the build directory.

There are two ways to run this program, Visual mode and Batch Mode. If you want to run this program in Visual mode, use command "./gamma_ray vis.mac" or else use "./gamma_ray run.mac".
The advantage of using Batch mode is it runs faster. You can open run.mac file to see how many particles are set to be simulated. If you make any changes, you would have to start the
process from "cmake .." all over again. 

After the program has run, a output.root file will be generated in the build folder.

(For details on the geometry, check the construct.cc file).
