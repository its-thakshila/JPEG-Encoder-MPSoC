/*************************************************************************************
 * CO503 Advanced Embedded Systems
 *
 * Date         : 16-08-2016
 * Author       : Isuru Nawinne
 * Edited by    :
 *
 * Description  : Compress and convert a BMP image file into JPEG format
 *
 *************************************************************************************/

#include "application/jpeg_encoding.h"
#include "application/bmp_extract.h"

#include "system.h"
#include "io.h"
#include "altera_avalon_pio_regs.h"
#include <unistd.h>

#define NO_OF_FILES 7

/* If your PIO instance name in Qsys is NOT led_out, change this to match.
 * Example: if Qsys name is "led", use LED_BASE from system.h.
 */
#ifndef LED_OUT_BASE
#define LED_PIO_BASE LED_OUT_BASE
#else
#define LED_PIO_BASE LED_OUT_BASE
#endif

/* LED patterns */
#define LED_IDLE        0x00
#define LED_VALID_BMP   0x01
#define LED_EXTRACTING  0x03
#define LED_ENCODING    0x07
#define LED_DONE        0xFF
#define LED_ERROR       0xAA

/* Hold times (microseconds) */
#define LED_DONE_HOLD_US   500000   /* 0.5 s */
#define LED_ERROR_HOLD_US  500000   /* 0.5 s */

static inline void set_leds(unsigned char v)
{
    IOWR_ALTERA_AVALON_PIO_DATA(LED_PIO_BASE, v);
}

void convert_picture(const char *jtag_input);

int main()
{
    char jtag_input[20];

    // Print that welcome message. Programmers looove welcome messages! ;)
    printf("CO503 JPEG Encoder \n\n");

    set_leds(LED_IDLE);

    while(1) {
        set_leds(LED_IDLE);
        printf("Input file: ");
        scanf("%s", jtag_input); // Ask for the input BMP file

        // Check if the filename ends in '.bmp'
        if(strcmp(&jtag_input[strlen(jtag_input) - 4], ".bmp") == 0) {

            set_leds(LED_VALID_BMP);
            convert_picture(jtag_input); // See function at the bottom

        } else {
            // Not a BMP -> show error pattern briefly
            set_leds(LED_ERROR);
            usleep(LED_ERROR_HOLD_US);
            set_leds(LED_IDLE);
        }
        printf("\n\n");
    }

    return 0;
}

/*
 * Convert a BMP picture of name <jtag_input> into JPEG.
 */
void convert_picture(const char *jtag_input)
{
    char file_name[80] = "/mnt/host/files/";
    char destination[80] = "/mnt/host/files/";
    Bmp_data pic_data;

    strcat(file_name, jtag_input);
    strcat(destination, jtag_input);

    // Replace the '.bmp' with '.jpg'
    strcpy(&destination[strlen(destination) - 3], "jpg");

    set_leds(LED_EXTRACTING);

    if(bmp_extract(file_name, &pic_data) == 0) {
        set_leds(LED_ENCODING);

        // Convert to JPEG. This is where the magic happens!
        jpeg_encode(destination, pic_data.bitmap,
                    pic_data.header->BMPHeight,
                    pic_data.header->BMPWidth, 90);

        set_leds(LED_DONE);
        usleep(LED_DONE_HOLD_US);
        set_leds(LED_IDLE);

    } else {
        // An error has happened
        set_leds(LED_ERROR);
        usleep(LED_ERROR_HOLD_US);
        set_leds(LED_IDLE);
    }
}
