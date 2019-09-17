#include "SCH_SETTING.h"

sch::sch() {
 int Ck = 1;
 int co = 2;
 data[0][1] = "월요일";
 data[0][2] = "화요일";
 data[0][3] = "수요일";
 data[0][4] = "목요일";
 data[0][5] = "금요일";
 color[0] = "FF00CC";
 color[1] = "orange";
 color[2] = "FFFF00";
 color[3] = "33FF66";
 color[4] = "3366FF";
 color[5] = "00FFFF";
 color[6] = "FF6699";
 color_num = -1;

 for (int k = 1; k < 21; k++){
  if (co != 0)
  {
   data[k][0] = 'A';
   co = 0;
  }
  else
  {
   data[k][0] = 'B';
   co = 1;
   Ck++;
  }
 }

 for (int k = 1; k < 21; k++) {
  for (int i = 1; i < 6; i++) {
   data[k][i] = "　";
   data2[k][i] = "　";
  }
 }
}

void sch::menu() {
 cout << "1: 입력" << endl;
 cout << "2: 출력" << endl;
 cout << "3: 시간표 html저장" << endl;
 cout << "4: 시간표 html저장_ver_2" << endl;
 cout << "5: 저장된 시간표" << endl;
 cout << "6: 저장된 시간표_ver_2" << endl;
 cout << "q: 나가기" << endl;
}

void sch::input() {
 ifstream is;
 string temp;
 string buf;
 string subject;
 string _class;
 int num;
 double Fnum;
 double Lnum;

 int count = 0;
 is.open("e:\\20141250\\c++\\data.txt");
 while (getline(is, temp)) {
  stringstream tok(temp);
  while (tok >> buf) {
   if (count == 0) {
    if (buf == "#") {
     break;
    }
    else {
     for (int k = 1; k < 6; k++) {
      if (!this->data[0][k].find(buf)) {
       num = k;
      }
      else {}
     }
     ++count;
    }
   }
   
   else if (count == 1) {
    subject = buf;
    ++count;
   }

   else if (count == 2) {
    Fnum = atof(buf.c_str());
    Fnum = Fnum * 2 - 1;
    ++count;
   }

   else if (count == 3) {
    Lnum = atof(buf.c_str());
    Lnum = (Lnum / 30 - 1) + Fnum;
    ++count;
   }
   else {
    _class = buf;
    for (int k = Fnum; k <= Lnum; k++) {
     data[k][num] = subject;
     data2[k][num] = _class;
     if (m.find(data[k][num]) == m.end()) {
      color_num++;
      m.insert(pair<string, string>(data[k][num], color[color_num]));
     }
     else {}
    }
    count = 0;
   }
  }
 }
}

void sch::show() {
 float co = 1;
 for (int k = 0; k < 21; k++) {
  if (k == 0) {
   cout << setw(4) << data[k][0];
  }
  else {
   cout << setw(4) << (int)co << data[k][0];
   co = co + 0.5;
  }
  for (int i = 1; i < 6; i++) {
   cout << setw(20) << data[k][i];
  }
  cout << endl;
  cout << setw(4) << data2[k][0];
  for (int i = 1; i < 6; i++) {
   cout << setw(20) << data2[k][i];
  }
  cout << "\n" << endl;
 }
}

void sch::save_sch() {
 ofstream os;
 int co = 0;
 os.open("e:\\20141250\\C++\\html.html");
 os << "<html>\n<head>\n<title>시간표\n</title>\n<body>" << endl;
 os << "<table border = \"2\" width=\"900\" height=\"300\" align = \"center\">" << endl;
 for (int k = 0; k < 21; k++) {
  os << "<tr>" << endl;
  if (k != 0 && k % 2 == 1) {
   os << "<th rowspan=\"2\" width=\"30\">" << k - co << "</th>";
   ++co;
  }
  else if (k == 0) {
   os << "<th></th>";
  }
  os << "<th width=\"30\">";
  os << data[k][0];
  os << "<br/>" << data2[k][0];
  os << "</th>";
  for (int i = 1; i < 6; i++) {
   os << "<th width=\"168\">";
   os << data[k][i];
   os << "<br/>" << data2[k][i];
   os << "</th>";
   
  }
  os << "\n</tr>" << endl;
 }
 os << "</table>\n</body>\n</head>\n</html>";
 os.close();
}

