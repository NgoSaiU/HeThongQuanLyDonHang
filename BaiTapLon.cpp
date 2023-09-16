#include <iostream>
#include <string>
#include <fstream>
#include <conio.h>
#include <iomanip>
#define MAX 20

using namespace std;

struct maSo
{
    string maTinh, tenTinh;
    string maTinhGui, maTinhNhan;
    int thuTu = 0;
};

struct thongTinDonHang
{
    maSo MS;
    string tenGui, tenNhan, maHang;
    string diaChiGui, diaChiNhan;
    string SDTGui, SDTNhan;
    int loaiHang, trongLuong;
    double phiVanChuyen;
};

struct Node
{
    thongTinDonHang info;
    Node *link;
};

struct khachThanThiet
{
    string ten;
    double phiVC = 0;
};

typedef struct Node *node;

node first;

void init(node &first)
{
    first = NULL;
}

node khoiTaoNodeDonHang(thongTinDonHang x)
{
    node p = new Node;
    if (p == NULL)
    {
        cout << "\nCap phat that bai !";
        return NULL;
    }
    p->info = x;
    p->link = NULL;
    return p;
}
int soLuongDonHang(node firts);
void chenDau(node &first, thongTinDonHang x);
void chenCuoi(node &first, thongTinDonHang x);
void chenGiua(node &first, int x, thongTinDonHang s);

int xoaDau(node &first);
int xoaCuoi(node &first);
int xoaGiua(node &first, int x);
void nhap1DonHang(thongTinDonHang &s);
void nhapDSDonHang(node &first, int n);
void docThongTinMotGoiHang(ifstream &filein, thongTinDonHang &sv);
void docDanhSachGoiHang(ifstream &filein, node &first);
void xuat1DonHang(thongTinDonHang s, int stt);
void xuatDSDonHang();

int loaiHangGuiNhieu(node first);
double donHangPhiVCMax(node a);
void xuatLoaiHang(int x);
void xuatTrongLuong(int x);
int demHangGui(string s);
int demHangNhan(string s);
int xoaTatCaDonHang(node &a);
int docSLTinh();
void docMaTinh(maSo *ms, int n);
void xuatTenTinh(maSo *list, int n, string soTinh);
void xuatMaTinh(maSo *list, int n, string Tinh);
void ghiDSDonHang(thongTinDonHang ds);
void khachHangThanThiet();
void hoanVi(thongTinDonHang &x, thongTinDonHang &y);
void sapXepHangTheoKhuVuc(node first);
void XuatGoiHangGuiTungKhuVucTinhThanh(node fist);
void xuatDonHang(thongTinDonHang s);
int soHangCanGui(string x);

