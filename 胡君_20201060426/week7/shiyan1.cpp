#include <gl/glut.h>
#include <iostream>
using namespace std;
int winWidth = 400, winHeight = 300;
//定义变量
int flag = 0;
int n = 0;
int tempX, tempY;


struct LineNode {
int x1;
int y1;
int x2;
int y2;
}Line[100];


void Initial(void) {
glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
}

void ChangeSize(int w, int h) {
winWidth = w;
winHeight = h;
glViewport(0, 0, w, h);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluOrtho2D(0.0, winWidth, 0.0, winHeight);
}

void Display(void) {
glClear(GL_COLOR_BUFFER_BIT);
glColor3f(1.0f, 0.0f, 0.0f);

int i = 0;
//绘制折线
for (i = 0; i < n; i++) {
glBegin(GL_LINES);
glVertex2i(Line[i].x1, Line[i].y1);
glVertex2i(Line[i].x2, Line[i].y2);
glEnd();

}
if (flag == 1) {
glBegin(GL_LINES);
glVertex2i(Line[i].x1, Line[i].y1);
//glVertex2i(tempX, tempY);  
glVertex2i(Line[i].x2, Line[i].y2);
glEnd();
}

glutSwapBuffers();
}


//响应鼠标函数
void MousePlot(GLint button, GLint action, GLint xMouse, GLint yMouse) {
//左键点击
if (button == GLUT_LEFT_BUTTON && action == GLUT_DOWN) {
if (flag == 0) {
flag = 1;
Line[n].x1 = xMouse;
Line[n].y1 = winHeight - yMouse;
//cout<<Line[n].x1<<" "<<Line[n].y1<<endl;

}
else {
//flag = 0;
Line[n].x2 = xMouse;
Line[n].y2 = winHeight - yMouse;

n++;
// 
Line[n].x1 = Line[n - 1].x2;
Line[n].y1 = Line[n - 1].y2;
}

}
//右键点击
if (button == GLUT_RIGHT_BUTTON && action == GLUT_DOWN) {
flag = 0;
n = 0;
glutPostRedisplay();

}

}

// 鼠标移动函数
void PassiveMouseMove(GLint xMouse, GLint yMouse) {
//
//if(flag == 1){
//tempX = xMouse;
//tempY = winHeight - yMouse;
Line[n].x2 = xMouse;
Line[n].y2 = winHeight - yMouse;
glutPostRedisplay();
//Display();
//}

}

//
int main(int argc, char* argv[]) {
glutInit(&argc, argv);
glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
glutInitWindowSize(400, 300);
glutInitWindowPosition(100, 100);
glutCreateWindow("胡君20201060426");
glutDisplayFunc(Display);

glutReshapeFunc(ChangeSize);//回调函数
glutMouseFunc(MousePlot);//指定鼠标点击响应函数
glutPassiveMotionFunc(PassiveMouseMove);//指定鼠标移动响应函数
Initial();
glutMainLoop();
return 0;
}
