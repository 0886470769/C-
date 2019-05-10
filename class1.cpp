// class1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
#include<string>
#include<conio.h>
/*
le nam dai an
STT: 1751062219
Lop: K59TH
*/
struct sinhvien
{
	string hoten;
	string mssv;
	string tenmh;
	float diem;
	double diemtb;

};
typedef struct sinhvien SinhVien;
struct danhsach
{
	SinhVien arr[100];
	int n;
};
typedef struct danhsach DanhSach;

void Nhap_Thong_Tin_1_Sinh_Vien(SinhVien& sv)
{
	do {

		fflush(stdin); 
		cout << "\nNhap ho ten sinh vien: ";
		getline(cin, sv.hoten);
		if (sv.hoten.length() > 30) {

			cout << "\nHo ten toi da 30 ki tu. Xin kiem tra lai";
		}

	} while (sv.hoten.length() > 30);

	do
	{

		fflush(stdin);
		cout << "\nNhap ma so sinh vien: ";
		getline(cin, sv.mssv);
		if (sv.mssv.length() > 10) {

			cout << "\nMa so sinh vien toi da 10 ki tu. Xin kiem tra lai";
		}
	} while (sv.mssv.length() > 10);

	do {

		fflush(stdin);
		cout << "\nNhap ten mon hoc: ";
		getline(cin, sv.tenmh);
		if (sv.tenmh.length() > 30) {

			cout << "\nTen mon hoc toi da 30 ki tu. Xin kiem tra lai";
		}

	} while (sv.tenmh.length() > 30);

	do {
		cout << "\nNhap diem sinh vien: ";
		cin >> sv.diem;
		if (sv.diem < 0 || sv.diem > 10)
		{

			cout << "\nDiem trung binh khong duoc < 0 hay > 10";
		}
	} while (sv.diem < 0 || sv.diem > 10);


	do {
		cout << "\nNhap diem trung binh sinh vien: ";
		cin >> sv.diemtb;
		if (sv.diemtb < 0 || sv.diemtb > 10)
		{

			cout << "\nDiem trung binh khong duoc < 0 hay > 10";
		}
	} while (sv.diemtb < 0 || sv.diemtb > 10);

}

void Xuat_Thong_Tin_1_Sinh_Vien(SinhVien sv)
{
	cout << "\nHo ten sinh vien: " << sv.hoten;

	cout << "\nTen mon hoc: " << sv.tenmh;

	cout << "\nMa so sinh vien: " << sv.mssv;

	cout << "\nDiem  sinh vien: " << sv.diem;

	cout << "\nDiem trung binh sinh vien: " << sv.diemtb;
}

void Nhap_Danh_Sach_Sinh_Vien(DanhSach & ds)
{
	for (int i = 0; i < ds.n; i++)
	{
		cout << "\n\t\t NHAP THONG TIN SINH VIEN THU " << i + 1 << endl;
		Nhap_Thong_Tin_1_Sinh_Vien(ds.arr[i]);

	}
}

void Xuat_Danh_Sach_Sinh_Vien(DanhSach ds)
{
	for (int i = 0; i < ds.n; i++)
	{
		cout << "\n\t\t XUAT THONG TIN SINH VIEN THU " << i + 1 << endl;
		Xuat_Thong_Tin_1_Sinh_Vien(ds.arr[i]);

	}
}

float Tim_Diem_Trung_Binh_Cao_Nhat(DanhSach ds)
{

	int max = ds.arr[0].diemtb;
	for (int i = 1; i < ds.n; i++)
	{

		if (ds.arr[i].diemtb > max)
		{

			max = ds.arr[i].diemtb;
		}

	}
	for (int i = 0; i < ds.n; i++)
	{
		if (ds.arr[i].diemtb == max)
		{
			Xuat_Thong_Tin_1_Sinh_Vien(ds.arr[i]);

		}
	}
	return max;
}

double Tim_Sinh_Vien_Diem_Trung_Binh_Thap_Nhat(DanhSach ds)
{
	int min = ds.arr[0].diemtb;
	for (int i = 1; i < ds.n; i++)
	{
		if (ds.arr[i].diemtb < min)
		{
			min = ds.arr[i].diemtb;
		}
	}
	for (int i = 0; i < ds.n; i++)
	{
		if (ds.arr[i].diemtb == min)
		{
			Xuat_Thong_Tin_1_Sinh_Vien(ds.arr[i]);

		}
	}
	return min;
}

int main()
{
	DanhSach ds;
	cout << "\nNhap so luong sinh vien: ";
	cin >> ds.n;
	cout << "\n\n\n\t\tNHAP DANH SACH SINH VIEN\n";
	Nhap_Danh_Sach_Sinh_Vien(ds);
	cout << "\n\n\n\t\tXUAT DANH SACH SINH VIEN\n";
	Xuat_Danh_Sach_Sinh_Vien(ds);

	float max = Tim_Diem_Trung_Binh_Cao_Nhat(ds);
	cout << "\n\n\tDiem trung binh cao nhat la: " << max;
	cout << "\n\n\t\t DANH SACH SINH VIEN CO DIEM TRUNG BINH CAO NHAT\n";


	float min = Tim_Diem_Trung_Binh_Cao_Nhat(ds);
	cout << "\n\n\tDiem trung binh cao nhat la: " << min;
	cout << "\n\n\t\t DANH SACH SINH VIEN CO DIEM TRUNG BINH THAP NHAT\y";
	Tim_Sinh_Vien_Diem_Trung_Binh_Thap_Nhat(ds);
	system("pause");
	return 0;
}
// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