int main()
{
    thongTinDonHang s;
    int chon, n;
    bool nhap = false;
    char thoat;
    ifstream filein;
    init(first);

    do
    {

        do
        {
            system("cls");
            s.MS.thuTu = soLuongDonHang(first);
            cout << "+-------------------------------------MENU--------------------------------------+" << endl;
            cout << "|\t\t 1. Nhap thong tin don hang tu ban phim.                   \t|" << endl
                 << "|\t\t 2. Nhap thong tin don hang tu file txt.                   \t|" << endl
                 << "|\t\t 3. Ghi danh sach don hang vao file txt.                   \t|" << endl
                 << "|\t\t 4. Xuat danh sach khach hang.                             \t|" << endl
                 << "|\t\t 5. Them don hang tai vi tri dau danh sach.                \t|" << endl
                 << "|\t\t 6. Them don hang tai vi tri giua danh sach.               \t|" << endl
                 << "|\t\t 7. Them don hang tai vi tri cuoi danh sach.               \t|" << endl
                 << "|\t\t 8. Xoa don hang tai vi tri dau danh sach.                 \t|" << endl
                 << "|\t\t 9. Xoa don hang tai vi tri giua danh sach.                \t|" << endl
                 << "|\t\t10. Xoa don hang tai vi tri cuoi danh sach                 \t|" << endl
                 << "|\t\t11. Sap xep hang theo tung khu vuc tinh thanh cua          \t|" << endl
                 << "|\t\t    noi nhan, trong tung nhom tinh thanh sap xep theo loai.\t|" << endl
                 << "|\t\t12. Them 1 don hang van dam bao duoc thu tu da sap xep.    \t|" << endl
                 << "|\t\t13. Xuat goi hang can gui tung khu vuc tinh thanh.         \t|" << endl
                 << "|\t\t14. Xuat khach hang than thiet                             \t|" << endl
                 << "|\t\t15. Nhap ten de biet so luong hang da gui va da nhan.      \t|" << endl
                 << "|\t\t16. Khach hang thuong gui loai hang nao nhat?              \t|" << endl
                 << "|\t\t17. Xuat thong tin cac don hang co phi van chuyen cao nhat.\t|" << endl
                 << "|\t\t18. Xoa tat ca don hang da luu.                            \t|" << endl
                 << "|\t\t19. Thoat chuong trinh.                                    \t|" << endl;
            cout << "+-------------------------------------------------------------------------------+" << endl;
            cout << "\t\tLua chon cua ban: ";
            cin >> chon;
            if (chon <= 0)
            {
                cout << "Ban khong the nhap so bang 0 hoac nho hon 0!" << endl;
                _getch();
            }
            else if (chon > 19)
            {
                cout << "Ban nhap so qua yeu cau. Vui long nhap lai!" << endl;
                _getch();
            }
        } while (chon <= 0 || chon > 19);

        switch (chon)
        {
        case 1:
        {

            do
            {
                cout << "Nhap so luong don hang: ";
                cin >> n;
                cout << endl
                     << endl;
                if (n <= 0)
                    cout << "Khong the nhap don hang bang 0 hoac nho hon 0!" << endl;
            } while (n <= 0);
            nhapDSDonHang(first, n);
            nhap = true;
            break;
        }

        case 2:
        {
            ifstream filein;
            filein.open("danhSachDonHang.txt", ios::in);
            if (filein.is_open())
            {
                docDanhSachGoiHang(filein, first);
                cout << "Doc file thanh cong" << endl;
                filein.close();
            }
            else
                cout << "Khong the mo file\n";
            nhap = true;
            break;
        }

        case 3:
        {
            if (nhap)
            {
                ghiDSDonHang(s);
            }
            else
                cout << "Ban chua nhap don hang nao. Vui long thu lai sau!" << endl;
            break;
        }

        case 4:
        {
            if (nhap)
            {
                xuatDSDonHang();
            }
            else
                cout << "Ban chua nhap don hang nao. Vui long thu lai sau!" << endl;
            break;
        }

        case 5:
        {
            nhap1DonHang(s);
            chenDau(first, s);
            break;
        }

        case 6:
        {
            int x;
            do
            {
                cout << "Nhap vi tri can chen: ";
                cin >> x;
                if (x < 1 || x > soLuongDonHang(first) + 1)
                    cout << "\nNhap vi tri sai. Vui long nhap lai!\n";
            } while (x < 1 || x > soLuongDonHang(first) + 1);
            nhap1DonHang(s);
            chenGiua(first, x, s);
            break;
        }

        case 7:
        {
            nhap1DonHang(s);
            chenCuoi(first, s);
            break;
        }

        case 8:
        {
            if (nhap)
            {
                if (xoaDau(first))
                    cout << "Xoa don hang dau thanh cong!" << endl;
                else
                    cout << "Xoa don hang dau khong thanh cong!" << endl;
            }
            else
                cout << "Ban chua nhap don hang nao. Vui long thu lai sau!" << endl;
            break;
        }

        case 9:
        {
            if (nhap)
            {
                int x;
                do
                {

                    cout << "Nhap vi tri can xoa: ";
                    cin >> x;
                    if (x < 1 || x > soLuongDonHang(first))
                        cout << "\nNhap vi tri sai. Vui long nhap lai!\n";
                } while (x < 1 || x > soLuongDonHang(first));
                if (xoaGiua(first, x))
                    cout << "Xoa don hang tai vi tri " << x << " thanh cong!" << endl;
                else
                    cout << "Xoa don hang tai vi tri " << x << " khong thanh cong!" << endl;
            }
            else
                cout << "Ban chua nhap don hang nao. Vui long thu lai sau!" << endl;
            break;
        }

        case 10:
        {
            if (nhap)
            {
                if (xoaCuoi(first))
                    cout << "Xoa don hang cuoi thanh cong!" << endl;
                else
                    cout << "Xoa don hang cuoi khong thanh cong!" << endl;
            }
            else
                cout << "Ban chua nhap don hang nao. Vui long thu lai sau!" << endl;
            break;
        }
        case 11:
        {
            if (nhap)
            {
                sapXepHangTheoKhuVuc(first);
                xuatDSDonHang();
            }
            else
                cout << "Ban chua nhap don hang nao. Vui long thu lai sau!" << endl;
            break;
        }

        case 12:
        {
            if (nhap)
            {
                thongTinDonHang a;
                nhap1DonHang(a);
                chenCuoi(first, a);
                sapXepHangTheoKhuVuc(first);
            }
            else
                cout << "Ban chua nhap don hang nao. Vui long thu lai sau!" << endl;
            break;
        }

        case 13:
        {
            if (nhap)
            {
                string x;
                cout << "Nhap ten tinh de biet so hang can gui: ";
                cin.ignore();
                getline(cin, x);
                cout << "\nSo hang can gui o tinh " << x << " la: " << soHangCanGui(x) << endl;
            }
            else
                cout << "Ban chua nhap don hang nao. Vui long thu lai sau!" << endl;
            break;
        }

        case 14:
        {
            if (nhap)
            {
                khachHangThanThiet();
            }
            else
                cout << "Ban chua nhap don hang nao. Vui long thu lai sau!" << endl;
            break;
        }

        case 15:
        {
            if (nhap)
            {
                string x;
                cout << "Nhap ten khach hang: ";
                cin.ignore();
                getline(cin, x);
                cout << "Khach hang " << x << " da gui la: " << demHangGui(x) << " don hang." << endl;
                cout << "Khach hang " << x << " da nhan la: " << demHangNhan(x) << " don hang." << endl;
            }
            else
                cout << "Ban chua nhap don hang nao. Vui long thu lai sau!" << endl;
            break;
        }

        case 16:
        {
            if (nhap)
            {
                cout << "Loai hang thuong duoc khach hang gui nhieu nhat la loai hang: ";
                if (loaiHangGuiNhieu(first) == 1)
                    cout << "Kho";
                else if (loaiHangGuiNhieu(first) == 2)
                    cout << "Long";
                else if (loaiHangGuiNhieu(first) == 3)
                    cout << "De vo";
                else
                    cout << "Khong duoc de tham nuoc";
            }
            else
                cout << "Ban chua nhap don hang nao. Vui long thu lai sau!" << endl;
            break;
        }

        case 17:
        {
            if (nhap)
            {
                int dem = 1;
                cout << "Nhung don hang co phi van chuyen cao nhat la: " << endl;
                double x = donHangPhiVCMax(first);
                for (node p = first; p != NULL; p = p->link)
                {
                    if (p->info.phiVanChuyen == x)
                    {
                        cout << "\t\t\t----- DON HANG THU: " << dem++ << " -----" << endl;
                        xuatDonHang(p->info);
                    }
                }
            }
            else
                cout << "Ban chua nhap don hang nao. Vui long thu lai sau!" << endl;
            break;
        }
        case 18:
        {
            if (nhap)
            {
                if (xoaTatCaDonHang(first))
                {
                    cout << "Xoa thanh cong!";
                    nhap = false;
                }
                else
                    cout << "Xoa khong thanh cong!";
            }
            else
                cout << "Ban chua nhap don hang nao. Vui long thu lai sau!" << endl;
            break;
        }
        default:
            cout << "Ban thuc su muon thoat? (Y/N)" << endl
                 << "Lua chon cua ban: ";
            cin >> thoat;
            if (thoat == 'Y' || thoat == 'y')
                cout << "Ban chon thoat. Cam on ban da su dung chuong trinh." << endl;
            break;
        }
        _getch();
    } while (chon >= 1 && chon <= 18 || thoat == 'N' || thoat == 'n');

    return 0;
}