void sch::save_sch_ver_2() {
 ofstream os;
 int co = 0;
 os.open("e:\\20141250\\C++\\html2.html");
 os << "<html>\n<head>\n<title>시간표\n</title>\n<body>" << endl;
 os << "<table border = \"2\" width=\"900\" height=\"50\" align = \"center\" bgcolor=\"99CC99\">" << endl;
 os << "<tr>" << endl;
 os << "<th>시간표</th>\n</tr></table><br/>" << endl;
 os << "<table border = \"2\" width=\"900\" height=\"500\" align = \"center\">" << endl;
 for (int k = 0; k < 21; k++) {
  os << "<tr>" << endl;
  if (k != 0 && k % 2 == 1) {
   os << "<th rowspan=\"2\" width=\"30\" bgcolor = \"CCFF33\">" << k - co << "</th>";
   ++co;
  }
  else if (k == 0) {
   os << "<th bgcolor = \"CCFF33\"></th>";
  }
  os << "<th width=\"30\" bgcolor = \"CCFF33\">";
  os << data[k][0];
  os << "<br/>" << data2[k][0];
  os << "</th>";
  for (int i = 1; i < 6; i++) {
   for (int c = 1;; c++) {
    if (data[k][i] == data[k-1][i] && !(data[k][i] == "" || data[k][i] == "　")) {
     break;
    }

    else if (data[k][i] == data[k + c][i] && !(data[k][i] == "" || data[k][i] == "　")) {
     continue;
    }

    else if ((data[k][i] == "" || data[k][i] == "　") && c == 1) {
     os << "<th width=\"168\">";
     os << data[k][i];
     os << "<br/>" << data2[k][i];
     os << "</th>";
     break;
    }

    else {
     if (c > 1) {
      iter = m.find(data[k][i]);
      os << "<th rowspan=\"" << c << "\" width=\"168\" bgcolor=\"" << iter->second << "\">";
      os << data[k][i];
      os << "<br/>" << data2[k][i];
      os << "</th>";
      break;
     }
     else {
      if (k == 0) {
       os << "<th width=\"168\" bgcolor = \"CCFF33\">";
       os << data[k][i];
       os << "<br/>" << data2[k][i];
       os << "</th>";
       break;
      }
      else {
       os << "<th width=\"168\">";
       os << data[k][i];
       os << "<br/>" << data2[k][i];
       os << "</th>";
       break;
      }
     }
    }
   }
  }
  os << "\n</tr>" << endl;
 }
 os << "</table>\n</body>\n</head>\n</html>";
 os.close();
}

void sch::show_html() {
 system("e:\\20141250\\C++\\html.html");
}

void sch::show_html_ver_2() {
 system("e:\\20141250\\C++\\html2.html");
}

void sch::run() {
 int ch = 5;
 char cp;
 menu();
 while (ch == 5) {
  if (kbhit()) {
   cp = getch();
   switch (cp) {
   case '1':
    system("cls");
    input();
    system("pause");
    system("cls");
    menu();
    break;
   case '2':
    system("cls");
    show();
    system("pause");
    system("cls");
    menu();
    break;
   case '3':
    system("cls");
    save_sch();
    system("pause");
    system("cls");
    menu();
    break;
   case '4':
    system("cls");
    save_sch_ver_2();
    system("pause");
    system("cls");
    menu();
    break;
   case '5':
    system("cls");
    show_html();
    system("pause");
    system("cls");
    menu();
    break;
   case '6':
    system("cls");
    show_html_ver_2();
    system("pause");
    system("cls");
    menu();
    break;
   case 'q':
   case 'Q':
    ch = 4;
    break;
   default:;
   }
  }
 }
}
