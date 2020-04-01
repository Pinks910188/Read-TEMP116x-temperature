# Read-TEMP116x-temperature

----
## How Can Use:
Chip datasheet : [http://www.ti.com/lit/ds/symlink/tmp116.pdf](http://www.ti.com/lit/ds/symlink/tmp116.pdf)

----
## usage

Add header for your function.

>

    #include <readEnvTemp.h>

Add code in your function.

>
    readEnvTemp temp;
    temp.getTemp();


## Note
>
    #define TMP116x_bus "/dev/i2c-0"
    #define TMP116x_i2c_address 0x48

i2c bus and TMP116x_i2c_address is needed define by yourself, maybe bus will be "/dev/i2c-0" or "/dev/i2c-1". About address, please read Datasheet, it has detail description.




----
## changelog
* 01-04-2020 First push code.

----
## thanks
* If you have any question, welcome to contact me.