int soLuongDonHang(node firts)
{
    int dem = 0;
    node p = firts;
    while (p != NULL)
    {
        dem++;
        p = p->link;
    }
    return dem;
}

void chenDau(node &first, thongTinDonHang x)
{
    node s = khoiTaoNodeDonHang(x);
    if (first == NULL)
        first = s;
    else
    {
        s->link = first;
        first = s;
    }
}

void chenCuoi(node &first, thongTinDonHang x)
{
    node s = khoiTaoNodeDonHang(x);

    if (first == NULL)
        first = s;
    else
    {
        node q = first;
        while (q->link != NULL)
            q = q->link;
        q->link = s;
    }
}

void chenGiua(node &first, int x, thongTinDonHang s)
{
    int n = soLuongDonHang(first);
    if (x == 1)
    {
        chenDau(first, s);
        return;
    }
    if (x == n + 1)
    {
        chenCuoi(first, s);
        return;
    }
    node q = first;
    for (int i = 2; i < x; i++)
        q = q->link;
    node a = khoiTaoNodeDonHang(s);
    a->link = q->link;
    q->link = a;
}

int xoaDau(node &first)
{
    if (first != NULL)
    {
        node p = first;
        first = first->link;
        delete p;
        return 1;
    }
    return 0;
}

int xoaCuoi(node &first)
{
    if (first != NULL)
    {
        node p, q;
        p = first;
        q = NULL;
        if (p != NULL)
            while (p->link != NULL)
            {
                q = p;
                p = p->link;
            }
        if (p != first)
            q->link = NULL;
        else
            first = NULL;
        delete p;
        return 1;
    }
    return 0;
}

