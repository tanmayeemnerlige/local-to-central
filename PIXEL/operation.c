#include <stdlib.h>
#include "header.h"


PiArray* initialize(int size)
{
    PiArray *buffer;
    buffer = (PiArray*) malloc (sizeof(PiArray));

    if(buffer == NULL)
    {
        buffer->status = FAIL;
        return buffer;
    }

    buffer->c_size = 0;
    buffer->t_size = size;

    buffer->point = (Pixel*) malloc (sizeof(Pixel)*size);

    if(buffer->point == NULL)
    {
        buffer->status = FAIL;
        return buffer;
    }

    buffer->status = SUCCESS;
    return buffer;
}
//___________________________________________________________________________

//PiArray* get_point(unsigned short int red, unsigned short int green, unsigned short int blue)
//{
//    PiArray *temp;
//
//    temp->point[c_] = red;
//    temp->green = green;
//    temp->blue = blue;
//    //temp->opac = opac;
//
//    return temp;
//}
//____________________________________________________________________________

int insert_pixel(PiArray* buffer, unsigned short int red, unsigned short int green, unsigned short int blue, float opac)
{
    if(buffer->c_size == buffer->t_size)  return FULL;

    buffer->point[buffer->c_size].red = red;
    buffer->point[buffer->c_size].blue = blue;
    buffer->point[buffer->c_size].green = green;
    buffer->point[buffer->c_size].opac = opac;

    buffer->c_size++;
    buffer->status = SUCCESS;

    return buffer->status;
}
//_____________________________________________________________________________

//COUNTING RED, GREEN AND BLUE IN DIFFERENT FUNCTIONS
//_____________________________________________________________________________

int count_red(PiArray* buffer)
{
    if(buffer->c_size == 0)  return FAIL;

    int count = 0;
    for(int i=0; i<buffer->c_size; i++)
    {
        if(buffer->point[i].red == 255 && buffer->point[i].green == 0 && buffer->point[i].blue == 0)
            count++;
    }

    return count;
}
//____________________________________________________________________________

int count_green(PiArray* buffer)
{
    if(buffer->c_size == 0)  return FAIL;

    int count = 0;
    for(int i=0; i<buffer->c_size; i++)
    {
        if(buffer->point[i].red == 0 && buffer->point[i].green == 255 && buffer->point[i].blue == 0)
            count++;
    }

    return count;
}
//____________________________________________________________________________

int count_blue(PiArray* buffer)
{
    if(buffer->c_size == 0)  return FAIL;

    int count = 0;
    for(int i=0; i<buffer->c_size; i++)
    {
        if(buffer->point[i].red == 0 && buffer->point[i].green == 0 && buffer->point[i].blue == 255)
            count++;
    }

    return count;
}
//____________________________________________________________________________

int reset_opac(PiArray* buffer, int position)
{
    if(buffer->c_size == 0)  return FAIL;

    buffer->point[position-1].opac = 0;
    buffer->status = SUCCESS;

    return buffer->status;
}
//____________________________________________________________________________

int set_opac(PiArray* buffer, int position)
{
    if(buffer->c_size == 0)  return FAIL;

    buffer->point[position-1].opac = 1;
    buffer->status = SUCCESS;

    return buffer->status;
}
//_______________________________________________________________________________________________________

//COUNTING RED, GREEN AND BLUE USING A SINGLE STRUCTURE
//_______________________________________________________________________________________________________

Count all_count(PiArray* buffer)
{
    Count c;
    c.red = 0;
    c.green = 0;
    c.blue = 0;

    if(buffer->c_size == 0)
    {
        c.number = FAIL;
        return c;
    }

    for(int i=0; i<buffer->c_size; i++)
    {
        if(buffer->point[i].red == 255 && buffer->point[i].green == 0 && buffer->point[i].blue == 0)
            c.red++;

        else if(buffer->point[i].red == 0 && buffer->point[i].green == 255 && buffer->point[i].blue == 0)
            c.green++;

        else if(buffer->point[i].red == 0 && buffer->point[i].green == 0 && buffer->point[i].blue == 255)
            c.blue++;
    }

    return c;
}
