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

# Bài 8: Memory layout
<details><summary>Chi tiết</summary>   
<p> 
  
## Khái niệm
<details><summary>Chi tiết</summary>   
<p>
	
#### Trong ngôn ngữ lập trình C, bộ nhớ của chương trình thường được phân chia thành các phân vùng khác nhau, mỗi phân vùng có mục đích và quy tắc sử dụng riêng. Dưới đây là một số phân vùng nhớ quan trọng trong C:
#### Text Segment
**Text Segment** là một phần của bộ nhớ trong mô hình bộ nhớ của một chương trình máy tính, được sử dụng để lưu trữ mã máy của chương trình. Cụ thể, Text Segment chứa mã máy đã được biên dịch từ mã nguồn của chương trình và được CPU thực thi để thực hiện các hành động quy định trong chương trình.
#### Một số đặc điểm:
#### Mã máy:
+ Chứa mã máy, tức là tập hợp các lệnh thực thi được CPU hiểu được.
+ Mã máy được tạo ra thông qua quá trình biên dịch từ mã nguồn của chương trình.
#### Quyền truy cập:
Text Segment thường có quyền đọc và thực thi, nhưng không có quyền ghi. điều này ngăn chặn chương trình việc tự sửa đổi mã máy của nó.
#### Kích thước cố định:
+ Kích thước của Text Segment thường là cố định khi chương trình được biên dịch.
+ Điều này giúp hệ điều hành và CPU dễ dàng quản lý vùng nhớ này.
#### Lưu Trữ Code và Hằng Số:
+ Bao gồm cả mã máy của các hàm và các hằng số.
+ Các hàm được gọi từ các phần khác của chương trình sẽ có địa chỉ trong Text Segment.

### Data Segment
**Data Segment** là một phần của bộ nhớ trong mô hình bộ nhớ của một chương trình máy tính, được sử dụng để lưu trữ dữ liệu tĩnh của chương trình. Dữ liệu tĩnh bao gồm biến toàn cục và biến tĩnh (static), tức là các biến mà không phụ thuộc vào thời gian chạy của chương trình. 
**Một số đặc điểm:**
**Biến Toàn Cục (Global Variables):**
+ Chứa giá trị của các biến toàn cục được khai báo trong chương trình.
+ Các biến này có thể được truy cập từ bất kỳ hàm nào trong chương trình.
#### Biến Tĩnh (Static Variables):
+ Chứa giá trị của các biến tĩnh, nghĩa là biến được khai báo với từ khóa static.
+ Có thể được truy cập chỉ trong phạm vi của hàm mà chúng được khai báo.
**Initialized Data Segment (Dữ liệu Đã Khởi Tạo):**
+ Chứa giá trị của các biến toàn cục và biến tĩnh được khởi tạo với giá trị ban đầu.
+ Dữ liệu này được sao chép từ bộ nhớ của chương trình thực thi.
**Uninitialized Data Segment (Dữ liệu Chưa Khởi Tạo):**
+ Chứa giá trị mặc định của các biến toàn cục và biến tĩnh mà không cần khởi tạo giá trị ban đầu.
+ Dữ liệu trong phân vùng này thường được xác định bởi giá trị 0.
**Quyền truy cập:** Data Segment thường có quyền đọc và ghi, nghĩa là dữ liệu có thể được đọc và sửa đổi trong quá trình thực thi của chương trình.
**Kích thước cố định:** Kích thước của Data Segment có thể thay đổi trong quá trình thực thi của chương trình khi các biến được khởi tạo hoặc giải phóng.
### Heap
**Heap** là một phần của bộ nhớ trong mô hình bộ nhớ của một chương trình máy tính, được sử dụng để cấp phát bộ nhớ động. Các biến được cấp phát trên heap không có kích thước xác định tại thời điểm biên dịch và có thể được quản lý động trong quá trình thực thi của chương trình.
#### Một số đặc điểm:
**Cấp phát động:**
+ Heap được sử dụng để cấp phát bộ nhớ động trong quá trình thực thi của chương trình.
+ Điều này cho phép chương trình tạo ra và giải phóng bộ nhớ theo nhu cầu, thích ứng với sự biến đổi của dữ liệu trong quá trình chạy.
+ **Quyền truy cập:** Bộ nhớ trên heap thường có quyền đọc và ghi, nghĩa là dữ liệu có thể được đọc và sửa đổi trong suốt thời gian chương trình chạy.
+ **Cấp Phát và Giải** Phóng Bộ Nhớ: Các hàm như malloc(), calloc(), realloc(), và free() được sử dụng để cấp phát và giải phóng bộ nhớ trên heap.
+ **Kích Thước Thay Đổi:** Kích thước của heap có thể thay đổi trong quá trình thực thi của chương trình, tùy thuộc vào các thao tác cấp phát và giải phóng bộ nhớ.
+ Không Giữ Giá Trị Mặc Định: Bộ nhớ trên heap không giữ giá trị mặc định như trong Data Segment. Nếu không được khởi tạo, giá trị của biến trên heap sẽ không xác định.
#### Ví dụ cấp phát động:
```bash
#include <stdio.h>
#include <stdlib.h>

int main() {
    // Cấp phát bộ nhớ động cho một biến kiểu int
    int *dynamicVar = (int *)malloc(sizeof(int));

    if (dynamicVar != NULL) {
        // Gán giá trị cho biến trên heap
        *dynamicVar = 42;

        // In giá trị
        printf("Value on heap: %d\n", *dynamicVar);

        // Giải phóng bộ nhớ trên heap
        free(dynamicVar);
    }

    return 0;
}

 ```


