#include <iostream>

#ifdef __APPLE__
#  include <GLUT/glut.h>
#else
#  include <GL/glut.h>
#endif
#include <cstdlib>
#include <fstream>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#define PI 3.14159265
#define N 120.0

static float mercurio = 0, lua=0,Venus = 0, terra = 0, marte = 0,jupter = 0, saturno = 0,urano = 0,neturno =0,rotDisco=0, rotsistema=0;
static float hor=0.0,ver=0.0,pro=0.0,rot=0.0, rot1=0.0, rot2=0.0;
static float cone = 0, disco=0,Sc=0,P=16, lateral=0;
static float espX=-10,espY=0,espZ=0,t=2,movX=0,angle=0;
static float escala=0.3;
static float cameraX = 9, cameraY=0, cameraZ=0, cameraRotaca=0;
int i=0,j=0, controle=0;
float engolida = 5.0, cone_alt=1;
GLint fogMode;

static unsigned int texture[15]; // Array of texture indices.
static unsigned char chessboard[64][64][3]; // Storage for chessboard image.
static float d = 0.0; // Distance parameter in gluLookAt().

static GLUquadricObj *qobj_ASS,*qobj,*qobj_mercurio, *qobj_lua,*qobj_Venus, *qobj_terra, *qobj_marte,*qobj_jupter, *qobj_saturno,*qobj_urano,*qobj_neturno,*qobj_cone, *qobj_disco,*qobj_disco_saturno, *qobj_esfera_buraco;

static float ponto[100][2]={{7.609284,-5.440211}, {7.197006,-4.529602}, {6.881821,-3.591488}, {6.665059,-2.636067}, {6.546995,-1.673522}, {6.526865,-0.713917}, {6.602888,0.232910}, {6.772310,1.157450}, {7.031448,2.050614}, {7.375747,2.903824}, {7.799846,3.709096}, {8.297649,4.459116}, {8.862409,5.147301}, {9.486807,5.767861}, {10.163045,6.315842}, {10.882941,6.787165}, {11.638022,7.178652}, {12.419623,7.488044}, {13.218986,7.714003}, {14.027351,7.856115}, {14.836058,7.914867}, {31.636639,7.891632}, {32.420906,7.788628}, {17.181030,7.608881}, {17.909622,7.356170}, {18.599810,7.034976}, {19.245291,6.650413}, {19.840403,6.208157}, {20.380161,5.714375}, {20.860310,5.175645}, {21.277340,4.598869}, {21.628523,3.991196}, {21.911919,3.359932}, {22.126377,2.712456}, {22.271542,2.056135}, {22.347822,1.398242}, {22.356382,0.745879}, {22.299105,0.105893}, {22.178553,-0.515187}, {21.997927,-1.111222}, {21.761007,-1.676522}, {21.472107,-2.205899}, {21.135994,-2.694716}, {20.757843,-3.138928}, {20.343147,-3.535111}, {19.897661,-3.880487}, {19.427319,-4.172941}, {18.938162,-4.411027}, {18.436264,-4.593971}, {17.927664,-4.721659}, {17.418289,-4.794623}, {32.913887,-4.814017}, {32.419975,-4.781588}, {31.941753,-4.699635}, {31.484081,-4.570973}, {31.051403,-4.398878}, {14.647721,-4.187040}, {14.276550,-3.939504}, {13.940893,-3.660608}, {13.643212,-3.354925}, {13.385418,-3.027199}, {13.168858,-2.682277}, {12.994318,-2.325049}, {12.862026,-1.960383}, {12.771667,-1.593063}, {12.722401,-1.227731}, {12.712887,-0.868830}, {12.741318,-0.520552}, {12.805459,-0.186789}, {12.902683,0.128908}, {13.030025,0.423367}, {13.184225,0.693829}, {13.361782,0.937972}, {13.559010,1.153930}, {13.772094,1.340307}, {13.997146,1.496183}, {14.230259,1.621114}, {14.467569,1.715123}, {14.705301,1.778693}, {14.939827,1.812740}, {31.167709,1.818595}, {31.385754,1.797970}, {31.591040,1.752925}, {31.780968,1.685829}, {31.953283,1.599316}, {32.106110,1.496241}, {32.237957,1.379628}, {32.347748,1.252623}, {32.434830,1.118445}, {32.498955,0.980326}, {32.540302,0.841469}, {32.559448,0.704992}, {32.557365,0.573883}, {32.535389,0.450950}, {32.495201,0.338784}, {32.438789,0.239711}, {32.368423,0.155766}, {32.286598,0.088655}, {32.196014,0.039733}, {32.099499,0.009983}};

static GLUnurbsObj *nurbsObject; // Pointer to NURBS object.


float luzAmbiente[]={0.04f, 0.0f, 0.0f, 1.0f}; 
float luzDifusa[]={1.0f, 1.0f, 1.0f, 1.0f};  
float luzEspecular[]={1.0f, 1.0f, 1.0f, 1.0f};
float posicaoLuz[]={0.0f, 5.0f, 5.0f, 0.0f};  



/*float luzAmbiente_spot[]={0.04f, 0.0f, 0.0f, 1.0f}; 
float luzDifusa_spot[]={1.0f, 1.0f, 1.0f, 1.0f};  
float luzEspecular_spot[]={1.0f, 1.0f, 1.0f, 1.0f};*/
float posicaoLuz_spot[]={0.0f, -1.0f, 0.0f, 0.0f};  
float direcao_spot[]={0.0f, -1.0f, 0.0f, 0.0f};  

