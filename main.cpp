/* mbed Microcontroller Library
 * Copyright (c) 2019 ARM Limited
 * SPDX-License-Identifier: Apache-2.0
 */

#define MBED_CONF_TARGET_STDIO_UART_TX PA_9
#define MBED_CONF_TARGET_STDIO_UART_RX PA_10

#include "mbed.h"
#include "SDBlockDevice.h"
#include "FATFileSystem.h"
//#include "USBSerial.h"

#define WAIT_TIME_MS 500 
DigitalOut led1(PC_13);


//SDBlockDevice sd(MBED_CONF_SD_SPI_MOSI, MBED_CONF_SD_SPI_MISO, MBED_CONF_SD_SPI_CLK, MBED_CONF_SD_SPI_CS);
SDBlockDevice sd(MBED_CONF_SD_SPI_MOSI, MBED_CONF_SD_SPI_MISO, MBED_CONF_SD_SPI_CLK, MBED_CONF_SD_SPI_CS);
FATFileSystem fs("SD");
char filereadchar=0;

int main()
{
    printf("This is the bare metal blinky example running on Mbed OS %d.%d.%d.\n", MBED_MAJOR_VERSION, MBED_MINOR_VERSION, MBED_PATCH_VERSION);

    while (true)
    {
        led1 = !led1;
        thread_sleep_for(WAIT_TIME_MS);
    }
}

// SDFileSystem sd(p5, p6, p7, p8, "sd"); // the pinout on the mbed Cool Components workshop board
 
// int main() {
//     printf("Hello World!\n");   
 
//     mkdir("/sd/mydir", 0777);
    
//     FILE *fp = fopen("/sd/mydir/sdtest.txt", "w");
//     if(fp == NULL) {
//         error("Could not open file for write\n");
//     }
//     fprintf(fp, "Hello fun SD Card World!");
//     fclose(fp); 
 
//     printf("Goodbye World!\n");
// }