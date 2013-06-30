Pillow-Engine
=============
##Is there any reason to read this?

1. Yes there is
2. Language is C++, as this is the most common for game dev
3. This will be for 3D games
4. Define more things

##Dev Environment

####To get Visual Studio Premium 2012

1. Go to https://secure.scs.carleton.ca:4430/scs_authentication/dreamspark-form.php?department=scs
2. Sign in with carleton.ca username and password
3. Click on Developer tools
4. Click on Microsoft Visual Studio 2012
5. Look for the link to Microsoft Visual Studio Premium 2012, and add that to your cart
6. Continue with the checkout process, up to the point where it tells you your key and asks you to download it.
7. Save your key somewhere where you will not lose it
8. Go to https://docs.google.com/file/d/0BzWIsCZgQb_LRVlMcF9DbVdzNHM/edit?usp=sharing and download* and run that.
9. Follow the installation instructions and enter the key from earlier

####Download the OpenGL dev library (GLEW and freeGLUT)

1. Go to: http://glew.sourceforge.net/
2. Download the Windows 32 bit binary file
3. Extract the zip to a folder of your choosing
4. [Go here to download freeGlut] (http://sourceforge.net/projects/freeglut/files/freeglut/2.8.1/freeglut-2.8.1.tar.gz/download?use_mirror=superb-dca2&download=)
5. Extract the zip to a location of your choosing
6. Create a folder called C Libs on your C:\ drive
7. In that folder create two folders "include" and "lib"
8. From where you extracted glew copy the contents of "include" and "lib" into the repective folders in "C:\C Libs"
9. Repeat the above for the download of freeGlut
10. once this is done open the project that you wish to work on.
11. once it is open press F5 to build and run it, it should fail to run
12. We now need to copy the "freeglut.dll" file from the freeglut/bin folder into the projects Debug folder
13. Do the same as above for the glew32.dll file in the Glew folder



##Examples

1. window test

    a. draws a basic window and prints a string out to it
    
    b. link to tutorial it came from: http://www.cprogramming.com/tutorial/opengl_first_windows_app.html
    
##Tutorials:
1. [Basic Glut/openGL tutorial] (http://www.lighthouse3d.com/tutorials/glut-tutorial/setup-basics/)




___

\* this download is only an installer, which will download the actual program (~8GB)
