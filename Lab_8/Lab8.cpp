#include<stdlib.h>
#include"C:\Users\Admin\glut-3.7.6-bin\glut.h"
#include<iostream>
using namespace std;

/* начальная ширина и высота окна */
GLint Width = 1024, Height = 1024;
/* размер куба */
int CubeSize = 10;

void TimerMove(int value) {
	glColor3ub(155, 155, 0);
	int y = 0, x = 0;
	while (y < Height) {
		while (x < Width) {
			glVertex2f(x, y);
			glVertex2f(x + Width / CubeSize, y + Height / CubeSize);
			glVertex2f(x + Width / (CubeSize / 2), y);
			x += Width / (CubeSize / 2);
		}
		x = 0;
		y += Height / CubeSize;
	}
	glutPostRedisplay();
	glutTimerFunc(33, TimerMove, 1);
}

void Display(void) {
	glClearColor(0, 0, 0, 1);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3ub(155, 155, 0);
	glBegin(GL_TRIANGLES);

	int y = 0, x = 0;
	while (y < Height) {
		while (x < Width) {
			glVertex2f(x, y);
			glVertex2f(x + Width / CubeSize, y + Height / CubeSize);
			glVertex2f(x + Width / (CubeSize / 2), y);
			x += Width / (CubeSize / 2);
		}
		x = 0;
		y += Height / CubeSize;
	}

	glEnd();
	glFinish();
}
/* Функция вызывается при изменении размеров окна */
void Reshape(GLint w, GLint h){
	Width = w;
	Height = h;
	/* устанавливаем размеры области отображения */
	glViewport(0, 0, w, h);

	/* ортографическая проекция */
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, w, 0, h, -1.0, 1.0);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

/*Фунция для изменения масштаба изображения*/
void SpecKeyboard(int key, int x, int y) {
	if (key == GLUT_KEY_UP) CubeSize *= (CubeSize < 1024) ? 2 : 1;
	if (key == GLUT_KEY_DOWN) CubeSize /= (CubeSize > 0) ? 2 : 1;
}
void Keyboard(unsigned char key, int x, int y)
{
#define ESCAPE '\033'

	if (key == ESCAPE)
		exit(0);
}

int main(int argc, char* argv[]){
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB);
	glutInitWindowSize(Width, Height);
	glutCreateWindow("Triangles");

	glutDisplayFunc(Display);
	glutReshapeFunc(Reshape);
	glutSpecialFunc(SpecKeyboard);
	glutKeyboardFunc(Keyboard);
	glutTimerFunc(33, TimerMove, 1);
	glutMainLoop();
}