using namespace std;

// Begin globals.
static int changeControls = 1; // If control points to be changed.
static int selectedControlPoint = 0; // Selected control point number.
static int selectedKnot = 0; // Selected knot number.
static long font = (long)GLUT_BITMAP_8_BY_13; // Font selection.
static int animateMode = 0; // In animation mode?
static int animationPeriod = 1000; // Time interval between frames.
// Control points.

static float controlPoints[40][3] =
{

       {10.000000, 0.000000, 0.0},
    {10.000000, 15.000000, 0.0},
    {-10.000000, 15.000000, 0.0},
    {-10.000000, -10.000000, 0.0},
    {20.000000, -10.000000, 0.0},
    {20.000000, 25.000000, 0.0},
    {-20.000000, 25.000000, 0.0},
    {-20.000000, -20.000000, 0.0},
    {30.000000, -20.000000, 0.0},
    {30.000000, 35.000000, 0.0},
    {-30.000000, 35.000000, 0.0},
    {-30.000000, -30.000000, 0.0},
    {40.000000, -30.000000, 0.0},
    {40.000000, 45.000000, 0.0},
    {-40.000000, 45.000000, 0.0},
    {-40.000000, -40.000000, 0.0},
    {50.000000, -40.000000, 0.0},
    {50.000000, 55.000000, 0.0},
    {-50.000000, 55.000000, 0.0},
    {-50.000000, -50.000000, 0.0},
    {60.000000, -50.000000, 0.0},
    {60.000000, 65.000000, 0.0},
    {-60.000000, 65.000000, 0.0},
    {-60.000000, -60.000000, 0.0},
    {70.000000, -60.000000, 0.0},
    {70.000000, 75.000000, 0.0},
    {-70.000000, 75.000000, 0.0},
    {-70.000000, -70.000000, 0.0},
    {80.000000, -70.000000, 0.0},
    {80.000000, 85.000000, 0.0},
    {-80.000000, 85.000000, 0.0},
    {-80.000000, -80.000000, 0.0},
    {90.000000, -80.000000, 0.0},
    {90.000000, 95.000000, 0.0},
    {-90.000000, 95.000000, 0.0},
    {-90.000000, -90.000000, 0.0},
    {100.000000, -90.000000, 0.0},
    {100.000000, 105.000000, 0.0},
    {-100.000000, 105.000000, 0.0},

};

// Control point values stored unchanged for use on reset.
static float originalControlPoints[40][3] =
{
    {10.000000, 0.000000, 0.0},
    {10.000000, 15.000000, 0.0},
    {-10.000000, 15.000000, 0.0},
    {-10.000000, -10.000000, 0.0},
    {20.000000, -10.000000, 0.0},
    {20.000000, 25.000000, 0.0},
    {-20.000000, 25.000000, 0.0},
    {-20.000000, -20.000000, 0.0},
    {30.000000, -20.000000, 0.0},
    {30.000000, 35.000000, 0.0},
    {-30.000000, 35.000000, 0.0},
    {-30.000000, -30.000000, 0.0},
    {40.000000, -30.000000, 0.0},
    {40.000000, 45.000000, 0.0},
    {-40.000000, 45.000000, 0.0},
    {-40.000000, -40.000000, 0.0},
    {50.000000, -40.000000, 0.0},
    {50.000000, 55.000000, 0.0},
    {-50.000000, 55.000000, 0.0},
    {-50.000000, -50.000000, 0.0},
    {60.000000, -50.000000, 0.0},
    {60.000000, 65.000000, 0.0},
    {-60.000000, 65.000000, 0.0},
    {-60.000000, -60.000000, 0.0},
    {70.000000, -60.000000, 0.0},
    {70.000000, 75.000000, 0.0},
    {-70.000000, 75.000000, 0.0},
    {-70.000000, -70.000000, 0.0},
    {80.000000, -70.000000, 0.0},
    {80.000000, 85.000000, 0.0},
    {-80.000000, 85.000000, 0.0},
    {-80.000000, -80.000000, 0.0},
    {90.000000, -80.000000, 0.0},
    {90.000000, 95.000000, 0.0},
    {-90.000000, 95.000000, 0.0},
    {-90.000000, -90.000000, 0.0},
    {100.000000, -90.00000, 0.0},
    {100.000000, 105.000000, 0.0},
    {-100.000000, 105.000000, 0.0},



};

static float knots[20] ={0.0, 6.0, 12.0, 18.0, 24.0, 30.0, 36.0, 42.0, 48.0, 54.0, 60.0, 66.0, 72.0, 78, 84, 90, 96, 102, 108};

struct BitMapFile
{
   int sizeX;
   int sizeY;
   unsigned char *data;
};

