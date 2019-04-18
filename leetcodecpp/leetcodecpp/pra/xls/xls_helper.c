#include <iostream>
#include <string.h>
#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS
#include <vector>
#include <codecvt>
#include <unordered_map>

#include "utlit.h"
#include "BasicExcel.hpp"
using namespace YExcel;

const std::string khbh_zjzh_file = "��֤��.xls";
const std::string jb_zjzh_file = "�ʽ��˺��뾭��.xls";

unordered_map<string, string> zjzh_khbh_dict;
unordered_map<string, string> khbh_jb_dict;

unordered_map<string, unordered_map<string, vector<vector<string>>>> item_dict;


// wstring��utf-8��utf-16ת��
std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>>  convertor_utf;
// wstring��խ�ַ���ת��
std::wstring_convert<std::codecvt<wchar_t, char, std::mbstate_t>> conv(new std::codecvt<wchar_t, char, std::mbstate_t>("CHS"));


// C++11 std ��ʽת�� 
//std::wstring wstrTmp1 = conv.from_bytes(strTmp);
// wstringת��Ϊstring
//std::string strTmp2 = conv.to_bytes(wstrTmp1);

string get_str_value(BasicExcelCell* cell) {
	string value = "";
	switch (cell->Type())
	{
	case BasicExcelCell::STRING:
		value = cell->GetString();
		break;
	case BasicExcelCell::WSTRING:
		value = conv.to_bytes(cell->GetWString());
		break;
	default:
		break;
	}
	return value;
}



int init_zjzh_khbh_dict() {

	BasicExcel e;
	e.Load(khbh_zjzh_file.c_str());
	BasicExcelWorksheet* sheet1 = e.GetWorksheet("sheet0");
	if (sheet1) {
		size_t maxRows = sheet1->GetTotalRows();

		for (size_t r = 1; r < maxRows; ++r) {

			BasicExcelCell* cell_key = sheet1->Cell(r, 2);
			BasicExcelCell* cell_value = sheet1->Cell(r, 0);

			//cout <<r << " "<< cell_key->GetString() << " "<< cell_value->GetString() << endl;

			zjzh_khbh_dict[cell_key->GetString()] = cell_value->GetString();// �ʽ��˺ţ��ͻ����
		}
		return 1;
	}
	return 0;
}


int init_jb_zjzh_dict() {
	
	init_zjzh_khbh_dict();

	BasicExcel e;
	e.Load(jb_zjzh_file.c_str());
	BasicExcelWorksheet* sheet1 = e.GetWorksheet("SQL Results");
	if (sheet1) {
		size_t maxRows = sheet1->GetTotalRows();
		//size_t maxCols = sheet1->GetTotalCols();

		for (size_t r = 0; r < maxRows; ++r) {
			
			BasicExcelCell* cell_key = sheet1->Cell(r, 1);
			BasicExcelCell* cell_value = sheet1->Cell(r, 2);
			string khbh;
			if (zjzh_khbh_dict.find(get_str_value(cell_key)) == zjzh_khbh_dict.end()) {
				continue;// �ʽ��˺ţ��ͻ����  ����û�м�¼
			}

			khbh = zjzh_khbh_dict[get_str_value(cell_key)];
			string value = conv.to_bytes(cell_value->GetWString());
			khbh_jb_dict[khbh] = value;   //�ͻ���ţ�����
		}
		return 1;
	}
	return 0;
}



