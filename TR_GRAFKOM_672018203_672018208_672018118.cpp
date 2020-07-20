#include<windows.h>
#include<gl/glut.h>

void init(void);
void tampil(void);
void keyboard(unsigned char, int, int);
void mouse(int button, int state, int x, int y);
void ukuran(int, int);
void mouseMotion(int x, int y);

float xrot =0.f;
float yrot = 0.f;
float xdiff = 0.f;
float ydiff = 0.f;
bool mouseDown = false;
int is_depth;

int main (int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(800, 600);
	glutInitWindowPosition(250, 50);
	glutCreateWindow("TUGAS RANCANG");
	init();
	glutDisplayFunc(tampil);
	glutKeyboardFunc(keyboard);
	
	glutMouseFunc(mouse);
	glutMotionFunc(mouseMotion);
	
	glutReshapeFunc(ukuran);
	glutDisplayFunc(tampil);
	glutMainLoop();
	return 0;
}

void init(void)
{
	glClearColor(1,1,1,0);
	glMatrixMode(GL_PROJECTION);
	glEnable(GL_DEPTH_TEST);
	is_depth=1;
	glMatrixMode(GL_MODELVIEW);
	glPointSize(3.5);
	glLineWidth(1);
}

void tampil(void)
{
	glPushMatrix();
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	gluLookAt(0,0,100,0,0,0,0,1,0);
	glRotatef(xrot, 1, 0,0);
	glRotatef(yrot, 0,1,0);
	
	//Lantai
	glBegin(GL_POLYGON);
	glColor3ub(129,126,113);
	glVertex3f(-85,-32.9,165);
	glVertex3f(85,-32.9,165);
	glVertex3f(175,-32.9,75);
	glVertex3f(175,-32.9,-145);
	glVertex3f(85,-32.9,-235);
	glVertex3f(-85,-32.9,-235);
	glVertex3f(-175,-32.9,-145);
	glVertex3f(-175,-32.9,75);
	glEnd();
	
	//Lapangan
	//luar
	glBegin(GL_QUADS);
	glColor3ub(107, 168, 49);
	glVertex3f(-65,-32,55);
	glVertex3f(65,-32,55);
	glVertex3f(65,-32,-125);
	glVertex3f(-65,-32,-125);
	glEnd();
	
	//luar Putih
	glBegin(GL_QUADS);
	glColor3ub(255, 255, 255);
	glVertex3f(-41,-31,31);
	glVertex3f(41,-31,31);
	glVertex3f(41,-31,-101);
	glVertex3f(-41,-31,-101);
	glEnd();
	
	//Dalam
	glBegin(GL_QUADS);
	glColor3ub(135, 170, 48);
	glVertex3f(-40,-30,30);
	glVertex3f(40,-30,30);
	glVertex3f(40,-30,-100);
	glVertex3f(-40,-30,-100);
	glEnd();
	
	//Garis Putih Tengah
	glBegin(GL_QUADS);
	glColor3ub(255, 255, 255);
	glVertex3f(-40,-29.7,-35);
	glVertex3f(40,-29.7,-35);
	glVertex3f(40,-29.7,-36);
	glVertex3f(-40,-29.7,-36);
	glEnd();
	
	//Poligon Tengah Dalam
	glBegin(GL_POLYGON);
	glColor3ub(135, 170, 48);
	glVertex3f(-9,-29.8,-35);
	glVertex3f(-5,-29.8,-27);
	glVertex3f(5,-29.8,-27);
	glVertex3f(9,-29.8,-35);
	glVertex3f(5,-29.8,-43);
	glVertex3f(-5,-29.8,-43);
	glEnd();
	
	//Poligon Tengah Luar
	glBegin(GL_POLYGON);
	glColor3ub(255, 255, 255);
	glVertex3f(-10,-29.9,-35);
	glVertex3f(-6,-29.9,-26);
	glVertex3f(6,-29.9,-26);
	glVertex3f(10,-29.9,-35);
	glVertex3f(6,-29.9,-44);
	glVertex3f(-6,-29.9,-44);
	glEnd();
	
	//Kotak Depan Besar
	//Garis Putih Dalam
	glBegin(GL_QUADS);
	glColor3ub(135, 170, 48);
	glVertex3f(-20,-29.8,30);
	glVertex3f(20,-29.8,30);
	glVertex3f(20,-29.8,10);
	glVertex3f(-20,-29.8,10);
	glEnd();
	
	//Garis Putih Luar
	glBegin(GL_QUADS);
	glColor3ub(255, 255, 255);
	glVertex3f(-21,-29.9,30);
	glVertex3f(21,-29.9,30);
	glVertex3f(21,-29.9,9);
	glVertex3f(-21,-29.9,9);
	glEnd();
	
	//Kotak Depan Kecil
	//Garis Putih Dalam
	glBegin(GL_QUADS);
	glColor3ub(135, 170, 48);
	glVertex3f(-10,-29.6,30);
	glVertex3f(10,-29.6,30);
	glVertex3f(10,-29.6,20);
	glVertex3f(-10,-29.6,20);
	glEnd();
	
	//Garis Putih Luar
	glBegin(GL_QUADS);
	glColor3ub(255, 255, 255);
	glVertex3f(-11,-29.7,30);
	glVertex3f(11,-29.7,30);
	glVertex3f(11,-29.7,19);
	glVertex3f(-11,-29.7,19);
	glEnd();
	
	//Kotak Belakang Besar
	//Garis Putih Dalam
	glBegin(GL_QUADS);
	glColor3ub(135, 170, 48);
	glVertex3f(-20,-29.8,-80);
	glVertex3f(20,-29.8,-80);
	glVertex3f(20,-29.8,-100);
	glVertex3f(-20,-29.8,-100);
	glEnd();
	
	//Garis Putih Luar
	glBegin(GL_QUADS);
	glColor3ub(255, 255, 255);
	glVertex3f(-21,-29.9,-79); 
	glVertex3f(21,-29.9,-79);
	glVertex3f(21,-29.9,-100);
	glVertex3f(-21,-29.9,-100);
	glEnd();
	
	//Kotak Belakang Kecil
	//Garis Putih Dalam
	glBegin(GL_QUADS);
	glColor3ub(135, 170, 48);
	glVertex3f(-10,-29.6,-90);
	glVertex3f(10,-29.6,-90);
	glVertex3f(10,-29.6,-100);
	glVertex3f(-10,-29.6,-100);
	glEnd();
	
	//Garis Putih Luar
	glBegin(GL_QUADS);
	glColor3ub(255, 255, 255);
	glVertex3f(-11,-29.7,-89);
	glVertex3f(11,-29.7,-89);
	glVertex3f(11,-29.7,-100);
	glVertex3f(-11,-29.7,-100);
	glEnd();
	
	//Gawang Depan
	//kanan
	glBegin(GL_QUADS);
	glColor3ub(234, 230, 214);
	glVertex3f(10,-30,40);
	glVertex3f(10,-30,30);
	glVertex3f(10,-23,30);
	glVertex3f(10,-23,35);
	glEnd();
	
	//kiri
	glBegin(GL_QUADS);
	glColor3ub(234, 230, 214);
	glVertex3f(-10,-30,40);
	glVertex3f(-10,-30,30);
	glVertex3f(-10,-23,30);
	glVertex3f(-10,-23,35);
	glEnd();
	
	//belakang
	glBegin(GL_QUADS);
	glColor3ub(234, 230, 214);
	glVertex3f(-10,-30,40);
	glVertex3f(10,-30,40);
	glVertex3f(10,-23,35);
	glVertex3f(-10,-23,35);
	glEnd();
	
	//atas
	glBegin(GL_QUADS);
	glColor3ub(234, 230, 214);
	glVertex3f(-10,-23,35);
	glVertex3f(10,-23,35);
	glVertex3f(10,-23,30);
	glVertex3f(-10,-23,30);
	glEnd();
	
	//Gawang Belakang
	//kanan
	glBegin(GL_QUADS);
	glColor3ub(234, 230, 214);
	glVertex3f(10,-30,-100);
	glVertex3f(10,-30,-110);
	glVertex3f(10,-23,-105);
	glVertex3f(10,-23,-100);
	glEnd();
	
	//kiri
	glBegin(GL_QUADS);
	glColor3ub(234, 230, 214);
	glVertex3f(-10,-30,-100);
	glVertex3f(-10,-30,-110);
	glVertex3f(-10,-23,-105);
	glVertex3f(-10,-23,-100);
	glEnd();
	
	//belakang
	glBegin(GL_QUADS);
	glColor3ub(234, 230, 214);
	glVertex3f(-10,-30,-110);
	glVertex3f(10,-30,-110);
	glVertex3f(10,-23,-105);
	glVertex3f(-10,-23,-105);
	glEnd();
	
	//atas
	glBegin(GL_QUADS);
	glColor3ub(234, 230, 214);
	glVertex3f(-10,-23,-100);
	glVertex3f(10,-23,-100);
	glVertex3f(10,-23,-105);
	glVertex3f(-10,-23,-105);
	glEnd();
	
	//Setengah Poligon depan
	//Dalam
	glBegin(GL_QUADS);
	glColor3ub(135, 170, 48);
	glVertex3f(-10,-29.8,9);
	glVertex3f(10,-29.8,9);
	glVertex3f(6,-29.8,0);
	glVertex3f(-6,-29.8,0);
	glEnd();
	
	//Luar
	glBegin(GL_QUADS);
	glColor3ub(255, 255, 255);
	glVertex3f(-11,-29.9,9);
	glVertex3f(11,-29.9,9);
	glVertex3f(7,-29.9,-1);
	glVertex3f(-7,-29.9,-1);
	glEnd();
	
	//Setengah Poligon Belakang
	//Dalam
	glBegin(GL_QUADS);
	glColor3ub(135, 170, 48);
	glVertex3f(-6,-29.8,-70);
	glVertex3f(6,-29.8,-70);
	glVertex3f(10,-29.8,-79);
	glVertex3f(-10,-29.8,-79);
	glEnd();
	
	//Luar
	glBegin(GL_QUADS);
	glColor3ub(255, 255, 255);
	glVertex3f(-7,-29.9,-69);
	glVertex3f(7,-29.9,-69);
	glVertex3f(11,-29.9,-79);
	glVertex3f(-11,-29.9,-79);
	glEnd();
	
	//Dinding kecil
	//kanan1
	glBegin(GL_QUADS);
	glColor3ub(189,186,174);
	glVertex3f(55,-32,45);
	glVertex3f(55,-32,-20);
	glVertex3f(55,-28,-20);
	glVertex3f(55,-28,45);
	glEnd();
	
	//kanan2
	glBegin(GL_QUADS);
	glColor3ub(189,186,174);
	glVertex3f(55,-32,-50);
	glVertex3f(55,-32,-115);
	glVertex3f(55,-28,-115);
	glVertex3f(55,-28,-50);
	glEnd();
	
	//kanan masuk1
	glBegin(GL_QUADS);
	glColor3ub(189,186,174);
	glVertex3f(55,-32,-20);
	glVertex3f(65,-32,-20);
	glVertex3f(65,-28,-20);
	glVertex3f(55,-28,-20);
	glEnd();
	
	//kanan masuk2
	glBegin(GL_QUADS);
	glColor3ub(189,186,174);
	glVertex3f(55,-32,-50);
	glVertex3f(65,-32,-50);
	glVertex3f(65,-28,-50);
	glVertex3f(55,-28,-50);
	glEnd();
	
	//kiri
	glBegin(GL_QUADS);
	glColor3ub(189,186,174);
	glVertex3f(-55,-32,45);
	glVertex3f(-55,-32,-115);
	glVertex3f(-55,-28,-115);
	glVertex3f(-55,-28,45);
	glEnd();

	//depan
	glBegin(GL_QUADS);
	glColor3ub(189,186,174);
	glVertex3f(-55,-32,45);
	glVertex3f(55,-32,45);
	glVertex3f(55,-28,45);
	glVertex3f(-55,-28,45);
	glEnd();
	
	//belakang
	glBegin(GL_QUADS);
	glColor3ub(189,186,174);
	glVertex3f(-55,-32,-115);
	glVertex3f(55,-32,-115);
	glVertex3f(55,-28,-115);
	glVertex3f(-55,-28,-115);
	glEnd();
	
	//bangku kanan
	//depan kuning
	glBegin(GL_QUADS);
	glColor3ub(255, 191, 36);
	glVertex3f(65,-32,45);
	glVertex3f(65,-32,12.5);
	glVertex3f(95,-10,12.5);
	glVertex3f(95,-10,45);
	glEnd();
	
	//depan hijau
	glBegin(GL_QUADS);
	glColor3ub(62, 132, 75);
	glVertex3f(65,-32,12.5);
	glVertex3f(65,-32,-20);
	glVertex3f(95,-10,-20);
	glVertex3f(95,-10,12.5);
	glEnd();
	
	//belakang kuning
	glBegin(GL_QUADS);
	glColor3ub(255, 191, 36);
	glVertex3f(65,-32,-82.5);
	glVertex3f(65,-32,-115);
	glVertex3f(95,-10,-115);
	glVertex3f(95,-10,-82.5);
	glEnd();
	
	//belakang hijau
	glBegin(GL_QUADS);
	glColor3ub(62, 132, 75);
	glVertex3f(65,-32,-50);
	glVertex3f(65,-32,-82.5);
	glVertex3f(95,-10,-82.5);
	glVertex3f(95,-10,-50);
	glEnd();
	
	//atas
	glBegin(GL_QUADS);
	glColor3ub(234, 230, 214);
	glVertex3f(95,-10,45);
	glVertex3f(105,-10,45);
	glVertex3f(105,-10,-115);
	glVertex3f(95,-10,-115);
	glEnd();
	
	//bangku kanan atas
	//depan kuning
	glBegin(GL_QUADS);
	glColor3ub(255, 191, 36);
	glVertex3f(105,-10,45);
	glVertex3f(105,-10,12.5);
	glVertex3f(135,12,12.5);
	glVertex3f(135,12,45);
	glEnd();
	
	//tengah hijau
	glBegin(GL_QUADS);
	glColor3ub(62, 132, 75);
	glVertex3f(105,-10,12.5);
	glVertex3f(105,-10,-82.5);
	glVertex3f(135,12,-82.5);
	glVertex3f(135,12,12.5);
	glEnd();
	
	//belakang kuning
	glBegin(GL_QUADS);
	glColor3ub(255, 191, 36);
	glVertex3f(105,-10,-82.5);
	glVertex3f(105,-10,-115);
	glVertex3f(135,12,-115);
	glVertex3f(135,12,-82.5);
	glEnd();
	
	//bangku kiri
	//depan kuning
	glBegin(GL_QUADS);
	glColor3ub(255, 191, 36);
	glVertex3f(-65,-32,45);
	glVertex3f(-65,-32,12.5);
	glVertex3f(-95,-10,12.5);
	glVertex3f(-95,-10,45);
	glEnd();
	
	//tengah hijau
	glBegin(GL_QUADS);
	glColor3ub(62, 132, 75);
	glVertex3f(-65,-32,12.5);
	glVertex3f(-65,-32,-82.5);
	glVertex3f(-95,-10,-82.5);
	glVertex3f(-95,-10,12.5);
	glEnd();
	
	//belakang kuning
	glBegin(GL_QUADS);
	glColor3ub(255, 191, 36);
	glVertex3f(-65,-32,-82.5);
	glVertex3f(-65,-32,-115);
	glVertex3f(-95,-10,-115);
	glVertex3f(-95,-10,-82.5);
	glEnd();
	
	//atas
	glBegin(GL_QUADS);
	glColor3ub(234, 230, 214);
	glVertex3f(-95,-10,45);
	glVertex3f(-105,-10,45);
	glVertex3f(-105,-10,-115);
	glVertex3f(-95,-10,-115);
	glEnd();
	
	//bangku kiri atas
	//depan kuning
	glBegin(GL_QUADS);
	glColor3ub(255, 191, 36);
	glVertex3f(-105,-10,45);
	glVertex3f(-105,-10,12.5);
	glVertex3f(-135,12,12.5);
	glVertex3f(-135,12,45);
	glEnd();
	
	//tengah hijau
	glBegin(GL_QUADS);
	glColor3ub(255, 191, 36);
	glVertex3f(-105,-10,12.5);
	glVertex3f(-105,-10,-82.5);
	glVertex3f(-135,12,-82.5);
	glVertex3f(-135,12,12.5);
	glEnd();
	
	//belakang kuning
	glBegin(GL_QUADS);
	glColor3ub(255, 191, 36);
	glVertex3f(-105,-10,-82.5);
	glVertex3f(-105,-10,-115);
	glVertex3f(-135,12,-115);
	glVertex3f(-135,12,-82.5);
	glEnd();
	
	//bangku depan
	glBegin(GL_QUADS);
	glColor3ub(255, 191, 36);
	glVertex3f(-55,-32,55);
	glVertex3f(55,-32,55);
	glVertex3f(55,-10,85);
	glVertex3f(-55,-10,85);
	glEnd();
	
	//atas
	glBegin(GL_QUADS);
	glColor3ub(234, 230, 214);
	glVertex3f(-55,-10,85);
	glVertex3f(55,-10,85);
	glVertex3f(55,-10,95);
	glVertex3f(-55,-10,95);
	glEnd();
	
	//bangku depan atas
	glBegin(GL_QUADS);
	glColor3ub(255, 191, 36);
	glVertex3f(-55,-10,95);
	glVertex3f(55,-10,95);
	glVertex3f(55,12,125);
	glVertex3f(-55,12,125);
	glEnd();
	
	//bangku belakang
	glBegin(GL_QUADS);
	glColor3ub(255, 191, 36);
	glVertex3f(-55,-32,-125);
	glVertex3f(55,-32,-125);
	glVertex3f(55,-10,-155);
	glVertex3f(-55,-10,-155);
	glEnd();
	
	//atas
	glBegin(GL_QUADS);
	glColor3ub(234, 230, 214);
	glVertex3f(-55,-10,-155);
	glVertex3f(55,-10,-155);
	glVertex3f(55,-10,-165);
	glVertex3f(-55,-10,-165);
	glEnd();
	
	//bangku belakang atas
	glBegin(GL_QUADS);
	glColor3ub(255, 191, 36);
	glVertex3f(-55,-10,-165);
	glVertex3f(55,-10,-165);
	glVertex3f(55,12,-195);
	glVertex3f(-55,12,-195);
	glEnd();
	
	//penyambung bangku depan
	//atas kanan
	glBegin(GL_QUADS);
	glColor3ub(234, 230, 214);
	glVertex3f(55,-10,95);
	glVertex3f(105,-10,45);
	glVertex3f(95,-10,45);
	glVertex3f(55,-10,85);
	glEnd();
	
	//bangku kanan
	glBegin(GL_QUADS);
	glColor3ub(62, 132, 75);
	glVertex3f(55,12,125);
	glVertex3f(135,12,45);
	glVertex3f(105,-10,45);
	glVertex3f(55,-10,95);
	glEnd();
	
	//atas kiri
	glBegin(GL_QUADS);
	glColor3ub(234, 230, 214);
	glVertex3f(-55,-10,95);
	glVertex3f(-105,-10,45);
	glVertex3f(-95,-10,45);
	glVertex3f(-55,-10,85);
	glEnd();
	
	//bangku kiri
	glBegin(GL_QUADS);
	glColor3ub(62, 132, 75);
	glVertex3f(-55,12,125);
	glVertex3f(-135,12,45);
	glVertex3f(-105,-10,45);
	glVertex3f(-55,-10,95);
	glEnd();
	
	//penyambung bangku belakang
	//atas kanan
	glBegin(GL_QUADS);
	glColor3ub(234, 230, 214);
	glVertex3f(55,-10,-155);
	glVertex3f(95,-10,-115);
	glVertex3f(105,-10,-115);
	glVertex3f(55,-10,-165);
	glEnd();
	
	//bangku kanan
	glBegin(GL_QUADS);
	glColor3ub(62,132,75);
	glVertex3f(55,-10,-165);
	glVertex3f(105,-10,-115);
	glVertex3f(135,12,-115);
	glVertex3f(55,12,-195);
	glEnd();
	
	//atas kiri
	glBegin(GL_QUADS);
	glColor3ub(234, 230, 214);
	glVertex3f(-55,-10,-155);
	glVertex3f(-95,-10,-115);
	glVertex3f(-105,-10,-115);
	glVertex3f(-55,-10,-165);
	glEnd();
	
	//bangku kiri
	glBegin(GL_QUADS);
	glColor3ub(62,132,75);
	glVertex3f(-55,-10,-165);
	glVertex3f(-105,-10,-115);
	glVertex3f(-135,12,-115);
	glVertex3f(-55,12,-195);
	glEnd();
	
	//dinding masuk kanan
	//1
	glBegin(GL_QUADS);
	glColor3ub(234, 230, 214);
	glVertex3f(65,-32,-20);
	glVertex3f(135,-32,-20);
	glVertex3f(135,-10,-20);
	glVertex3f(95,-10,-20);
	glEnd();
	
	//2
	glBegin(GL_QUADS);
	glColor3ub(234, 230, 214);
	glVertex3f(65,-32,-50);
	glVertex3f(135,-32,-50);
	glVertex3f(135,-10,-50);
	glVertex3f(95,-10,-50);
	glEnd();
	
	//dinding masuk depan kanan 
	//1
	glBegin(GL_QUADS);
	glColor3ub(234,230,214);
	glVertex3f(65,-32,45);
	glVertex3f(135,-32,45);
	glVertex3f(135,-10,45);
	glVertex3f(95,-10,45);
	glEnd();
	
	//2
	glBegin(GL_QUADS);
	glColor3ub(234,230,214);
	glVertex3f(55,-32,125);
	glVertex3f(55,-32,55);
	glVertex3f(55,-10,85);
	glVertex3f(55,-10,125);
	glEnd();
	
	//dinding masuk depan kiri
	//1
	glBegin(GL_QUADS);
	glColor3ub(234,230,214);
	glVertex3f(-65,-32,45);
	glVertex3f(-135,-32,45);
	glVertex3f(-135,-10,45);
	glVertex3f(-95,-10,45);
	glEnd();
	
	//2
	glBegin(GL_QUADS);
	glColor3ub(234,230,214);
	glVertex3f(-55,-32,125);
	glVertex3f(-55,-32,55);
	glVertex3f(-55,-10,85);
	glVertex3f(-55,-10,125);
	glEnd();
	
	//dinding masuk belakang kanan
	//1
	glBegin(GL_QUADS);
	glColor3ub(234,230,214);
	glVertex3f(65,-32,-115);
	glVertex3f(135,-32,-115);
	glVertex3f(135,-10,-115);
	glVertex3f(95,-10,-115);
	glEnd();
	
	//2
	glBegin(GL_QUADS);
	glColor3ub(234,230,214);
	glVertex3f(55,-32,-125);
	glVertex3f(55,-32,-195);
	glVertex3f(55,-10,-195);
	glVertex3f(55,-10,-155);
	glEnd();
	
	//dinding masuk belakang kiri
	//1
	glBegin(GL_QUADS);
	glColor3ub(234,230,214);
	glVertex3f(-65,-32,-115);
	glVertex3f(-135,-32,-115);
	glVertex3f(-135,-10,-115);
	glVertex3f(-95,-10,-115);
	glEnd();
	
	//2
	glBegin(GL_QUADS);
	glColor3ub(234,230,214);
	glVertex3f(-55,-32,-125);
	glVertex3f(-55,-32,-195);
	glVertex3f(-55,-10,-195);
	glVertex3f(-55,-10,-155);
	glEnd();
	
	//dinding luar kanan
	glBegin(GL_QUADS);
	glColor3ub(189,186,174);
	glVertex3f(135,-32,45);
	glVertex3f(135,-32,-115);
	glVertex3f(135,12,-115);
	glVertex3f(135,12,45);
	glEnd();
	
	//dinding luar kiri
	glBegin(GL_QUADS);
	glColor3ub(189,186,174);
	glVertex3f(-135,-32,45);
	glVertex3f(-135,-32,-115);
	glVertex3f(-135,12,-115);
	glVertex3f(-135,12,45);
	glEnd();
	
	//dinding Luar belakang
	glBegin(GL_QUADS);
	glColor3ub(189,186,174);
	glVertex3f(-55,-32,-195);
	glVertex3f(55,-32,-195);
	glVertex3f(55,12,-195);
	glVertex3f(-55,12,-195);
	glEnd();
	
	//dinding Luar depan
	glBegin(GL_QUADS);
	glColor3ub(189,186,174);
	glVertex3f(-55,-32,125);
	glVertex3f(55,-32,125);
	glVertex3f(55,12,125);
	glVertex3f(-55,12,125);
	glEnd();
	
	//dinding Luar penyambung depan
	//kanan
	glBegin(GL_QUADS);
	glColor3ub(189,186,174);
	glVertex3f(55,-32,125);
	glVertex3f(135,-32,45);
	glVertex3f(135,12,45);
	glVertex3f(55,12,125);
	glEnd();
	
	//kiri
	glBegin(GL_QUADS);
	glColor3ub(189,186,174);
	glVertex3f(-55,-32,125);
	glVertex3f(-135,-32,45);
	glVertex3f(-135,12,45);
	glVertex3f(-55,12,125);
	glEnd();
	
	//dinding Luar penyambung belakang
	//kanan
	glBegin(GL_QUADS);
	glColor3ub(189,186,174);
	glVertex3f(55,-32,-195);
	glVertex3f(135,-32,-115);
	glVertex3f(135,12,-115);
	glVertex3f(55,12,-195);
	glEnd();
	
	//kiri
	glBegin(GL_QUADS);
	glColor3ub(189,186,174);
	glVertex3f(-55,-32,-195);
	glVertex3f(-135,-32,-115);
	glVertex3f(-135,12,-115);
	glVertex3f(-55,12,-195);
	glEnd();
	
	//atap kanan
	//depan
	glBegin(GL_POLYGON);
	glColor3ub(107,159,110);
	glVertex3f(55,12,125);
	glVertex3f(135,12,45);
	glVertex3f(55,50,45);
	glEnd();
	
	//belakang
	glBegin(GL_POLYGON);
	glColor3ub(107,159,110);
	glVertex3f(55,50,-115);
	glVertex3f(135,12,-115);
	glVertex3f(55,12,-195);
	glEnd();
	
	//tengah
	glBegin(GL_QUADS);
	glColor3ub(107,159,110);
	glVertex3f(55,50,45);
	glVertex3f(135,12,45);
	glVertex3f(135,12,-115);
	glVertex3f(55,50,-115);
	glEnd();
	
	//atap kiri
	//depan
	glBegin(GL_POLYGON);
	glColor3ub(107,159,110);
	glVertex3f(-55,12,125);
	glVertex3f(-135,12,45);
	glVertex3f(-55,50,45);
	glEnd();
	
	//belakang
	glBegin(GL_POLYGON);
	glColor3ub(107,159,110);
	glVertex3f(-55,50,-115);
	glVertex3f(-135,12,-115);
	glVertex3f(-55,12,-195);
	glEnd();
	
	//tengah
	glBegin(GL_QUADS);
	glColor3ub(107,159,110);
	glVertex3f(-55,50,45);
	glVertex3f(-135,12,45);
	glVertex3f(-135,12,-115);
	glVertex3f(-55,50,-115);
	glEnd();
	
	//atap depan
	glBegin(GL_QUADS);
	glColor3ub(107,159,110);
	glVertex3f(-55,12,125);
	glVertex3f(55,12,125);
	glVertex3f(55,31,85);
	glVertex3f(-55,31,85);
	glEnd();
	
	//atap belakang
	glBegin(GL_QUADS);
	glColor3ub(107,159,110);
	glVertex3f(-55,31,-155);
	glVertex3f(55,31,-155);
	glVertex3f(55,12,-195);
	glVertex3f(-55,12,-195);
	glEnd();
	
	//Garis depan
	//1
	glBegin(GL_QUADS);
	glColor3ub(234,230,214);
	glVertex3f(-55,-32,160);
	glVertex3f(-55,-32,125);
	glVertex3f(-55,12,125);
	glVertex3f(-55,12,140);
	glEnd();

	//2
	glBegin(GL_QUADS);
	glColor3ub(234,230,214);
	glVertex3f(55,-32,160);
	glVertex3f(55,-32,125);
	glVertex3f(55,12,125);
	glVertex3f(55,12,140);
	glEnd();
	
	//3
	glBegin(GL_QUADS);
	glColor3ub(234,230,214);
	glVertex3f(0,-32,160);
	glVertex3f(0,-32,125);
	glVertex3f(0,12,125);
	glVertex3f(0,12,140);
	glEnd();
	
	//4
	glBegin(GL_QUADS);
	glColor3ub(234,230,214);
	glVertex3f(27.5,-32,160);
	glVertex3f(27.5,-32,125);
	glVertex3f(27.5,12,125);
	glVertex3f(27.5,12,140);
	glEnd();
	
	//5
	glBegin(GL_QUADS);
	glColor3ub(234,230,214);
	glVertex3f(-27.5,-32,160);
	glVertex3f(-27.5,-32,125);
	glVertex3f(-27.5,12,125);
	glVertex3f(-27.5,12,140);
	glEnd();
	
	//Garis belakang
	//1
	glBegin(GL_QUADS);
	glColor3ub(234,230,214);
	glVertex3f(-55,-32,-195);
	glVertex3f(-55,-32,-230);
	glVertex3f(-55,12,-210);
	glVertex3f(-55,12,-195);
	glEnd();

	//2
	glBegin(GL_QUADS);
	glColor3ub(234,230,214);
	glVertex3f(55,-32,-195);
	glVertex3f(55,-32,-230);
	glVertex3f(55,12,-210);
	glVertex3f(55,12,-195);
	glEnd();
	
	//3
	glBegin(GL_QUADS);
	glColor3ub(234,230,214);
	glVertex3f(0,-32,-195);
	glVertex3f(0,-32,-230);
	glVertex3f(0,12,-210);
	glVertex3f(0,12,-195);
	glEnd();
	
	//4
	glBegin(GL_QUADS);
	glColor3ub(234,230,214);
	glVertex3f(27.5,-32,-195);
	glVertex3f(27.5,-32,-230);
	glVertex3f(27.5,12,-210);
	glVertex3f(27.5,12,-195);
	glEnd();
	
	//5
	glBegin(GL_QUADS);
	glColor3ub(234,230,214);
	glVertex3f(-27.5,-32,-195);
	glVertex3f(-27.5,-32,-230);
	glVertex3f(-27.5,12,-210);
	glVertex3f(-27.5,12,-195);
	glEnd();
	
	//atas kanan1
	glBegin(GL_QUADS);
	glColor3ub(234,230,214);
	glVertex3f(135,12,45);
	glVertex3f(155,12,45);
	glVertex3f(155,12,-115);
	glVertex3f(135,12,-115);
	glEnd();
	
	//atas kanan2
	glBegin(GL_QUADS);
	glColor3ub(234,230,214);
	glVertex3f(135,-5,45);
	glVertex3f(155,-5,45);
	glVertex3f(155,-5,-115);
	glVertex3f(135,-5,-115);
	glEnd();
	
	//atas kanan3
	glBegin(GL_QUADS);
	glColor3ub(234,230,214);
	glVertex3f(135,-18,45);
	glVertex3f(155,-18,45);
	glVertex3f(155,-18,-115);
	glVertex3f(135,-18,-115);
	glEnd();
	
	//atas kiri1
	glBegin(GL_QUADS);
	glColor3ub(234,230,214);
	glVertex3f(-135,12,45);
	glVertex3f(-155,12,45);
	glVertex3f(-155,12,-115);
	glVertex3f(-135,12,-115);
	glEnd();
	
	//atas kiri2
	glBegin(GL_QUADS);
	glColor3ub(234,230,214);
	glVertex3f(-135,-5,45);
	glVertex3f(-155,-5,45);
	glVertex3f(-155,-5,-115);
	glVertex3f(-135,-5,-115);
	glEnd();
	
	//atas kiri3
	glBegin(GL_QUADS);
	glColor3ub(234,230,214);
	glVertex3f(-135,-18,45);
	glVertex3f(-155,-18,45);
	glVertex3f(-155,-18,-115);
	glVertex3f(-135,-18,-115);
	glEnd();
	
	//atas depan serong kanan
	glBegin(GL_QUADS);
	glColor3ub(234,230,214);
	glVertex3f(55,12,145);
	glVertex3f(155,12,45);
	glVertex3f(135,12,45);
	glVertex3f(55,12,125);
	glEnd();
	
	//atas belakang serong kiri
	glBegin(GL_QUADS);
	glColor3ub(234,230,214);
	glVertex3f(55,12,-195);
	glVertex3f(135,12,-115);
	glVertex3f(155,12,-115);
	glVertex3f(55,12,-215);
	glEnd();
	
	//atas belakang serong kanan
	glBegin(GL_QUADS);
	glColor3ub(234,230,214);
	glVertex3f(-55,12,-195);
	glVertex3f(-135,12,-115);
	glVertex3f(-155,12,-115);
	glVertex3f(-55,12,-215);
	glEnd();
	
	//atas belakang serong kanan
	glBegin(GL_QUADS);
	glColor3ub(234,230,214);
	glVertex3f(55,12,145);
	glVertex3f(155,12,45);
	glVertex3f(135,12,45);
	glVertex3f(55,12,125);
	glEnd();
	
	//atas depan serong kiri
	glBegin(GL_QUADS);
	glColor3ub(234,230,214);
	glVertex3f(-55,12,145);
	glVertex3f(-155,12,45);
	glVertex3f(-135,12,45);
	glVertex3f(-55,12,125);
	glEnd();
	
	//tangga kanan1
	glBegin(GL_QUADS);
	glColor3ub(216,212,195);
	glVertex3f(175,-32,45);
	glVertex3f(175,-32,25);
	glVertex3f(155,-5,25);
	glVertex3f(155,-5,45);
	glEnd();
	
	//tangga kanan2
	glBegin(GL_QUADS);
	glColor3ub(216,212,195);
	glVertex3f(175,-32,-95);
	glVertex3f(175,-32,-115);
	glVertex3f(155,-5,-115);
	glVertex3f(155,-5,-95);
	glEnd();
	
	//tangga kanan3
	glBegin(GL_QUADS);
	glColor3ub(216,212,195);
	glVertex3f(175,-32,20);
	glVertex3f(175,-32,0);
	glVertex3f(155,-18,0);
	glVertex3f(155,-18,20);
	glEnd();
	
	//tangga kanan4
	glBegin(GL_QUADS);
	glColor3ub(216,212,195);
	glVertex3f(175,-32,-70);
	glVertex3f(175,-32,-90);
	glVertex3f(155,-18,-90);
	glVertex3f(155,-18,-70);
	glEnd();
	
	//tangga kiri1
	glBegin(GL_QUADS);
	glColor3ub(216,212,195);
	glVertex3f(-175,-32,45);
	glVertex3f(-175,-32,25);
	glVertex3f(-155,-5,25);
	glVertex3f(-155,-5,45);
	glEnd();
	
	//tangga kiri2
	glBegin(GL_QUADS);
	glColor3ub(216,212,195);
	glVertex3f(-175,-32,-95);
	glVertex3f(-175,-32,-115);
	glVertex3f(-155,-5,-115);
	glVertex3f(-155,-5,-95);
	glEnd();
	
	//tangga kiri3
	glBegin(GL_QUADS);
	glColor3ub(216,212,195);
	glVertex3f(-175,-32,20);
	glVertex3f(-175,-32,0);
	glVertex3f(-155,-18,0);
	glVertex3f(-155,-18,20);
	glEnd();
	
	//tangga kiri4
	glBegin(GL_QUADS);
	glColor3ub(216,212,195);
	glVertex3f(-175,-32,-70);
	glVertex3f(-175,-32,-90);
	glVertex3f(-155,-18,-90);
	glVertex3f(-155,-18,-70);
	glEnd();
	
	//bola
	glPushMatrix();
	glTranslatef(0,-28,-35);
	glColor3ub(216,212,195);
	glutSolidSphere(-1,100,100);
	glPopMatrix();
	
	//pintu kanan Luar
	glBegin(GL_QUADS);
	glColor3ub(79,70,67);
	glVertex3f(135.1,-32,-18);
	glVertex3f(135.1,-32,-52);
	glVertex3f(135.1,-21,-52);
	glVertex3f(135.1,-21,-18);
	glEnd();
	
	//pintu kanan Dalam
	glBegin(GL_QUADS);
	glColor3ub(255,255,255);
	glVertex3f(135.2,-32,-20);
	glVertex3f(135.2,-32,-50);
	glVertex3f(135.2,-23,-50);
	glVertex3f(135.2,-23,-20);
	glEnd();
	
	//garis tengah
	glBegin(GL_QUADS);
	glColor3ub(79,70,67);
	glVertex3f(135.3,-32,-34);
	glVertex3f(135.3,-32,-36);
	glVertex3f(135.3,-23,-36);
	glVertex3f(135.3,-23,-34);
	glEnd();
	
	//pintu kiri Luar
	glBegin(GL_QUADS);
	glColor3ub(79,70,67);
	glVertex3f(-135.1,-32,-18);
	glVertex3f(-135.1,-32,-52);
	glVertex3f(-135.1,-21,-52);
	glVertex3f(-135.1,-21,-18);
	glEnd();
	
	//pintu kiri Dalam
	glBegin(GL_QUADS);
	glColor3ub(255,255,255);
	glVertex3f(-135.2,-32,-20);
	glVertex3f(-135.2,-32,-50);
	glVertex3f(-135.2,-23,-50);
	glVertex3f(-135.2,-23,-20);
	glEnd();
	
	//garis tengah
	glBegin(GL_QUADS);
	glColor3ub(79,70,67);
	glVertex3f(-135.3,-32,-34);
	glVertex3f(-135.3,-32,-36);
	glVertex3f(-135.3,-23,-36);
	glVertex3f(-135.3,-23,-34);
	glEnd();
	
	//pintu tangga kanan bawah
	glBegin(GL_QUADS);
	glColor3ub(255,255,255);
	glVertex3f(135.2,-18,20);
	glVertex3f(135.2,-18,0);
	glVertex3f(135.2,-9,0);
	glVertex3f(135.2,-9,20);
	glEnd();
	
	//batas pintu
	glBegin(GL_QUADS);
	glColor3ub(79,70,67);
	glVertex3f(135.1,-18,22);
	glVertex3f(135.1,-18,-2);
	glVertex3f(135.1,-7,-2);
	glVertex3f(135.1,-7,22);
	glEnd();
	
	//sekat pintu
	glBegin(GL_QUADS);
	glColor3ub(79,70,67);
	glVertex3f(135.3,-18,9);
	glVertex3f(135.3,-18,11);
	glVertex3f(135.3,-7,11);
	glVertex3f(135.3,-7,9);
	glEnd();
	
	//pintu tangga kanan bawah 2
	glBegin(GL_QUADS);
	glColor3ub(255,255,255);
	glVertex3f(135.2,-18,-70);
	glVertex3f(135.2,-18,-90);
	glVertex3f(135.2,-9,-90);
	glVertex3f(135.2,-9,-70);
	glEnd();
	
	//batas pintu 2
	glBegin(GL_QUADS);
	glColor3ub(79,70,67);
	glVertex3f(135.1,-18,-68);
	glVertex3f(135.1,-18,-92);
	glVertex3f(135.1,-7,-92);
	glVertex3f(135.1,-7,-68);
	glEnd();
	
	//sekat pintu 2
	glBegin(GL_QUADS);
	glColor3ub(79,70,67);
	glVertex3f(135.3,-18,-79);
	glVertex3f(135.3,-18,-81);
	glVertex3f(135.3,-7,-81);
	glVertex3f(135.3,-7,-79);
	glEnd();
	
	//pintu tangga kanan atas
	glBegin(GL_QUADS);
	glColor3ub(255,255,255);
	glVertex3f(135.2,-5,45);
	glVertex3f(135.2,-5,25);
	glVertex3f(135.2,7,25);
	glVertex3f(135.2,7,45);
	glEnd();
	
	//batas pintu atas
	glBegin(GL_QUADS);
	glColor3ub(79,70,67);
	glVertex3f(135.1,-5,47);
	glVertex3f(135.1,-5,23);
	glVertex3f(135.1,9,23);
	glVertex3f(135.1,9,47);
	glEnd();
	
	//sekat pintu atas
	glBegin(GL_QUADS);
	glColor3ub(79,70,67);
	glVertex3f(135.3,-5,36);
	glVertex3f(135.3,-5,34);
	glVertex3f(135.3,7,34);
	glVertex3f(135.3,7,36);
	glEnd();
	
	//pintu tangga kanan atas 2
	glBegin(GL_QUADS);
	glColor3ub(255,255,255);
	glVertex3f(135.2,-5,-95);
	glVertex3f(135.2,-5,-115);
	glVertex3f(135.2,7,-115);
	glVertex3f(135.2,7,-95);
	glEnd();
	
	//batas pintu atas2
	glBegin(GL_QUADS);
	glColor3ub(79,70,67);
	glVertex3f(135.1,-5,-93);
	glVertex3f(135.1,-5,-117);
	glVertex3f(135.1,9,-117);
	glVertex3f(135.1,9,-93);
	glEnd();
	
	//sekat pintu atas2
	glBegin(GL_QUADS);
	glColor3ub(79,70,67);
	glVertex3f(135.3,-5,-104);
	glVertex3f(135.3,-5,-106);
	glVertex3f(135.3,7,-106);
	glVertex3f(135.3,7,-104);
	glEnd();
	
	//pintu tangga kiri bawah
	glBegin(GL_QUADS);
	glColor3ub(255,255,255);
	glVertex3f(-135.2,-18,20);
	glVertex3f(-135.2,-18,0);
	glVertex3f(-135.2,-9,0);
	glVertex3f(-135.2,-9,20);
	glEnd();
	
	//batas pintu
	glBegin(GL_QUADS);
	glColor3ub(79,70,67);
	glVertex3f(-135.1,-18,22);
	glVertex3f(-135.1,-18,-2);
	glVertex3f(-135.1,-7,-2);
	glVertex3f(-135.1,-7,22);
	glEnd();
	
	//sekat pintu
	glBegin(GL_QUADS);
	glColor3ub(79,70,67);
	glVertex3f(-135.3,-18,9);
	glVertex3f(-135.3,-18,11);
	glVertex3f(-135.3,-7,11);
	glVertex3f(-135.3,-7,9);
	glEnd();
	
	//pintu tangga kiri bawah 2
	glBegin(GL_QUADS);
	glColor3ub(255,255,255);
	glVertex3f(-135.2,-18,-70);
	glVertex3f(-135.2,-18,-90);
	glVertex3f(-135.2,-9,-90);
	glVertex3f(-135.2,-9,-70);
	glEnd();
	
	//batas pintu 2
	glBegin(GL_QUADS);
	glColor3ub(79,70,67);
	glVertex3f(-135.1,-18,-68);
	glVertex3f(-135.1,-18,-92);
	glVertex3f(-135.1,-7,-92);
	glVertex3f(-135.1,-7,-68);
	glEnd();
	
	//sekat pintu 2
	glBegin(GL_QUADS);
	glColor3ub(79,70,67);
	glVertex3f(-135.3,-18,-79);
	glVertex3f(-135.3,-18,-81);
	glVertex3f(-135.3,-7,-81);
	glVertex3f(-135.3,-7,-79);
	glEnd();
	
	//pintu tangga kiri atas
	glBegin(GL_QUADS);
	glColor3ub(255,255,255);
	glVertex3f(-135.2,-5,45);
	glVertex3f(-135.2,-5,25);
	glVertex3f(-135.2,7,25);
	glVertex3f(-135.2,7,45);
	glEnd();
	
	//batas pintu atas
	glBegin(GL_QUADS);
	glColor3ub(79,70,67);
	glVertex3f(-135.1,-5,47);
	glVertex3f(-135.1,-5,23);
	glVertex3f(-135.1,9,23);
	glVertex3f(-135.1,9,47);
	glEnd();
	
	//sekat pintu atas
	glBegin(GL_QUADS);
	glColor3ub(79,70,67);
	glVertex3f(-135.3,-5,36);
	glVertex3f(-135.3,-5,34);
	glVertex3f(-135.3,7,34);
	glVertex3f(-135.3,7,36);
	glEnd();
	
	//pintu tangga kiri atas 2
	glBegin(GL_QUADS);
	glColor3ub(255,255,255);
	glVertex3f(-135.2,-5,-95);
	glVertex3f(-135.2,-5,-115);
	glVertex3f(-135.2,7,-115);
	glVertex3f(-135.2,7,-95);
	glEnd();
	
	//batas pintu atas2
	glBegin(GL_QUADS);
	glColor3ub(79,70,67);
	glVertex3f(-135.1,-5,-93);
	glVertex3f(-135.1,-5,-117);
	glVertex3f(-135.1,9,-117);
	glVertex3f(-135.1,9,-93);
	glEnd();
	
	//sekat pintu atas2
	glBegin(GL_QUADS);
	glColor3ub(79,70,67);
	glVertex3f(-135.3,-5,-104);
	glVertex3f(-135.3,-5,-106);
	glVertex3f(-135.3,7,-106);
	glVertex3f(-135.3,7,-104);
	glEnd();
	
	
	//bangku cadangan 1
	
	//samping 1
	glBegin(GL_QUADS);
	glColor3ub(255,255,255);
	glVertex3f(48,-32,30);
	glVertex3f(54,-32,30);
	glVertex3f(54,-25,30);
	glVertex3f(48 ,-22,30);
	glEnd();
	
	//samping 2
	glBegin(GL_QUADS);
	glColor3ub(255,255,255);
	glVertex3f(48,-32,10);
	glVertex3f(54,-32,10);
	glVertex3f(54,-25,10);
	glVertex3f(48 ,-22,10);
	glEnd();
	
	//belakang 
	glBegin(GL_QUADS);
	glColor3ub(255,255,255);
	glVertex3f(54,-32,30);
	glVertex3f(54,-32,10);
	glVertex3f(54,-25,10);
	glVertex3f(54 ,-25,30);
	glEnd();
	
	//atas
	glBegin(GL_QUADS);
	glColor3ub(255,255,255);
	glVertex3f(48,-22,30);
	glVertex3f(54,-25,30);
	glVertex3f(54,-25,10);
	glVertex3f(48 ,-22,10);
	glEnd();
	
	//bangku
	glBegin(GL_QUADS);
	glColor3ub(234,230,214);
	glVertex3f(48,-30,30);
	glVertex3f(54,-30,30);
	glVertex3f(54,-30,10);
	glVertex3f(48 ,-30,10);
	glEnd();
	
	//bangku cadangan 2
	
	//samping 
	glBegin(GL_QUADS);
	glColor3ub(255,255,255);
	glVertex3f(48,-32,-100);
	glVertex3f(54,-32,-100);
	glVertex3f(54,-25,-100);
	glVertex3f(48 ,-22,-100);
	glEnd();
	
	//samping 2
	glBegin(GL_QUADS);
	glColor3ub(255,255,255);
	glVertex3f(48,-32,-80);
	glVertex3f(54,-32,-80);
	glVertex3f(54,-25,-80);
	glVertex3f(48 ,-22,-80);
	glEnd();
	
	//belakang 
	glBegin(GL_QUADS);
	glColor3ub(255,255,255);
	glVertex3f(54,-32,-100);
	glVertex3f(54,-32,-80);
	glVertex3f(54,-25,-80);
	glVertex3f(54 ,-25,-100);
	glEnd();
	
	//atas
	glBegin(GL_QUADS);
	glColor3ub(255,255,255);
	glVertex3f(48,-22,-100);
	glVertex3f(54,-25,-100);
	glVertex3f(54,-25,-80);
	glVertex3f(48 ,-22,-80);
	glEnd();
	
	//bangku
	glBegin(GL_QUADS);
	glColor3ub(234,230,214);
	glVertex3f(48,-30,-100);
	glVertex3f(54,-30,-100);
	glVertex3f(54,-30,-80);
	glVertex3f(48 ,-30,-80);
	glEnd();
	
	//bendera kanan 1 
	glBegin(GL_QUADS);
	glColor3ub(234,230,214);
	glVertex3f(40,-30,30);
	glVertex3f(40,-30,30.5);
	glVertex3f(40,-25,30.5);
	glVertex3f(40,-25,30);
	glEnd();
	
	// bendera 1
	glBegin(GL_QUADS);
	glColor3ub(251,25,25);
	glVertex3f(40,-27,30.5);
	glVertex3f(40,-27,32);
	glVertex3f(40,-25,32);
	glVertex3f(40,-25,30.5);
	glEnd();
	
	//bendera kiri 1 
	glBegin(GL_QUADS);
	glColor3ub(234,230,214);
	glVertex3f(-40,-30,30);
	glVertex3f(-40,-30,30.5);
	glVertex3f(-40,-25,30.5);
	glVertex3f(-40,-25,30);
	glEnd();
	
	// bendera 1
	glBegin(GL_QUADS);
	glColor3ub(251,25,25);
	glVertex3f(-40,-27,30.5);
	glVertex3f(-40,-27,32);
	glVertex3f(-40,-25,32);
	glVertex3f(-40,-25,30.5);
	glEnd();
	
	
	//bendera kanan 2 
	glBegin(GL_QUADS);
	glColor3ub(234,230,214);
	glVertex3f(40,-30,-99.5);
	glVertex3f(40,-30,-100);
	glVertex3f(40,-25,-100);
	glVertex3f(40,-25,-99.5);
	glEnd();
	
	// bendera 2
	glBegin(GL_QUADS);
	glColor3ub(251,25,25);
	glVertex3f(40,-27,-97);
	glVertex3f(40,-27,-99.5);
	glVertex3f(40,-25,-99.5);
	glVertex3f(40,-25,-97);
	glEnd();
	
	//bendera kiri 2 
	glBegin(GL_QUADS);
	glColor3ub(234,230,214);
	glVertex3f(-40,-30,-99.5);
	glVertex3f(-40,-30,-100);
	glVertex3f(-40,-25,-100);
	glVertex3f(-40,-25,-99.5);
	glEnd();
	
	// bendera 2
	glBegin(GL_QUADS);
	glColor3ub(251,25,25);
	glVertex3f(-40,-27,-97);
	glVertex3f(-40,-27,-99.5);
	glVertex3f(-40,-25,-99.5);
	glVertex3f(-40,-25,-97);
	glEnd();
	
	glPopMatrix();
	glutSwapBuffers();
}