// Routine to read a bitmap file.
// Works only for uncompressed bmp files of 24-bit color.
BitMapFile *getBMPData(string filename)
{
   BitMapFile *bmp = new BitMapFile;
   unsigned int size, offset, headerSize;
  
   // Read input file name.
   ifstream infile(filename.c_str(), ios::binary);
 
   // Get the starting point of the image data.
   infile.seekg(10);
   infile.read((char *) &offset, 4); 
   
   // Get the header size of the bitmap.
   infile.read((char *) &headerSize,4);

   // Get width and height values in the bitmap header.
   infile.seekg(18);
   infile.read( (char *) &bmp->sizeX, 4);
   infile.read( (char *) &bmp->sizeY, 4);

   // Allocate buffer for the image.
   size = bmp->sizeX * bmp->sizeY * 24;
   bmp->data = new unsigned char[size];

   // Read bitmap data.
   infile.seekg(offset);
   infile.read((char *) bmp->data , size);
   
   // Reverse color from bgr to rgb.
   int temp;
   for (int i = 0; i < size; i += 3)
   { 
      temp = bmp->data[i];
	  bmp->data[i] = bmp->data[i+2];
	  bmp->data[i+2] = temp;
   }

   return bmp;
}

// Load external textures.
void loadExternalTextures()			
{
   BitMapFile *image[15];

   image[0] = getBMPData("texturas/sun.bmp");
   image[1] = getBMPData("texturas/Galáxia2.bmp");
   image[2] = getBMPData("texturas/jupter2.bmp");
   image[3] = getBMPData("texturas/marte.bmp");
  // image[4] = getBMPData("texturas/mercurio.bmp");
   image[5] = getBMPData("texturas/neturno.bmp");
   image[6] = getBMPData("texturas/saturno.bmp");
   image[7] = getBMPData("texturas/terra.bmp");
   image[8] = getBMPData("texturas/venus.bmp");
   image[9] = getBMPData("texturas/aneis.bmp");
   image[10] = getBMPData("texturas/lua.bmp");
//   image[11] = getBMPData("texturas/cone22.bmp");
   image[12] = getBMPData("texturas/disco3.bmp");

   
   glBindTexture(GL_TEXTURE_2D, texture[0]); 
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
   glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_NEAREST);
   glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_NEAREST);
   glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, image[0]->sizeX, image[0]->sizeY, 0, 
	            GL_RGB, GL_UNSIGNED_BYTE, image[0]->data);			

   glBindTexture(GL_TEXTURE_2D, texture[1]); 
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
   glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_NEAREST);
   glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_NEAREST);
   glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, image[1]->sizeX, image[1]->sizeY, 0, 
	            GL_RGB, GL_UNSIGNED_BYTE, image[1]->data);

   glBindTexture(GL_TEXTURE_2D, texture[2]); 
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
   glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_NEAREST);
   glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_NEAREST);
   glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, image[2]->sizeX, image[2]->sizeY, 0, 
	            GL_RGB, GL_UNSIGNED_BYTE, image[2]->data);

   glBindTexture(GL_TEXTURE_2D, texture[3]); 
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
   glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_NEAREST);
   glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_NEAREST);
   glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, image[3]->sizeX, image[3]->sizeY, 0, 
	            GL_RGB, GL_UNSIGNED_BYTE, image[3]->data);

 /*  glBindTexture(GL_TEXTURE_2D, texture[4]); 
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
   glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_NEAREST);
   glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_NEAREST);
   glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, image[4]->sizeX, image[4]->sizeY, 0, 
	            GL_RGB, GL_UNSIGNED_BYTE, image[4]->data);
*/
   
   glBindTexture(GL_TEXTURE_2D, texture[5]); 
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
   glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_NEAREST);
   glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_NEAREST);
   glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, image[5]->sizeX, image[5]->sizeY, 0, 
	            GL_RGB, GL_UNSIGNED_BYTE, image[5]->data);
   
   glBindTexture(GL_TEXTURE_2D, texture[6]); 
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
   glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_NEAREST);
   glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_NEAREST);
   glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, image[6]->sizeX, image[6]->sizeY, 0, 
	            GL_RGB, GL_UNSIGNED_BYTE, image[6]->data);

   glBindTexture(GL_TEXTURE_2D, texture[7]); 
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
   glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_NEAREST);
   glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_NEAREST);
   glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, image[7]->sizeX, image[7]->sizeY, 0, 
	            GL_RGB, GL_UNSIGNED_BYTE, image[7]->data);

   glBindTexture(GL_TEXTURE_2D, texture[8]); 
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
   glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_NEAREST);
   glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_NEAREST);
   glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, image[8]->sizeX, image[8]->sizeY, 0, 
	            GL_RGB, GL_UNSIGNED_BYTE, image[8]->data);

   glBindTexture(GL_TEXTURE_2D, texture[9]); 
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
   glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_NEAREST);
   glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_NEAREST);
   glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, image[9]->sizeX, image[9]->sizeY, 0, 
	            GL_RGB, GL_UNSIGNED_BYTE, image[9]->data);

   glBindTexture(GL_TEXTURE_2D, texture[10]); 
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
   glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_NEAREST);
   glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_NEAREST);
   glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, image[10]->sizeX, image[10]->sizeY, 0, 
	            GL_RGB, GL_UNSIGNED_BYTE, image[10]->data);
/*
   glBindTexture(GL_TEXTURE_2D, texture[11]); 
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
   glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_NEAREST);
   glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_NEAREST);
   glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, image[11]->sizeX, image[11]->sizeY, 0, 
	            GL_RGB, GL_UNSIGNED_BYTE, image[11]->data);
*/
   glBindTexture(GL_TEXTURE_2D, texture[12]); 
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
   glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_NEAREST);
   glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_NEAREST);
   glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, image[12]->sizeX, image[12]->sizeY, 0, 
	            GL_RGB, GL_UNSIGNED_BYTE, image[12]->data);

}