### Stack
**Stack** là một phần quan trọng của bộ nhớ trong mô hình bộ nhớ của một chương trình máy tính. Nó được sử dụng để lưu trữ các biến cục bộ, các giá trị trả về từ hàm, địa chỉ trả về và một số thông tin khác liên quan đến thực thi của chương trình. 
#### Một số đặc điểm:
+ **LIFO:** Stack hoạt động theo nguyên tắc LIFO, nghĩa là phần tử cuối cùng được thêm vào sẽ là phần tử đầu tiên được lấy ra.
+ **Các biến cục bộ:** Chứa các biến cục bộ, tức là các biến được khai báo trong các hàm và chỉ có giá trị trong phạm vi của hàm đó.
+ **Kích thước cố định:** Tùy thuộc vào hệ điều hành khác nhau
+ **Địa chỉ trả về:** Khi một hàm được gọi, địa chỉ trả về (return address) được đẩy vào ngăn xếp để theo dõi nơi chương trình sẽ tiếp tục sau khi hàm kết thúc thực thi.
+ **Thực hiện gọi hàm và trả về:** Khi một hàm được gọi, các giá trị và địa chỉ quan trọng liên quan đến hàm đó được đẩy vào ngăn xếp. Sau khi hàm kết thúc, những giá trị này được lấy ra để quay trở lại thực thi chương trình.
+ **Khối lệnh ( Frame):** Mỗi hàm khi được gọi tạo ra một khối lệnh (frame) trên ngăn xếp, chứa các biến cục bộ và các giá trị khác liên quan đến hàm.
+ **Stack pointer:** Con trỏ ngăn xếp (stack pointer) giữ địa chỉ hiện tại của stack và được cập nhật liên tục khi dữ liệu được đẩy vào hoặc lấy ra.
+ **Stack** là một cơ chế quan trọng trong quá trình thực thi chương trình và thường được sử dụng để quản lý luồng thực thi, gọi hàm, và theo dõi các biến cục bộ. Các ngôn ngữ lập trình thường sử dụng ngăn xếp để triển khai thực thi hàm và quản lý các biến cục bộ.
### Memory - mapped Segment
**Memory-mapped segment** là một phần của bộ nhớ trong mô hình bộ nhớ của một chương trình máy tính, được sử dụng để tương tác với các thiết bị ngoại vi thông qua các địa chỉ bộ nhớ. Thông thường, các thiết bị ngoại vi như cổng vào/ra (I/O ports) và thanh ghi của các thiết bị được ánh xạ trực tiếp vào không gian địa chỉ bộ nhớ của chương trình.
**Một số đặc điểm:**
+ Tương tác với thiết bị ngoại vi: Memory-mapped segment cho phép chương trình tương tác với các thiết bị ngoại vi bằng cách truy cập địa chỉ bộ nhớ tương ứng với các thanh ghi và cổng I/O của các thiết bị đó.
+ Địa chỉ bộ nhớ ánh xạ: Các địa chỉ bộ nhớ của các thanh ghi và cổng I/O của các thiết bị ngoại vi được ánh xạ vào không gian địa chỉ bộ nhớ của chương trình.
+ Quyền truy cập: Memory-mapped segment thường có thể có quyền đọc và ghi để cho phép chương trình gửi dữ liệu đến thiết bị và đọc dữ liệu từ thiết bị.
+ Giao tiếp với thiết bị ngoại vi: Thông qua Memory-mapped segment, chương trình có thể gửi lệnh và nhận dữ liệu từ các thiết bị ngoại vi, như cổng COM, bàn phím, màn hình và các thiết bị khác.
+ Sử dụng trong ngôn ngữ mã máy và assembly: Memory-mapped segment thường được sử dụng nhiều trong ngôn ngữ máy và ngôn ngữ gần với phần cứng để thực hiện các thao tác gần với phần cứng của hệ thống.
+ Điều khiển thiết bị: Ánh xạ địa chỉ bộ nhớ của các thanh ghi và cổng I/O của thiết bị ngoại vi cho phép chương trình kiểm soát và điều khiển các thiết bị ngoại vi.
**Lưu ý** rằng sử dụng Memory-mapped segment đôi khi yêu cầu quyền hệ điều hành và có thể chỉ có sẵn trong môi trường thực thi nào đó (ví dụ như hệ điều hành Unix-like).
  </p>
