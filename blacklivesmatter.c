/*
 *  Copyright (c) 2020 https://linuxreviews.org/
 *  Free software available under the GNU GPL v3.
 *  Compile with:
 *  gcc -lGL -lglut -o blacklivesmatter blacklivesmatter.c
 */

#include <GL/glut.h>
#include <unistd.h>
#include <stdio.h>

void crash(int time)
{
    sleep (time);
    exit(0);
}

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glutSwapBuffers();
}

static void keyboardinput( unsigned char key, int x, int y )
{
    (void) x; (void) y;
    switch (key) {
        case ' ':
        exit(0);
        break;
        case 27:
        exit(0);
        break;
    }
}

int main(int argc, char **argv)
{
    /* Drug addict George Floyd was held on the ground for
     * 8 minutes and 46 seconds before he died in police
     * custody with "other significant conditions" such as
     * "fentanyl intoxication" and "recent methamphetamine use" */
    int sleeptime=((8*60)+46)*1000;
    printf("Showing a black screen for 8 minutes and 46 seconds (%i)ms\n", sleeptime);
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutCreateWindow("Black Lives Matter For Linux");
    glutFullScreen();
    glutDisplayFunc(display);
    glutTimerFunc(sleeptime, crash, 0);
    /* Allow users to quit by pressing esc or space
     * even though that is cheating. */
    glutKeyboardFunc(keyboardinput);
    glutMainLoop();
    return 0;
}