int xoaGiua(node &first, int x)
{
    int n = soLuongDonHang(first);
    if (x == 1 || n == 1)
    {
        xoaDau(first);
        return 1;
    }
    if (x == n)
    {
        xoaCuoi(first);
        return 1;
    }
    else
    {
        node p = first;
        for (int i = 2; i < x; i++)
            p = p->link;
        node q = p->link;
        p->link = q->link;
        delete q;
        return 1;
    }
    return 0;
}

void nhap1DonHang(thongTinDonHang &s)
{
    node p = first;
    maSo *list;
    string tinhGui, tinhNhan;
    int n = docSLTinh();
    list = new maSo[n];
    docMaTinh(list, n);

    s.MS.thuTu++;

    cin.ignore();
    cout << "Nhap ho ten khach hang gui: ";
    getline(cin, s.tenGui);
    cout << "Nhap dia chi tinh gui: ";
    getline(cin, s.diaChiGui);
    for (int i = 0; i < n; i++)
    {
        if (list[i].tenTinh == s.diaChiGui)
            s.MS.maTinhGui = list[i].maTinh;
    }
    cout << "Nhap so dien thoai nguoi gui: ";
    cin >> s.SDTGui;
    cin.ignore();

    // thong tin nguoi nhan
    cout << "Nhap ho ten khach hang nhan: " << endl;
    string a;
    while (p != NULL)
    {
        if (s.tenGui == p->info.tenGui && a != p->info.tenNhan)
        {
            a = p->info.tenNhan;
            cout << p->info.tenNhan << endl;
        }

        p = p->link;
    }
    getline(cin, s.tenNhan);
    cout << "Nhap dia chi tinh nhan: " << endl;
    p = first;
    while (p != NULL)
    {

        if (s.tenGui == p->info.tenGui && a != p->info.diaChiNhan)
        {
            a = p->info.diaChiNhan;
            cout << p->info.diaChiNhan << endl;
        }

        p = p->link;
    }
    getline(cin, s.diaChiNhan);
    for (int i = 0; i < n; i++)
    {
        if (list[i].tenTinh == s.diaChiNhan)
            s.MS.maTinhNhan = list[i].maTinh;
    }
    s.maHang = s.MS.maTinhGui + s.MS.maTinhNhan + to_string(s.MS.thuTu++);

    cout << "Nhap so dien thoai nguoi nhan: ";
    cin >> s.SDTNhan;
    cin.ignore();

    do
    {
        cout << "Nhap phi chuyen hang: ";
        cin >> s.phiVanChuyen;
        if (s.phiVanChuyen < 0)
            cout << "\nNhap sai. Vui long nhap lai!\n";
    } while (s.phiVanChuyen < 0);
    do
    {

        cout << "Vui long khoang khoi luong sau:"
             << "\n1. Nho hon 1 Kg."
             << "\n2. Tu 1 den 2 Kg."
             << "\n3. Tu 2 den 5 Kg."
             << "\n4. Lon hon 5 Kg.";
        cout << "\nNhap trong luong don hang: ";
        cin >> s.trongLuong;
        if (s.trongLuong < 1 || s.trongLuong > 4)
            cout << "\nNhap sai. Vui long nhap lai!\n";
    } while (s.trongLuong < 1 || s.trongLuong > 4);
    do
    {
        cout << "Vui long chon loai hang sau:"
             << "\n1. Loai kho."
             << "\n2. Loai long."
             << "\n3. Loai de vo."
             << "\n4. Khong duoc de tham nuoc.";
        cout << "\nNhap loai hang: ";
        cin >> s.loaiHang;
        if (s.loaiHang < 1 || s.loaiHang > 4)
            cout << "\nNhap sai. Vui long nhap lai!\n";
    } while (s.loaiHang < 1 || s.loaiHang > 4);
    delete[] list;
    list = 0;
    cout << "+++++++++++++++++++++++++++++++++++++++++++\n";
}

