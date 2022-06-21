#pragma once

float ver[8][3] =
{
    {-1.0,  -1.0,    1.0},
    {-1.0,   1.0,    1.0},
    { 1.0,   1.0,    1.0},
    { 1.0,  -1.0,    1.0},
    {-1.0,  -1.0,   -1.0},
    {-1.0,   1.0,   -1.0},
    { 1.0,   1.0,   -1.0},
    { 1.0,  -1.0,   -1.0},
};

GLfloat color[8][3] =
{
    {0.0,   0.0,    0.0},
    {1.0,   0.0,    0.0},
    {1.0,   1.0,    0.0},
    {0.0,   1.0,    0.0},
    {0.0,   0.0,    1.0},
    {1.0,   0.0,    1.0},
    {1.0,   1.0,    1.0},
    {0.0,   1.0,    1.0},
};

void quad(int a, int b, int c, int d)
{
    glBegin(GL_QUADS);
    glColor3fv(color[a]);
    glVertex3fv(ver[a]);

    glColor3fv(color[b]);
    glVertex3fv(ver[b]);

    glColor3fv(color[c]);
    glVertex3fv(ver[c]);

    glColor3fv(color[d]);
    glVertex3fv(ver[d]);
    glEnd();
}

void colorcube()
{
    quad(0, 3, 2, 1);
    quad(2, 3, 7, 6);
    quad(0, 4, 7, 3);
    quad(1, 2, 6, 5);
    quad(4, 5, 6, 7);
    quad(0, 1, 5, 4);
}