</details>

## Stack và Heap
<details><summary>Chi tiết</summary>   
<p> 
  
+ Bộ nhớ Heap và bộ nhớ Stack bản chất đều cùng là vùng nhớ được tạo ra và lưu trữ trong RAM khi chương trình được thực thi.
+ Bộ nhớ Stack được dùng để lưu trữ các biến cục bộ trong hàm, tham số truyền vào... Truy cập vào bộ nhớ này rất nhanh và được thực thi khi chương trình được biên dịch.
+ Bộ nhớ Heap được dùng để lưu trữ vùng nhớ cho những biến con trỏ được cấp phát động bởi các hàm malloc - calloc - realloc (trong C).

	**Kích thước vùng nhớ:**
+ Stack: kích thước của bộ nhớ Stack là cố định, tùy thuộc vào từng hệ điều hành, ví dụ hệ điều hành Windows là 1 MB, hệ điều hành Linux là 8 MB (lưu ý là con số có thể khác tùy thuộc vào kiến trúc hệ điều hành của bạn).
+ Heap: kích thước của bộ nhớ Heap là không cố định, có thể tăng giảm do đó đáp ứng được nhu cầu lưu trữ dữ liệu của chương trình.

	**Đặc điểm vùng nhớ:**
+ Stack: vùng nhớ Stack được quản lý bởi hệ điều hành, dữ liệu được lưu trong Stack sẽ tự động hủy khi hàm thực hiện xong công việc của mình.
+ Heap: Vùng nhớ Heap được quản lý bởi lập trình viên (trong C hoặc C++), dữ liệu trong Heap sẽ không bị hủy khi hàm thực hiện xong, điều đó có nghĩa bạn phải tự tay hủy vùng nhớ bằng câu lệnh free (trong C), và delete hoặc delete [] (trong C++), nếu không sẽ xảy ra hiện tượng rò rỉ bộ nhớ. 

	**Vấn đề lỗi xảy ra với vùng nhớ:**