void nhapDSDonHang(node &first, int n)
{
    thongTinDonHang x;
    for (int i = 0; i < n; i++)
    {
        cout << "\nNhap thong tin don hang thu " << soLuongDonHang(first) + 1 << ": " << endl
             << endl;
        nhap1DonHang(x);
        chenCuoi(first, x);
    }
}

void docDanhSachGoiHang(ifstream &filein, node &first)
{
    while (!filein.eof())
    {
        thongTinDonHang dh;
        docThongTinMotGoiHang(filein, dh);
        chenCuoi(first, dh);
    }
}

void docThongTinMotGoiHang(ifstream &filein, thongTinDonHang &s)
{
    maSo *list;
    int n = docSLTinh();
    list = new maSo[n];
    docMaTinh(list, n);
    s.MS.thuTu = soLuongDonHang(first) + 1;

    // thong tin nguoi gui
    getline(filein, s.tenGui, ',');
    getline(filein, s.diaChiGui, ',');
    for (int i = 0; i < n; i++)
    {
        if (list[i].tenTinh == s.diaChiGui)
            s.MS.maTinhGui = list[i].maTinh;
    }
    getline(filein, s.SDTGui, ',');

    // thon tin nguoi nhan
    getline(filein, s.tenNhan, ',');
    getline(filein, s.diaChiNhan, ',');
    for (int i = 0; i < n; i++)
    {
        if (list[i].tenTinh == s.diaChiNhan)
            s.MS.maTinhNhan = list[i].maTinh;
    }
    getline(filein, s.SDTNhan, ',');

    // cac thong tin khac
    filein >> s.phiVanChuyen;
    filein.ignore();
    filein >> s.trongLuong;
    filein.ignore();
    filein >> s.loaiHang;
    filein.ignore();
    s.maHang = s.MS.maTinhGui + s.MS.maTinhNhan + to_string(s.MS.thuTu++);
}

