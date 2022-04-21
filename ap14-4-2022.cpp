#include <stdio.h>
#include <stdlib.h>
#include <iomanip>
#include <conio.h>
#include <time.h>
struct ToDo // tạo struct todo 
{
    char buffer[101];  // chứa dữ liệu của các node
    struct ToDo *next; // dung để liên kết các node với nhau
    int count; // biến count dùng để lưu số lượng node 
};
typedef struct ToDo todo;  
todo *start = NULL; // khởi tạo con trỏ/node start với giá trị bằng NULL
void delay(int number_of_seconds) //*delay() hàm được định nghĩa sẳn 
{
    int milli_seconds = 1000 * number_of_seconds;

    clock_t start_time = clock();

    while (clock() < start_time + milli_seconds)
        ;
}
void adjustcount() 
{
    todo *temp; // khai báo node temp
    int i = 1; // khởi tạo biến i với giá trị ban đầu là 1
    temp = start;// gán node temp =node start
    while (temp != NULL) // vòng while để duyệt qua các node để xác định số node hiện có thông qua biến count
    {
        temp->count = i;
        i++;
        temp = temp->next;
    }
    // count lúc này đang mang giá trị bằng với số node
}
void createtodo() // hàm tạo todo mới
{
    char check; // khởi tạo biến check để kiểm tra mong muốn của người dùng
    todo *add, *temp; // tạo hai node add (để thêm todo) và temp 
    system("cls"); // *hàm được định nghĩa sẳn để xóa sạch màn hình 

    while (17) // sử dụng vòng lặp vô hạn với điều kiện luôn đúng
    {
        printf("\nVUI LONG XAC NHAN, BAN CO MUON TAO TODO MOI KHONG ? NEU CO GO 'y'(yes), NEU KHONG GO 'n'(no) DE TIEP TUC\n\t\t");
        fflush(stdin);// dung xóa bộ nhớ đệm 
        scanf("%s", &check); 
        if (check == 'n')//không tạo thêm/mới todo
            break;
        else if (check == 'y' )//tạo thêm/mới todo
        {
            if (start == NULL) // nếu chưa có node (chưa có todo nào được khởi tạo từ trước) nào 
            {
                // *calloc để cấp phát bộ nhớ động
                // cấp phát bộ nhớ cho add
                add = (todo *)calloc(1, sizeof(todo)); //*ptr = (cast-type*)calloc(n, element-size);
                start = add;  // gán add cho start
                printf("\nMOI BAN NHAP TODO MOI: .....\n");
                fflush(stdin);
                gets(add->buffer); // nhập todo
                add->count = 1; // tắng biến count lên 1 tức nghĩa trong todo chỉ mới có 1 todo
                start->next = NULL; // cho start->next=NULL vì đây là node đầu tiên 
            }
            else // ngược lại đã có todo từ trước 
            {
                temp = (todo *)calloc(1, sizeof(todo)); // cấp phát bộ nhớ cho temp
                printf("\nMOI BAN NHAP TODO MOI: .....\n");
                fflush(stdin);
gets(temp->buffer);
temp->next = NULL; //
                add->next = temp;  //thêm todo(nodo) vào sau todo đã thêm 
                add = add->next;   // !lấy ví dụ minh họa
            }
            adjustcount(); // gọi lại hàm adjustcount() để lưu lại số lượng node vừa thêm
        }
        else // trường hợp người sử dụng sự dụng sai cú pháp cho sẵn 
        {
            printf("\nSAI CU PHAP, MOI BAN NHAP LAI!");
            delay(1);
            createtodo();// ghi dai thoi xiu cop
        }
    }
}
void seetodo()// xem todo đã tạo
{
    system("cls");// hàm system ("sls ") để xoa màn hình 
    todo *temp; // tao node temp
    temp = start; // gán giá trị temp = start
    if (start == NULL)// nếu giá trị ban đầu = 0 thì: 
        printf("\n\nBAN CHUA CO TODO \n\n");
    while (temp != NULL)// vòng lặp while .... dùng để duyệt qua các node
    {
        printf("%d.)", temp->count);
        puts(temp->buffer);
        fflush(stdin);// xoa bo nhớ đệm
        temp = temp->next;
    }

    printf("\n\n\n");
    system("pause");// hàm system ("pause") dùng để dừng chương trình để chuẩn bị cho 1 lần nhập phím
}
void deletetodo()// hàm xóa các todo
{
    system("cls");// hàm để xóa toàn bộ chương trình
    int x;// khai báo một biến x
    todo *del, *temp; // tạo 2 node del va temp
    if (start == NULL)// nếu chưa có todo list (node nào) thì in ra dòng dưới
        printf("\n\nKHONG CO TODO CAN LAM TRONG HOM NAY!:-)\n\n\n");
    else // ngược lại 
    {
        printf("\nNHAP DIA CHI TODO MA BAN MUON XOA.\n\t\t");
        scanf("%d", &x);
        del = start;// gán giá trị start cho del  
        temp = start->next; // gán temp cho node tiếp theo 
        while (1)// vòng lặp vô hạn với điều kiện luôn đúng
        {
            if (del->count == x)// kiểm tra coi đúng node cần xóa chưa nếu đúng thì xóa
            {
                start = start->next;
                // free giải phóng bộ nhớ
                free(del);  // giải phóng bộ nhớ (todo) có trong del
                adjustcount();// gọi lại hàm adjustcount() để lưu lại số lượng node 
                break;// dừng lại vòng while
            }

            if (temp->count == x)// kiểm tra    
            {
                del->next = temp->next;
                free(temp);
                adjustcount();
                break;
            }
            else
            {
                del = temp;
                temp = temp->next;
            }
        }
    }
    system("pause");// hàm system ("pause") dùng để dừng chương trình để chuẩn bị cho 1 lần nhập phím
}
void comman(char choice)// đưa ra một option cho người dùng lựa chọn 
{
    int choiceTempo;
    choiceTempo = choice;
    switch (choiceTempo)
    {
    case '1':
        seetodo();
        break;
    case '2':
        createtodo();
        break;
case '3':
        deletetodo();
        break;
    case '4':
        exit(1);
        break;
    default:
        printf("\nLUA CHON KHONG HOP LE :-(\n");
        printf("\nMOI BAN NHAP LAI SU LUA CHON: ");
        scanf("%s", &choiceTempo);
        comman(choiceTempo);
    }
}
void INTERFACE()// render ra giao diện của todolist
{
    system("color 3F");
    printf("\n\n\n\n");
    printf("\t~~~~~~~~~~~~~~~~~~~~~"
           "~~~~~~~~~~~~~~~~~~~~~~~~"
           "~~~~~~~~~~~~~~~~~~~~~~~~"
           "~~~~~~~~~~~~~~~~~~~~~~~"
           "~~~~~~~~~~\n");
    printf("\t~~~~~~~~~~~~~~~~~~~~~~"
           "~~~~~~~~~~~~~~~~~~~~~~~"
           "~~~~~~~~~~~~~~~~~~~~~~~"
           "~~~~~~~~~~~~~~~~~~~~~~~~"
           "~~~~~~~~~~\n\n");
    printf("\t} : } : } : } : } : } "
           ": } : } : } :   "
           " "
           "CHAO BAN DEN VOI TODO LIST : { : { : { : { : { "
           ": { : { : { : {\n\n");
    printf("\t~~~~~~~~~~~~~~~~~~~~~"
           "~~~~~~~~~~~~~~~~~~~~~~~~"
           "~~~~~~~~~~~~~~~~~~~~~~~~~"
"~~~~~~~~~~~~~~~~~~~~~~"
           "~~~~~~~~~~\n");
    printf("\t~~~~~~~~~~~~~~~~~~~~~~"
           "~~~~~~~~~~~~~~~~~~~~~~~"
           "~~~~~~~~~~~~~~~~~~~~~~~"
           "~~~~~~~~~~~~~~~~~~~~~~~~"
           "~~~~~~~~~~\n");
    system("pause");
}
int main()
{
    char choice;
    INTERFACE();
    while (1)
    {
        system("cls");
        printf("\n\n\n\n\n\n\n\n");
        printf("\t\t\t\t\tCHON '1' DE XEM TODOS TRONG NGAY\n");
        printf("\t\t\t\t\tCHON '2' DE TAO TODO MOI CHO RIENG BAN\n");
        printf("\t\t\t\t\tCHON '3' DE XOA TODO\n");
        printf("\t\t\t\t\tCHON '4' DE THOAT KHOI UNG DUNG\n");
        printf("\t\t\t\t\tNHAP LUA CHON CUA BAN:");
        scanf("%s", &choice);
        comman(choice);
    }
}