void init(void){
   glClearColor (0.0, 0.0, 0.0, 0.0);
   glShadeModel (GL_FLAT);


	glLightfv(GL_LIGHT1, GL_POSITION, posicaoLuz_spot);   
	glLightf(GL_LIGHT1, GL_SPOT_CUTOFF, 30.0 );   
	glLightfv(GL_LIGHT1, GL_SPOT_DIRECTION, direcao_spot);   



	// Define os parâmetros da luz de número 0
	glLightfv(GL_LIGHT0, GL_AMBIENT, luzAmbiente); 
	glLightfv(GL_LIGHT0, GL_DIFFUSE, luzDifusa);
	glLightfv(GL_LIGHT0, GL_SPECULAR, luzEspecular);
	glLightfv(GL_LIGHT0, GL_POSITION, posicaoLuz);   
	
	glEnable(GL_LIGHTING);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LIGHT1);
   glEnable(GL_LIGHT0);
}

void setup(void)
{
   glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
   glClearColor(0.0, 0.0, 0.0, 0.0);

   // Create NURBS object.
   nurbsObject = gluNewNurbsRenderer();
   gluNurbsProperty(nurbsObject, GLU_SAMPLING_METHOD, GLU_PATH_LENGTH);
   gluNurbsProperty(nurbsObject, GLU_SAMPLING_TOLERANCE, 10.0);
  
   qobj = gluNewQuadric();
   gluQuadricDrawStyle(qobj, GLU_FILL);
   gluQuadricNormals (qobj, GLU_SMOOTH);
   gluQuadricTexture (qobj, GL_TRUE);

   qobj_ASS = gluNewQuadric();
   gluQuadricDrawStyle(qobj_ASS, GLU_FILL);
   gluQuadricNormals (qobj_ASS, GLU_SMOOTH);
   gluQuadricTexture (qobj_ASS, GL_TRUE);

   qobj_mercurio = gluNewQuadric();
   gluQuadricDrawStyle(qobj_mercurio, GLU_FILL);
   gluQuadricNormals (qobj_mercurio, GLU_SMOOTH);
   gluQuadricTexture (qobj_mercurio, GL_TRUE);

   qobj_lua = gluNewQuadric();
   gluQuadricDrawStyle(qobj_lua, GLU_FILL);
   gluQuadricNormals (qobj_lua, GLU_SMOOTH);
   gluQuadricTexture (qobj_lua, GL_TRUE);

   qobj_Venus = gluNewQuadric();
   gluQuadricDrawStyle(qobj_Venus, GLU_FILL);
   gluQuadricNormals (qobj_Venus, GLU_SMOOTH);
   gluQuadricTexture (qobj_Venus, GL_TRUE);

   qobj_terra = gluNewQuadric();
   gluQuadricDrawStyle(qobj_terra, GLU_FILL);
   gluQuadricNormals (qobj_terra, GLU_SMOOTH);
   gluQuadricTexture (qobj_terra, GL_TRUE);

   qobj_marte = gluNewQuadric();
   gluQuadricDrawStyle(qobj_marte, GLU_FILL);
   gluQuadricNormals (qobj_marte, GLU_SMOOTH);
   gluQuadricTexture (qobj_marte, GL_TRUE);

   qobj_jupter = gluNewQuadric();
   gluQuadricDrawStyle(qobj_jupter, GLU_FILL);
   gluQuadricNormals (qobj_jupter, GLU_SMOOTH);
   gluQuadricTexture (qobj_jupter, GL_TRUE);

   qobj_saturno = gluNewQuadric();
   gluQuadricDrawStyle(qobj_saturno, GLU_FILL);
   gluQuadricNormals (qobj_saturno, GLU_SMOOTH);
   gluQuadricTexture (qobj_saturno, GL_TRUE);

   qobj_urano = gluNewQuadric();
   gluQuadricDrawStyle(qobj_urano, GLU_FILL);
   gluQuadricNormals (qobj_urano, GLU_SMOOTH);
   gluQuadricTexture (qobj_urano, GL_TRUE);

   qobj_neturno = gluNewQuadric();
   gluQuadricDrawStyle(qobj_neturno, GLU_FILL);
   gluQuadricNormals (qobj_neturno, GLU_SMOOTH);
   gluQuadricTexture (qobj_neturno, GL_TRUE);

   qobj_cone = gluNewQuadric();
   gluQuadricDrawStyle(qobj_cone, GLU_FILL);
   gluQuadricNormals (qobj_cone, GLU_SMOOTH);
   gluQuadricTexture (qobj_cone, GL_TRUE);

   qobj_disco = gluNewQuadric();
   gluQuadricDrawStyle(qobj_disco, GLU_FILL);
   gluQuadricNormals (qobj_disco, GLU_SMOOTH);
   gluQuadricTexture (qobj_disco, GL_TRUE);

   qobj_disco_saturno = gluNewQuadric();
   gluQuadricDrawStyle(qobj_disco_saturno, GLU_FILL);
   gluQuadricNormals (qobj_disco_saturno, GLU_SMOOTH);
   gluQuadricTexture (qobj_disco_saturno, GL_TRUE);

   qobj_esfera_buraco = gluNewQuadric();
   gluQuadricDrawStyle(qobj_esfera_buraco, GLU_FILL);
   gluQuadricNormals (qobj_esfera_buraco, GLU_SMOOTH);
   gluQuadricTexture (qobj_esfera_buraco, GL_TRUE);

   glEnable(GL_DEPTH_TEST); // Enable depth testing.

   // Create texture index array.
   glGenTextures(15, texture);

   // Load external textures.
   loadExternalTextures();

   // Turn on OpenGL texturing.
   glEnable(GL_TEXTURE_2D); 

   // Specify how texture values combine with current surface color values.
   glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE); 
   glEnable(GL_CULL_FACE);
   glCullFace(GL_BACK);
}