void xuatDSDonHang()
{
    cout << "\n\t\t\t\t\t\t\t\t\t+-------------------------+\n";
    cout << "\t\t\t\t\t\t\t\t\t| BANG DANH SACH DON HANG |\n";
    cout << "\t\t\t\t\t\t\t\t\t+-------------------------+\n\n";
    Node *p = first;
    int stt = 1;
    cout << "+-----+---------+";
    cout << "----------------------------+------------+------------+";
    cout << "----------------------------+------------+------------+";
    cout << "---------------+--------------+-----------------------+" << endl;
    cout << setw(4) << left << "| STT |" << setw(9) << left << " Ma Hang |"
         << setw(28) << left << "       Ten Nguoi Gui        |" << setw(13) << left << "  Tinh Gui  |" << setw(12) << left << "  SDT Gui   |"
         << setw(28) << left << "       Ten Nguoi Nhan       |" << setw(13) << left << "  Tinh Nhan |" << setw(12) << left << "  SDT Nhan  |"
         << setw(7) << left << " Phi VC (VND)  |" << setw(15) << left << " Trong Luong  |" << setw(25) << left << "      Loai Hang        |" << endl;
    cout << "+-----+---------+";
    cout << "----------------------------+------------+------------+";
    cout << "----------------------------+------------+------------+";
    cout << "---------------+--------------+-----------------------+" << endl;
    while (p != NULL)
    {
        xuat1DonHang(p->info, stt++);
        p = p->link;
        cout << "+-----+---------+";
        cout << "----------------------------+------------+------------+";
        cout << "----------------------------+------------+------------+";
        cout << "---------------+--------------+-----------------------+" << endl;
    }
}

void xuat1DonHang(thongTinDonHang s, int stt)
{
    int x, y;
    x = s.loaiHang;
    y = s.trongLuong;

    cout << "|" << setw(5) << left << stt << "|" << setw(9) << left << s.maHang << "|"
         << setw(28) << left << s.tenGui << "|" << setw(12) << left << s.diaChiGui << "|" << setw(12) << left << s.SDTGui << "|"
         << setw(28) << left << s.tenNhan << "|" << setw(12) << left << s.diaChiNhan << "|" << setw(12) << left << s.SDTNhan << "|"
         << "    " << setw(7) << left << s.phiVanChuyen << "    |" << setw(14) << left;
    xuatTrongLuong(y);
    cout << "|" << setw(23) << left;
    xuatLoaiHang(x);
    cout << "|" << endl;
}

void xuatDonHang(thongTinDonHang s)
{
    int x, y;
    x = s.loaiHang;
    y = s.trongLuong;
    cout << "\n\t\tMa so don hang\t\t\t: " << s.maHang << endl;
    cout << "\t\tHo Ten nguoi gui\t\t: " << s.tenGui << endl;
    cout << "\t\tDia chi nguoi gui\t\t: " << s.diaChiGui << endl;
    cout << "\t\tSo dien thoai nguoi gui\t\t: " << s.SDTGui << endl;
    cout << "\t\tHo Ten nguoi nhan\t\t: " << s.tenNhan << endl;
    cout << "\t\tDia chi nguoi nhan\t\t: " << s.diaChiNhan << endl;
    cout << "\t\tSo dien thoai nguoi nhan\t: " << s.SDTNhan << endl;
    cout << "\t\tPhi van chuyen\t\t\t: " << s.phiVanChuyen << " VND" << endl;
    cout << "\t\tTrong luong don hang\t\t: ";
    xuatTrongLuong(y);
    cout << " kg\n";

    cout << "\t\tLoai Hang\t\t\t: ";
    xuatLoaiHang(x);
    cout << endl;
    cout << "\t\t   **********************************\n\n";
}

