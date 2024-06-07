#include "DibujarPiezas.h"
#include <math.h>

DibujarPiezas::DibujarPiezas(void)
{
}

DibujarPiezas::~DibujarPiezas(void)
{
}

void DibujarPiezas::dibujaPieza(int x, int y, const char* tex)
{
    glEnable(GL_TEXTURE_2D);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    GLuint textureId = ETSIDI::getTexture(tex).id;
    glBindTexture(GL_TEXTURE_2D, textureId);



    glDisable(GL_LIGHTING);
    glColor3f(1, 1, 1);
    glPushMatrix();

    
    glTranslatef(x - 3.5f, 0.3f, y - 5.6f); 

    glRotatef(-90, 1.0f, 0.0f, 0.0f);
    glRotatef(180, 0.0f, 1.0f, 0.0f);

    
    glBegin(GL_QUADS);
   
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-0.4f, -0.4f, 0.001f); 

   
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(0.4f, -0.4f, 0.001f); 

    
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(0.4f, 0.4f, 0.001f); 

   
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-0.4f, 0.4f, 0.001f); 
    glEnd();

    glPopMatrix();
    glDisable(GL_TEXTURE_2D);
    glDisable(GL_BLEND);
    glEnable(GL_LIGHTING);
}