+ Stack: bởi vì bộ nhớ Stack cố định nên nếu chương trình bạn sử dụng quá nhiều bộ nhớ vượt quá khả năng lưu trữ của Stack chắc chắn sẽ xảy ra tình trạng tràn bộ nhớ Stack (Stack overflow), các trường hợp xảy ra như bạn khởi tạo quá nhiều biến cục bộ, hàm đệ quy vô hạn,...
	**Ví dụ tràn bộ nhớ stack khi gọi hàm đệ quy vô hạn:**
 ```bash
int foo(int x){
    printf("De quy khong gioi han\n");
    return foo(x);
}
```
**Heap:**  Nếu bạn liên tục cấp phát vùng nhớ mà không giải phóng thì sẽ bị lỗi tràn vùng nhớ Heap (Heap overflow). Nếu bạn khởi tạo một vùng nhớ quá lớn mà vùng nhớ Heap không thể lưu trữ một lần được sẽ bị lỗi khởi tạo vùng nhớ Heap thất bại.
**Ví dụ trường hợp khởi tạo vùng nhớ Heap quá lớn:**
```bash
int *A = (int *)malloc(18446744073709551615);
```


</p>
</details>

</p>
</details>

# Bài 9: JSON
<details><summary>Chi tiết</summary>   
<p> 

  
## Khái niệm 
 
