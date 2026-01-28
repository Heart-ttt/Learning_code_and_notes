## 程序结构
- 预处理器指令
- 函数
- 变量
- 语句和表达式
- 注释
- 程序结构还包括顺序结构、分支结构、循环结构

## 数据类型
- 基本数据类型
  - int 4byte
  - long 4byte
  - short 2byte
  - char 1byte
  - float 4byte
  - double 8byte
- 枚举类型
- void类型
- 派生类型：数组类型、指针类型、结构体类型
- C 语言不会自动把整数“转成字符串”。
    你必须显式地进行字符映射（如 +'0'）或使用格式化函数（如 sprintf）。
    ```c
    i = 0;j = (char)i;//实质上是转变成ASCIL码的0即'\0'；
    ```

## 变量与常量
- 整数常量 0x or 0X 表示16进制；0表示8进制
- 浮点常量
- 字符常量->' '
- 字符串常量->" "
- 使用 #define和const定义常量

## 运算符
- 算数运算符(+)(-)(*)(/)(%)取模(++)(--)
- 关系运算符
- 逻辑运算符(&&)(||)(!)
- 位运算符(&)(|)(^)异或(~)取反(<<)左移(>>)右移
- 赋值运算符
- 其他：条件运算符(?:)逗号运算(,)sizeof(运算)

## 格式化输出(printf)

### 常用的格式控制符号

| 格式符 | 说明 | 对应参数类型 | 示例 |
|--------|------|----------------|------|
| `%d` 或 `%i` | 有符号十进制整数 | `int` | `printf("%d", 42);` → `42` |
| `%u` | 无符号十进制整数 | `unsigned int` | `printf("%u", -1);` → `4294967295` |
| `%x` | 小写十六进制整数 | `unsigned int` | `printf("%x", 255);` → `ff` |
| `%X` | 大写十六进制整数 | `unsigned int` | `printf("%X", 255);` → `FF` |
| `%o` | 八进制整数 | `unsigned int` | `printf("%o", 8);` → `10` |
| `%c` | 单个字符 | `char` / `int` | `printf("%c", 'A');` → `A` |
| `%s` | 字符串（以 `\0` 结尾） | `char*` | `printf("%s", "Hi");` → `Hi` |
| `%f` 或 `%F` | 十进制浮点数（小写/大写） | `float`, `double` | `printf("%f", 3.14);` → `3.140000` |
| `%e` | 科学计数法（小写 e） | `float`, `double` | `printf("%e", 123.4);` → `1.234000e+02` |
| `%E` | 科学计数法（大写 E） | `float`, `double` | `printf("%E", 123.4);` → `1.234000E+02` |
| `%g` | 自动选择 `%f` 或 `%e`（更简洁） | `float`, `double` | `printf("%g", 123.0);` → `123` |
| `%G` | 同 `%g`，但用大写 E | `float`, `double` | `printf("%G", 123.4);` → `123.4` |
| `%p` | 指针地址（通常十六进制） | `void*` | `printf("%p", &var);` → `0x7fff5fbff6ac` |
| `%%` | 输出字面百分号 `%` | 无 | `printf("100%%");` → `100%` |

### 常用修饰符（可组合使用）

| 修饰符 | 说明 | 示例 |
|--------|------|------|
| `%5d` | 至少占 5 列，右对齐 | `printf("%5d", 7);` → `    7` |
| `%-5d` | 至少占 5 列，左对齐 | `printf("%-5d", 7);` → `7    ` |
| `%.2f` | 保留 2 位小数 | `printf("%.2f", 3.1415);` → `3.14` |
| `%05d` | 用 0 填充至 5 位 | `printf("%05d", 42);` → `00042` |
| `%.*s` | 动态指定字符串长度 | `printf("%.*s", 3, "hello");` → `hel` |

## 控制语句

## [字符串](strings.c)

```c
char site[7] = {'h', 'e', 'l', 'l', 'o', '\0'};
char site[7] = "hello";
```
以上两句语句是等价的

`size_t`表示有几个数字如2103=>4

### 字符串常见函数

```c
size_t strlen(const char *s);//计算字符串s的长度，不包含'\0'

char* strcpy(char *dest, const char *src);//把src所指向的字符串复制到dest所指向的空间中，'\0'也会拷贝过去
//！！如果目标数组不够大，会导致缓冲区溢出

char* strncpy(char *dest, const char *src, size_t n);//把src指向字符串的前n个字符复制到dest所指向的空间中，是否拷贝'\0'取决于指定的长度是否包含'\0'

char* strcat(char dest, const char src);

char* strncat(cahr dest, const char src, size_t n);

int strcmp(const char *s1, const char *s2);

```

## 函数

## 内存分类

- 静态/全局内存
- 自动内存（栈）

    函数内部声明的变量使用这部分内存，在函数被调用时才创建（创造和释放不受控制）
- 动态内存（堆）
  
    根据需求编写代码动态分配内存，可以编写代码释放，内存中内容直到释放才消失
    ```c    
    int *b = (*int)malloc(sizeof(int))
    其中malloc在堆内存中开辟一片空间，在栈内存中的指针变量b指向这一片空间
    malloc函数返回的是一个指针
    ```

## 数组

### 定义: 数组是可以存储一个固定大小的相同类型元素的顺序集合
- 利用sizeof()求数组的大小
```c
    double d[5]={0};printf("%d", sizeof(d)/sizeof(d[0]))
    output:5
```
- 数组名表示数组的地址，即数组首元素的地址`数组名的地址==数组的地址`

### 数组与指针
在堆内存中开辟一片空间来存放数组
```c
arr_type* Create_arr(int len){
    arr_type *arr = malloc(sizeof(arr_type)*len);
    return arr;
}
```

### 二维数组

## 指针

指针的大小取决于系统的架构:`x86`系统中占`4 byte`; `x64`系统中占`8 byte`

在声明中`int *p = &a` 即声明一个指针变量. 

间接应用操作符`*p = 100 =>p` 所指向地址中存的值. 

给指针加上整数，实质上是给对应指针类型的字节数的乘积. `int *a => *(a+1)` 即加上四个字节.  

## 结构体

### 结构体的两种定义方式

```c
struct point{
    int x;
    int y;
};

typedef struct{
    char stuId[11];
    char stuName[20];
    int age;
}student;

//在链表中使用此定义，使语法可以调用
typedef strcuct node{
    int data;
    struct node *next;
}Node;

int main(void){
    struct point space;
    student stu_1;
}
```