void increaseKnot(int i)
{
   if ( (i < 19) )
   {
      if (knots[i] < knots[i+1]) knots[i] += 1.0;
	  else
	  {
	     increaseKnot(i+1);
	     if (knots[i] < knots[i+1]) knots[i] += 1.0;
	  }
   }
   if ( (i == 19 )  && ( knots[i] < 120.0) )    knots[i] += 1.0;
}

// Function to decrease value of a knot.
void decreaseKnot(int i)
{
   if ( (i > 0) )
   {
      if (knots[i] > knots[i-1]) knots[i] -= 1.0;
	  else
	  {
	     decreaseKnot(i-1);
		 if (knots[i] > knots[i-1]) knots[i] -= 1.0;
	  }
   }
   if ( (i == 0 )  && ( knots[i] > 0.0) )    knots[i] -= 1.0;
}

// Reset knot values.
void resetKnots(void)
{
   int i;
   for (i = 0; i < 20; i++) knots[i] = 6.0*i;
   selectedKnot = 0;
}

// Reset control points.
void resetControlPoints(void)
{
   int i,j;
   for (i = 0; i < 40; i++) for (j = 0; j < 3; j++) controlPoints[i][j] = originalControlPoints[i][j];
   selectedControlPoint = 0;
}

// Recursive computation of B-spline functions.
float Bspline(int i, int m, float u)
{
   float coef1, coef2;
   if ( m == 1 )
   {
	  if ( i == 0 ) if ( ( knots[i] <= u ) && ( u <= knots[i+1] ) ) return 1.0;
      if ( ( knots[i] < u ) && ( u <= knots[i+1] ) ) return 1.0;
	  else return 0.0;
   }
   else
   {
      if ( knots[i+m-1] == knots[i] )
	  {
	     if ( u == knots[i] ) coef1 = 1;
		 else coef1 = 0;
	  }
	  else coef1 = (u - knots[i])/(knots[i+m-1] - knots[i]);

      if ( knots[i+m] == knots[i+1] )
	  {
		 if ( u == knots[i+m] ) coef2 = 1;
		 else coef2 = 0;
	  }
	  else coef2 = (knots[i+m] - u)/(knots[i+m] - knots[i+1]);

      return ( coef1 * Bspline(i, m-1, u) + coef2 * Bspline(i+1 ,m-1 ,u) );
   }
}


// Drawing routine.
void dicoburaco()
{
   int i, j;

   glRotatef(rotDisco,0,0,1);
   glPushMatrix();
   glRotated(0, 0,0,1);
   glColor3f(1.0,1.0, 1.0);
   gluBeginCurve(nurbsObject);
   gluNurbsCurve(nurbsObject, 19, knots, 3, controlPoints[0], 4, GL_MAP1_VERTEX_3);
   gluEndCurve(nurbsObject);

   glPopMatrix();

   glPushMatrix();

   glRotated(36, 0,0,1);
   glColor3f(1.0,1.0, 1.0);
   gluBeginCurve(nurbsObject);
   gluNurbsCurve(nurbsObject, 19, knots, 3, controlPoints[0], 4, GL_MAP1_VERTEX_3);
   gluEndCurve(nurbsObject);

   glPopMatrix();

   glPushMatrix();

   glRotated(72, 0,0,1);
   glColor3f(1.0,1.0, 1.0);
   gluBeginCurve(nurbsObject);
   gluNurbsCurve(nurbsObject, 19, knots, 3, controlPoints[0], 4, GL_MAP1_VERTEX_3);
   gluEndCurve(nurbsObject);

   glPopMatrix();

   glPushMatrix();

   glRotated(108, 0,0,1);
   glColor3f(1.0,1.0, 1.0);
   gluBeginCurve(nurbsObject);
   gluNurbsCurve(nurbsObject, 19, knots, 3, controlPoints[0], 4, GL_MAP1_VERTEX_3);
   gluEndCurve(nurbsObject);

   glPopMatrix();
   glPushMatrix();

   glRotated(144, 0,0,1);
   glColor3f(1.0,1.0, 1.0);
   gluBeginCurve(nurbsObject);
   gluNurbsCurve(nurbsObject, 19, knots, 3, controlPoints[0], 4, GL_MAP1_VERTEX_3);
   gluEndCurve(nurbsObject);

   glPopMatrix();

   glPushMatrix();

   glRotated(180, 0,0,1);
   glColor3f(1.0,1.0, 1.0);
   gluBeginCurve(nurbsObject);
   gluNurbsCurve(nurbsObject, 19, knots, 3, controlPoints[0], 4, GL_MAP1_VERTEX_3);
   gluEndCurve(nurbsObject);

   glPopMatrix();
   glPushMatrix();

   glRotated(216, 0,0,1);
   glColor3f(1.0,1.0, 1.0);
   gluBeginCurve(nurbsObject);
   gluNurbsCurve(nurbsObject, 19, knots, 3, controlPoints[0], 4, GL_MAP1_VERTEX_3);
   gluEndCurve(nurbsObject);

   glPopMatrix();
   glPushMatrix();

   glRotated(252, 0,0,1);
   glColor3f(1.0,1.0, 1.0);
   gluBeginCurve(nurbsObject);
   gluNurbsCurve(nurbsObject, 19, knots, 3, controlPoints[0], 4, GL_MAP1_VERTEX_3);
   gluEndCurve(nurbsObject);

   glPopMatrix();

   glPushMatrix();

   glRotated(288, 0,0,1);
   glColor3f(1.0,1.0, 1.0);
   gluBeginCurve(nurbsObject);
   gluNurbsCurve(nurbsObject, 19, knots, 3, controlPoints[0], 4, GL_MAP1_VERTEX_3);
   gluEndCurve(nurbsObject);

   glPopMatrix();

   glPushMatrix();
   glRotated(324, 0,0,1);
   glColor3f(1.0,1.0, 1.0);
   gluBeginCurve(nurbsObject);
   gluNurbsCurve(nurbsObject, 19, knots, 3, controlPoints[0], 4, GL_MAP1_VERTEX_3);
   gluEndCurve(nurbsObject);

   glPopMatrix();

}