+ JSON là viết tắt của "JavaScript Object Notation" (Ghi chú về Đối tượng JavaScript). Đây là một định dạng truyền tải dữ liệu phổ biến trong lập trình và giao tiếp giữa các máy chủ và trình duyệt web, cũng như giữa các hệ thống khác nhau.
+ JSON được thiết kế để dễ đọc và dễ viết cho con người, cũng như dễ dàng để phân tích và tạo ra cho máy tính. Nó sử dụng một cú pháp nhẹ dựa trên cặp key - value, tương tự như các đối tượng và mảng trong JavaScript. Mỗi đối tượng JSON bao gồm một tập hợp các cặp "key" và "value", trong khi mỗi mảng JSON là một tập hợp các giá trị.
### Các định dạng 
```bash
1
{
  "name": “John Doe",
  "age": 30.1234,
  "city": "New York",
  "isStudent": true,
  "grades": [85, 90, 78]
}

2
typedef enum {
    JSON_NULL,
    JSON_BOOLEAN,
    JSON_NUMBER,
    JSON_STRING,
    JSON_ARRAY,
    JSON_OBJECT
} JsonType
3
[
  {
    "name": "John Doe",
    "age": 30,
    "city": "New York",
    "occupation": "Software Engineer",
    "isStudent": false
  },
  {
    "name": "Jane Smith",
    "age": null,
    "city": "Los Angeles",
    "contact": {
      "email": "jane.smith@example.com",
      "phone": "555-1234"
    }
  },
  {
    "name": "Bob Johnson",
    "age": 35,
    "city": "Chicago"
  }
]

 ví dụ
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stddef.h>
#include <ctype.h>
#include <stdbool.h>




typedef enum {
    JSON_NULL,
    JSON_BOOLEAN,
    JSON_NUMBER,
    JSON_STRING,
    JSON_ARRAY,
    JSON_OBJECT
} JsonType;


typedef struct JsonValue {
    JsonType type;
    union {
        int boolean;
        double number;
        char *string;
        struct {
            struct JsonValue *values;
            size_t count;
        } array;
        struct {
            char **keys;
            struct JsonValue *values;
            size_t count;
        } object;
    } value;
} JsonValue;



JsonValue *parse_json(const char **json);

void free_json_value(JsonValue *json_value);

static void skip_whitespace(const char **json) {
    while (isspace(**json)) {
        (*json)++;
    }
}

JsonValue *parse_null(const char **json) {
    skip_whitespace(json);
    if (strncmp(*json, "null", 4) == 0) {
        JsonValue *value = (JsonValue *) malloc(sizeof(JsonValue));
        value->type = JSON_NULL;
        *json += 4;
        return value;
    }
    return NULL;
}

JsonValue *parse_boolean(const char **json) {
    skip_whitespace(json);
    JsonValue *value = (JsonValue *) malloc(sizeof(JsonValue));
    if (strncmp(*json, "true", 4) == 0) {
        value->type = JSON_BOOLEAN;
        value->value.boolean = true;
        *json += 4;
    } else if (strncmp(*json, "false", 5) == 0) {
        value->type = JSON_BOOLEAN;
        value->value.boolean = false;
        *json += 5;
    } else {
        free(value);
        return NULL;
    }
    return value;
}

JsonValue *parse_number(const char **json) {
    skip_whitespace(json);
    char *end;


    double num = strtod(*json, &end);
    if (end != *json) {
        JsonValue *value = (JsonValue *) malloc(sizeof(JsonValue));
        value->type = JSON_NUMBER;
        value->value.number = num;
        *json = end;
        return value;
    }
    return NULL;
}

JsonValue *parse_string(const char **json) {
    skip_whitespace(json);


    if (**json == '\"') {
        (*json)++;
        const char *start = *json;
        while (**json != '\"' && **json != '\0') {
            (*json)++;
        }
        if (**json == '\"') {
            size_t length = *json - start; // 3
            char *str = (char *) malloc((length + 1) * sizeof(char));
            strncpy(str, start, length);
            str[length] = '\0';


            JsonValue *value = (JsonValue *) malloc(sizeof(JsonValue));
            value->type = JSON_STRING;
            value->value.string = str;
            (*json)++;
            return value;
        }
    }
    return NULL;
}



JsonValue *parse_array(const char **json) {
    skip_whitespace(json);
    if (**json == '[') {
        (*json)++;
        skip_whitespace(json);

        JsonValue *array_value = (JsonValue *)malloc(sizeof(JsonValue));
        array_value->type = JSON_ARRAY;
        array_value->value.array.count = 0;
        array_value->value.array.values = NULL;

        /*
        double arr[2] = {};
        arr[0] = 30;
        arr[1] = 70;
        */

        while (**json != ']' && **json != '\0') {
            JsonValue *element = parse_json(json); // 70
            if (element) {
                array_value->value.array.count++;
                array_value->value.array.values = (JsonValue *)realloc(array_value->value.array.values, array_value->value.array.count * sizeof(JsonValue));
                array_value->value.array.values[array_value->value.array.count - 1] = *element;
                free(element);
            } else {
                break;
            }
            skip_whitespace(json);
            if (**json == ',') {
                (*json)++;
            }
        }
        if (**json == ']') {
            (*json)++;
            return array_value;
        } else {
            free_json_value(array_value);
            return NULL;
        }
    }
    return NULL;
}

JsonValue *parse_object(const char **json) {
    skip_whitespace(json);
    if (**json == '{') {
        (*json)++;
        skip_whitespace(json);

        JsonValue *object_value = (JsonValue *)malloc(sizeof(JsonValue));
        object_value->type = JSON_OBJECT;
        object_value->value.object.count = 0;
        object_value->value.object.keys = NULL;
        object_value->value.object.values = NULL;



        while (**json != '}' && **json != '\0') {
            JsonValue *key = parse_string(json);
            if (key) {
                skip_whitespace(json);
                if (**json == ':') {
                    (*json)++;
                    JsonValue *value = parse_json(json);
                    if (value) {
                        object_value->value.object.count++;
                        object_value->value.object.keys = (char **)realloc(object_value->value.object.keys, object_value->value.object.count * sizeof(char *));
                        object_value->value.object.keys[object_value->value.object.count - 1] = key->value.string;

                        object_value->value.object.values = (JsonValue *)realloc(object_value->value.object.values, object_value->value.object.count * sizeof(JsonValue));
                        object_value->value.object.values[object_value->value.object.count - 1] = *value;
                        free(value);
                    } else {
                        free_json_value(key);
                        break;
                    }
                } else {
                    free_json_value(key);
                    break;
                }
            } else {
                break;
            }
            skip_whitespace(json);
            if (**json == ',') {
                (*json)++;
            }
        }
        if (**json == '}') {
            (*json)++;
            return object_value;
        } else {
            free_json_value(object_value);
            return NULL;
        }
    }
    return NULL;
}


JsonValue *parse_json(const char **json) { 
    while (isspace(**json)) {
        (*json)++;
    }



    switch (**json) {
        case 'n':
            return parse_null(json);
        case 't':
        case 'f':
            return parse_boolean(json);
        case '\"':
            return parse_string(json);
        case '[':
            return parse_array(json);
        case '{':
            return parse_object(json);
        default:
            if (isdigit(**json) || **json == '-') {
                return parse_number(json);
            } else {
                // Lỗi phân tích cú pháp
                return NULL;
            }
    }
}



////////////




/////////////

void free_json_value(JsonValue *json_value) {
    if (json_value == NULL) {
        return;
    }

    switch (json_value->type) {
        case JSON_STRING:
            free(json_value->value.string);
            break;

        case JSON_ARRAY:
            for (size_t i = 0; i < json_value->value.array.count; i++) {
                free_json_value(&json_value->value.array.values[i]);
            }
            free(json_value->value.array.values);
            break;

        case JSON_OBJECT:
            for (size_t i = 0; i < json_value->value.object.count; i++) {
                free(json_value->value.object.keys[i]);
                free_json_value(&json_value->value.object.values[i]);
            }
            free(json_value->value.object.keys);
            free(json_value->value.object.values);
            break;

        default:
            break;
    }
}



void test(JsonValue* json_value){
    if (json_value != NULL && json_value->type == JSON_OBJECT) {
        // Truy cập giá trị của các trường trong đối tượng JSON
        size_t num_fields = json_value->value.object.count;
        size_t num_fields2 = json_value->value.object.values->value.object.count;
        for (size_t i = 0; i < num_fields; ++i) {

            char* key = json_value->value.object.keys[i];
            JsonValue* value = &json_value->value.object.values[i];

            JsonType type = (int)(json_value->value.object.values[i].type);


            if(type == JSON_STRING){
                printf("%s: %s\n", key, value->value.string);
            }

            if(type == JSON_NUMBER){
                printf("%s: %f\n", key, value->value.number);
            }

            if(type == JSON_BOOLEAN){
                printf("%s: %s\n", key, value->value.boolean ? "True":"False");
            }

            if(type == JSON_OBJECT){
                printf("%s: \n", key);
                test(value);
            }

            if(type == JSON_ARRAY){
                printf("%s: ", key);
                for (int i = 0; i < value->value.array.count; i++)
                {
                   test(value->value.array.values + i);
                } 
                printf("\n");
            }

  
        }

     
    }
    else 
    {
            if(json_value->type == JSON_STRING){
                printf("%s ", json_value->value.string);
            }

            if(json_value->type == JSON_NUMBER){
                printf("%f ", json_value->value.number);
            }

            if(json_value->type == JSON_BOOLEAN){
                printf("%s ", json_value->value.boolean ? "True":"False");
            }

            if(json_value->type == JSON_OBJECT){
                printf("%s: \n", json_value->value.object.keys);
                test(json_value->value.object.values);
                           
            }
    }

}




int main(int argc, char const *argv[])
{
     // Chuỗi JSON đầu vào
    
    const char* json_str = "{"
                        "\"1001\":{"
                          "\"SoPhong\":3,"
                          "\"NguoiThue\":{"
                            "\"Ten\":\"Nguyen Van A\","
                            "\"CCCD\":\"1920517781\","
                            "\"Tuoi\":26,"
                            "\"ThuongTru\":{"
                              "\"Duong\":\"73 Ba Huyen Thanh Quan\","
                              "\"Phuong_Xa\":\"Phuong 6\","
                              "\"Tinh_TP\":\"Ho Chi Minh\""
                            "}"
                          "},"
                          "\"SoNguoiO\":{"
                            "\"1\":\"Nguyen Van A\","
                            "\"2\":\"Nguyen Van B\","
                            "\"3\":\"Nguyen Van C\""
                          "},"
                          "\"TienDien\": [24, 56, 98],"
                          "\"TienNuoc\":30.000"
                        "},"
                        "\"1002\":{"
                          "\"SoPhong\":5,"
                          "\"NguoiThue\":{"
                            "\"Ten\":\"Phan Hoang Trung\","
                            "\"CCCD\":\"012345678912\","
                            "\"Tuoi\":24,"
                            "\"ThuongTru\":{"
                              "\"Duong\":\"53 Le Dai Hanh\","
                              "\"Phuong_Xa\":\"Phuong 11\","
                              "\"Tinh_TP\":\"Ho Chi Minh\""
                            "}"
                          "},"
                          "\"SoNguoiO\":{"
                            "\"1\":\"Phan Van Nhat\","
                            "\"2\":\"Phan Van Nhi\","
                            "\"2\":\"Phan Van Tam\","
                            "\"3\":\"Phan Van Tu\""
                          "},"
                          "\"TienDien\":23.000,"
                          "\"TienNuoc\":40.000"
                        "}"
                      "}";
    

    // Phân tích cú pháp chuỗi JSON
    JsonValue* json_value = parse_json(&json_str);



   test(json_value);

    // Kiểm tra kết quả phân tích cú pháp

       // Giải phóng bộ nhớ được cấp phát cho JsonValue
    free_json_value(json_value);
    
    

        //printf("test = %x", '\"');

       // hienthi(5);
    
    return 0;
}




```

