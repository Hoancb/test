/*
MSSV: 21110827
Họ và tên : Trần Khải Hoàn
Ngày cập nhật cuối : 05 / 03 / 2022
*/
#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
struct MH {
	char mamh[15];
	char tenmh[50];
	int sotc;
	float diem;
};
struct SV {
	char mssv[10];
	char hoten[50];
	int tuoi;
	int somon;
	MH kq[100];
	int tongtc, tongtctl;
	float dtbc, dtbtl;
};

void docfile(const char filename[], SV& s);
void insv(SV s);
void ghifile(const char filename[], SV s);
void ghifile2(const char filename[], SV s);

int main()
{
	int n;
	SV a;
	docfile("D:/SV.TXT", a);
	insv(a);
	ghifile("D:/OUTPUT1.TXT", a);
	ghifile2("D:/OUTPUT2.TXT", a);
	return 0;
}

void docfile(const char filename[], SV& s)
{
	char temp[100];
	FILE* fp;
	fopen_s(&fp, filename, "rt");
	if (fp == NULL)
	{
		cout << "Khong mo duoc tap tin!\n";
		return;
	}
	fgets(s.mssv, 10, fp);
	s.mssv[strlen(s.mssv) - 1] = '\0';
	fgets(s.hoten, 50, fp);
	s.hoten[strlen(s.hoten) - 1] = '\0';
	fscanf_s(fp, "%d", &s.tuoi);
	fscanf_s(fp, "%d", &s.somon);
	for (int i = 0; i < s.somon; i++)
	{
		fgets(temp, 100, fp);
		fgets(temp, 100, fp);
		fgets(s.kq[i].mamh, 15, fp);
		fgets(s.kq[i].tenmh, 50, fp);
		fscanf_s(fp, "%d", &s.kq[i].sotc);
		fscanf_s(fp, "%f", &s.kq[i].diem);
	}
		fclose(fp);
	int tong = 0, tongtl = 0;
	float td = 0, tdtl = 0;
	for (int i = 0; i < s.somon; i++)
	{
		tong += s.kq[i].sotc;
		td += s.kq[i].sotc * s.kq[i].diem;
		if (s.kq[i].diem >= 5.0) {
			tongtl += s.kq[i].sotc;
			tdtl += s.kq[i].sotc * s.kq[i].diem;
		}
	}
	s.tongtc = tong;
	s.tongtctl = tongtl;
	s.dtbc = td / tong;
	s.dtbtl = tdtl / tongtl;
}

void ghifile(const char filename[], SV s)
{
	FILE* fp;
	fopen_s(&fp, "D:/OUTPUT1.TXT", "wt");
	if (fp == NULL)
	{
		cout << "Khong mo duoc tap tin!\n";
		return;
	}
	fprintf(fp, "%s\n", s.mssv);
	fprintf(fp, "%s\n", s.hoten);
	fprintf(fp, "%d\n", s.tuoi);
	fprintf(fp, "%d\n", s.somon);
	fprintf(fp, "%d\n", s.tongtc);
	fprintf(fp, "%d\n", s.tongtctl);
	fprintf(fp, "%f\n", s.dtbc);
	fprintf(fp, "%f\n", s.dtbtl);
	for(int i = 0; i < s.somon; i++)
	{
		fprintf(fp, "%s\n", s.kq[i].mamh);
		fprintf(fp, "%s\n", s.kq[i].tenmh);
		fprintf(fp, "%d\n", s.kq[i].sotc);
		fprintf(fp, "%f\n", s.kq[i].diem);
	}
	fclose(fp);
}
void ghifile2(const char filename[], SV s)
{
	FILE* fp;
	fopen_s(&fp, "D:/OUTPUT2.TXT", "wt");
	if (fp == NULL)
	{
		cout << "Khong mo duoc tap tin!\n";
		return;
	}
	fprintf(fp, "%s\n", s.mssv);
	fprintf(fp, "%s\n", s.hoten);
	fprintf(fp, "%d\n", s.tuoi);
	fprintf(fp, "%d\n", s.somon);
	fprintf(fp, "%d\n", s.tongtc);
	fprintf(fp, "%d\n", s.tongtctl);
	fprintf(fp, "%f\n", s.dtbc);
	fprintf(fp, "%f\n", s.dtbtl);
	for (int i = 0; i < s.somon; i++)
	{
		fprintf(fp, "%s\n", s.kq[i].mamh);
		fprintf(fp, "%s\n", s.kq[i].tenmh);
		fprintf(fp, "%d\n", s.kq[i].sotc);
		fprintf(fp, "%f\n", s.kq[i].diem);
	}
	fclose(fp);
}
void insv(SV s)
{
	printf("Ma so SV: %s\n", s.mssv);
	printf("Ho va ten: %s\n", s.hoten);
	printf("Tuoi: %d\n", s.tuoi);
	printf("So mon: %d\n", s.somon);
	printf("Tong TC: % d\n", s.tongtc);
	printf("Tong TCTL: % d\n", s.tongtctl);
	printf("Diem TBC: % f\n", s.dtbc);
	printf("Diem TBTL: % f\n", s.dtbtl);
	for (int i = 0; i < s.somon; i++)
	{
		printf("Ma MH: %s\n", s.kq[i].mamh);
		printf("Ten MH: %s\n", s.kq[i].tenmh);
		printf("So TC: %d\n", s.kq[i].sotc);
		printf("Diem: %f\n", s.kq[i].diem);
	
	}
}