int loaiHangGuiNhieu(node first)
{
    int loai1, loai2, loai3, loai4;
    loai1 = loai2 = loai3 = loai4 = 0;
    int a[4];
    node p = first;
    while (p != NULL)
    {
        if (p->info.loaiHang == 1)
            a[0] = loai1++;

        else if (p->info.loaiHang == 2)
            a[1] = loai2++;
        else if (p->info.loaiHang == 3)
            a[2] = loai3++;
        else
            a[3] = loai4++;
        p = p->link;
    }
    int Max = a[0];
    for (int i = 0; i < 4; i++)
    {
        if (a[i] > Max)
            Max = a[i];
    }
    for (int i = 0; i < 4; i++)
    {
        if (a[i] == Max)
            return i + 1;
    }
}

double donHangPhiVCMax(node a)
{
    thongTinDonHang s;
    double Max = a->info.phiVanChuyen;
    for (node p = a; p != NULL; p = p->link)
    {
        if (p->info.phiVanChuyen > Max)
            Max = p->info.phiVanChuyen;
    }
    return Max;
}

void xuatLoaiHang(int x)
{
    if (x == 1)
    {
        cout << "Kho";
        return;
    }
    if (x == 2)
    {
        cout << "Long";
        return;
    }
    if (x == 3)
    {
        cout << "De vo";
        return;
    }
    if (x == 4)
    {
        cout << "Khong duoc de tham nuoc";
        return;
    }
}

void xuatTrongLuong(int x)
{
    if (x == 1)
    {
        cout << "Nho hon 1 kg";
        return;
    }
    if (x == 2)
    {
        cout << "Tu 1 den 2 kg";
        return;
    }
    if (x == 3)
    {
        cout << "Tu 2 den 5 kg";
        return;
    }
    if (x == 4)
    {
        cout << "Lon hon 5 kg";
        return;
    }
}

int demHangGui(string s)
{
    int dem = 0;
    for (node p = first; p != NULL; p = p->link)
    {
        if (p->info.tenGui == s)
            dem++;
    }
    return dem;
}

int demHangNhan(string s)
{
    int dem = 0;
    for (node p = first; p != NULL; p = p->link)
    {
        if (p->info.tenNhan == s)
            dem++;
    }
    return dem;
}

int xoaTatCaDonHang(node &a)
{
    int n = soLuongDonHang(first);
    if (n > 0)
    {
        for (int i = 0; i < n; i++)
            xoaDau(first);
        return 1;
    }
    return 0;
}

int docSLTinh()
{
    ifstream inData;
    string s;
    int dem = 0;
    inData.open("maTinh.txt");
    if (inData.is_open())
    {
        while (!inData.eof())
        {
            getline(inData, s);
            if (s == "")
                break;
            dem++;
        }
        inData.close();
        return dem;
    }
    else
    {
        cout << "Khong doc duoc file maTinh" << endl;
        return 0;
    }
}

void docMaTinh(maSo *ms, int n)
{
    ifstream inData;
    inData.open("maTinh.txt", ios::in);
    if (inData.is_open())
    {
        for (int i = 0; i < n; i++)
        {
            getline(inData, ms[i].maTinh, ':');
            getline(inData, ms[i].tenTinh);
        }
        inData.close();
    }
    else
        cout << "Khong mo duoc file";
}

void xuatTenTinh(maSo *list, int n, string soTinh)
{
    cout << "Ten tinh cua ban la: " << endl;
    for (int i = 0; i < n; i++)
    {
        if (list[i].maTinh == soTinh)
            cout << list[i].tenTinh << endl;
    }
}

void xuatMaTinh(maSo *list, int n, string Tinh)
{
    cout << "Ma tinh cua ban la: " << endl;
    for (int i = 0; i < n; i++)
    {
        if (list[i].tenTinh == Tinh)
            cout << list[i].maTinh << endl;
    }
}

