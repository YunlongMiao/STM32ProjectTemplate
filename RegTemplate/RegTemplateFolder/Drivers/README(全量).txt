    该文件夹下面存放驱动层代码，包括：
    1，BSP：正点原子提供的板级支持包驱动代码（原HARDWARE文件夹下的代码），如：LED、BEEP、KEY、EXTI、TIMER、WDG...等
    2，CMSISI：ARM提供的CMSIS代码（主要包括各种头文件和启动文件（.s文件），为了方便使用，减少占用空间，我们进行了精简）
    3，SYSTEM：正点原子提供的系统文件, 包括delay.c、usart.c和sys.c，用于方便用户快速构建工程