void handle_file(const string& filepath, const string& fname) {

	if (fname.find_first_of("�ʲ��йܲ�") == 0 
		&&
		(
		fname.find("-01-") != string::npos ||
		fname.find("-02-") != string::npos ||
		fname.find("-03-") != string::npos ||
		fname.find("-04-") != string::npos ||
		fname.find("-05-") != string::npos ||
		fname.find("-06-") != string::npos ||
		fname.find("-07-") != string::npos ||
		fname.find("-7-") != string::npos) 
		)
	  {
		cout << filepath << endl;
		BasicExcel e;
		e.Load(filepath.c_str());
		BasicExcelWorksheet* sheet1 = e.GetWorksheet("sheet0");
		if (sheet1) {
			size_t maxRows = sheet1->GetTotalRows();
			size_t maxCols = sheet1->GetTotalCols();

			vector<string> title_arr;

			//������,ͬʱѰ�ҿͻ����/�ͻ�������
			int keycol = -1; //�ͻ������
			wstring wkhbh = L"�ͻ����";
			string khbh = conv.to_bytes(wkhbh);
			//WStringToString(wkhbh, khbh);
			wstring wkhdm = L"�ͻ�����";
			string khdm = conv.to_bytes(wkhdm);;
			//WStringToString(wkhdm, khdm);
			for (size_t c = 0; c < maxCols; ++c) {
				BasicExcelCell* cell = sheet1->Cell(0, c);
				wstring s=cell->GetWString();
			
				string value = get_str_value(cell);
				if (value == khbh || value == khdm) {
					keycol = c;
				}
				title_arr.push_back(get_str_value(cell));
			}

			if (keycol == -1) {
				return;
			}

			//������
			for (size_t r = 1; r < maxRows; ++r) {
				vector<string> content_arr;

				for (size_t c = 0; c < maxCols; ++c) {
					BasicExcelCell* cell = sheet1->Cell(r, c);
					string value = get_str_value(cell);
					content_arr.push_back(value);
				}

				//�ͻ�����
				BasicExcelCell* cell = sheet1->Cell(r, keycol);
				string khdm = get_str_value(cell);

				if (khbh_jb_dict.find(khdm) == khbh_jb_dict.end()) {
					//û�ҵ�,����������¼
					continue;
				}

				string key_jb = khbh_jb_dict[khdm];

				if (item_dict.find(key_jb) == item_dict.end()) {
					//��δ����
					unordered_map<string, vector<vector<string>>> sub_map;
					vector<vector<string>> bigarr;
					bigarr.push_back({ filepath });
					bigarr.push_back(title_arr);
					bigarr.push_back(content_arr);
					sub_map[fname] = bigarr;
					item_dict[key_jb] = sub_map;
				}
				else {
					// �Ѵ�����sub_map
					unordered_map<string, vector<vector<string>>> &sub_map = item_dict[key_jb];
					if (sub_map.find(fname) == sub_map.end()) {
						//δ����fnamekey
						vector<vector<string>> bigarr;
						bigarr.push_back({ filepath/*GBKToUTF8(filepath)*/ });
						bigarr.push_back(title_arr);
						bigarr.push_back(content_arr);
						sub_map[fname] = bigarr;
					}
					else {
						//����fname key
						sub_map[fname].push_back(content_arr);
					}
 				}
			}
		}
	}
}


string idx_helper(int r, int c) {
	string d = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char cc[8];
	sprintf_s(cc, "%c%d", d[c], r + 1);
	return cc;
}


void write_excel(const string& jbname, const unordered_map<string, vector<vector<string>>>& submap) {

	BasicExcel e;
	e.Load("example.xls");
	int i = 0;
	for (const auto& n : submap) {
		
		// �ļ���������
		vector<string> fnames=split(n.first, '-');
		wstring sheetname = conv.from_bytes(fnames[1]+fnames[2]);
		BasicExcelWorksheet* sheet = e.AddWorksheet(i);
		sheet = e.GetWorksheet(i);
		if (sheet) {
			const vector<vector<string>>& content = n.second;

			int size = content.size();
			for (int r = 0; r < size; r++)
			{
				int csize = content[r].size();
				for (int c = 0; c < csize; c++) {
					sheet->Cell(r, c)->SetWString(conv.from_bytes(content[r][c]).c_str());
				}
			}
		}
		e.RenameWorksheet(i, sheetname.c_str());
		i++;
	}

	string filename = conv.to_bytes(conv.from_bytes(jbname)) + ".xls";
	e.SaveAs(filename.c_str());

}

void test()
{
	std::string strTmp = "���� C++11 ���ַ�ת����";
	// wstring��utf-8��utf-16ת��
	std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>>  convertor_utf;
	// wstring��խ�ַ���ת��
	std::wstring_convert<std::codecvt<wchar_t, char, std::mbstate_t>> conv(new std::codecvt<wchar_t, char, std::mbstate_t>("CHS"));
	// C++11 std ��ʽת�� 
	std::wstring wstrTmp1 = conv.from_bytes(strTmp);
	// wstringת��Ϊstring
	std::string strTmp2 = conv.to_bytes(wstrTmp1);

	// ���õ�������
	std::wcout.imbue(std::locale("chs"));
	// ���wstring��Ҫ wcout
	std::wcout << "WSTRING: \t"  << wstrTmp1 << std::endl;
	std::cout << "C++11 wstring ת��Ϊ string\t" << strTmp2 << std::endl;
}


int main()
{
	//test();
	init_jb_zjzh_dict();
	std::cout << khbh_jb_dict.size() << endl;

	std::function<void(const std::string&, const string&)> f(handle_file);
	runpath(".\\�㷢���˵�", f);

	cout << item_dict.size() << endl;
	
	for (const auto& n : item_dict) {
		/*
		cout << n.first << endl;
		cout << n.second.size() << endl;
		for (const auto& nn : n.second) {
			cout << nn.first << endl;
			cout << nn.second.size() << endl;
			
			for (const auto& subarr : nn.second) {
				for (const auto& subsmallarr : subarr) {
					cout << UTF8ToGBK(subsmallarr) << " ";
				}
				cout << endl;
			}
			
		}
		*/
		write_excel(n.first, n.second);
	}

	char c = getchar();

	return 0;
}