void ghiDSDonHang(thongTinDonHang ds)
{
    maSo *list;
    string tinhGui, tinhNhan;
    int n = docSLTinh();
    list = new maSo[n];
    docMaTinh(list, n);
    ds.MS.thuTu = soLuongDonHang(first) + 1;

    ofstream listOut;
    listOut.open("DanhSachCacGoiHang.txt", ios::out);
    if (listOut.is_open())
    {
        for (node p = first; p != NULL; p = p->link)
        {
            for (int i = 0; i < n; i++)
            {
                if (list[i].tenTinh == ds.diaChiGui)
                    ds.MS.maTinhGui = list[i].maTinh;
            }
            for (int i = 0; i < n; i++)
            {
                if (list[i].tenTinh == ds.diaChiNhan)
                    ds.MS.maTinhNhan = list[i].maTinh;
            }
            ds.maHang = ds.MS.maTinhGui + ds.MS.maTinhNhan + to_string(ds.MS.thuTu++);

            listOut << p->info.maHang << ','
                    << p->info.tenGui << ',' << p->info.diaChiGui << ',' << p->info.SDTGui << ','
                    << p->info.tenNhan << ',' << p->info.diaChiNhan << ',' << p->info.SDTNhan << ','
                    << p->info.phiVanChuyen << ',' << p->info.trongLuong << ',' << p->info.loaiHang << endl;
        }
        listOut.close();
        cout << "Ghi vao file thanh cong!";
    }
    else
        cout << "Khong mo duoc file\n";
}

void khachHangThanThiet()
{
    struct khachThanThiet
    {
        string ten;
        double phiVC = 0;
    };
    khachThanThiet *a;
    int n = soLuongDonHang(first);
    a = new khachThanThiet[n];
    node p = first;
    int i = 0;
    while (i < n)
    {
        for (node q = first; q != NULL; q = q->link)
        {
            for (int j = 0; j < i; j++)
                if (a[j].ten != q->info.tenGui)
                {
                    a[j].ten = q->info.tenGui;
                    break;
                }
        }
        i++;
    }
    for (int j = 0; j <= i; j++)
    {
        for (node q = first; q != NULL; q = q->link)
        {
            if (a[j].ten == q->info.tenGui)
                a[j].phiVC += q->info.phiVanChuyen;
        }
    }
    double tam = a[0].phiVC;
    for (int j = 0; j <= i; j++)
    {
        if (a[j].phiVC > tam)
            tam = a[j].phiVC;
    }
    cout << "Nhung khach hang than thiet nhat la: " << endl;
    for (int j = 0; j <= i; j++)
    {
        if (a[j].phiVC == tam)
        {
            cout << "\t\t" << a[j].ten << endl;
        }
    }
    // delete a;
}

void hoanVi(thongTinDonHang &x, thongTinDonHang &y)
{
    thongTinDonHang tam = x;
    x = y;
    y = tam;
}

void sapXepHangTheoKhuVuc(node first)
{
    for (node p = first; p != NULL; p = p->link)
        for (node q = p->link; q != NULL; q = q->link)
            if (p->info.diaChiNhan < q->info.diaChiNhan)
                hoanVi(p->info, q->info);
            else if (p->info.diaChiNhan == q->info.diaChiNhan)
                if (p->info.loaiHang > q->info.loaiHang)
                    hoanVi(p->info, q->info);
}

void XuatGoiHangGuiTungKhuVucTinhThanh(node fist)
{
    for (node p = first; p != NULL; p = p->link)
        for (node q = p->link; q != NULL; q = q->link)
            if (p->info.diaChiGui < q->info.diaChiGui)
                hoanVi(p->info, q->info);
}

int soHangCanGui(string x)
{
    int dem = 0;
    for (node p = first; p != NULL; p = p->link)
    {
        if (p->info.diaChiGui == x)
            dem++;
    }
    return dem;
}