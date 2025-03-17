# STMF407Template
STM32F407基本工程框架



HalTemplate:hal库版本

LibTemplate：标准库版本

RegTemplate：寄存器版本

FreeRTOSTemplate：FreeRTOS版本



------

## FreeRTOSTemplate记录

FreeRTOSTemplate/MyProjectTemplate为OS确定模板，调试完成

### 过程记录：

添加freertos后，系统功能测试正常。

尝试更换hal时基为定时器6，使用代码为stm32cubemx生成的时基替换文件stm32f4xx_hal_timebase_tim.c

切换后freertos时钟无异常。hal库延时函数以及自定义使用滴答计时器us延时异常，延时长度大致为正常延时3倍，判断时钟问题。

尝试切换为定时器1，现象一致。尝试生成空白模板，移植us延时和时基替换文件stm32f4xx_hal_timebase_tim.c，结果正常。

二者硬件仿真类似，尝试debug hal库文件，发现hal_conf文件外部晶振定义错误，修改后现象依旧。

尝试替换整个hal库文件，问题解决。。。

### bug分析：

初始项目使用stm32cubemx生成，可能存在宏定义。

------

printf输出乱码问题，文件编码格式问题，utf-8修改为gbk2312