</p>
</details>

# Bài 10: Linked List
<details><summary>Chi tiết</summary>   
<p> 
	
## Khái niệm
**Linked list** là một cấu trúc dữ liệu trong lập trình máy tính, được sử dụng để tổ chức và lưu trữ dữ liệu. Một linked list bao gồm một chuỗi các "nút" (nodes), mỗi nút chứa một giá trị dữ liệu và một con trỏ (pointer) đến nút tiếp theo trong chuỗi.
**Có hai loại linked list chính:**
+ Singly Linked List (Danh sách liên kết đơn): Mỗi nút chỉ chứa một con trỏ đến nút tiếp theo trong chuỗi.
+ Doubly Linked List (Danh sách liên kết đôi): Mỗi nút chứa hai con trỏ, một trỏ đến nút tiếp theo và một trỏ đến nút trước đó.
+ Một linked list cung cấp một cách linh hoạt để thêm, xóa và chèn các phần tử mà không cần phải di chuyển toàn bộ dãy số như mảng. Tuy nhiên, nó cũng có một số nhược điểm, như việc cần thêm một con trỏ cho mỗi nút, tăng độ phức tạp của bộ nhớ và có thể dẫn đến hiệu suất kém hơn trong một số trường hợp so với mảng.
**Dưới đây là định nghĩa 1 node trong singly linked list:**
  
 ```bash

struct Node {
    int data;         // Dữ liệu của nút
    Node* next;       // Con trỏ đến nút tiếp theo trong danh sách
};
```


