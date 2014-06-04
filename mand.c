#include <stdio.h>
#include <bmpfile.h>

#define HEIGHT 4000
#define WIDTH 6000
#define MAX_ITER 1000

rgb_pixel_t palette[256] = {{0, 0, 0, 0}};
rgb_pixel_t data[WIDTH][HEIGHT];
	
void init_palette()
{
	int i = 20;
	int red, green, blue;
	const rgb_pixel_t black = {0, 0, 0, 0};
	const rgb_pixel_t white = {255,255,255, 0};
	
	palette[0] = white;
	palette[255] = black;

	for (red = 0; red <= 255; red += 51)
	{
		for (green = 0; green <= 255; green += 51)
		{
			for (blue = 0; blue <= 255; blue+= 51)
			{
				palette[i].red = red;
				palette[i].green = green;
				palette[i].blue = blue;
				++i;
			}
		}
	}
}

void mand()
{
	int px, py, iter;
	float x0, y0, x, y, xtemp;

	for(py = 0; py < HEIGHT; py++)
	{
		for(px = 0; px < WIDTH; px++)
		{
			x0 = -2.5f + ((px * 3.5) / WIDTH);
			y0 = -1.0f + ((py * 2.0) / HEIGHT);
			x = 0.0f;
			y = 0.0f;
			iter = 0;
			
			while(x*x + y*y < 2*2 && iter < MAX_ITER)
			{
				xtemp = x*x - y*y + x0;
				y = 2*x*y + y0;
				x = xtemp;
				iter++;
			}
			
			data[px][py] = palette[iter % 256];
		}
	}
}

void write_bmp()
{
	bmpfile_t *bmp;
	int w, h;

	if((bmp = bmp_create(WIDTH, HEIGHT, 24)) == NULL){
		printf("Failed to create bitmap.\n");
	}
	
	for(h = 0; h < HEIGHT; ++h)
	{
		for(w = 0; w < WIDTH; ++w)
		{
			bmp_set_pixel(bmp, w, h, data[w][h]);
		}
	}

	bmp_save(bmp, "out.bmp");
	bmp_destroy(bmp);
}

int main()
{
	init_palette();
	mand();
	write_bmp();
	
	return 0;
}
