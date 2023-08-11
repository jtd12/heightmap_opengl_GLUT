#include"gameSetup.hpp"



setup::setup()
{

car=new vehicule();
sky=new skybox();
cam=new camera();
loadHeightmap("data/heightmap.bmp",512,512);



}



setup::~setup()
{
delete car;
delete sky;
delete cam;
}

int setup::loadHeightmap(const char * name,int width, int height)
{
	tex=new textures();
//	tex=new textures();
	width_=width;
	height_=height;
	FILE *fp;
	fp=fopen(name,"rb");
	fread(hHeightField,1,width*height,fp);
	fclose(fp);
	
	texture=tex->loadBMP_custom("data/Grass_01_c.bmp");
	for(int mapX=0;mapX<width;mapX++)
	{
		for(int mapZ=0;mapZ<height;mapZ++)
		{
		//	printf("%d, %d, %d\n", mapX, mapZ, hHeightField[mapX][mapZ]);
		}
	}
	//	unsigned int pixel=((unsigned int*) pixels)[i*tex->images.dataPos/4 +j];
		
		return true;

	
	
}

void  setup::renderHeightMap(float size,float h)
{
	/*
	for(int i=0;i<heights.size()-1;i++)
	{
		for(int j=0;j<heights[0].size()-1;j++)
		{
			glBegin(GL_TRIANGLE_STRIP);
			glColor3f(heights[i][j],heights[i][j],heights[i][j]);
			glVertex3f(i*size,heights[i][j]*h,j*size);
			glVertex3f((i+1)*size,heights[i+1][j]*h,j*size);
			glVertex3f(i*size,heights[i][j+1]*h,(j+1)*size);
			glVertex3f((i+1)*size,heights[i+1][j+1]*h,(j+1)*size);
			glEnd();
			
		}
	}
	*/
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D,texture);
	
	
	for (int mapX = 0; mapX < width_; mapX++){
		for (int mapZ = 0; mapZ < height_; mapZ++){
			glBegin(GL_QUADS);
				glTexCoord2f((float)mapX / width_, (float)mapZ / height_);
				glVertex3f(mapX*size, hHeightField[mapX][mapZ]*h, mapZ*size);	
				
				glTexCoord2f((float)mapX / width_, (float)(mapZ + 1) / height_) ;
				glVertex3f((mapX + 1)*size, hHeightField[mapX][mapZ+1]*h, (mapZ + 1)*size);	
				
				glTexCoord2f((float)(mapX + 1) / width_, (float)mapZ / height_);
				glVertex3f((mapX + 1)*size, hHeightField[mapX + 1][mapZ]*h, mapZ*size);	
				
				glTexCoord2f((float)(mapX + 1) / width_, (float)(mapZ + 1) / height_);
				glVertex3f((mapX + 1)*size, hHeightField[mapX + 1][mapZ + 1]*h, (mapZ + 1)*size);
			glEnd();
		}
		}
		
		glDisable(GL_TEXTURE_2D);
	
}

void setup::mouseMove(int mx,int my)
{
	cam->control(mx,my);
}
void setup:: mouseState(int button, int state, int x, int y)
{
	cam->mouse( button,  state,  x,  y);
}
void setup::keyboard(unsigned char key, int x, int y)
{
	switch(key)
	{
		case 'c':
		case 'C': 
		car->ouvrirPorte1();
		glutPostRedisplay();
		break;
		
		case 'v':
		case 'V': 
		car->ouvrirPorte2();
		glutPostRedisplay();
		break;
		     
	}
}
void setup::specialKey(int key, int x, int y)
{
	switch(key)
	{
		case GLUT_KEY_UP:
		 if(cam->getPitch()!=90 && cam->getPitch()!=-90)
			cam->moveCamera(0);
		cam->moveCameraUp(180.0);
		glutPostRedisplay();
			break;
		case GLUT_KEY_DOWN:
		 if(cam->getPitch()!=90 && cam->getPitch()!=-90)
			cam->moveCamera(180);
		cam->moveCameraUp(0.0);
		glutPostRedisplay();
			break;
		case GLUT_KEY_RIGHT:
			cam->moveCamera(-90);
			glutPostRedisplay();
			break;
		case GLUT_KEY_LEFT:
			cam->moveCamera(90);
			glutPostRedisplay();
			break;	
			
	}
}
void setup::update()
{
	car->update();
	sky->update();
}
void setup::draw()
{
	glTranslated(-200,0,-200);
	cam->update();
	glPushMatrix();
	glRotated(sky->getRot(),0,0.5,0);
	sky->drawSkybox(10000);
	glPopMatrix();
	glPushMatrix();
	car->draw();
	glPopMatrix();
	glPushMatrix();
	glTranslated(-4000,-3000,-2000);
	renderHeightMap(10,9);
	glPopMatrix();
}