**Một số thao tác trong list:**

 ```bash
	Khởi tạo một node:
node *createNode(int value)
{
    node *ptr = (node*)malloc(sizeof(node));
    ptr->value = value;
    ptr->next = NULL;
    return ptr;
}
```

**Chèn một node vào cuối list:**
 ```bash
void push_back(node** array, int value)
{
    node *temp, *p;
    temp = createNode(value);
    
    p = *array;          // use p instead of array because we are using pointer, use array will change the structure of linkedlist

    if (*array == NULL)   // if array doesn't have any node yet
    {
        
        *array = temp;
    }
    else                // if array has some node
    {      
        while (p->next != NULL) // which mean the current node is not the last node
        {
            p = p->next;    // check next node until it a last node
            
        }
        
        p->next = temp;     // change it next member point to address of new node have just create
    }
}
```

**Xóa node cuối cùng của list:**
 
 ```bash
void pop_back(node **array)
{
    node *p, *temp;
    p = *array;
    int i = 0; // to 

    while (p->next != NULL)     // free the last node in the list
    {
        p = p->next;
        i++;
    }
    free(p);

    temp = *array;
    int j;
    for ( j = 0; j < i - 1 ; j++)    // change the next member of the node at the (last - 1) position to NULL
    {
        temp = temp->next;
    }
    
    temp->next = NULL;
}
```
</p>
</details>

# Bài 11: Stack - Queue
<details><summary>Chi tiết</summary>   
<p> 
  
## Stack
<details><summary>Chi tiết</summary>   
<p> 
	
