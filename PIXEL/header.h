
#define FAIL -1
#define SUCCESS 1
#define FULL 9
#define INVALID 5

typedef struct _pixel_
{
    unsigned short int red, green, blue;
    float opac;
} Pixel;

typedef struct _array_
{
    Pixel *point;
    int c_size, t_size;
    int status;
} PiArray;

typedef struct _count_
{
    int red;
    int green;
    int blue;
    int number;
} Count;

PiArray* initialize(int );

//Pixel* get_point(unsigned short int, unsigned short int, unsigned short int);

int insert_pixel(PiArray* , unsigned short int , unsigned short int , unsigned short int, float );

int count_red(PiArray*);

int count_green(PiArray*);

int count_blue(PiArray*);

int reset_opac(PiArray* , int );

int set_opac(PiArray*, int);

Count all_count(PiArray* );  //to return count of RGB together
