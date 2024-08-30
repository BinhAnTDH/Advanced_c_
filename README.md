# Bài 1: Compiler - Macro
## Compiler
Trình biên dịch (compiler) trong C/C++ là công cụ chuyển đổi mã nguồn từ ngôn ngữ lập trình cấp cao (C hoặc C++) sang mã máy hoặc mã thực thi để máy tính có thể hiểu và thực hiện
 ![image](https://github.com/user-attachments/assets/abb9cd9f-07b4-4ebc-a624-dd9db724e8de)
 ## 1 Preprocessing (Tiền Xử Lý)

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
## 2 Compiler (GCC.g++)
### Mục đích: Chuyển mã nguồn đã được tiền xử lý thành mã assembly.
### Công việc:
+ Phân tích cú pháp: Kiểm tra xem mã nguồn có tuân thủ đúng cú pháp của ngôn ngữ C hay không.
+ Phân tích ngữ nghĩa: Kiểm tra xem các biểu thức và câu lệnh có ý nghĩa hợp lý hay không.
+ Tạo mã assembly: Chuyển đổi mã nguồn thành mã assembly, một ngôn ngữ cấp thấp hơn, gần với ngôn ngữ máy tính hơn.
### Kết quả: Một file chứa mã assembly (.s).
## 3 Assembler (as)
### Mục đích:
+ Chuyển mã assembly thành mã máy.
### Công việc:
+ Dịch mã assembly: Mỗi dòng lệnh assembly được dịch thành một hoặc nhiều lệnh máy tương ứng.
### Kết quả: 
+ Một file chứa mã máy chưa được liên kết (.o hoặc .obj).
## 4 Liên kết (Linking):

### Mục đích: 
+ Kết hợp các file mã máy (.o hoặc .obj) với các thư viện (static library) để tạo thành một file thực thi hoàn chỉnh.
## Công việc:
+ Giải quyết các tham chiếu: Liên kết các hàm và biến được khai báo trong một file với định nghĩa của chúng trong các file khác hoặc trong thư viện.
+ Tạo file thực thi: Tạo ra một file thực thi (.exe) có thể chạy được trên hệ điều hành.
## 2,Macro
Hiểu đơn giản thôi thì ***Macro*** là những thứ được định nghĩa trước quá trình Preprocessor diễn ra như: các thư viện được thêm vào #include, hoặc là các định nghĩa được viết vào #define.
+ thư viện **#inlcude** thì hiểu đơn giản đó là một file code khác được dán vào chương trình của mình là mình có thể sử dụng các thứ được viết sẵn trong file code đó ra để sử dụng.
+ **#define** hiểu đơn giản như là thay thế một đoạn code này bằng một cái tên khác cho dễ đọc và dễ hình dung hơn, và giúp chương trình dễ bảo trì.
+ Ngoài #define chúng ta còn có **#undef** dùng để định nghĩa lại các macro đã định nghĩa trước đó.
+ Ngoài ra còn có **#if, #elif, #else** thì nó cũng giống như các lệnh if else sài bình thương thôi, nó sẽ dựa theo các #define đã định nghĩa ở trước đó để thực hiện các điều kiện đúng 
+ Chỉ thị tiền xử lý **#ifdef, #ifndef** được hiểu đơn giản là đã được định nghĩa hoặc là chưa được định nghĩa. Với #ifdef thì nếu một #define trong điều kiện của #ifdef đã được định nghĩa thì nó sẽ thực hiện các câu lệnh trong điều kiện còn không thì chương trình sẽ không thực hiện nữa. Còn với #ifndef thì ngược lại, nếu một #define trong điều kiện của #ifndef chưa được định nghĩa thì nó sẽ thực hiện các câu lệnh trong điều kiện còn nếu đã được định nghĩa rồi thì nó sẽ không thực hiện nữa. Với #ifndef thì được sử dụng như là tránh các lỗi liên quan tới việc chèn thư viện bị trùng nhau trong một file.
+ **Variadic macro** Là một dạng macro cho phép nhận một số lượng biến tham số có thể thay đổi. Giúp định nghĩa các macro có thể xử lý một lượng biến đầu vào khác nhau.
# Bài 2 STDARG - ASSERT
## STDARG (stdarg.h)
**STDARG** là viết tắt của standard argument. Thư viện **stdarg.h**trong C cung cấp một cơ chế để các hàm có thể nhận một số lượng đối số thay đổi. Điều này rất hữu ích khi bạn không biết trước sẽ có bao nhiêu đối số được truyền vào hàm.

#### Các hàm chính trong stdarg.h:

+ va_list: Một kiểu dữ liệu đặc biệt dùng để lưu trữ thông tin về danh sách các đối số biến đổi.
+ va_start: Khởi tạo một đối tượng va_list trước khi truy cập các đối số.
+ va_arg: Truy cập đến một đối số cụ thể trong danh sách đối số biến đổi.
+ va_end: Kết thúc việc sử dụng danh sách đối số biến đổi.
## ASSERT (assert.h)
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
### Kết hợp STDARG và ASSERT
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
# Bài 3 Pointer
### khái niệm  
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
### Các loại pointer:
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








 



