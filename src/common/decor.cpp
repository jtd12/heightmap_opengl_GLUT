#include"decor.h"

decor::decor()
{
		obj=new objloader();
		sol=obj->load("data/decor.obj",NULL);
	
		
}
decor::~decor()
{
	delete obj;
}
void decor::update()
{

}
void decor::draw()
{
	glPushMatrix();	
	glCallList(sol);
	glPopMatrix();
}