**Stack (ngăn xếp)** là một cấu trúc dữ liệu tuân theo nguyên tắc "Last In, First Out" (LIFO), nghĩa là phần tử cuối cùng được thêm vào stack sẽ là phần tử đầu tiên được lấy ra. 
**Các thao tác cơ bản trên stack bao gồm:**
+ “ push” (đẩy) để thêm một phần tử vào đỉnh của stack.
+ “ pop” để xóa một phần tử ở đỉnh stack.
+ “ top” để lấy giá trị của phần tử ở đỉnh stack.
+ 
```bash
#include <stdio.h>
#include <stdlib.h>

typedef struct Stack {
    int* items;
    int size;
    int top;
} Stack;

void initialize( Stack *stack, int size) {
    stack->items = (int*) malloc(sizeof(int) * size);
    stack->size = size;
    stack->top = -1;
}

int is_empty( Stack stack) {
    return stack.top == -1;
}

int is_full( Stack stack) {
    return stack.top == stack.size - 1;
}

void push( Stack *stack, int value) {
    if (!is_full(*stack)) {
        stack->items[++stack->top] = value;
    } else {
        printf("Stack overflow\n");
    }
}

int pop( Stack *stack) {
    if (!is_empty(*stack)) {
        return stack->items[stack->top--];
    } else {
        printf("Stack underflow\n");
        return -1;
    }
}

int top( Stack stack) {
    if (!is_empty(stack)) {
        return stack.items[stack.top];
    } else {
        printf("Stack is empty\n");
        return -1;
    }
}

int main() {
    Stack stack1;
    initialize(&stack1, 5);


    push(&stack1, 10);
    push(&stack1, 20);
    push(&stack1, 30);
    push(&stack1, 40);
    push(&stack1, 50);
    push(&stack1, 60);

    printf("Top element: %d\n", top(stack1));

    printf("Pop element: %d\n", pop(&stack1));
    printf("Pop element: %d\n", pop(&stack1));

    printf("Top element: %d\n", top(stack1));

    return 0;
}

```

</p>
</details>



# Queue
<details><summary>Chi tiết</summary>   
<p> 
  
**Queue** là một cấu trúc dữ liệu tuân theo nguyên tắc "First In, First Out" (FIFO), nghĩa là phần tử đầu tiên được thêm vào hàng đợi sẽ là phần tử đầu tiên được lấy ra. 
**Các thao tác cơ bản trên hàng đợi bao gồm:**
+ “enqueue” (thêm phần tử vào cuối hàng đợi)
+ “dequeue” (lấy phần tử từ đầu hàng đợi). 
+ “front” để lấy giá trị của phần tử đứng đầu hàng đợi.
  
```bash

#include <stdio.h>
#include <stdlib.h>


typedef struct Queue {
    int* items;
    int size;
    int front, rear;
} Queue;

void initialize(Queue *queue, int size) 
{
    queue->items = (int*) malloc(sizeof(int)* size);
    queue->front = -1;
    queue->rear = -1;
    queue->size = size;
}

int is_empty(Queue queue) {
    return queue.front == -1;
}

int is_full(Queue queue) {
    return (queue.rear + 1) % queue.size == queue.front;
}

void enqueue(Queue *queue, int value) {
    if (!is_full(*queue)) {
        if (is_empty(*queue)) {
            queue->front = queue->rear = 0;
        } else {
            queue->rear = (queue->rear + 1) % queue->size;
        }
        queue->items[queue->rear] = value;
    } else {
        printf("Queue overflow\n");
    }
}

int dequeue(Queue *queue) {
    if (!is_empty(*queue)) {
        int dequeued_value = queue->items[queue->front];
        if (queue->front == queue->rear) {
            queue->front = queue->rear = -1;
        } else {
            queue->front = (queue->front + 1) % queue->size;
        }
        return dequeued_value;
    } else {
        printf("Queue underflow\n");
        return -1;
    }
}

int front(Queue queue) {
    if (!is_empty(queue)) {
        return queue.items[queue.front];
    } else {
        printf("Queue is empty\n");
        return -1;
    }
}

int main() {
    Queue queue;
    initialize(&queue, 3);

    enqueue(&queue, 10);
    enqueue(&queue, 20);
    enqueue(&queue, 30);

    printf("Front element: %d\n", front(queue));

    printf("Dequeue element: %d\n", dequeue(&queue));
    printf("Dequeue element: %d\n", dequeue(&queue));

    printf("Front element: %d\n", front(queue));

    enqueue(&queue, 40);
    enqueue(&queue, 50);
    printf("Dequeue element: %d\n", dequeue(&queue));
    printf("Front element: %d\n", front(queue));

    return 0;
}
```

</p>
</details>

</p>
</details>