void desenhasistema(){


   gluQuadricDrawStyle(qobj, GLU_FILL);
    
  
   glPushMatrix();
   glTranslatef(espX,espY,espZ);
    
    if(controle==8){
       glTranslatef(5,0,0);
       glRotatef(25, 1, 0, 0);   
       glRotatef(lateral, 0, 1, 0);
       glTranslatef(-engolida,0,0);  
    }
   glPushMatrix();
   if(engolida>0.5){
   	if(engolida>=4.5){
                glBindTexture(GL_TEXTURE_2D, texture[0]);
   		gluSphere(qobj, 4/4, 100,100);   /* Sol*/
   	}else{
   		glBindTexture(GL_TEXTURE_2D, texture[0]);
   		gluSphere(qobj, engolida/4, 100,100);   /* Sol*/
	}
   }
   
   glPopMatrix();


   glPushMatrix();
   glRotatef ((GLfloat) mercurio, 0.0, 1.0, 0.0);
   glRotatef ((GLfloat) mercurio, 1.0, 0.0, 0.0);
   glTranslatef (6.0/4, 0.0, 0.0);/*Mercurio*/
   if(engolida>0.8){
        //glBindTexture(GL_TEXTURE_2D, texture[4]);
   	gluSphere(qobj_mercurio, 0.013/4, 100,100);
   }
   glPopMatrix();

   glPushMatrix();
   glRotatef ((GLfloat) Venus, 0.0, 1.0, 0.0);
   glRotatef ((GLfloat) Venus, 1.0, 0.0, 0.0);
   glTranslatef (7.0/4, 0.0, 0.0);/*Venus*/
   if(engolida>0.8){
	   glBindTexture(GL_TEXTURE_2D, texture[8]);
   	gluSphere(qobj_Venus, 0.033/4, 100,100);
   }
   glPopMatrix();

   glPushMatrix();
   glRotatef ((GLfloat) terra, 0.0, 1.0, 0.0);
   glRotatef ((GLfloat) terra, 1.0, 0.0, 0.0);
   glTranslatef (8.0/4, 0.0, 0.0);/*Terra*/
   if(engolida>0.8){
           glBindTexture(GL_TEXTURE_2D, texture[7]);
	   gluSphere(qobj_terra, 0.0351/4, 100,100);
   }
   glPushMatrix();
   glRotatef ((GLfloat) lua, 0.0, 1.0, 0.0);
   glTranslatef (0.5/4, 0.0, 0.0);/*lua*/
   if(engolida>0.9){
   	glBindTexture(GL_TEXTURE_2D, texture[10]);
   	gluSphere(qobj_lua, 0.0091/4, 100,100);
   }
   glPopMatrix();

   glPopMatrix();

   glPushMatrix();
   glRotatef ((GLfloat) marte, 0.0, 1.0, 0.0);
   glRotatef ((GLfloat) marte, 1.0, 0.0, 0.0);
   glTranslatef (9.0/4, 0.0, 0.0);/*Marte*/
   if(engolida>1){
	   glBindTexture(GL_TEXTURE_2D, texture[3]); 
	   gluSphere(qobj_marte, 0.0182/4, 100,100);
   }
   glPopMatrix();

   glPushMatrix();
   glRotatef ((GLfloat) jupter, 0.0, 1.0, 0.0);
   glRotatef ((GLfloat) jupter, 1.0, 0.0, 0.0);
   glTranslatef (10.0/4, 0.0, 0.0);/*Jupiter*/
   if(engolida>1){
	   glBindTexture(GL_TEXTURE_2D, texture[2]);
	   gluSphere(qobj_jupter, 0.4/4, 100,100);
   }
   glPopMatrix();

   glPushMatrix();

   glPushMatrix();
   glRotatef ((GLfloat) saturno, 0.0, 1.0, 0.0);
   glTranslatef (12.0/4, 0.0, 0.0);/*Saturno*/
   glRotatef (90, 1.0, 0.0, 0.0);
   if(engolida>1){
	glBindTexture(GL_TEXTURE_2D, texture[9]);
   	gluDisk(qobj_disco_saturno,0.04/4,0.5/4,100,100);
   }
   glPopMatrix();

   glRotatef ((GLfloat) saturno, 0.0, 1.0, 0.0);
   glRotatef ((GLfloat) saturno, 1.0, 0.0, 0.0);
   glTranslatef (12.0/4, 0.0, 0.0);/*Saturno*/
   if(engolida>1){
  	glBindTexture(GL_TEXTURE_2D, texture[6]);
   	gluSphere(qobj_saturno, 0.325/4, 100,100);
   }
   glPushMatrix();
   glRotatef ((GLfloat) lua, 0.0, 1.0, 0.0);
   glTranslatef (0.8/4, 0.0, 0.0);/*lua*/
   if(engolida>1){
           glBindTexture(GL_TEXTURE_2D, texture[10]);
	   gluSphere(qobj_lua, 0.0091/4, 100,100);
   }
   glPopMatrix();

   glPushMatrix();
   glRotatef ((GLfloat) lua, 0.0, 1.0, 0.0);
   glTranslatef (-0.8/4, 0.0, 0.0);/*lua*/
   if(engolida>1){
          glBindTexture(GL_TEXTURE_2D, texture[10]);
 	  gluSphere(qobj_lua, 0.0091/4, 100,100);
   }
   glPopMatrix();

   glPopMatrix();

   glPushMatrix();
   glRotatef ((GLfloat) urano, 0.0, 1.0, 0.0);
   glRotatef ((GLfloat) urano, 1.0, 0.0, 0.0);
   glTranslatef (14/4, 0.0, 0.0);/*Urano*/
   if(engolida>1){
	   gluSphere(qobj, 0.1391/4, 100,100);
   }
   glPopMatrix();

   glPushMatrix();
   glRotatef ((GLfloat) neturno, 0.0, 1.0, 0.0);
   glRotatef ((GLfloat) neturno, 1.0, 0.0, 0.0);
   glTranslatef (15/4, 0.0, 0.0);/*neturno*/
   if(engolida>1){
	   glBindTexture(GL_TEXTURE_2D, texture[5]); 
	   gluSphere(qobj_neturno, 0.1339/4, 100,100);
   }
   glPopMatrix();
   glPopMatrix();

}