void keyboard (unsigned char key, int x, int y)
{
	switch (key)
	{
		case 'w':
		case 'W':
			glTranslatef(0,0,3);
			break;
		case 's':
		case 'S':
			glTranslatef(0,0,-3);
			break;
		case 'd':
		case 'D':
			glTranslatef(3,0,0);
			break;	
		case 'a':
		case 'A':
			glTranslatef(-3,0,0);
			break;
		case '7':
			glTranslatef(0,3,0);
			break;
		case '9':
			glTranslatef(0,-3,0);
			break;
		case '2':
			glRotatef(2,1,0,0);
			break;
		case '8':
			glRotatef(-2,1,0,0);
			break;
		case '6':
			glRotatef(2,0,1,0);
			break;	
		case '4':
			glRotatef(-2,0,1,0);
			break;
		case '1':
			glRotatef(2,0,0,1);
			break;
		case '3':
			glRotatef(-2,0,0,1);
			break;
		case '5':
			if(is_depth)
			{
				is_depth = 0;
				glDisable(GL_DEPTH_TEST);
			}
			else
			{
				is_depth = 1;
				glEnable(GL_DEPTH_TEST);
			}
	}
	tampil();
}

void idle()
{
	if (!mouseDown)
	{
		xrot += 0.3;
		yrot += 0.4;
	}
	glutPostRedisplay();
}

void mouse(int button, int state, int x, int y)
{
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		mouseDown = true;
		xdiff = x - yrot;
		ydiff = -y + xrot;
	}
	else
	mouseDown = false;
}

void mouseMotion(int x, int y)
{
	if(mouseDown)
	{
		yrot = x - xdiff;
		xrot = y + ydiff;
		
		glutPostRedisplay();
	}
}

void ukuran(int lebar, int tinggi)
{
	if (tinggi ==0) tinggi =1;
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluPerspective(50,lebar/tinggi, 5, 500);
glTranslatef(0,0,-200);
glMatrixMode(GL_MODELVIEW);
}
