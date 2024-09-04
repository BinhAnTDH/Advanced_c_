# Bài 1: Compiler - Macro
<details><summary>Chi tiết</summary>
<p>
	
## Compiler
<details><summary>Chi tiết</summary>   
<p> 
	
Trình biên dịch (compiler) trong C/C++ là công cụ chuyển đổi mã nguồn từ ngôn ngữ lập trình cấp cao (C hoặc C++) sang mã máy hoặc mã thực thi để máy tính có thể hiểu và thực hiện
 ![image](https://github.com/user-attachments/assets/abb9cd9f-07b4-4ebc-a624-dd9db724e8de)
 
 ## 1 Preprocessing (Tiền Xử Lý)

 <details><summary>Chi tiết</summary>   
<p> 

 Tiền xử lý là giai đoạn đầu tiên trong quá trình biên dịch một chương trình C. Nó là một bước quan trọng, diễn ra trước khi mã nguồn C được chuyển đổi thành mã máy. 
 Mục đích chính của tiền xử lý là chuẩn bị mã nguồn cho giai đoạn biên dịch tiếp theo
##  Các công việc chính của tiền xử lý:
Bao gồm các file header: Các chỉ thị như #include <stdio.h> sẽ yêu cầu tiền xử lý đưa toàn bộ nội dung của file header vào mã nguồn tại vị trí của chỉ thị. Các file header thường chứa các khai báo hàm, cấu trúc dữ liệu và các macro được sử dụng trong chương trình.
-***Định nghĩa macro: Các macro là những đoạn mã được đặt tên, cho phép bạn thay thế một đoạn mã bằng một tên ngắn gọn. Ví dụ:#define PI 3.14159
Điều kiện biên dịch: Các chỉ thị như #ifdef, #ifndef, #if, #else, #endif cho phép bạn điều khiển việc biên dịch các đoạn mã khác nhau dựa trên các điều kiện nhất định. Điều này rất hữu ích khi bạn muốn tạo ra các phiên bản khác nhau của một chương trình.

+ #include để chèn nội dung từ các file khác vào mã nguồn.
+ #define, #undef: là một chỉ thị của preprocessor dùng để định nghĩa/hủy định nghĩa macro
+ #if: Kiểm tra điều kiện; nếu đúng, mã bên trong sẽ được biên dịch.
+ #elif: Kiểm tra điều kiện khác nếu #if hoặc #elif trước đó sai.
+ #else: Biên dịch mã nếu tất cả điều kiện trước đó (#if, #elif) đều sai.
+ #ifdef: Biên dịch mã nếu một macro đã được định nghĩa.
+ #ifndef: Kiểm tra xem một đoạn mã hoặc 1 biến đã được định nghĩa chưa, nếu đã được định nghĩa thì sẽ không lặp lại nội dung
+ Xóa bỏ các comment: Tiền xử lý loại bỏ tất cả các comment trong mã nguồn (các dòng bắt đầu bằng // hoặc nằm giữa /* và */).
  
    </p>
</details> 

## 2 Compiler (GCC.g++)
<details><summary>Chi tiết</summary>   
<p> 
  
### Mục đích: Chuyển mã nguồn đã được tiền xử lý thành mã assembly.
### Công việc:
+ Phân tích cú pháp: Kiểm tra xem mã nguồn có tuân thủ đúng cú pháp của ngôn ngữ C hay không.
+ Phân tích ngữ nghĩa: Kiểm tra xem các biểu thức và câu lệnh có ý nghĩa hợp lý hay không.
+ Tạo mã assembly: Chuyển đổi mã nguồn thành mã assembly, một ngôn ngữ cấp thấp hơn, gần với ngôn ngữ máy tính hơn.
### Kết quả: Một file chứa mã assembly (.s).
</p>
</details>

## 3 Assembler (as)
<details><summary>Chi tiết</summary>   
<p> 
	
### Mục đích:
+ Chuyển mã assembly thành mã máy.
### Công việc:
+ Dịch mã assembly: Mỗi dòng lệnh assembly được dịch thành một hoặc nhiều lệnh máy tương ứng.
### Kết quả: 
+ Một file chứa mã máy chưa được liên kết (.o hoặc .obj).
</p>
</details>

## 4 Liên kết (Linking):
<details><summary>Chi tiết</summary>   
<p> 
	
### Mục đích: 
+ Kết hợp các file mã máy (.o hoặc .obj) với các thư viện (static library) để tạo thành một file thực thi hoàn chỉnh.
## Công việc:
+ Giải quyết các tham chiếu: Liên kết các hàm và biến được khai báo trong một file với định nghĩa của chúng trong các file khác hoặc trong thư viện.
+ Tạo file thực thi: Tạo ra một file thực thi (.exe) có thể chạy được trên hệ điều hành.
</p>
</details>

## 2,Macro
<details><summary>Chi tiết</summary>   
<p> 
Hiểu đơn giản thôi thì ***Macro*** là những thứ được định nghĩa trước quá trình Preprocessor diễn ra như: các thư viện được thêm vào #include, hoặc là các định nghĩa được viết vào #define.
+ thư viện **#inlcude** thì hiểu đơn giản đó là một file code khác được dán vào chương trình của mình là mình có thể sử dụng các thứ được viết sẵn trong file code đó ra để sử dụng.
+ **#define** hiểu đơn giản như là thay thế một đoạn code này bằng một cái tên khác cho dễ đọc và dễ hình dung hơn, và giúp chương trình dễ bảo trì.
+ Ngoài #define chúng ta còn có **#undef** dùng để định nghĩa lại các macro đã định nghĩa trước đó.
+ Ngoài ra còn có **#if, #elif, #else** thì nó cũng giống như các lệnh if else sài bình thương thôi, nó sẽ dựa theo các #define đã định nghĩa ở trước đó để thực hiện các điều kiện đúng 
+ Chỉ thị tiền xử lý **#ifdef, #ifndef** được hiểu đơn giản là đã được định nghĩa hoặc là chưa được định nghĩa. Với #ifdef thì nếu một #define trong điều kiện của #ifdef đã được định nghĩa thì nó sẽ thực hiện các câu lệnh trong điều kiện còn không thì chương trình sẽ không thực hiện nữa. Còn với #ifndef thì ngược lại, nếu một #define trong điều kiện của #ifndef chưa được định nghĩa thì nó sẽ thực hiện các câu lệnh trong điều kiện còn nếu đã được định nghĩa rồi thì nó sẽ không thực hiện nữa. Với #ifndef thì được sử dụng như là tránh các lỗi liên quan tới việc chèn thư viện bị trùng nhau trong một file.
+ **Variadic macro** Là một dạng macro cho phép nhận một số lượng biến tham số có thể thay đổi. Giúp định nghĩa các macro có thể xử lý một lượng biến đầu vào khác nhau.
</p>
</details>

 </p>
</details>

</p>
</details>
 

# Bài 2 STDARG - ASSERT
<details><summary>Chi tiết</summary>   
<p>
	
## STDARG (stdarg.h)
<details><summary>Chi tiết</summary>   
<p>
	
**STDARG** là viết tắt của standard argument. Thư viện **stdarg.h**trong C cung cấp một cơ chế để các hàm có thể nhận một số lượng đối số thay đổi. Điều này rất hữu ích khi bạn không biết trước sẽ có bao nhiêu đối số được truyền vào hàm.

#### Các hàm chính trong stdarg.h:

+ va_list: Một kiểu dữ liệu đặc biệt dùng để lưu trữ thông tin về danh sách các đối số biến đổi.
+ va_start: Khởi tạo một đối tượng va_list trước khi truy cập các đối số.
+ va_arg: Truy cập đến một đối số cụ thể trong danh sách đối số biến đổi.
+ va_end: Kết thúc việc sử dụng danh sách đối số biến đổi.
  </p>
</details>

## ASSERT (assert.h)
<details><summary>Chi tiết</summary>   
<p> 
  
**ASSERT** là một macro (một đoạn mã được thay thế bằng một giá trị khác trước khi biên dịch) được sử dụng để kiểm tra các điều kiện giả định trong chương trình. Nếu điều kiện không đúng, chương trình sẽ bị dừng và thông báo lỗi.
#### Cách sử dụng:
```bash
#include <assert.h>

int main() {
    int x = 10;
    assert(x > 0); // Nếu x <= 0, chương trình sẽ dừng và báo lỗi
    // ...
}
```

#### Lợi ích của ASSERT:

+ Phát hiện lỗi sớm: Giúp phát hiện các lỗi trong giai đoạn phát triển.
+ Tăng tính tin cậy của chương trình: Đảm bảo rằng các giả định của chương trình luôn đúng.
+ Tạo ra các đoạn mã rõ ràng hơn: Làm cho mã nguồn dễ đọc và hiểu hơn.
#### Lưu ý:

+ Trong sản xuất: Thường tắt các kiểm tra ASSERT bằng macro NDEBUG để tăng hiệu suất.
ASSERT không thay thế cho việc kiểm tra lỗi đầy đủ: Nó chỉ là một công cụ hỗ trợ.

</p>
</details>

## Kết hợp STDARG và ASSERT
<details><summary>Chi tiết</summary>   
<p> 
  
Chúng ta có thể kết hợp STDARG và ASSERT để kiểm tra tính hợp lệ của các đối số truyền vào hàm có số lượng thay đổi
#### ví dụ 
```bash
void printNumbers(int count, ...) {
    assert(count > 0); // Kiểm tra số lượng đối số phải lớn hơn 0
    // ...
}
```
### Tổng kết:

+ **STDARG** cho phép các hàm có số lượng đối số linh hoạt.
+ **ASSERT** giúp đảm bảo tính đúng đắn của chương trình bằng cách kiểm tra các điều kiện giả định.
+ Kết hợp cả hai giúp tạo ra các hàm mạnh mẽ và đáng tin cậy.
### Khi nào nên sử dụng:

+ **STDARG**: Khi bạn cần viết các hàm có thể nhận một số lượng đối số khác nhau, ví dụ như các hàm in, hàm tính toán tổng.
+ **ASSERT**: Khi bạn muốn kiểm tra các điều kiện quan trọng trong chương trình, đặc biệt là trong giai đoạn phát triển.
### Lưu ý:

+ Việc sử dụng quá nhiều ASSERT có thể làm giảm hiệu suất của chương trình.
+ Nên sử dụng ASSERT một cách có chọn lọc và hợp lý.
</p>
</details>

  </p>
</details>

# Bài 3 Pointer
<details><summary>Chi tiết</summary>   
<p> 
	
	
## khái niệm  
<details><summary>Chi tiết</summary>   
<p>
	
+Trong ngôn ngữ lập trình C, con trỏ (pointer) là một biến chứa địa chỉ bộ nhớ của một biến khác. Việc sử dụng con trỏ giúp chúng ta thực hiện các thao tác trên bộ nhớ một cách linh hoạt hơn
#### Cách khai báo:
+ int *ptr;  // con trỏ đến kiểu int
+ char *ptr_char;  // con trỏ đến kiểu char
+ float *ptr_float;  // con trỏ đến kiểu float
#### Lấy địa chỉ của một biến:
```bash
int x = 10;
int *ptr_x = &x;  // ptr_x giờ đây chứa địa chỉ của x
```
#### Sử dụng con trỏ để truy cập giá trị:
```bash
int y = *ptr_x;  // y sẽ bằng giá trị của x
```
Kích thước của con trỏ sẽ phụ thuộc kiến trúc máy tính và trình biên dịch. Ta có thể dùng sizeof() để kiểm tra kích thước của con trỏ:
```bash
#include <stdio.h>

int main() {
    int *ptr;
    printf("Size of pointer: %lu bytes\n", sizeof(ptr));
    return 0;
}
```
Ví dụ:
```bash
#include <stdio.h>
void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;

}

int main()
{
   int a = 10, b = 20;
   swap(&a, &b);

   printf("value a is: %d\n", a);
   printf("value b is: %d\n", b);

    return 0;
}
```
</p>
</details>

## Các loại pointer:
<details><summary>Chi tiết</summary>   
<p> 
  
#### Void pointer:
Void pointer thường dùng để trỏ để tới bất kỳ địa chỉ nào mà không cần biết tới kiểu dữ liệu của giá trị tại địa chỉ đó.

```bash

void *ptr_void;

```

	Ví dụ:
 ```bash
#include <stdio.h>
#include <stdlib.h>

int main() {
   
    int value = 5;
    double test = 15.7;
    char letter = 'A';
   
    void *ptr = &value;
    printf("value is: %d\n", *(int*)(ptr));

    ptr = &test;
    printf("value is: %f\n", *(double*)(ptr));

    ptr = &letter;
    printf("value is: %c\n", *(char*)(ptr));
   
    return 0;
}

```

#### Pointer to Constant:
	Định nghĩa một con trỏ không thể thay đổi giá trị tại địa chỉ mà nó trỏ đến thông qua dereference nhưng giá trị tại địa chỉ đó có thể thay đổi.
 
	+ Ví dụ:
  ```bash
#include <stdio.h>
#include <stdlib.h>

int main() {
    
    int value = 5;
    int const *ptr_const = &value;

    //*ptr_const = 7; // wrong
    //ptr_const++; // right
    
    printf("value: %d\n", *ptr_const);

    value = 9;
    printf("value: %d\n", *ptr_const);

    return 0;
}
```
#### Constant Pointer:
	Định nghĩa một con trỏ mà giá trị nó trỏ đến (địa chỉ ) không thể thay đổi. Tức là khi con trỏ này được khởi tạo thì nó sẽ không thể trỏ tới địa chỉ khác.
```bash 
#include <stdio.h>
#include <stdlib.h>


int main() {
    
    int value = 5;
    int test = 15;
    int *const const_ptr = &value;

    printf("value: %d\n", *const_ptr);

    *const_ptr = 7;
    printf("value: %d\n", *const_ptr);

    //const_ptr = &test; // wrong
    
    return 0;
}

```


#### Function pointer:
+ Pointer to function (con trỏ hàm) là một biến mà giữ địa chỉ của một hàm. Có nghĩa là, nó trỏ đến vùng nhớ trong bộ nhớ chứa mã máy của hàm được định nghĩa trong chương trình.
+ Trong ngôn ngữ lập trình C, con trỏ hàm cho phép bạn truyền một hàm như là một đối số cho một hàm khác, lưu trữ địa chỉ của hàm trong một cấu trúc dữ liệu, hoặc thậm chí truyền hàm như một giá trị trả về từ một hàm khác.
  
```bash   
Ví dụ:
#include <stdio.h>

// Hàm mẫu 1
void greetEnglish() {
    printf("Hello!\n");
}

// Hàm mẫu 2
void greetFrench() {
    printf("Bonjour!\n");
}

int main() {
    // Khai báo con trỏ hàm
    void (*ptrToGreet)();

    // Gán địa chỉ của hàm greetEnglish cho con trỏ hàm
    ptrToGreet = greetEnglish;

    // Gọi hàm thông qua con trỏ hàm
    (*ptrToGreet)();  // In ra: Hello!

    // Gán địa chỉ của hàm greetFrench cho con trỏ hàm
    ptrToGreet = greetFrench;

    // Gọi hàm thông qua con trỏ hàm
    (*ptrToGreet)();  // In ra: Bonjour!

    return 0;
}

```

	
	Trong ví dụ này, ptrToGreet là một con trỏ hàm có thể trỏ đến các hàm greetEnglish và greetFrench. Việc này giúp linh hoạt trong việc chọn và sử dụng hàm tương ứng tại thời điểm chạy.
```bash  
	Ví dụ 2:
#include <stdio.h>

void sum(int a, int b)
{
    printf("Sum of %d and %d is: %d\n",a,b, a+b);
}

void subtract(int a, int b)
{
    printf("Subtract of %d by %d is: %d \n",a,b, a-b);
    
}

void multiple(int a, int b)
{
    printf("Multiple of %d and %d is: %d \n",a,b, a*b );
    
}

void divide(int a, int b)
{
    if (b == 0)
    {
        printf("Mau so phai khac 0\n");
        return;
    }
    
    printf("%d divided by %d is: %f \n",a,b, (double)a / (double)b);
    
}

void calculator(void (*ptr)(int a, int b), int a, int b)
{
    printf("Program calculate: \n");
    ptr(a,b);
}

int main()
{
    void (*ptrToFunc)(int,int);
    ptrToFunc = &divide;

    calculator(ptrToFunc,5,2);

    return 0;
}

```

	
**ptrToFunc** là một con trỏ hàm trỏ đến các hàm sum, subtract, multiple, divide. **Hàm calculator** với 3 tham số truyền vào là: con trỏ hàm, a, b, và sẽ call function mà con trỏ đang trỏ tới và truyền vào 2 tham số a và b.
#### Pointer to pointer:
**Con trỏ đến con trỏ (Pointer to Pointer)** là một kiểu dữ liệu trong ngôn ngữ lập trình cho phép bạn lưu trữ địa chỉ của một con trỏ. Con trỏ đến con trỏ cung cấp một cấp bậc trỏ mới, cho phép bạn thay đổi giá trị của con trỏ gốc. Cấp bậc này có thể hữu ích trong nhiều tình huống, đặc biệt là khi bạn làm việc với các hàm cần thay đổi giá trị của con trỏ.
```bash 
	Ví dụ:
#include <stdio.h>

int main() {
    int value = 42;
    int *ptr1 = &value;  // Con trỏ thường trỏ đến một biến

    int **ptr2 = &ptr1;  // Con trỏ đến con trỏ

    printf("Value: %d\n", **ptr2);

    return 0;
}
```



**Trong ví dụ này:**
+ ptr1 là một con trỏ thường trỏ đến biến value.
+ ptr2 là một con trỏ đến con trỏ, trỏ đến địa chỉ của ptr1.
+ Khi sử dụng **ptr2, chúng ta có thể truy cập giá trị của biến value.
+	Ứng dụng phổ biến trong cấp phát động mảng hai chiều:
 ```bash 
#include <stdio.h>
#include <stdlib.h>

void allocate2DArray(int ***arr, int rows, int columns) {
    // Cấp phát bộ nhớ cho mảng con trỏ
    *arr = (int**)malloc(rows * sizeof(int*));

    // Cấp phát bộ nhớ cho mỗi hàng
    for (int i = 0; i < rows; ++i) {
        (*arr)[i] = (int*)malloc(columns * sizeof(int));
    }
}

void initialize2DArray(int ***arr, int rows, int columns) {
    // Gán giá trị cho mảng 2D
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            (*arr)[i][j] = i * columns + j + 1;
        }
    }
}

void print2DArray(int **arr, int rows, int columns) {
    // In ra giá trị của mảng 2D
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            printf("%4d ", arr[i][j]);
        }
        printf("\n");
    }
}

void free2DArray(int ***arr, int rows) {
    // Giải phóng bộ nhớ của mảng 2D
    for (int i = 0; i < rows; ++i) {
        free((*arr)[i]);
    }
    free(*arr);
}

int main() {
    int rows = 3, columns = 4;
    int **matrix;

    // Cấp phát bộ nhớ cho mảng 2D
    allocate2DArray(&matrix, rows, columns);

    // Khởi tạo giá trị cho mảng 2D
    initialize2DArray(&matrix, rows, columns);

    // In ra giá trị của mảng 2D
    printf("2D Array:\n");
    print2DArray(matrix, rows, columns);

    // Giải phóng bộ nhớ của mảng 2D
    free2DArray(&matrix, rows);

    return 0;
}

```

#### NULL pointer:
**Null** Pointer là một con trỏ không trỏ đến bất kỳ đối tượng hoặc vùng nhớ cụ thể nào. Trong ngôn ngữ lập trình C, một con trỏ có thể được gán giá trị NULL để biểu diễn trạng thái null.
```bash 
	Ví dụ:
#include <stdio.h>

int main() {
    int *ptr = NULL;  // Gán giá trị NULL cho con trỏ

    if (ptr == NULL) {
        printf("Pointer is NULL\n");
    } else {
        printf("Pointer is not NULL\n");
    }

    return 0;
}
```
**Trong ví dụ này:**
+ Con trỏ ptr được khai báo và được gán giá trị NULL.
+ Một điều kiện kiểm tra xem con trỏ có trỏ đến một đối tượng nào đó hay không.
+ Nếu con trỏ bằng NULL, chương trình in ra "Pointer is NULL", ngược lại nếu con trỏ không bằng NULL, chương trình in ra "Pointer is not NULL".
+ Sử dụng null pointer thường hữu ích để kiểm tra xem một con trỏ đã được khởi tạo và có trỏ đến một vùng nhớ hợp lệ chưa. Tránh dereferencing (sử dụng giá trị mà con trỏ trỏ đến) một null pointer là quan trọng để tránh lỗi chương trình.
</p>
</details>

</p>
</details>

# Bài 4: Extern - Static - Volatile
<details><summary>Chi tiết</summary>   
<p> 
  
## Extern
<details><summary>Chi tiết</summary>   
<p> 
	
**Khái niệm Extern trong ngôn ngữ lập trình C** được sử dụng để thông báo rằng một biến hoặc hàm đã được khai báo ở một nơi khác trong chương trình hoặc trong một file nguồn khác. Điều này giúp chương trình hiểu rằng biến hoặc hàm đã được định nghĩa và sẽ được sử dụng từ một vị trí khác, giúp quản lý sự liên kết giữa các phần khác nhau của chương trình hoặc giữa các file nguồn.
	**Ví dụ:**
 ```bash 
	File main.c
#include <stdio.h>

int value = 90;

extern void display();

int main()

{
	printf("hello\n");
	display();
}


	File other.c
#include <stdio.h>

extern int value;
void display()
{
	printf("value: %d\n", value);
}

```
#### Ứng dụng:
**Chia sẻ biến và hàm giữa các file nguồn:**
+ Extern cho phép bạn chia sẻ biến và hàm giữa nhiều file nguồn trong một chương trình.
+ Điều này hữu ích khi bạn muốn tách chương trình thành các phần nhỏ để quản lý dễ dàng hơn.
+ Chia sẻ biến và hàm giữa các module hoặc thư viện:
+ Extern có thể được sử dụng để kết nối các module hoặc thư viện trong một dự án lớn.
**Khai báo hàm trong trường hợp định nghĩa sau:**
Nếu bạn muốn sử dụng một hàm trước khi nó được định nghĩa trong mã nguồn, bạn có thể sử dụng extern để khai báo hàm.
**Biến toàn cục giữa các tệp nguồn:**
Khi có một biến toàn cục được sử dụng trong nhiều file nguồn, extern giúp các file nguồn biết về sự tồn tại của biến đó.
**Chia sẻ hằng số giữa các file nguồn:**
Nếu bạn có một hằng số được sử dụng ở nhiều nơi, bạn có thể sử dụng extern để chia sẻ giá trị của hằng số đó giữa các file nguồn.

</p>
</details>

### Static
<details><summary>Chi tiết</summary>   
<p> 
	
**Static local variables**
Khi static được sử dụng với local variables (biến cục bộ - khai báo biến trong một hàm), nó giữ giá trị của biến qua các lần gọi hàm và giữ phạm vi của biến chỉ trong hàm đó.
#### Ví dụ:
```bash 
#include <stdio.h>

void exampleFunction() {
    static int count = 0;  // Biến static giữ giá trị qua các lần gọi hàm
    count++;
    printf("Count: %d\n", count);
}

int main() {
    exampleFunction();  // In ra "Count: 1"
    exampleFunction();  // In ra "Count: 2"
    exampleFunction();  // In ra "Count: 3"
    return 0;
}
```

#### Ứng dụng:
+ Lưu trữ trạng thái giữa các lần gọi hàm: Sử dụng biến static để theo dõi trạng thái trạng thái giữa các lần gọi hàm mà không cần sử dụng biến toàn cục.
Static global variables
+ Khi static được sử dụng với global variables ( biến toàn cục - khai báo biến bên ngoài hàm), nó hạn chế phạm vi của biến đó chỉ trong file nguồn hiện tại.
	#### Ví dụ:
```bash
	File main.c
#include <stdio.h>

extern void display();
//extern int s_g_value;
extern int g_value;

int main()
{
	printf("hello\n");
	g_value = 40;
	
	display();

	return 0;
}




	File other.c:
#include <stdio.h>

int g_value = 30;
static int s_g_value = 20;


void display()
{
	printf("static global value: %d\n", s_g_value);
	printf("global value: %d\n", g_value);
}

```
### Static trong class
Khi một thành viên của lớp được khai báo là static, nó thuộc về lớp chứ không thuộc về các đối tượng cụ thể của lớp đó. Các đối tượng của lớp sẽ chia sẻ cùng một bản sao của thành viên static, và nó có thể được truy cập mà không cần tạo đối tượng. Nó thường được sử dụng để lưu trữ dữ liệu chung của tất cả đối tượng.
#### Ví dụ:
```bash
#include <iostream>

typedef enum
{
    red = 0,
    blue,
    green,
    purple,
    black,
    yellow
} Pen_Color;

void print_color_pen(Pen_Color color)
{
    switch (color)
    {
    case red:
        std::cout << "Red\n";
        break;
    case blue:
        std::cout << "Blue\n";
        break;
    case green:
        std::cout << "Green\n";
        break;
    
    default:
        break;
    }
}


class PEN
{
public:
    Pen_Color pen_color;
    static int pen_length;

    PEN(Pen_Color color);
    Pen_Color get_color()
    {
        return pen_color;
    }
    void set_length(int length)
    {
        pen_length = length;
    }
};

int PEN::pen_length;

PEN::PEN(Pen_Color color)
{
    pen_color = color;
    pen_length = 10;
}


int main(int argc, char const *argv[])
{
    PEN blue_pen(blue);
    PEN red_pen(red);
    PEN green_pen(green);

    blue_pen.set_length(9);

    std::cout << "Color: ";
    print_color_pen(blue_pen.get_color());
    std::cout << "Length: " << blue_pen.pen_length << '\n';

    std::cout << "Color: ";
    print_color_pen(red_pen.get_color());
    std::cout << "Length: " << red_pen.pen_length << '\n';

    std::cout << "Color: ";
    print_color_pen(green_pen.get_color());
    std::cout << "Length: " << green_pen.pen_length << '\n';

    return 0;
}

```

</p>
</details>

## Volatile
<details><summary>Chi tiết</summary>   
<p> 
  
	Từ khóa volatile trong ngôn ngữ lập trình C được sử dụng để báo hiệu cho trình biên dịch rằng một biến có thể thay đổi ngẫu nhiên, ngoài sự kiểm soát của chương trình. Việc này ngăn chặn trình biên dịch tối ưu hóa hoặc xóa bỏ các thao tác trên biến đó, giữ cho các thao tác trên biến được thực hiện như đã được định nghĩa.
#### Ví dụ:


### Register
	Trong ngôn ngữ lập trình C, từ khóa register được sử dụng để chỉ ra ý muốn của lập trình viên rằng một biến được sử dụng thường xuyên và có thể được lưu trữ trong một thanh ghi máy tính, chứ không phải trong bộ nhớ RAM. Việc này nhằm tăng tốc độ truy cập. Tuy nhiên, lưu ý rằng việc sử dụng register chỉ là một đề xuất cho trình biên dịch và không đảm bảo rằng biến sẽ được lưu trữ trong thanh ghi. Trong thực tế, trình biên dịch có thể quyết định không tuân thủ lời đề xuất này.
#### Ví dụ:
```bash
#include <stdio.h>
#include <time.h>

int main() {
    // Lưu thời điểm bắt đầu
    clock_t start_time = clock();

    // Đoạn mã của chương trình
    for (int i = 0; i < 1000000; ++i) {
        // Thực hiện một số công việc bất kỳ
    }

    // Lưu thời điểm kết thúc
    clock_t end_time = clock();

    // Tính thời gian chạy bằng miligiây
    double time_taken = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;

    printf("Thoi gian chay cua chuong trinh: %f giay\n", time_taken);

    return 0;
}

```
</p>
</details>

</p>
</details>

# Bài 5: Goto - setjmp.h
<details><summary>Chi tiết</summary>   
<p> 
  
## Goto trong C
<details><summary>Chi tiết</summary>   
<p> 
  
**“ goto ”** là một từ khóa trong ngôn ngữ lập trình C, cho phép chương trình nhảy đến một nhãn (label) đã được đặt trước đó trong cùng một hàm. Mặc dù nó cung cấp khả năng kiểm soát flow của chương trình, nhưng việc sử dụng goto thường được xem là không tốt vì nó có thể làm cho mã nguồn trở nên khó đọc và khó bảo trì.

#### Ví dụ:
```bash
#include <stdio.h>

int main() {
    int i = 0;

    // Đặt nhãn
    start:
        if (i >= 5) {
            goto end;  // Chuyển control đến nhãn "end"
        }

        printf("%d ", i);
        i++;

        goto start;  // Chuyển control đến nhãn "start"

    // Nhãn "end"
    end:
        printf("\n");

    return 0;
}

 ```

+ Trong ví dụ này, goto được sử dụng để tạo một vòng lặp đơn giản. Khi i đạt đến giá trị 5, control sẽ chuyển đến nhãn "end" và kết thúc chương trình.
+ Việc sử dụng goto có thể làm cho mã nguồn trở nên khó bảo trì và khó đọc. Nhiều lập trình viên và chuẩn coding conventions không khuyến khích sử dụng goto nếu có cách thức khác để thực hiện logic. Thay vào đó, sử dụng các cấu trúc kiểm soát vòng lặp (for, while, do-while) và cấu trúc điều kiện (if, else) để viết mã nguồn dễ đọc và bảo trì hơn. 
+ Mặc dù sử dụng goto không được khuyến khích trong phần lớn các trường hợp vì nó có thể làm tăng khả năng phức tạp và khó bảo trì của mã nguồn, nhưng có một số tình huống cụ thể mà việc sử dụng goto có thể được coi là hợp lý:
#### Thoát khỏi nhiều cấp độ vòng lặp
	Trong một số trường hợp, việc thoát khỏi nhiều cấp độ vòng lặp có thể trở nên phức tạp nếu sử dụng cấu trúc kiểm soát vòng lặp thông thường. Trong tình huống như vậy, goto có thể được sử dụng để dễ dàng thoát khỏi nhiều cấp độ vòng lặp.
	**Ví dụ:**
 ```bash
for (int i = 0; i < 10; ++i) {
    for (int j = 0; j < 10; ++j) {
        if (some_condition(i, j)) {
            goto exit_loops;
        }
    }
}

exit_loops:

 ```


#### Xử lý lỗi và giải phóng bộ nhớ
	Trong trường hợp xử lý lỗi, có thể sử dụng goto để dễ dàng giải phóng bộ nhớ đã được cấp phát trước khi thoát khỏi hàm.
```bash
void process_data() {
    int *data = malloc(sizeof(int) * 100);
    if (data == NULL) {
        goto cleanup;
    }

    // Xử lý dữ liệu ở đây

    cleanup:
    free(data);
}
```



#### Implement Finite State Machines (FSM)
	Trong một số trường hợp, đặc biệt là khi triển khai Finite State Machines, goto có thể được sử dụng để chuyển đến các trạng thái khác nhau một cách dễ dàng.
 ```bash
switch (current_state) {
    case STATE_A:
        // Xử lý State A
        if (condition) {
            goto STATE_B;
        }
        break;

    case STATE_B:
        // Xử lý State B
        break;
}

 ```
</p>
</details>

## Thư viện setjmp.h
<details><summary>Chi tiết</summary>   
<p> 
  
**setjmp.h** là một thư viện trong ngôn ngữ lập trình C, cung cấp hai hàm chính là setjmp và longjmp. Cả hai hàm này thường được sử dụng để thực hiện xử lý ngoại lệ trong C, mặc dù nó không phải là một cách tiêu biểu để xử lý ngoại lệ trong ngôn ngữ này.
**Ví dụ:**
```bash
#include <stdio.h>
#include <setjmp.h>

jmp_buf buffer;

void risky_function() {
    printf("Entering risky_function\n");
    
    // Thiết lập điểm cho việc "quay lại"
    if (setjmp(buffer) != 0) {
        printf("Exiting risky_function due to longjmp\n");
        return;
    }

    // Mô phỏng một tình huống lỗi
    int error_condition = 1;
    if (error_condition) {
        printf("Error detected in risky_function\n");
        longjmp(buffer, 1);  // "Quay lại" tới điểm đã được thiết lập bởi setjmp
    }

    printf("Exiting risky_function normally\n");
}

int main() {
    printf("Starting main\n");
    risky_function();
    printf("Back in main after risky_function\n");

    return 0;
}
 ```


Trong ví dụ này, setjmp được sử dụng để thiết lập một điểm, và longjmp được sử dụng để "quay lại" điểm đã được thiết lập đó khi một tình huống lỗi được phát hiện trong hàm risky_function.

</p>
</details>

</p>
</details>

# Bài 6: Bitmask
<details><summary>Chi tiết</summary>   
<p> 
	
## Khái niệm cơ bản
<details><summary>Chi tiết</summary>   
<p> 
	Bitmask là một kỹ thuật sử dụng các bit để lưu trữ và thao tác với các cờ (flags) hoặc trạng thái. Có thể sử dụng bitmask để đặt, xóa và kiểm tra trạng thái của các bit cụ thể trong một từ (word).
	Bitmask thường được sử dụng để tối ưu hóa bộ nhớ, thực hiện các phép toán logic trên một cụm bit, và quản lý các trạng thái, quyền truy cập, hoặc các thuộc tính khác của một đối tượng.
</p>
</details>

## Các toán tử bitwise
<details><summary>Chi tiết</summary>   
<p>
	
### AND bitwise ( & )
Dùng để thực hiện phép AND bitwise giữa từng cặp bit của hai số. Kết quả là 1 nếu cả hai bit tương ứng đều là 1, ngược lại là 0.
**Ví dụ:**
int result = num1 & num2;

### OR bitwise ( | )
Dùng để thực hiện phép OR bitwise giữa từng cặp bit của hai số. Kết quả là 1 nếu có hơn một bit tương ứng là 1.
**Ví dụ:**
int result = num1 | num2;




### XOR bitwise
Dùng để thực hiện phép XOR bitwise giữa từng cặp bit của hai số. Kết quả là 1 nếu chỉ một trong hai bit tương ứng là 1.
**Ví dụ:**
int result = num1 ^ num2;


### NOT bitwise
Dùng để thực hiện phép NOT bitwise trên từng bit của một số. Kết quả là bit đảo ngược của số đó.
**Ví dụ:**
int result = ~num;


### Shift left và Shift right
+ Dùng để di chuyển bit sang trái hoặc sang phải.
+ Trong trường hợp <<, các bit ở bên phải sẽ được dịch sang trái, và các bit trái cùng sẽ được đặt giá trị 0.
+ Trong trường hợp >>, các bit ở bên trái sẽ được dịch sang phải, và các bit phải cùng sẽ được đặt giá trị 0 hoặc 1 tùy thuộc vào giá trị của bit cao nhất (bit dấu).
	**Ví dụ:**
+ int resultLeftShift = num << shiftAmount;
+ int resultRightShift = num >> shiftAmount;




	**Một số ví dụ và ứng dụng:**
```bash
  
#include <stdio.h>
#include <stdint.h>


#define GENDER        1 << 0  // Bit 0: Giới tính (0 = Nữ, 1 = Nam)
#define TSHIRT        1 << 1  // Bit 1: Áo thun (0 = Không, 1 = Có)
#define HAT           1 << 2  // Bit 2: Nón (0 = Không, 1 = Có)
#define SHOES         1 << 3  // Bit 3: Giày (0 = Không, 1 = Có)
// Tự thêm 5 tính năng khác
#define FEATURE1      1 << 4  // Bit 4: Tính năng 1
#define FEATURE2      1 << 5  // Bit 5: Tính năng 2
#define FEATURE3      1 << 6  // Bit 6: Tính năng 3
#define FEATURE4      1 << 7  // Bit 7: Tính năng 4

void enableFeature(uint8_t *features, uint8_t feature) {
    *features |= feature;
}

void disableFeature(uint8_t *features, uint8_t feature) {
    *features &= ~feature;
}


int isFeatureEnabled(uint8_t features, uint8_t feature) {
    return (features & feature) != 0;
}

void listSelectedFeatures(uint8_t features) {
    printf("Selected Features:\n");

    if (features & GENDER) {
        printf("- Gender\n");
    }
    if (features & TSHIRT) {
        printf("- T-Shirt\n");
    }
    if (features & HAT) {
        printf("- Hat\n");
    }
    if (features & SHOES) {
        printf("- Shoes\n");
    }
    // Thêm các điều kiện kiểm tra cho các tính năng khác
}

void removeFeatures(uint8_t *features, uint8_t unwantedFeatures) {
    *features &= ~unwantedFeatures;
}



int main() {
    uint8_t options = 0;

    // Thêm tính năng 
    enableFeature(&options, GENDER | TSHIRT | HAT);

    removeFeatures(&options, TSHIRT);

    // Liệt kê các tính năng đã chọn
    listSelectedFeatures(options);
    
    return 0;
}

```
#### Ví dụ 2:
```bash
#include <stdio.h>

#define LED1 1 << 0 // 0001
#define LED2 1 << 1 // 0010
#define LED3 1 << 2 // 0100
#define LED4 1 << 3 // 1000


void enableLED(unsigned int *GPIO_PORT, unsigned int LED) {
    *GPIO_PORT |= LED;
}

void disableLED(unsigned int *GPIO_PORT, unsigned int LED) {
    *GPIO_PORT &= ~LED;
}


int main() {
    unsigned int GPIO_PORT = 0; // Giả sử là biến điều khiển cổng GPIO

    // Bật LED1 và LED3
    enableLED(&GPIO_PORT, LED1 | LED3);
    if (GPIO_PORT & LED1 )
    {
        printf("LED1 is on\n");
    }

    if (GPIO_PORT & LED2)
    {
        printf("LED2 is on\n");
    }

    if (GPIO_PORT & LED3)
    {
        printf("LED3 is on\n");
    }
    
    // Tắt LED1 và bật LED2
    disableLED(&GPIO_PORT, LED1);
    enableLED(&GPIO_PORT, LED2);

    if (GPIO_PORT & LED1 )
    {
        printf("LED1 is on\n");
    }

    if (GPIO_PORT & LED2)
    {
        printf("LED2 is on\n");
    }

    if (GPIO_PORT & LED3)
    {
        printf("LED3 is on\n");
    }

    // Cập nhật trạng thái của GPIO_PORT tương ứng với hardware

    return 0;
}
```


**Ví dụ 3:**
 ```bash
#include <stdio.h>
#include <stdint.h>

#define ENABLE 1
#define DISABLE 0

typedef struct {
    uint8_t LED1 : 1;
    uint8_t LED2 : 1;
    uint8_t LED3 : 1;
    uint8_t LED4 : 1;
    uint8_t LED5 : 1;
    uint8_t LED6 : 1;
    uint8_t LED7 : 1;
    uint8_t LED8 : 1;
} LEDStatus;



int main() {
    LEDStatus ledStatus = {.LED7 = ENABLE};

    // Bật LED 1 và 3
    ledStatus.LED1 = ENABLE;
    ledStatus.LED3 = ENABLE;

    // Kiểm tra trạng thái của LED 1
    if (ledStatus.LED1) {
        printf("LED1 is on\n");
    }


    return 0;
}

```



**Ví dụ 4:**
 ```bash
#include <stdio.h>
#include <stdint.h>
#define COLOR_RED 0
#define COLOR_BLUE 1
#define COLOR_BLACK 2
#define COLOR_WHITE 3
#define POWER_100HP 0
#define POWER_150HP 1
#define POWER_200HP 2
#define ENGINE_1_5L 0
#define ENGINE_2_0L 1

typedef uint8_t CarColor;
typedef uint8_t CarPower;
typedef uint8_t CarEngine;



#define SUNROOF_MASK 1 << 0     // 0001
#define PREMIUM_AUDIO_MASK 1 << 1 // 0010
#define SPORTS_PACKAGE_MASK 1 << 2 // 0100
// Thêm các bit masks khác tùy thuộc vào tùy chọn


typedef struct {
    uint8_t additionalOptions : 3; // 3 bits cho các tùy chọn bổ sung
    CarColor color : 2;
    CarPower power : 2;
    CarEngine engine : 1;
    
} CarOptions;



void configureCar(CarOptions *car, CarColor color, CarPower power, CarEngine engine, uint8_t options) {
    car->color = color;
    car->power = power;
    car->engine = engine;
    car->additionalOptions = options;
}

void setOption(CarOptions *car, uint8_t optionMask) {
    car->additionalOptions |= optionMask;
}

void unsetOption(CarOptions *car, uint8_t optionMask) {
    car->additionalOptions &= ~optionMask;
}


void displayCarOptions(const CarOptions car) {
    const char *colors[] = {"Red", "Blue", "Black", "White"};
    const char *powers[] = {"100HP", "150HP", "200HP"};
    const char *engines[] = {"1.5L", "2.0L"};

    printf("Car Configuration: \n");
    printf("Color: %s\n", colors[car.color]);
    printf("Power: %s\n", powers[car.power]);
    printf("Engine: %s\n", engines[car.engine]);
    printf("Sunroof: %s\n", (car.additionalOptions & SUNROOF_MASK) ? "Yes" : "No");
    printf("Premium Audio: %s\n", (car.additionalOptions & PREMIUM_AUDIO_MASK) ? "Yes" : "No");
    printf("Sports Package: %s\n", (car.additionalOptions & SPORTS_PACKAGE_MASK) ? "Yes" : "No");
}

int main() {
    CarOptions myCar = {COLOR_BLACK, POWER_150HP, ENGINE_2_0L};

    setOption(&myCar, SUNROOF_MASK);
    setOption(&myCar, PREMIUM_AUDIO_MASK);
    
    displayCarOptions(myCar);

    unsetOption(&myCar, PREMIUM_AUDIO_MASK); 
    displayCarOptions(myCar);

    printf("size of my car: %d\n", sizeof(CarOptions));

    return 0;
}

```
</p>
</details>

</p>
</details>

# Bài 7: Struct - Union
<details><summary>Chi tiết</summary>   
<p>
	
## Struct
<details><summary>Chi tiết</summary>   
<p> 	
Trong ngôn ngữ lập trình C, **struct** là một cấu trúc dữ liệu cho phép lập trình viên tự định nghĩa một kiểu dữ liệu mới bằng cách nhóm các biến có các kiểu dữ liệu khác nhau lại với nhau. struct cho phép tạo ra một thực thể dữ liệu lớn hơn và có tổ chức hơn từ các thành viên (members) của nó.
	
```bash
Cú pháp:
 
struct TenStruct {
    kieuDuLieu1 thanhVien1;
    kieuDuLieu2 thanhVien2;
    // ...
};
```


**Ví dụ:**
```bash
struct Point {
    int x;
    int y;
};

```


**Thành Viên (Member):** Mỗi biến trong struct được gọi là một thành viên hoặc trường. Trong ví dụ struct Point, x và y là các thành viên của Point.
**Khởi Tạo và Truy Cập Thành Viên:**
+ Để khởi tạo một biến thuộc kiểu struct, bạn sử dụng cú pháp như sau:
  
```bash
struct Point p1 = {10, 20};
 ```
+ Để truy cập các thành viên, bạn sử dụng toán tử ( . ):
  
```bash 
printf("X coordinate: %d\n", p1.x);
 ```

+ Sử Dụng Tham Số Trong Hàm:
	Bạn có thể truyền một biến thuộc kiểu struct như một tham số cho một hàm.
```bash 
void printPoint(struct Point p) {
    printf("(%d, %d)\n", p.x, p.y);
}
```



### Truyền Con Trỏ đến Struct:
Bạn có thể truyền con trỏ đến struct như một tham số cho một hàm, cho phép thay đổi giá trị của struct bên trong hàm.
```bash
void updatePoint(struct Point* p, int newX, int newY) {
    p->x = newX;
    p->y = newY;
}

```
### Sử Dụng typedef để Tạo Bí Danh:
Bạn có thể sử dụng typedef để tạo bí danh cho struct, giúp rút ngắn cú pháp khi khai báo biến.
```bash
typedef struct Point {
    int x;
    int y;
} Point;



Sau đó, bạn có thể khai báo biến như sau:
```bash
Point p1 = {10, 20};

```
**struct** giúp tổ chức dữ liệu một cách hiệu quả và làm cho mã nguồn trở nên dễ đọc và bảo trì hơn.
</p>
</details>

## Union
<details><summary>Chi tiết</summary>   
<p> 
Trong ngôn ngữ lập trình C, union là một cấu trúc dữ liệu giúp lập trình viên kết hợp nhiều kiểu dữ liệu khác nhau vào một cùng một vùng nhớ. Mục đích chính của union là tiết kiệm bộ nhớ bằng cách chia sẻ cùng một vùng nhớ cho các thành viên của nó. Điều này có nghĩa là, trong một thời điểm, chỉ một thành viên của union có thể được sử dụng.
	
**Cú pháp định nghĩa union trong C như sau:**

```bash
union TenUnion {
    kieuDuLieu1 thanhVien1;
    kieuDuLieu2 thanhVien2;
    // ...
};
```



#### Ví dụ:
```bash
union Data {
    int i;
    float f;
    char str[20];
};
```



+ Trong đoạn mã trên, union Data định nghĩa một kiểu dữ liệu mới có ba thành viên là i (kiểu int), f (kiểu float), và str (mảng kiểu char).
**Các khái niệm chính của union trong C bao gồm:**
**Tiết kiệm bộ nhớ:**
+ union tiết kiệm bộ nhớ bằng cách chia sẻ cùng một vùng nhớ cho các thành viên. Kích thước của union là kích thước của thành viên lớn nhất.
+ Truy cập thành viên:
+ Bạn truy cập các thành viên của union bằng cách sử dụng toán tử . như struct.
```bash
union Data data;
data.i = 10;
printf("Value of i: %d\n", data.i);

```
+ Sử dụng trong các tình huống đặc biệt
+ **union** thường được sử dụng khi bạn có một biến có thể chứa một trong các kiểu dữ liệu khác nhau và bạn chỉ cần sử dụng một kiểu dữ liệu tại một thời điểm.
```bash
union Value {
    int intValue;
    float floatValue;
    char stringValue[20];
};

```
**Biểu diễn dữ liệu tương đồng**
	Khi bạn có các dữ liệu có ý nghĩa tương đồng nhưng có kiểu dữ liệu khác nhau, union giúp bạn biểu diễn chúng một cách hiệu quả.
```bash
union Measurement {
    int height;
    float depth;
    double distance;
};
 ```



**Lưu trữ dữ liệu tạm thời**
	**union** có thể được sử dụng để lưu trữ dữ liệu tạm thời khi bạn cần một biến có thể chứa một trong các kiểu dữ liệu khác nhau tùy thuộc vào tình huống.
 ```bash
union TemporaryData {
    int intValue;
    float floatValue;
    char stringValue[20];
};
```

+ Lưu ý rằng khi sử dụng union, cần phải kiểm soát rất cẩn thận để tránh những lỗi gây ra bởi việc truy cập vào thành viên không hợp lệ, vì bạn chỉ nên đọc giá trị của thành viên bạn đã ghi vào gần đây nhất.

</p>
</details>

</p>
</details>





 