void desenhaburaco(){

  glDisable(GL_TEXTURE_2D);
	GLfloat fogColor[4]={1.0,0.4,0.4,1};

   glPushMatrix();
   glTranslatef (16.0, 0.0, 3);
   glTranslatef (0, 0, 3);
 
   glPushMatrix();
   glEnable(GL_FOG);
   fogMode = GL_EXP2;
   glFogi(GL_FOG_MODE, fogMode);
   glFogfv(GL_FOG_COLOR, fogColor);
   glFogf(GL_FOG_DENSITY, 0.5);
   glHint(GL_FOG_HINT, GL_DONT_CARE);
   glFogf(GL_FOG_START, 1);
   glFogf(GL_FOG_END, 5);
   glRotatef (cone, 0.0, 1.0, 0.0);
   glRotatef(90,1,0,0);
   glColor4f(1,1,1,0);
   gluCylinder(qobj, 0.1, 0.2, cone_alt, 15, 15);//cilindro inferior
   glDisable(GL_FOG);
   glPopMatrix();

   glPushMatrix();
   glEnable(GL_FOG);
   fogMode = GL_EXP2;
   glFogi(GL_FOG_MODE, fogMode);
   glFogfv(GL_FOG_COLOR, fogColor);
   glFogf(GL_FOG_DENSITY, 0.5);
   glHint(GL_FOG_HINT, GL_DONT_CARE);
   glFogf(GL_FOG_START, 1);
   glFogf(GL_FOG_END, 5);
   glRotatef (cone, 0.0, 1.0, 0.0);
   glRotatef(90,1,0,0);
   glRotatef(180,1,0,0);
   glColor4f(1,1,1,0);
   gluCylinder(qobj, 0.1, 0.2, cone_alt, 15, 15);//cilindro inferior
   glDisable(GL_FOG);
   glPopMatrix();

   glPushMatrix();
   glColor3f (0.0/255, 0.0/255, 0/255);//esfera central
   gluSphere(qobj,1.1,100,100);
   glPopMatrix();

   glPushMatrix();
   glColor3f (0.41, 0.055, 0);
   glRotatef (cone, 0.0, 1.0, 0.0);
   glRotatef(115,1,0,0);
   glScalef(0.15,0.15,0.15);
   		glEnable(GL_TEXTURE_2D);
   if((controle>7)&&(engolida>0)){
	    glBindTexture(GL_TEXTURE_2D, texture[12]);
	   	gluDisk(qobj_ASS,5, 30,100,100);
	    dicoburaco();
	}
   glPopMatrix();
   gluQuadricDrawStyle(qobj, GLU_FILL);

   glPopMatrix();

}

