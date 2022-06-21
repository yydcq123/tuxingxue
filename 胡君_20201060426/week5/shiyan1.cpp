#include<GL/glut.h>
#include<math.h>
#include<iostream>
using namespace std;
float R;
const double PI = acos(-1.0);
void displayCircle()
{
    glClear(GL_COLOR_BUFFER_BIT);       //清除。GL_COLOR_BUFFER_BIT表示清除颜色
    int n = 80;     //这里的n表示用多边形绘制圆的精度，可以考虑增大精度
    glBegin(GL_LINE_STRIP);
    /*
        表示对以下画出的点进行的操作，这里是形成多边形
        类似的还有GL_LINE_STRIP、GL_LINE_LOOP、GL_POINT等
    */
    for (int i = 0; i < n; i++)     //通过数学计算来画多边形的点
    {
        glVertex2f(R * cos(2 * PI * i / n), R * sin(2 * PI * i / n));
    }
    int i = 0;
    glVertex2f(R * cos(2 * PI * i / n), R * sin(2 * PI * i / n));
    glEnd();
    glFlush();
}
void displayStar()
{
    GLfloat a = 1 / (2 - 2 * cos(72 * PI / 180));
    GLfloat bx = a * cos(18 * PI / 180);
    GLfloat by = a * sin(18 * PI / 180);
    GLfloat cy = -a * cos(18 * PI / 180);
    GLfloat
        PointA[2] = { 0, a },
        PointB[2] = { bx, by },
        PointC[2] = { 0.5, cy },
        PointD[2] = { -0.5, cy },
        PointE[2] = { -bx, by };

    glClear(GL_COLOR_BUFFER_BIT);
    // 按照A->C->E->B->D->A的顺序，可以一笔将五角星画出
    glBegin(GL_LINE_LOOP);
    glVertex2fv(PointA);
    glVertex2fv(PointC);
    glVertex2fv(PointE);
    glVertex2fv(PointB);
    glVertex2fv(PointD);
    glEnd();
    glFlush();
}
int main(int argc, char* argv[])

{
    glutInit(&argc, argv);
    /*
        对GLUT进行初始化，这个函数必须在其它的GLUT使用之前调用一次。
        其格式比较死板，一般照抄这句glutInit(&argc, argv)就可以了。
    */
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
    /*
        设置显示方式。
        其中GLUT_RGB表示使用RGB颜色，与之对应的还有GLUT_INDEX（表示使用索引颜色）。
        GLUT_SINGLE表示使用单缓冲，与之对应的还有GLUT_DOUBLE（使用双缓冲）。
    */
    glutInitWindowPosition(100, 100);       //指定窗口位置
    glutInitWindowSize(400, 400);       //指定窗口大小
    glutCreateWindow("胡君20201060426");        //新窗口标题
    cout << "请输入R的值：" << endl;
    cin >> R;
    glutDisplayFunc(&displayCircle);
    //glutDisplayFunc(&displayStar);
    glutMainLoop();     //显示窗口，窗口关闭时跳出循环
    return 0;
}
