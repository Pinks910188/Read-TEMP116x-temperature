#include <iostream>
#include <iomanip>

#include <unistd.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <linux/i2c-dev.h>
#include <stdio.h>
#include <cmath>

#include "readEnvTemp.h"

using namespace std;

readEnvTemp::readEnvTemp(){
    cout << "readEnvTemp class build" << endl;
}

readEnvTemp::~readEnvTemp(){
    cout << "readEnvTemp class close" << endl;
}

void readEnvTemp::getTemp(){
    bool ret;
    ret = true;

    /* set-up */
    if ((file_i2c = open(TMP116x_bus, O_RDWR)) < 0) {
        printf("Failed to open the i2c bus\n");
        ret = false;

    }
    if (ioctl(file_i2c, I2C_SLAVE, TMP116x_i2c_address) < 0) {
         printf("Failed to acquire bus access and/or talk to slave.\n");
         ret = false;

    }

    /* read */
    char addrBuf[2];
    int readBytes = 0;
    addrBuf[0] =  0x00;		// pointer to register address.
    addrBuf[1] = TMP116x_i2c_address;	// IC address
    readBytes = write(file_i2c, addrBuf, sizeof(addrBuf)); //pointer address & send addr.
    if (readBytes != sizeof(addrBuf))
    {
        printf("Error: Received no ACK-Bit, couldn't established connection! \n");
        ret = false;
    }

    char buffer[2];
    int i = 0;
    // read response
    readBytes = read(file_i2c, &buffer, sizeof(buffer));
    if (readBytes != sizeof(buffer))
    {
        printf("Error: TMP116x read error!\n");
        ret = false;

    }

    int tempValueOfRegister = 16 * 16 * int(buffer[0]) + int(buffer[1]);
    double temp = tempValueOfRegister * tempStepdistance / 1000;

    cout << "Now temp is :" << temp << endl;

}
