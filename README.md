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
