#include<GL\glut.h>
#include<iostream>
#include<cmath>
using namespace std;
//DDA算法绘制直线
void DrowDDA(int x1, int y1, int x2, int y2)
{
	glColor3f(1.0, 0.0, 0.0);       //所要画线的颜色为红色
	glPointSize(3.0f);
	int m = 0;
	//选择两个点的坐标的距离的最大值
	if (abs(x2 - x1) >= abs(y2 - y1))
	{
		m = abs(x2 - x1);              // x 为计长方向
	}
	else
	{
		m = abs(y2 - y1);              // y 为计长方向
	}
	float dx = (float)(x2 - x1) / m;   // 当 x 为计长方向，dx = 1
	float dy = (float)(y2 - y1) / m;   // 当 y 为计长方向，dy = 1
	float x = x1;
	float y = y1;
	for (int i = 0; i < m; ++i)//循环设置定点
	{
		glBegin(GL_POINTS);//把每一个顶点做为一个定点处理，绘制N个定点
		glVertex2f((int)x, (int)y);//设置定点
		glEnd();
		glFlush();
		x += dx;
		y += dy;
	}
}

void display(void)
{
	// 用当前背景色填充窗口，如果不写这句会残留之前的图像
	glClear(GL_COLOR_BUFFER_BIT);
	int x1 = 0, y1 = 0, x2 = 500, y2 = 500;
	int x12 = 0, y12 = 0, x22 = 500, y22 = 500;
	DrowDDA(x1, y1, x2, y2);//使用DDA算法绘制直线
}
int main(int argc, char* argv[])
{
	glutInit(&argc, argv);//初始化glut的库
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(200, 200);//窗口的位置
	glutInitWindowSize(400, 400);//窗口的大小
	glutCreateWindow("胡君 20201060426");
	glutDisplayFunc(display);//调用函数
	glClearColor(1.0, 1.0, 1.0, 0.0);  //窗口的背景为白色
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0.0, 200.0, 0.0, 150.0);
	glutMainLoop();//让 glut 程序进入事件循环。在一个glut程序中最多只能调用一次。一旦调用，会直到程序结束才返回。
	return 0;
}
