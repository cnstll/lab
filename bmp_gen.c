#include <stdint.h> // for specific size integers
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>

typedef struct	s_header {
    char		*bitmapSignatureBytes;
    uint32_t	sizeOfBitmapFile;
    uint32_t	reservedBytes;
    uint32_t	pixelDataOffset;
}				t_header;

typedef	struct	s_info_header {
    uint32_t sizeOfThisHeader;
    int32_t width; // in pixels
    int32_t height; // in pixels
    uint16_t numberOfColorPlanes; // must be 1
    uint16_t colorDepth;
    uint32_t compressionMethod;
    uint32_t rawBitmapDataSize; // generally ignored
    int32_t horizontalResolution; // in pixel per meter
    int32_t verticalResolution; // in pixel per meter
    uint32_t colorTableEntries;
    uint32_t importantColors;
}				t_info_header;

typedef	struct	s_px {
    uint8_t blue;
    uint8_t green;
    uint8_t red;
}				t_px;

typedef struct	s_bmp {
	t_header		*header;
	t_info_header	*info_header;
	t_px			*px;
}				t_bmp;

void	init_bmp_header(t_bmp *bmp)
{
    bmp->header = malloc(sizeof(t_header));
    bmp->header->bitmapSignatureBytes = malloc(sizeof(char) * 3);
    bmp->header->bitmapSignatureBytes = "BM";
    bmp->header->sizeOfBitmapFile = 54 + 786432;
    bmp->header->reservedBytes = 0;
    bmp->header->pixelDataOffset = 54;
}

void	init_bmp_info_header(t_bmp *bmp)
{
	
    bmp->info_header = malloc(sizeof(t_info_header));
	bmp->info_header->sizeOfThisHeader = 40;
    bmp->info_header->width = 512; // in pixels
    bmp->info_header->height = 512; // in pixels
    bmp->info_header->numberOfColorPlanes = 1; // must be 1
    bmp->info_header->colorDepth = 24;
    bmp->info_header->compressionMethod = 0;
    bmp->info_header->rawBitmapDataSize = 0; // generally ignored
    bmp->info_header->horizontalResolution = 3780; // in pixel per meter
    bmp->info_header->verticalResolution = 3780; // in pixel per meter
    bmp->info_header->colorTableEntries = 0;
    bmp->info_header->importantColors = 0;
}

void	init_pixel (t_bmp *bmp)
{
    bmp->px = malloc(sizeof(t_px));
	bmp->px->blue = 255;
    bmp->px->green = 255;
    bmp->px->red = 0;
}

void	init_all(t_bmp *bmp)
{
	init_bmp_header(bmp);
	init_bmp_info_header(bmp);
	init_pixel(bmp);
}

int main(int argc, char **argv) {

    int		fd;
	int		r;
	t_bmp	*bmp;
		
	fd = open("./screenshot.bmp", O_CREAT|O_RDWR, S_IRWXU|S_IRWXG);
	if (fd < 0)
		return (-1);
	bmp = malloc(sizeof(t_bmp));
	init_all(bmp);
	r = write(fd, (char *) &bmp->header, 14);
	if (r == 0)
		return (-1);
    r = write(fd, (char *) &bmp->info_header, 40);
	if (r == 0)
		return (-1);

    // writing pixel data
    size_t numberOfPixels = bmp->info_header->width * bmp->info_header->height;
    for (size_t i = 0; i < numberOfPixels; i++) {
        r = write(fd, (char *) &bmp->px, 3);
		if (r == 0)
			return (-1);
    }
	free(bmp->header);
	free(bmp->info_header);
	free(bmp->header->bitmapSignatureBytes);
	free(bmp->px);
	free(bmp);
    close(fd);

    return 0;
}