void display(void){
   glClear (GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

   glPushMatrix();
   glRotatef(rotsistema,1,0,0);
   glTranslatef (cameraX, cameraY, cameraZ);
   glRotatef (cameraRotaca, 1.0, 0.0, 0.0);

   glPushMatrix();
   glBindTexture(GL_TEXTURE_2D, texture[1]);        

   glBegin(GL_POLYGON);
      glTexCoord2f(0.0, 0.0); glVertex3f(-110.0, -50.0, -82.0);
      glTexCoord2f(1.0, 0.0); glVertex3f(110.0, -50.0, -82.0);
      glTexCoord2f(1.0, 1.0); glVertex3f(110.0, 50.0, -82.0);
      glTexCoord2f(0.0, 1.0); glVertex3f(-110.0, 50.0, -82.0);
   glEnd();   

   glBegin(GL_POLYGON);
      glTexCoord2f(0.0, 0.0); glVertex3f(-110.0, -50.0, 82.0);
      glTexCoord2f(1.0, 0.0); glVertex3f(110.0, -50.0, 82.0);
      glTexCoord2f(1.0, 1.0); glVertex3f(110.0, -50.0, -82.0);
      glTexCoord2f(0.0, 1.0); glVertex3f(-110.0, -50.0, -82.0);
   glEnd();   

   glBegin(GL_POLYGON);
      glTexCoord2f(0.0, 0.0); glVertex3f(-110.0, 50.0, -82.0);
      glTexCoord2f(1.0, 0.0); glVertex3f(110.0, 50.0, -82.0);
      glTexCoord2f(1.0, 1.0); glVertex3f(110.0, 50.0, 82.0);
      glTexCoord2f(0.0, 1.0); glVertex3f(-110.0, 50.0, 82.0);
   glEnd();   

   glBegin(GL_POLYGON);
      glTexCoord2f(0.0, 0.0); glVertex3f(-110.0, 50.0, 82.0);
      glTexCoord2f(1.0, 0.0); glVertex3f(110.0, 50.0, 82.0);
      glTexCoord2f(1.0, 1.0); glVertex3f(110.0, -50.0, 82.0);
      glTexCoord2f(0.0, 1.0); glVertex3f(-110.0, -50.0, 82.0);
   glEnd();   


   glPopMatrix();

   desenhaburaco();

   desenhasistema();

   glPopMatrix();

   glutSwapBuffers();
}

void reshape (int w, int h){
   glViewport (0, 0, (GLsizei) w, (GLsizei) h);
   glMatrixMode (GL_PROJECTION);
   glLoadIdentity ();
   gluPerspective(60.0, (GLfloat) w/(GLfloat) h, 1.0, 100.0);
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
   gluLookAt (0.0, 0.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
}

void keyboard (unsigned char key, int x, int y){
   switch (key) {
    break;
      case ' ':
        controle++;
        glutPostRedisplay();
      break;
      case 27:
         exit(0);
         break;
      default:
         break;
   }
}

void gira(){
    if(controle<2){
        if(terra==90)
            controle++;
        cameraRotaca=terra;
    }else if (controle == 3){
        if(cameraRotaca==180)
            controle++;
        cameraRotaca+=1.25;
    }else if(controle==4){
        cameraZ-=0.01;
        if(cameraZ<-8)
            controle++;
    }else if(controle ==5){
        cameraX-=0.01;
        if(cameraX<2){
            controle++;
        }
    }else if(controle==6){
        escala-=0.0001;
        espX+=0.01;
        cameraX-=0.007;
        if(espX>10){
            controle++;
        }
    }else if(controle==7){
    	
    	controle++;
    }else if(controle==8){
         
      if(lateral < 359)
     	lateral = lateral + 10;
     else
     	lateral = 0;

     if(engolida > 0){
      engolida -= 0.01;
     }
     if(engolida < 1.0)
     cone_alt += 0.5;
    }
    if(engolida < 0.2){
    	cone_alt = 0;
    }
     if(rotDisco<359)
        rotDisco = rotDisco - 2;
     else
        rotDisco=0;
     if(mercurio<359)
        mercurio = mercurio + 2;
     else
        mercurio=0;
     if(Venus<359)
        Venus = Venus + 1.48;
     else
        Venus=0;
     if(terra <359)
        terra=terra+1.25;
     else
        terra = 0;
    if(lua <359)
        lua=lua+5;
     else
        lua=0;
     if(marte<359)
        marte = marte + 1;
     else
        marte=0;
     if(jupter<359)
        jupter = jupter + 0.55;
     else
        jupter=0;
     if(saturno<359)
        saturno = saturno + 0.38;
     else
        saturno =0;
     if(urano<359)
        urano = urano + 0.29;
     else
        urano =0;
     if(neturno<359)
        neturno = neturno + 0.2;
     else
      neturno = 0;
    if(cone<359)
        cone = cone + 700;
     else
        cone=0;
     



     glutPostRedisplay();
}
int main(int argc, char** argv){
   glutInit(&argc, argv);
   glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
   glutInitWindowSize (500, 500);
   glutInitWindowPosition (100, 100);
   glutCreateWindow (argv[0]);
   setup();
   init ();
   glutDisplayFunc(display);
   glutReshapeFunc(reshape);
   glutKeyboardFunc(keyboard);

   glEnable(GL_NORMALIZE);
   glEnable(GL_COLOR_MATERIAL);
    
   glutIdleFunc(gira);
   glutMainLoop();
   return 0;
}
