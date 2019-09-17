#pragma once
#ifndef __SCH_SETTING_H__
#define __SCH_SETTING_H__
#include "SCH.h"
class sch {
private:
 string data[21][6];
 string data2[21][6];
 string color[7];
 map<string, string> m;
 map<string, string> ::iterator iter;
 int color_num;
public:
 sch();
 void menu(); // 메뉴
 void input(); // input
 void show(); // 콘솔창 출력
 void save_sch(); // html저장
 void save_sch_ver_2(); // html ver2
 void show_html(); // start html
 void show_html_ver_2(); // start html
 void run(); // run
};

#endif